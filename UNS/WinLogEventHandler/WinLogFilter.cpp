/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
#include "WinLogFilter.h"
#include "UNSEventsDefinition.h"
#include "UNSMessageFile.h"

WinLogFilter::WinLogFilter()
{
	eventsMap_.bind(EVENT_NETWORK_TRAFFIC_TX_CEASED,		GmsEventType(UNS_CIRCUIT_BREAKER  , NETWORK_TRAFFIC_TX_CEASED));
	eventsMap_.bind(EVENT_NETWORK_CONNECTIVITY_TX_REDUCED, 	GmsEventType(UNS_CIRCUIT_BREAKER  , NETWORK_CONNECTIVITY_TX_REDUCED));
	eventsMap_.bind(EVENT_NETWORK_TRAFFIC_RX_CEASED,		 GmsEventType(UNS_CIRCUIT_BREAKER  , NETWORK_TRAFFIC_RX_CEASED));
	eventsMap_.bind(EVENT_NETWORK_CONNECTIVITY_RX_REDUCED,	 GmsEventType(UNS_CIRCUIT_BREAKER  , NETWORK_CONNECTIVITY_RX_REDUCED));
		
	eventsMap_.bind(EVENT_WIRELESS_STATE_CHANGED,			 GmsEventType(UNS_WLAN             , WLAN_WIRELESS_PROFILE_STATE_CHANGED));
	eventsMap_.bind(EVENT_WLAN_PROFILE_INSUFFICIENT,		 GmsEventType(UNS_WLAN             , WLAN_PROFILE_INSUFFICIENT));
	eventsMap_.bind(EVENT_WLAN_SECURITY_INSUFFICIENT,		 GmsEventType(UNS_WLAN             , WLAN_SECURITY_INSUFFICIENT));
	eventsMap_.bind(EVENT_WLAN_SESSION_ESTABLISHED,			 GmsEventType(UNS_WLAN             , WLAN_SESSION_ESTABLISHED));
	eventsMap_.bind(EVENT_WLAN_SESSION_ENDED,				 GmsEventType(UNS_WLAN             , WLAN_SESSION_ENDED));
	eventsMap_.bind(EVENT_WLAN_PROFILE_SYNC_DISABLE,		 GmsEventType(UNS_WLAN             , WLAN_PROFILE_SYNC_DISABLE));
	eventsMap_.bind(EVENT_WLAN_PROFILE_SYNC_ENABLE,			 GmsEventType(UNS_WLAN             , WLAN_PROFILE_SYNC_ENABLE));
	eventsMap_.bind(EVENT_WLAN_CONTROL_HOST,				 GmsEventType(UNS_WLAN             , WLAN_CONTROL_HOST));
	eventsMap_.bind(EVENT_WLAN_CONTROL_ME,					 GmsEventType(UNS_WLAN             , WLAN_CONTROL_ME));
	eventsMap_.bind(EVENT_WLAN_PROTECTION_ON_HIGH,			 GmsEventType(UNS_WLAN             , WLAN_PROTECTION_ON_HIGH));
	eventsMap_.bind(EVENT_WLAN_PROTECTION_ON_PASSIVE,		 GmsEventType(UNS_WLAN             , WLAN_PROTECTION_ON_PASSIVE));
	eventsMap_.bind(EVENT_WLAN_PROTECTION_OFF,				 GmsEventType(UNS_WLAN             , WLAN_PROTECTION_OFF));

	eventsMap_.bind(EVENT_REMOTE_SOL_STARTED,				 GmsEventType(UNS_REMOTE_DIAGNOSTIC, REMOTE_SOL_STARTED));
	eventsMap_.bind(EVENT_REMOTE_SOL_ENDED,					 GmsEventType(UNS_REMOTE_DIAGNOSTIC, REMOTE_SOL_ENDED));
	eventsMap_.bind(EVENT_REMOTE_IDER_STARTED,				 GmsEventType(UNS_REMOTE_DIAGNOSTIC, REMOTE_USBR_STARTED));
	eventsMap_.bind(EVENT_REMOTE_IDER_ENDED,				 GmsEventType(UNS_REMOTE_DIAGNOSTIC, REMOTE_USBR_ENDED));

	eventsMap_.bind(EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED,  GmsEventType(UNS_REMOTE_PWR        , REMOTE_GRACEFUL_SHUTDOWN_SUCCEED));
	eventsMap_.bind(EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED,   GmsEventType(UNS_REMOTE_PWR 		, REMOTE_GRACEFUL_SHUTDOWN_FAILED));
	eventsMap_.bind(EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED,    GmsEventType(UNS_REMOTE_PWR 		, REMOTE_GRACEFUL_REBOOT_SUCCEED));
	eventsMap_.bind(EVENT_REMOTE_GRACEFUL_REBOOT_FAILED,     GmsEventType(UNS_REMOTE_PWR 		, REMOTE_GRACEFUL_REBOOT_FAILED));
	eventsMap_.bind(EVENT_REMOTE_SLEEP,		                 GmsEventType(UNS_REMOTE_PWR 		, REMOTE_SLEEP));
	eventsMap_.bind(EVENT_REMOTE_HIBERNATE,		             GmsEventType(UNS_REMOTE_PWR        , REMOTE_HIBERNATE));
	eventsMap_.bind(EVENT_REMOTE_SLEEP_FAILED,		                 GmsEventType(UNS_REMOTE_PWR 		, REMOTE_SLEEP_FAILED));
	eventsMap_.bind(EVENT_REMOTE_HIBERNATE_FAILED,		             GmsEventType(UNS_REMOTE_PWR        , REMOTE_HIBERNATE_FAILED));

	eventsMap_.bind(EVENT_PARTIAL_FWU_END_SUCCESS_WLAN,		 GmsEventType(UNS_GENERAL		, PFW_UPGRADE_SUCCESS_WLAN));
	eventsMap_.bind(EVENT_PARTIAL_FWU_END_SUCCESS_LANG,		 GmsEventType(UNS_GENERAL		, PFW_UPGRADE_SUCCESS_LANG));
	eventsMap_.bind(EVENT_PARTIAL_FWU_END_FAILURE_WLAN,		 GmsEventType(UNS_GENERAL		, PFW_UPGRADE_FAILURE_WLAN));
	eventsMap_.bind(EVENT_PARTIAL_FWU_END_FAILURE_LANG,		 GmsEventType(UNS_GENERAL		, PFW_UPGRADE_FAILURE_LANG));
	eventsMap_.bind(EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN,	 GmsEventType(UNS_GENERAL		, MISSING_IMAGE_FILE_WLAN));
	eventsMap_.bind(EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG,	 GmsEventType(UNS_GENERAL		, MISSING_IMAGE_FILE_LANG));

	eventsMap_.bind(EVENT_IP_REFRESH_REQUESTED_LAN,			 GmsEventType(UNS_GENERAL		, IP_REFRESH_REQUESTED_LAN));
	eventsMap_.bind(EVENT_IP_REFRESH_REQUESTED_WLAN,		 GmsEventType(UNS_GENERAL		, IP_REFRESH_REQUESTED_WLAN));

	eventsMap_.bind(EVENT_IP_SYNC_FW_UPDATE_FAILED,			 GmsEventType(UNS_GENERAL		, UNS_NETWORK_SYNC_UPDATE_FAILED));
	eventsMap_.bind(EVENT_IP_SYNC_VALIDATION_FAILED,		 GmsEventType(UNS_GENERAL		, UNS_NETWORK_SYNC_VALIDATION_FAILED));
	eventsMap_.bind(EVENT_ALARM_CLOCK_BOOT,					 GmsEventType(UNS_GENERAL		, ALARM_CLOCK_REBOOT));

	eventsMap_.bind(EVENT_AGENT_PRSENCE_NOT_STARTED,		 GmsEventType(UNS_GENERAL		, AGENT_PRSENCE_NOT_STARTED));
	eventsMap_.bind(EVENT_AGENT_PRSENCE_STOPED,				 GmsEventType(UNS_GENERAL		, AGENT_PRSENCE_STOPED));
	eventsMap_.bind(EVENT_AGENT_PRSENCE_EXPIRED,			 GmsEventType(UNS_GENERAL		, AGENT_PRSENCE_EXPIRED));

	eventsMap_.bind(EVENT_FW_FATAL_ERROR,					GmsEventType(UNS_GENERAL		, FW_FATAL_ERROR));

	eventsMap_.bind(EVENT_KVM_SESSION_STARTED,				GmsEventType(UNS_GENERAL		, KVM_SESSION_STARTED));
	eventsMap_.bind(EVENT_KVM_SESSION_STOPPED,				GmsEventType(UNS_GENERAL		, KVM_SESSION_STOPPED));

	eventsMap_.bind(EVENT_PORT_FORWARDING_SERVICE_UNAVAILABLE,GmsEventType(UNS_GENERAL		, PORT_FORWARDING_SERVICE_UNAVAILABLE));

	eventsMap_.bind(EVENT_AMT_DISABLE_ATTEMPT, 				GmsEventType(UNS_GENERAL		, AMT_DISABLE_ATTEMPT));

}
	
bool
WinLogFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	GmsEventType et;
	if (toSubscribe(alert, et))
	{
		return GMSConfig_.CheckEventToPublish(et.id);
	}
	return false;
}

bool
WinLogFilter::toSubscribe(const GMS_AlertIndication *alert, GmsEventType &et) const
{
	int i = eventsMap_.find(alert->id, et);
	if (i==-1)
		return false;
	return true;
}
