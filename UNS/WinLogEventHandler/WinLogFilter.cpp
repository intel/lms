/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
#include "WinLogFilter.h"
#include "UNSEventsDefinition.h"
#include "UNSMessageFile.h"
#include "UNSRegistry.h"
#include <vector>

struct filter_entry
{
	LmsRegStr reg;
	uint32_t id;
	uint16_t category;
	int ev_id;
};

static const std::vector<filter_entry> config_bindings = {
	{ LMS_REG_TEXT("NETWORK_TRAFFIC_TX_CEASED"), NETWORK_TRAFFIC_TX_CEASED, UNS_CIRCUIT_BREAKER, EVENT_NETWORK_TRAFFIC_TX_CEASED},
	{ LMS_REG_TEXT("NETWORK_CONNECTIVITY_TX_REDUCED"), NETWORK_CONNECTIVITY_TX_REDUCED, UNS_CIRCUIT_BREAKER, EVENT_NETWORK_CONNECTIVITY_TX_REDUCED},
	{ LMS_REG_TEXT("NETWORK_TRAFFIC_RX_CEASED"), NETWORK_TRAFFIC_RX_CEASED, UNS_CIRCUIT_BREAKER, EVENT_NETWORK_TRAFFIC_RX_CEASED},
	{ LMS_REG_TEXT("NETWORK_CONNECTIVITY_RX_REDUCED"), NETWORK_CONNECTIVITY_RX_REDUCED, UNS_CIRCUIT_BREAKER, EVENT_NETWORK_CONNECTIVITY_RX_REDUCED},

	{ LMS_REG_TEXT("WLAN_WIRELESS_PROFILE_STATE_CHANGED"), WLAN_WIRELESS_PROFILE_STATE_CHANGED, UNS_WLAN, EVENT_WIRELESS_STATE_CHANGED},
	{ LMS_REG_TEXT("WLAN_PROFILE_INSUFFICIENT"), WLAN_PROFILE_INSUFFICIENT, UNS_WLAN, EVENT_WLAN_PROFILE_INSUFFICIENT},
	{ LMS_REG_TEXT("WLAN_SECURITY_INSUFFICIENT"), WLAN_SECURITY_INSUFFICIENT, UNS_WLAN, EVENT_WLAN_SECURITY_INSUFFICIENT},
	{ LMS_REG_TEXT("WLAN_SESSION_ESTABLISHED"), WLAN_SESSION_ESTABLISHED, UNS_WLAN, EVENT_WLAN_SESSION_ESTABLISHED},
	{ LMS_REG_TEXT("WLAN_SESSION_ENDED"), WLAN_SESSION_ENDED, UNS_WLAN, EVENT_WLAN_SESSION_ENDED},
	{ LMS_REG_TEXT("WLAN_PROFILE_SYNC_DISABLE"), WLAN_PROFILE_SYNC_DISABLE, UNS_WLAN, EVENT_WLAN_PROFILE_SYNC_DISABLE},
	{ LMS_REG_TEXT("WLAN_PROFILE_SYNC_ENABLE"), WLAN_PROFILE_SYNC_ENABLE, UNS_WLAN, EVENT_WLAN_PROFILE_SYNC_ENABLE},

	{ LMS_REG_TEXT("WLAN_CONTROL_ME"), WLAN_CONTROL_ME, UNS_WLAN, EVENT_WLAN_CONTROL_ME},
	{ LMS_REG_TEXT("WLAN_CONTROL_HOST"), WLAN_CONTROL_HOST, UNS_WLAN, EVENT_WLAN_CONTROL_HOST},
	{ LMS_REG_TEXT("WLAN_PROTECTION_HIGH"), WLAN_PROTECTION_ON_HIGH, UNS_WLAN, EVENT_WLAN_PROTECTION_ON_HIGH},
	{ LMS_REG_TEXT("WLAN_PROTECTION_PASSIVE"), WLAN_PROTECTION_ON_PASSIVE, UNS_WLAN, EVENT_WLAN_PROTECTION_ON_PASSIVE},
	{ LMS_REG_TEXT("WLAN_PROTECTION_OFF"), WLAN_PROTECTION_OFF, UNS_WLAN, EVENT_WLAN_PROTECTION_OFF},

	{ LMS_REG_TEXT("REMOTE_SOL_STARTED"), REMOTE_SOL_STARTED, UNS_REMOTE_DIAGNOSTIC, EVENT_REMOTE_SOL_STARTED},
	{ LMS_REG_TEXT("REMOTE_SOL_ENDED"), REMOTE_SOL_ENDED, UNS_REMOTE_DIAGNOSTIC,EVENT_REMOTE_SOL_ENDED },
	{ LMS_REG_TEXT("REMOTE_IDER_STARTED"), REMOTE_USBR_STARTED, UNS_REMOTE_DIAGNOSTIC, EVENT_REMOTE_IDER_STARTED},
	{ LMS_REG_TEXT("REMOTE_IDER_ENDED"), REMOTE_USBR_ENDED, UNS_REMOTE_DIAGNOSTIC, EVENT_REMOTE_IDER_ENDED},

	{ LMS_REG_TEXT("REMOTE_GRACEFUL_SHUTDOWN_SUCCEED"), REMOTE_GRACEFUL_SHUTDOWN_SUCCEED, UNS_REMOTE_PWR, EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED},
	{ LMS_REG_TEXT("REMOTE_GRACEFUL_SHUTDOWN_FAILED"), REMOTE_GRACEFUL_SHUTDOWN_FAILED, UNS_REMOTE_PWR, EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED},
	{ LMS_REG_TEXT("REMOTE_GRACEFUL_REBOOT_SUCCEED "), REMOTE_GRACEFUL_REBOOT_SUCCEED, UNS_REMOTE_PWR, EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED},
	{ LMS_REG_TEXT("REMOTE_GRACEFUL_REBOOT_FAILED"), REMOTE_GRACEFUL_REBOOT_FAILED, UNS_REMOTE_PWR, EVENT_REMOTE_GRACEFUL_REBOOT_FAILED},
	{ LMS_REG_TEXT("REMOTE_SLEEP"), REMOTE_SLEEP, UNS_REMOTE_PWR, EVENT_REMOTE_SLEEP},
	{ LMS_REG_TEXT("REMOTE_HIBERNATE"), REMOTE_HIBERNATE, UNS_REMOTE_PWR, EVENT_REMOTE_HIBERNATE},
	{ LMS_REG_TEXT("REMOTE_SLEEP_FAILED"), REMOTE_SLEEP_FAILED, UNS_REMOTE_PWR, EVENT_REMOTE_SLEEP_FAILED},
	{ LMS_REG_TEXT("REMOTE_HIBERNATE_FAILED"), REMOTE_HIBERNATE_FAILED, UNS_REMOTE_PWR, EVENT_REMOTE_HIBERNATE_FAILED},

	{ LMS_REG_TEXT("PFW_UPGRADE_SUCCESS_LANG"), PFW_UPGRADE_SUCCESS_LANG, UNS_GENERAL, EVENT_PARTIAL_FWU_END_SUCCESS_LANG},
	{ LMS_REG_TEXT("PFW_UPGRADE_SUCCESS_WLAN"), PFW_UPGRADE_SUCCESS_WLAN, UNS_GENERAL, EVENT_PARTIAL_FWU_END_SUCCESS_WLAN},
	{ LMS_REG_TEXT("VAL_PFW_UPGRADE_FAILURE_LANG"), PFW_UPGRADE_FAILURE_LANG, UNS_GENERAL, EVENT_PARTIAL_FWU_END_FAILURE_LANG},
	{ LMS_REG_TEXT("VAL_PFW_UPGRADE_FAILURE_WLAN"), PFW_UPGRADE_FAILURE_WLAN, UNS_GENERAL, EVENT_PARTIAL_FWU_END_FAILURE_WLAN},
	{ LMS_REG_TEXT("MISSING_IMAGE_FILE_LANG"), MISSING_IMAGE_FILE_LANG, UNS_GENERAL, EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG},
	{ LMS_REG_TEXT("MISSING_IMAGE_FILE_WLAN"), MISSING_IMAGE_FILE_WLAN, UNS_GENERAL, EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN},

	{ LMS_REG_TEXT("IP_REFRESH_REQUESTED_LAN"), IP_REFRESH_REQUESTED_LAN, UNS_GENERAL, EVENT_IP_REFRESH_REQUESTED_LAN},
	{ LMS_REG_TEXT("IP_REFRESH_REQUESTED_WLAN"), IP_REFRESH_REQUESTED_WLAN, UNS_GENERAL, EVENT_IP_REFRESH_REQUESTED_WLAN},

	{ LMS_REG_TEXT("UNS_NETWORK_SYNC_VALIDATION_FAILED"), UNS_NETWORK_SYNC_VALIDATION_FAILED, UNS_GENERAL, EVENT_IP_SYNC_VALIDATION_FAILED},
	{ LMS_REG_TEXT("UNS_NETWORK_SYNC_UPDATE_FAILED"), UNS_NETWORK_SYNC_UPDATE_FAILED, UNS_GENERAL, EVENT_IP_SYNC_FW_UPDATE_FAILED},
	{ LMS_REG_TEXT("ALARM_CLOCK_BOOT"), ALARM_CLOCK_REBOOT, UNS_GENERAL, EVENT_ALARM_CLOCK_BOOT},

	{ LMS_REG_TEXT("AGENT_PRSENCE_NOT_STARTED"), AGENT_PRSENCE_NOT_STARTED, UNS_GENERAL, EVENT_AGENT_PRSENCE_NOT_STARTED},
	{ LMS_REG_TEXT("AGENT_PRSENCE_STOPED"), AGENT_PRSENCE_STOPED, UNS_GENERAL, EVENT_AGENT_PRSENCE_STOPED},
	{ LMS_REG_TEXT("AGENT_PRSENCE_EXPIRED"), AGENT_PRSENCE_EXPIRED, UNS_GENERAL, EVENT_AGENT_PRSENCE_EXPIRED},

	{ LMS_REG_TEXT("FW_FATAL_ERROR"), FW_FATAL_ERROR, UNS_GENERAL, EVENT_FW_FATAL_ERROR},

	{ LMS_REG_TEXT("KVM_SESSION_STARTED"), KVM_SESSION_STARTED, UNS_GENERAL, EVENT_KVM_SESSION_STARTED},
	{ LMS_REG_TEXT("KVM_SESSION_STOPPED"), KVM_SESSION_STOPPED, UNS_GENERAL, EVENT_KVM_SESSION_STOPPED},

	{ LMS_REG_TEXT("PORT_FORWARDING_SERVICE_UNAVAILABLE"), PORT_FORWARDING_SERVICE_UNAVAILABLE, UNS_GENERAL, EVENT_PORT_FORWARDING_SERVICE_UNAVAILABLE},

	{ LMS_REG_TEXT("AMT_DISABLE_ATTEMPT"), AMT_DISABLE_ATTEMPT, UNS_GENERAL, EVENT_AMT_DISABLE_ATTEMPT},

	{ LMS_REG_TEXT("WATCHDOG_ERROR"), WATCHDOG_ERROR, UNS_GENERAL, EVENT_WATCHDOG_ERROR},

	{ LMS_REG_TEXT("FWCIRAWORKAROUND_SUCCESS"), FWCIRAWORKAROUND_SUCCESS, UNS_GENERAL, EVENT_FWCIRAWORKAROUND_SUCCESS},
	{ LMS_REG_TEXT("FWCIRAWORKAROUND_FAILURE"), FWCIRAWORKAROUND_FAILURE, UNS_GENERAL, EVENT_FWCIRAWORKAROUND_FAILURE},
};

WinLogFilter::WinLogFilter()
{
	for (const auto& bind : config_bindings)
	{
		unsigned long lval = 1;
		//For every parameter that is read, if it's not found, its default value is used.
		GetFromRegistry(LMS_REG_CONFIG_DATA, bind.reg, &lval, 1);
		m_EventsToPublish.bind(bind.id, lval);
		eventsMap_.bind(bind.ev_id, GmsEventType(bind.category, bind.id));
	}

	m_EventsToPublish.bind(UNS_WARNING_MESSAGE, 1);
	m_EventsToPublish.bind(UNS_ERROR_MESSAGE, 1);
}
	
bool WinLogFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	GmsEventType et;
	if (toSubscribe(alert, et))
	{
		return CheckEventToPublish(et.id);
	}
	return false;
}

bool WinLogFilter::toSubscribe(const GMS_AlertIndication *alert, GmsEventType &et) const
{
	return (eventsMap_.find(alert->id, et) != -1);
}

bool WinLogFilter::CheckEventToPublish(unsigned long EventID) const
{
	int publish;
	if (m_EventsToPublish.find(EventID, publish) == -1) {
		// The event is not in the map
		UNS_DEBUG(L"Event [%d] does not need to publish\n", EventID);
		return false;
	}
	return (publish == 1);
}
