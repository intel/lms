/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2023 Intel Corporation
 */
#ifndef __WLAN_BL_H_
#define __WLAN_BL_H_

#include "WlanProfiles.h"
#include "WlanWSManClient.h"
#include <mutex>

namespace wlanps {

	class WlanBL
	{
	public:
		static void SyncProfiles(unsigned int portForwardingPort, HANDLE hwlan);
		static void onConnectionComplete(unsigned int portForwardingPort, HANDLE hwlan, PINTEL_PROFILE_DATA profileData);

	private:
		static std::mutex _updateMutex;

		static bool trans2CIM(PINTEL_PROFILE_DATA profileData, SingleMeProfile& wifiSettings);
		static void CleanOsProfileList(WlanOsProfileList &wlanOsProfiles);
		static bool AddMissingProfilesToMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles);
		static bool FetchOsProfiles(HANDLE hwlan, WlanOsProfileList &wlanOsProfiles);
		static bool CleanupProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles, bool all);
		static bool EnumerateMeProfiles(WlanWSManClient &wsmanClient, MeProfileList &profiles);
		static unsigned int AddUpdateProfile(WlanWSManClient& wsmanClient, SingleMeProfile& wifiSettings, bool found);
	};
}

#endif // __WLAN_BL_H_
