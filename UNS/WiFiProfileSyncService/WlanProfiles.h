/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
#ifndef __WLAN_PRFOFILES_H_
#define __WLAN_PRFOFILES_H_

#include <wlanapi.h>
#include <winnt.h>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "WlanDefs.h"

namespace wlanps {

	class WlanProfileNameMapper
	{
	public:
		typedef std::pair<unsigned int, unsigned int> profile_numbers_t;
	private:
		bool transition_workaround;
		typedef std::map<std::wstring, profile_numbers_t> profile_name_map_t;
		profile_name_map_t profile_map;
		const wchar_t* delimiter = L"&";

		bool ReadMap();
		bool WriteMap();

		/*
		* Map format: <profile name>&<number1>&<number2>&...
		*/

	public:
		WlanProfileNameMapper(bool _transition_workaround): transition_workaround(_transition_workaround) { ReadMap(); };

		void Clean() { profile_map.clear(); };
		profile_numbers_t InsertProfile(const std::wstring &name, const profile_numbers_t &num);
		profile_numbers_t AddProfile(const std::wstring &name, const profile_numbers_t &num, bool transitionMode);
		bool DelProfile(const std::wstring &name);
		profile_numbers_t GetProfile(const std::wstring &name);
	};

	typedef std::set<std::wstring> authenticationSet_t;
	typedef std::set<std::wstring> encriptionSet_t;
	typedef std::vector<std::pair<std::wstring, std::wstring>> crossauthSet_t;

	class WlanProfiles
	{
	private:
		HANDLE m_hwlan;
		bool transition_workaround;

	public:
		WlanProfiles(HANDLE hwlan, bool _transition_workaround);
		~WlanProfiles() {};

		bool GetProfileData(PINTEL_PROFILE_DATA profileData, unsigned long* pProfileFlags,
			const authenticationSet_t& supportedAuthentication, const encriptionSet_t& supportedEncription, const crossauthSet_t& supportedCrossauth,
			bool add_map);
		bool GetProfiles(WlanOsProfileList &profiles, const authenticationSet_t &supportedAuthentication,
			const encriptionSet_t &supportedEncription, const crossauthSet_t& supportedCrossauth);
		void RefillProfilesWithID(WlanOsProfileList& profiles);

	private:
		WlanProfileNameMapper name_mapper;

		std::wstring xmlRead(const std::wstring &strXML, std::wstring strKey);
		std::wstring xmlReadWithNamespace(const std::wstring& strXML, std::wstring strKey);
		bool isLegalProfileName(const std::wstring &profileName);
		bool isSupportedEncription(const std::wstring &enc, const encriptionSet_t &supportedEnc);
		bool isSupportedAuthentication(const std::wstring &auth, const authenticationSet_t &supportedAuth);
		std::wstring checkSupportedTransitionAuthentication(const std::wstring& auth, const crossauthSet_t& supportedCrossauth);
	};
}
#endif //__WLAN_PRFOFILES_H_