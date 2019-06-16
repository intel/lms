/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: GMSConfig.cpp

--*/
#include "global.h"
#include "UNSMessageFile.h"
#include "GMSConfig.h"
#include "UNSRegistry.h"

/*Constants*/
//Constants for configuration parameters names
const LmsRegStr VAL_NETWORK_TRAFFIC_TX_CEASED           = LMS_REG_TEXT("NETWORK_TRAFFIC_TX_CEASED");
const LmsRegStr VAL_NETWORK_CONNECTIVITY_TX_REDUCED     = LMS_REG_TEXT("NETWORK_CONNECTIVITY_TX_REDUCED");
const LmsRegStr VAL_NETWORK_TRAFFIC_RX_CEASED           = LMS_REG_TEXT("NETWORK_TRAFFIC_RX_CEASED");
const LmsRegStr VAL_NETWORK_CONNECTIVITY_RX_REDUCED     = LMS_REG_TEXT("NETWORK_CONNECTIVITY_RX_REDUCED");
const LmsRegStr VAL_WLAN_WIRELESS_PROFILE_STATE_CHANGED = LMS_REG_TEXT("WLAN_WIRELESS_PROFILE_STATE_CHANGED");
const LmsRegStr VAL_WLAN_PROFILE_INSUFFICIENT           = LMS_REG_TEXT("WLAN_PROFILE_INSUFFICIENT");
const LmsRegStr VAL_WLAN_SECURITY_INSUFFICIENT          = LMS_REG_TEXT("WLAN_SECURITY_INSUFFICIENT");
const LmsRegStr VAL_WLAN_SESSION_ESTABLISHED            = LMS_REG_TEXT("WLAN_SESSION_ESTABLISHED");
const LmsRegStr VAL_WLAN_SESSION_ENDED                  = LMS_REG_TEXT("WLAN_SESSION_ENDED");
const LmsRegStr VAL_REMOTE_SOL_STARTED                  = LMS_REG_TEXT("REMOTE_SOL_STARTED");
const LmsRegStr VAL_REMOTE_SOL_ENDED                    = LMS_REG_TEXT("REMOTE_SOL_ENDED");
const LmsRegStr VAL_REMOTE_IDER_STARTED                 = LMS_REG_TEXT("REMOTE_IDER_STARTED");
const LmsRegStr VAL_REMOTE_IDER_ENDED                   = LMS_REG_TEXT("REMOTE_IDER_ENDED");
const LmsRegStr VAL_PFW_UPGRADE_SUCCESS_LANG            = LMS_REG_TEXT("PFW_UPGRADE_SUCCESS_LANG");
const LmsRegStr VAL_PFW_UPGRADE_SUCCESS_WLAN            = LMS_REG_TEXT("PFW_UPGRADE_SUCCESS_WLAN");
const LmsRegStr VAL_PFW_UPGRADE_FAILURE_LANG            = LMS_REG_TEXT("VAL_PFW_UPGRADE_FAILURE_LANG");
const LmsRegStr VAL_PFW_UPGRADE_FAILURE_WLAN            = LMS_REG_TEXT("VAL_PFW_UPGRADE_FAILURE_WLAN");
const LmsRegStr VAL_MISSING_IMAGE_FILE_LANG             = LMS_REG_TEXT("MISSING_IMAGE_FILE_LANG");
const LmsRegStr VAL_MISSING_IMAGE_FILE_WLAN             = LMS_REG_TEXT("MISSING_IMAGE_FILE_WLAN");
const LmsRegStr VAL_UNS_NETWORK_SYNC_VALIDATION_FAILED  = LMS_REG_TEXT("UNS_NETWORK_SYNC_VALIDATION_FAILED");
const LmsRegStr VAL_UNS_NETWORK_SYNC_UPDATE_FAILED      = LMS_REG_TEXT("UNS_NETWORK_SYNC_UPDATE_FAILED");
const LmsRegStr VAL_IP_REFRESH_REQUESTED_LAN            = LMS_REG_TEXT("IP_REFRESH_REQUESTED_LAN");
const LmsRegStr VAL_IP_REFRESH_REQUESTED_WLAN           = LMS_REG_TEXT("IP_REFRESH_REQUESTED_WLAN");
const LmsRegStr VAL_AGENT_PRSENCE_NOT_STARTED           = LMS_REG_TEXT("AGENT_PRSENCE_NOT_STARTED");
const LmsRegStr VAL_AGENT_PRSENCE_STOPED                = LMS_REG_TEXT("AGENT_PRSENCE_STOPED");
const LmsRegStr VAL_AGENT_PRSENCE_EXPIRED               = LMS_REG_TEXT("AGENT_PRSENCE_EXPIRED");
const LmsRegStr VAL_ALARM_CLOCK_BOOT                    = LMS_REG_TEXT("ALARM_CLOCK_BOOT");
const LmsRegStr VAL_WLAN_CONTROL_ME                     = LMS_REG_TEXT("WLAN_CONTROL_ME");
const LmsRegStr VAL_WLAN_CONTROL_HOST                   = LMS_REG_TEXT("WLAN_CONTROL_HOST");
const LmsRegStr VAL_WLAN_PROTECTION_ON_HIGH             = LMS_REG_TEXT("WLAN_PROTECTION_HIGH");
const LmsRegStr VAL_WLAN_PROTECTION_ON_PASSIVE          = LMS_REG_TEXT("WLAN_PROTECTION_PASSIVE");
const LmsRegStr VAL_WLAN_PROTECTION_OFF                 = LMS_REG_TEXT("WLAN_PROTECTION_OFF");
const LmsRegStr VAL_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED    = LMS_REG_TEXT("REMOTE_GRACEFUL_SHUTDOWN_SUCCEED");
const LmsRegStr VAL_REMOTE_GRACEFUL_SHUTDOWN_FAILED     = LMS_REG_TEXT("REMOTE_GRACEFUL_SHUTDOWN_FAILED");
const LmsRegStr VAL_REMOTE_GRACEFUL_REBOOT_SUCCEED      = LMS_REG_TEXT("REMOTE_GRACEFUL_REBOOT_SUCCEED ");
const LmsRegStr VAL_REMOTE_GRACEFUL_REBOOT_FAILED       = LMS_REG_TEXT("REMOTE_GRACEFUL_REBOOT_FAILED");
const LmsRegStr VAL_REMOTE_SLEEP                        = LMS_REG_TEXT("REMOTE_SLEEP");
const LmsRegStr VAL_REMOTE_HIBERNATE                    = LMS_REG_TEXT("REMOTE_HIBERNATE");
const LmsRegStr VAL_REMOTE_SLEEP_FAILED                 = LMS_REG_TEXT("REMOTE_SLEEP_FAILED");
const LmsRegStr VAL_REMOTE_HIBERNATE_FAILED             = LMS_REG_TEXT("REMOTE_HIBERNATE_FAILED");
const LmsRegStr VAL_FW_FATAL_ERROR                      = LMS_REG_TEXT("FW_FATAL_ERROR");
const LmsRegStr VAL_KVM_SESSION_STARTED                 = LMS_REG_TEXT("KVM_SESSION_STARTED");
const LmsRegStr VAL_KVM_SESSION_STOPPED                 = LMS_REG_TEXT("KVM_SESSION_STOPPED");
const LmsRegStr VAL_PORT_FORWARDING_SERVICE_UNAVAILABLE = LMS_REG_TEXT("PORT_FORWARDING_SERVICE_UNAVAILABLE");
const LmsRegStr VAL_AMT_DISABLE_ATTEMPT                 = LMS_REG_TEXT("AMT_DISABLE_ATTEMPT");

//default ctor
GMSConfig::GMSConfig()
{
	LoadMachineConfig();
}

//Init(): Load the configuration from configuration files.
//Returns true on success, false if either of the files could not be opened (in which
//case the defaults will be used).
bool GMSConfig::Init()
{
	return LoadMachineConfig();
}

bool GMSConfig::LoadMachineConfig()
{
	unsigned long lval;
	//For every parameter that is read, if it's not found, its default value is used.
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_NETWORK_TRAFFIC_TX_CEASED, &lval, 1);
	m_EventsToPublish.bind(NETWORK_TRAFFIC_TX_CEASED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_NETWORK_CONNECTIVITY_TX_REDUCED, &lval, 1);
	m_EventsToPublish.bind(NETWORK_CONNECTIVITY_TX_REDUCED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_NETWORK_TRAFFIC_RX_CEASED, &lval, 1);
	m_EventsToPublish.bind(NETWORK_TRAFFIC_RX_CEASED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_NETWORK_CONNECTIVITY_RX_REDUCED, &lval, 1);
	m_EventsToPublish.bind(NETWORK_CONNECTIVITY_RX_REDUCED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_PROFILE_INSUFFICIENT, &lval, 1);
	m_EventsToPublish.bind(WLAN_PROFILE_INSUFFICIENT, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_SECURITY_INSUFFICIENT, &lval, 1);
	m_EventsToPublish.bind(WLAN_SECURITY_INSUFFICIENT, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_SESSION_ESTABLISHED, &lval, 1);
	m_EventsToPublish.bind(WLAN_SESSION_ESTABLISHED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_SESSION_ENDED, &lval, 1);
	m_EventsToPublish.bind(WLAN_SESSION_ENDED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_WIRELESS_PROFILE_STATE_CHANGED, &lval, 1);
	m_EventsToPublish.bind(WLAN_WIRELESS_PROFILE_STATE_CHANGED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_SOL_STARTED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_SOL_STARTED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_SOL_ENDED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_SOL_ENDED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_IDER_STARTED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_USBR_STARTED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_IDER_ENDED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_USBR_ENDED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_PFW_UPGRADE_SUCCESS_LANG, &lval, 1);
	m_EventsToPublish.bind(PFW_UPGRADE_SUCCESS_LANG, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_PFW_UPGRADE_SUCCESS_WLAN, &lval, 1);
	m_EventsToPublish.bind(PFW_UPGRADE_SUCCESS_WLAN, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_PFW_UPGRADE_FAILURE_LANG, &lval, 1);
	m_EventsToPublish.bind(PFW_UPGRADE_FAILURE_LANG, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_PFW_UPGRADE_FAILURE_WLAN, &lval, 1);
	m_EventsToPublish.bind(PFW_UPGRADE_FAILURE_WLAN, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_MISSING_IMAGE_FILE_LANG, &lval, 1);
	m_EventsToPublish.bind(MISSING_IMAGE_FILE_LANG, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_MISSING_IMAGE_FILE_WLAN, &lval, 1);
	m_EventsToPublish.bind(MISSING_IMAGE_FILE_WLAN, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_UNS_NETWORK_SYNC_VALIDATION_FAILED, &lval, 1);
	m_EventsToPublish.bind(UNS_NETWORK_SYNC_VALIDATION_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_UNS_NETWORK_SYNC_UPDATE_FAILED, &lval, 1);
	m_EventsToPublish.bind(UNS_NETWORK_SYNC_UPDATE_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_IP_REFRESH_REQUESTED_LAN, &lval, 1);
	m_EventsToPublish.bind(IP_REFRESH_REQUESTED_LAN, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_IP_REFRESH_REQUESTED_WLAN, &lval, 1);
	m_EventsToPublish.bind(IP_REFRESH_REQUESTED_WLAN, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_AGENT_PRSENCE_NOT_STARTED, &lval, 1);
	m_EventsToPublish.bind(AGENT_PRSENCE_NOT_STARTED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_AGENT_PRSENCE_STOPED, &lval, 1);
	m_EventsToPublish.bind(AGENT_PRSENCE_STOPED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_AGENT_PRSENCE_EXPIRED, &lval, 1);
	m_EventsToPublish.bind(AGENT_PRSENCE_EXPIRED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_ALARM_CLOCK_BOOT, &lval, 1);
	m_EventsToPublish.bind(ALARM_CLOCK_REBOOT, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_GRACEFUL_SHUTDOWN_SUCCEED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_GRACEFUL_SHUTDOWN_FAILED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_GRACEFUL_SHUTDOWN_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_GRACEFUL_REBOOT_SUCCEED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_GRACEFUL_REBOOT_SUCCEED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_GRACEFUL_REBOOT_FAILED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_GRACEFUL_REBOOT_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_SLEEP, &lval, 1);
	m_EventsToPublish.bind(REMOTE_SLEEP, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_HIBERNATE, &lval, 1);
	m_EventsToPublish.bind(REMOTE_HIBERNATE, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_SLEEP_FAILED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_SLEEP_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_REMOTE_HIBERNATE_FAILED, &lval, 1);
	m_EventsToPublish.bind(REMOTE_HIBERNATE_FAILED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_CONTROL_HOST, &lval, 1);
	m_EventsToPublish.bind(WLAN_CONTROL_HOST, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_CONTROL_ME, &lval, 1);
	m_EventsToPublish.bind(WLAN_CONTROL_ME, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_PROTECTION_ON_HIGH, &lval, 1);
	m_EventsToPublish.bind(WLAN_PROTECTION_ON_HIGH, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_PROTECTION_ON_PASSIVE, &lval, 1);
	m_EventsToPublish.bind(WLAN_PROTECTION_ON_PASSIVE, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_WLAN_PROTECTION_OFF, &lval, 1);
	m_EventsToPublish.bind(WLAN_PROTECTION_OFF, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_FW_FATAL_ERROR, &lval, 1);
	m_EventsToPublish.bind(FW_FATAL_ERROR, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_KVM_SESSION_STARTED, &lval, 1);
	m_EventsToPublish.bind(KVM_SESSION_STARTED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_KVM_SESSION_STOPPED, &lval, 1);
	m_EventsToPublish.bind(KVM_SESSION_STOPPED, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_PORT_FORWARDING_SERVICE_UNAVAILABLE, &lval, 1);
	m_EventsToPublish.bind(PORT_FORWARDING_SERVICE_UNAVAILABLE, lval);
	GetFromRegistry(LMS_REG_CONFIG_DATA, VAL_AMT_DISABLE_ATTEMPT, &lval, 1);
	m_EventsToPublish.bind(AMT_DISABLE_ATTEMPT, lval);

	m_EventsToPublish.bind(UNS_WARNING_MESSAGE, 1);
	m_EventsToPublish.bind(UNS_ERROR_MESSAGE,   1);

	return true;
}

bool GMSConfig::CheckEventToPublish(unsigned long EventID) const
{
	int publish;
	int i = m_EventsToPublish.find(EventID,publish);
	if (i ==-1) { 
		// The event is not in the map
		UNS_DEBUG(L"Event [%d] does not need to publish",L"\n",EventID);
		return false;
	}
	return (publish == 1);
}
