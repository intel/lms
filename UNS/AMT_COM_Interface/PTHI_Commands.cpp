/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: PTHI_Commands.cpp

--*/

// PTHI_Commands.cpp : Implementation of CPTHI_Commands
#pragma once

#include "stdafx.h"
#include "PTHI_Commands.h"
#include "atlsafe.h"
#include <string>
#include "comdef.h"
#include "UNSDebug.h"
#include "UNSRegistry.h"
#include "DataStorageGenerator.h"
#include "PTHI_Commands_BE.h"

#pragma comment (lib,"version")
#pragma comment (lib,"Ws2_32")

#include <set>
#include "Sddl.h"
#define MAX_BUFFER_LENGTH  256

BOOL ReadPermissionsFromReg(DATA_NAME funcName, std::set<std::wstring>& groups)
{
	BOOL rc = FALSE;
	WCHAR val[1024];
	unsigned long valSz;
	valSz = sizeof(WCHAR) * 1024;
	//set <wstring> groups;
	WCHAR seps[]   = L",;";
	WCHAR* token;

	groups.clear();
	memset(val,0,sizeof(WCHAR)*1024);

	std::wstring storageVal;
	if (DSinstance().GetDataValue(funcName, storageVal, true) == TRUE)
	{
		if (storageVal.size() >= valSz)
		{
			return FALSE;
		}
		rc = TRUE;
		if (storageVal.size() > 0)
		{
			wcscpy_s(val, valSz, storageVal.c_str());
			token = wcstok( val, seps );
			// Note: strtok is deprecated; consider using strtok_s instead
			while( token != NULL )
			{
				std::wstring group = token;
				// Remove leading and trailing white space
				static const WCHAR whitespace[] = L" ";
				group.erase( 0, group.find_first_not_of(whitespace) );
				group.erase( group.find_last_not_of(whitespace) + 1U );
				groups.insert(group);
				token = wcstok( NULL, seps );
			}
		}
	}

	return rc;
}

bool HasAccessByBuiltinGroup(WELL_KNOWN_SID_TYPE WinBuiltinSid,TOKEN_GROUPS * groups, std::set<std::wstring>& GroupsSet)
{
	// check if user in the WinBuiltinSid group

	bool bHasAccess = false;
	DWORD SidSize;
	PSID AdministratorsSid = NULL;

	SidSize = SECURITY_MAX_SID_SIZE;
	// Allocate enough memory for the largest possible SID.
	AdministratorsSid = LocalAlloc(LMEM_FIXED, SidSize);
	if(!(AdministratorsSid))
	{
		return false;
	}
	// Create a SID on the local computer.
	if(!CreateWellKnownSid(WinBuiltinSid, NULL, AdministratorsSid, &SidSize))
	{
		LocalFree(AdministratorsSid);
		return false;
	}

	//LPTSTR lpBuffWellKnownSid;
	//ConvertSidToStringSid(TheSID,&lpBuffWellKnownSid);
	WCHAR szGrpName[MAX_BUFFER_LENGTH + 1],gszDomainName[15+1];
	SID_NAME_USE snu;
	for (WORD i= 0 ; i < groups->GroupCount; i++)
	{
		DWORD dwUserNameSize = MAX_BUFFER_LENGTH, dwDomainNameSize = 15;
		::LookupAccountSidW(NULL, groups->Groups[i].Sid,
		szGrpName, &dwUserNameSize, gszDomainName,
		&dwDomainNameSize, &snu);
		if ((SidTypeGroup == snu) || (SidTypeAlias == snu))
		{
			DWORD needAttributes = SE_GROUP_MANDATORY | SE_GROUP_ENABLED_BY_DEFAULT |SE_GROUP_ENABLED;
			if  (groups->Groups[i].Attributes & needAttributes )
			{
				LPTSTR lpBuff;
				ConvertSidToStringSid(groups->Groups[i].Sid,&lpBuff);
				//DbgPrint ("Group %s ,szDomainName %s , Attrib %d, SID_NAME_USE %d sid is %s\n",szGrpName,gszDomainName,groups->Groups[i].Attributes,snu,lpBuff);
				LocalFree(lpBuff);
				GroupsSet.insert(szGrpName);
				if (EqualSid(groups->Groups[i].Sid,AdministratorsSid))
				{
					bHasAccess = true;
					break;
				}

				/* ADD INCLUDING GROUPS ?????????????????
				string DomainAndGroup;
				if (_tcscmp(gszDomainName,_T("BUILTIN"))==0)
				{
					DomainAndGroup.assign(szDomainName);
					DomainAndGroup.append("\\");
					DomainAndGroup.append(szGrpName);
					//DomainAndGroup..Format(_T("%s\\%s"),szDomainName,szGrpName);
				}
				else
				{
					//DomainAndGroup.Format(_T("%s\\%s"),gszDomainName,szGrpName);
					DomainAndGroup.assign(gszDomainName);
					DomainAndGroup.append("\\");
					DomainAndGroup.append(szGrpName);
				}

				GroupsSet.insert(DomainAndGroup);*/

			}
		}
	}
	LocalFree(AdministratorsSid);
	return bHasAccess;
}

HRESULT CheckCredentials(DATA_NAME funcName)
{
	std::set<std::wstring> UserGroupsSet;
	BOOL rc = ReadPermissionsFromReg(funcName,UserGroupsSet);
	if (rc==0)
	{
		return S_FALSE;
	}

	if (rc && UserGroupsSet.empty())
	{
		return S_OK;
	}

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
		return hr;
	}

	if (dwImp!= SecurityImpersonation)
	{
		//DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		CloseHandle(hThreadTok);
		return hr;
	}


	bRes =::GetTokenInformation(hThreadTok, TokenUser,
		NULL, 0, &dwBytesReturned);

	if (bRes == 0)
	{
		CloseHandle(hThreadTok);
		return S_FALSE;
	}

	auto m_pUserTokenInfo = new unsigned char[dwBytesReturned];
	if (m_pUserTokenInfo == NULL)
	{
		CloseHandle(hThreadTok);
		return S_FALSE;
	}

	bRes = ::GetTokenInformation(hThreadTok, TokenUser,
		m_pUserTokenInfo,
		dwBytesReturned, &dwBytesReturned);

	if (!bRes)
	{
		DbgPrintW(L"Unable to GetTokenInformation - TokenUser (0x%x)\n", GetLastError());
		CloseHandle(hThreadTok);
		delete [] m_pUserTokenInfo;
		return S_FALSE;
	}


	DWORD dwUserNameSize = MAX_BUFFER_LENGTH, dwDomainNameSize = 15;
	WCHAR szUserName[MAX_BUFFER_LENGTH + 1],szDomainName[15 + 1];
	SID_NAME_USE snu;

	bRes = ::LookupAccountSidW(0, ((PTOKEN_USER) m_pUserTokenInfo)->User.Sid,
		szUserName, &dwUserNameSize, szDomainName,
		&dwDomainNameSize, &snu);

	delete [] m_pUserTokenInfo;

	//DBGTRACE(_T("Connect User is %s ,szDomainName %s"),szUserName,szDomainName);

	bRes =::GetTokenInformation(hThreadTok, TokenGroups,
		NULL, 0, &dwBytesReturned);

	TOKEN_GROUPS * groups;

	groups =(TOKEN_GROUPS*) new unsigned char[dwBytesReturned];

	bRes = ::GetTokenInformation(hThreadTok, TokenGroups,
		groups,
		dwBytesReturned, &dwBytesReturned);
	if (!bRes)
	{
		//DBGERROR(LOCATION, _T("Unable to GetTokenInformation - TokenUser (0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		delete [] groups;
		return hr;
	}

	CloseHandle(hThreadTok);

	hr = CoRevertToSelf();
	if (hr != S_OK)
	{
		//DBGERROR(LOCATION, _T("CoRevertToSelf (0x%x)"), hr);
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		delete [] groups;
		return hr;
	}

	bool bHasAccess = false;
	std::set<std::wstring> GroupsSet;
	GroupsSet.clear();
	bHasAccess = HasAccessByBuiltinGroup(WinBuiltinAdministratorsSid,groups, GroupsSet);

	if (!bHasAccess && (funcName >= 0)) // if user is admin or system there is no need to check for other groups
	{
		if (rc)
		{
			// Usergroup empty case is handled at the beginning of the function - due bug 192098
			//if (UserGroupsSet.empty())
			//{
			//	GroupsSet.clear();
			//	bHasAccess = HasAccessByBuiltinGroup(WinBuiltinUsersSid,groups, GroupsSet);
			//}
			//else
			//{
				std::set<std::wstring>::const_iterator GroupsSetIter, pFindIter;
				for ( GroupsSetIter = UserGroupsSet.begin( ); GroupsSetIter != UserGroupsSet.end( ); GroupsSetIter++ )
				{
					pFindIter = GroupsSet.find(*GroupsSetIter);
					if ((pFindIter != GroupsSet.end( )))
					{
						DbgPrintW(L"The user group is found in reg GroupsSet!!!\n");
						bHasAccess = true;
						break;
					}
				}
				GroupsSet.clear();
			//}
		}
	}

	if (bHasAccess)
		hr = S_OK;
	else
		hr = S_FALSE;

	delete [] groups;


	return hr;
}

STDMETHODIMP CPTHI_Commands::GetAMTVersion(BSTR* AMTVersion)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"AMTVersion", AMTVersion) == true)
	{
		if (wcscmp(*AMTVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetAMTVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sAMTVersion;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetAMTVersion(sAMTVersion);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sAMTVersion.c_str());
	*AMTVersion = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetLMSVersion(BSTR* sVersion)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"LMSVersion", sVersion) == true)
	{
		if (wcscmp(*sVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetLMSVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sLMSVersion;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetLMSVersion(sLMSVersion);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sLMSVersion.c_str());
	*sVersion = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetHeciVersion(BSTR* sVersion)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"HeciVersion", sVersion) == true)
	{
		if (wcscmp(*sVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetHeciVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sHeciVersion;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetHeciVersion(sHeciVersion);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sHeciVersion.c_str());
	*sVersion = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningMode(SHORT* pProvisioningMode)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ProvisioningMode", pProvisioningMode) == true)
	{
		if (*pProvisioningMode == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetProvisioningMode_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t ProvisioningMode;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetProvisioningMode(ProvisioningMode);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pProvisioningMode = (SHORT)ProvisioningMode;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningTlsMode(SHORT* pProvisioningTlsMode)
{
	/*AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ProvisioningTlsMode", pProvisioningTlsMode) == true)
	{
		if (*pProvisioningTlsMode == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetProvisioningTlsMode_F) != S_OK)
		return E_ACCESSDENIED;
	uint32_t ProvisioningTlsMode;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetProvisioningTlsMode(ProvisioningTlsMode);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pProvisioningTlsMode = (SHORT)ProvisioningTlsMode;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningState(SHORT* pProvisioningState)
{
	/*
	AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ProvisioningState", pProvisioningState) == true)
	{
		if (*pProvisioningState == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetProvisioningState_F) != S_OK)
	{
		return E_ACCESSDENIED;
	}

	uint32_t ProvisioningState;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetProvisioningState(ProvisioningState);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pProvisioningState = (SHORT)ProvisioningState;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetNetworkConnectionStatus(SHORT* pStatus,SHORT* pConnectionType,SHORT* pConnectionTrigger)
{
	/*
	AMT_STATUS_NOT_PERMITTED	Entity has no permission to get connection status.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"NetworkConnectionStatus", pStatus) == true)
		if (GetFromRegistry(L"DebugData", L"NetworkConnectionType", pConnectionType) == true)
			if (GetFromRegistry(L"DebugData", L"NetworkConnectionTrigger", pConnectionTrigger) == true)
			{
				if (*pStatus == -1)
					return E_FAIL;
				return S_OK;
			}
#endif
	if (CheckCredentials(GetNetworkConnectionStatus_F) != S_OK)
	{
		return E_ACCESSDENIED;
	}

	uint32_t Status, ConnectionType, ConnectionTrigger;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetNetworkConnectionStatus(
		Status, ConnectionType, ConnectionTrigger);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pStatus = (SHORT)Status;
	*pConnectionType = (SHORT)ConnectionType;
	*pConnectionTrigger = (SHORT)ConnectionTrigger;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetUserInitiatedEnabled(SHORT* pStatus)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"CIRAenabled", pStatus) == true)
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetUserInitiatedEnabled_F) != S_OK)
	{
		return E_ACCESSDENIED;
	}

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetUserInitiatedEnabled(*pStatus);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::getWebUIState(SHORT* pState)
{
	/*
	AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"WebUIState", pState) == true)
	{
		if (*pState == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(getWebUIState_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t State;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).getWebUIState(State);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pState = (SHORT)State;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetPowerPolicy(BSTR* bstrPolicy)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"PowerPolicy", bstrPolicy) == true)
	{
		if (wcscmp((wchar_t*)bstrPolicy, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetPowerPolicy_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sPolicy;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetPowerPolicy(sPolicy);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sPolicy.c_str());
	*bstrPolicy = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetLastResetReason(SHORT* pReason)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"LastResetReason", pReason) == true)
	{
		if (*pReason == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetLastResetReason_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetLastResetReason(*pReason);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetRedirectionStatus(SHORT* pSOL, SHORT* pIDER)
{
	/*
	AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"RedirectionStatusSOL", pSOL) == true)
		if (GetFromRegistry(L"DebugData", L"RedirectionStatusIDER", pIDER) == true)
		{
			if (*pSOL == -1)
				return E_FAIL;
			return S_OK;
		}
#endif

	if (CheckCredentials(GetRedirectionStatus_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t SOL, IDER;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetRedirectionStatus(SOL, IDER);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pSOL = (SHORT)SOL;
	*pIDER = (SHORT)IDER;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSystemDefenseStatus(SHORT* pStatus)
{
	/*
	AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SystemDefenseStatus", pStatus) == true)
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSystemDefenseStatus_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t Status;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetSystemDefenseStatus(Status);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pStatus = (SHORT)Status;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetNetworkSettings(SHORT ConnectionType /*WIRED, WIRELESS*/,
												SHORT* pDhcpEnabled ,// Both
												BSTR*  bstrIpAddress,//Both
												BSTR*  bstrMacAddress,//Both
												SHORT* pLinkStatus, //Both
												SHORT* pWirelessControl,// WIRELESS
												SHORT* pWirelessConfEnabled) //WIRELESS
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"DhcpEnabled", pDhcpEnabled) == true)
		 && (GetFromRegistry(L"DebugData", L"IpAddress", bstrIpAddress) == true)
		 && (GetFromRegistry(L"DebugData", L"MacAddress", bstrMacAddress) == true)
		 && (GetFromRegistry(L"DebugData", L"LinkStatus", pLinkStatus) == true)
		 && (GetFromRegistry(L"DebugData", L"WirelessControl", pWirelessControl) == true)
		 && (GetFromRegistry(L"DebugData", L"WirelessConfEnabled", pWirelessConfEnabled) == true))
		{
			if (*pDhcpEnabled == -1)
				return E_FAIL;
			return S_OK;
		}
#endif

	if (CheckCredentials(GetNetworkSettings_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sIpAddress;
	std::string sMacAddress;
	uint32_t DhcpEnabled;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetNetworkSettings(ConnectionType, DhcpEnabled,
		sIpAddress, sMacAddress, *pLinkStatus, *pWirelessControl, *pWirelessConfEnabled);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pDhcpEnabled = (SHORT)DhcpEnabled;
	CComBSTR bstr(sIpAddress.c_str());
	*bstrIpAddress = bstr.Detach();
	CComBSTR bstr1(sMacAddress.c_str());
	*bstrMacAddress = bstr1.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetIPv6NetworkSettings(SHORT ConnectionType /*WIRED, WIRELESS*/,
										BSTR* IPv6DefaultRouter,
										BSTR* PrimaryDNS,
										BSTR* SecondaryDNS,
										VARIANT* pResponse,
										VARIANT_BOOL* pIpv6Enable)
{
	/*
	AMT_STATUS_UNSUPPORTED	Returned if this FW SKU does not support IPv6. The status of IPv6 support can be retrieved by calling CFG_GetIPv6Settings.
AMT_STATUS_INVALID_MESSAGE_LENGTH	Length field of header is invalid.
AMT_STATUS_IPV6_INTERFACE_DISABLED	The IPv6 interface is currently disabled so there is no current IPv6 status available for this interface.
AMT_STATUS_INTERFACE_DOES_NOT_EXIST	The network interface that is being referred to in this command does not exist (e.g. wireless interface on desktop)
*/
#ifdef _DEBUG
	TCHAR addresses[2048];
	DWORD Ipv6Enable_;
	if ((GetFromRegistry(L"DebugData", L"IPv6DefaultRouter", IPv6DefaultRouter) == true)
		 && (GetFromRegistry(L"DebugData", L"PrimaryDNS", PrimaryDNS) == true)
		 && (GetFromRegistry(L"DebugData", L"SecondaryDNS", SecondaryDNS) == true)
		 && (GetFromRegistry(L"DebugData", L"IPv6Addresses", addresses, 2048) == true)
		 && (GetFromRegistry(L"DebugData", L"Ipv6Enable", &Ipv6Enable_) == true))
		{
			if (wcscmp((wchar_t*)IPv6DefaultRouter, L"exception") == 0)
				return E_FAIL;

			WCHAR *token;
			WCHAR seps[]   = L"|";
			unsigned long i = 0;
			long num = 0;

			for (i=0; i < wcslen(addresses); i++)
				if (addresses[i] == L'|')
					num++;

			if (i > 0) // there is at least one word
				num++;

			SAFEARRAY *pSar ;
			VariantInit(pResponse);
			pSar = SafeArrayCreateVector(VT_BSTR, 0, num) ;
			token = wcstok( addresses, seps ); // C4996
			 // Note: strtok is deprecated; consider using strtok_s instead
			num = 0;
			while( token != NULL )
			{

				CComBSTR bstr(token);
				SafeArrayPutElement(pSar, &num, bstr) ;
				token = wcstok( NULL, seps ); // C4996
				num++;
			}
			pResponse->vt = VT_ARRAY | VT_BSTR ;
			pResponse->parray = pSar ;
			*pIpv6Enable = (VARIANT_BOOL)Ipv6Enable_;
			return S_OK;
		}
#endif

	if (CheckCredentials(GetIPv6NetworkSettings_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sIPv6DefaultRouter;
	std::string sPrimaryDNS;
	std::string sSecondaryDNS;
	std::vector<std::string> Response;
	bool Ipv6Enable;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetIPv6NetworkSettings(ConnectionType, sIPv6DefaultRouter,
		sPrimaryDNS, sSecondaryDNS, Response, Ipv6Enable);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sIPv6DefaultRouter.c_str());
	*IPv6DefaultRouter = bstr.Detach();
	CComBSTR bstr1(sPrimaryDNS.c_str());
	*PrimaryDNS = bstr1.Detach();
	CComBSTR bstr2(sSecondaryDNS.c_str());
	*SecondaryDNS = bstr2.Detach();
	*pIpv6Enable = Ipv6Enable ? TRUE : FALSE;

	SAFEARRAY *pSar;
	VariantInit(pResponse);
	BSTR bstrTmp;
	try
	{
		pSar = SafeArrayCreateVector(VT_BSTR, 0, Response.size());
		for (LONG i = 0 ; i < (LONG)Response.size(); i++)
		{
			CComBSTR bstrAddress(Response[i].c_str());
			bstrTmp = bstrAddress.Detach();
			SafeArrayPutElement(pSar, &i, bstrTmp);
		}
		pResponse->vt = VT_ARRAY | VT_BSTR;
		pResponse->parray = pSar;
	}
	catch(_com_error &err)
	{
		const TCHAR* reason =  err.ErrorMessage();
		DbgPrintW(L"com error %wC\n", reason);
	}
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSystemUUID(BSTR* bstrUUID)
{
	/*
	AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SystemUUID", bstrUUID) == true)
	{
		if (wcscmp(*bstrUUID, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSystemUUID_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sUUID;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetSystemUUID(sUUID);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(sUUID.c_str());
	*bstrUUID = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::OpenUserInitiatedConnection(void)
{
/*
AMT_STATUS_NOT_PERMITTED	Entity has no permission to open a connection..
AMT_STATUS_INTERNAL_ERROR	The operation could not be completed by AMT.
AMT_STATUS_DATA_MISSING		No connectivity policy configured when AMT is outside the enterprise network.
*/
	if (CheckCredentials(OpenUserInitiatedConnection_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).OpenUserInitiatedConnection();
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::CloseUserInitiatedConnection(void)
{
	/*
	AMT_STATUS_NOT_PERMITTED	Entity has no permission to close a connection.
	*/
	if (CheckCredentials(CloseUserInitiatedConnection_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).CloseUserInitiatedConnection();
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::TerminateKVMSession(void)
{
	if (CheckCredentials(TerminateKVMSession_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).TerminateKVMSession();
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetKVMRedirectionState(VARIANT_BOOL* pEnabled, VARIANT_BOOL* pConnected)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"KVMRedirectionStateEnabled", (SHORT*)pEnabled) == true)
	{
		if (GetFromRegistry(L"DebugData", L"KVMRedirectionStateConnected", (SHORT*)pConnected) == true)
		{
			if ((*pEnabled == -1) || (*pConnected == -1))
				return E_FAIL;
		}
		return S_OK;
	}
#endif

	if (CheckCredentials(GetKVMRedirectionState_F) != S_OK)
		return E_ACCESSDENIED;

	bool enabled, connected;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetKVMRedirectionState(enabled, connected);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pEnabled = enabled ? TRUE : FALSE;
	*pConnected = connected ? TRUE : FALSE;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSpriteLanguage(SHORT* pLanguage)
{

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SpriteLanguage", pLanguage) == true)
	{
		if (*pLanguage == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSpriteLanguage_F) != S_OK)
		return E_ACCESSDENIED;
	unsigned short lang = 0;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetSpriteLanguage(lang);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pLanguage = lang;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::SetSpriteLanguage(SHORT Language)
{
#ifdef _DEBUG
	//PartFWUpdateThread::instance(Language,MANUAL_MODE).actNow();
	//return S_OK;
#endif
	if (CheckCredentials(SetSpriteLanguage_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).SetSpriteLanguage(Language);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSpriteZoom(SHORT* pZoom)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SpriteZoom", pZoom) == true)
	{
		if (*pZoom == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSpriteZoom_F) != S_OK)
		return E_ACCESSDENIED;
	unsigned short zoom = 0;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetSpriteZoom(zoom);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pZoom = zoom;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSpriteParameters(SHORT* pLanguage, SHORT* pZoom)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SpriteLanguage", pLanguage) == true)
	{
		if (GetFromRegistry(L"DebugData", L"SpriteZoom", pZoom) == true)
		{
			if ((*pZoom == -1) || (*pLanguage == -1))
				return E_FAIL;
			return S_OK;
		}
	}
#endif

	if (CheckCredentials(GetSpriteParameters_F) != S_OK)
		return E_ACCESSDENIED;
	unsigned short lang = 0;
	unsigned short zoom = 0;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetSpriteParameters(lang, zoom);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	*pLanguage = lang;
	*pZoom = zoom;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::SetSpriteZoom(SHORT Zoom)
{
	if (CheckCredentials(SetSpriteZoom_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).SetSpriteZoom(Zoom);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetConfigurationInfo(SHORT* pControlMode,SHORT* pProvisioningMethod,BSTR* pCreationTimeStamp,SAFEARRAY** ppCertHash)
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"ControlMode", pControlMode) == true)
		&& (GetFromRegistry(L"DebugData", L"ProvisioningMethod", pProvisioningMethod) == true)
		&& (GetFromRegistry(L"DebugData", L"CreationTimeStamp", pCreationTimeStamp) == true))
	{
		if (*pControlMode == -1)
			return E_FAIL;

		BYTE Data[1024];
		ULONG len=1024;
 		if (GetFromRegistry(L"DebugData", L"CertHash", Data, &len) == true)
		{
			CComSafeArray<BYTE> hashdata(len);
			int intLen = (int) len;
			for (int i=0; i < intLen; i++)
			{
				hashdata[i]=Data[i];
			}
			*ppCertHash = hashdata.Detach();

		}
		return S_OK;
	}
#endif

	if (CheckCredentials(GetConfigurationInfo_F) != S_OK)
		return E_ACCESSDENIED;

	std::string CreationTimeStampStr;
	std::vector<unsigned char> CertHash;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetConfigurationInfo(*pControlMode, *pProvisioningMethod,
		CreationTimeStampStr, CertHash);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(CreationTimeStampStr.c_str());
	*pCreationTimeStamp = bstr.Detach();
	CComSafeArray<BYTE> hashdata(CertHash.size());
	for (int i = 0; i < (int)CertHash.size(); i++)
	{
		hashdata[i] = CertHash[i];
	}
	*ppCertHash = hashdata.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::TerminateRemedySessions(void)
{
	DbgPrintW(L"CPTHI_Commands::TerminateRemedySessions\n");
#ifdef _DEBUG
	SHORT result;
	if (GetFromRegistry(L"DebugData", L"TerminateRemedySessions", &result) == true)
	{
		if (result == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(TerminateRemedySessions_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).TerminateRemedySessions();
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetUserConsentState(SHORT* pState, USER_CONSENT_POLICY* pPolicy)
{
#ifdef _DEBUG
	short UserConsentPolicy;
	if ((GetFromRegistry(L"DebugData", L"UserConsentState", pState) == true)
		&& (GetFromRegistry(L"DebugData", L"UserConsentPolicy", &UserConsentPolicy) == true))
	{
		if (*pState == -1)
			return E_FAIL;
		*pPolicy = (USER_CONSENT_POLICY)UserConsentPolicy;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetUserConsentState_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetUserConsentState(*pState, *pPolicy);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetWLANLinkInfo(UINT* pPreference, UINT* pControl, UINT* pProtection)
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"WLANLinkPreference", (SHORT*)pPreference) == true)
		&& (GetFromRegistry(L"DebugData", L"WLANLinkControl", (SHORT*)pControl) == true)
		&& (GetFromRegistry(L"DebugData", L"WLANLinkProtection", (SHORT*)pProtection) == true))
	{
		if (*pPreference == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetWLANLinkInfo_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetWLANLinkInfo(*pPreference, *pControl, *pProtection);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::SetLinkPreferenceToHost(void)
{
	DbgPrintW(L"CPTHI_Commands::SetLinkPreferenceToHost\n");
#ifdef _DEBUG
	SHORT result;
	if (GetFromRegistry(L"DebugData", L"SetLinkPreferenceToHost", &result) == true)
	{
		if (result == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(SetLinkPreferenceToHost_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).SetLinkPreferenceToHost();
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}
STDMETHODIMP CPTHI_Commands::InitiateUserConnection(SHORT* pStatus)
{
/*
AMT_STATUS_NOT_PERMITTED	Entity has no permission to open a connection..
AMT_STATUS_INTERNAL_ERROR	The operation could not be completed by AMT.
AMT_STATUS_DATA_MISSING		No connectivity policy configured when AMT is outside the enterprise network.
*/
	if (CheckCredentials(InitiateUserConnection_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).InitiateUserConnection(*pStatus);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}


STDMETHODIMP CPTHI_Commands::userInitiatedPolicyRuleExists(SHORT* pStatus)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"userInitiatedPolicyRuleExists", pStatus) == true)
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(userInitiatedPolicyRuleExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).userInitiatedPolicyRuleExists(*pStatus);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::userInitiatedPolicyRuleForLocalMpsExists(SHORT* pStatus)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"userInitiatedPolicyRuleForLocalMpsExists", pStatus) == true)
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(UserInitiatedPolicyRuleForLocalMpsExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).userInitiatedPolicyRuleForLocalMpsExists(*pStatus);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}


STDMETHODIMP CPTHI_Commands::snmpEventSubscriberExists(SHORT* pExist)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"snmpEventSubscriberExists", pExist) == true)
	{
		if (*pExist == -1)
			return E_FAIL;
		return S_OK;
	}
#endif


	if (CheckCredentials(snmpEventSubscriberExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).snmpEventSubscriberExists(*pExist);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::CILAFilterCollectionSubscriptionExists(SHORT* pExist)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"CILAFilterCollectionSubscriptionExists", pExist) == true)
	{
		if (*pExist == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(CILAFilterCollectionSubscriptionExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).CILAFilterCollectionSubscriptionExists(*pExist);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::UpdateScreenSettings (EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters)
{
	return UpdateScreenSettings2(eExtendedDisplayParameters, MAX_DISPLAY_NUMBER_LEGACY);
}

STDMETHODIMP CPTHI_Commands::UpdateScreenSettings2(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, SHORT numOfDisplays)
{
	/*#ifdef _DEBUG
	if (GetFromRegistry("DebugData", "UpdateScreenSettings",&eExtendedDisplayParameters, &numOfDisplays) == true)
	{
	if (eExtendedDisplayParameters == -1)
		return E_FAIL;
	if (numOfDisplays == -1)
		return E_FAIL;
	return S_OK;
	}
	#endif*/

	if (CheckCredentials(UpdateScreenSettings_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).UpdateScreenSettings2(eExtendedDisplayParameters, numOfDisplays);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetRedirectionSessionLinkTechnology(REDIRECTION_SESSION_TYPE sessionType , SHORT* pLinkTechnology)
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"RedirectionSessionLinkTechnology", (SHORT*)pLinkTechnology) == true))
	{
		if (*pLinkTechnology == -1)
			return E_FAIL;
		return S_OK;
	}
#endif
	if (CheckCredentials(GetRedirectionSessionLinkTechnology_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).GetRedirectionSessionLinkTechnology(sessionType, *pLinkTechnology);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::IsRebootAfterProvisioningNeeded(VARIANT_BOOL *pNeeded)
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"IsRebootAfterProvisioningNeeded", (SHORT*)pNeeded) == true))
	{
		DbgPrintW(L"CPTHI_Commands::IsRebootAfterProvisioningNeeded DEBUG mode, got from registry %d",L"\n",*pNeeded);
		return S_OK;
	}
#endif
	if (CheckCredentials(IsRebootAfterProvisioningNeeded_F) != S_OK)
		return E_ACCESSDENIED;

	bool isNeeded;
	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).IsRebootAfterProvisioningNeeded(isNeeded);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	if (isNeeded)
		*pNeeded = VARIANT_TRUE;
	else
		*pNeeded = VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::ProxyAddProxyEntry(BSTR		proxy_fqdn,
												USHORT		proxy_port,
												SAFEARRAY*	gateway_mac_address,
												BSTR		network_dns_suffix)

{
	if (CheckCredentials(ProxyAddProxyEntry_F) != S_OK)
		return E_ACCESSDENIED;

	HRESULT rc=E_FAIL;
	LONG UBound = 0, LBound = 0;
	LONG arraySize = 0;
	rc = SafeArrayGetUBound(gateway_mac_address, 1, &UBound);
	if (!SUCCEEDED(rc))
	{
		return rc;
	}

	rc = SafeArrayGetLBound(gateway_mac_address, 1, &LBound);
	if (!SUCCEEDED(rc))
	{
		return rc;
	}

	arraySize = (UBound - LBound) + 1;
	// Check for Mac MAX Len
	if (arraySize != 6)
	{
		return E_INVALIDARG;
	}

	Intel::LMS::LMS_ERROR err = Intel::LMS::PTHI_Commands_BE(GetGmsPortForwardingStarted()).ProxyAddProxyEntry(
		ConvertBStrToString(proxy_fqdn),
		proxy_port,
		(uint8_t*)gateway_mac_address->pvData,
		ConvertBStrToString(network_dns_suffix));
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

inline std::string ConvertBStrToString(BSTR bstr)
{
	USES_CONVERSION;

	return (SysStringLen(bstr) == 0) ? std::string() : std::string(CW2A(bstr));
}
