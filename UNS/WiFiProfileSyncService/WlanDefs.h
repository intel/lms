/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2022 Intel Corporation
 */
#ifndef __WLAN_DEFS_H_
#define __WLAN_DEFS_H_

#include <wlanapi.h>
#include <vector>
#include <memory>

namespace wlanps {

	const unsigned int INTEL_SHORT_DESCR_LEN = 32;
	const unsigned int INTEL_KEY_MATERIAL_LEN = 64;
	const unsigned int MAX_USER_PROFILES = 16; // User Profiles DB maximum size

	typedef struct INTEL_PROFILE_DATA_tag {
		GUID  ifGuid;
		WCHAR profile[WLAN_MAX_NAME_LENGTH + 1];
		WCHAR SSID[DOT11_SSID_MAX_LENGTH + 1];
		WCHAR auth[INTEL_SHORT_DESCR_LEN];
		WCHAR encr[INTEL_SHORT_DESCR_LEN];
		WCHAR keyMaterial[INTEL_KEY_MATERIAL_LEN];

		void FreeKeyMaterial()
		{
			SecureZeroMemory(keyMaterial, INTEL_KEY_MATERIAL_LEN * sizeof(WCHAR));
		}

	}INTEL_PROFILE_DATA, *PINTEL_PROFILE_DATA;
	
	typedef std::vector<std::shared_ptr<INTEL_PROFILE_DATA>> WlanOsProfileList;

	const unsigned short AuthenticationMethodOther = 1;
	const unsigned short AuthenticationMethodOpenSystem = 2;
	const unsigned short AuthenticationMethodSharedKey = 3;
	const unsigned short AuthenticationMethodWPAPSK = 4;
	const unsigned short AuthenticationMethodWPAIEEE802_1x = 5;
	const unsigned short AuthenticationMethodWPA2PSK = 6;
	const unsigned short AuthenticationMethodWPA2IEEE802_1x = 7;
	const unsigned short AuthenticationMethodDMTFReserved = 8;
	const unsigned short AuthenticationMethodWPA3SAE = 32768; // WPA3
	const unsigned short AuthenticationMethodWPA3OWE = 32769; // OWE
	const unsigned short AuthenticationMethodVendorReserved = 32770;

	const unsigned short EncryptionMethodOther = 1;
	const unsigned short EncryptionMethodWEP = 2;
	const unsigned short EncryptionMethodTKIP = 3;
	const unsigned short EncryptionMethodCCMP = 4;
	const unsigned short EncryptionMethodNone = 5;
	const unsigned short EncryptionMethodReserved = 6;
}

#endif // __WLAN_DEFS_H_
