/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018 Intel Corporation
 */
#ifndef __WLAN_NOTIFICATIONS_H_
#define __WLAN_NOTIFICATIONS_H_

#pragma once
#include <wlanapi.h>
#include <winnt.h>
#include "WiFiProfileSyncService.h"

namespace wlanps {

	//
	// handle the MSFT Wireless Zero Configuration (WZC)
	//
	class WlanNotifications
	{

	private:

		WiFiProfileSyncService *m_service;

	public:

		virtual ~WlanNotifications() {};
		static WlanNotifications& getInstance();

		int Init(HANDLE hwlan, WiFiProfileSyncService *service);

	private:

		WlanNotifications();

		WlanNotifications(WlanNotifications const&) = delete;
		WlanNotifications& operator=(WlanNotifications const&) =  delete;

		static VOID WINAPI WlanNotificationCbk(PWLAN_NOTIFICATION_DATA pWlanNotificationData, PVOID pContext);

		static LPWSTR SsidToStringW(__out_ecount(count) LPWSTR buf, __in unsigned long count, __in PDOT11_SSID pSsid);
	};

}

#endif //__WLAN_NOTIFICATIONS_H_