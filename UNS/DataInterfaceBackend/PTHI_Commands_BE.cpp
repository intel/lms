/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
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
#include "PSRGetPlatformServiceRecordCommand.h"
#include "GetUPIDFeatureStateCommand.h"
#include "SetUPIDFeatureStateCommand.h"
#include "ReadFileExCommand.h"
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

#define CATCH_PSRErrorException(func) \
	catch (Intel::MEI_Client::PSR_Client::PSRErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	}

#define CATCH_UPIDErrorException(func) \
	catch (Intel::MEI_Client::UPID_Client::UPIDErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	}
#define CATCH_NoClientExceptionReturn(func) \
	catch (const Intel::MEI_Client::HeciNoClientException& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(L"Exception in " func " %C\n", reason); \
		return LMS_ERROR::NOT_SUPPORTED_BY_FW; \
	}

#define CATCH_exception(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(L"Exception in " func L" %C\n", reason); \
	}

#define CATCH_MCHIErrorExceptionAllReturn(func) \
	catch (const Intel::MEI_Client::MCHI_Client::MCHIErrorExceptionNoFile&) \
	{ \
		UNS_DEBUG(func L" failed NoFile\n"); \
		return LMS_ERROR::NOT_SUPPORTED_BY_FW; \
	} \
	catch (Intel::MEI_Client::MCHI_Client::MCHIErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	} \
	CATCH_NoClientExceptionReturn(func) \
	CATCH_MEIClientException(func) \
	CATCH_exception(func) \
	return LMS_ERROR::FAIL;

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

		std::string timeToString(uint32_t timestamp)
		{
			struct tm time_tm;
			time_t time_ = timestamp;
#ifdef WIN32
			gmtime_s(&time_tm, &time_);
#else
			gmtime_r(&time_, &time_tm);
#endif // WIN32
			char time_s[128];
			strftime(time_s, 128, "%FT%RZ", &time_tm);
			return time_s;
		}

		PTHI_Commands_BE::PTHI_Commands_BE(unsigned int port) : Common_BE(port)
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetCodeVersionCommand")
			CATCH_MEIClientException(L"GetCodeVersionCommand")
			CATCH_exception(L"GetCodeVersionCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetAMTVersion(std::string &sAMTVersion)
		{
			return GetStringAMTVersion(sAMTVersion);
		}

#ifdef WIN32
		LMS_ERROR PTHI_Commands_BE::GetLMSVersion(std::string& sVersion)
		{
			DWORD dwHandle = 0;
			DWORD FileSize;
			WCHAR Filename[MAX_PATH + 1] = { 0 };

			if (GetModuleFileNameW(NULL, Filename, MAX_PATH) == 0)
			{
				UNS_DEBUG(L"GetServiceVersion:GetModuleFileName failed with err=%d\n", GetLastError());
				return LMS_ERROR::FAIL;
			}

			FileSize = GetFileVersionInfoSize(Filename, &dwHandle);
			if (FileSize == 0)
			{
				UNS_DEBUG(L"GetServiceVersion:GetFileVersionInfoSize failed err=%d\n", GetLastError());
				return LMS_ERROR::FAIL;
			}

			std::vector<BYTE> FileValues(FileSize);
			if (GetFileVersionInfo(Filename, NULL, FileSize, FileValues.data()) == 0)
			{
				UNS_DEBUG(L"GetServiceVersion:GetFileVersionInfoSize failed err=%d\n", GetLastError());
				return LMS_ERROR::FAIL;
			}

			VS_FIXEDFILEINFO *fileQuerInfo;
			UINT InfoSize = 0;
			if (!VerQueryValue(FileValues.data(), TEXT("\\"), (LPVOID*)&fileQuerInfo, &InfoSize) ||
				!InfoSize || InfoSize < sizeof(VS_FIXEDFILEINFO)) 
			{
				UNS_DEBUG(L"GetServiceVersion:VerQueryValue failed err=%d\n", GetLastError());
				return LMS_ERROR::FAIL;
			}
			std::stringstream ss;
			ss << HIWORD(fileQuerInfo->dwProductVersionMS) << "."
			   << LOWORD(fileQuerInfo->dwProductVersionMS) << "."
			   << HIWORD(fileQuerInfo->dwProductVersionLS) << "."
			   << LOWORD(fileQuerInfo->dwProductVersionLS);
			sVersion = ss.str();

			return LMS_ERROR::OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetHeciVersion(std::string &sVersion)
		{
			try
			{
				Intel::MEI_Client::GetHeciDriverVersion(sVersion);
				return LMS_ERROR::OK;
			}
			CATCH_HECIException(L"GetHeciVersion")
			CATCH_AMTHIErrorException(L"GetHeciVersion")
			CATCH_MEIClientException(L"GetHeciVersion")
			CATCH_exception(L"GetHeciVersion")
			return LMS_ERROR::FAIL;
		}
#else
		LMS_ERROR PTHI_Commands_BE::GetLMSVersion(std::string &sVersion)
		{
			std::stringstream str;
			str << MAJOR_VERSION << "." << MINOR_VERSION << "." <<
				QUICK_FIX_NUMBER << "." << VER_BUILD;
			sVersion = str.str();
			return LMS_ERROR::OK;
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
				return LMS_ERROR::OK;
			}
			catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
			{
				unsigned int errNo = e.getErr();
				if (errNo == AMT_STATUS_NOT_READY)
				{
					pProvisioningState = 4; // CCK enrolled (registration to CCK) - Dan:: need to align IMSS to the new definition - no more CCK
					UNS_DEBUG(L"GetProvisioningStateCommand failed, but returned status=%d assume CCK enrolled let ProvisioningState=4\n", errNo);
					return LMS_ERROR::OK;
				}
				else
				{
					UNS_DEBUG(L"GetProvisioningStateCommand failed ret=%d\n", errNo);
				}
			}
			CATCH_MEIClientException(L"GetProvisioningStateCommand")
			CATCH_exception(L"GetProvisioningStateCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetRemoteAccessConnectionStatus")
			CATCH_MEIClientException(L"GetRemoteAccessConnectionStatus")
			CATCH_exception(L"GetRemoteAccessConnectionStatus")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetUserInitiatedEnabled(short &pStatus)
		{
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetUserInitiatedEnabledInterfacesCommand getUserInitiatedEnabledInterfacesCommand;
				pStatus = getUserInitiatedEnabledInterfacesCommand.getResponse().EnabledInterfaces.OS_Agent;
				UNS_DEBUG(L"GetUserInitiatedEnabled enabled=%d\n", pStatus);
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetUserInitiatedEnabledInterfacesCommand")
			CATCH_MEIClientException(L"GetUserInitiatedEnabledInterfacesCommand")
			CATCH_exception(L"GetUserInitiatedEnabledInterfacesCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetPowerPolicy(std::string &bstrPolicy)
		{
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetCurrentPowerPolicyCommand getCurrentPowerPolicyCommand;
				UNS_DEBUG(L"powerPolicyName=%C\n", getCurrentPowerPolicyCommand.getResponse().c_str());
				bstrPolicy = getCurrentPowerPolicyCommand.getResponse().c_str();
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetCurrentPowerPolicyCommand")
			CATCH_MEIClientException(L"GetCurrentPowerPolicyCommand")
			CATCH_exception(L"GetCurrentPowerPolicyCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetLastResetReason(short &pReason)
		{
			// Need to check if the values fit to: ME_LAST_RESET_REASON ==> POWER_UP = 0,FW_RESET = 1,GLOBAL_SYSTEM_RESET = 2,REASON_UNKOWN = 3
			try
			{
				Intel::MEI_Client::AMTHI_Client::GetAMTStateCommand getAMTStateCommand;
				pReason = getAMTStateCommand.getResponse().StateData.Fields.LastMEResetType;
				UNS_DEBUG(L"LastResetReason=%d\n", pReason);
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetAMTStateCommand")
			CATCH_MEIClientException(L"GetAMTStateCommand")
			CATCH_exception(L"GetAMTStateCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetRedirectionSessionsStateCommand")
			CATCH_MEIClientException(L"GetRedirectionSessionsStateCommand")
			CATCH_exception(L"GetRedirectionSessionsStateCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetSystemDefenseStatus")
			CATCH_MEIClientException(L"GetSystemDefenseStatus")
			CATCH_exception(L"GetSystemDefenseStatus")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::INVALIDARG;
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

				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetLanInterfaceSettingsCommand")
			CATCH_MEIClientException(L"GetLanInterfaceSettingsCommand")
			CATCH_exception(L"GetLanInterfaceSettingsCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::INVALIDARG;
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
				return LMS_ERROR::OK;
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
					return LMS_ERROR::OK;
				}
				else
					UNS_DEBUG(L"GetIPv6LanInterfaceStatusCommand failed ret=%d\n", errNo);
			}
			CATCH_MEIClientException(L"GetIPv6LanInterfaceStatusCommand")
			CATCH_exception(L"GetIPv6LanInterfaceStatusCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"GetUUIDCommand")
			CATCH_MEIClientException(L"GetUUIDCommand")
			CATCH_exception(L"GetUUIDCommand")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			CATCH_AMTHIErrorException(L"CloseUserInitiatedConnection")
			CATCH_MEIClientException(L"CloseUserInitiatedConnection")
			CATCH_exception(L"CloseUserInitiatedConnection")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetKVMRedirectionState(bool &pEnabled, bool &pConnected)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				KVMWSManClient WSClient(m_port);
				bool MEBxState = false;
				if (!WSClient.GetMEBxState(&MEBxState))
				{
					return LMS_ERROR::FAIL;
				}
				if (!MEBxState)
				{
					pEnabled = false;
					pConnected = false;
					return LMS_ERROR::OK;
				}
				unsigned short state;
				if (!WSClient.KVMRedirectionState(&state))
				{
					return LMS_ERROR::FAIL;
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
					return LMS_ERROR::UNEXPECTED;
				}
				return LMS_ERROR::OK;
			}
			CATCH_exception(L"GetKVMRedirectionState")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::SetSpriteLanguage(unsigned short Language)
		{
			auto svc = theService::instance();
			if (svc == nullptr)
			{
				return LMS_ERROR::FAIL;
			}

			MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
			mbPtr->data_block(new StartPFWUP(Language));
			mbPtr->msg_type(MB_PFWU_EVENT);
			if (!svc->sendMessage(GMS_PARTIALFWUPDATESERVICE, mbPtr))
			{
				return LMS_ERROR::FAIL;
			}
			return LMS_ERROR::OK;
		}

		LMS_ERROR PTHI_Commands_BE::GetSpriteParameters(unsigned short &pLanguage, unsigned short &pZoom)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				SIOWSManClient Client(m_port);
				if (Client.GetSpriteParameters(&pLanguage, &pZoom) != true)
					return LMS_ERROR::FAIL;

				unsigned long lang;
				if (!DSinstance().GetDataValue(LastLanguageUpdate, lang))
					pLanguage = DEFAULT_LANG_ID;
				return LMS_ERROR::OK;
			}
			CATCH_exception(L"GetSpriteParameters")

			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::SetSpriteZoom(unsigned short Zoom)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				SIOWSManClient Client(m_port);
				if (Client.SetSpriteZoom(Zoom))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"SIOWSManClient")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetConfigurationInfo(short &pControlMode, short &pProvisioningMethod,
			std::string &pCreationTimeStamp, std::vector<unsigned char> &ppCertHash)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				HBPWSManClient HBPWSManClient_obj(m_port);
				std::string CreationTimeStampStr;
				if (HBPWSManClient_obj.GetConfigurationInfo(&pControlMode, &pProvisioningMethod, CreationTimeStampStr, ppCertHash) != true)
					return LMS_ERROR::FAIL;

				UNS_DEBUG(L"ControlMode=%d, ProvisioningMethod=%d, CreationTimeStampStr=%C\n",
					pControlMode, pProvisioningMethod, CreationTimeStampStr.c_str());
				pCreationTimeStamp = CreationTimeStampStr;
				return LMS_ERROR::OK;
			}
			CATCH_exception(L"SIOWSManClient")
			return LMS_ERROR::FAIL;
		}

		const int TERMINATEREMEDYSESSIONS_RETRIES = 3;
		const long TERMINATEREMEDYSESSIONS_RETRY_TIMEOUT = 2000;
		LMS_ERROR PTHI_Commands_BE::TerminateRemedySessions(void)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				LMS_ERROR ret = LMS_ERROR::FAIL;
				KVMWSManClient _KVMWSManClient(m_port);
				if (_KVMWSManClient.TerminateKVMSession())
					ret = LMS_ERROR::OK;
				// Terminate IDER, SOL sessions
				AMTRedirectionServiceWSManClient _AMTRedirectionServiceWSManClient(m_port);
				if (_AMTRedirectionServiceWSManClient.TerminateSession(1)) //SOL
					ret = LMS_ERROR::OK;
				if (_AMTRedirectionServiceWSManClient.TerminateSession(0)) // IDER
					ret = LMS_ERROR::OK;

				unsigned int ReturnValue;
				CancelOptInClient _CancelOptInClient(m_port);
				short policy = 0, state = 0;

				if (!_CancelOptInClient.GetUserConsentState(&state, &policy))
					return LMS_ERROR::FAIL;
				if (state != 0) // cancel consent only if consent started
				{
					for (int i = 0; i < TERMINATEREMEDYSESSIONS_RETRIES; i++)
					{
						if ((_CancelOptInClient.CancelOptIn(&ReturnValue)) && (ReturnValue == 0))
						{
							ret = LMS_ERROR::OK;
							break;
						}
						else
							std::this_thread::sleep_for(std::chrono::milliseconds(TERMINATEREMEDYSESSIONS_RETRY_TIMEOUT));
					}
				}
				return ret;
			}
			CATCH_exception(L"TerminateRemedySessions")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetUserConsentState(short &pState, USER_CONSENT_POLICY &pPolicy)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				short UserConsentPolicy;
				CancelOptInClient _CancelOptInClient(m_port);
				if (!_CancelOptInClient.GetUserConsentState(&pState, &UserConsentPolicy))
					return LMS_ERROR::FAIL;
				pPolicy = static_cast<USER_CONSENT_POLICY>(UserConsentPolicy);

				UNS_DEBUG(L"UserConsentState=%d, UserConsentPolicy=%d \n", pState, pPolicy);

				return LMS_ERROR::OK;
			}
			CATCH_exception(L"TerminateRemedySessions")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetWLANLinkInfo(unsigned int &pPreference, unsigned int &pControl, unsigned int &pProtection)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				AMTEthernetPortSettingsClient Client(m_port);
				bool isLink = false;
				if (!Client.GetAMTEthernetPortSettings(&pPreference, &pControl, &pProtection, &isLink))
					return LMS_ERROR::FAIL;

				UNS_DEBUG(L"GetWLANLinkInfo: Preference=%d, Control=%d Protection=%d \n", pPreference, pControl, pProtection);

				return LMS_ERROR::OK;
			}
			CATCH_exception(L"GetWLANLinkInfo")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::SetLinkPreferenceToHost(void)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				AMTEthernetPortSettingsClient Client(m_port);
				if (Client.SetLinkPreference(2))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"SetLinkPreferenceToHost")
			return LMS_ERROR::FAIL;
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
				return LMS_ERROR::OK;
			}
			catch (Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
			{
				pStatus = (short)e.getErr();
				if ((pStatus == AMT_STATUS_NOT_READY) || (pStatus == AMT_STATUS_DATA_MISSING))
				{
					UNS_DEBUG(L"OpenUserInitiatedConnection failed, but returned status=%d\n", pStatus);
					return LMS_ERROR::OK;
				}
				else
				{
					UNS_DEBUG(L"OpenUserInitiatedConnection failed, ret=%d\n", pStatus);
				}
			}
			CATCH_MEIClientException(L"OpenUserInitiatedConnection")
			CATCH_exception(L"OpenUserInitiatedConnection")
			return LMS_ERROR::FAIL;
		}


		LMS_ERROR PTHI_Commands_BE::userInitiatedPolicyRuleExists(short &pStatus)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				AMTFCFHWSmanClient Client(m_port);
				if (Client.userInitiatedPolicyRuleExists(&pStatus))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"userInitiatedPolicyRuleExists")

			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::userInitiatedPolicyRuleForLocalMpsExists(short &pStatus)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				AMTFCFHWSmanClient Client(m_port);
				if (Client.userInitiatedPolicyRuleForLocalMpsExists(&pStatus))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"userInitiatedPolicyRuleForLocalMpsExists")

			return LMS_ERROR::FAIL;
		}


		LMS_ERROR PTHI_Commands_BE::snmpEventSubscriberExists(short &pExist)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				AMTFCFHWSmanClient Client(m_port);
				if (Client.snmpEventSubscriberExists(&pExist))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"snmpEventSubscriberExists")

			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::CILAFilterCollectionSubscriptionExists(short &pExist)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				AMTFCFHWSmanClient Client(m_port);
				if (Client.CILAFilterCollectionSubscriptionExists(&pExist))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"CILAFilterCollectionSubscriptionExists")

			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::UpdateScreenSettings2(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, unsigned short numOfDisplays)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				KVMScreenSettingClient Client(m_port);
				KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

				for (size_t i = 0; i < numOfDisplays && i < array_size(extendedDisplayParameters.screenSettings); ++i)
				{
					extendedDisplayParameters.screenSettings[i].isActive = eExtendedDisplayParameters.DisplayParameters[i].IsActive;
					extendedDisplayParameters.screenSettings[i].ResolutionX = eExtendedDisplayParameters.DisplayParameters[i].SizeX;
					extendedDisplayParameters.screenSettings[i].ResolutionY = eExtendedDisplayParameters.DisplayParameters[i].SizeY;
					extendedDisplayParameters.screenSettings[i].UpperLeftX = eExtendedDisplayParameters.DisplayParameters[i].UpperLeftX;
					extendedDisplayParameters.screenSettings[i].UpperLeftY = eExtendedDisplayParameters.DisplayParameters[i].UpperLeftY;
					extendedDisplayParameters.screenSettings[i].Pipe = eExtendedDisplayParameters.DisplayParameters[i].Pipe;
				}
				if (Client.updateScreenSettings(extendedDisplayParameters, numOfDisplays))
					return LMS_ERROR::OK;
			}
			CATCH_exception(L"updateScreenSettings")

			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetRedirectionSessionLinkTechnology(REDIRECTION_SESSION_TYPE sessionType, short &pLinkTechnology)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try {
				if (sessionType == SOL_S)
				{
					IPSSolSessionUsingPortClient solClient(m_port);
					if (solClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
						return LMS_ERROR::FAIL;
				}
				else if (sessionType == IDER_S)
				{
					IPSIderSessionUsingPortClient iderClient(m_port);
					if (iderClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
						return LMS_ERROR::FAIL;
				}
				else if (sessionType == KVM_S)
				{
					IPSKVMSessionUsingPortClient kvmClient(m_port);
					if (kvmClient.GetSessionLinkTechnology(&pLinkTechnology) != true)
						return LMS_ERROR::FAIL;
				}
				else
				{
					UNS_DEBUG(L"GetRedirectionSessionLinkTechnology: Invalid session type %d\n", sessionType);
					return LMS_ERROR::INVALIDARG;
				}

				UNS_DEBUG(L"GetRedirectionSessionLinkTechnology: LinkTechnology=%d \n", pLinkTechnology);
				return LMS_ERROR::OK;
			}
			CATCH_exception(L"updateScreenSettings")

			return LMS_ERROR::FAIL;
		}

		std::string genesisFieldToString(const uint8_t *info)
		{
			return std::string(info, info + Intel::MEI_Client::PSR_Client::PSR_GENESIS_FIELD_INFO_SIZE).c_str();
		}

		std::string formatPSRPrefix(const std::string& item)
		{
			std::stringstream parsed;

			parsed << "<Data>\n<Item><![CDATA[" << item << "]]></Item>" << std::endl;
			parsed << "<Value><![CDATA[";
			return parsed.str();
		}

		std::string formatPSRSuffix()
		{
			std::stringstream parsed;

			parsed << "]]></Value>\n</Data>" << std::endl;
			return parsed.str();
		}

		template<class T>
		std::string formatPSRField(const std::string& item, const T& value)
		{
			std::stringstream parsed;

			parsed << formatPSRPrefix(item) << value << formatPSRSuffix();
			return parsed.str();
		}

		LMS_ERROR PTHI_Commands_BE::GetPlatformServiceRecord(std::string& strPSR)
		{
			std::array<uint8_t, Intel::MEI_Client::PSR_Client::PSR_NONCE_SIZE> nonce = { 0 };
			std::stringstream parsed;
			std::map<uint32_t, std::string> log_states = {
				{Intel::MEI_Client::PSR_Client::PSR_LOG_NOT_STARTED, "Not started"},
				{Intel::MEI_Client::PSR_Client::PSR_LOG_STARTED, "Started"},
				{Intel::MEI_Client::PSR_Client::PSR_LOG_STOPPED, "Stopped"},
			};
			std::map<uint8_t, std::string> events = {
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_START, "Log Started"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_STOP, "Log Ended"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_MAX_EVENT, "Log Full"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_RP_INF_FAIL, "Replay Protection Infrastructure Failure"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_PSR_MISSING, "Log Missing"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_PSR_INVALID, "Log Integrity Compromised"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_PRTC_FAILURE, "PRTC Reset"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_RECOVERY_STATE, "Log in Recovery State"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_DAM_STATE, "DAM State Entered"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_UNLOCK_STTE, "Unlocked State Entered"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_SVN_INCREASE, "PSR SVN Incremented"},
				{Intel::MEI_Client::PSR_Client::PSR_EVENT_CHASSIS_INTRUSION, "Chassis Intrusion Detected"},
			};
			std::string state_str, event_str;
			enum class TIMER_FAIL
			{
				NO,
				PRTC,
				RP
			};
			TIMER_FAIL have_timer_fail = TIMER_FAIL::NO;

			try
			{
				Intel::MEI_Client::PSR_Client::PSRGetPlatformServiceRecordCommand psrGetPlatformServiceRecordCommand(nonce);
				Intel::MEI_Client::PSR_Client::PSR_GET_RESPONSE psr = psrGetPlatformServiceRecordCommand.getResponse();

				parsed << "<?xml version=\"1.0\"?>\n<MsInfo>\n<Category name=\"Platform Service Record\">\n";

				parsed << "<Category name=\"General\">" << std::endl;
				try
				{
					state_str = log_states.at(psr.log_state);
				}
				catch (std::out_of_range const&)
				{
					state_str = "Unknown";
				}
				parsed << formatPSRField("Log State", state_str);
				parsed << formatPSRPrefix("PSR Version") << psr.psr_version_major << "." << psr.psr_version_minor << formatPSRSuffix();
				parsed << formatPSRField("Platform Service Record ID", uuidToString(psr.psrid));
				parsed << formatPSRPrefix("Unique Platform ID");
				for (size_t k = 0; k < Intel::MEI_Client::PSR_Client::UPID_PLATFORM_ID_LENGTH; k++)
					parsed << "0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)psr.upid[k] << std::dec << " ";
				parsed << formatPSRSuffix();
				parsed << "</Category>" << std::endl;

				parsed << "<Category name=\"Genesis\">" << std::endl;
				parsed << formatPSRField("Log Start Date", timeToString(psr.genesis_info.genesis_date));
				parsed << formatPSRField("OEM Name", genesisFieldToString(psr.genesis_info.oem_info));
				parsed << formatPSRField("OEM Make", genesisFieldToString(psr.genesis_info.oem_make_info));
				parsed << formatPSRField("OEM Model", genesisFieldToString(psr.genesis_info.oem_model_info));
				parsed << formatPSRField("Country of Manufacturer", genesisFieldToString(psr.genesis_info.manuf_country));
				parsed << formatPSRPrefix("OEM Data");
				for (size_t i = 0; i < Intel::MEI_Client::PSR_Client::PSR_GENESIS_DATA_STORE_INFO_SIZE; i++)
					parsed << "0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)psr.genesis_info.oem_data_store[i] << std::dec << " ";
				parsed << formatPSRSuffix();
				parsed << "</Category>" << std::endl;

				parsed << "<Category name=\"Ledger\">" << std::endl;
				parsed << formatPSRPrefix("S0 Run Time In Seconds") << psr.ledger_info.s0_seconds_counter << formatPSRSuffix();
				parsed << formatPSRField("S0 to S5 Transition Count", psr.ledger_info.s0_to_s5_counter);
				parsed << formatPSRField("S0 to S4 Transition Count", psr.ledger_info.s0_to_s4_counter);
				parsed << formatPSRField("S0 to S3 Transition Count", psr.ledger_info.s0_to_s3_counter);
				parsed << formatPSRField("Warm Reset Count", psr.ledger_info.warm_reset_counter);
				parsed << "</Category>" << std::endl;

				parsed << "<Category name=\"Events\">" << std::endl;
				for (uint32_t i = 0; i < psr.events_count && i < Intel::MEI_Client::PSR_Client::PSR_CRITICAL_EVENTS_NUM_MAX; i++)
				{
					try
					{
						event_str = events.at(psr.events_info[i].event_id);
					}
					catch (std::out_of_range const&)
					{
						event_str = "Unknown";
					}
					parsed << "<Category name=\"" << event_str << "\">" << std::endl;
					parsed << formatPSRField("Event ID", (unsigned int)psr.events_info[i].event_id);
					switch (psr.events_info[i].event_id)
					{
					case Intel::MEI_Client::PSR_Client::PSR_EVENT_PRTC_FAILURE:
						have_timer_fail = TIMER_FAIL::PRTC;
						parsed << formatPSRField("Time", "Unknown");
						break;
					case Intel::MEI_Client::PSR_Client::PSR_EVENT_RP_INF_FAIL:
						have_timer_fail = TIMER_FAIL::RP;
						parsed << formatPSRField("Time", "Unknown");
						break;
					default:
						switch (have_timer_fail)
						{
						case TIMER_FAIL::PRTC:
							parsed << formatPSRPrefix("Time") << psr.events_info[i].timestamp << " seconds since PRTC Reset event" << formatPSRSuffix();
							break;
						case TIMER_FAIL::RP:
							parsed << formatPSRPrefix("Time") << psr.events_info[i].timestamp << " seconds since Failure event" << formatPSRSuffix();
							break;
						default:
							parsed << formatPSRField("Time", timeToString(psr.genesis_info.genesis_date + psr.events_info[i].timestamp));
							break;
						}
					}
					parsed << "</Category>" << std::endl;
				}
				parsed << "</Category>" << std::endl;

				parsed << "</Category>" << std::endl;
				parsed << "</MsInfo>" << std::endl;
				strPSR = parsed.str();
				return LMS_ERROR::OK;
			}
			CATCH_PSRErrorException(L"PSRGetPlatformServiceRecordCommand")
			CATCH_NoClientExceptionReturn(L"PSRGetPlatformServiceRecordCommand")
			CATCH_MEIClientException(L"PSRGetPlatformServiceRecordCommand")
			CATCH_exception(L"PSRGetPlatformServiceRecordCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetPlatformServiceRecordRaw(std::vector<uint8_t>& binPSR)
		{
			std::array<uint8_t, Intel::MEI_Client::PSR_Client::PSR_NONCE_SIZE> nonce = { 0 };
			std::stringstream parsed;

			try
			{
				Intel::MEI_Client::PSR_Client::PSRGetPlatformServiceRecordRawCommand psrGetPlatformServiceRecordCommand(nonce);
				Intel::MEI_Client::PSR_Client::PSR_GET_RESPONSE_RAW psr = psrGetPlatformServiceRecordCommand.getResponse();

				binPSR.assign(psr.data, psr.data + sizeof(psr.data));

				return LMS_ERROR::OK;
			}
			CATCH_PSRErrorException(L"GetPlatformServiceRecordRaw")
			CATCH_NoClientExceptionReturn(L"GetPlatformServiceRecordRaw")
			CATCH_MEIClientException(L"GetPlatformServiceRecordRaw")
			CATCH_exception(L"GetPlatformServiceRecordRaw")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::GetUPIDFeatureState(bool& state)
		{
			try
			{
				Intel::MEI_Client::UPID_Client::GetUPIDFeatureStateCommand command;
				Intel::MEI_Client::UPID_Client::UPID_PLATFORM_ID_FEATURE_STATE_GET_Response response = command.getResponse();
				state = response.FeatureEnabled;

				return LMS_ERROR::OK;
			}
			CATCH_UPIDErrorException(L"GetUPIDStateCommand")
			CATCH_NoClientExceptionReturn(L"GetUPIDStateCommand")
			CATCH_MEIClientException(L"GetUPIDStateCommand")
			CATCH_exception(L"GetUPIDStateCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::SetUPIDFeatureState(bool state)
		{
			try
			{
				Intel::MEI_Client::UPID_Client::SetUPIDFeatureStateCommand command(state);

				return LMS_ERROR::OK;
			}
			CATCH_UPIDErrorException(L"SetUPIDStateCommand")
			CATCH_NoClientExceptionReturn(L"SetUPIDStateCommand")
			CATCH_MEIClientException(L"SetUPIDStateCommand")
			CATCH_exception(L"SetUPIDStateCommand")
			return LMS_ERROR::FAIL;
		}

		LMS_ERROR PTHI_Commands_BE::SkuMgrQualifiedBrandEntitlements(unsigned int& data)
		{
			try
			{
				Intel::MEI_Client::MCHI_Client::ReadFileExCommand readFileEx(
					Intel::MEI_Client::MCHI_Client::MCA_FILE_ID::SKU_MGR_QUALIFIED_BRAND_ENTITLEMENTS, 0, sizeof(unsigned int), 0);
				Intel::MEI_Client::MCHI_Client::READ_FILE_EX_RESPONSE response = readFileEx.getResponse();
				if (response.Data.size() != sizeof(unsigned int))
				{
					UNS_DEBUG("Data size is wrong %zu != %zu\n", response.Data.size(), sizeof(unsigned int));
					return LMS_ERROR::FAIL;
				}
				uint8_t* p = (uint8_t*)&data;
				std::copy(response.Data.begin(), response.Data.end(), p);
				return LMS_ERROR::OK;
			}
			CATCH_MCHIErrorExceptionAllReturn(L"SkuMgrQualifiedBrandEntitlements")
		}
	}
}
