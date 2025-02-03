/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
#ifndef __WLAN_PRFOFILES_H_
#define __WLAN_PRFOFILES_H_

#include <wlanapi.h>
#include <winnt.h>
#include <memory>
#include <set>
#include <string>

namespace wlanps {

	typedef std::set<std::wstring> authenticationSet_t;
	typedef std::set<std::wstring> encriptionSet_t;

	class WlanProfiles
	{
	private:
		HANDLE m_hwlan;

	public:
		WlanProfiles(HANDLE hwlan);
		~WlanProfiles() {};

		bool GetProfileData(PINTEL_PROFILE_DATA profileData, unsigned long* pProfileFlags,
			const authenticationSet_t& supportedAuthentication, const encriptionSet_t& supportedEncription);
		bool GetProfiles(WlanOsProfileList &profiles, const authenticationSet_t &supportedAuthentication, const encriptionSet_t &supportedEncription);

	private:
		std::wstring xmlRead(const std::wstring &strXML, std::wstring strKey);
		bool isLegalProfileName(const std::wstring &profileName);
		bool isSupportedEncription(const std::wstring &enc, const encriptionSet_t &supportedEnc);
		bool isSupportedAuthentication(const std::wstring &auth, const authenticationSet_t &supportedAuth);
	};
}
#endif //__WLAN_PRFOFILES_H_