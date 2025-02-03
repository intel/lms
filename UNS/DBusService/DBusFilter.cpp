/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2025 Intel Corporation
 */
/*++

@file: DBusFilter.cpp

--*/
#include "DBusFilter.h"
#include "UNSEventsDefinition.h"

DBusFilter::DBusFilter(unsigned int maxEventID):eventsIDList_(maxEventID+1, 0, NULL), arrayMaxElement_(maxEventID)
{}

bool DBusFilter::addEvent(unsigned int eventID)
{
	if (eventID > arrayMaxElement_)
		return false;
	eventsIDList_[eventID] = 1;
	return true;
}

bool DBusFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	if (alert->id <= arrayMaxElement_ && eventsIDList_[alert->id] == 1)
		return true;
	return false;
}

bool DBusFilter::defaultInitialization(std::shared_ptr<DBusFilter> filter)
{
	if (
		filter->addEvent(EVENT_GENERAL_NOTIFICATION) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_PRE) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_IN) &&
		filter->addEvent(EVENT_PROVISIONING_STATE_POST) &&
		filter->addEvent(EVENT_NETWORK_STATE_CHANGE) &&
		filter->addEvent(EVENT_UNPROVISIONES_STARTED) &&
		filter->addEvent(EVENT_CONTROL_MODE_CHANGE) &&
		filter->addEvent(EVENT_REMOTE_REBOOT) &&
		filter->addEvent(EVENT_ME_ENABLE) &&
		filter->addEvent(EVENT_ME_DISABLE) &&
		filter->addEvent(EVENT_AMT_ENABLE) &&
		filter->addEvent(EVENT_AMT_DISABLE) &&
		filter->addEvent(EVENT_FW_FATAL_ERROR) &&
		filter->addEvent(EVENT_WATCHDOG_ERROR) &&

		filter->addEvent(EVENT_NETWORK_TRAFFIC_TX_CEASED) &&
		filter->addEvent(EVENT_NETWORK_CONNECTIVITY_TX_REDUCED) &&
		filter->addEvent(EVENT_NETWORK_TRAFFIC_RX_CEASED) &&
		filter->addEvent(EVENT_NETWORK_CONNECTIVITY_RX_REDUCED) &&
		filter->addEvent(EVENT_SYSTEM_DEFENCE_CHANGE) &&

		filter->addEvent(EVENT_EAC_NOTIFICATION) &&
		filter->addEvent(EVENT_EAC_ENABLED) &&
		filter->addEvent(EVENT_EAC_DISABLED) &&

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
		filter->addEvent(EVENT_KVM_SCREEN_SETTING_UPDATE) &&

		filter->addEvent(EVENT_RCS_TUNNEL_CLOSE) &&
		filter->addEvent(EVENT_RCS_TUNNEL_OPEN) &&

		filter->addEvent(EVENT_SERVICE_RESUME) &&
		filter->addEvent(EVENT_SERVICE_HECI_ENABLE) &&
		filter->addEvent(EVENT_SERVICE_HECI_DISABLE) &&
		// LMS extended events
		filter->addEvent(EVENT_PROVISIONING) &&
		filter->addEvent(EVENT_UNPROVISIONING) &&
		filter->addEvent(EVENT_SD_STARTED) &&
		filter->addEvent(EVENT_SD_FINISHED) &&

		filter->addEvent(EVENT_IP_SYNC_DISABLE) &&
		filter->addEvent(EVENT_IP_SYNC_ENABLE) &&
		filter->addEvent(EVENT_IP_REFRESH_LAN) &&
		filter->addEvent(EVENT_IP_REFRESH_WLAN) &&
		filter->addEvent(EVENT_IP_SYNC_FW_UPDATE_FAILED) &&
		filter->addEvent(EVENT_IP_SYNC_VALIDATION_FAILED) &&
		filter->addEvent(EVENT_PROXY_SYNC_DISABLE) &&
		filter->addEvent(EVENT_PROXY_SYNC_ENABLE) &&

		filter->addEvent(EVENT_USER_CONSENT_ENDED) &&
		filter->addEvent(EVENT_USER_CONSENT_GRANTED) &&
		filter->addEvent(EVENT_USER_CONSENT_REQUESTED) &&
		filter->addEvent(EVENT_USER_CONSENT_TIMEOUT_STARTED) &&
		filter->addEvent(EVENT_USER_CONSENT_CONFIGURATION_CHANGED) &&

		filter->addEvent(EVENT_PARTIAL_FWU_BEGIN) &&
		filter->addEvent(EVENT_PARTIAL_FWU_END_SUCCESS_WLAN) &&
		filter->addEvent(EVENT_PARTIAL_FWU_END_SUCCESS_LANG) &&
		filter->addEvent(EVENT_PARTIAL_FWU_END_FAILURE_WLAN) &&
		filter->addEvent(EVENT_PARTIAL_FWU_END_FAILURE_LANG) &&
		filter->addEvent(EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN) &&
		filter->addEvent(EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG) &&

		filter->addEvent(EVENT_TIME_SYNC_DISABLE) &&
		filter->addEvent(EVENT_TIME_SYNC_ENABLE)
	) //if
		return true;

	UNS_ERROR(L"filter initialization failed\n");
	return false;
}
