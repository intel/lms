/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
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
		static bool transition_workaround;

		static bool trans2CIM(PINTEL_PROFILE_DATA profileData, SingleMeProfile & wifiSettings1, SingleMeProfile & wifiSettings2);
		static void CleanOsProfileList(WlanOsProfileList &wlanOsProfiles);
		static bool AddMissingProfilesToMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles);
		static bool FetchOsProfiles(WlanProfiles& osProfiles, WlanOsProfileList &wlanOsProfiles);
		static bool CleanupProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles, bool all);
		static bool EnumerateMeProfiles(WlanWSManClient &wsmanClient, MeProfileList &profiles);
		static unsigned int AddUpdateProfile(WlanWSManClient& wsmanClient, SingleMeProfile& wifiSettings, bool found);
		static std::string getName(PINTEL_PROFILE_DATA profileData, bool secondary);
	};
}

#endif // __WLAN_BL_H_
