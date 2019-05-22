/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018 Intel Corporation
 */
#ifndef __WLAN_BL_H_
#define __WLAN_BL_H_

#pragma once

#include "WlanProfiles.h"

#include "CIM_WiFiEndpointSettings.h"
#include <memory>
#include <locale>
#include <codecvt>
#include <string>
#include <map>
#include <mutex>

namespace wlanps{

	class WlanBL
	{
	private:
		WlanProfiles	                                                                            m_osProfiles;								// Operating System Profiles, in OS format
		PINTEL_PROFILE_DATA                                                                         m_wlanOsProfiles[MAX_OS_USER_PROFILES];		// Operating System Profiles, in Intel format
		int																							m_numOsUserProfiles;
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings>>    m_MeProfileList;							// ME db Profiles

		std::mutex      _updateMutex;
		std::wstring    _lastConnSSID = L"";
		long long       _lastConn = 0;


	public:
		~WlanBL();
		static WlanBL& getInstance();

		int Init(HANDLE hwlan);

		void SyncProfiles();

		void onConnectionComplete(PINTEL_PROFILE_DATA profileData);

	private:
		WlanBL();

		int trans2CIM(PINTEL_PROFILE_DATA profileData, Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings& wifiSettings);
		void PrintWifiSetting(int auth, int enc, int prio, wchar_t* elementName, wchar_t* ssid);

		void    CleanOsProfileList();
		int		AddMissingProfilesToMe();
		bool	FetchMeProfiles();
		int		FetchOsProfiles();
		void	PrintInternalMeProfiles();
		void	PrintInternalOsUserProfileList();
		int		CleanupProfilesInMe();
	};
}

#endif
