/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: PTHI_Commands_BE.cpp

--*/
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>
#include "global.h"
#include "GmsService.h"
#include "SIOWSManClient.h"
#include "HBPWSManClient.h"
#include "KVMWSManClient.h"
#include "CancelOptInClient.h"
#include "AMTRedirectionServiceWSManClient.h"
#include "AMTFCFHWSmanClient.h"
#include "AMTEthernetPortSettingsClient.h"
#include "GetRemoteAccessConnectionStatusCommand.h"
#include "OpenUserInitiatedConnectionCommand.h"
#include "CloseUserInitiatedConnectionCommand.h"
#include "GetSystemDefenseStateCommand.h"
#include "MEIClientException.h"
#include "HECIException.h"
#include "AMTHIErrorException.h"
#include "GetIPv6LanInterfaceStatusCommand.h"
#include "GetUUIDCommand.h"
#include "GetUserInitiatedEnabledInterfacesCommand.h"
#include "GetCodeVersionCommand.h"
#include "GetCurrentPowerPolicyCommand.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "GetProvisioningStateCommand.h"
#include "GetRedirectionSessionsStateCommand.h"
#include "GetAMTStateCommand.h"
#include "KVMScreenSettingClient.h"
#include "Tools.h"
#include "EventManagment.h"
#include "DataStorageGenerator.h"
#include "IPSKVMSessionUsingPortClient.h"
#include "IPSSOLSessionUsingPortClient.h"
#include "IPSIderSessionUsingPortClient.h"
#include "PTHI_Commands_BE.h"
#include "version.h"
#include "servicesNames.h"

namespace Intel {
	namespace LMS {

#define CATCH_HECIException(func) \
	catch (Intel::MEI_Client::HECIException& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(func L" HECIException failed %C\n", reason); \
	}

#define CATCH_MEIClientException(func) \
	catch (Intel::MEI_Client::MEIClientException& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(func L" failed %C\n", reason); \
	}

#define CATCH_AMTHIErrorException(func) \
	catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	}

#define CATCH_exception(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(L"Exception in " func L" %C\n", reason); \
	}

template<typename T, size_t SIZE>
constexpr size_t array_size(const T (&)[SIZE]) { return SIZE; }

		const short DEFAULT_LANG_ID = 100;

		std::string uuidToString(const uint8_t uuid[])
		{
			const unsigned int guid_index[16] = {3, 2, 1, 0, 5, 4, 7, 6, 8, 9, 10, 11, 12, 13, 14, 15};
			std::stringstream uuidStr;

			for (unsigned int i = 0; i < 16; ++i)
			{
				uuidStr << std::setfill('0') << std::setw(2) << std::hex << (int)uuid[guid_index[i]];
				if ((i == 3) || (i == 5) || (i == 7) || (i == 9))
				{
					uuidStr << "-";
				}
			}
			return uuidStr.str();
		}

		PTHI_Commands_BE::PTHI_Commands_BE(bool isPfwUp) : Common_BE(isPfwUp)
		{
		}

		LMS_ERROR GetStringAMTVersion(std::string &AMTVersion)
		{
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetCodeVersionCommand getCodeVersionCommand;
				Intel::MEI_Client::AMTHI_Client::CODE_VERSIONS codeVersions = getCodeVersionCommand.getResponse();
				//get the AMT version from the code version array
				for (unsigned int i = 0; i < codeVersions.Versions.size(); i++)
				{
					if (!codeVersions.Versions[i].Description.compare("AMT"))
					{
						AMTVersion = codeVersions.Versions[i].Version;
						break;
					}
				}
				for (unsigned int i = 0; i < codeVersions.Versions.size(); ++i)
				{
					if (!codeVersions.Versions[i].Description.compare("Build Number"))
					{
						AMTVersion.append(".");
						AMTVersion.append(codeVersions.Versions[i].Version);
						break;
					}
				}
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetCodeVersionCommand")
			CATCH_MEIClientException(L"GetCodeVersionCommand")
			CATCH_exception(L"GetCodeVersionCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetAMTVersion(std::string &sAMTVersion)
		{
			return GetStringAMTVersion(sAMTVersion);
		}

#ifdef WIN32
		LMS_ERROR GetServiceVersion(const std::wstring &ServiceName, std::string &sVersion)
		{
			HKEY hKey;
			wchar_t path[MAX_PATH + 1];//BUFSIZE
			wchar_t expandedPath[MAX_PATH + 1];
			DWORD pathBufSize = MAX_PATH;//BUFSIZE
			LONG RetValue;
			DWORD dwHandle = 0;
			DWORD bufCount = MAX_PATH;

			BYTE* FileValues = NULL;
			DWORD FileSize;
			std::wstring ServiceKey(L"SYSTEM\\CurrentControlSet\\Services\\");
			ServiceKey += ServiceName;
			RetValue = RegOpenKeyEx(HKEY_LOCAL_MACHINE, ServiceKey.c_str(), 0, KEY_QUERY_VALUE, &hKey);

			if (RetValue != ERROR_OK)
			{
				UNS_DEBUG(L"GetServiceVersion:RegOpenKeyEx failed err=%d\n", RetValue);
				return ERROR_FAIL;
			}
			RetValue = RegQueryValueEx(hKey, L"ImagePath", NULL, NULL, (LPBYTE)path, &pathBufSize);
			if ((RetValue != ERROR_OK) || (pathBufSize > MAX_PATH))
			{
				UNS_DEBUG(L"GetServiceVersion:RegQueryValueEx failed err=%d\n", RetValue);
				RegCloseKey(hKey);
				return ERROR_FAIL;
			}
			/* Even if the function returns ERROR_SUCCESS,
			 * the application should ensure that the string is properly terminated before using it.
			 */
			path[pathBufSize] = '\0';

			RegCloseKey(hKey);

			bufCount = ExpandEnvironmentStrings(path, expandedPath, sizeof(expandedPath));
			if (bufCount > MAX_PATH)
			{
				UNS_DEBUG(L"ExpandEnvironmentStrings: Too small buffer for expanding %W\n", path);
				return ERROR_FAIL;
			}
			else if (bufCount == 0)
			{
				UNS_DEBUG(L"ExpandEnvironmentStrings failed.\n");
				return ERROR_FAIL;
			}

			wchar_t* formattedPath, *EndPath;
			if (expandedPath[0] == '"')
			{
				formattedPath = &expandedPath[1];
				EndPath = wcschr(formattedPath, '"');
				if (EndPath != NULL)
					*EndPath = 0;
			}
			else
			{
				formattedPath = &expandedPath[0];
			}

			FileSize = GetFileVersionInfoSize((LPTSTR)formattedPath, &dwHandle);
			if (FileSize == 0)
			{
				UNS_DEBUG(L"GetServiceVersion:GetFileVersionInfoSize failed err=%d\n", GetLastError());
				return ERROR_FAIL;
			}

			FileValues = new BYTE[FileSize];
			if (GetFileVersionInfo((LPTSTR)formattedPath, NULL, FileSize, FileValues) == 0)
			{
				delete[] FileValues;
				UNS_DEBUG(L"GetServiceVersion:GetFileVersionInfoSize failed err=%d\n", GetLastError());
				return ERROR_FAIL;
			}

			VS_FIXEDFILEINFO *fileQuerInfo;
			UINT InfoSize = 0;
			if (!VerQueryValue(FileValues, TEXT("\\"), (LPVOID*)&fileQuerInfo, &InfoSize) ||
				!InfoSize || InfoSize < sizeof(VS_FIXEDFILEINFO)) 
			{
				delete[] FileValues;
				UNS_DEBUG(L"GetServiceVersion:VerQueryValue failed err=%d\n", GetLastError());
				return ERROR_FAIL;
			}
			std::stringstream ss;
			ss << HIWORD(fileQuerInfo->dwProductVersionMS) << "."
			   << LOWORD(fileQuerInfo->dwProductVersionMS) << "."
			   << HIWORD(fileQuerInfo->dwProductVersionLS) << "."
			   << LOWORD(fileQuerInfo->dwProductVersionLS);
			sVersion = ss.str();

			delete[] FileValues;

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetHeciVersion(std::string &sVersion)
		{
			teeDriverVersion_t HeciVersion;

			try
			{
				Intel::MEI_Client::GetHeciDriverVersion(&HeciVersion);
				std::stringstream ss;
				ss << HeciVersion.major << "."
				   << HeciVersion.minor << "."
				   << HeciVersion.hotfix << "." 
				   << HeciVersion.build;

				sVersion = ss.str();
				return ERROR_OK;
			}
			CATCH_HECIException(L"GetHeciVersion")
			CATCH_AMTHIErrorException(L"GetHeciVersion")
			CATCH_MEIClientException(L"GetHeciVersion")
			CATCH_exception(L"GetHeciVersion")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetLMSVersion(std::string &sVersion)
		{
			return GetServiceVersion(L"LMS", sVersion);
		}

#else
		LMS_ERROR PTHI_Commands_BE::GetLMSVersion(std::string &sVersion)
		{
			std::stringstream str;
			str << MAJOR_VERSION << "." << MINOR_VERSION << "." <<
				QUICK_FIX_NUMBER << "." << VER_BUILD;
			sVersion = str.str();
			return ERROR_OK;
		}
#endif // WIN32

		LMS_ERROR PTHI_Commands_BE::GetProvisioningState(uint32_t &pProvisioningState)
		{
			/*
			AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
			*/

			try
			{
				Intel::MEI_Client::AMTHI_Client::GetProvisioningStateCommand getProvisioningStateCommand;
				pProvisioningState = getProvisioningStateCommand.getResponse().ProvisioningState;
				UNS_DEBUG(L"ProvisioningState=%d\n", pProvisioningState);
				return ERROR_OK;
			}
			catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
			{
				unsigned int errNo = e.getErr();
				if (errNo == AMT_STATUS_NOT_READY)
				{
					pProvisioningState = 4; // CCK enrolled (registration to CCK) - Dan:: need to align IMSS to the new definition - no more CCK
					UNS_DEBUG(L"GetProvisioningStateCommand failed, but returned status=%d assume CCK enrolled let ProvisioningState=4\n", errNo);
					return ERROR_OK;
				}
				else
				{
					UNS_DEBUG(L"GetProvisioningStateCommand failed ret=%d\n", errNo);
				}
			}
			CATCH_MEIClientException(L"GetProvisioningStateCommand")
			CATCH_exception(L"GetProvisioningStateCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetNetworkConnectionStatus(uint32_t &pStatus, uint32_t &pConnectionType, uint32_t &pConnectionTrigger)
		{
			try {
				Intel::MEI_Client::AMTHI_Client::GetRemoteAccessConnectionStatusCommand getRemoteAccessConnectionStatus;
				Intel::MEI_Client::AMTHI_Client::REMOTE_ACCESS_STATUS Status = getRemoteAccessConnectionStatus.getResponse();
				pStatus = Status.RemoteAccessConnectionStatus;
				pConnectionType = Status.AmtNetworkConnectionStatus;
				pConnectionTrigger = Status.RemoteAccessConnectionTrigger;
				UNS_DEBUG(L"RemoteAccessConnectionStatus=%d\t AmtNetworkConnectionStatus=%d\n", pStatus, pConnectionType);
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetRemoteAccessConnectionStatus")
			CATCH_MEIClientException(L"GetRemoteAccessConnectionStatus")
			CATCH_exception(L"GetRemoteAccessConnectionStatus")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetUserInitiatedEnabled(short &pStatus)
		{
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetUserInitiatedEnabledInterfacesCommand getUserInitiatedEnabledInterfacesCommand;
				pStatus = getUserInitiatedEnabledInterfacesCommand.getResponse().EnabledInterfaces.OS_Agent;
				UNS_DEBUG(L"GetUserInitiatedEnabled enabled=%d\n", pStatus);
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetUserInitiatedEnabledInterfacesCommand")
			CATCH_MEIClientException(L"GetUserInitiatedEnabledInterfacesCommand")
			CATCH_exception(L"GetUserInitiatedEnabledInterfacesCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetPowerPolicy(std::string &bstrPolicy)
		{
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetCurrentPowerPolicyCommand getCurrentPowerPolicyCommand;
				UNS_DEBUG(L"powerPolicyName=%C\n", getCurrentPowerPolicyCommand.getResponse().c_str());
				bstrPolicy = getCurrentPowerPolicyCommand.getResponse().c_str();
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetCurrentPowerPolicyCommand")
			CATCH_MEIClientException(L"GetCurrentPowerPolicyCommand")
			CATCH_exception(L"GetCurrentPowerPolicyCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetLastResetReason(short &pReason)
		{
			// Need to check if the values fit to: ME_LAST_RESET_REASON ==> POWER_UP = 0,FW_RESET = 1,GLOBAL_SYSTEM_RESET = 2,REASON_UNKOWN = 3
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetAMTStateCommand getAMTStateCommand;
				pReason = getAMTStateCommand.getResponse().StateData.Fields.LastMEResetType;
				UNS_DEBUG(L"LastResetReason=%d\n", pReason);
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetAMTStateCommand")
			CATCH_MEIClientException(L"GetAMTStateCommand")
			CATCH_exception(L"GetAMTStateCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetRedirectionStatus(uint32_t &pSOL, uint32_t &pIDER)
		{
			/*
			AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
			*/
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetRedirectionSessionsStateCommand getRedirectionState;
				pSOL = getRedirectionState.getResponse().SolOpen;
				pIDER = getRedirectionState.getResponse().IderOpen;
				UNS_DEBUG(L"SOL=%d \t IDER=%d\n", pSOL, pIDER);
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetRedirectionSessionsStateCommand")
			CATCH_MEIClientException(L"GetRedirectionSessionsStateCommand")
			CATCH_exception(L"GetRedirectionSessionsStateCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetSystemDefenseStatus(uint32_t &pStatus)
		{
			/*
			AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
			*/
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetSystemDefenseStateCommand getSystemDefenseState;
				pStatus = getSystemDefenseState.getResponse().SystemDefenseActivated;
				UNS_DEBUG(L"systemDefense=%d \n", pStatus);
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetSystemDefenseStatus")
			CATCH_MEIClientException(L"GetSystemDefenseStatus")
			CATCH_exception(L"GetSystemDefenseStatus")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetNetworkSettings(short ConnectionType /*WIRED, WIRELESS*/,
													   uint32_t &pDhcpEnabled,// Both
													   std::string &strIpAddress,//Both
													   std::string &bstrMacAddress,//Both
													   short &pLinkStatus, //Both
													   short &pWirelessControl,// WIRELESS
													   short &pWirelessConfEnabled) //WIRELESS
		{
			Intel::MEI_Client::AMTHI_Client::INTERFACE_SETTINGS AMTinterface;

			switch (ConnectionType) {
			case 0: AMTinterface = Intel::MEI_Client::AMTHI_Client::WIRED; break;
			case 1: AMTinterface = Intel::MEI_Client::AMTHI_Client::WIRELESS; break;
			default:
				UNS_DEBUG(L"GetNetworkSettings: wrong ConnectionType\n");
				return ERROR_INVALIDARG;
			}
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetLanInterfaceSettingsCommand getLanInterfaceSettingsCommand(AMTinterface);
				Intel::MEI_Client::AMTHI_Client::LAN_SETTINGS lanSettings = getLanInterfaceSettingsCommand.getResponse();
				pDhcpEnabled = lanSettings.DhcpEnabled;
				in_addr addr;
				addr.s_addr = htonl(lanSettings.Ipv4Address);
				strIpAddress = inet_ntoa(addr);

				bstrMacAddress = MacAddressToString(lanSettings.MacAddress, 6);
				pLinkStatus = lanSettings.LinkStatus;

				if (AMTinterface == Intel::MEI_Client::AMTHI_Client::WIRELESS) {
					pWirelessControl = lanSettings.DhcpIpMode;
					pWirelessConfEnabled = (short)lanSettings.Enabled;
				}
				else {
					// not applicable
					pWirelessControl = 5;
					pWirelessConfEnabled = 5;
				}

				UNS_DEBUG(L"ConnectionType=%d DhcpEnabled=%d IpAddress=%C MacAddress=%C LinkStatus=%d WirelessControl=%d WirelessConfEnabled=%d\n",
					ConnectionType, pDhcpEnabled, inet_ntoa(addr), bstrMacAddress.c_str(), pLinkStatus, pWirelessControl, pWirelessConfEnabled);

				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetLanInterfaceSettingsCommand")
			CATCH_MEIClientException(L"GetLanInterfaceSettingsCommand")
			CATCH_exception(L"GetLanInterfaceSettingsCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetIPv6NetworkSettings(short ConnectionType /*WIRED, WIRELESS*/,
			std::string &IPv6DefaultRouter,
			std::string &PrimaryDNS,
			std::string &SecondaryDNS,
			std::vector<std::string> &pResponse,
			bool &pIpv6Enable)
		{
			/*
			AMT_STATUS_UNSUPPORTED	Returned if this FW SKU does not support IPv6. The status of IPv6 support can be retrieved by calling CFG_GetIPv6Settings.
			AMT_STATUS_INVALID_MESSAGE_LENGTH	Length field of header is invalid.
			AMT_STATUS_IPV6_INTERFACE_DISABLED	The IPv6 interface is currently disabled so there is no current IPv6 status available for this interface.
			AMT_STATUS_INTERFACE_DOES_NOT_EXIST	The network interface that is being referred to in this command does not exist (e.g. wireless interface on desktop)
			*/
			Intel::MEI_Client::AMTHI_Client::INTERFACE_SETTINGS AMTinterface;
			switch (ConnectionType) {
			case 0: AMTinterface = Intel::MEI_Client::AMTHI_Client::WIRED; break;
			case 1: AMTinterface = Intel::MEI_Client::AMTHI_Client::WIRELESS; break;
			default:
				UNS_DEBUG(L"GetIPv6NetworkSettings: wrong ConnectionType\n");
				return ERROR_INVALIDARG;
			}

			bool Ipv6Enablement = false;
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetIPv6LanInterfaceStatusCommand getIPv6LanInterfaceStatusCommand(AMTinterface);
				Intel::MEI_Client::AMTHI_Client::GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE lanSettings = getIPv6LanInterfaceStatusCommand.getResponse();
				Ipv6Enablement = true; //because no exception was thrown

				IPv6DefaultRouter = lanSettings.IPv6DefaultRouter;
				PrimaryDNS = lanSettings.PrimaryDNS;
				SecondaryDNS = lanSettings.SecondaryDNS;

				pResponse.resize(lanSettings.IPv6Addresses.size());
				std::stringstream ip_str;
				size_t adressesSize = lanSettings.IPv6Addresses.size();
				for (size_t i = 0; i < adressesSize; i++)
				{
					pResponse[i] = lanSettings.IPv6Addresses[i].Address;
					ip_str << pResponse[i].c_str() << ", ";
				}
				UNS_DEBUG(L"GetLanInterfaceSettings:  IPv6DefaultRouter=%C PrimaryDNS=%C SecondaryDNS=%C \t   IPv6: %C\n, Ipv6Enablement=%d",
					IPv6DefaultRouter.c_str(), PrimaryDNS.c_str(), SecondaryDNS.c_str(), ip_str.str().c_str(), Ipv6Enablement);
				pIpv6Enable = Ipv6Enablement;
				return ERROR_OK;
			}
			catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
			{
				unsigned int errNo = e.getErr();
				if (errNo == AMT_STATUS_IPV6_INTERFACE_DISABLED) //this is not a failure
				{
					IPv6DefaultRouter = "";
					PrimaryDNS = "";
					SecondaryDNS = "";
					pResponse.resize(0);
					pIpv6Enable = Ipv6Enablement;
					return ERROR_OK;
				}
				else
					UNS_DEBUG(L"GetIPv6LanInterfaceStatusCommand failed ret=%d\n", errNo);
			}
			CATCH_MEIClientException(L"GetIPv6LanInterfaceStatusCommand")
			CATCH_exception(L"GetIPv6LanInterfaceStatusCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetSystemUUID(std::string &bstrUUID)
		{
			/*
			AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
			*/

			std::string systemUUID;
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetUUIDCommand  getUUIDCommand;
				Intel::MEI_Client::AMTHI_Client::GET_UUID_RESPONSE uuid = getUUIDCommand.getResponse();
				bstrUUID = uuidToString(uuid.UUID);

				UNS_DEBUG("AmtUUID=%C\n", bstrUUID.c_str());
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"GetUUIDCommand")
			CATCH_MEIClientException(L"GetUUIDCommand")
			CATCH_exception(L"GetUUIDCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::CloseUserInitiatedConnection(void)
		{
			/*
			AMT_STATUS_NOT_PERMITTED	Entity has no permission to close a connection.
			*/
			try
			{
				Intel::MEI_Client::AMTHI_Client::CloseUserInitiatedConnectionCommand closeUserInitiatedConnection;
				UNS_DEBUG(L"CIRA closed\n");
				return ERROR_OK;
			}
			CATCH_AMTHIErrorException(L"CloseUserInitiatedConnection")
			CATCH_MEIClientException(L"CloseUserInitiatedConnection")
			CATCH_exception(L"CloseUserInitiatedConnection")
			return ERROR_FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetKVMRedirectionState(bool &pEnabled, bool &pConnected)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			KVMWSManClient WSClient;
			bool MEBxState = false;
			if (!WSClient.GetMEBxState(&MEBxState))
			{
				return ERROR_FAIL;
			}
			if (!MEBxState)
			{
				pEnabled = false;
				pConnected = false;
				return ERROR_OK;
			}
			unsigned short state;
			if (!WSClient.KVMRedirectionState(&state))
			{
				return ERROR_FAIL;
			}
			switch (state)
			{
			case 2: //Enabled and Connected
				pEnabled = true;
				pConnected = true;
				break;
			case 3: //Disabled and NotConnected
				pEnabled = false;
				pConnected = false;
				break;
			case 6: //Enabled and NotConnected
				pEnabled = true;
				pConnected = false;
				break;
			default:
				UNS_DEBUG(L"Wrong KVMRedirectionState=%d \n", state);
				return ERROR_UNEXPECTED;
			}
			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::SetSpriteLanguage(unsigned short Language)
		{
			MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
			mbPtr->data_block(new StartPFWUP(Language));
			mbPtr->msg_type(MB_PFWU_EVENT);

			if (!theService::instance()->sendMessage(GMS_PARTIALFWUPDATESERVICE, mbPtr))
			{
				return ERROR_FAIL;
			}
			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetSpriteParameters(unsigned short &pLanguage, unsigned short &pZoom)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			SIOWSManClient Client;
			if (Client.GetSpriteParameters(&pLanguage, &pZoom) != true)
				return ERROR_FAIL;

			unsigned long lang;
			if (!DSinstance().GetDataValue(LastLanguageUpdate, lang))
				pLanguage = DEFAULT_LANG_ID;

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::SetSpriteZoom(unsigned short Zoom)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			SIOWSManClient Client;
			if (Client.SetSpriteZoom(Zoom) != true)
				return ERROR_FAIL;
			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetConfigurationInfo(short &pControlMode, short &pProvisioningMethod,
			std::string &pCreationTimeStamp, std::vector<unsigned char> &ppCertHash)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			HBPWSManClient HBPWSManClient_obj;
			std::string CreationTimeStampStr;
			if (HBPWSManClient_obj.GetConfigurationInfo(&pControlMode, &pProvisioningMethod, CreationTimeStampStr, ppCertHash) != true)
				return ERROR_FAIL;

			UNS_DEBUG(L"ControlMode=%d, ProvisioningMethod=%d, CreationTimeStampStr=%C\n",
				pControlMode, pProvisioningMethod, CreationTimeStampStr.c_str());
			pCreationTimeStamp = CreationTimeStampStr;

			return ERROR_OK;
		}

		const int TERMINATEREMEDYSESSIONS_RETRIES = 3;
		const long TERMINATEREMEDYSESSIONS_RETRY_TIMEOUT = 2000;
		LMS_ERROR PTHI_Commands_BE::TerminateRemedySessions(void)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			LMS_ERROR ret = ERROR_FAIL;
			KVMWSManClient _KVMWSManClient;
			if (_KVMWSManClient.TerminateKVMSession())
				ret = ERROR_OK;
			// Terminate IDER, SOL sessions
			AMTRedirectionServiceWSManClient _AMTRedirectionServiceWSManClient;
			if (_AMTRedirectionServiceWSManClient.TerminateSession(1)) //SOL
				ret = ERROR_OK;
			if (_AMTRedirectionServiceWSManClient.TerminateSession(0)) // IDER
				ret = ERROR_OK;

			unsigned int ReturnValue;
			CancelOptInClient _CancelOptInClient;
			short policy, state;

			_CancelOptInClient.GetUserConsentState(&state, &policy);
			if (state != 0) // cancel consent only if consent started
			{
				for (int i = 0; i < TERMINATEREMEDYSESSIONS_RETRIES; i++)
				{
					if ((_CancelOptInClient.CancelOptIn(&ReturnValue)) && (ReturnValue == 0))
					{
						ret = ERROR_OK;
						break;
					}
					else
						std::this_thread::sleep_for(std::chrono::milliseconds(TERMINATEREMEDYSESSIONS_RETRY_TIMEOUT));
				}
			}
			return ret;
		}

		LMS_ERROR PTHI_Commands_BE::GetUserConsentState(short &pState, USER_CONSENT_POLICY &pPolicy)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			short UserConsentPolicy;
			CancelOptInClient _CancelOptInClient;
			if (!_CancelOptInClient.GetUserConsentState(&pState, &UserConsentPolicy))
				return ERROR_FAIL;
			pPolicy = static_cast<USER_CONSENT_POLICY>(UserConsentPolicy);

			UNS_DEBUG(L"UserConsentState=%d, UserConsentPolicy=%d \n", pState, pPolicy);

			return ERROR_OK;

		}

		LMS_ERROR PTHI_Commands_BE::GetWLANLinkInfo(unsigned int &pPreference, unsigned int &pControl, unsigned int &pProtection)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTEthernetPortSettingsClient Client;
			if (!Client.GetAMTEthernetPortSettings(&pPreference, &pControl, &pProtection))
				return ERROR_FAIL;

			UNS_DEBUG(L"GetWLANLinkInfo: Preference=%d, Control=%d Protection=%d \n", pPreference, pControl, pProtection);

			return ERROR_OK;

		}

		LMS_ERROR PTHI_Commands_BE::SetLinkPreferenceToHost(void)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTEthernetPortSettingsClient Client;
			if (!Client.SetLinkPreference(2))
				return ERROR_FAIL;
			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::InitiateUserConnection(short &pStatus)
		{
			/*
			AMT_STATUS_NOT_PERMITTED	Entity has no permission to open a connection..
			AMT_STATUS_INTERNAL_ERROR	The operation could not be completed by AMT.
			AMT_STATUS_DATA_MISSING		No connectivity policy configured when AMT is outside the enterprise network.
			*/
			try {
				Intel::MEI_Client::AMTHI_Client::OpenUserInitiatedConnectionCommand openUserInitiatedConnection;
				pStatus = AMT_STATUS_SUCCESS;
				UNS_DEBUG(L"OpenUserInitiatedConnection opened\n");
				return ERROR_OK;
			}
			catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
			{
				pStatus = (short)e.getErr();
				if ((pStatus == AMT_STATUS_NOT_READY) || (pStatus == AMT_STATUS_DATA_MISSING))
				{
					UNS_DEBUG(L"OpenUserInitiatedConnection failed, but returned status=%d\n", pStatus);
					return ERROR_OK;
				}
				else
				{
					UNS_DEBUG(L"OpenUserInitiatedConnection failed, ret=%d\n", pStatus);
				}
			}
			CATCH_MEIClientException(L"OpenUserInitiatedConnection")
			CATCH_exception(L"OpenUserInitiatedConnection")
			return ERROR_FAIL;
		}


		LMS_ERROR PTHI_Commands_BE::userInitiatedPolicyRuleExists(short &pStatus)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTFCFHWSmanClient Client;
			if (Client.userInitiatedPolicyRuleExists(&pStatus) != true)
				return ERROR_FAIL;

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::userInitiatedPolicyRuleForLocalMpsExists(short &pStatus)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTFCFHWSmanClient Client;
			if (Client.userInitiatedPolicyRuleForLocalMpsExists(&pStatus) != true)
				return ERROR_FAIL;

			return ERROR_OK;
		}


		LMS_ERROR PTHI_Commands_BE::snmpEventSubscriberExists(short &pExist)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTFCFHWSmanClient Client;
			if (Client.snmpEventSubscriberExists(&pExist) != true)
				return ERROR_FAIL;

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::CILAFilterCollectionSubscriptionExists(short &pExist)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			AMTFCFHWSmanClient Client;
			if (Client.CILAFilterCollectionSubscriptionExists(&pExist) != true)
				return ERROR_FAIL;

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::UpdateScreenSettings2(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, short numOfDisplays)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			KVMScreenSettingClient Client;
			KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

			for (int i = 0; i < numOfDisplays && i < array_size(extendedDisplayParameters.screenSettings); ++i)
			{
				extendedDisplayParameters.screenSettings[i].isActive = eExtendedDisplayParameters.DisplayParameters[i].IsActive;
				extendedDisplayParameters.screenSettings[i].ResolutionX = eExtendedDisplayParameters.DisplayParameters[i].SizeX;
				extendedDisplayParameters.screenSettings[i].ResolutionY = eExtendedDisplayParameters.DisplayParameters[i].SizeY;
				extendedDisplayParameters.screenSettings[i].UpperLeftX = eExtendedDisplayParameters.DisplayParameters[i].UpperLeftX;
				extendedDisplayParameters.screenSettings[i].UpperLeftY = eExtendedDisplayParameters.DisplayParameters[i].UpperLeftY;
				extendedDisplayParameters.screenSettings[i].Pipe = eExtendedDisplayParameters.DisplayParameters[i].Pipe;
			}
			if (!Client.updateScreenSettings(extendedDisplayParameters, numOfDisplays))
			{
				return ERROR_FAIL;
			}

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetRedirectionSessionLinkTechnology(REDIRECTION_SESSION_TYPE sessionType, short &pLinkTechnology)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			if (sessionType == SOL_S)
			{
				IPSSolSessionUsingPortClient solClient;
				if (solClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
					return ERROR_FAIL;
			}
			else if (sessionType == IDER_S)
			{
				IPSIderSessionUsingPortClient iderClient;
				if (iderClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
					return ERROR_FAIL;
			}
			else if (sessionType == KVM_S)
			{
				IPSKVMSessionUsingPortClient kvmClient;
				if (kvmClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
					return ERROR_FAIL;
			}
			else
			{
				UNS_DEBUG(L"GetRedirectionSessionLinkTechnology: Invalid session type %d\n", sessionType);
				return ERROR_INVALIDARG;
			}

			UNS_DEBUG(L"GetRedirectionSessionLinkTechnology: LinkTechnology=%d \n", pLinkTechnology);

			return ERROR_OK;
		}

		LMS_ERROR PTHI_Commands_BE::IsRebootAfterProvisioningNeeded(bool &pNeeded)
		{
			unsigned long needed = 0;
			if (!DSinstance().GetDataValue(RebootAfterProvsioningNeeded_S, needed, true)) {
				UNS_ERROR(L"CPTHI_Commands::IsRebootAfterProvisioningNeeded GetDataValue failed\n");
				return ERROR_FAIL;
			}
			pNeeded = (needed != 0);
			UNS_DEBUG(L"CPTHI_Commands::IsRebootAfterProvisioningNeeded, got from StatusEventHandler %d\n", pNeeded);
			return ERROR_OK;
		}
	}
}
