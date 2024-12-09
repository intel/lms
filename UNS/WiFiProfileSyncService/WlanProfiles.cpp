/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
#include "global.h"
#include "WlanDefs.h"
#include "WlanProfiles.h"

namespace wlanps
{

	WlanProfiles::WlanProfiles(HANDLE wlanHandle) : m_hwlan(wlanHandle)
	{
	}

	bool WlanProfiles::GetProfileData(PINTEL_PROFILE_DATA profileData, unsigned long* pProfileFlags,
		const authenticationSet_t& supportedAuthentication, const encriptionSet_t& supportedEncription)
	{
		std::wstring auth;
		std::wstring enc;
		std::wstring key;
		std::wstring ssid;
		std::wstring ssidElement;
		bool ret;

		// WlanGetProfile
		LPWSTR pProfileXml = nullptr;
		*pProfileFlags = WLAN_PROFILE_GET_PLAINTEXT_KEY;
		unsigned long  dwGrantedAccess = 0;
		unsigned long  dwResult = WlanGetProfile(m_hwlan, &(profileData->ifGuid), profileData->profile, nullptr, &pProfileXml, pProfileFlags, &dwGrantedAccess);

		if (dwResult != ERROR_SUCCESS)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: WlanGetProfile failed with %d\n", dwResult);
			ret = false;
			goto cleanup;
		}

		// Check if this profile is an IT (Group Policy) profile
		if (*pProfileFlags & WLAN_PROFILE_GROUP_POLICY)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %W is a Group Policy Profile\n", profileData->profile);
			ret = false;
			goto cleanup; // skip
		}

		if (!isLegalProfileName(profileData->profile))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: illegal profile name %W\n", profileData->profile);
			ret = false;
			goto cleanup;
		}

		if (pProfileXml == nullptr)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: empty profile xml for %W\n", profileData->profile);
			ret = false;
			goto cleanup;
		}

		auth = xmlRead(pProfileXml, L"authentication");
		enc = xmlRead(pProfileXml, L"encryption");
		key = xmlRead(pProfileXml, L"keyMaterial");
		ssidElement = xmlRead(pProfileXml, L"SSID");
		ssid = xmlRead(ssidElement, L"name");

		if (!isSupportedEncription(enc, supportedEncription))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: encription unsupported by LMS-PS %W for Profile %W\n",
				enc.c_str(), profileData->profile);
			ret = false;
			goto cleanup;
		}

		if (!isSupportedAuthentication(auth, supportedAuthentication))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: authentication unsupported by LMS-PS %W for Profile %W\n",
				auth.c_str(), profileData->profile);
			ret = false;
			goto cleanup;
		}

		//Set the profile data
		wcsncpy_s(profileData->auth, INTEL_SHORT_DESCR_LEN, auth.c_str(), auth.length());
		wcsncpy_s(profileData->encr, INTEL_SHORT_DESCR_LEN, enc.c_str(), enc.length());
		wcsncpy_s(profileData->keyMaterial, INTEL_KEY_MATERIAL_LEN, key.c_str(), key.length());
		wcsncpy_s(profileData->SSID, ssid.c_str(), _countof(profileData->SSID));

		ret = true;

	cleanup:
		if (pProfileXml != nullptr)
		{
			WlanFreeMemory(pProfileXml);
			pProfileXml = nullptr;
		}
		SecureZeroMemory(&key[0], key.size() * sizeof(WCHAR));

		return ret;
	}

	std::wstring WlanProfiles::xmlRead(const std::wstring& strXML, std::wstring strKey)
	{
		std::wstring strVal;
		std::wstring start_tag, end_tag;

		start_tag = L"<" + strKey + L">";
		size_t start_tag_len = start_tag.length();

		end_tag = L"</" + strKey + L">";
		size_t start_pos = strXML.find(start_tag, 0);
		size_t end_pos = strXML.find(end_tag, start_pos);

		if (start_pos != strXML.npos && end_pos != strXML.npos && start_pos < end_pos && (start_pos + start_tag_len) < end_pos)
		{
			strVal = strXML.substr(start_pos + start_tag_len, end_pos - (start_pos + start_tag_len));
		}
		return strVal;
	}

	bool WlanProfiles::isLegalProfileName(const std::wstring& profileName)
	{
		bool isLegal = false;

		std::wstring startOfTag = L"<";
		std::wstring endOfTag = L">";
		std::wstring ampersand = L"&";

		size_t startOfTagPosition = profileName.find(startOfTag, 0);
		size_t endOfTagPosition = profileName.find(endOfTag, 0);
		size_t ampersandPosition = profileName.find(ampersand, 0);

		if ((startOfTagPosition == std::wstring::npos) &&
			(endOfTagPosition == std::wstring::npos) &&
			(ampersandPosition == std::wstring::npos))
		{
			isLegal = true;
		}
		else
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Bad characters in profile name\n");
		}
		return isLegal;
	}

	bool WlanProfiles::GetProfiles(WlanOsProfileList& profiles, const authenticationSet_t& supportedAuthentication, const encriptionSet_t& supportedEncription)
	{
		// initialize variables
		unsigned long dwResult = 0;

		// WlanEnumInterfaces
		PWLAN_INTERFACE_INFO_LIST pIfList = nullptr;
		PWLAN_PROFILE_INFO_LIST   pProfileList = nullptr;

		PWLAN_INTERFACE_INFO      pIfInfo = nullptr;
		PWLAN_PROFILE_INFO        pProfile = nullptr;

		if (nullptr == m_hwlan)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": handle is not opened\n");
			return false;
		}

		dwResult = WlanEnumInterfaces(m_hwlan, nullptr, &pIfList);
		if (dwResult != ERROR_SUCCESS)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": WlanEnumInterfaces failed with error: %d\n", dwResult);
			return false;
		}
		if (pIfList == nullptr)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": WlanEnumInterfaces returned nullptr\n");
			return false;
		}

		UNS_TRACE(L"[ProfileSync] " __FUNCTIONW__": WLAN_INTERFACE_INFO_LIST Entries: %d Index: %d\n",
			pIfList->dwNumberOfItems, pIfList->dwIndex);

		// Loop over Wlan Interfaces
		for (size_t i = 0; i < pIfList->dwNumberOfItems; i++)
		{
			pIfInfo = (WLAN_INTERFACE_INFO*)&pIfList->InterfaceInfo[i];

			UNS_TRACE(L"[ProfileSync] " __FUNCTIONW__": [%d] Interface Description: %W  Interface State: %d, dwNumberOfItems = %d\n",
				i, pIfInfo->strInterfaceDescription, pIfInfo->isState, pIfList->dwNumberOfItems);

			dwResult = WlanGetProfileList(m_hwlan, &pIfInfo->InterfaceGuid, nullptr, &pProfileList);
			if (dwResult != ERROR_SUCCESS)
			{
				UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": WlanGetProfileList error: %u\n", dwResult);
				continue;
			}

			UNS_TRACE(L"[ProfileSync] " __FUNCTIONW__": WlanGetProfileList num of items: %d\n", pProfileList->dwNumberOfItems);

			// Loop over all OS profiles or until MAX_USER_PROFILES User Profiles were found
			for (size_t j = 0; (j < pProfileList->dwNumberOfItems) && (profiles.size() < MAX_USER_PROFILES); j++)
			{
				std::shared_ptr<INTEL_PROFILE_DATA> prof(new INTEL_PROFILE_DATA);
				unsigned long profileFlags = 0;

				pProfile = (WLAN_PROFILE_INFO*)&pProfileList->ProfileInfo[j];
				wcsncpy_s(prof->profile, pProfile->strProfileName, _countof(prof->profile));
				memcpy_s(&prof->ifGuid, sizeof(prof->ifGuid), &pIfInfo->InterfaceGuid, sizeof(prof->ifGuid));

				if (!GetProfileData(prof.get(), &profileFlags, supportedAuthentication, supportedEncription))
				{
					UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: GetProfileData failed\n");
					continue;
				}

				//update the list
				profiles.push_back(prof);
			}
		}

		UNS_TRACE(L"[ProfileSync] " __FUNCTIONW__": numUserProfiles %d\n", profiles.size());

		if (pProfileList != nullptr)
		{
			WlanFreeMemory(pProfileList);
			pProfileList = nullptr;
		}

		if (pIfList != nullptr)
		{
			WlanFreeMemory(pIfList);
			pIfList = nullptr;
		}

		return true;
	}

	bool WlanProfiles::isSupportedEncription(const std::wstring& enc, const encriptionSet_t& supportedEnc)
	{
		return (supportedEnc.find(enc) != supportedEnc.end());
	}

	bool WlanProfiles::isSupportedAuthentication(const std::wstring& auth, const authenticationSet_t& supportedAuth)
	{
		return (supportedAuth.find(auth) != supportedAuth.end());
	}

} // namespace wlanps