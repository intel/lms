/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: StatusEventFilter.cpp

--*/

#include "StatusEventFilter.h"
#include "UNSEventsDefinition.h"

StatusEventFilter::StatusEventFilter(unsigned int maxEventID):eventsIDList_(maxEventID+1, 0, NULL), arrayMaxElement_(maxEventID)
{}

bool
StatusEventFilter::addEvent(unsigned int eventID)
{
	if (eventID > arrayMaxElement_)
		return false;
	eventsIDList_[eventID] = 1;
	return true;
}

bool 
StatusEventFilter::toSubscribe(const GMS_AlertIndication *alert) const
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
StatusEventFilter::defaultInitialization(std::shared_ptr<StatusEventFilter> filter)
{
	if (
		filter->addEvent(EVENT_GENERAL_NOTIFICATION) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_PRE) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_IN) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_POST) &&
		filter->addEvent(EVENT_NETWORK_STATE_CHANGE) &&
		filter->addEvent(EVENT_UNPROVISIONES_STARTED) &&
		filter->addEvent(EVENT_CONTROL_MODE_CHANGE) && 
		filter->addEvent(EVENT_ME_ENABLE) &&
		filter->addEvent(EVENT_ME_DISABLE) &&
		filter->addEvent(EVENT_AMT_ENABLE) &&
		filter->addEvent(EVENT_AMT_DISABLE) &&
		filter->addEvent(EVENT_PORT_FORWARDING_SERVICE_AVAILABLE) &&

		filter->addEvent(EVENT_SYSTEM_DEFENCE_CHANGE) &&

		filter->addEvent(EVENT_REMOTE_SOL_STARTED) &&
		filter->addEvent(EVENT_REMOTE_SOL_ENDED) &&
		filter->addEvent(EVENT_REMOTE_IDER_STARTED) &&
		filter->addEvent(EVENT_REMOTE_IDER_ENDED) &&

		filter->addEvent(EVENT_WIRELESS_STATE_CHANGED) &&
		filter->addEvent(EVENT_WLAN_PROFILE_SYNC_DISABLE) &&
		filter->addEvent(EVENT_WLAN_PROFILE_SYNC_ENABLE) &&
		filter->addEvent(EVENT_WLAN_CONTROL_ME) &&
		filter->addEvent(EVENT_WLAN_CONTROL_HOST) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_ON_HIGH) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_ON_PASSIVE) &&
		filter->addEvent(EVENT_WLAN_PROTECTION_OFF) &&

		filter->addEvent(EVENT_KVM_SESSION_REQUESTED) &&
		filter->addEvent(EVENT_KVM_SESSION_STARTED) &&
		filter->addEvent(EVENT_KVM_SESSION_STOPPED) &&
		filter->addEvent(EVENT_KVM_DISABLED) &&
		filter->addEvent(EVENT_KVM_ENABLED) &&
		filter->addEvent(EVENT_KVM_DATA_CHANNEL) &&

		filter->addEvent(EVENT_SERVICE_RESUME) &&
		filter->addEvent(EVENT_SERVICE_HECI_DISABLE) &&

		filter->addEvent(EVENT_IP_SYNC_DISABLE) &&
		filter->addEvent(EVENT_IP_SYNC_ENABLE) &&
		filter->addEvent(EVENT_IP_REFRESH_LAN) &&
		filter->addEvent(EVENT_IP_REFRESH_WLAN) &&

		filter->addEvent(EVENT_USER_CONSENT_ENDED) &&
		filter->addEvent(EVENT_USER_CONSENT_GRANTED) &&
		filter->addEvent(EVENT_USER_CONSENT_REQUESTED) &&
		filter->addEvent(EVENT_USER_CONSENT_CONFIGURATION_CHANGED) &&

		filter->addEvent(EVENT_AGENT_1) &&
		filter->addEvent(EVENT_AGENT_2)&&
		filter->addEvent(EVENT_AGENT_4)&&

		filter->addEvent(EVENT_TIME_SYNC_DISABLE)&&
		filter->addEvent(EVENT_TIME_SYNC_ENABLE)
	) //if
		return true;
	UNS_DEBUG(L"filter initialization failed", L"\n");
	return false;
}