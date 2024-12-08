/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
#include "global.h"
#include <sstream>
#include <algorithm>
#include "DataStorageGenerator.h"
#include "WlanDefs.h"
#include "WlanProfiles.h"

namespace wlanps
{
	WlanProfiles::WlanProfiles(HANDLE wlanHandle, bool _transition_workaround) :
		m_hwlan(wlanHandle), transition_workaround(_transition_workaround), name_mapper(_transition_workaround)
	{
	}

	bool WlanProfiles::GetProfileData(PINTEL_PROFILE_DATA profileData, unsigned long* pProfileFlags,
		const authenticationSet_t& supportedAuthentication, const encriptionSet_t& supportedEncription, const crossauthSet_t& supportedCrossauth,
		bool add_map)
	{
		std::wstring auth;
		std::wstring auth2;
		std::wstring enc;
		std::wstring key;
		std::wstring ssid;
		std::wstring ssidElement;
		std::wstring transitionModeStr;
		bool transitionMode = false;
		WlanProfileNameMapper::profile_numbers_t nameMap;
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
		transitionModeStr = xmlReadWithNamespace(pProfileXml, L"transitionMode");
		transitionMode = (transitionModeStr == L"true");

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

		if (transitionMode && (auth2 = checkSupportedTransitionAuthentication(auth, supportedCrossauth)).empty())
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: authentication unsupported for transition by LMS-PS %W for Profile %W\n",
				auth.c_str(), profileData->profile);
			ret = false;
			goto cleanup;
		}

		//Set the profile data
		wcsncpy_s(profileData->auth, INTEL_SHORT_DESCR_LEN, auth.c_str(), auth.length());
		wcsncpy_s(profileData->auth2, INTEL_SHORT_DESCR_LEN, auth2.c_str(), auth2.length());
		wcsncpy_s(profileData->encr, INTEL_SHORT_DESCR_LEN, enc.c_str(), enc.length());
		wcsncpy_s(profileData->keyMaterial, INTEL_KEY_MATERIAL_LEN, key.c_str(), key.length());
		wcsncpy_s(profileData->SSID, ssid.c_str(), _countof(profileData->SSID));
		profileData->transitionMode = transitionMode;
		if (transition_workaround)
		{
			nameMap = name_mapper.GetProfile(profileData->profile);
			if (add_map)
			{
				nameMap = name_mapper.AddProfile(profileData->profile, nameMap, transitionMode);
			}
			profileData->profileID1 = nameMap.first;
			profileData->profileID2 = nameMap.second;
		}

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

	std::wstring WlanProfiles::xmlRead(const std::wstring &strXML, std::wstring strKey)
	{
		std::wstring strVal;
		std::wstring start_tag, end_tag;

		start_tag = L"<" + strKey + L">";
		size_t start_tag_len = start_tag.length();

		end_tag = L"</" + strKey + L">";
		size_t start_pos = strXML.find(start_tag, 0);
		size_t end_pos = strXML.find(end_tag, start_pos);

		if (start_pos != strXML.npos &&  end_pos != strXML.npos && start_pos < end_pos && (start_pos + start_tag_len) < end_pos)
		{
			strVal = strXML.substr(start_pos + start_tag_len, end_pos - (start_pos + start_tag_len));
		}
		return strVal;
	}

	std::wstring WlanProfiles::xmlReadWithNamespace(const std::wstring& strXML, std::wstring strKey)
	{
		std::wstring strVal;
		std::wstring start_tag, end_tag;

		start_tag = L"<" + strKey;
		end_tag = L"</" + strKey + L">";
		size_t start_pos = strXML.find(start_tag, 0);
		start_pos = strXML.find(L'>', start_pos);
		size_t end_pos = strXML.find(end_tag, start_pos);

		if (start_pos != strXML.npos && end_pos != strXML.npos && start_pos < end_pos && (start_pos + 1) < end_pos)
		{
			strVal = strXML.substr(start_pos + 1, end_pos - (start_pos + 1));
		}
		return strVal;
	}

	bool WlanProfiles::isLegalProfileName(const std::wstring &profileName)
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

	bool WlanProfiles::GetProfiles(WlanOsProfileList& profiles, const authenticationSet_t& supportedAuthentication,
		const encriptionSet_t& supportedEncription, const crossauthSet_t& supportedCrossauth)
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

			size_t max_profiles = (transition_workaround) ? MAX_USER_PROFILES / 2 : MAX_USER_PROFILES;
			// Loop over all OS profiles or until MAX_USER_PROFILES User Profiles were found
			for (size_t j = 0; (j < pProfileList->dwNumberOfItems) && (profiles.size() < max_profiles); j++)
			{
				std::shared_ptr<INTEL_PROFILE_DATA> prof(new INTEL_PROFILE_DATA);
				unsigned long profileFlags = 0;

				pProfile = (WLAN_PROFILE_INFO*)&pProfileList->ProfileInfo[j];
				wcsncpy_s(prof->profile, pProfile->strProfileName, _countof(prof->profile));
				memcpy_s(&prof->ifGuid, sizeof(prof->ifGuid), &pIfInfo->InterfaceGuid, sizeof(prof->ifGuid));

				if (!GetProfileData(prof.get(), &profileFlags, supportedAuthentication, supportedEncription, supportedCrossauth, false))
				{
					UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: GetProfileData failed\n");
					continue;
				}

				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Profile= %-25W SSID= %-25W aut= %-10W/%-10W, enc= %W, transitionMode= %d\n",
					prof->profile, prof->SSID, prof->auth, prof->auth2, prof->encr, prof->transitionMode);
				//update the list
				profiles.push_back(prof);
			}
		}

		if (transition_workaround)
		{
			// update name_mapper to remove profiles that cease to exists
			name_mapper.Clean();
			for (const auto& profile : profiles)
			{
				name_mapper.InsertProfile(profile->profile,
					WlanProfileNameMapper::profile_numbers_t(profile->profileID1, profile->profileID2));
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

	void WlanProfiles::RefillProfilesWithID(WlanOsProfileList& profiles)
	{
		if (!transition_workaround)
			return;

		for (const auto& profile : profiles)
		{
			WlanProfileNameMapper::profile_numbers_t num(profile->profileID1, profile->profileID2);
			num = name_mapper.AddProfile(profile->profile, num, profile->transitionMode);
			profile->profileID1 = num.first;
			profile->profileID2 = num.second;
		}
	}

	std::wstring WlanProfiles::checkSupportedTransitionAuthentication(const std::wstring &auth, const crossauthSet_t &supportedCrossauth)
	{
		auto auth_pair = find_if(supportedCrossauth.cbegin(), supportedCrossauth.cend(),
			[auth](const auto& auth_p) { return auth_p.first == auth; });

		if (auth_pair == supportedCrossauth.end())
			return std::wstring(); // No supported auth found
		return auth_pair->second;
	}

	bool WlanProfileNameMapper::ReadMap()
	{
		if (!transition_workaround)
			return true;

		std::wstring map_str;
		wchar_t *pos, *pos1, *pos2;
		wchar_t *context = NULL;
		if (!DSinstance().GetDataValue(WlanProfileNames, map_str, true))
		{
			// if fail, continue with empty map
			UNS_ERROR(L"WlanProfileNameMapper registry read failed\n");
		}
		pos = wcstok_s(&map_str[0], delimiter, &context);
		while (pos != NULL)
		{
			pos1 = wcstok_s(NULL, delimiter, &context);
			pos2 = wcstok_s(NULL, delimiter, &context);
			if (pos1 == NULL || pos2 == NULL)
			{
				profile_map.clear();
				return false;
			}
			profile_map[pos] = profile_numbers_t(_wtoi(pos1), _wtoi(pos2));
			pos = wcstok_s(NULL, delimiter, &context);
		}
		return true;
	}

	bool WlanProfileNameMapper::WriteMap()
	{
		if (!transition_workaround)
			return true;

		std::wstringstream map_str;
		bool first_val = true;

		for (const auto& [profile_name, profile_numbers] : profile_map)
		{
			if (first_val)
			{
				first_val = false;
			}
			else
			{
				map_str << delimiter;
			}
			map_str << profile_name << delimiter << profile_numbers.first << delimiter << profile_numbers.second;
		}
		return DSinstance().SetDataValue(WlanProfileNames, map_str.str(), true);
	}

	WlanProfileNameMapper::profile_numbers_t WlanProfileNameMapper::GetProfile(const std::wstring& name)
	{
		if (!transition_workaround)
			return profile_numbers_t(0, 0);
		try
		{
			return profile_map.at(name);
		}
		catch (const std::out_of_range&)
		{
			return profile_numbers_t(0, 0);
		}
	}

	WlanProfileNameMapper::profile_numbers_t WlanProfileNameMapper::InsertProfile(const std::wstring& name, const profile_numbers_t &num)
	{
		if (!transition_workaround)
			return profile_numbers_t(0, 0);
		profile_map[name] = num;
		WriteMap();
		return profile_map[name];
	}

	WlanProfileNameMapper::profile_numbers_t WlanProfileNameMapper::AddProfile(const std::wstring& name, const profile_numbers_t &num, bool transitionMode)
	{
		if (!transition_workaround)
			return profile_numbers_t(0, 0);
		if (num.first != 0)
		{
			profile_map[name] = profile_numbers_t(num.first, (transitionMode) ? num.first + 1 : 0);
			WriteMap();
			return profile_map[name];
		}

		for (unsigned int id = 1; id < 255; id += 2)
		{
			if (std::find_if(profile_map.cbegin(), profile_map.cend(),
				[&id](const profile_name_map_t::value_type& profile) { return profile.second.first == id; }) == profile_map.cend())
			{
				profile_map[name] = profile_numbers_t(id, (transitionMode) ? id + 1 : 0);;
				WriteMap();
				return profile_map[name];
			}
		}
		return profile_numbers_t(0, 0);
	}

	bool WlanProfileNameMapper::DelProfile(const std::wstring& name)
	{
		if (!transition_workaround)
			return true;
		bool ret = profile_map.erase(name) == 1;
		WriteMap();
		return ret;
	}
} // namespace wlanps