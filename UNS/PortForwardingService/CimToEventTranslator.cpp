/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: CimToEventTranslator.cpp

--*/

#include "CimToEventTranslator.h"
#include "ace/OS_NS_time.h"
#include "ace/Date_Time.h"
#include "UNSEventsDefinition.h"
#include "Tools.h"
#include <sstream>


// check with actual CIM 
const ACE_TString SEPERATOR(ACE_TEXT(" - "));

const ACE_TString AGENT_PRSENCE_1(ACE_TEXT("iAMT0002"));	// 0  - The agent has not started
const ACE_TString AGENT_PRSENCE_2(ACE_TEXT("iAMT0003"));	// 0  - The agent has stopped
const ACE_TString AGENT_PRSENCE_4(ACE_TEXT("iAMT0005"));	// 0  - The agent has expired

const ACE_TString GENERAL_NOTIFICATION_1(ACE_TEXT("iAMT0050 - 0"));	// 1 160 
const ACE_TString GENERAL_NOTIFICATION_2(ACE_TEXT("iAMT0055 - 0"));	// 1 11
const ACE_TString GENERAL_NOTIFICATION_3(ACE_TEXT("iAMT0055 - 1"));	// 1 12
const ACE_TString GENERAL_NOTIFICATION_4(ACE_TEXT("iAMT0055 - 2"));	// 1 13  - EVENT_PROVISIONING_STATE_POST
const ACE_TString GENERAL_NOTIFICATION_5(ACE_TEXT("iAMT0057 - 0"));	// 1 14
const ACE_TString GENERAL_NOTIFICATION_6(ACE_TEXT("iAMT0055 - 3"));	// 1 15
const ACE_TString GENERAL_NOTIFICATION_7(ACE_TEXT("iAMT0055 - 4"));	// 1 16 
const ACE_TString GENERAL_NOTIFICATION_8(ACE_TEXT("iAMT0071")); // AMT Disable Attempt detected


const ACE_TString CIRCUITBREAKER_NOTIFICATION_1(ACE_TEXT("iAMT0050 - 16"));	// 2 20
const ACE_TString CIRCUITBREAKER_NOTIFICATION_2(ACE_TEXT("iAMT0050 - 17"));	// 2 21
const ACE_TString CIRCUITBREAKER_NOTIFICATION_3(ACE_TEXT("iAMT0050 - 18"));	// 2 22
const ACE_TString CIRCUITBREAKER_NOTIFICATION_4(ACE_TEXT("iAMT0050 - 19")); // 2 23
const ACE_TString CIRCUITBREAKER_NOTIFICATION_5(ACE_TEXT("iAMT0056 - 0"));	// 2 24

const ACE_TString EAC_NOTIFICATION_1(ACE_TEXT("iAMT0050 - 32"));	// 3 30
const ACE_TString EAC_NOTIFICATION_2(ACE_TEXT("iAMT0050 - 33"));	// 3 31 
const ACE_TString EAC_NOTIFICATION_3(ACE_TEXT("iAMT0050 - 34"));	// 3 32 

const ACE_TString REMOTE_DIAGNOSTIC_1(ACE_TEXT("iAMT0050 - 48"));	// 4 40
const ACE_TString REMOTE_DIAGNOSTIC_2(ACE_TEXT("iAMT0050 - 49"));	// 4 41
const ACE_TString REMOTE_DIAGNOSTIC_3(ACE_TEXT("iAMT0050 - 50"));	// 4 42
const ACE_TString REMOTE_DIAGNOSTIC_4(ACE_TEXT("iAMT0050 - 51"));	// 4 43

const ACE_TString WLAN_NOTIFICATION_1(ACE_TEXT("iAMT0050 - 66"));	// 5 50
const ACE_TString WLAN_NOTIFICATION_2(ACE_TEXT("iAMT0050 - 67"));	// 5 52
const ACE_TString WLAN_NOTIFICATION_3(ACE_TEXT("iAMT0050 - 68"));	// 5 51
const ACE_TString WLAN_NOTIFICATION_4(ACE_TEXT("iAMT0050 - 69"));	// 5 53
const ACE_TString WLAN_NOTIFICATION_5(ACE_TEXT("iAMT0054 - 70"));	// 5 54
const ACE_TString WLAN_NOTIFICATION_6(ACE_TEXT("iAMT0049 - 0"));	// 5 55
const ACE_TString WLAN_NOTIFICATION_7(ACE_TEXT("iAMT0049 - 1"));	// 5 56
const ACE_TString WLAN_NOTIFICATION_8(ACE_TEXT("iAMT0068 - 2"));	// 5 47  - WLAN Link Protection is ON (HIGH)
const ACE_TString WLAN_NOTIFICATION_9(ACE_TEXT("iAMT0068 - 1"));	// 5 48	 - WLAN Link Protection is ON (PASSIVE)
const ACE_TString WLAN_NOTIFICATION_10(ACE_TEXT("iAMT0068 - 0"));	// 5 49	 - WLAN Link Protection is OFF
const ACE_TString WLAN_CONTROL_NOTIFICATION_2(ACE_TEXT("iAMT0066 - 1"));	// 5 57  - WLAN Link Control set to ME	
const ACE_TString WLAN_CONTROL_NOTIFICATION_1(ACE_TEXT("iAMT0066 - 0"));	// 5 58  - WLAN Link Control set to HOST	

const ACE_TString SECIO_NOTIFICATION_1(ACE_TEXT("iAMT0051 - 0"));	// 6 60
const ACE_TString SECIO_NOTIFICATION_2(ACE_TEXT("iAMT0051 - 1"));// 6 61
const ACE_TString SECIO_NOTIFICATION_3(ACE_TEXT("iAMT0051 - 2"));	// 6 62
const ACE_TString SECIO_NOTIFICATION_4(ACE_TEXT("iAMT0060 - 0"));	// 6 63

const ACE_TString KVM_NOTIFICATION_1(ACE_TEXT("iAMT0052 - 0"));	// 7 70
const ACE_TString KVM_NOTIFICATION_2(ACE_TEXT("iAMT0052 - 1"));	// 7 71  - KVM_SESSION_STARTED
const ACE_TString KVM_NOTIFICATION_3(ACE_TEXT("iAMT0052 - 2"));	// 7 72  - EVENT_KVM_SESSION_STOPPED - KVM_SESSION_FINISHED
const ACE_TString KVM_NOTIFICATION_4(ACE_TEXT("iAMT0059 - 0"));	// 7 73
const ACE_TString KVM_NOTIFICATION_5(ACE_TEXT("iAMT0059 - 1"));	// 7 74
const ACE_TString KVM_NOTIFICATION_6(ACE_TEXT("iAMT0052 - 3"));	// 7 76  - EVENT_KVM_DATA_CHANNEL


const ACE_TString RCS_NOTIFICATION_5(ACE_TEXT("iAMT0058 - 0"));	// 8 84  - EVENT_RCS_TUNNEL_CLOSE - CIRA_DISCONNECTED
const ACE_TString RCS_NOTIFICATION_6(ACE_TEXT("iAMT0058 - 1"));	// 8 85

const ACE_TString IPSYNC_NOTIFICATION_1(ACE_TEXT("iAMT0062 - 0"));	// 10 110 - EVENT_IpSync disabled
const ACE_TString IPSYNC_NOTIFICATION_2(ACE_TEXT("iAMT0062 - 1"));	// 10 111 - EVENT_IpSync enabled

const ACE_TString PROXY_NOTIFICATION_1(ACE_TEXT("iAMT0063 - 0"));	// 11 120 - EVENT_HttpProxySync disabled
const ACE_TString PROXY_NOTIFICATION_2(ACE_TEXT("iAMT0063 - 1"));	// 11 121 - EVENT_HttpProxySync enabled

const ACE_TString USER_CONSENT_NOTIFICATION_1(ACE_TEXT("iAMT0064 - 2"));	// 13 130 - User consent ended		
const ACE_TString USER_CONSENT_NOTIFICATION_2(ACE_TEXT("iAMT0064 - 1"));	// 13 131 - User consent granted		
const ACE_TString USER_CONSENT_NOTIFICATION_3(ACE_TEXT("iAMT0064 - 3"));	// 13 132 - User consent requested		
const ACE_TString USER_CONSENT_NOTIFICATION_4(ACE_TEXT("iAMT0064 - 4"));	// 13 134 - User consent configuration changed

const ACE_TString IPREFRESH_NOTIFICATION_1(ACE_TEXT("iAMT0065 - 0"));	// 0 – IpRefresh for LAN		
const ACE_TString IPREFRESH_NOTIFICATION_2(ACE_TEXT("iAMT0065 - 1"));	// 1 – IpRefresh for WLAN	

const ACE_TString TIMESYNC_NOTIFICATION_1(ACE_TEXT("iAMT0069 - 0"));  // 15 270 - EVENT_TIME_SYNC_DISABLE
const ACE_TString TIMESYNC_NOTIFICATION_2(ACE_TEXT("iAMT0069 - 1"));  // 15 271 - EVENT_TIME_SYNC_ENABLE

const ACE_TString GRACEFUL_PWR_OPERATION_1(ACE_TEXT("iAMT0067 - 0")); // Graceful shutdown
const ACE_TString GRACEFUL_PWR_OPERATION_2(ACE_TEXT("iAMT0067 - 1")); // Graceful reboot
const ACE_TString GRACEFUL_PWR_OPERATION_3(ACE_TEXT("iAMT0067 - 2")); // Graceful sleep
const ACE_TString GRACEFUL_PWR_OPERATION_4(ACE_TEXT("iAMT0067 - 3")); // Graceful hibernate

const ACE_TString EVENTS_AGENTS_HEADER(ACE_TEXT("Local Software Monitor has detected that agent "));
const ACE_TString EVENTS_AGENT_NOT_STARTED_SUFFIX(ACE_TEXT(" has not started"));
const ACE_TString EVENTS_AGENT_STOPED_SUFFIX(ACE_TEXT(" has stopped"));
const ACE_TString EVENTS_AGENT_EXPIRED_SUFFIX(ACE_TEXT(" has expired"));

CimToEventTranslator::CimToEventTranslator()
{
	
	m_eventsMap.bind(AGENT_PRSENCE_1, GmsEventType(CATEGORY_GENERAL, EVENT_AGENT_1));
	m_eventsMap.bind(AGENT_PRSENCE_2, GmsEventType(CATEGORY_GENERAL, EVENT_AGENT_2));
	m_eventsMap.bind(AGENT_PRSENCE_4, GmsEventType(CATEGORY_GENERAL, EVENT_AGENT_4));

	m_eventsMap.bind(GENERAL_NOTIFICATION_1, GmsEventType(CATEGORY_GENERAL, EVENT_AMT_ENABLE,"Manageability enabled")); //User Notification Alert - Manageability is enabled
	m_eventsMap.bind(GENERAL_NOTIFICATION_2, GmsEventType(CATEGORY_GENERAL, EVENT_PROVISIONING_STATE_PRE,"Provisioning state PRE")); //User Notification Alert   - Provisioning State Change Notification %1s
	m_eventsMap.bind(GENERAL_NOTIFICATION_3, GmsEventType(CATEGORY_GENERAL, EVENT_PROVISIONING_STATE_IN,"Provisioning state IN")); //User Notification Alert   - Provisioning State Change Notification %1s
	 m_eventsMap.bind(GENERAL_NOTIFICATION_4, GmsEventType(CATEGORY_GENERAL, EVENT_PROVISIONING_STATE_POST,"Provisioning state POST")); //User Notification Alert   - Provisioning State Change Notification %1s
	 m_eventsMap.bind(GENERAL_NOTIFICATION_5, GmsEventType(CATEGORY_GENERAL, EVENT_NETWORK_STATE_CHANGE,"Network state change")); //User Notification Alert   - Network State Change Notification
	 m_eventsMap.bind(GENERAL_NOTIFICATION_6, GmsEventType(CATEGORY_GENERAL, EVENT_UNPROVISIONES_STARTED,"Unprovisioning started")); //User Notification Alert   - Provisioning State Change Notification %1s
	 m_eventsMap.bind(GENERAL_NOTIFICATION_7, GmsEventType(CATEGORY_GENERAL, EVENT_CONTROL_MODE_CHANGE)); 
	m_eventsMap.bind(GENERAL_NOTIFICATION_8, GmsEventType(CATEGORY_GENERAL, EVENT_AMT_DISABLE_ATTEMPT, "Intel(R) AMT disable attempt detected"));

	 m_eventsMap.bind(CIRCUITBREAKER_NOTIFICATION_1, GmsEventType(CATEGORY_CIRCUIT_BREAKER, EVENT_NETWORK_TRAFFIC_TX_CEASED, "System Defense TX traffic ceased")); //User Notification Alert   - Circuit Breaker notification. (CB Drop TX filter hit. )
	 m_eventsMap.bind(CIRCUITBREAKER_NOTIFICATION_2, GmsEventType(CATEGORY_CIRCUIT_BREAKER, EVENT_NETWORK_CONNECTIVITY_TX_REDUCED, "System Defense TX traffic reduced")); //User Notification Alert   - Circuit Breaker notification. (CB Rate Limit TX filter hit.)
	 m_eventsMap.bind(CIRCUITBREAKER_NOTIFICATION_3, GmsEventType(CATEGORY_CIRCUIT_BREAKER, EVENT_NETWORK_TRAFFIC_RX_CEASED, "System Defense RX traffic ceased")); //User Notification Alert   - Circuit Breaker notification. (CB Drop RX filter hit. ) 
	 m_eventsMap.bind(CIRCUITBREAKER_NOTIFICATION_4, GmsEventType(CATEGORY_CIRCUIT_BREAKER, EVENT_NETWORK_CONNECTIVITY_RX_REDUCED, "System Defense RX traffic reduced")); //User Notification Alert   - Circuit Breaker notification. (CB Rate Limit RX filter hit.)
	 m_eventsMap.bind(CIRCUITBREAKER_NOTIFICATION_5, GmsEventType(CATEGORY_CIRCUIT_BREAKER, EVENT_SYSTEM_DEFENCE_CHANGE, "System Defense state changed")); //User Notification Alert   - System Defence Change Notification

	 m_eventsMap.bind(EAC_NOTIFICATION_1, GmsEventType(CATEGORY_EAC, EVENT_EAC_NOTIFICATION ,"EAC notification")); //User Notification Alert   - EAC notification
	 m_eventsMap.bind(EAC_NOTIFICATION_2, GmsEventType(CATEGORY_EAC, EVENT_EAC_ENABLED));  
	 m_eventsMap.bind(EAC_NOTIFICATION_3, GmsEventType(CATEGORY_EAC, EVENT_EAC_DISABLED));  

	 m_eventsMap.bind(REMOTE_DIAGNOSTIC_1, GmsEventType(CATEGORY_REMOTE_DIAGNOSTIC, EVENT_REMOTE_SOL_STARTED, "Remote SOL session started")); //User Notification Alert   - Remote diagnostics. (Remote Redirection session started (SOL).)
	 m_eventsMap.bind(REMOTE_DIAGNOSTIC_2, GmsEventType(CATEGORY_REMOTE_DIAGNOSTIC, EVENT_REMOTE_SOL_ENDED, "Remote SOL session ended")); //User Notification Alert   - Remote diagnostics. (Remote Redirection session stopped (SOL).)
	 m_eventsMap.bind(REMOTE_DIAGNOSTIC_3, GmsEventType(CATEGORY_REMOTE_DIAGNOSTIC, EVENT_REMOTE_IDER_STARTED, "Remote USBr session started")); //User Notification Alert   - Remote diagnostics. (Remote Redirection session started (USB-R).)
	 m_eventsMap.bind(REMOTE_DIAGNOSTIC_4, GmsEventType(CATEGORY_REMOTE_DIAGNOSTIC, EVENT_REMOTE_IDER_ENDED, "Remote USBr session ended")); //User Notification Alert   - Remote diagnostics. (Remote Redirection session stopped (USB-R).)

	 m_eventsMap.bind(WLAN_NOTIFICATION_1, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROFILE_INSUFFICIENT, ""));
	 m_eventsMap.bind(WLAN_NOTIFICATION_2, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_SESSION_ESTABLISHED, "WLAN Link Preference set to Intel(R) ME")); //User Notification Alert   - WLAN notification. (Management device overrides host Radio.)
	 m_eventsMap.bind(WLAN_NOTIFICATION_3, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_SECURITY_INSUFFICIENT, ""));
	 m_eventsMap.bind(WLAN_NOTIFICATION_4, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_SESSION_ENDED, "WLAN Link Preference set to Host (Operating system)")); //User Notification Alert   - WLAN notification. (Management device relinquishes control over host Radio.)
	 m_eventsMap.bind(WLAN_NOTIFICATION_5, GmsEventType(CATEGORY_WLAN, EVENT_WIRELESS_STATE_CHANGED, "Wireless profile sync enablement state changed")); //User Notification Alert   - WLAN notification. Wireless Profile sync enablement state changed
	 m_eventsMap.bind(WLAN_NOTIFICATION_6, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROFILE_SYNC_DISABLE, ""));
	 m_eventsMap.bind(WLAN_NOTIFICATION_7, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROFILE_SYNC_ENABLE, ""));
	 m_eventsMap.bind(WLAN_NOTIFICATION_8, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROTECTION_ON_HIGH, "Intel(R) ME WLAN Link Protection is ON (HIGH)"));
	 m_eventsMap.bind(WLAN_NOTIFICATION_9, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROTECTION_ON_PASSIVE, "Intel(R) ME WLAN Link Protection is ON (PASSIVE)"));
	 m_eventsMap.bind(WLAN_NOTIFICATION_10, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_PROTECTION_OFF, "Intel(R) ME WLAN Link Protection is OFF"));
	 m_eventsMap.bind(WLAN_CONTROL_NOTIFICATION_1, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_CONTROL_HOST,"WLAN Link Control set to Host (Operating system)")); //User Notification Alert - WLAN Link Control set to HOST
	 m_eventsMap.bind(WLAN_CONTROL_NOTIFICATION_2, GmsEventType(CATEGORY_WLAN, EVENT_WLAN_CONTROL_ME,"WLAN Link Control set to Intel(R) ME")); //User Notification Alert - WLAN Link Control set to Intel® ME

	 m_eventsMap.bind(SECIO_NOTIFICATION_1, GmsEventType(CATEGORY_SECIO, EVENT_SECIO_SEMAPHORE_AT_HOST, "Sprite is in use by another application")); //User Notification Alert   - SecIo event %1s
	 m_eventsMap.bind(SECIO_NOTIFICATION_2, GmsEventType(CATEGORY_SECIO, EVENT_SECIO_SEMAPHORE_AT_ME, ""));
	 m_eventsMap.bind(SECIO_NOTIFICATION_3, GmsEventType(CATEGORY_SECIO, EVENT_SECIO_SEMAPHORE_TIMEOUT, ""));
	 m_eventsMap.bind(SECIO_NOTIFICATION_4, GmsEventType(CATEGORY_SECIO, EVENT_SECIO_CONFIGURATION_EVENT, "Sprite configuration change requested")); //User Notification Alert   - SecIO configuration event

	 m_eventsMap.bind(KVM_NOTIFICATION_1, GmsEventType(CATEGORY_KVM, EVENT_KVM_SESSION_REQUESTED, "KVM session requested")); //User Notification Alert   - KVM session event %1s
	 m_eventsMap.bind(KVM_NOTIFICATION_2, GmsEventType(CATEGORY_KVM, EVENT_KVM_SESSION_STARTED, "KVM session started")); //User Notification Alert   - KVM session event %1s
	 m_eventsMap.bind(KVM_NOTIFICATION_3, GmsEventType(CATEGORY_KVM, EVENT_KVM_SESSION_STOPPED, "KVM session stopped")); //User Notification Alert   - KVM session event %1s
	 m_eventsMap.bind(KVM_NOTIFICATION_4, GmsEventType(CATEGORY_KVM, EVENT_KVM_DISABLED, "KVM disabled")); //User Notification Alert   - KVM enabled event %1s
	 m_eventsMap.bind(KVM_NOTIFICATION_5, GmsEventType(CATEGORY_KVM, EVENT_KVM_ENABLED, "KVM enabled")); //User Notification Alert   - KVM enabled event %1s
	 m_eventsMap.bind(KVM_NOTIFICATION_6, GmsEventType(CATEGORY_KVM, EVENT_KVM_DATA_CHANNEL, "KVM data channel")); //User Notification Alert   - KVM session event %1s
	 m_eventsMap.bind(RCS_NOTIFICATION_5, GmsEventType(CATEGORY_RCS, EVENT_RCS_TUNNEL_CLOSE, "Client Initiated Remote Access (CIRA) session disconnected")); //User Notification Alert   - Remote Access Connection Notification %1s
	 m_eventsMap.bind(RCS_NOTIFICATION_6, GmsEventType(CATEGORY_RCS, EVENT_RCS_TUNNEL_OPEN, "Client Initiated Remote Access (CIRA) session connected")); //User Notification Alert   - Remote Access Connection Notification %1s
	 
	 m_eventsMap.bind(IPSYNC_NOTIFICATION_1, GmsEventType(CATEGORY_IPSYNC, EVENT_IP_SYNC_DISABLE,"IP synchronization disabled")); //User Notification Alert - IP synchronization disabled
	 m_eventsMap.bind(IPSYNC_NOTIFICATION_2, GmsEventType(CATEGORY_IPSYNC, EVENT_IP_SYNC_ENABLE,"IP synchronization enabled")); //User Notification Alert - IP synchronization enabled
	
	 m_eventsMap.bind(PROXY_NOTIFICATION_1, GmsEventType(CATEGORY_PROXY, EVENT_PROXY_SYNC_DISABLE,"User Notification Alert - Proxy synchronization disabled"));//to check if need to change it
	 m_eventsMap.bind(PROXY_NOTIFICATION_2, GmsEventType(CATEGORY_PROXY, EVENT_PROXY_SYNC_ENABLE,"User Notification Alert - Proxy synchronization enabled"));//to check if need to change it
	 
	 m_eventsMap.bind(USER_CONSENT_NOTIFICATION_1, GmsEventType(USER_CONSENT, EVENT_USER_CONSENT_ENDED,"User consent ended")); //User Notification Alert - User consent ended
	 m_eventsMap.bind(USER_CONSENT_NOTIFICATION_2, GmsEventType(USER_CONSENT, EVENT_USER_CONSENT_GRANTED, "User consent granted")); //User Notification Alert - User consent granted
	 m_eventsMap.bind(USER_CONSENT_NOTIFICATION_3, GmsEventType(USER_CONSENT, EVENT_USER_CONSENT_REQUESTED, "User consent requested")); //User Notification Alert - User consent requested
	 m_eventsMap.bind(USER_CONSENT_NOTIFICATION_4, GmsEventType(USER_CONSENT, EVENT_USER_CONSENT_CONFIGURATION_CHANGED, "User consent configuration changed"));  //User Notification Alert - User consent timeout started
	 	
	 m_eventsMap.bind(IPREFRESH_NOTIFICATION_1, GmsEventType(CATEGORY_IPSYNC, EVENT_IP_REFRESH_LAN, "User Notification Alert - IP refresh LAN"));//to check if need to change it
	 m_eventsMap.bind(IPREFRESH_NOTIFICATION_2, GmsEventType(CATEGORY_IPSYNC, EVENT_IP_REFRESH_WLAN, "User Notification Alert - IP refresh WLAN"));//to check if need to change it

	 m_eventsMap.bind(TIMESYNC_NOTIFICATION_1, GmsEventType(CATEGORY_TIMESYNC, EVENT_TIME_SYNC_DISABLE, "Time synchronization disabled")); //User Notification Alert - Time synchronization disabled
 	 m_eventsMap.bind(TIMESYNC_NOTIFICATION_2, GmsEventType(CATEGORY_TIMESYNC, EVENT_TIME_SYNC_ENABLE, "Time synchronization enabled")); //User Notification Alert - Time synchronization enabled

	 m_eventsMap.bind(GRACEFUL_PWR_OPERATION_1, GmsEventType(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, EVENT_REMOTE_GRACEFUL_SHUTDOWN_REQUESTED, ""));
	 m_eventsMap.bind(GRACEFUL_PWR_OPERATION_2, GmsEventType(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, EVENT_REMOTE_GRACEFUL_REBOOT_REQUESTED,   ""));
	 m_eventsMap.bind(GRACEFUL_PWR_OPERATION_3, GmsEventType(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, EVENT_REMOTE_SLEEP,                       "Sleep operation was requested by remote administrator"));
	 m_eventsMap.bind(GRACEFUL_PWR_OPERATION_4, GmsEventType(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, EVENT_REMOTE_HIBERNATE,                   "Hibernate operation was requested by remote administrator"));
}

bool
CimToEventTranslator::translate(const std::string &cimMessageID, const std::string &cimMessageArg, const std::string &cimMessageText, GMS_AlertIndication &unsEvent)
{

	UNS_DEBUG(L"CimToEventTranslator:translate", L"\n");

	// Uniq string ID
	ACE_TString uniqStrID;

	unsEvent.Datetime = getDateTime();
	if (cimMessageID.length()) {
		unsEvent.MessageID = ACE_TEXT_CHAR_TO_TCHAR(cimMessageID.c_str());
		uniqStrID.append(unsEvent.MessageID.c_str(), unsEvent.MessageID.length());
	}
	else
	{
		return false;
	}
	GmsEventType et;
	//We first try to find the event as is in the map (on the time this code was written it was foth events AGENT_PRSENCE_1,AGENT_PRSENCE_2,AGENT_PRSENCE_4
	if (m_eventsMap.find(uniqStrID, et) == 0)
	{
		if (cimMessageArg.size() > 0)
		{
			unsEvent.MessageArguments.push_back(ACE_TEXT_CHAR_TO_TCHAR(cimMessageArg.c_str()));
			UNS_DEBUG(L"CimToEventTranslator: MessageArguments=%C", L"\n", cimMessageArg.c_str());

		}
	}
	else
	{
		//if fail to find we try to append first argument to the event (assuming event in the format of iAMT00## - *) where * is a unique value hold in MessageArguments[0] 
		ACE_TString sep = SEPERATOR;
		uniqStrID.append(sep.c_str(), sep.length());
		UNS_DEBUG(L"  CimToEventTranslator: MessageID=%C", L"\n", cimMessageID.c_str() );
		// We copy only the first arg - the Message IS
		if (cimMessageArg.size() > 0) {

			//The next line logic - in order to indentify the Event in the map it uses the messageID and the first argument (if exist)
			uniqStrID.append(ACE_TEXT_CHAR_TO_TCHAR(cimMessageArg.c_str()), cimMessageArg.length());
			UNS_DEBUG(L"  CimToEventTranslator: MessageArgument=%C", L"\n", (cimMessageArg).c_str());
		}
		if (m_eventsMap.find(uniqStrID, et) != 0)
		{
			// The event is not in the map
			UNS_DEBUG(L"CimToEventTranslator: uniqStrID [%s] not found in map", L"\n", uniqStrID.c_str());
			return false;
		}
	}

	unsEvent.category = et.category;
	unsEvent.id = et.id;
	unsEvent.Message = setMessage(unsEvent, cimMessageText, et);

	UNS_DEBUG(L"    CimToEventTranslator: unsEvent category=%d id=%d Message=%s", L"\n",
		unsEvent.category, unsEvent.id, unsEvent.Message.c_str());
	return true;
}

ACE_TString
CimToEventTranslator::setMessage(GMS_AlertIndication &unsEvent, const std::string &cimMessageText, GmsEventType& et)
{
	ACE_TString message;
	switch (et.id)
	{
	case EVENT_AGENT_1:
		if (unsEvent.MessageArguments.size() > 0)
		{
			message = EVENTS_AGENTS_HEADER;
			unsEvent.MessageArguments[0] += EVENTS_AGENT_NOT_STARTED_SUFFIX;
			message.append(unsEvent.MessageArguments[0].c_str(), unsEvent.MessageArguments[0].length());
		}
		break;
	case EVENT_AGENT_2:
		if (unsEvent.MessageArguments.size() > 0)
		{
			message = EVENTS_AGENTS_HEADER;
			unsEvent.MessageArguments[0] += EVENTS_AGENT_STOPED_SUFFIX;
			message.append(unsEvent.MessageArguments[0].c_str(), unsEvent.MessageArguments[0].length());
		}
		break;
	case EVENT_AGENT_4:
		if (unsEvent.MessageArguments.size() > 0)
		{
			message = EVENTS_AGENTS_HEADER;
			unsEvent.MessageArguments[0] += EVENTS_AGENT_EXPIRED_SUFFIX;
			message.append(unsEvent.MessageArguments[0].c_str(), unsEvent.MessageArguments[0].length());
		}
		break;
	default:

		message = ACE_TEXT_CHAR_TO_TCHAR(cimMessageText.c_str());
		if (message.compare(ACE_TEXT("")) == 0 && !et.message.empty())
			message = ACE_TEXT_CHAR_TO_TCHAR(et.message.c_str());
		UNS_DEBUG(L"    CimToEventTranslator::setMessage category=%d id=%d cimEventMessage=%s message=%s", L"\n",
			unsEvent.category, unsEvent.id, unsEvent.Message.c_str(), message.c_str());

		break;
	}
	return message;
}