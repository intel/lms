/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2020 Intel Corporation
 */
#ifndef __WLAN_BL_H_
#define __WLAN_BL_H_

#include "WlanProfiles.h"
#include "WlanWSManClient.h"
#include <mutex>

namespace wlanps {

	class WlanBL
	{
	private:
		WlanProfiles	    m_osProfiles;								// Operating System Profiles, in OS format
		PINTEL_PROFILE_DATA m_wlanOsProfiles[MAX_OS_USER_PROFILES];		// Operating System Profiles, in Intel format
		int                 m_numOsUserProfiles;

		std::mutex      _updateMutex;

	public:
		~WlanBL();
		static WlanBL& getInstance();

		bool Init(HANDLE hwlan);

		void SyncProfiles();

		void onConnectionComplete(PINTEL_PROFILE_DATA profileData);

	private:
		WlanBL();

		bool trans2CIM(PINTEL_PROFILE_DATA profileData, SingleMeProfile& wifiSettings);
		void PrintWifiSetting(int auth, int enc, int prio, wchar_t* elementName, wchar_t* ssid);

		void    CleanOsProfileList();
		bool	AddMissingProfilesToMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList);
		bool	FetchOsProfiles();
		void	PrintInternalOsUserProfileList();
		bool	CleanupProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList);
		bool	UpdateProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList);

		bool EnumerateMeProfiles(WlanWSManClient &wsmanClient, MeProfileList &profiles);
	};
}

#endif // __WLAN_BL_H_
