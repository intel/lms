/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2022 Intel Corporation
 */
#include "UNSEventsDefinition.h"
#include "StatusEventHandler.h"
#include "DataStorageGenerator.h"
#include "GetProvisioningStateCommand.h"
#include "GetSystemDefenseStateCommand.h"
#include "GetRedirectionSessionsStateCommand.h"
#include "GetFWCapsCommand.h"
#include "GetLastHostResetReasonCommand.h"
#include "GetEACStateCommand.h"
#include "Tools.h"
#include "MKHIErrorException.h"
#include "DataStorageWrapper.h"

//WSMAN calls
#include "CancelOptInClient.h"
#include "KVMWSManClient.h"
#include "SyncIpClient.h"
#include "AMTEthernetPortSettingsClient.h"
#include "TimeSynchronizationClient.h"
#include "WlanWSManClient.h"

//messages definitions
const ACE_TString ENABLED_STR(ACE_TEXT("enabled"));
const ACE_TString DISABLED_STR(ACE_TEXT("disabled"));
const ACE_TString STARTED_STR(ACE_TEXT("started"));
const ACE_TString STOPED_STR(ACE_TEXT("stopped"));
const ACE_TString DATA_CHANNEL_STR(ACE_TEXT("data channel"));
const ACE_TString ENDED_STR(ACE_TEXT("ended"));
const ACE_TString REQUESTED_STR(ACE_TEXT("requested"));
const ACE_TString GRANTED_STR(ACE_TEXT("granted"));
const ACE_TString AMT_STATE(ACE_TEXT("Manageability "));
const ACE_TString ALARM_CLOCK_BOOT_STR(ACE_TEXT("Local Maintenance Timer has awoken the system from "));
const ACE_TString LAST_REMOTE_REBOOT_STR(ACE_TEXT("Remote power operation"));
const ACE_TString MEI_DRIVER(ACE_TEXT("Intel(R) MEI driver "));
const ACE_TString IP_SYNC_ENABLE(ACE_TEXT("IP synchronization "));
const ACE_TString TIME_SYNC_ENABLE(ACE_TEXT("Time synchronization "));
const ACE_TString ME_CONFIGURED(ACE_TEXT("Intel(R) ME configured"));
const ACE_TString ME_UNCONFIGURED(ACE_TEXT("Intel(R) ME unconfigured"));
const ACE_TString SOL_SESSION(ACE_TEXT("Remote SOL session "));
const ACE_TString IDER_SESSION(ACE_TEXT("Remote USBr session "));
const ACE_TString KVM_TEXT(ACE_TEXT("KVM "));
const ACE_TString KVM_SESSION(ACE_TEXT("KVM session "));
const ACE_TString USER_CONSENT_STR(ACE_TEXT("User consent "));
const ACE_TString PROVISIONING(ACE_TEXT("Provisioning state "));
const ACE_TString ME_STATE(ACE_TEXT("Common Services are "));
const ACE_TString EVENT_USER_CONSENT_GRANTED_MSG(ACE_TEXT("User consent granted"));
const ACE_TString EVENT_USER_CONSENT_TIMEOUR_STARTED_MSG(ACE_TEXT("User consent timeout started"));
const ACE_TString EVENT_USER_CONSENT_CONFIGURATION_CHANGED_MSG(ACE_TEXT("User consent configuration changed"));
const ACE_TString EVENT_SYSTEM_SDEFECE_STARTED(ACE_TEXT("System Defense started"));
const ACE_TString EVENT_SYSTEM_SDEFECE_STOPED(ACE_TEXT("System Defense stopped"));
const ACE_TString EVENT_SYSTEM_SDEFECE_CHANGE_MSG(ACE_TEXT("System Defense state changed"));

const ACE_TString LINK_PROTECTION_HIGH_MSG(ACE_TEXT("Intel(R) ME WLAN Link Protection is ON (HIGH)"));
const ACE_TString LINK_PROTECTION_PASSIVE_MSG(ACE_TEXT("Intel(R) ME WLAN Link Protection is ON (PASSIVE)"));
const ACE_TString LINK_PROTECTION_OFF_MSG(ACE_TEXT("Intel(R) ME WLAN Link Protection is OFF"));
const ACE_TString LINK_CONTROL_HOST_MSG(ACE_TEXT("WLAN Link Control set to Host (Operating system)"));
const ACE_TString LINK_CONTROL_ME_MSG(ACE_TEXT("WLAN Link Control set to Intel(R) ME"));

StatusEventHandler::StatusEventHandler(): filter_(new StatusEventFilter)
{
	StatusEventFilter::defaultInitialization(filter_);
	m_KVM=0;
	m_SOL=0;
	m_IDER=0;
	m_prevUserConsentState=OPT_IN_STATE_NOT_STARTED;
	m_prevProvState = Intel::MEI_Client::AMTHI_Client::PROVISIONING_STATE_PRE;
	m_UserConsentPolicy = ALL_SESSIONS;
	m_prevAmtState=NOT_PRESENT;
	m_prevManageMode=NOT_KNOWN;
	m_prevCustomerType = CORPORATE;	
	m_eacEnabled = true;
	m_firstPullForEvents = true;
	m_firstCheckForBootReason = true;
}

int StatusEventHandler::init (int argc, ACE_TCHAR *argv[])
{
	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed\n");
		return retVal;
	}

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_SRVICE_UP);
	this->putq(mbPtr->duplicate());

	return 0;
}

int StatusEventHandler::fini (void)
{
	UNS_DEBUG(L"StatusEventHandler service finalized\n");
	ACE_Reactor::instance()->cancel_timer (this);
	return 0;
}

int StatusEventHandler::suspend()
{
	ACE_Reactor::instance()->cancel_timer (this);
	return EventHandler::suspend();
}

int StatusEventHandler::resume()
{
	int res=EventHandler::resume();

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_SRVICE_UP);
	this->putq(mbPtr->duplicate());

	return res;
}
int
	StatusEventHandler::handle_event (MessageBlockPtr mbPtr )
{	
	GMS_AlertIndication * pGMS_AlertIndication = nullptr;
	int type=mbPtr->msg_type();

	switch (type)
	{
	case MB_SRVICE_UP:
		firstPullForEvents();
		GenerateEvents();
		return 0;
	case MB_PUBLISH_EVENT:
		pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
		if (pGMS_AlertIndication != nullptr)
		{
			return handleStatusChanged(pGMS_AlertIndication);
		}
		else
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("StatusEventHandler::Invalid data block.\n")), -1);
		}
	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT ("StatusEventHandler::Invalid Message.\n")), -1);
	}
	return 0;
}

const ACE_TString
	StatusEventHandler::name()
{
	return STATUS_EVENT_HANDLER;
}

int StatusEventHandler::handleStatusChanged(const GMS_AlertIndication *alert)
{
	FuncEntryExit<void> fee(this, L"handleStatusChanged");
	UNS_DEBUG(L"category=%d id=%d\n", alert->category, alert->id);
	switch (alert->category)
	{
	case CATEGORY_GENERAL:
		handleGeneralEvents(alert);
		break;
	case CATEGORY_CIRCUIT_BREAKER:	
		handleSystemDefenceEvents(alert);
		break;
	case CATEGORY_REMOTE_DIAGNOSTIC:
		handleRemoteDiagnosticEvents(alert);
		break;
	case CATEGORY_KVM:
		handleKVMEvents(alert);
		break;
	case CATEGORY_UNS:
		handleUNSEvents(alert);
		break;
	case CATEGORY_IPSYNC:
		handleIPSyncEvents(alert);
		break;
	case CATEGORY_USER_CONSENT:
		handleUserConsentEvents(alert);
		break;
	case CATEGORY_WLAN:
		handleWlanEvents(alert);
		break;
	case CATEGORY_TIMESYNC:
		handleTimeSyncEvents(alert);
		break;
	}
	return true;
}
void StatusEventHandler::handleGeneralEvents(const GMS_AlertIndication *alert)
{
	switch (alert->id)
	{
	case EVENT_UNPROVISIONES_STARTED:
	case EVENT_PROVISIONING_STATE_PRE:
	case EVENT_PROVISIONING_STATE_IN:
	case EVENT_PROVISIONING_STATE_POST:
		handleProvisioningEvents(alert);
		break;
	case EVENT_CONTROL_MODE_CHANGE: 
		SaveCurrentStatus(1,CONTROL_MODE_S); //CCM=0, ACM=1;
		break;
	case EVENT_ME_ENABLE :
		SaveCurrentStatus(1,ME_ENABLE_S);
		NotifyConfigurator(1, CONFIGURATION_TYPE::ME_ENABLE_CONF);
		break;
	case EVENT_ME_DISABLE:
		SaveCurrentStatus(0,ME_ENABLE_S);
		NotifyConfigurator(0, CONFIGURATION_TYPE::ME_ENABLE_CONF);
		break;
	case EVENT_AMT_ENABLE :
		SaveCurrentStatus(2,AMT_ENABLE_S);
		NotifyConfigurator(1, CONFIGURATION_TYPE::AMT_ENABLE_CONF);
		break;
	case EVENT_AMT_DISABLE:
		SaveCurrentStatus(1,AMT_ENABLE_S);
		NotifyConfigurator(0, CONFIGURATION_TYPE::AMT_ENABLE_CONF);
		break;
	case EVENT_AGENT_1:
	case EVENT_AGENT_2:
	case EVENT_AGENT_4:
		handleAgentPresenceEvents(alert);
		break;
	}

}

void StatusEventHandler::handleAgentPresenceEvents(const GMS_AlertIndication *alert)
{
	if ((m_prevManageMode== L3) || (m_prevManageMode== SBT) || (m_prevManageMode== VPRO))
	{
		switch (alert->id)
		{
		case EVENT_AGENT_1:			
			raiseGMS_AlertIndication(alert->category, EVENT_AGENT_PRSENCE_NOT_STARTED, alert->Datetime,
				alert->MessageID, alert->Message, alert->MessageArguments);
			break;
		case EVENT_AGENT_2:	
			raiseGMS_AlertIndication(alert->category, EVENT_AGENT_PRSENCE_STOPED, alert->Datetime,
				alert->MessageID, alert->Message, alert->MessageArguments);
			break;
		case EVENT_AGENT_4:	
			raiseGMS_AlertIndication(alert->category, EVENT_AGENT_PRSENCE_EXPIRED, alert->Datetime,
				alert->MessageID, alert->Message, alert->MessageArguments);
			break;
		}
	}
}
void StatusEventHandler::handleProvisioningEvents(const GMS_AlertIndication *alert)
{
	using namespace Intel::MEI_Client::AMTHI_Client;
	Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE prevProvState;
	unsigned long curProvState;
	switch (alert->id)
	{
	case EVENT_UNPROVISIONES_STARTED:
	case EVENT_PROVISIONING_STATE_PRE:
		curProvState=PROVISIONING_STATE_PRE;
		prevProvState=UpdatePrevProvisioningState(PROVISIONING_STATE_PRE);
		if (prevProvState==PROVISIONING_STATE_POST) // unprovision
		{
			raiseGMS_AlertIndication(alert->category, EVENT_UNPROVISIONING, alert->Datetime,
				alert->MessageID, ME_UNCONFIGURED, alert->MessageArguments);
			if (m_eacEnabled)
				raiseGMS_AlertIndication(CATEGORY_EAC, EVENT_EAC_DISABLED, alert->Datetime, ACTIVE_MESSAGEID, ACE_TEXT(""));
		}
		break;
	case EVENT_PROVISIONING_STATE_IN:
		curProvState=PROVISIONING_STATE_IN;
		prevProvState=UpdatePrevProvisioningState(PROVISIONING_STATE_IN);
		if (prevProvState==PROVISIONING_STATE_POST) // unprovision
		{
			raiseGMS_AlertIndication(alert->category, EVENT_UNPROVISIONING, alert->Datetime,
				alert->MessageID, ME_UNCONFIGURED, alert->MessageArguments);
			if (m_eacEnabled)
				raiseGMS_AlertIndication(CATEGORY_EAC, EVENT_EAC_DISABLED, alert->Datetime, ACTIVE_MESSAGEID, ACE_TEXT(""));
		}
		break;
	case EVENT_PROVISIONING_STATE_POST:
		curProvState=PROVISIONING_STATE_POST;
		prevProvState=UpdatePrevProvisioningState(PROVISIONING_STATE_POST);
		if (prevProvState==PROVISIONING_STATE_PRE || prevProvState==PROVISIONING_STATE_IN) // provision
		{
			MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
			mbPtr->data_block(new ACE_Data_Block());
			mbPtr->msg_type(MB_ME_CONFIGURED);
			m_mainService->sendMessage(GMS_CONFIGURATOR,mbPtr);
		}
		break;
	default:
		UNS_ERROR(L"StatusEventHandler::handleProvisioningEvents - invalid OrgEvent.id %d\n", alert->id);
		return;
	}
	SaveCurrentStatus(curProvState, AMT_PROVISIONING_STATE_S);
	NotifyConfigurator(curProvState, CONFIGURATION_TYPE::AMT_PROVISION_CONF);
}

void  StatusEventHandler::handleSystemDefenceEvents(const GMS_AlertIndication *alert)
{
	if (alert->id == EVENT_SYSTEM_DEFENCE_CHANGE)// System Defense Changed (may be started, finished, other level)
	{		
		//This cause recreating the event and by this UNS keep sending this event.
		bool SystemDefenseState = 0;
		if (GetSystemDefenseState(SystemDefenseState))
		{				
			SaveCurrentStatus(SystemDefenseState, SYS_DEF_ACTIVE_S);
			if (SystemDefenseState==0)// off
				raiseGMS_AlertIndication(alert->category, EVENT_SD_FINISHED, alert->Datetime,
					alert->MessageID, EVENT_SYSTEM_SDEFECE_STOPED, alert->MessageArguments);
			else if (SystemDefenseState==1) // on
				raiseGMS_AlertIndication(alert->category, EVENT_SD_STARTED, alert->Datetime,
					alert->MessageID, EVENT_SYSTEM_SDEFECE_STARTED, alert->MessageArguments);
		}
	}	
}

void  StatusEventHandler::handleRemoteDiagnosticEvents(const GMS_AlertIndication *alert)
{
	OPT_IN_STATE UserConsentState;
	switch (alert->id)
	{
	case EVENT_REMOTE_SOL_STARTED:
		m_SOL = 1;
		SaveCurrentStatus(1,SOL_ACTIVE_S);

		break;
	case EVENT_REMOTE_SOL_ENDED:
		SaveCurrentStatus(0,SOL_ACTIVE_S);
		m_SOL = 0;
		break;
	case EVENT_REMOTE_IDER_STARTED:
		SaveCurrentStatus(1,IDER_ACTIVE_S);
		m_IDER = 1;
		if ((m_UserConsentPolicy == ALL_SESSIONS)&& (m_prevUserConsentState != OPT_IN_STATE_RECEIVED) && (m_prevUserConsentState != OPT_IN_STATE_IN_SESSION))   // In Session
			m_prevUserConsentState=OPT_IN_STATE_IN_SESSION; // State;
		break;
	case EVENT_REMOTE_IDER_ENDED:
		SaveCurrentStatus(0,IDER_ACTIVE_S);
		m_IDER = 0;
		GetUserConsentState(&UserConsentState,&m_UserConsentPolicy);// get policy (can be change after UNS started by wsman command)
		if((UserConsentState == OPT_IN_STATE_RECEIVED || UserConsentState == OPT_IN_STATE_IN_SESSION) && (m_UserConsentPolicy == ALL_SESSIONS) && (m_SOL == 0) && (m_KVM == 0))
			raiseGMS_AlertIndication(CATEGORY_USER_CONSENT, EVENT_USER_CONSENT_TIMEOUT_STARTED, alert->Datetime, ACE_TEXT(""),
				EVENT_USER_CONSENT_TIMEOUR_STARTED_MSG, alert->MessageArguments);
		break;
	}
}

void  StatusEventHandler::handleKVMEvents(const GMS_AlertIndication *alert)
{		
	OPT_IN_STATE UserConsentState;
	switch (alert->id)
	{
	case EVENT_KVM_SESSION_REQUESTED:
		SaveCurrentStatus(KVM_REQUESTED,KVM_SESSION_S);
		if (m_UserConsentPolicy != NOT_REQUIRED)
		{
			GetUserConsentState(&UserConsentState,&m_UserConsentPolicy);
			SaveCurrentStatus(UserConsentState,USER_CONSENT_S);
		}
		break;
	case EVENT_KVM_SESSION_STARTED:
		SaveCurrentStatus(KVM_STARTED,KVM_SESSION_S);
		if ((m_UserConsentPolicy != NOT_REQUIRED)&&(m_prevUserConsentState != OPT_IN_STATE_RECEIVED) &&	(m_prevUserConsentState != OPT_IN_STATE_IN_SESSION))
		{
			m_prevUserConsentState=OPT_IN_STATE_IN_SESSION; 
			SaveCurrentStatus(UC_GRANTED,USER_CONSENT_S);
		}
		m_KVM = 1;
		break;
	case EVENT_KVM_SESSION_STOPPED:
		SaveCurrentStatus(KVM_STOPPED,KVM_SESSION_S);
		m_KVM = 0;
		GetUserConsentState(&UserConsentState,&m_UserConsentPolicy); // get policy (can't be change after UNS started by wsman command)
		SaveCurrentStatus(UserConsentState,USER_CONSENT_S);
		if ((UserConsentState == OPT_IN_STATE_RECEIVED || UserConsentState == OPT_IN_STATE_IN_SESSION) && 
			(((m_UserConsentPolicy == ALL_SESSIONS) && (m_SOL == 0) && (m_IDER == 0)) || (m_UserConsentPolicy == KVM_ONLY)))
		{
			raiseGMS_AlertIndication(CATEGORY_USER_CONSENT, EVENT_USER_CONSENT_TIMEOUT_STARTED, alert->Datetime, ACE_TEXT(""),
				EVENT_USER_CONSENT_TIMEOUR_STARTED_MSG, alert->MessageArguments);
		}
		break;
	case EVENT_KVM_DISABLED:
		SaveCurrentStatus(0,KVM_ENABLE_S);
		break;
	case EVENT_KVM_ENABLED:
		SaveCurrentStatus(1,KVM_ENABLE_S);
		break;
	case EVENT_KVM_DATA_CHANNEL:
		SaveCurrentStatus(KVM_DATA_CHANNEL, KVM_SESSION_S);
		break;
	}
}
void  StatusEventHandler::handleUNSEvents(const GMS_AlertIndication *alert)
{
	switch (alert->id)
	{
	case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
		firstPullForEvents();
		GeneratePortFwrdRelatedEvents();
		break;
	}
}
void  StatusEventHandler::handleIPSyncEvents(const GMS_AlertIndication *alert)
{
	switch (alert->id)
	{
	case EVENT_IP_SYNC_DISABLE:
		SaveCurrentStatus(0,IP_SYNC_ENABLE_S);
		NotifyConfigurator(0, CONFIGURATION_TYPE::IP_SYNC_CONF);
		break;
	case EVENT_IP_SYNC_ENABLE:
		SaveCurrentStatus(1,IP_SYNC_ENABLE_S);
		NotifyConfigurator(1, CONFIGURATION_TYPE::IP_SYNC_CONF);
		break;
	case EVENT_IP_REFRESH_LAN:
		UNS_DEBUG(L"IPRefresh LAN\n");
		NotifyIPRefresh(MB_IPREFRESH_LAN);
		break;
	case EVENT_IP_REFRESH_WLAN:
		UNS_DEBUG(L"IPRefresh WLAN\n");
		NotifyIPRefresh(MB_IPREFRESH_WLAN);
		break;
	}
}
void  StatusEventHandler::handleUserConsentEvents(const GMS_AlertIndication *alert)
{	
	switch (alert->id)
	{
	case EVENT_USER_CONSENT_GRANTED:
		SaveCurrentStatus(UC_GRANTED,USER_CONSENT_S);
		m_prevUserConsentState = OPT_IN_STATE_RECEIVED;
		UNS_DEBUG(L"ExtendEvent EVENT_USER_CONSENT_GRANTED\n");
		break;
	case EVENT_USER_CONSENT_REQUESTED:
		SaveCurrentStatus(UC_REQUESTED,USER_CONSENT_S);
		break;
	case EVENT_USER_CONSENT_ENDED:
		SaveCurrentStatus(UC_ENDED,USER_CONSENT_S);
		m_prevUserConsentState = OPT_IN_STATE_NOT_STARTED;
		UNS_DEBUG(L"ExtendEvent EVENT_USER_CONSENT_ENDED\n");
		break;
	case EVENT_USER_CONSENT_CONFIGURATION_CHANGED:   

		if (!m_mainService->GetPortForwardingStarted()) {
			UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting GenerateUCEvents operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
			break;
		}

		GenerateUCEvents(true);
		break;
	}
}

void  StatusEventHandler::handleWlanEvents(const GMS_AlertIndication *alert)
{
	switch (alert->id)
	{
	case EVENT_WLAN_CONTROL_ME:
		SaveCurrentStatus(ME_CONTROL, LINK_CONTROL_S);
		break;
	case EVENT_WLAN_CONTROL_HOST:
		SaveCurrentStatus(HOST_CONTROL, LINK_CONTROL_S);
		break;
	case EVENT_WLAN_PROTECTION_ON_HIGH:
		SaveCurrentStatus(PROTECTION_HIGH, LINK_PROTECTION_S);
		break;
	case EVENT_WLAN_PROTECTION_ON_PASSIVE:
		SaveCurrentStatus(PROTECTION_PASSIVE, LINK_PROTECTION_S);
		break;
	case EVENT_WLAN_PROTECTION_OFF:
		SaveCurrentStatus(PROTECTION_OFF, LINK_PROTECTION_S);
		break;
	case EVENT_WLAN_PROFILE_SYNC_DISABLE:
		SaveCurrentStatus(0, WIFI_PROFILE_SYNC_ENABLE_S);
		NotifyConfigurator(0, CONFIGURATION_TYPE::WIFI_PROFILE_SYNC_CONF);
		break;
	case EVENT_WLAN_PROFILE_SYNC_ENABLE:
		SaveCurrentStatus(1, WIFI_PROFILE_SYNC_ENABLE_S);
		NotifyConfigurator(1, CONFIGURATION_TYPE::WIFI_PROFILE_SYNC_CONF);
		break;
	case EVENT_WIRELESS_STATE_CHANGED:
		{
			bool enabled = false;
			if (GetLocalProfileSynchronizationEnabled(enabled))
			{
				CheckForStatusChange(WIFI_PROFILE_SYNC_ENABLE_S, enabled, PUBLISHEVENTS::WIFIPROFILESYNCENABLE);
			}
			break;
		}
	}
}

void StatusEventHandler::handleTimeSyncEvents(const GMS_AlertIndication *alert)
{
	switch (alert->id)
	{
	case EVENT_TIME_SYNC_DISABLE:
		SaveCurrentStatus(0,TIME_SYNC_ENABLE_S);
		NotifyConfigurator(0, CONFIGURATION_TYPE::TIME_SYNC_CONF);
		break;
	case EVENT_TIME_SYNC_ENABLE:
		SaveCurrentStatus(1,TIME_SYNC_ENABLE_S);
		NotifyConfigurator(1, CONFIGURATION_TYPE::TIME_SYNC_CONF);
		break;
	}
}

bool StatusEventHandler::SaveCurrentStatus(uint32_t status,DATA_NAME storageName)
{
	return DSinstance().SetDataValue(storageName, status,true); 
}

void StatusEventHandler::NotifyConfigurator(int status,CONFIGURATION_TYPE RegValueName)
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration(RegValueName,status));
	mbPtr->msg_type(MB_CONFIGURATION_CHANGE);
	m_mainService->sendMessage(GMS_CONFIGURATOR,mbPtr);      
}   

void StatusEventHandler::NotifyIPRefresh(int eventType)
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(eventType);
	m_mainService->sendMessage(GMS_IPREFRESHSERVICE,mbPtr);
}

bool StatusEventHandler::StatusChanged(DATA_NAME storageName, uint32_t state)
{
	DataStorageWrapper& ds = DSinstance();	
	unsigned long prevState = 0;

	if (ds.GetDataValue(storageName, prevState, true))
	{
		if (prevState != state)
		{
			return true;
		}
	}
	else
		SaveCurrentStatus(state,storageName);

	return false;
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName,bool state, PUBLISHEVENTS ev)
{
	if(StatusChanged(storageName, (uint32_t)state))
		publishEvent(state,ev);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName,Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		publishProvisioningEvent(state);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName,FEATURE_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		publishAMTEnabledEvent(state == ENABLED);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName,UC_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		publishUCStateEvent(state);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName,KVM_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		publishEvent(state, PUBLISHEVENTS::KVMACTIVITY);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName, WLAN_CONTROL_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		PublishWlanControlEvent(state);
}

void StatusEventHandler::CheckForStatusChange(DATA_NAME storageName, WLAN_PROTECTION_STATE state)
{
	if(StatusChanged(storageName, (uint32_t)state))
		PublishWlanProtectionEvent(state);
}

void StatusEventHandler::GenerateUCEvents(bool AmtState)
{
	FuncEntryExit<void> fee(this, L"GenerateUCEvents");

	UC_STATE UCstate = UC_ENDED;
	if (AmtState)
	{
		OPT_IN_STATE UserConsentState = OPT_IN_STATE_NOT_STARTED;
		USER_CONSENT_POLICY UserConsentPolicy;

		if (!GetUserConsentState(&UserConsentState, &UserConsentPolicy))
		{
			UNS_ERROR(L"StatusEventHandler: GetUserConsentState failed\n");
			return;
		}

		if ((UserConsentState == OPT_IN_STATE_REQUESTED) || (UserConsentState == OPT_IN_STATE_DISPLAYED))
			UCstate = UC_REQUESTED;
		else if ((UserConsentState == OPT_IN_STATE_RECEIVED) || (UserConsentState == OPT_IN_STATE_IN_SESSION))
			UCstate = UC_GRANTED;
	}
	CheckForStatusChange(USER_CONSENT_S,UCstate);
}

void StatusEventHandler::GenerateEvents()
{
	FuncEntryExit<void> fee(this, L"GenerateEvents");

	FEATURE_STATE AmtState = NOT_PRESENT;
	if (GetAmtState(AmtState))
	{
		CheckForStatusChange(AMT_ENABLE_S,AmtState);
	}
	else
	{
		UNS_ERROR(L"Failure\n");
		// assume that it is FWreset or HECI disabled
		// nothing to do without HECI
		return;
	}
	GenerateEACEvents(AmtState);
	GenerateSOLIDEREvents(AmtState);
	GenerateSystemDefenseEvents(AmtState);
	GenerateProvisioningEvents(AmtState);
	GenerateMEEvents();
}

void StatusEventHandler::GeneratePortFwrdRelatedEvents()
{
	FuncEntryExit<void> fee(this, L"GeneratePortFwrdRelatedEvents");

	if (!m_mainService->GetPortForwardingStarted()) {
		UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting GeneratePortFwrdRelatedEvents operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
		return;
	}

	FEATURE_STATE AMTState = NOT_PRESENT;
	if (!GetAmtState(AMTState))
	{
		UNS_ERROR(L"Failure\n");
		// assume that it is FWreset or HECI disabled
		// nothing to do without HECI
		return;
	}

	checkForBootReason();

	GenerateSharedStaticIPEvents(AMTState);
	GenerateTimeSyncEvents(AMTState);
	GenerateWiFiProfileSyncEvents(AMTState);

	// Order of GenerateKVMRedirectionEvents and GenerateUCEvents matters (if KVM_REQUESTED state then don't generate UC_REQUESTED event)
	GenerateKVMRedirectionEvents(AMTState); 
	GenerateUCEvents(AMTState);

	GenerateWLANEvents();

	requestDisplaySettings();
}

void StatusEventHandler::GenerateEACEvents(bool AMTstate)
{
	bool EACEnabled=0;//TODO::to check if it is the right default value
	if (AMTstate)
	{
		if (!GetEACEnabled(EACEnabled))
		{
			UNS_ERROR(L"StatusEventHandler: GetEACState failed\n");
			return;
		}
	}
	CheckForStatusChange(EAC_ENABLE_S,EACEnabled, PUBLISHEVENTS::EACENABLE);//TODO:: to check if it is needed when AMTState!=true
}

void StatusEventHandler::GenerateSharedStaticIPEvents(bool AMTstate)
{
	FuncEntryExit<void> fee(this, L"GenerateSharedStaticIPEvents");

	bool IPSyncEnabled = false;//TODO::to check if it is the right default value
	if (AMTstate)
	{
		SyncIpClient syncIpClient;
		if (!syncIpClient.GetSharedStaticIpState(&IPSyncEnabled)) 
		{
			UNS_ERROR(L"StatusEventHandler: GetIPSyncState failed\n");
			return;
		}
	}
	CheckForStatusChange(IP_SYNC_ENABLE_S,IPSyncEnabled, PUBLISHEVENTS::IPSYNCENABLE);//TODO:: to check if it is needed when AMTState!=true
}

void StatusEventHandler::GenerateWiFiProfileSyncEvents(bool AMTstate)
{
	FuncEntryExit<void> fee(this, L"GenerateWiFiProfileSyncEvents");

	bool enabled = false;

	if (AMTstate)
	{
		if (!GetLocalProfileSynchronizationEnabled(enabled))
		{
			UNS_ERROR(L"StatusEventHandler: GetLocalProfileSynchronizationEnabled failed\n");
			return;
		}
	}
	CheckForStatusChange(WIFI_PROFILE_SYNC_ENABLE_S, enabled, PUBLISHEVENTS::WIFIPROFILESYNCENABLE);
}

void StatusEventHandler::GenerateTimeSyncEvents(bool AMTstate)
{
	FuncEntryExit<void> fee(this, L"GenerateTimeSyncEvents");

	bool timeSyncEnabled = false;
	if (AMTstate)
	{
		TimeSynchronizationClient timeClient;

		if (!timeClient.GetLocalTimeSyncEnabledState(timeSyncEnabled))
		{
			UNS_ERROR(L"StatusEventHandler: GetTimeSyncState failed\n");
			return;
		}
	}
	CheckForStatusChange(TIME_SYNC_ENABLE_S,timeSyncEnabled, PUBLISHEVENTS::TIMESYNCENABLE);//TODO:: to check if it is needed when AMTState!=true
}

void StatusEventHandler::GenerateSOLIDEREvents(bool AMTstate)
{
	bool SOLState=0, IDERState=0; 
	if (AMTstate)
	{
		if (!GetSolIderState(SOLState, IDERState))
		{
			UNS_ERROR(L"StatusEventHandler: GetSolIderState failed\n");
			return;
		}
	}
	CheckForStatusChange(SOL_ACTIVE_S,SOLState, PUBLISHEVENTS::SOL);
	CheckForStatusChange(IDER_ACTIVE_S,IDERState, PUBLISHEVENTS::IDER);
}

void StatusEventHandler::GenerateKVMRedirectionEvents(bool AMTstate)
{
	FuncEntryExit<void> fee(this, L"GenerateKVMRedirectionEvents");

	bool KVMEnable = false;
	KVM_STATE KVMState=KVM_STOPPED;
	if (AMTstate)
	{
		if (!GetKVMRedirectionState(KVMEnable, KVMState))
		{
			UNS_ERROR(L"StatusEventHandler: GetKVMRedirectionState failed\n");
		}
	}
	CheckForStatusChange(KVM_ENABLE_S,KVMEnable, PUBLISHEVENTS::KVMSTATE);
	CheckForStatusChange(KVM_SESSION_S,KVMState);

	// If generating KVM_REQUESTED event, don't also generate UC_REQUESTED event
	// since both events have the same string
	if (KVMState == KVM_REQUESTED && StatusChanged(USER_CONSENT_S, UC_REQUESTED))
		SaveCurrentStatus(UC_REQUESTED, USER_CONSENT_S);
}

void StatusEventHandler::GenerateSystemDefenseEvents(bool AMTstate)
{
	bool SysDefState = 0;

	if (AMTstate)
	{
		if (!GetSystemDefenseState(SysDefState))
		{
			UNS_ERROR(L"StatusEventHandler: GetSystemDefenseState failed\n");
			return;
		}
		//if the system defense state have changed - update the registry key and send an event if needed
		if(StatusChanged(SYS_DEF_ACTIVE_S, SysDefState))
			raiseGMS_AlertIndication(CATEGORY_CIRCUIT_BREAKER, EVENT_SYSTEM_DEFENCE_CHANGE, getDateTime(), ACTIVE_MESSAGEID, EVENT_SYSTEM_SDEFECE_CHANGE_MSG);
	}

}

void StatusEventHandler::GenerateProvisioningEvents(bool AMTstate)
{
	Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE ProvState=Intel::MEI_Client::AMTHI_Client::PROVISIONING_STATE_PRE;
	if (AMTstate)
	{
		if (!GetProvisioningState(ProvState))
		{
			UNS_ERROR(L"StatusEventHandler: GetProvisioningState failed\n");
			return;
		}
	}
	CheckForStatusChange(AMT_PROVISIONING_STATE_S,ProvState);
}

void StatusEventHandler::GenerateMEEvents()
{
	bool MEState=0;
	if (!GetMEState(MEState))
	{
		UNS_ERROR(L"StatusEventHandler: GetMEState failed\n");
		return;
	}
	CheckForStatusChange(ME_ENABLE_S,MEState, PUBLISHEVENTS::MESTATE);
}

void StatusEventHandler::GenerateWLANEvents()
{
	FuncEntryExit<void> fee(this, L"GenerateWLANEvents");

	AMTEthernetPortSettingsClient client;
	unsigned int linkPreference, linkControl, linkProtection; 
	bool isLink = false;
	if(!client.GetAMTEthernetPortSettings(&linkPreference, &linkControl, &linkProtection, &isLink))
	{
		UNS_ERROR(L"StatusEventHandler: GetAMTEthernetPortSettings failed\n");
		return;
	}
	if(!isLink)
	{
		UNS_DEBUG(L"No wireless link available\n");
		return;
	}

	CheckForStatusChange(LINK_CONTROL_S, (WLAN_CONTROL_STATE)linkControl);
	if(linkProtection != NOT_EXIST)
		CheckForStatusChange(LINK_PROTECTION_S, (WLAN_PROTECTION_STATE)linkProtection);
}

namespace 
{

	CUSTOMER_TYPE GetPlatformTypeExt(const Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE *Platform)
	{
		if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_FULL_SKU)
		{
			return CORPORATE;
		}
		if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_SMALL_SKU)
		{
			return CONSUMER;
		}
		UNS_ERROR(L"Wrong Customer type %d\n", Platform->Data);
		return WRONG_CUSTOMER_TYPE;
	}
}


bool StatusEventHandler::GetManageabiltyMode(MENAGEABILTY_MODE* pManageMode, CUSTOMER_TYPE* pType)
{
	bool rc = false;
	FuncEntryExit<decltype(rc)> fee(this, L"GetManageabiltyMode", rc);

	namespace MKHI_Client = Intel::MEI_Client::MKHI_Client;

	try
	{	
		MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;
		MKHI_Client::MKHI_PLATFORM_TYPE Platform = getPlatformTypeCommand.getResponse();
		UNS_DEBUG(L"platform=0x%X\n", Platform);
		MenageabiltyModeLogic(Platform, pManageMode);
		rc = true;

		*pType = GetPlatformTypeExt(&Platform);
		if (*pType == WRONG_CUSTOMER_TYPE)
		{
			*pType = CORPORATE;
		}
		UNS_DEBUG(L"CustomerType=%d ManageMode=%d\n", *pType, *pManageMode);
	}
	catch (MKHI_Client::MKHIErrorException& e)
	{	
		UNS_ERROR(L"GetManageabiltyMode failed %u\n", e.getErr());
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{	
		UNS_ERROR(L"GetManageabiltyMode failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetManageabiltyMode %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"Exception in GetManageabiltyMode\n");
	}
	return rc;
}

bool StatusEventHandler::GetAmtState(FEATURE_STATE &AmtState) const
{
	bool rc = false;
	FuncEntryExit<decltype(rc)> fee(this, L"GetAmtState", rc);

	namespace MKHI_Client = Intel::MEI_Client::MKHI_Client;

	try
	{
		MKHI_Client::GetFWCapsCommand getCapabilitiesCommand(MKHI_Client::FEATURES_CAPABLE);
		MKHI_Client::GetFWCapsCommand getFeaturesStateCommand(MKHI_Client::FEATURES_ENABLED);
		MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData = getCapabilitiesCommand.getResponse();
		MKHI_Client::MEFWCAPS_SKU_MKHI StateData = getFeaturesStateCommand.getResponse();
		UNS_DEBUG(L"Capability=0x%X State=0x%X\n", CapabilityData, StateData);
		AmtState = FeatureStateLogic(CapabilityData.Fields.Amt, StateData.Fields.Amt);
		UNS_DEBUG(L"AmtState=%d\n", AmtState);
		rc = true;
	}
	catch (MKHI_Client::MKHIErrorException& e)
	{
		UNS_ERROR(L"GetAmtState failed %u\n", e.getErr());
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"GetAmtState failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetAmtState %C\n", e.what());
	}
	catch (...)
	{
		UNS_ERROR(L"Exception in GetAmtState\n");
	}
	return rc;
}

// Publish AMT enabled event
void StatusEventHandler::publishAMTEnabledEvent(bool enable)
{
	unsigned long eventID= enable ? EVENT_AMT_ENABLE : EVENT_AMT_DISABLE;
	ACE_TString message=AMT_STATE;
	message+=(enable ? ENABLED_STR : DISABLED_STR); 
	raiseGMS_AlertIndication(CATEGORY_GENERAL,eventID,getDateTime(),ACTIVE_MESSAGEID,message);
}

bool StatusEventHandler::GetSolIderState(bool& SOLState, bool& IDERState)
{
	using namespace Intel::MEI_Client;
	bool res = false;

	try
	{
		AMTHI_Client::GetRedirectionSessionsStateCommand getRedirectionState;
		SOLState = getRedirectionState.getResponse().SolOpen;
		IDERState = getRedirectionState.getResponse().IderOpen;		 	
		UNS_DEBUG(L"SOL=%d \t IDER=%d\n",SOLState,IDERState);
		res = true;			
	}
	catch(AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_ERROR(L"GetRedirectionSessionsStateCommand failed, ret=%d\n", e.getErr());
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR(L"GetRedirectionSessionsStateCommand failed %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"GetRedirectionSessionsStateCommand failed\n");
	}

	return res;
}

bool StatusEventHandler::GetSystemDefenseState(bool& SysDefState)
{	
	using namespace Intel::MEI_Client;
	try
	{
		AMTHI_Client::GetSystemDefenseStateCommand getSystemDefenseState;
		SysDefState = getSystemDefenseState.getResponse().SystemDefenseActivated;
		UNS_DEBUG(L"SystemDefense=%d \n",SysDefState);
		return true;
	}
	catch (AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_ERROR(L"GetSystemDefenseState failed, ret=%d\n", e.getErr());
	}
	catch(MEIClientException& e)
	{
		UNS_ERROR(L"GetSystemDefenseState failed %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"GetSystemDefenseState failed\n");
	}

	return false;
}

bool StatusEventHandler::GetMEState(bool& MEState)
{
	// assume that ME is enable when every watch dog command returns true
	using namespace Intel::MEI_Client;

	try
	{
		// DAN:: Need to replace that pooling with device status notification
		AMTHI_Client::GetSystemDefenseStateCommand getSystemDefenseState;
		MEState = true;
		return true;
	}
	catch (MEIClientException& e)
	{	
		UNS_ERROR(L"GetMEState failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetMEState %C\n", e.what());
	}		
	catch(...)
	{
		UNS_ERROR(L"Exception in GetMEState\n");
	}

	MEState = false;
	return false;
}

void StatusEventHandler::MenageabiltyModeLogic(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE platform, MENAGEABILTY_MODE* pMode)
{
	using namespace Intel::MEI_Client::MKHI_Client;
	switch (platform.Fields.Brand) 
	{
	case NoBrand: *pMode=NONE;
		break;
	case BrandAMT: *pMode=VPRO;
		break;
	case BrandStdMng: *pMode=STANDARD;
		break;
	case BrandL3: *pMode=L3;
		break;
	case BrandSBT: *pMode=SBT;
		break;
	default:
		*pMode=NOT_KNOWN;
	}
}

FEATURE_STATE StatusEventHandler::FeatureStateLogic(bool CapabilityBit, bool StateBit)
{
	if (CapabilityBit)
		if (StateBit)
			return ENABLED;
		else
			return DISABLED;
	else
		return NOT_PRESENT;
}

// Publish events: 
//   SOL started/stopped,
//   IDER started/stopped,
//   System Defence started/stopped,
//   KVM started/stopped,
//   KVM enabled/disabled,
//   REMOTE ASSIST enabled/disabled,
//   Manageabilty mode changed,
//   ME STATE enabled/disabled
//	 TimeSync state enabled/disabled
void StatusEventHandler::publishEvent(int action,PUBLISHEVENTS ev)
{
	unsigned short	category; 
	unsigned long	id = EVENT_GENERAL_DEFAULT;      
	ACE_TString   Message;  
	ACE_TString	  actionstr;

	switch (ev)
	{
	case PUBLISHEVENTS::SOL:
		category 	= CATEGORY_REMOTE_DIAGNOSTIC;  
		id 			= action ? EVENT_REMOTE_SOL_STARTED : EVENT_REMOTE_SOL_ENDED;
		Message		= SOL_SESSION; 
		actionstr	= action ? STARTED_STR : ENDED_STR;
		break;
	case PUBLISHEVENTS::IDER:
		category 	= CATEGORY_REMOTE_DIAGNOSTIC;
		id 			= action ? EVENT_REMOTE_IDER_STARTED : EVENT_REMOTE_IDER_ENDED;
		Message		+=IDER_SESSION; 
		actionstr	= action ? STARTED_STR : ENDED_STR;
		break;
	case PUBLISHEVENTS::KVMSTATE:
		category 	= CATEGORY_KVM;
		id 			= action ? EVENT_KVM_ENABLED : EVENT_KVM_DISABLED;
		Message		= KVM_TEXT;
		actionstr	= action ? ENABLED_STR : DISABLED_STR;
		break;
	case PUBLISHEVENTS::KVMACTIVITY:
		category 	= CATEGORY_KVM;	
		Message		= KVM_SESSION;
		switch (action)
		{
		case KVM_REQUESTED:
			id			= EVENT_KVM_SESSION_REQUESTED;
			actionstr	= REQUESTED_STR;
			break;
		case KVM_STARTED:
			id 			= EVENT_KVM_SESSION_STARTED;
			actionstr	= STARTED_STR;
			break;
		case KVM_STOPPED:
			id 			= EVENT_KVM_SESSION_STOPPED;
			actionstr	= STOPED_STR;
			break;
		case KVM_DATA_CHANNEL:
			id			= EVENT_KVM_DATA_CHANNEL;
			actionstr	= DATA_CHANNEL_STR;
			break;
		}
		break;
	case PUBLISHEVENTS::MANAGEMODE:
		category 	= CATEGORY_GENERAL;
		id 			= EVENT_CONTROL_MODE_CHANGE;
		break;
	case PUBLISHEVENTS::MESTATE:
		category 	= CATEGORY_GENERAL;
		id 			= action ? EVENT_ME_ENABLE : EVENT_ME_DISABLE;      
		Message		+=ME_STATE;
		actionstr 	= action ? ENABLED_STR : DISABLED_STR;   
		break;
	case PUBLISHEVENTS::HECISTATE:
		category 	= CATEGORY_UNS;
		id 			= action ? EVENT_SERVICE_HECI_ENABLE : EVENT_SERVICE_HECI_DISABLE;      
		Message		= MEI_DRIVER;
		actionstr 	= action ? ENABLED_STR : DISABLED_STR;   
		break;	
	case PUBLISHEVENTS::EACENABLE:
		category 	= CATEGORY_EAC;
		id 			= action ? EVENT_EAC_ENABLED : EVENT_EAC_DISABLED;
		break;
	case PUBLISHEVENTS::IPSYNCENABLE:
		category 	= CATEGORY_IPSYNC;
		Message		= IP_SYNC_ENABLE;
		id 			= action ? EVENT_IP_SYNC_ENABLE : EVENT_IP_SYNC_DISABLE;
		actionstr 	= action ? ENABLED_STR : DISABLED_STR; 
		break;
	case PUBLISHEVENTS::WIFIPROFILESYNCENABLE:
		category	= CATEGORY_WLAN;
		id			= action ? EVENT_WLAN_PROFILE_SYNC_ENABLE : EVENT_WLAN_PROFILE_SYNC_DISABLE;
		break;
	case PUBLISHEVENTS::TIMESYNCENABLE:
		category 	= CATEGORY_TIMESYNC;
		Message		= TIME_SYNC_ENABLE;
		id 			= action ? EVENT_TIME_SYNC_ENABLE : EVENT_TIME_SYNC_DISABLE;
		actionstr 	= action ? ENABLED_STR : DISABLED_STR; 
		break;
	default:
		return;
	}
	Message += actionstr;   
	raiseGMS_AlertIndication(category,id,getDateTime(),ACTIVE_MESSAGEID,Message);
}

void StatusEventHandler::raiseGMS_AlertIndication(unsigned short category, unsigned long id, const std::string &Datetime,
	const ACE_TString &MessageID, const ACE_TString &Message, const std::vector<ACE_TString> &MessageArguments)
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);

	if (MessageArguments.empty())
	{
		mbPtr->data_block(new GMS_AlertIndication(category,id,Datetime,MessageID,Message));
	}
	else
	{
		mbPtr->data_block(new GMS_AlertIndication(category,id,Datetime,MessageID,Message,MessageArguments[0]));
	}
	mbPtr->msg_type(MB_PUBLISH_EVENT);
	m_mainService->sendMessage(EVENT_MANAGER,mbPtr);
}

void StatusEventHandler::raiseGMS_AlertIndication(unsigned short category, unsigned long id, const std::string &Datetime,
	const ACE_TString &MessageID, const ACE_TString &Message)
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new GMS_AlertIndication(category, id, Datetime, MessageID, Message));
	mbPtr->msg_type(MB_PUBLISH_EVENT);
	m_mainService->sendMessage(EVENT_MANAGER,mbPtr);
}

Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE StatusEventHandler::UpdatePrevProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE State)
{
	Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE prevState = m_prevProvState;
	m_prevProvState = State;
	return prevState;
}

void StatusEventHandler::SafeSetProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE State)
{
	std::lock_guard<std::mutex> lock(m_semAMTEnabled);
	m_prevProvState = State;
}
 
bool StatusEventHandler::GetUserConsentState(OPT_IN_STATE* pState, USER_CONSENT_POLICY* pPolicy)
{
	CancelOptInClient _CancelOptInClient;
	short UserConsentPolicy;
	short UserConsentState;

	if (!_CancelOptInClient.GetUserConsentState(&UserConsentState, &UserConsentPolicy))
		return false;
	*pPolicy = (USER_CONSENT_POLICY)UserConsentPolicy;
	*pState = (OPT_IN_STATE)UserConsentState;
	UNS_DEBUG(L"GetUserConsentState State=%d, Policy=%d\n",*pState,*pPolicy);
	return true;
}

#ifdef WIN32
bool StatusEventHandler::GetLocalProfileSynchronizationEnabled(bool &enabled)
{
	WlanWSManClient WlanWSMan;
	bool ret;

	ret = WlanWSMan.LocalProfileSynchronizationEnabled(enabled);
	if (!ret) {
		UNS_ERROR(L"StatusEventHandler:: WlanWSMan failed to receive current state\n");
		return false;
	}
	if (!enabled)
		UNS_DEBUG(L"StatusEventHandler:: LocalProfileSynchronization disabled in FW\n");

	return true;
}
#else // WIN32
bool StatusEventHandler::GetLocalProfileSynchronizationEnabled(bool &enabled)
{
	enabled = false;
	UNS_DEBUG(L"StatusEventHandler:: WiFiProfileSync supported only on Windows\n");
	return true;
}
#endif // WIN32

// Publish Provisioning event
void StatusEventHandler::publishProvisioningEvent(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE state)
{
	using namespace Intel::MEI_Client::AMTHI_Client;
	unsigned long ProvisioningEvent;
	ACE_TString ProvisioningEventStr;
	switch (state)
	{
	case PROVISIONING_STATE_PRE: 
		ProvisioningEvent = EVENT_PROVISIONING_STATE_PRE;
		ProvisioningEventStr = ACE_TEXT("PRE");
		break;
	case PROVISIONING_STATE_IN: 
		ProvisioningEvent = EVENT_PROVISIONING_STATE_IN;
		ProvisioningEventStr = ACE_TEXT("IN");
		break;
	case PROVISIONING_STATE_POST: 
		ProvisioningEvent = EVENT_PROVISIONING_STATE_POST;
		ProvisioningEventStr = ACE_TEXT("POST");
		break;
	default:
		UNS_ERROR(L"Wrong PROVISIONING_STATE=%d \n", state);
		return;
	} 
	raiseGMS_AlertIndication(CATEGORY_GENERAL,ProvisioningEvent,getDateTime(),ACTIVE_MESSAGEID,PROVISIONING+ProvisioningEventStr);
}

bool StatusEventHandler::GetProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE& ProvState)
{
	using namespace Intel::MEI_Client::AMTHI_Client;
	using namespace Intel::MEI_Client;

	try
	{
		GetProvisioningStateCommand getProvisioningStateCommand;
		ProvState = getProvisioningStateCommand.getResponse().ProvisioningState;
		return true;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR(L"GetProvisioningStateCommand failed ret=%C\n", e.getErr());
		return false;
	}
	catch (MEIClientException& e) //original error handling was just returning "false"
	{	
		UNS_ERROR(L"GetProvisioningStateCommand failed %C\n",e.what());
		return false;
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetProvisioningStateCommand %C\n", e.what());
		return false;
	}
	catch(...)
	{
		UNS_ERROR(L"Exception in GetProvisioningStateCommand\n");
		return false;
	}

}

void StatusEventHandler::firstPullForEvents(void)
{
	FuncEntryExit<void> fee(this, L"firstPullForEvents");

	if (!m_firstPullForEvents)
	{
		UNS_DEBUG(L"firstPullForEvents: Not first time\n");
		return;
	}

	m_firstPullForEvents = false;
	DataStorageWrapper& ds = DSinstance();
	using namespace Intel::MEI_Client;

	if (!GetAmtState(m_prevAmtState))
	{
		unsigned long val;
		if (!ds.GetDataValue(AMT_ENABLE_S, val, true))
		{
			m_prevAmtState = NOT_PRESENT;
		}
		else
		{
			m_prevAmtState = (FEATURE_STATE)val;
		}
	}

	GetManageabiltyMode(&m_prevManageMode, &m_prevCustomerType);

	// provisioning state		
	AMTHI_Client::AMT_PROVISIONING_STATE prevProvState = AMTHI_Client::PROVISIONING_STATE_PRE;
	unsigned long val = 0;
	if (!ds.GetDataValue(AMT_PROVISIONING_STATE_S, val, true))
	{
		if (m_prevCustomerType == CORPORATE)
		{
			GetProvisioningState(prevProvState);
		}
	}
	else
	{
		prevProvState = (AMTHI_Client::AMT_PROVISIONING_STATE)val;
	}
	SafeSetProvisioningState(prevProvState);
}

void StatusEventHandler::checkForBootReason()
{
	FuncEntryExit<void> fee(this, L"checkForBootReason");

	if (!m_firstCheckForBootReason)
	{
		UNS_DEBUG(L"checkForBootReason: Not first time\n");
		return;
	}

	m_firstCheckForBootReason = false;
	DataStorageWrapper& ds = DSinstance();
	using namespace Intel::MEI_Client;
	::uint32_t Reason,TimeStamp;		
	try
	{
		AMTHI_Client::GetLastHostResetReasonCommand getLastHostResetReasonCommand;

		Reason = getLastHostResetReasonCommand.getResponse().Reason;
		TimeStamp = getLastHostResetReasonCommand.getResponse().RemoteControlTimeStamp;
		bool bNewRemoteReboot=false;
		if (Reason==0) 	// RemoteControl=0, Other=1
		{
			unsigned long prevRemoteRebootTimeStamp = 0;

			if (ds.GetDataValue(REMOTE_REBOOT_S, prevRemoteRebootTimeStamp))
			{
				if (prevRemoteRebootTimeStamp != TimeStamp)
				{
					bNewRemoteReboot = true;
				}
			}
			else
			{
				bNewRemoteReboot = true;
			}
			if (bNewRemoteReboot)
			{
				publishRemoteRebootEvent();
				ds.SetDataValue(REMOTE_REBOOT_S, (unsigned long)TimeStamp, true);
			}
		}
		//alarm clock event
		if (m_prevManageMode== L3 ||
			m_prevManageMode== SBT ||
			m_prevManageMode== VPRO)
		{
			SX_STATES previousSXState;
			if (GetAlarmClockBootEvent(previousSXState))
			{
				publishAlarmClockBoot(previousSXState);
			}
		}
	}
	catch(AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_ERROR(L"GetLastHostResetReasonCommand failed, ret=%d\n", e.getErr());
	}	
	catch (MEIClientException& e)
	{
		UNS_ERROR(L"GetLastHostResetReasonCommand failed %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"GetLastHostResetReasonCommand failed\n");
	}
}


// Publish Remote Reboot event
void StatusEventHandler::publishRemoteRebootEvent()
{
	raiseGMS_AlertIndication(CATEGORY_GENERAL, EVENT_REMOTE_REBOOT, getDateTime(), ACTIVE_MESSAGEID, LAST_REMOTE_REBOOT_STR);
}

//publish Host boot by Alarm clock
void StatusEventHandler::publishAlarmClockBoot(SX_STATES previousSXState)
{
	std::vector<ACE_TString>  MessageArguments;
	MessageArguments.push_back(GetSXState(previousSXState));
	raiseGMS_AlertIndication(CATEGORY_GENERAL, EVENT_ALARM_CLOCK_BOOT, getDateTime(), ACTIVE_MESSAGEID, ALARM_CLOCK_BOOT_STR, MessageArguments);
}

ACE_TString StatusEventHandler::GetSXState(SX_STATES previousSXState)
{
	ACE_TString ret;
	switch (previousSXState)
	{

	case SX_Other:
		ret = ACE_TEXT("Other");
		break;
	case SX_S0:
		ret = ACE_TEXT("S0");
		break;
	case SX_S1:
		ret = ACE_TEXT("S1");
		break;
	case SX_S2:
		ret = ACE_TEXT("S2");
		break;
	case SX_S3:
		ret = ACE_TEXT("S3");
		break;
	case SX_S4:
		ret = ACE_TEXT("S4");
		break;
	case SX_S5:
		ret = ACE_TEXT("S5");
		break;
	default:
		ret = ACE_TEXT("Unknown");
		break;
	}
	return ret;
}

bool StatusEventHandler::GetEACEnabled(bool& enable)
{
	using namespace Intel::MEI_Client;	
	try
	{		
		AMTHI_Client::GetEACStateCommand getEACStateCommand;
		AMTHI_Client::AMT_BOOLEAN Eac_enabled = getEACStateCommand.getResponse().EacEnabled;
		std::lock_guard<std::mutex> lock(m_semAMTEnabled);
		enable = m_eacEnabled = (Eac_enabled != AMTHI_Client::AMT_FALSE);
	}
	catch (AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_ERROR(L"GetEACStateCommand failed ret=%d\n", e.getErr());
		return false;
	}
	catch (MEIClientException& e)
	{	
		UNS_ERROR(L"GetEACStateCommand failed %C\n", e.what());
		return false;
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetEACStateCommand %C\n", e.what());
		return false;
	}
	catch(...)
	{
		UNS_ERROR(L"Exception in GetEACStateCommand\n");
		return false;
	}

	return true;
}

bool StatusEventHandler::GetAlarmClockBootEvent(SX_STATES &previousSXState)
{
	HostBootReasonClient client;

	HOST_RESET_REASON int_resetReason;
	SX_STATES int_previousSXState;
	if (client.GetHostResetReason(int_resetReason, int_previousSXState))
	{
		if (int_resetReason == Alarm)
		{
			previousSXState = int_previousSXState;
			return true;
		}
	}
	return false;
}

bool StatusEventHandler::GetKVMRedirectionState(bool& enable,KVM_STATE& connected)
{
	KVMWSManClient Client;
	OPT_IN_STATE UserConsentState = OPT_IN_STATE_NOT_STARTED;
	USER_CONSENT_POLICY UserConsentPolicy;
	unsigned short state;

	if (Client.KVMRedirectionState(&state))
	{
		UNS_DEBUG(L"StatusEventHandler: KVMRedirectionState=%u\n", state);
		switch (state)
		{
		case KVM_ENABLED_AND_CONNECTED: 
			enable=true;
			connected=KVM_STARTED;
			if (GetUserConsentState(&UserConsentState, &UserConsentPolicy) &&
			   (UserConsentState == OPT_IN_STATE_REQUESTED || UserConsentState == OPT_IN_STATE_DISPLAYED))
				connected=KVM_REQUESTED;
			return true;
		case KVM_DISABLED: 
			enable=false;
			connected=KVM_STOPPED;
			return true;
		case KVM_ENABLED_AND_DISCONNECTED: 
			enable=true;
			connected=KVM_STOPPED;
			return true;
		default:
			UNS_ERROR(L"Wrong KVMRedirectionState=%u\n", state);
			return false;
		}
	}
	return false;
}


void StatusEventHandler::publishUCStateEvent(UC_STATE state)
{
	ACE_TString actionstr;
	unsigned long	id = EVENT_GENERAL_DEFAULT;

	switch (state)
	{
	case UC_REQUESTED:
		id = EVENT_USER_CONSENT_REQUESTED;
		actionstr=REQUESTED_STR;
		break;
	case UC_GRANTED:
		id = EVENT_USER_CONSENT_GRANTED;
		actionstr=GRANTED_STR;
		break;
	case UC_ENDED:
		id = EVENT_USER_CONSENT_ENDED;
		actionstr=ENDED_STR;
		break;
	} 
	raiseGMS_AlertIndication(CATEGORY_USER_CONSENT, id, getDateTime(), ACTIVE_MESSAGEID, USER_CONSENT_STR + actionstr);
}

void StatusEventHandler::PublishWlanProtectionEvent(WLAN_PROTECTION_STATE state)
{
	ACE_TString message;
	unsigned long id = EVENT_GENERAL_DEFAULT;
	switch(state)
	{
	case PROTECTION_HIGH:
		id = EVENT_WLAN_PROTECTION_ON_HIGH;
		message = LINK_PROTECTION_HIGH_MSG;
		break;
	case PROTECTION_PASSIVE:
		id =EVENT_WLAN_PROTECTION_ON_PASSIVE;
		message = LINK_PROTECTION_PASSIVE_MSG;
		break;
	case PROTECTION_OFF:
		id =EVENT_WLAN_PROTECTION_OFF;
		message = LINK_PROTECTION_OFF_MSG;
		break;
	}
	raiseGMS_AlertIndication(CATEGORY_WLAN,id,getDateTime(),ACTIVE_MESSAGEID,message);
}

void StatusEventHandler::PublishWlanControlEvent(WLAN_CONTROL_STATE state)
{
	ACE_TString message;
	unsigned long id = EVENT_GENERAL_DEFAULT;

	switch(state)
	{
	case ME_CONTROL:
		id = EVENT_WLAN_CONTROL_ME;
		message = LINK_CONTROL_ME_MSG;
		break;
	case HOST_CONTROL:
		id = EVENT_WLAN_CONTROL_HOST;
		message = LINK_CONTROL_HOST_MSG;
		break;
	}

	raiseGMS_AlertIndication(CATEGORY_WLAN,id,getDateTime(),ACTIVE_MESSAGEID,message);
}

// Request display settings from IMSS - called only after the machine state was updated in the registry 
void StatusEventHandler::requestDisplaySettings()
{	
	FuncEntryExit<void> fee(this, L"requestDisplaySettings");
	// Check if the machine is provisioned and KVM enabled
	DataStorageWrapper& ds = DSinstance();	
	unsigned long state = 0;
	if (!ds.GetDataValue(KVM_ENABLE_S, state, true))
	{
		UNS_ERROR(L"Failed to get KVM status\n");
		return;
	}
	if (state==false)
		return;

	if (!ds.GetDataValue(AMT_PROVISIONING_STATE_S, state, true))
	{
		UNS_ERROR(L"Failed to get provisioning state\n");
		return;
	}
	if (state!=Intel::MEI_Client::AMTHI_Client::PROVISIONING_STATE_POST)
		return;
	raiseGMS_AlertIndication(CATEGORY_KVM,EVENT_KVM_SCREEN_SETTING_UPDATE,getDateTime(),ACTIVE_MESSAGEID, ACE_TEXT(""));
	UNS_DEBUG(L"Sending request for display settings\n");
}

LMS_SUBSERVICE_DEFINE (STATUSEVENTHANDLER, StatusEventHandler)
