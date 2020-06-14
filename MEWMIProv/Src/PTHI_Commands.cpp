/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
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
#include "GetProvisioningTlsModeCommand.h"
#include "GetSecurityParametersCommand.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "GetProvisioningModeCommand.h"
#include "GetProvisioningStateCommand.h"
#include "GetPIDCommand.h"
#include "GetZeroTouchEnabledCommand.h"
#include "GetDNSSuffixCommand.h"
#include "GetRemoteAccessConnectionStatusCommand.h"
#include "GetConfigServerDataCommand.h"
#include "GetAMTStateCommand.h"
#include "GetCurrentPowerPolicyCommand.h"
#include "StopConfigurationCommand.h"
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
#include "SetDNSSuffixCommand.h"
#include "SetProvisioningServerOTPCommand.h"
#include "StartConfigurationExCommand.h"
#include "MNGIsChangeToAMTEnabledCommand.h"
#include "MNGChangeToAMTCommand.h"
#include "DebugPrints.h"
#include "GetKVMSessionStateCommand.h"
#include "CryptUtils_w.h"

#pragma comment (lib,"version")
#pragma comment (lib,"Ws2_32")

// CPTHI_Commands

#define MAX_BUFFER_LENGTH  256

using namespace Intel::MEI_Client::AMTHI_Client;
using namespace Intel::MEI_Client::Manageability_Client;
using namespace Intel::MEI_Client;


HRESULT IsUserAdmin()
{
	HRESULT  hr = S_OK;
	DWORD dwImp = 0;
	HANDLE hThreadTok = NULL;
	DWORD dwBytesReturned;
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

	TOKEN_GROUPS * groups;

	groups =(TOKEN_GROUPS*) new unsigned char[dwBytesReturned];

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

	for (WORD i= 0 ; i < groups->GroupCount; i++)
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

HRESULT getApplicationDetails(string& userNameStr, string& domainNameStr, string& applicationName)
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

	TOKEN_USER * user;

	user =(TOKEN_USER*) new unsigned char[dwBytesReturned];

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
	USES_CONVERSION;

	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetFQDNCommand command;
		GET_FQDN_RESPONSE response = command.getResponse();
		(*amtFQDN) = ToWStr(response.FQDN);
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetFQDNCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::OpenCIRA(void)
{
	//if (CheckCredentials(_T("OpenCIRA")) != S_OK)
	//	return E_ACCESSDENIED;


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
	catch (exception& e)
	{
		UNS_ERROR("Exception in OpenUserInitiatedConnectionCommand %C\n", e.what());
	}
	return rc;
}

unsigned int PTHI_Commands::CloseCIRA(void)
{
	//if (CheckCredentials(_T("CloseCIRA")) != S_OK)
	//	return E_ACCESSDENIED;


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
	catch (exception& e)
	{
		UNS_ERROR("Exception in CloseUserInitiatedConnectionCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetProvisioningTlsMode(SHORT* pProvisioningTlsMode)
{

	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetProvisioningTLSModeCommand command;
		PROV_TLS_MODE_RESPONSE response = command.getResponse();
		*pProvisioningTlsMode = response.ProvTLSMode;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetProvisioningTlsModeCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetProvisioningTlsModeCommand failed %C\n",e.what());
	}
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetProvisioningTlsModeCommand %C\n", e.what());
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetSecurityParametersCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::isWiredLinkUp(bool* enabled)
{
	//char str[256];


	// TODO: Add your implementation code here
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetProvisioningMode(unsigned char& mode)
{

	//bool isNullBufferReceived;
//	AMT_BOOLEAN legacy;
	// TODO: Add your implementation code here
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetProvisioningModeCommand command;
		PROVISIONING_MODE_SETTINGS response = command.getResponse();
		mode = (unsigned char)response.ProvisioningMode;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetProvisioningModeCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetProvisioningModeCommand failed %C\n",e.what());
	}
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetProvisioningModeCommand %C\n", e.what());
	}

	return rc;
}

UINT PTHI_Commands::GetProvisioningState(SHORT* pProvisioningState)
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetProvisioningStateCommand %C\n", e.what());
	}

	return rc;
}

UINT PTHI_Commands::GetPID(wstring* pPID)
{
	USES_CONVERSION;


	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetPIDCommand command;
		GET_PID_RESPONSE response = command.getResponse();
		wchar_t PID[50];
		swprintf(PID,50,L"%c%c%c%c-%c%c%c%c",
			response.pid[0],response.pid[1],response.pid[2],response.pid[3],response.pid[4],
			response.pid[5],response.pid[6],response.pid[7]);
		pPID->assign(PID);
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("GetPIDCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetPIDCommand failed %C\n",e.what());
	}
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetPIDCommand %C\n", e.what());
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetZeroTouchEnabledCommand %C\n", e.what());
	}

	return rc;
}


unsigned int PTHI_Commands::GetProvisioningInfo(wstring* pPKIDNSSuffix, wstring* pConfigServerFQDN)
{
	USES_CONVERSION;


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
	catch (exception& e)
	{
		UNS_ERROR("Exception in AMTHICommand %C\n", e.what());
	}


	return rc;
}

unsigned int PTHI_Commands::GetRemoteAccessConnectionStatus(SHORT* ConnectionTrigger, SHORT* NetworkConStatus, std::wstring* MPshostName, SHORT* RemoteAccessConStatus )
{
	USES_CONVERSION;


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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetRemoteAccessConnectionStatusCommand %C\n", e.what());
	}

	return rc;
}


/*
 * Calls to Activate AMT configuration.
 * Arguments:
 *	param - Local agent parameters structure
 * Return values:
 *	PT_STATUS_SUCCESS - on success for get amt configuration data
 *	appropriate error value defined in StatusCodeDefinitions.h - on failure
 */
unsigned int Activate(LOCAL_AGENT_PARAMS param, bool alreadyActivated, SHORT* provTlsMode)
{
	unsigned int status = 0;
	bool ztcEnabled;
	ProvTLSMode_t provisioningTlsMode;

	CFG_PROVISIONING_STATE provstate;
//	bool isNullBufferReceived;
	bool isDNSSet = false;
	bool isOTPSet = false;
	bool setDNSOrOTPWhileAmtActivated = false;
	string lastFunction;

	try
	{
	do {
		// ZTC enabled
		lastFunction = "GetZeroTouchEnabledCommand";
		GetZeroTouchEnabledCommand zeroTouchCommand;
		ztcEnabled = zeroTouchCommand.getResponse().ZTCEnabled;
		if(!ztcEnabled && 0!= param.OneTimePassword.length())
		{
			status = AMT_STATUS_INVALID_PT_MODE;
			break;
		}
		// Get provisioning TLS mode
		lastFunction = "GetProvisioningTLSModeCommand";
		GetProvisioningTLSModeCommand provTLSCommand;
		provisioningTlsMode = provTLSCommand.getResponse().ProvTLSMode;


		*provTlsMode = static_cast<SHORT>(provisioningTlsMode);
		if(PSK == provisioningTlsMode && 0!= param.OneTimePassword.length())
		{
			status = PTSDK_STATUS_INVALID_PARAM;
			break;
		}
		if(PSK != provisioningTlsMode && ztcEnabled )
		{
			if(0 != param.DnsSuffix.length())
			{
				lastFunction = "SetDNSSuffixCommand";
				SetDNSSuffixCommand setDNSSuffixCommand(param.DnsSuffix);
				lastFunction = "GetDNSSuffixCommand";
				GetDNSSuffixCommand getDNSSuffixCommand;
				string tempDnsSuffix = getDNSSuffixCommand.getResponse();

				if (tempDnsSuffix.compare(param.DnsSuffix) != 0)
				{
					status=AMT_STATUS_INTERNAL_ERROR;
					UNS_ERROR("Error: SetDNSSuffix Failed\n");
					break;
				}
				isDNSSet = true;
			}
			if(0 != param.OneTimePassword.length())
			{
				lastFunction = "SetProvisioningServerOTPCommand";
				SetProvisioningServerOTPCommand setOTPCommand(param.OneTimePassword);
				isOTPSet = true;
			}
		}

		if (!alreadyActivated)
		{
			try{
				lastFunction = "StartConfigurationExCommand";
				StartConfigurationExCommand startConfCommand(param.EnableIPv6);
			}
			catch (AMTHIErrorException& e)
			{
				status = e.getErr();
			}
			if(AMT_STATUS_SUCCESS != status && AMT_STATUS_CERTIFICATE_NOT_READY != status)
			{
				// This code deals with the situation that AMT is already activated
				// (so the StartConfiguration fails) but the DNS or OTP were set:
				// In this case we want to expose a positive message to the user
				// indicating the success of the DNS or OTP set
				if ((PT_STATUS_INVALID_PT_MODE == status) && (isDNSSet || isOTPSet))
				{
					setDNSOrOTPWhileAmtActivated = true;
					status = AMT_STATUS_SUCCESS;
				}
				break;
			}
			else if(AMT_STATUS_CERTIFICATE_NOT_READY == status)
			{
				if(PSK == provisioningTlsMode)
				{
					break;
				}
				else
				{
					for(int i = 0; i < 20; i++)
					{
						Sleep(30000);
						// provisioning state
						try {
							GetProvisioningStateCommand getProvStateCommand;
							provstate = getProvStateCommand.getResponse();
							break;
						}
						catch (...)
						{
							UNS_ERROR("Error: StartConfiguration Failed\n");
						}
					}
					if(AMT_STATUS_SUCCESS  == status && PROVISIONING_STATE_IN != provstate.ProvisioningState)
					{
						status = AMT_STATUS_INVALID_PROVISIONING_STATE;
						break;
					}
				}
			}
		}

	}while(0);
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("%C failed ret=%d\n", lastFunction, e.getErr());
		status = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("%C failed %C\n",lastFunction, e.what());
		status = AMT_STATUS_INTERNAL_ERROR;
	}
	catch (exception& e)
	{
		UNS_ERROR("Exception in %C %C\n",lastFunction, e.what());
		status = AMT_STATUS_INTERNAL_ERROR;
	}

	if (!setDNSOrOTPWhileAmtActivated)
	{
		if(AMT_STATUS_SUCCESS == status)
		{
			UNS_DEBUG("AMT Config Activate Succeeded\n");
		}
		else
		{
			UNS_ERROR("AMT Config Activate Failed\n");
		}
	}
	return status;
}

/*
 * Calls to DiscoveryTest for check AMT configuration.
 * Arguments:
 *	isActivate - if this test running for start amt configuration
 * Return values:
 *	AMT_STATUS_SUCCESS - on success for get amt configuration data
 *	appropriate error value defined in StatusCodeDefinitions.h - on failure
 */
unsigned int PTHI_Commands::DiscoveryTest(bool isActivate, bool & alreadyActivated)
{
	unsigned int  status = AMT_STATUS_SUCCESS ;
    bool isReinit = false;
	bool isNullBufferReceived = false;
	// In order to know if the mode is not AMT (i.e. NONE or ASF), basic commands like
	//	GetProvisioningMode should return with null buffer.
	try {
		GetProvisioningStateCommand provisioningStateCommand;
	}
	catch (const MEIClientExceptionZeroBuffer&)
	{
		if(!isActivate)
		{
			return status;
		}
		status= ChangeToAMT();
		if (status == AMT_STATUS_SUCCESS)
		{
			Sleep(CHANGE_TO_AMT_TIMEOUT);
		}
		else
		{
			UNS_ERROR("Error: ChangeToAMT Failed with status %C\n", status);
			return status;
		}
	}
	catch (const MEIClientException& e)
	{
		UNS_ERROR("GetProvisioningStateCommand failed %C\n", e.what());
	}
	//It may take the AMTHI time to work after ChangeToAMTSucceeds
	for(int i = 0; i < 12; i++)
    {
		try {
			GetCodeVersionCommand getCodeVersionCommand;
			getCodeVersionCommand.getResponse(); // There was a version parsing and usage here, but removed
			return status;
		}
		catch (AMTHIErrorException& e)
		{
			//in case reached here the AMTHI engine in the FW works and other problem ocured - so, no need to continue try
			UNS_ERROR("GetCodeVersionCommand failed ret=%d\n", e.getErr());
			status = e.getErr();
			return status;
		}
		catch (MEIClientException& e)
		{
			UNS_ERROR("GetCodeVersionCommand failed %C\n", e.what());
		}
		catch (exception& e)
		{
			UNS_ERROR("Exception in GetCodeVersionCommand %C\n", e.what());
		}

		Sleep(5000);

    }

	status = AMT_STATUS_INTERNAL_ERROR;

	UNS_ERROR("Error: ChangeToAMT Failed \n");


    return status;
}

unsigned int PTHI_Commands::ZTCActivate(std::string OTP, std::string PKIDNSSuffix, SHORT* provTLSMode)
{
	//if (CheckCredentials(_T("OpenCIRA")) != S_OK)
	//	return E_ACCESSDENIED;


	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;

		char str[256];
		LOCAL_AGENT_PARAMS param;
		memset(&param,0,sizeof(LOCAL_AGENT_PARAMS));
		bool alreadyActivated = false;
		param.OneTimePassword = OTP;
		param.DnsSuffix = PKIDNSSuffix;
		param.Activate = true;

		rc = DiscoveryTest(param.Activate, alreadyActivated);
		if(AMT_STATUS_SUCCESS == rc && param.Activate)
		{
			if ((rc=Activate(param, alreadyActivated, provTLSMode))==0)
			{
				sprintf(str,"Activate succeed\n");
				rc= S_OK;
			}
			else
				sprintf(str,"Activate failed ret=%d\n",rc);
		}
		else
			sprintf(str,"DiscoveryTest return ret=%d param.Activate=%d\n",rc,param.Activate);
		OutputDebugStringA(str);

	return rc;
}

unsigned int PTHI_Commands::GetConfigServerData(wstring* Address, unsigned short* port)
{
	USES_CONVERSION;


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
	catch (exception& e)
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
//	int ret;

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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetAMTState %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetPowerPolicy(wstring* policy)
{
	USES_CONVERSION;

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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetPowerPolicy %C\n", e.what());
	}

	return rc;
}
/*
 * Change SKU to AMT
 */
unsigned int PTHI_Commands::ChangeToAMT()
{
	unsigned int status = AMT_STATUS_SUCCESS;
	string lastFunction ="";
	try {
		lastFunction = "MNGIsChangeToAMTEnabledCommand";
		MNGIsChangeToAMTEnabledCommand isChangedToAMTCommand;
		IsChangedEnabledResponse isChangedResponse = isChangedToAMTCommand.getResponse();

		if (isChangedResponse.Enabled)
		{
			lastFunction = "MNGChangeToAMTCommand";
			MNGChangeToAMTCommand changeToAMTCommand;
			status = changeToAMTCommand.getResponse().Status;
			UNS_DEBUG("MNGChangeToAMTCommand status returned is %d\n", status);
		}
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("%C failed %C\n", lastFunction, e.what());
		status = E_FAIL;
	}


	catch (exception& e)
	{
		UNS_ERROR("Exception in %C %C\n", lastFunction, e.what());
		status = E_FAIL;
	}


	return status;
}

unsigned int PTHI_Commands::StopConfiguration(void)
{

	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		StopConfigurationCommand command;
		rc = 0;
	}
	catch (AMTHIErrorException& e)
	{
		UNS_ERROR("StopConfigurationCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("StopConfigurationCommand failed %C\n",e.what());
	}
	catch (exception& e)
	{
		UNS_ERROR("Exception in StopConfigurationCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetAMTVersion(std::wstring* AMTVersion, unsigned int* sku)
{
	USES_CONVERSION;


	// TODO: Add your implementation code here
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		GetCodeVersionCommand command;
		CODE_VERSIONS response = command.getResponse();
		vector<AMT_VERSION_TYPE>::iterator itr = response.Versions.begin();
		vector<AMT_VERSION_TYPE>::iterator endItr = response.Versions.end();
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
				if (itr->Description.compare("Sku") == 0)
				{
					*sku = atoi(itr->Version.c_str());
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetCodeVersionCommand %C\n", e.what());
	}

	if (rc != 0)
	{
		try
		{
			Intel::MEI_Client::MKHI_Client::GetFWVersionCommand command;
			Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE response = command.getResponse();
			wstringstream strStream(wstringstream::in | wstringstream::out);
			strStream << response.FTMajor << L"." << response.FTMinor << L"." <<
				response.FTHotFix << L"." << response.FTBuildNo;
			strStream >> *AMTVersion;
			rc = S_OK;
		}
		catch (MEIClientException& e)
		{
			UNS_ERROR("FWUGetVersionCommand failed %C\n", e.what());
		}
		catch (exception& e)
		{
			UNS_ERROR("Exception in FWUGetVersionCommand %C\n", e.what());
		}
	}

	return rc;
}

wstring  CFG_IPv4_ADDRESStowstring(unsigned int IP)
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
	USES_CONVERSION;
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;

	try {
		GetMESetupAuditRecordCommand command;
		GetMESetupAuditRecord_RESPONSE response = command.getResponse();

		MEAudit->ProvisioningTLSMode = SetProvisioningTLSModeValues(response.ProvisioningTLSMode);
		MEAudit->SecureDNS = response.SecureDNS;
		MEAudit->HostInitiated = response.HostInitiated;
		MEAudit->SelectedHashType = response.SelectedHashType;
		for (int i=0; i < sizeof(response.SelectedHashData.SelectedHashData)/sizeof(response.SelectedHashData.SelectedHashData[0]); i++)
			MEAudit->SelectedHashData.push_back( response.SelectedHashData.SelectedHashData[i]);
		for (int i=0; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH; i++)
			MEAudit->CACertificateSerial1.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		for (int i=NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*2; i++)
			MEAudit->CACertificateSerial2.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		for (int i=NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*2; i < NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH*3; i++)
			MEAudit->CACertificateSerial3.push_back( response.CaCertificateSerials.CaCertificateSerials[i]);
		MEAudit->AdditionalCaSerialNums = response.AdditionalCaSerialNums;
		MEAudit->IsOemDefault = response.IsOemDefault;
		MEAudit->IsTimeValid = response.IsTimeValid;
		MEAudit->ProvServerIP = ToWStr(response.ProvServerIP);
		//MEAudit->ProvServerIP = CFG_IPv4_ADDRESStowstring(response.ProvServerIP);
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
	catch (exception& e)
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
	catch (exception& e)
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetWebUIStateCommand %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetCertificateHash(vector<HashEntry> &hashlist)
{
	USES_CONVERSION;
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		EnumerateHashHandlesCommand command;
		ENUMERATE_HASH_HANDLES_RESPONSE response = command.getResponse();
		vector<unsigned int>::iterator itr = response.HashHandles.begin();
		vector<unsigned int>::iterator endItr = response.HashHandles.end();
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
			catch (exception& e)
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
	catch (exception& e)
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
	catch (exception& e)
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetRedirectionState %C\n", e.what());
	}

	return rc;
}

unsigned int PTHI_Commands::GetPortSettings(vector<EthernetPortEntry> &ethernetPortList)
{
	USES_CONVERSION;
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
		catch (exception& e)
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
			catch (exception& e)
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetTcpipParametersCommand %C\n", e.what());
	}

	return (rc);
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
			string encryptedPassword = WSmanCrypt::EncryptString(response.Password); //EncryptString will empty response.Password
			LocalAccount->Password.assign(encryptedPassword);
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
	catch (exception& e)
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
	catch (exception& e)
	{
		UNS_ERROR("Exception in GetLocalSystemAccountCommand %C\n", e.what());
	}

	return rc;
}
