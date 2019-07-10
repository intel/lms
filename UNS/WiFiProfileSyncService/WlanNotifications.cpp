/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
 */
#include <string>
#include "global.h"
#include "WlanDefs.h"
#include "WlanNotifications.h"
#include "MessageBlockPtr.h"
#include "WiFiProfileSyncService.h"

wlanps::WlanNotifications& wlanps::WlanNotifications::getInstance()
{
	static WlanNotifications wlanNotificationsInstance;
	return wlanNotificationsInstance;
}

int wlanps::WlanNotifications::Init(HANDLE hwlan, WiFiProfileSyncService *service)
{

	m_service = service;

	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": WlanRegisterNotification\n");

	//  register notifications on all wireless interfaces
	unsigned long retVal = WlanRegisterNotification(
		hwlan,
		WLAN_NOTIFICATION_SOURCE_ACM | WLAN_NOTIFICATION_SOURCE_MSM,
		TRUE,                      // IgnoreDuplicate, TRUE - notification will not be sent to the client if it is identical to the previous one.
		wlanps::WlanNotifications::WlanNotificationCbk,
		this,                       // context - pointer to the object class
		nullptr,                    // Reserved for future use. Must be set to nullptr
		nullptr                     // dwPrevNotifSource - A pointer to the previously registered notification sources.
	);

	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": WlanRegisterNotification retVal=%d\n", retVal);

	return 0;
}

// copy SSID to a null-terminated WCHAR string
// count is the number of WCHAR in the buffer.
LPWSTR wlanps::WlanNotifications::SsidToStringW(__out_ecount(count) LPWSTR buf, __in unsigned long count, __in PDOT11_SSID pSsid)
{
	ULONG   bytes, i;
	bytes = count - 1 < pSsid->uSSIDLength ? (count - 1) : pSsid->uSSIDLength;
	for (i = 0; i<bytes; i++)
		mbtowc(&buf[i], (const char *)&pSsid->ucSSID[i], 1);
	buf[bytes] = '\0';
	return buf;
}

wlanps::WlanNotifications::WlanNotifications(): m_service(nullptr)
{

}

VOID WINAPI wlanps::WlanNotifications::WlanNotificationCbk(PWLAN_NOTIFICATION_DATA pWlanNotificationData, PVOID pContext)
{
	wlanps::WlanNotifications *pWlanNotif = (wlanps::WlanNotifications*)(pContext);
	PWLAN_CONNECTION_NOTIFICATION_DATA pConnNotifData =	(PWLAN_CONNECTION_NOTIFICATION_DATA)pWlanNotificationData->pData;

	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Got WLAN Notification. Source = %d\n", pWlanNotificationData->NotificationSource);

	if (pWlanNotificationData->NotificationSource == WLAN_NOTIFICATION_SOURCE_ACM && 
		pWlanNotificationData->NotificationCode == wlan_notification_acm_connection_complete)
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": acm_connection_complete\n");
			
		if (pConnNotifData->wlanReasonCode == WLAN_REASON_CODE_SUCCESS)
		{
			// Send profile, GUID, SSID to eventHandler.
			MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);

			WiFiProfileSyncService::WPFS_Message_Block *message = new WiFiProfileSyncService::WPFS_Message_Block();

			wcsncpy_s(message->_profileData.profile, WLAN_MAX_NAME_LENGTH, pConnNotifData->strProfileName, WLAN_MAX_NAME_LENGTH);
			message->_profileData.ifGuid = pWlanNotificationData->InterfaceGuid;
			SsidToStringW(message->_profileData.SSID, sizeof(message->_profileData.SSID) / sizeof(WCHAR), &pConnNotifData->dot11Ssid);

			mbPtr->data_block(message);
			mbPtr->msg_type(MB_WPFS_SYNC);
			pWlanNotif->m_service->putq(mbPtr->duplicate());
		}
		else
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": connection failed\n");
		}
	}
}