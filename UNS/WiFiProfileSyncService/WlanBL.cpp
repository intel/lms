/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2020 Intel Corporation
 */
#include "global.h"
#include "WlanDefs.h"
#include "WlanBL.h"
#include "Tools.h"
#include <string>
#include <map>

namespace wlanps {
	const std::string IntelInstanceIDUser = "Intel(r) AMT:WiFi Endpoint User Settings ";
	typedef std::map<std::wstring, int> str_int_map_t;

	authenticationSet_t supportedAuthentication = { L"open", L"WPAPSK", L"WPA2PSK", L"WPA3SAE", L"OWE" };
	encriptionSet_t supportedEncription = { L"WEP", L"TKIP", L"AES", L"none" };

	std::mutex WlanBL::_updateMutex;

	void WlanBL::CleanOsProfileList(WlanOsProfileList& wlanOsProfiles)
	{
		for (auto iterator = wlanOsProfiles.begin(); iterator != wlanOsProfiles.end(); iterator++)
		{
			(*iterator)->FreeKeyMaterial();
		}
	}

	bool WlanBL::FetchOsProfiles(HANDLE hwlan, WlanOsProfileList &wlanOsProfiles)
	{
		WlanProfiles osProfiles(hwlan); // Operating System Profiles, in OS format
		bool ret = osProfiles.GetProfiles(wlanOsProfiles, supportedAuthentication, supportedEncription);
		if (ret)
		{
			PrintInternalOsUserProfileList(wlanOsProfiles);
		}
		return ret;
	}

	void WlanBL::PrintInternalOsUserProfileList(WlanOsProfileList &wlanOsProfiles)
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: ------- GetProfiles: - OS Profiles List Start (length [%02d]) ------\n",
			wlanOsProfiles.size());
		
		for (auto iterator = wlanOsProfiles.begin(); iterator != wlanOsProfiles.end(); iterator++)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Profile= %-25W SSID=  %-25W aut = %-10sW, enc= %W\n",
			 (*iterator)->profile, (*iterator)->SSID, (*iterator)->auth, (*iterator)->encr);
		}

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: ------- GetProfiles - OS Profiles List End (length [%02d]) ------\n",
			wlanOsProfiles.size());
	}

	bool WlanBL::EnumerateMeProfiles(WlanWSManClient &wsmanClient, MeProfileList &profiles)
	{
		if (!wsmanClient.Enumerate(profiles))
		{
			return false;
		}

		UNS_DEBUG(L"[ProfileSync] ME Profiles List Start ------\n");
		for (MeProfileList::iterator it = profiles.begin(); it != profiles.end();)
		{
			if ((*it)->InstanceID().compare(0, IntelInstanceIDUser.length(), IntelInstanceIDUser) != 0)
			{
				UNS_DEBUG(L"[ProfileSync] ME Profile  = '%C' - IT one, ignoring\n", (*it)->ElementName().c_str());
				it = profiles.erase(it);
			}
			else
			{
				UNS_DEBUG(L"[ProfileSync] ME Profile  = '%C'\n", (*it)->ElementName().c_str());
				++it;
			}
		}
		UNS_DEBUG(L"[ProfileSync] ME Profiles List End ------\n");
		return true;
	}

	void WlanBL::SyncProfiles(HANDLE hwlan)
	{
		std::lock_guard<std::mutex> lock(_updateMutex);

		bool wsmanStatus;
		MeProfileList MeProfileList;
		WlanWSManClient wsmanClient;

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Enumerating ME (CSME FW) Profiles, Wait for it...\n");
		if (!EnumerateMeProfiles(wsmanClient, MeProfileList))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Enumerate failed -> Stop sync operation\n");
			return;
		}

		WlanOsProfileList wlanOsProfiles;
		if (!FetchOsProfiles(hwlan, wlanOsProfiles))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Fetch OS Profiles failed -> Stop sync operation\n");
			return;
		}

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Delete Profiles which are not in the top16 user profiles\n");
		wsmanStatus = CleanupProfilesInMe(wsmanClient, MeProfileList, wlanOsProfiles);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: CleanupProfilesInMe completed %C\n", wsmanStatus == true ? "successfully" : "with failure");

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Add Missing profiles \n");
		wsmanStatus = AddMissingProfilesToMe(wsmanClient, MeProfileList, wlanOsProfiles);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: AddMissingProfilesToMe completed %C\n", wsmanStatus == true ? "successfully" : "with failure");

		CleanOsProfileList(wlanOsProfiles);
	}

	bool WlanBL::CleanupProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles)
	{
		bool bFoundMatch;
		bool status;

		try
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: numOsProfiles %d, numMEPRofiles %d\n", wlanOsProfiles.size(), MeProfileList.size());

			//---- Go over ME profile list in loop. Any profile that doesn't exist in the 1st 16 profiles from the OS - delete
			for (auto meIterator = MeProfileList.begin(); meIterator != MeProfileList.end(); meIterator++)
			{
				bFoundMatch = false;
				for (auto osIterator = wlanOsProfiles.begin(); osIterator != wlanOsProfiles.end(); osIterator++)
				{
					std::string currentOsProfile = WStringToString((*osIterator)->profile);

					if ((*meIterator)->ElementName().compare(currentOsProfile) == 0)
					{
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  Profile matching with one of top 16 OS User Profile\n",
							currentOsProfile.c_str());
						bFoundMatch = true;
						break;
					}
				}

				if (bFoundMatch == false)
				{
					//If I got here, it means I didn't find a match in the OS list for this profile
					std::string name = (*meIterator)->ElementName();
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  Profile is not at the top 16 - Deleting Profile From ME !\n",
						name.c_str());
					status = wsmanClient.DeleteProfile(**meIterator);
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  DeleteProfile completed %C\n",
						name.c_str(), status == true ? "successfully" : "with Exception");
				}
			}
		}
		catch (std::exception* e)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]:  Exception %C\n", e->what());
			return false;
		}

		return true;
	}

	bool WlanBL::AddMissingProfilesToMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles)
	{
		bool ret = true;

		try
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: numOsProfiles %d, numMEPRofiles %d\n", wlanOsProfiles.size(), MeProfileList.size());

			// Go over the top 16 profiles in the OS profile list. Any profile that doesn't exist in the ME list - Add it
			for (auto osIterator = wlanOsProfiles.begin(); osIterator != wlanOsProfiles.end(); osIterator++)
			{
				Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings wifiSettings = { 0 };
				if (!trans2CIM((*osIterator).get(), wifiSettings))
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25W trans2CIM failed -> Don't add this profile\n",
						(*osIterator)->profile);
					ret = false;
					continue;
				}

				std::string currentOsProfile = WStringToString((*osIterator)->profile);
				MeProfileList::iterator me_it = find_if(MeProfileList.begin(), MeProfileList.end(),
					[currentOsProfile](const std::shared_ptr<SingleMeProfile> &p) {return currentOsProfile == p->ElementName(); });
				if (me_it == MeProfileList.end())
				{
					//If I got here, it means I didn't find a match in the OS list for this profile
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C OS Profile has no match - Add Profile To ME !\n",
						currentOsProfile.c_str());
					unsigned int wsmanStatus = wsmanClient.AddProfile(wifiSettings);
					switch (wsmanStatus)
					{
					case WSMAN_AMT_ERROR_SUCCESS:
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C AddProfile completed\n",
							currentOsProfile.c_str());
						break;
					case WSMAN_AMT_UNSUPPORTED:
						UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C AddProfile rejected as unsupported by FW\n",
							currentOsProfile.c_str());
						break;
					default:
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C AddProfile failed ret = %u\n",
							currentOsProfile.c_str(), wsmanStatus);
						break;
					}
				}
				else
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C OS Profile has match - Update Profile To ME !\n",
						currentOsProfile.c_str());
					unsigned int wsmanStatus = wsmanClient.UpdateProfile(wifiSettings);
					switch (wsmanStatus)
					{
					case WSMAN_AMT_ERROR_SUCCESS:
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C UpdateProfile completed\n",
							currentOsProfile.c_str());
						break;
					case WSMAN_AMT_UNSUPPORTED:
						UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C UpdateProfile rejected as unsupported by FW\n",
							currentOsProfile.c_str());
						break;
					default:
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C UpdateProfile failed ret = %u\n",
							currentOsProfile.c_str(), wsmanStatus);
						break;
					}
				}
			}
		}
		catch (std::exception* e)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]:  Exception %C\n", e->what());
			return false;
		}

		return ret;
	}

	void WlanBL::onConnectionComplete(HANDLE hwlan, PINTEL_PROFILE_DATA profileData)
	{
		std::lock_guard<std::mutex> lock(_updateMutex);
		bool retVal;
		bool bFound = false;
		bool bFoundMatch = false;
		unsigned long profileFlags = 0;
		WlanWSManClient wsmanClient;
		MeProfileList MeProfileList;


		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Got connected to profile: [%W]\n", profileData->profile);

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Calling osProfiles.GetProfileData...\n");
		WlanProfiles osProfiles(hwlan); // Operating System Profiles, in OS format
		retVal = osProfiles.GetProfileData(profileData, &profileFlags);

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Calling osProfiles.GetProfileData returned %d\n", retVal);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Profile details: SSID = %W aut = %W, enc = %W profileFlags 0x%08X\n",
			profileData->SSID, profileData->auth, profileData->encr, profileFlags);

		if (!retVal)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": GetProfileData failed! Stop add Profile process\n");
			return;
		}

		// Check if this profile is an IT (Group Policy) profile
		if (profileFlags == WLAN_PROFILE_GROUP_POLICY)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": This is an IT Profile --> Do nothing\n");
			profileData->FreeKeyMaterial();
			return;
		}

		Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings wifiSettings;
		retVal = trans2CIM(profileData, wifiSettings);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": trans2CIM returned %d\n", retVal);
		
		profileData->FreeKeyMaterial();

		if (!retVal)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: trans2CIM failed -> Don't add this profile\n");
			return;
		}

		// Check if the connected Profile exists in ME Profile List
		try
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Getting ME Profiles list\n");

			// Get Profile list from ME
			bool wsmanStatus = EnumerateMeProfiles(wsmanClient, MeProfileList);
			if (!wsmanStatus)
			{
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Enumerate failed -> Stop operation\n");

				return;
			}
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.Enumerate completed\n");


			WlanOsProfileList wlanOsProfiles;
			FetchOsProfiles(hwlan, wlanOsProfiles);

			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Num of ME profiles %d Profiles - Num of OS Profiles %d\n",
				MeProfileList.size(), wlanOsProfiles.size());

			// Search the Profile in ME Profile list
			for (auto meIterator = MeProfileList.begin(); meIterator != MeProfileList.end(); meIterator++)
			{
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_MeProfileList->ElementName: [%C]\n",
					(*meIterator)->ElementName().c_str());

				if ((*meIterator)->ElementName().compare(wifiSettings.ElementName()) == 0)
				{
					bFound = true;
					break;
				}
			}

			if ((MAX_USER_PROFILES == MeProfileList.size()) && (bFound == false))
			{
				// FW DB is full, delete the appropriate user profile
				for (auto meIterator = MeProfileList.begin(); meIterator != MeProfileList.end(); meIterator++)
				{
					bFoundMatch = false;
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Going to search ME Profile %C in OS profile list...\n",
						(*meIterator)->ElementName().c_str());
					for (auto osIterator = wlanOsProfiles.begin(); osIterator != wlanOsProfiles.end(); osIterator++)
					{
						std::string currentOsProfile = WStringToString((*osIterator)->profile);

						if ((*meIterator)->ElementName().compare(currentOsProfile) == 0)
						{
							UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  Profile matching with one of top 16 OS User Profile\n",
								currentOsProfile.c_str());
							bFoundMatch = true;
							break;
						}
					}

					if (bFoundMatch == false)
					{
						std::string name = (*meIterator)->ElementName();
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  Profile is not at the top 16 - Deleting Profile From ME!\n",
							name.c_str());

						wsmanStatus = wsmanClient.DeleteProfile(**meIterator);

						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  DeleteProfile completed\n",
							name.c_str());
						break;
					}
				}
			}

			CleanOsProfileList(wlanOsProfiles);

			if (bFound == true)
			{
				// Profile exists in ME Profile list -> Update Profile
				unsigned int status = wsmanClient.UpdateProfile(wifiSettings);
				switch (status)
				{
				case WSMAN_AMT_ERROR_SUCCESS:
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%W] completed\n",
						profileData->profile);
					break;
				case WSMAN_AMT_UNSUPPORTED:
					UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%W] rejected as unsupported by FW\n",
						profileData->profile);
					break;
				default:
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%W] failed ret = %u\n",
						profileData->profile, status);
					break;
				}
			}
			else
			{
				// Profile not exists in ME Profile list -> Add Profile
				unsigned int status = wsmanClient.AddProfile(wifiSettings);
				switch (status)
				{
				case WSMAN_AMT_ERROR_SUCCESS:
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%W] completed\n",
						profileData->profile);
					break;
				case WSMAN_AMT_UNSUPPORTED:
					UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%W] rejected as unsupported by FW\n",
						profileData->profile);
					break;
				default:
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%W] failed ret = %u\n",
						profileData->profile, status);
					break;
				}
			}
		}
		catch (std::exception* e)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Exception %C\n", e->what());
			return;
		}
	}

	bool WlanBL::trans2CIM(PINTEL_PROFILE_DATA profileData, SingleMeProfile& wifiSettings)
	{
		static const unsigned short TKIPPriority = 4;
		static const unsigned short Priority802_11x_AES	= 6;
		static const unsigned short WEPPriority = 7;
		static const unsigned short NoneEncPriority = 8;

		int auth = 1;
		int encr = 1;
		int priority = 8;

		// translate to CIM_WiFiEndpointSettings
		static const str_int_map_t authMap = {
			{ L"open",    AuthenticationMethodOpenSystem },
			{ L"WPAPSK",  AuthenticationMethodWPAPSK },
			{ L"WPA2PSK", AuthenticationMethodWPA2PSK },
			{ L"WPA3SAE", AuthenticationMethodWPA3SAE },
			{ L"OWE", AuthenticationMethodWPA3OWE }
		};
		static const str_int_map_t encrMap = {
			{ L"WEP",  EncryptionMethodWEP },
			{ L"TKIP", EncryptionMethodTKIP },
			{ L"AES",  EncryptionMethodCCMP }, // CCMP
			{ L"none", EncryptionMethodNone }
		};

		static const str_int_map_t priorityMap = {
			{ L"WEP",  WEPPriority },
			{ L"TKIP", TKIPPriority },
			{ L"AES",  Priority802_11x_AES }, // CCMP
			{ L"none", NoneEncPriority }
		};

		wifiSettings.ElementName(WStringToString(profileData->profile));
		wifiSettings.SSID(WStringToString(profileData->SSID));

		try
		{
			auth = authMap.at(profileData->auth);
			encr = encrMap.at(profileData->encr);
			priority = priorityMap.at(profileData->encr);
		}
		catch (...)
		{
			UNS_ERROR(L"[ProfileSync] Fix the auth or encr map\n");
			return false;
		}

		wifiSettings.Priority(priority);
		wifiSettings.AuthenticationMethod(auth);
		wifiSettings.EncryptionMethod(encr);

		// PSKPassPhrase should be NULL if AuthenticationMethod does not contain
		// 4 ("WPA PSK") or 6 ("WPA2 PSK") or 32768 ("WPA3 SAE").
		if ((auth == AuthenticationMethodWPAPSK || auth == AuthenticationMethodWPA2PSK || auth == AuthenticationMethodWPA3SAE) &&
			encr != EncryptionMethodNone)
		{
			wifiSettings.PSKPassPhrase(WStringToString(profileData->keyMaterial));
		}

		PrintWifiSetting(auth, encr, priority, profileData->profile, profileData->SSID);

		return true;
	}

	void WlanBL::PrintWifiSetting(int auth, int enc, int prio, wchar_t* elementName, wchar_t* ssid)
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: wifiSettings Profile=%-25W, ssid=%-25W prio=%d auth=%d enc=%d\n",
			elementName, ssid, prio, auth, enc);
	}
} // namespace wlanps