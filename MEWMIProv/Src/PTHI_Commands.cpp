/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: PTHI_Commands.cpp

--*/

// PTHI_Commands.cpp : Implementation of CPTHI_Commands

#include "stdafx.h"
#include "comutil.h"
#include "AtlConv.h"
#include "winver.h"
#include "ErrorCodes.h"
#include <sstream>
#include "oleauto.h"
#include "comdef.h"
#include "PTHI_Commands.h"
#include "StatusCodeDefinitions.h"
#include "StringManipulator.h"
#include "OpenUserInitiatedConnectionCommand.h"
#include "GetFQDNCommand.h"
#include "CloseUserInitiatedConnectionCommand.h"
#include "GetSecurityParametersCommand.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "GetProvisioningStateCommand.h"
#include "GetZeroTouchEnabledCommand.h"
#include "GetDNSSuffixCommand.h"
#include "GetRemoteAccessConnectionStatusCommand.h"
#include "GetConfigServerDataCommand.h"
#include "GetAMTStateCommand.h"
#include "GetCurrentPowerPolicyCommand.h"
#include "GetCodeVersionCommand.h"
#include "GetFWVersionCommand.h"
#include "GetMESetupAuditRecordCommand.h"
#include "GetWebUIStateCommand.h"
#include "GetRedirectionStateCommand.h"
#include "EnumerateHashHandlesCommand.h"
#include "GetCertificateHashEntryCommand.h"
#include "GetRedirectionSessionsStateCommand.h"
#include "GetTcpipParametersCommand.h"
#include "GetLocalSystemAccountCommand.h"
#include "UnprovisionCommand.h"
#include "DebugPrints.h"
#include "GetKVMSessionStateCommand.h"

#pragma comment (lib,"version")
#pragma comment (lib,"Ws2_32")

// CPTHI_Commands

using namespace Intel::MEI_Client::AMTHI_Client;
using namespace Intel::MEI_Client;

HRESULT IsUserAdmin()
{
	HRESULT  hr = S_OK;
	DWORD dwImp = 0;
	HANDLE hThreadTok = NULL;
	DWORD dwBytesReturned = 0;
	BOOL bRes;

	// You must call this before trying to open a thread token!
	hr = CoImpersonateClient();
	if (hr != S_OK)
	{
		//DBGWARNING(LOCATION, _T("Unable to CoImpersonateClient (0x%x)"), hr);
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		return hr;
	}
	bRes = OpenThreadToken(
		GetCurrentThread(),
		TOKEN_QUERY,
		TRUE,
		&hThreadTok
		);

	if (bRes == FALSE)
	{
		//DBGERROR(LOCATION, _T("Unable to OpenThreadToken (0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	bRes = GetTokenInformation(
		hThreadTok,
		TokenImpersonationLevel,
		&dwImp,
		sizeof(DWORD),
		&dwBytesReturned
		);

	if (!bRes)
	{
		//DBGERROR(LOCATION, _T("Unable to GetTokenInformation - TokenImpersonationLevel(0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}

	if (dwImp!= SecurityImpersonation)
	{
		//DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}



	bRes =::GetTokenInformation(hThreadTok, TokenGroups,
		NULL, 0, &dwBytesReturned);

	if (!bRes && GetLastError() != ERROR_INSUFFICIENT_BUFFER)
	{
		hr = S_FALSE;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	std::vector <uint8_t> groups_vec(dwBytesReturned);
	TOKEN_GROUPS *groups = (TOKEN_GROUPS *)groups_vec.data();

	bRes = ::GetTokenInformation(hThreadTok, TokenGroups,
		groups,
		dwBytesReturned, &dwBytesReturned);
	if (!bRes || dwBytesReturned < sizeof(TOKEN_GROUPS))
	{
		hr = S_FALSE;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	bool isAdmin = false;
	DWORD SidSize;
	PSID AdministratorsSid = NULL;

	SidSize = SECURITY_MAX_SID_SIZE;
	// Allocate enough memory for the largest possible SID.
	if(!(AdministratorsSid = LocalAlloc(LMEM_FIXED, SidSize)))
	{
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}

	// Create a SID on the local computer.
	if(!CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, AdministratorsSid, &SidSize))
	{
		LocalFree(AdministratorsSid);
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return S_FALSE;
	}

	for (DWORD i = 0 ; i < groups->GroupCount; i++)
	{
		if (EqualSid(groups->Groups[i].Sid,AdministratorsSid))
		{
			isAdmin = true;
			break;
		}
	}
	////////////////////
	LocalFree(AdministratorsSid);
	CloseHandle(hThreadTok);

	hr = CoRevertToSelf();
	if (hr != S_OK)
	{
		//DBGERROR(LOCATION, _T("CoRevertToSelf (0x%x)"), hr);
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		return hr;
	}

	if (!isAdmin)
		hr = S_FALSE;


	return hr;
}

HRESULT getApplicationDetails(std::string& userNameStr, std::string& domainNameStr, std::string& applicationName)
{
	HRESULT  hr = S_OK;
	DWORD dwImp = 0;
	HANDLE hThreadTok = NULL;
	DWORD dwBytesReturned;
	BOOL bRes;
	char* userName;
	char* domainName;
	DWORD userNameSize = 1, domainNameSize = 1;
	SID_NAME_USE eUse = SidTypeUnknown;


	// You must call this before trying to open a thread token!
	hr = CoImpersonateClient();
	if (hr != S_OK)
	{
		//DBGWARNING(LOCATION, _T("Unable to CoImpersonateClient (0x%x)"), hr);
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		return hr;
	}
	bRes = OpenThreadToken(
		GetCurrentThread(),
		TOKEN_QUERY,
		TRUE,
		&hThreadTok
		);

	if (bRes == FALSE)
	{
		//DBGERROR(LOCATION, _T("Unable to OpenThreadToken (0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	bRes = GetTokenInformation(
		hThreadTok,
		TokenImpersonationLevel,
		&dwImp,
		sizeof(DWORD),
		&dwBytesReturned
		);

	if (!bRes)
	{
		//DBGERROR(LOCATION, _T("Unable to GetTokenInformation - TokenImpersonationLevel(0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}

	if (dwImp!= SecurityImpersonation)
	{
		//DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}

	bRes =::GetTokenInformation(hThreadTok, TokenUser,
		NULL, 0, &dwBytesReturned);

	if (!bRes && GetLastError() != ERROR_INSUFFICIENT_BUFFER)
	{
		hr = S_FALSE;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	std::vector<TOKEN_USER> user_vec;
	user_vec.reserve(dwBytesReturned);
	TOKEN_USER *user = user_vec.data();

	bRes = ::GetTokenInformation(hThreadTok, TokenUser,
		user, dwBytesReturned, &dwBytesReturned);
	if (!bRes || dwBytesReturned < sizeof(TOKEN_USER))
	{
		hr = S_FALSE;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	//first call to get the buffer suzes
	bRes = ::LookupAccountSid(NULL, user->User.Sid, NULL, (LPDWORD)&userNameSize, NULL, (LPDWORD)&domainNameSize, &eUse);
	if (!bRes)
	{
		hr = S_FALSE;
		CloseHandle(hThreadTok);
		CoRevertToSelf();
		return hr;
	}

	userName = (char *)GlobalAlloc(
           GMEM_FIXED,
		   userNameSize);
	if (userName == NULL) {
          //DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;
	}

        domainName = (char *)GlobalAlloc(GMEM_FIXED, domainNameSize);

    // Check GetLastError for GlobalAlloc error condition.
    if (domainName == NULL) {
          //DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		GlobalFree( userName );
		CloseHandle(hThreadTok);
		CoRevertToSelf () ;
		return hr;

    }
	//second call to get the userNAme and domain
	bRes = ::LookupAccountSidA(NULL, user->User.Sid, userName, (LPDWORD)&userNameSize, domainName, (LPDWORD)&domainNameSize, &eUse);
	userNameStr.assign(userName);
	domainNameStr.assign(domainName);

	GlobalFree(userName);
	GlobalFree(domainName);
	CloseHandle(hThreadTok);

	hr = CoRevertToSelf();
	if (hr != S_OK)
	{
		//DBGERROR(LOCATION, _T("CoRevertToSelf (0x%x)"), hr);
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		return hr;
	}

	return hr;
}

unsigned int PTHI_Commands::GetAMTFQDN(std::wstring* amtFQDN)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetFQDNCommand command;
		GET_FQDN_RESPONSE response = command.getResponse();
		*amtFQDN = UTF8ToWStr(response.FQDN);
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetFQDNCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetFQDNCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetFQDNCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::OpenCIRA(void)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		OpenUserInitiatedConnectionCommand command;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("OpenUserInitiatedConnectionCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("OpenUserInitiatedConnectionCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in OpenUserInitiatedConnectionCommand %C\n", e.what());
	}
	return rc;
}

unsigned int PTHI_Commands::CloseCIRA(void)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		CloseUserInitiatedConnectionCommand command;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("CloseUserInitiatedConnectionCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("CloseUserInitiatedConnectionCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in CloseUserInitiatedConnectionCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetTLSEnabled(bool* enabled)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetSecurityParametersCommand command;
		SECURITY_PARAMETERS response = command.getResponse();
		*enabled = response.TLSEnabled;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetSecurityParametersCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetSecurityParametersCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetSecurityParametersCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::isWiredLinkUp(bool* enabled)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetLanInterfaceSettingsCommand command(WIRED);
		LAN_SETTINGS response = command.getResponse();
		*enabled = (response.LinkStatus == 1);
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetLanInterfaceSettingsCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetLanInterfaceSettingsCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetProvisioningState(SHORT* pProvisioningState)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetProvisioningStateCommand command;
		CFG_PROVISIONING_STATE response = command.getResponse();
		*pProvisioningState = (SHORT)response.ProvisioningState;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetProvisioningStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetProvisioningStateCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetProvisioningStateCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::isRemoteConfigEnabled(bool* enabled)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetZeroTouchEnabledCommand command;
		*enabled = command.getResponse().ZTCEnabled;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetZeroTouchEnabledCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetZeroTouchEnabledCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetZeroTouchEnabledCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetProvisioningInfo(std::wstring* pPKIDNSSuffix, std::wstring* pConfigServerFQDN)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetDNSSuffixCommand command;
		GetConfigServerDataCommand confServerCommand;
		(*pConfigServerFQDN) = ToWStr(confServerCommand.getResponse().FQDN);
		(*pPKIDNSSuffix) = ToWStr(command.getResponse());
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("AMTHICommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("AMTHICommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in AMTHICommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetRemoteAccessConnectionStatus(SHORT* ConnectionTrigger, SHORT* NetworkConStatus, std::wstring* MPshostName, SHORT* RemoteAccessConStatus )
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetRemoteAccessConnectionStatusCommand command;
		REMOTE_ACCESS_STATUS response = command.getResponse();
		*ConnectionTrigger = response.RemoteAccessConnectionTrigger;
		*NetworkConStatus = response.AmtNetworkConnectionStatus;
		*MPshostName = ToWStr(response.MpsHostname);
		*RemoteAccessConStatus = response.RemoteAccessConnectionStatus;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetRemoteAccessConnectionStatusCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetRemoteAccessConnectionStatusCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetRemoteAccessConnectionStatusCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetConfigServerData(std::wstring* Address, unsigned short* port)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetConfigServerDataCommand command;
		CFG_GET_CONFIG_SERVER_DATA_RESPONSE response = command.getResponse();
		*Address = ToWStr(response.ServerAddr.c_str());
		if ((Address->compare(L"0.0.0.0") || Address->compare(L"::0")) && response.FQDN.length() > 0)
		{
			*Address = ToWStr(response.FQDN);
		}
		*port = response.ServerPort;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetConfigServerDataCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetConfigServerDataCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetConfigServerDataCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetAMTState(unsigned int* LastMEResetReason, bool *cryptoFuseEnabled)
{
/*
AMT_STATUS_NOT_READY	AMT device has not progressed far enough in its initialization to process the command.
AMT_STATUS_INVALID_AMT_MODE	Command is not permitted in current operating mode.
AMT_STATUS_INVALID_MESSAGE_LENGTH	Length field of header is invalid.
AMT_STATUS_UNSUPPORTED_OBJECT	StateDataIdentifier is not recognized or not supported by the AMT device.

*/

	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;

	try {
		GetAMTStateCommand command;
		AMT_STATE_RESPONSE response = command.getResponse();
		*LastMEResetReason = response.StateData.Fields.LastMEResetType;
		*cryptoFuseEnabled = !(response.StateData.Fields.CryptoFuse==0);
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetAMTState failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetAMTState failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetAMTState %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetPowerPolicy(std::wstring* policy)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetCurrentPowerPolicyCommand command;
		*policy = ToWStr(command.getResponse());
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetPowerPolicy failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetPowerPolicy failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetPowerPolicy %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetAMTVersion(std::wstring* AMTVersion)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetCodeVersionCommand command;
		CODE_VERSIONS response = command.getResponse();
		std::vector<AMT_VERSION_TYPE>::iterator itr = response.Versions.begin();
		std::vector<AMT_VERSION_TYPE>::iterator endItr = response.Versions.end();
		for (; itr != endItr ; ++itr)
		{
			if (itr->Description.compare("AMT") == 0)
			{
				*AMTVersion=ToWStr(itr->Version.c_str());
				rc = 0;
				break;
			}
		}
		if (rc == 0)
		{
			for (itr = response.Versions.begin(); itr != endItr ; ++itr)
			{
				if (itr->Description.compare("Build Number") == 0)
				{
					AMTVersion->append(L".");
					AMTVersion->append(itr->Version.begin(), itr->Version.end());
				}
			}
		}
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetCodeVersionCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetCodeVersionCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetCodeVersionCommand %C\n", e.what());
	}

	if (rc != 0)
	{
		try
		{
			Intel::MEI_Client::MKHI_Client::GetFWVersionCommand command;
			Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE response = command.getResponse();
			std::wstringstream strStream(std::wstringstream::in | std::wstringstream::out);
			strStream << response.FTMajor << L"." << response.FTMinor << L"." <<
				response.FTHotFix << L"." << response.FTBuildNo;
			strStream >> *AMTVersion;
			rc = S_OK;
		}
		catch (MEIClientException& e)
		{
			UNS_ERROR("FWUGetVersionCommand failed %C\n", e.what());
		}
		catch (std::exception& e)
		{
			UNS_ERROR("Exception in FWUGetVersionCommand %C\n", e.what());
		}
	}

	return rc;
}

std::wstring CFG_IPv4_ADDRESStowstring(unsigned int IP)
{
	WCHAR wsip[50];
	swprintf_s(wsip,50,L"%d.%d.%d.%d",(IP >> 24)&0xff, (IP >> 16)&0xff, (IP >> 8)&0xff, IP &0xff);
	return wsip;
}

unsigned char PTHI_Commands::SetProvisioningTLSModeValues(unsigned char provTLSMode)
{
	if (provTLSMode == 0)
		return 1;
	if (provTLSMode == 1)
		return 2;
	return 0;
}

unsigned int PTHI_Commands::GetMESetupAudit(MEAdminAudit *MEAudit)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;

	try {
		GetMESetupAuditRecordCommand command;
		GetMESetupAuditRecord_RESPONSE response = command.getResponse();

		MEAudit->ProvisioningTLSMode = SetProvisioningTLSModeValues(response.ProvisioningTLSMode);
		MEAudit->SecureDNS = response.SecureDNS;
		MEAudit->HostInitiated = response.HostInitiated;
		MEAudit->SelectedHashType = response.SelectedHashType;
		for (size_t i = 0; i < sizeof(response.SelectedHashData.SelectedHashData)/sizeof(response.SelectedHashData.SelectedHashData[0]); i++)
			MEAudit->SelectedHashData.push_back( response.SelectedHashData.SelectedHashData[i]);
		for (size_t i = 0; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH; i++)
			MEAudit->CACertificateSerial1.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		for (size_t i = NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*2; i++)
			MEAudit->CACertificateSerial2.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		for (size_t i = NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*2; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*3; i++)
			MEAudit->CACertificateSerial3.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		MEAudit->AdditionalCaSerialNums = response.AdditionalCaSerialNums;
		MEAudit->IsOemDefault = response.IsOemDefault;
		MEAudit->IsTimeValid = response.IsTimeValid;
		MEAudit->ProvServerIP = ToWStr(response.ProvServerIP);
		MEAudit->ProvServerFQDN = ToWStr(response.ProvServerFQDN);
		MEAudit->TlsStartTime.Day = response.TlsStartTime.Day;
		MEAudit->TlsStartTime.DayOfWeek = response.TlsStartTime.DayOfWeek;
		MEAudit->TlsStartTime.Hour = response.TlsStartTime.Hour;
		MEAudit->TlsStartTime.Minute = response.TlsStartTime.Minute;
		MEAudit->TlsStartTime.Month = response.TlsStartTime.Month;
		MEAudit->TlsStartTime.Second = response.TlsStartTime.Second;
		MEAudit->TlsStartTime.Year = response.TlsStartTime.Year;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetMESetupAuditRecordCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetMESetupAuditRecordCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetMESetupAuditRecordCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::getWebUIState(SHORT* pState)
{
	/*
	AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
	*/

	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetWebUIStateCommand command;
		GET_WEB_UI_STATE_RESPONSE response = command.getResponse();
		*pState = response.WebUiEnabled;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetWebUIStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetWebUIStateCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetWebUIStateCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetRedirectionStatus(SHORT* pSOL, SHORT* pIDER)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetRedirectionSessionsStateCommand command;
		GET_REDIRECTION_SESSIONS_STATE_RESPONSE response = command.getResponse();
		*pSOL = response.SolOpen;
		*pIDER = response.IderOpen;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetWebUIStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetWebUIStateCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetWebUIStateCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetCertificateHash(std::vector<HashEntry> &hashlist)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		EnumerateHashHandlesCommand command;
		ENUMERATE_HASH_HANDLES_RESPONSE response = command.getResponse();
		std::vector<unsigned int>::iterator itr = response.HashHandles.begin();
		std::vector<unsigned int>::iterator endItr = response.HashHandles.end();
		for (; itr != endItr; ++itr)
		{
			try {
				GetCertificateHashEntryCommand command(*itr);
				GET_CERTIFICATE_HASH_ENTRY_RESPONSE response = command.getResponse();
				HashEntry entry;
				entry.Description = ToWStr(response.Name);
				entry.IsDefault = response.IsDefault;
				entry.Enabled = response.IsActive;
				entry.HashType = response.HashAlgorithm;
				memcpy_s(entry.HashData, sizeof(entry.HashData), response.CertificateHash, sizeof(response.CertificateHash));
				hashlist.push_back(entry);
			}
			catch (AMTHIErrorException& e)
			{
				UNS_ERROR("GetCertificateHashEntryCommand failed ret=%d\n", e.getErr());
				rc = e.getErr();
			}
			catch (MEIClientException& e)
			{
				UNS_ERROR("GetCertificateHashEntryCommand failed %C\n", e.what());
			}
			catch (std::exception& e)
			{
				UNS_ERROR("Exception in GetCertificateHashEntryCommand %C\n", e.what());
			}
		}
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("EnumerateHashHandlesCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("EnumerateHashHandlesCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in EnumerateHashHandlesCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetKVMSessionActivation(bool* activated)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try
	{
		GetKVMSessionStateCommand command;
		GET_KVM_SESSION_STATE_RESPONSE response = command.getResponse();
		if (response.kvmStatus.KvmSessionIsActive)
			*activated = true;
		else
			*activated = false;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetKVMSessionActivation failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetKVMSessionActivation failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetKVMSessionActivation %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetRedirectionState(bool *pSolEnable, bool *pIDEREnabled, bool *pKVMEnabled)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetRedirectionStateCommand command;
		REDIRECTION_STATE response = command.getResponse();
		*pSolEnable = response.SOLEnabled;
		*pIDEREnabled = response.IDEREnabled;
		*pKVMEnabled = response.KVMEnabled;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetRedirectionState failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetRedirectionState failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetRedirectionState %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetPortSettings(std::vector<EthernetPortEntry> &ethernetPortList)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetTcpipParametersCommand TcpIPparametersCommand;
		TCPIP_PARAMETERS TCPIPparametersResponse = TcpIPparametersCommand.getResponse();
		EthernetPortEntry entry;
		entry.IPAddress = CFG_IPv4_ADDRESStowstring(TCPIPparametersResponse.LocalAddress);
		entry.PrimaryDNS = CFG_IPv4_ADDRESStowstring(TCPIPparametersResponse.PrimaryDnsAddress);
		entry.SecondaryDNS = CFG_IPv4_ADDRESStowstring(TCPIPparametersResponse.SecondaryDnsAddress);
		entry.SubnetMask = CFG_IPv4_ADDRESStowstring(TCPIPparametersResponse.SubnetMask);
		entry.DefaultGateway = CFG_IPv4_ADDRESStowstring(TCPIPparametersResponse.DefaultGatewayAddress);
		try {
			GetLanInterfaceSettingsCommand lanInterfaceCommand(WIRED);
			LAN_SETTINGS lanSettings = lanInterfaceCommand.getResponse();
			WCHAR sMacAddress[50];
			swprintf_s(sMacAddress, 50, L"%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
				lanSettings.MacAddress[0], lanSettings.MacAddress[1], lanSettings.MacAddress[2],
				lanSettings.MacAddress[3], lanSettings.MacAddress[4], lanSettings.MacAddress[5]);
			entry.MACAddress = sMacAddress;
			entry.LinkIsUp = (lanSettings.LinkStatus == 1) ? true : false;
			entry.DHCPEnabled = lanSettings.DhcpEnabled;
			ethernetPortList.push_back(entry);
			rc = 0;
		}
		catch (AMTHIErrorException& e)
		{
			UNS_ERROR("GetLanInterfaceSettingsCommand failed ret=%d\n", e.getErr());
			rc = e.getErr();
		}
		catch (MEIClientException& e)
		{
			UNS_ERROR("GetLanInterfaceSettingsCommand failed %C\n", e.what());
		}
		catch (std::exception& e)
		{
			UNS_ERROR("Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
		}
		if (rc != 0)
		{
			try {
				GetLanInterfaceSettingsCommand lanInterfaceCommand(WIRELESS);
				LAN_SETTINGS lanSettings = lanInterfaceCommand.getResponse();
				WCHAR sMacAddress[50];
				swprintf_s(sMacAddress, 50, L"%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
					lanSettings.MacAddress[0], lanSettings.MacAddress[1], lanSettings.MacAddress[2],
					lanSettings.MacAddress[3], lanSettings.MacAddress[4], lanSettings.MacAddress[5]);
				entry.MACAddress = sMacAddress;
				entry.LinkIsUp = (lanSettings.LinkStatus == 1) ? true : false;
				entry.DHCPEnabled = lanSettings.DhcpEnabled;
				ethernetPortList.push_back(entry);
				rc = 0;
			}
			catch (AMTHIErrorException& e)
			{
				UNS_ERROR("GetLanInterfaceSettingsCommand failed ret=%d\n", e.getErr());
				rc = e.getErr();
			}
			catch (MEIClientException& e)
			{
				UNS_ERROR("GetLanInterfaceSettingsCommand failed %C\n", e.what());
			}
			catch (std::exception& e)
			{
				UNS_ERROR("Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
			}
		}
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetTcpipParametersCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetTcpipParametersCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetTcpipParametersCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetLocalSystemAccount(LOCAL_SYSTEM_ACCOUNT *LocalAccount)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetLocalSystemAccountCommand command;
		GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE response = command.getResponse();
		LocalAccount->UserName = response.UserName;

		if (response.Password.length() < CFG_MAX_ACL_PWD_LENGTH)
		{
			LocalAccount->Password = response.Password;
		}
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetLocalSystemAccountCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetLocalSystemAccountCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetLocalSystemAccountCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::Unprovision()
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		UnprovisionCommand command(CFG_PROVISIONING_MODE_NONE);
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetLocalSystemAccountCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetLocalSystemAccountCommand failed %C\n",e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetLocalSystemAccountCommand %C\n", e.what());
	}

	return rc;
}
