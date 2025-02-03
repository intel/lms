/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2025 Intel Corporation
 */
/*++

@file: WMIFilter.cpp

--*/

#include "WMIFilter.h"
#include "UNSEventsDefinition.h"

WMIFilter::WMIFilter(unsigned int maxEventID):eventsIDList_(maxEventID+1, 0, NULL), arrayMaxElement_(maxEventID)
{}

bool
WMIFilter::addEvent(unsigned int eventID)
{
	if (eventID > arrayMaxElement_)
		return false;
	eventsIDList_[eventID] = 1;
	return true;
}

bool 
WMIFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	if (alert->id <= arrayMaxElement_)
	{
		if (eventsIDList_[alert->id] == 1)
		{
			return true;
		}
	}
	return false;
}

bool
WMIFilter::defaultInitialization(std::shared_ptr<WMIFilter> filter)
{
	if (
		filter->addEvent(EVENT_GENERAL_NOTIFICATION) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_PRE) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_IN) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_POST) &&
		filter->addEvent(EVENT_NETWORK_STATE_CHANGE) &&
		filter->addEvent(EVENT_UNPROVISIONES_STARTED) &&
		filter->addEvent(EVENT_REMOTE_REBOOT) &&
		filter->addEvent(EVENT_ME_ENABLE) &&
		filter->addEvent(EVENT_ME_DISABLE) &&
		filter->addEvent(EVENT_AMT_ENABLE) &&
		filter->addEvent(EVENT_AMT_DISABLE) &&
		filter->addEvent(EVENT_FW_FATAL_ERROR) &&

		filter->addEvent(EVENT_NETWORK_TRAFFIC_TX_CEASED) &&
		filter->addEvent(EVENT_NETWORK_CONNECTIVITY_TX_REDUCED) &&
		filter->addEvent(EVENT_NETWORK_TRAFFIC_RX_CEASED) &&
		filter->addEvent(EVENT_NETWORK_CONNECTIVITY_RX_REDUCED) &&
		filter->addEvent(EVENT_SYSTEM_DEFENCE_CHANGE) &&

		filter->addEvent(EVENT_EAC_NOTIFICATION) &&

		filter->addEvent(EVENT_REMOTE_SOL_STARTED) &&
		filter->addEvent(EVENT_REMOTE_SOL_ENDED) &&
		filter->addEvent(EVENT_REMOTE_IDER_STARTED) &&
		filter->addEvent(EVENT_REMOTE_IDER_ENDED) &&

		filter->addEvent(EVENT_WLAN_PROFILE_INSUFFICIENT) &&
		filter->addEvent(EVENT_WLAN_SECURITY_INSUFFICIENT) &&
		filter->addEvent(EVENT_WLAN_SESSION_ESTABLISHED) &&
		filter->addEvent(EVENT_WLAN_SESSION_ENDED) &&
		filter->addEvent(EVENT_WIRELESS_STATE_CHANGED) &&
		filter->addEvent(EVENT_WLAN_PROFILE_SYNC_DISABLE) &&
		filter->addEvent(EVENT_WLAN_PROFILE_SYNC_ENABLE) &&
		filter->addEvent(EVENT_WLAN_CONTROL_ME) &&
		filter->addEvent(EVENT_WLAN_CONTROL_HOST) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_ON_HIGH) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_ON_PASSIVE) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_OFF) &&

		filter->addEvent(EVENT_SECIO_CONFIGURATION_EVENT) &&

		filter->addEvent(EVENT_KVM_SESSION_REQUESTED) &&
		filter->addEvent(EVENT_KVM_SESSION_STARTED) &&
		filter->addEvent(EVENT_KVM_SESSION_STOPPED) &&
		filter->addEvent(EVENT_KVM_DISABLED) &&
		filter->addEvent(EVENT_KVM_ENABLED) &&
		filter->addEvent(EVENT_KVM_DATA_CHANNEL) &&

		filter->addEvent(EVENT_RCS_TUNNEL_CLOSE) &&
		filter->addEvent(EVENT_RCS_TUNNEL_OPEN) &&

		filter->addEvent(EVENT_SERVICE_HECI_ENABLE) &&
		filter->addEvent(EVENT_SERVICE_HECI_DISABLE) &&
		// LMS extended events
		filter->addEvent(EVENT_PROVISIONING) &&
		filter->addEvent(EVENT_UNPROVISIONING) &&
		filter->addEvent(EVENT_SD_STARTED) &&
		filter->addEvent(EVENT_SD_FINISHED) &&

		filter->addEvent(EVENT_IP_SYNC_DISABLE) &&
		filter->addEvent(EVENT_IP_SYNC_ENABLE) &&

		filter->addEvent(EVENT_USER_CONSENT_ENDED) &&
		filter->addEvent(EVENT_USER_CONSENT_GRANTED) &&
		filter->addEvent(EVENT_USER_CONSENT_REQUESTED) &&
		filter->addEvent(EVENT_USER_CONSENT_TIMEOUT_STARTED) &&

		filter->addEvent(EVENT_AGENT_PRSENCE_NOT_STARTED) &&
		filter->addEvent(EVENT_AGENT_PRSENCE_STOPED) &&
		filter->addEvent(EVENT_AGENT_PRSENCE_EXPIRED)&&

		filter->addEvent(EVENT_TIME_SYNC_DISABLE)&&
		filter->addEvent(EVENT_TIME_SYNC_ENABLE)
	) //if
		return true;
	UNS_ERROR(L"filter initialization failed\n");
	return false;
}