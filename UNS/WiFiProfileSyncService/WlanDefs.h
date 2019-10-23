/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
 */
#ifndef __WLAN_DEFS_H_
#define __WLAN_DEFS_H_

#pragma once

#include <wlanapi.h>
#include <map>
#include <functional>   // std::greater
#include <memory>

namespace wlanps {

	const unsigned int INTEL_SHORT_DESCR_LEN = 32;
	const unsigned int INTEL_KEY_MATERIAL_LEN = 64;
	const unsigned int INTEL_MAX_USERPROFILES = 16;
	const unsigned int INTEL_AT6_NAME_SIZE_1X = 32;
	const unsigned int MAX_OS_USER_PROFILES = 30;

	typedef enum INTEL_PS_EVENTS_tag
	{
		PS_THREAD_SHUTDOWN = WM_USER + 1,
		PS_ACM_CONNECTION_COMPLETE_SUCCESS,
		PS_MSM_DISCONNECTED,

		// Max event for the count
		PS_EVENTS_COUNT
	}INTEL_PS_EVENTS;

	typedef struct INTEL_PROFILE_DATA_tag {
		GUID  ifGuid;
		WCHAR profile[WLAN_MAX_NAME_LENGTH + 1];
		WCHAR SSID[DOT11_SSID_MAX_LENGTH + 1];
		WCHAR auth[INTEL_SHORT_DESCR_LEN];
		WCHAR encr[INTEL_SHORT_DESCR_LEN];
		WCHAR keyMaterial[INTEL_KEY_MATERIAL_LEN];
	}INTEL_PROFILE_DATA, *PINTEL_PROFILE_DATA;

   enum AuthenticationMethods
   {
	   AuthenticationMethodOther = 1,
	   AuthenticationMethodOpenSystem = 2,
	   AuthenticationMethodSharedKey = 3,
	   AuthenticationMethodWPAPSK = 4,
	   AuthenticationMethodWPAIEEE802_1x = 5,
	   AuthenticationMethodWPA2PSK = 6,
	   AuthenticationMethodWPA2IEEE802_1x = 7,
	   AuthenticationMethodDMTFReserved = 8,
	   AuthenticationMethodWPA3SAE = 32768, // WPA3
	   AuthenticationMethodVendorReserved = 32769
   };

   enum EncryptionMethods
   {
	   EncryptionMethodOther = 1,
	   EncryptionMethodWEP = 2,
	   EncryptionMethodTKIP = 3,
	   EncryptionMethodCCMP = 4,
	   EncryptionMethodNone = 5,
	   EncryptionMethodReserved = 6,
   };

}

#endif