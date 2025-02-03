/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2025 Intel Corporation
 */
#include "IMSSFilter.h"
#include "UNSEventsDefinition.h"

bool IMSSFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	switch (alert->category)
	{
		case CATEGORY_GENERAL:
			if ((alert->id == EVENT_PROVISIONING)||
				(alert->id == EVENT_UNPROVISIONING)||
				(alert->id == EVENT_ME_ENABLE)||
				(alert->id == EVENT_ME_DISABLE)||
				(alert->id == EVENT_AMT_ENABLE)||
				(alert->id == EVENT_AMT_DISABLE)||
				(alert->id == EVENT_NETWORK_STATE_CHANGE)||
				(alert->id == EVENT_REMOTE_REBOOT)||
				(alert->id == EVENT_FW_FATAL_ERROR))
				return true;
		case CATEGORY_CIRCUIT_BREAKER:
			if ((alert->id == EVENT_SD_STARTED)||
				(alert->id == EVENT_SD_FINISHED))
				return true;
		case CATEGORY_REMOTE_DIAGNOSTIC:
			if ((alert->id == EVENT_REMOTE_SOL_STARTED)||
				(alert->id == EVENT_REMOTE_SOL_ENDED) ||
				(alert->id == EVENT_REMOTE_IDER_STARTED)||
				(alert->id == EVENT_REMOTE_IDER_ENDED)
				)
				return true;
		case CATEGORY_WLAN:
			if ((alert->id == EVENT_WLAN_SESSION_ESTABLISHED)||
				(alert->id == EVENT_WLAN_SESSION_ENDED)
				)
				return true;
		case CATEGORY_SECIO:
			if (alert->id == EVENT_SECIO_CONFIGURATION_EVENT)
				return true;
		case CATEGORY_KVM:
			if ((alert->id == EVENT_KVM_SESSION_REQUESTED)||
				(alert->id == EVENT_KVM_SESSION_STARTED) ||
				(alert->id == EVENT_KVM_SESSION_STOPPED)||
				(alert->id == EVENT_KVM_DISABLED)||
				(alert->id == EVENT_KVM_ENABLED)||
				(alert->id == EVENT_KVM_DATA_CHANNEL)
				)
				return true;
		case CATEGORY_RCS:
			if ((alert->id == EVENT_RCS_TUNNEL_OPEN) ||
				(alert->id == EVENT_RCS_TUNNEL_CLOSE)
				)
				return true;
		case CATEGORY_USER_CONSENT:
			if ((alert->id == EVENT_USER_CONSENT_ENDED)||
				(alert->id == EVENT_USER_CONSENT_GRANTED)||
				(alert->id == EVENT_USER_CONSENT_REQUESTED)||
				(alert->id == EVENT_USER_CONSENT_TIMEOUT_STARTED)
				)
				return true;
		case CATEGORY_PARTIAL_FW_UPDATE:
			if ((alert->id == EVENT_PARTIAL_FWU_BEGIN)||
				(alert->id == EVENT_PARTIAL_FWU_END_SUCCESS_WLAN) ||
				(alert->id == EVENT_PARTIAL_FWU_END_SUCCESS_LANG) ||
				(alert->id == EVENT_PARTIAL_FWU_END_FAILURE_WLAN) ||
				(alert->id == EVENT_PARTIAL_FWU_END_FAILURE_LANG) ||
				(alert->id == EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN) ||
				(alert->id == EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG) 
				)
				return true;

	}
	return false;
}