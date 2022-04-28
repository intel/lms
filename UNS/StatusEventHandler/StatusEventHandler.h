/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2022 Intel Corporation
 */
#ifndef __STATUSEVENTHANDLER_H_
#define __STATUSEVENTHANDLER_H_
#include "global.h"
#include "ace/Acceptor.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/Task.h"
#include "ace/Svc_Handler.h"
#include "ace/Containers.h"
#include "ace/Map_Manager.h"
#include "ace/Synch.h"
#include "ace/Reactor_Notification_Strategy.h"
#include "ace/Message_Block.h"
#include "ace/Log_Msg.h"
#include "EventHandler.h"
#include "StatusEventFilter.h"
#include "AMT_COM_Interface_defs.h"
#include "GetProvisioningStateCommand.h"
#include "GetPlatformTypeCommand.h"
#include "HostBootReasonClient.h"
#include "STATUSEVENTHANDLER_export.h"
#include <vector>
#include <string>
#include <mutex>
enum DATA_NAME : unsigned int;

class STATUSEVENTHANDLER_Export StatusEventHandler : public EventHandler
{
public:

	StatusEventHandler();

	enum class PUBLISHEVENTS
	{
		SOL,
		IDER,
		SYSDEF,
		KVMSTATE,
		KVMACTIVITY,
		MANAGEMODE,
		MESTATE,
		HECISTATE,
		EACENABLE,
		IPSYNCENABLE,
		TIMESYNCENABLE,
		WIFIPROFILESYNCENABLE
	};

typedef enum _UC_STATE
{
	UC_ENDED,
	UC_REQUESTED,
	UC_GRANTED
} UC_STATE;

typedef enum _OPT_IN_STATE
{
	OPT_IN_STATE_NOT_STARTED = 0,
	OPT_IN_STATE_REQUESTED = 1,
	OPT_IN_STATE_DISPLAYED = 2,
	OPT_IN_STATE_RECEIVED = 3,
	OPT_IN_STATE_IN_SESSION = 4
} OPT_IN_STATE;

	static const unsigned short KVM_REDIRECTION_SAP_STATE_KVM_ENABLED_AND_CONNECTED = 2;
	static const unsigned short KVM_REDIRECTION_SAP_STATE_KVM_DISABLED = 3;
	static const unsigned short KVM_REDIRECTION_SAP_STATE_KVM_ENABLED_AND_DISCONNECTED = 6;

	enum class KVM_STATE
	{
		KVM_STOPPED,
		KVM_STARTED,
		KVM_REQUESTED,
		KVM_DATA_CHANNEL
	};

	enum class WLAN_CONTROL_STATE
	{
		ME_CONTROL = 1,
		HOST_CONTROL = 2
	};

	enum class WLAN_PROTECTION_STATE
	{
		PROTECTION_OFF = 1,
		PROTECTION_PASSIVE = 2,
		PROTECTION_HIGH = 3,
		NOT_EXIST = 5
	};

	void publishEvent(bool action, PUBLISHEVENTS ex);
	//// Publish KVM state event while UNS was stopped
	void publishUCStateEvent(UC_STATE state);

	void PublishWlanProtectionEvent(WLAN_PROTECTION_STATE state);
	void PublishWlanControlEvent(WLAN_CONTROL_STATE state);

protected:
	virtual int init(int argc, ACE_TCHAR *argv[]);

	virtual int fini (void);

	virtual int suspend();

	virtual int resume();

	virtual int handle_event (MessageBlockPtr mbPtr);


	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"STEH"; }

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}

private:

	bool SaveCurrentStatus(uint32_t status,DATA_NAME storageName);
	bool SaveCurrentStatus(KVM_STATE status);
	bool SaveCurrentStatus(WLAN_CONTROL_STATE status);
	bool SaveCurrentStatus(WLAN_PROTECTION_STATE status);
	void NotifyConfigurator(int status, CONFIGURATION_TYPE RegValueName);
	void NotifyIPRefresh(int RegValueName);
	bool StatusChanged(DATA_NAME storageName, uint32_t state);
	void CheckForStatusChange(DATA_NAME storageName,bool state,PUBLISHEVENTS ev);
	void CheckForStatusChange(DATA_NAME storageName,Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE state);
	void CheckForStatusChange(DATA_NAME storageName,FEATURE_STATE state);
	void CheckForStatusChange(DATA_NAME storageName,UC_STATE state);
	void CheckForStatusChange(DATA_NAME storageName,KVM_STATE state);
	void CheckForStatusChange(WLAN_PROTECTION_STATE state);
	void CheckForStatusChange(WLAN_CONTROL_STATE state);

	bool GetProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE& ProvState);
	bool GetSolIderState(bool& SOLState, bool& IDERState);
	bool GetSystemDefenseState(bool& SysDefState);
	bool GetMEState(bool& MEState);

	bool GetAlarmClockBootEvent(HostBootReasonClient::SX_STATES &previousSXState);

	// Publish Provisioning event while LMS was stopped
	void publishProvisioningEvent(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE state);

	// Generate events according to register values while LMS was stopped
	void GenerateEvents();
	void GeneratePortFwrdRelatedEvents();
	void GenerateEACEvents(bool AMTstate);
	void GenerateSharedStaticIPEvents(bool AMTstate);
	void GenerateTimeSyncEvents(bool AMTstate);
	void GenerateSOLIDEREvents(bool AMTstate);
	void GenerateKVMRedirectionEvents(bool AMTstate);
	void GenerateSystemDefenseEvents(bool AMTstate);
	void GenerateProvisioningEvents(bool AMTstate);
	void GenerateUCEvents(bool AMTstate);
	void GenerateMEEvents();
	void GenerateWLANEvents();
	void GenerateWiFiProfileSyncEvents(bool AMTstate);

	bool GetManageabiltyMode(MENAGEABILTY_MODE* pManageMode, CUSTOMER_TYPE* pType);
	bool GetAmtState(FEATURE_STATE &AmtState) const;

	// Publish AMT enabled event
	void publishAMTEnabledEvent(bool enable);

	void publishKVMActivityEvent(KVM_STATE action);

	static FEATURE_STATE FeatureStateLogic(bool CapabilityBit, bool StateBit);
	static void MenageabiltyModeLogic(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE platform, MENAGEABILTY_MODE* pMode);

	Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE UpdatePrevProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE State);
	bool GetUserConsentState(OPT_IN_STATE* pState, USER_CONSENT_POLICY* pPolicy);
	bool GetLocalProfileSynchronizationEnabled(bool &enabled);
	void firstPullForEvents();
	void checkForBootReason();

	int handleStatusChanged(const GMS_AlertIndication *alert);
	void handleGeneralEvents(const GMS_AlertIndication *alert);
	void handleSystemDefenceEvents(const GMS_AlertIndication *alert);
	void handleRemoteDiagnosticEvents(const GMS_AlertIndication *alert);
	void handleKVMEvents(const GMS_AlertIndication *alert);
	void handleUNSEvents(const GMS_AlertIndication *alert);
	void handleIPSyncEvents(const GMS_AlertIndication *alert);
	void handleUserConsentEvents(const GMS_AlertIndication *alert);
	void handleProvisioningEvents(const GMS_AlertIndication *alert);
	void handleAgentPresenceEvents(const GMS_AlertIndication *alert);
	void handleWlanEvents(const GMS_AlertIndication *alert);
	void handleTimeSyncEvents(const GMS_AlertIndication *alert);

	void raiseGMS_AlertIndication(unsigned short category, unsigned long id, const std::string &Datetime,
		const ACE_TString &MessageID, const ACE_TString &Message, const std::vector<ACE_TString> &MessageArguments);
	void raiseGMS_AlertIndication(unsigned short category, unsigned long id, const std::string &Datetime,
		const ACE_TString &MessageID, const ACE_TString &Message);

	// Publish Remote Reboot event
	void publishRemoteRebootEvent();
	//publish Host boot by Alarm clock
	void publishAlarmClockBoot(HostBootReasonClient::SX_STATES previousSXState);
	ACE_TString GetSXState(HostBootReasonClient::SX_STATES previousSXState);

	void SafeSetProvisioningState(Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE State);
	// Get the network settings (need for populate the MAC address)
	bool GetEACEnabled(bool& enable);
	bool GetKVMRedirectionState(bool& enable,KVM_STATE& connected);
	void requestDisplaySettings();

	short m_KVM;
	short m_SOL;
	short m_IDER;
	short m_prevUserConsentState;
	Intel::MEI_Client::AMTHI_Client::AMT_PROVISIONING_STATE m_prevProvState;
	USER_CONSENT_POLICY m_UserConsentPolicy;
	std::mutex m_semAMTEnabled;
	bool m_eacEnabled;
	FEATURE_STATE m_prevAmtState;
	CUSTOMER_TYPE m_prevCustomerType;
	MENAGEABILTY_MODE m_prevManageMode;
	bool m_firstPullForEvents;
	bool m_firstCheckForBootReason;
	std::shared_ptr<StatusEventFilter> filter_;
};

#endif /* __STATUSEVENTHANDLER_H_ */
