/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
#include "global.h"
#include "WlanDefs.h"
#include "WlanBL.h"
#include "Tools.h"
#include "GmsService.h"
#include <string>
#include <map>
#include <ace/ace_wchar.h>

namespace wlanps {
	const std::string IntelInstanceIDUser = "Intel(r) AMT:WiFi Endpoint User Settings ";

	authenticationSet_t supportedAuthentication = { L"open", L"WPAPSK", L"WPA2PSK", L"WPA3SAE", L"OWE" };
	encriptionSet_t supportedEncription = { L"WEP", L"TKIP", L"AES", L"none" };
	crossauthSet_t crossauthSet = { {L"WPA3SAE", L"WPA2PSK"} };

	std::mutex WlanBL::_updateMutex;
	bool WlanBL::transition_workaround = true;

	void WlanBL::CleanOsProfileList(WlanOsProfileList& wlanOsProfiles)
	{
		for (auto iterator = wlanOsProfiles.begin(); iterator != wlanOsProfiles.end(); iterator++)
		{
			(*iterator)->FreeKeyMaterial();
		}
	}

	bool WlanBL::FetchOsProfiles(WlanProfiles &osProfiles, WlanOsProfileList &wlanOsProfiles)
	{
		bool ret = osProfiles.GetProfiles(wlanOsProfiles, supportedAuthentication, supportedEncription, crossauthSet);
		if (ret)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: ------- GetProfiles: - OS Profiles List Start (length [%02d]) ------\n",
				wlanOsProfiles.size());

			for (auto iterator = wlanOsProfiles.begin(); iterator != wlanOsProfiles.end(); iterator++)
			{
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Profile= %-25W SSID=  %-25W aut = %-10W/%-10W, enc= %W\n",
					(*iterator)->profile, (*iterator)->SSID, (*iterator)->auth, (*iterator)->auth2, (*iterator)->encr);
			}

			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: ------- GetProfiles - OS Profiles List End (length [%02d]) ------\n",
				wlanOsProfiles.size());
		}
		return ret;
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

	void WlanBL::SyncProfiles(unsigned int portForwardingPort, HANDLE hwlan)
	{
		std::lock_guard<std::mutex> lock(_updateMutex);

		bool wsmanStatus;
		MeProfileList MeProfileList;
		WlanWSManClient wsmanClient(portForwardingPort);

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Enumerating ME (CSME FW) Profiles, Wait for it...\n");
		if (!EnumerateMeProfiles(wsmanClient, MeProfileList))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Enumerate failed -> Stop sync operation\n");
			return;
		}

		WlanOsProfileList wlanOsProfiles;
		WlanProfiles osProfiles(hwlan, transition_workaround); // Operating System Profiles, in OS format
		if (!FetchOsProfiles(osProfiles, wlanOsProfiles))
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Fetch OS Profiles failed -> Stop sync operation\n");
			return;
		}

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Delete Profiles which are not in the top16 user profiles\n");
		wsmanStatus = CleanupProfilesInMe(wsmanClient, MeProfileList, wlanOsProfiles, true);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: CleanupProfilesInMe completed %C\n", wsmanStatus == true ? "successfully" : "with failure");

		if (transition_workaround)
		{
			osProfiles.RefillProfilesWithID(wlanOsProfiles);
		}

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Add Missing profiles \n");
		wsmanStatus = AddMissingProfilesToMe(wsmanClient, MeProfileList, wlanOsProfiles);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: AddMissingProfilesToMe completed %C\n", wsmanStatus == true ? "successfully" : "with failure");

		CleanOsProfileList(wlanOsProfiles);
	}

	bool WlanBL::CleanupProfilesInMe(WlanWSManClient &wsmanClient, MeProfileList &MeProfileList, WlanOsProfileList &wlanOsProfiles, bool all)
	{
		bool bFoundMatch;
		bool status;

		try
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: numOsProfiles %d, numMEPRofiles %d\n", wlanOsProfiles.size(), MeProfileList.size());

			//---- Go over ME profile list in loop. Any profile that doesn't exist in the 1st 16 profiles from the OS - delete
			for (auto meIterator = MeProfileList.begin(); meIterator != MeProfileList.end(); )
			{
				bFoundMatch = false;
				for (auto osIterator = wlanOsProfiles.begin(); osIterator != wlanOsProfiles.end(); osIterator++)
				{
					std::string currentOsProfile1(getName((*osIterator).get(), false));
					std::string currentOsProfile2(getName((*osIterator).get(), true));

					if ((!currentOsProfile1.empty() && (*meIterator)->ElementName().compare(currentOsProfile1) == 0) ||
						(!currentOsProfile2.empty() && (*meIterator)->ElementName().compare(currentOsProfile2) == 0))
					{
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25C  Profile matching with one of top 16 OS User Profile\n",
							(*meIterator)->ElementName().c_str());
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

					meIterator = MeProfileList.erase(meIterator);
					if (!all) // exit after one slot is freed
					{
						break;
					}
				}
				else
				{
					meIterator++;
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
				Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings wifiSettings[2] = {0};
				if (!trans2CIM((*osIterator).get(), wifiSettings[0], wifiSettings[1]))
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %-25W trans2CIM failed -> Don't add this profile\n",
						(*osIterator)->profile);
					ret = false;
					continue;
				}

				for (size_t i = 0; i < 2; i++)
				{
					std::string currentOsProfile(wifiSettings[i].ElementName());
					if (currentOsProfile.empty())
						continue;
					MeProfileList::iterator me_it = find_if(MeProfileList.begin(), MeProfileList.end(),
						[&currentOsProfile](const std::shared_ptr<SingleMeProfile>& p) { return currentOsProfile == p->ElementName(); });

					AddUpdateProfile(wsmanClient, wifiSettings[i], (me_it != MeProfileList.end()));
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

	void WlanBL::onConnectionComplete(unsigned int portForwardingPort, HANDLE hwlan, PINTEL_PROFILE_DATA profileData)
	{
		std::lock_guard<std::mutex> lock(_updateMutex);
		bool retVal;
		bool bFound = false;
		unsigned long profileFlags = 0;
		WlanWSManClient wsmanClient(portForwardingPort);
		MeProfileList MeProfileList;


		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Got connected to profile: [%W]\n", profileData->profile);

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Calling osProfiles.GetProfileData...\n");
		WlanProfiles osProfiles(hwlan, transition_workaround); // Operating System Profiles, in OS format
		retVal = osProfiles.GetProfileData(profileData, &profileFlags, supportedAuthentication, supportedEncription, crossauthSet, true);

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Calling osProfiles.GetProfileData returned %d\n", retVal);
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Profile details: SSID = %W aut = %W, enc = %W profileFlags 0x%08X\n",
			profileData->SSID, profileData->auth, profileData->encr, profileFlags);

		if (!retVal)
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": GetProfileData failed! Stop add Profile process\n");
			return;
		}

		Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings wifiSettings[2] = { 0 };
		retVal = trans2CIM(profileData, wifiSettings[0], wifiSettings[1]);
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
			WlanOsProfileList wlanOsProfiles;
			FetchOsProfiles(osProfiles, wlanOsProfiles);

			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Num of ME profiles %d Profiles - Num of OS Profiles %d\n",
				MeProfileList.size(), wlanOsProfiles.size());

			for (unsigned int i = 0; i < 2; i++)
			{
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Getting ME Profiles list\n");
				// Get Profile list from ME
				bool wsmanStatus = EnumerateMeProfiles(wsmanClient, MeProfileList);
				if (!wsmanStatus)
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": Enumerate failed -> Stop operation\n");
					break;
				}
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.Enumerate completed\n");

				// Search the Profile in ME Profile list
				std::string currentOsProfile(wifiSettings[i].ElementName());
				if (currentOsProfile.empty())
					continue;
				MeProfileList::iterator me_it = find_if(MeProfileList.begin(), MeProfileList.end(),
					[&currentOsProfile](const std::shared_ptr<SingleMeProfile>& p) { return currentOsProfile == p->ElementName(); });

				if ((MAX_USER_PROFILES == MeProfileList.size()) && (me_it == MeProfileList.end()))
				{
					// FW DB is full, delete the appropriate user profile
					CleanupProfilesInMe(wsmanClient, MeProfileList, wlanOsProfiles, false);
				}

				AddUpdateProfile(wsmanClient, wifiSettings[i], (me_it != MeProfileList.end()));
			}

			CleanOsProfileList(wlanOsProfiles);
		}
		catch (std::exception* e)
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Exception %C\n", e->what());
			return;
		}
	}

	bool WlanBL::trans2CIM(PINTEL_PROFILE_DATA profileData, SingleMeProfile& wifiSettings1, SingleMeProfile& wifiSettings2 )
	{
		static const unsigned short TKIPPriority = 4;
		static const unsigned short Priority802_11x_AES	= 6;
		static const unsigned short WEPPriority = 7;
		static const unsigned short NoneEncPriority = 8;

		unsigned short auth = AuthenticationMethodOther;
		unsigned short auth2 = AuthenticationMethodOther;
		unsigned short encr = EncryptionMethodOther;
		int priority = NoneEncPriority;

		// translate to CIM_WiFiEndpointSettings
		static const std::map<std::wstring, unsigned short> authMap = {
			{ L"open",    AuthenticationMethodOpenSystem },
			{ L"WPAPSK",  AuthenticationMethodWPAPSK },
			{ L"WPA2PSK", AuthenticationMethodWPA2PSK },
			{ L"WPA3SAE", AuthenticationMethodWPA3SAE },
			{ L"OWE",     AuthenticationMethodWPA3OWE }
		};
		static const std::map<std::wstring, unsigned short> encrMap = {
			{ L"WEP",  EncryptionMethodWEP },
			{ L"TKIP", EncryptionMethodTKIP },
			{ L"AES",  EncryptionMethodCCMP }, // CCMP
			{ L"none", EncryptionMethodNone }
		};

		static const std::map<std::wstring, int> priorityMap = {
			{ L"WEP",  WEPPriority },
			{ L"TKIP", TKIPPriority },
			{ L"AES",  Priority802_11x_AES }, // CCMP
			{ L"none", NoneEncPriority }
		};

		wifiSettings1.ElementName(getName(profileData, false));
		wifiSettings2.ElementName(getName(profileData, true));
		wifiSettings1.SSID(ACE_Wide_To_Ascii(profileData->SSID).char_rep());
		wifiSettings2.SSID(ACE_Wide_To_Ascii(profileData->SSID).char_rep());

		try
		{
			auth = authMap.at(profileData->auth);
			auth2 = authMap.at(profileData->auth2);
			encr = encrMap.at(profileData->encr);
			priority = priorityMap.at(profileData->encr);
		}
		catch (...)
		{
			UNS_ERROR(L"[ProfileSync] Fix the auth or encr map\n");
			return false;
		}

		wifiSettings1.Priority(priority);
		wifiSettings2.Priority(priority);
		wifiSettings1.AuthenticationMethod(auth);
		wifiSettings2.AuthenticationMethod(auth2);
		wifiSettings1.EncryptionMethod(encr);
		wifiSettings2.EncryptionMethod(encr);

		// PSKPassPhrase should be NULL if AuthenticationMethod does not contain
		// 4 ("WPA PSK") or 6 ("WPA2 PSK") or 32768 ("WPA3 SAE").
		if ((auth == AuthenticationMethodWPAPSK || auth == AuthenticationMethodWPA2PSK || auth == AuthenticationMethodWPA3SAE) &&
			encr != EncryptionMethodNone)
		{
			wifiSettings1.PSKPassPhrase(ACE_Wide_To_Ascii(profileData->keyMaterial).char_rep());
		}
		if ((auth2 == AuthenticationMethodWPAPSK || auth2 == AuthenticationMethodWPA2PSK || auth2 == AuthenticationMethodWPA3SAE) &&
			encr != EncryptionMethodNone)
		{
			wifiSettings2.PSKPassPhrase(ACE_Wide_To_Ascii(profileData->keyMaterial).char_rep());
		}

		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: wifiSettings Profile=%-25W, ssid=%-25W prio=%d auth=%d/%d enc=%d\n",
			profileData->profile, profileData->SSID, priority, auth, auth2, encr);

		return true;
	}

	unsigned int WlanBL::AddUpdateProfile(WlanWSManClient& wsmanClient, SingleMeProfile& wifiSettings, bool found)
	{
		unsigned int status;

		if (found == true)
		{
			// Profile exists in ME Profile list -> Update Profile
			status = wsmanClient.UpdateProfile(wifiSettings);
			switch (status)
			{
			case WSMAN_AMT_ERROR_SUCCESS:
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%C] completed\n",
					wifiSettings.ElementName().c_str());
				break;
			case WSMAN_AMT_UNSUPPORTED:
				UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%C] rejected as unsupported by FW\n",
					wifiSettings.ElementName().c_str());
				break;
			default:
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.UpdateProfile [%C] failed ret = %u\n",
					wifiSettings.ElementName().c_str(), status);
				break;
			}
		}
		else
		{
			// Profile not exists in ME Profile list -> Add Profile
			status = wsmanClient.AddProfile(wifiSettings);
			switch (status)
			{
			case WSMAN_AMT_ERROR_SUCCESS:
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%C] completed\n",
					wifiSettings.ElementName().c_str());
				break;
			case WSMAN_AMT_UNSUPPORTED:
				UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%C] rejected as unsupported by FW\n",
					wifiSettings.ElementName().c_str());
				break;
			default:
				UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: m_wsmanClient.AddProfile [%C] failed ret = %u\n",
					wifiSettings.ElementName().c_str(), status);
				break;
			}
		}
		return status;
	}

	std::string WlanBL::getName(PINTEL_PROFILE_DATA profileData, bool secondary)
	{
		if (!transition_workaround)
		{
			return (secondary) ? std::string() : ACE_Wide_To_Ascii(profileData->profile).char_rep();
		}

		std::stringstream str;

		if (secondary ? profileData->profileID2 == 0 : profileData->profileID1 == 0)
			return std::string();
		str << "INTEL_SYNC_" << secondary ? profileData->profileID2 : profileData->profileID1;
		return str.str();
	}
} // namespace wlanps
