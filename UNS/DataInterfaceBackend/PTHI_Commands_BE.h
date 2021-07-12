/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: PTHI_Commands_BE.cpp

--*/

#include "DataInterfaceBackend.h"
#include <string>
#include <vector>


namespace Intel {
	namespace LMS {
		class PTHI_Commands_BE : Common_BE
		{
		public:
			PTHI_Commands_BE(bool isPfwup);

			LMS_ERROR GetAMTVersion(std::string &sAMTVersion);
#ifdef WIN32
			LMS_ERROR GetHeciVersion(std::string &sVersion);
#endif // WIN32
			LMS_ERROR GetLMSVersion(std::string &sVersion);

			LMS_ERROR GetProvisioningState(uint32_t &pProvisioningState);
			LMS_ERROR GetNetworkConnectionStatus(uint32_t &pStatus, uint32_t &pConnectionType, uint32_t &pConnectionTrigger);
			LMS_ERROR GetUserInitiatedEnabled(short &pStatus);
			LMS_ERROR GetPowerPolicy(std::string &bstrPolicy);
			LMS_ERROR GetLastResetReason(short &pReason);
			LMS_ERROR GetRedirectionStatus(uint32_t &pSOL, uint32_t &pIDER);
			LMS_ERROR GetSystemDefenseStatus(uint32_t &pStatus);
			LMS_ERROR GetNetworkSettings(short ConnectionType /*WIRED, WIRELESS*/,
				uint32_t &pDhcpEnabled,// Both
				std::string &strIpAddress,//Both
				std::string &bstrMacAddress,//Both
				short &pLinkStatus, //Both
				short &pWirelessControl,// WIRELESS
				short &pWirelessConfEnabled); //WIRELESS
			LMS_ERROR GetIPv6NetworkSettings(short ConnectionType /*WIRED, WIRELESS*/,
				std::string &IPv6DefaultRouter,
				std::string &PrimaryDNS,
				std::string &SecondaryDNS,
				std::vector<std::string> &pResponse,
				bool &pIpv6Enable);
			LMS_ERROR GetSystemUUID(std::string &bstrUUID);
			LMS_ERROR CloseUserInitiatedConnection(void);
			LMS_ERROR GetKVMRedirectionState(bool &pEnabled, bool &pConnected);
			LMS_ERROR SetSpriteLanguage(unsigned short Language);
			LMS_ERROR GetSpriteParameters(unsigned short &pLanguage, unsigned short &pZoom);
			LMS_ERROR SetSpriteZoom(unsigned short Zoom);
			LMS_ERROR GetConfigurationInfo(short &pControlMode, short &pProvisioningMethod,
				std::string &pCreationTimeStamp, std::vector<unsigned char> &ppCertHash);
			LMS_ERROR TerminateRemedySessions(void);
			LMS_ERROR GetUserConsentState(short &pState, USER_CONSENT_POLICY &pPolicy);
			LMS_ERROR GetWLANLinkInfo(unsigned int &pPreference, unsigned int &pControl, unsigned int &pProtection);
			LMS_ERROR SetLinkPreferenceToHost(void);
			LMS_ERROR InitiateUserConnection(short &pStatus);
			LMS_ERROR userInitiatedPolicyRuleExists(short &pStatus);
			LMS_ERROR userInitiatedPolicyRuleForLocalMpsExists(short &pStatus);
			LMS_ERROR snmpEventSubscriberExists(short &pExist);
			LMS_ERROR CILAFilterCollectionSubscriptionExists(short &pExist);
			LMS_ERROR UpdateScreenSettings2(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, unsigned short numOfDisplays);
			LMS_ERROR GetRedirectionSessionLinkTechnology(REDIRECTION_SESSION_TYPE sessionType, short &pLinkTechnology);
			LMS_ERROR GetPlatformServiceRecord(std::string& strPSR);
		};
	}
}
