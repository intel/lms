/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: PTHI_Commands.cpp

--*/

// PTHI_Commands.cpp : Implementation of CPTHI_Commands
#pragma once
#include "global.h"
#include "stdafx.h"
#include "PTHI_Commands.h"
#include "atlsafe.h"
#include <string>
#include "comdef.h"
#include "UNSRegistry.h"
#include "DataStorageGenerator.h"
#include "PTHI_Commands_BE.h"

#pragma comment (lib,"version")
#pragma comment (lib,"Ws2_32")

#include <set>
#include "Sddl.h"
#define MAX_BUFFER_LENGTH  256

static bool ReadPermissionsFromReg(DATA_NAME funcName, std::set<std::wstring>& groups)
{
	bool rc = false;
	WCHAR val[1024];
	size_t valSz = sizeof(val);
	WCHAR seps[]  = L",;";
	WCHAR* token;
	WCHAR* context = nullptr;

	groups.clear();
	memset(val, 0, sizeof(val));

	std::wstring storageVal;
	if (DSinstance().GetDataValue(funcName, storageVal, true))
	{
		if (storageVal.size() >= valSz)
		{
			return false;
		}

		rc = true;
		if (storageVal.size() > 0)
		{
			wcscpy_s(val, valSz, storageVal.c_str());
			token = std::wcstok(val, seps, &context);
			while (token)
			{
				std::wstring group = token;
				// Remove leading and trailing white space
				static const WCHAR whitespace[] = L" ";
				group.erase(0, group.find_first_not_of(whitespace));
				group.erase(group.find_last_not_of(whitespace) + 1U );
				groups.insert(group);
				token = std::wcstok(nullptr, seps, &context);
			}
		}
	}

	return rc;
}

bool HasAccessByBuiltinGroup(WELL_KNOWN_SID_TYPE WinBuiltinSid, TOKEN_GROUPS *groups, std::set<std::wstring>& GroupsSet)
{
	// check if user in the WinBuiltinSid group

	bool bHasAccess = false;
	DWORD SidSize;
	PSID AdministratorsSid = NULL;

	SidSize = SECURITY_MAX_SID_SIZE;
	// Allocate enough memory for the largest possible SID.
	AdministratorsSid = LocalAlloc(LMEM_FIXED, SidSize);
	if (!AdministratorsSid)
	{
		return false;
	}
	// Create a SID on the local computer.
	if (!CreateWellKnownSid(WinBuiltinSid, NULL, AdministratorsSid, &SidSize))
	{
		LocalFree(AdministratorsSid);
		return false;
	}

	WCHAR szGrpName[MAX_BUFFER_LENGTH + 1], gszDomainName[15+1];
	SID_NAME_USE snu;
	for (WORD i = 0; i < groups->GroupCount; i++)
	{
		DWORD dwUserNameSize = MAX_BUFFER_LENGTH, dwDomainNameSize = 15;
		::LookupAccountSidW(NULL, groups->Groups[i].Sid,
		                    szGrpName, &dwUserNameSize, gszDomainName,
		                    &dwDomainNameSize, &snu);
		if (SidTypeGroup == snu || SidTypeAlias == snu)
		{
			DWORD needAttributes = SE_GROUP_MANDATORY | SE_GROUP_ENABLED_BY_DEFAULT |SE_GROUP_ENABLED;
			if  (groups->Groups[i].Attributes & needAttributes)
			{
				LPTSTR lpBuff;
				ConvertSidToStringSid(groups->Groups[i].Sid, &lpBuff);
				LocalFree(lpBuff);
				GroupsSet.insert(szGrpName);
				if (EqualSid(groups->Groups[i].Sid, AdministratorsSid))
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
	bool rc = ReadPermissionsFromReg(funcName, UserGroupsSet);

	if (!rc)
	{
		return S_FALSE;
	}

	if (UserGroupsSet.empty())
	{
		return S_OK;
	}

	HRESULT hr = S_OK;
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

	bRes = OpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE, &hThreadTok);
	if (bRes == FALSE)
	{
		//DBGERROR(LOCATION, _T("Unable to OpenThreadToken (0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		return hr;
	}

	bRes = ::GetTokenInformation(hThreadTok, TokenImpersonationLevel,
	                             &dwImp, sizeof(dwImp), &dwBytesReturned);

	if (bRes == FALSE || (dwBytesReturned < sizeof(PTOKEN_USER)))
	{
		//DBGERROR(LOCATION, _T("Unable to GetTokenInformation - TokenImpersonationLevel(0x%x)"), GetLastError());
		hr = S_FALSE;//STATUS_SECURITY_PROBLEM;
		CloseHandle(hThreadTok);
		return hr;
	}

	if (dwImp != SecurityImpersonation)
	{
		//DBGERROR(LOCATION, _T("Wrong security TokenImpersonationLevel (%d)"), dwImp);
		hr = S_FALSE;//STATUS_SECURITY_NOT_CORRECT;
		CloseHandle(hThreadTok);
		return hr;
	}

	bRes =::GetTokenInformation(hThreadTok, TokenUser, NULL, 0, &dwBytesReturned);
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

	bRes = ::GetTokenInformation(hThreadTok, TokenUser, m_pUserTokenInfo,
	                             dwBytesReturned, &dwBytesReturned);
	if (bRes == FALSE || dwBytesReturned <  sizeof(PTOKEN_USER))
	{
		UNS_DEBUG(L"Unable to GetTokenInformation - TokenUser (0x%x)\n", GetLastError());
		CloseHandle(hThreadTok);
		delete [] m_pUserTokenInfo;
		return S_FALSE;
	}

	DWORD dwUserNameSize = MAX_BUFFER_LENGTH;
    DWORD dwDomainNameSize = 15;
	WCHAR szUserName[MAX_BUFFER_LENGTH + 1];
    WCHAR szDomainName[15 + 1];
	SID_NAME_USE snu;

	bRes = ::LookupAccountSidW(0, ((PTOKEN_USER)m_pUserTokenInfo)->User.Sid, szUserName,
	                           &dwUserNameSize, szDomainName, &dwDomainNameSize, &snu);

	delete [] m_pUserTokenInfo;

	//DBGTRACE(_T("Connect User is %s, szDomainName %s"),szUserName,szDomainName);

	bRes = ::GetTokenInformation(hThreadTok, TokenGroups, NULL, 0, &dwBytesReturned);
	if (bRes == FALSE || dwBytesReturned < sizeof(TOKEN_GROUPS))
	{
		CloseHandle(hThreadTok);
		return S_FALSE;//STATUS_SECURITY_PROBLEM;
	}

	TOKEN_GROUPS *groups = (TOKEN_GROUPS *)new unsigned char[dwBytesReturned];

	bRes = ::GetTokenInformation(hThreadTok, TokenGroups, groups, dwBytesReturned, &dwBytesReturned);
	if (bRes == FALSE || dwBytesReturned < sizeof(TOKEN_GROUPS))
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
	bHasAccess = HasAccessByBuiltinGroup(WinBuiltinAdministratorsSid, groups, GroupsSet);

	if (!bHasAccess && (funcName >= 0)) // if user is admin or system there is no need to check for other groups
	{
		if (rc)
		{
			// Usergroup empty case is handled at the beginning of the function - due bug 192098
			std::set<std::wstring>::const_iterator GroupsSetIter, pFindIter;
			for (GroupsSetIter = UserGroupsSet.begin( ); GroupsSetIter != UserGroupsSet.end( ); GroupsSetIter++)
			{
				pFindIter = GroupsSet.find(*GroupsSetIter);
				if ((pFindIter != GroupsSet.end()))
				{
					UNS_DEBUG(L"The user group is found in reg GroupsSet!!!\n");
					bHasAccess = true;
					break;
				}
			}
			GroupsSet.clear();
		}
	}

	if (bHasAccess)
		hr = S_OK;
	else
		hr = S_FALSE;

	delete [] groups;

	return hr;
}

HRESULT LMSError2HRESULT(Intel::LMS::LMS_ERROR err)
{
	switch (err)
	{
	case Intel::LMS::ERROR_OK:
		return S_OK;
	case Intel::LMS::ERROR_FAIL:
		return E_FAIL;
	case Intel::LMS::ERROR_UNEXPECTED:
		return E_UNEXPECTED;
	case Intel::LMS::ERROR_INVALIDARG:
		return E_INVALIDARG;
	case Intel::LMS::ERROR_NOT_AVAILABLE_NOW:
		return E_NOT_VALID_STATE;
	case Intel::LMS::ERROR_NOT_SUPPORTED_BY_FW:
		return E_NOINTERFACE;
	default:
		return E_FAIL;
	}
}

STDMETHODIMP CPTHI_Commands::GetAMTVersion(BSTR* AMTVersion)
{
	if (AMTVersion == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"AMTVersion", AMTVersion))
	{
		if (wcscmp(*AMTVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetAMTVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sAMTVersion;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetAMTVersion(sAMTVersion);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sAMTVersion.c_str());
	*AMTVersion = bstr.Detach();

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetLMSVersion(BSTR* sVersion)
{
	if (sVersion == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"LMSVersion", sVersion))
	{
		if (wcscmp(*sVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetLMSVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sLMSVersion;
	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetLMSVersion(sLMSVersion);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sLMSVersion.c_str());
	*sVersion = bstr.Detach();

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetHeciVersion(BSTR* sVersion)
{
	if (sVersion == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"HeciVersion", sVersion))
	{
		if (wcscmp(*sVersion, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetHeciVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sHeciVersion;
	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetHeciVersion(sHeciVersion);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sHeciVersion.c_str());
	*sVersion = bstr.Detach();

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningMode(SHORT* pProvisioningMode)
{
	if (pProvisioningMode == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CPTHI_Commands::GetProvisioningMode - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningTlsMode(SHORT* pProvisioningTlsMode)
{
	if (pProvisioningTlsMode == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CPTHI_Commands::GetProvisioningTlsMode - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::GetProvisioningState(SHORT* pProvisioningState)
{
	if (pProvisioningState == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ProvisioningState", pProvisioningState))
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

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetProvisioningState(ProvisioningState);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pProvisioningState = (SHORT)ProvisioningState;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetNetworkConnectionStatus(SHORT* pStatus, SHORT* pConnectionType, SHORT* pConnectionTrigger)
{
	if (pStatus == nullptr || pConnectionType == nullptr || pConnectionTrigger == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_NOT_PERMITTED	Entity has no permission to get connection status.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"NetworkConnectionStatus", pStatus) &&
	    GetFromRegistry(L"DebugData", L"NetworkConnectionType", pConnectionType) &&
	    GetFromRegistry(L"DebugData", L"NetworkConnectionTrigger", pConnectionTrigger))
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

	uint32_t Status;
	uint32_t ConnectionType;
	uint32_t ConnectionTrigger;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetNetworkConnectionStatus(Status, ConnectionType, ConnectionTrigger);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pStatus = (SHORT)Status;
	*pConnectionType = (SHORT)ConnectionType;
	*pConnectionTrigger = (SHORT)ConnectionTrigger;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetUserInitiatedEnabled(SHORT* pStatus)
{
	if (pStatus == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"CIRAenabled", pStatus))
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

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetUserInitiatedEnabled(*pStatus);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::getWebUIState(SHORT* pState)
{
	if (pState == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CPTHI_Commands::getWebUIState - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::GetPowerPolicy(BSTR* bstrPolicy)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"PowerPolicy", bstrPolicy))
	{
		if (wcscmp((wchar_t*)bstrPolicy, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetPowerPolicy_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sPolicy;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetPowerPolicy(sPolicy);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sPolicy.c_str());
	*bstrPolicy = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetLastResetReason(SHORT* pReason)
{
	if (pReason == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"LastResetReason", pReason))
	{
		if (*pReason == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetLastResetReason_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetLastResetReason(*pReason);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::GetRedirectionStatus(SHORT* pSOL, SHORT* pIDER)
{
	if (pSOL == nullptr || pIDER == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_INVALID_PARAMETER	Request Id is unknown
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"RedirectionStatusSOL", pSOL) &&
	        GetFromRegistry(L"DebugData", L"RedirectionStatusIDER", pIDER))
	{
		if (*pSOL == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetRedirectionStatus_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t SOL, IDER;
	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetRedirectionStatus(SOL, IDER);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pSOL = (SHORT)SOL;
	*pIDER = (SHORT)IDER;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSystemDefenseStatus(SHORT* pStatus)
{
	if (pStatus == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_INVALID_PARAMETER Request Id is unknown
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SystemDefenseStatus", pStatus))
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSystemDefenseStatus_F) != S_OK)
		return E_ACCESSDENIED;

	uint32_t Status;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetSystemDefenseStatus(Status);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pStatus = (SHORT)Status;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetNetworkSettings(SHORT ConnectionType,    // WIRED, WIRELESS
												SHORT* pDhcpEnabled,     // Both
												BSTR*  bstrIpAddress,    //Both
												BSTR*  bstrMacAddress,   //Both
												SHORT* pLinkStatus,      //Both
												SHORT* pWirelessControl, // WIRELESS
												SHORT* pWirelessConfEnabled) //WIRELESS
{

	if (pDhcpEnabled == nullptr ||
	    bstrIpAddress == nullptr ||
	    bstrMacAddress == nullptr ||
	    pLinkStatus == nullptr ||
	    pWirelessControl == nullptr ||
	    pWirelessConfEnabled == nullptr)
		return E_POINTER;
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"DhcpEnabled", pDhcpEnabled) &&
	    GetFromRegistry(L"DebugData", L"IpAddress", bstrIpAddress) &&
	    GetFromRegistry(L"DebugData", L"MacAddress", bstrMacAddress) &&
	    GetFromRegistry(L"DebugData", L"LinkStatus", pLinkStatus) &&
	    GetFromRegistry(L"DebugData", L"WirelessControl", pWirelessControl) &&
	    GetFromRegistry(L"DebugData", L"WirelessConfEnabled", pWirelessConfEnabled))
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

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetNetworkSettings(ConnectionType, DhcpEnabled,
	                            sIpAddress, sMacAddress, *pLinkStatus, *pWirelessControl, *pWirelessConfEnabled);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pDhcpEnabled = (SHORT)DhcpEnabled;
	ATL::CComBSTR bstr(sIpAddress.c_str());
	*bstrIpAddress = bstr.Detach();
	ATL::CComBSTR bstr1(sMacAddress.c_str());
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
	if (IPv6DefaultRouter == nullptr ||
	    PrimaryDNS == nullptr ||
	    SecondaryDNS == nullptr ||
	    pResponse == nullptr ||
	    pIpv6Enable == nullptr)
		return E_POINTER;
	/*
	 * AMT_STATUS_UNSUPPORTED	Returned if this FW SKU does not support IPv6. The status of IPv6 support can be retrieved by calling CFG_GetIPv6Settings.
	 * AMT_STATUS_INVALID_MESSAGE_LENGTH	Length field of header is invalid.
	 * AMT_STATUS_IPV6_INTERFACE_DISABLED	The IPv6 interface is currently disabled so there is no current IPv6 status available for this interface.
	 * AMT_STATUS_INTERFACE_DOES_NOT_EXIST	The network interface that is being referred to in this command does not exist (e.g. wireless interface on desktop)
	 */
#ifdef _DEBUG
	TCHAR addresses[2048];
	DWORD Ipv6Enable_ = 0;
	if (GetFromRegistry(L"DebugData", L"IPv6DefaultRouter", IPv6DefaultRouter) &&
	    GetFromRegistry(L"DebugData", L"PrimaryDNS", PrimaryDNS) &&
	    GetFromRegistry(L"DebugData", L"SecondaryDNS", SecondaryDNS) &&
	    GetFromRegistry(L"DebugData", L"IPv6Addresses", addresses, 2048) &&
	    GetFromRegistry(L"DebugData", L"Ipv6Enable", &Ipv6Enable_))
	{
		if (wcscmp((wchar_t*)IPv6DefaultRouter, L"exception") == 0)
			return E_FAIL;

		WCHAR *token;
		WCHAR seps[]   = L"|";
		unsigned long i = 0;
		long num = 0;

		for (i = 0; i < wcslen(addresses); i++)
			if (addresses[i] == L'|')
				num++;

		if (i > 0) // there is at least one word
			num++;

		SAFEARRAY *pSar ;
		wchar_t *context = nullptr;
		VariantInit(pResponse);
		pSar = SafeArrayCreateVector(VT_BSTR, 0, num) ;

		token = std::wcstok(addresses, seps, &context);
		num = 0;
		while (token != NULL)
		{
			ATL::CComBSTR bstr(token);
			SafeArrayPutElement(pSar, &num, bstr) ;
			token = std::wcstok(NULL, seps, &context);
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

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetIPv6NetworkSettings(ConnectionType, sIPv6DefaultRouter,
	                            sPrimaryDNS, sSecondaryDNS, Response, Ipv6Enable);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sIPv6DefaultRouter.c_str());
	*IPv6DefaultRouter = bstr.Detach();
	ATL::CComBSTR bstr1(sPrimaryDNS.c_str());
	*PrimaryDNS = bstr1.Detach();
	ATL::CComBSTR bstr2(sSecondaryDNS.c_str());
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
			ATL::CComBSTR bstrAddress(Response[i].c_str());
			bstrTmp = bstrAddress.Detach();
			SafeArrayPutElement(pSar, &i, bstrTmp);
		}
		pResponse->vt = VT_ARRAY | VT_BSTR;
		pResponse->parray = pSar;
	}
	catch(_com_error &err)
	{
		const TCHAR* reason =  err.ErrorMessage();
		UNS_DEBUG(L"com error %W\n", reason);
	}
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSystemUUID(BSTR* bstrUUID)
{
	if (bstrUUID == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_NOT_READY	Management controller has not progressed far enough in its initialization to process the command.
	*/
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SystemUUID", bstrUUID))
	{
		if (wcscmp(*bstrUUID, L"exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSystemUUID_F) != S_OK)
		return E_ACCESSDENIED;

	std::string sUUID;
	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetSystemUUID(sUUID);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(sUUID.c_str());
	*bstrUUID = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::OpenUserInitiatedConnection()
{
	UNS_DEBUG(L"CPTHI_Commands::OpenUserInitiatedConnection - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::CloseUserInitiatedConnection()
{
	/*
	AMT_STATUS_NOT_PERMITTED	Entity has no permission to close a connection.
	*/
	if (CheckCredentials(CloseUserInitiatedConnection_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.CloseUserInitiatedConnection();
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::TerminateKVMSession()
{
	UNS_DEBUG(L"CPTHI_Commands::TerminateKVMSession - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::GetKVMRedirectionState(VARIANT_BOOL* pEnabled, VARIANT_BOOL* pConnected)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"KVMRedirectionStateEnabled", (SHORT*)pEnabled))
	{
		if (GetFromRegistry(L"DebugData", L"KVMRedirectionStateConnected", (SHORT*)pConnected))
		{
			if ((*pEnabled == -1) || (*pConnected == -1))
				return E_FAIL;
		}
		return S_OK;
	}
#endif

	if (CheckCredentials(GetKVMRedirectionState_F) != S_OK)
		return E_ACCESSDENIED;

	bool enabled;
	bool connected;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetKVMRedirectionState(enabled, connected);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pEnabled = enabled ? TRUE : FALSE;
	*pConnected = connected ? TRUE : FALSE;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSpriteLanguage(SHORT*)
{
	UNS_DEBUG(L"CPTHI_Commands::GetSpriteLanguage - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::SetSpriteLanguage(SHORT Language)
{
	if (CheckCredentials(SetSpriteLanguage_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.SetSpriteLanguage(Language);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetSpriteZoom(SHORT*)
{
	UNS_DEBUG(L"CPTHI_Commands::GetSpriteZoom - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::GetSpriteParameters(SHORT* pLanguage, SHORT* pZoom)
{
	if (pLanguage == nullptr || pZoom == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"SpriteLanguage", pLanguage) &&
		GetFromRegistry(L"DebugData", L"SpriteZoom", pZoom))
	{
		if ((*pZoom == -1) || (*pLanguage == -1))
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetSpriteParameters_F) != S_OK)
		return E_ACCESSDENIED;

	unsigned short lang = 0;
	unsigned short zoom = 0;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetSpriteParameters(lang, zoom);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	*pLanguage = lang;
	*pZoom = zoom;

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::SetSpriteZoom(SHORT Zoom)
{
	if (CheckCredentials(SetSpriteZoom_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.SetSpriteZoom(Zoom);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	return S_OK;
}

STDMETHODIMP CPTHI_Commands::GetConfigurationInfo(SHORT* pControlMode,
												  SHORT* pProvisioningMethod,
												  BSTR* pCreationTimeStamp,
												  SAFEARRAY** ppCertHash)
{
	if (pControlMode == nullptr ||
		pProvisioningMethod == nullptr ||
		pCreationTimeStamp == nullptr ||
		ppCertHash == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ControlMode", pControlMode) &&
	    GetFromRegistry(L"DebugData", L"ProvisioningMethod", pProvisioningMethod) &&
	    GetFromRegistry(L"DebugData", L"CreationTimeStamp", pCreationTimeStamp))
	{
		if (*pControlMode == -1)
			return E_FAIL;

		BYTE Data[1024];
		ULONG len = 1024;
		if (GetFromRegistry(L"DebugData", L"CertHash", Data, &len))
		{
			ATL::CComSafeArray<BYTE> hashdata(len);
			for (LONG i = 0; i < len ; i++)
			{
				hashdata[i] = Data[i];
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

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetConfigurationInfo(*pControlMode, *pProvisioningMethod, CreationTimeStampStr, CertHash);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(CreationTimeStampStr.c_str());
	*pCreationTimeStamp = bstr.Detach();
	ATL::CComSafeArray<BYTE> hashdata(CertHash.size());
	for (size_t i = 0; i < CertHash.size(); i++)
	{
		hashdata[(LONG)i] = CertHash[i];
	}
	*ppCertHash = hashdata.Detach();
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::TerminateRemedySessions()
{
	UNS_DEBUG(L"CPTHI_Commands::TerminateRemedySessions\n");
#ifdef _DEBUG
	SHORT result;
	if (GetFromRegistry(L"DebugData", L"TerminateRemedySessions", &result))
	{
		if (result == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(TerminateRemedySessions_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.TerminateRemedySessions();
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::GetUserConsentState(SHORT* pState, USER_CONSENT_POLICY* pPolicy)
{
	if (pState == nullptr || pPolicy == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	SHORT UserConsentPolicy = 0;
	if (GetFromRegistry(L"DebugData", L"UserConsentState", pState) &&
	    GetFromRegistry(L"DebugData", L"UserConsentPolicy", &UserConsentPolicy))
	{
		if (*pState == -1)
			return E_FAIL;
		*pPolicy = (USER_CONSENT_POLICY)UserConsentPolicy;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetUserConsentState_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetUserConsentState(*pState, *pPolicy);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::GetWLANLinkInfo(UINT* pPreference, UINT* pControl, UINT* pProtection)
{
	if (pControl == nullptr || pProtection == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"WLANLinkPreference", (SHORT*)pPreference) &&
		GetFromRegistry(L"DebugData", L"WLANLinkControl", (SHORT*)pControl) &&
	    GetFromRegistry(L"DebugData", L"WLANLinkProtection", (SHORT*)pProtection))
	{
		if (*pPreference == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetWLANLinkInfo_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetWLANLinkInfo(*pPreference, *pControl, *pProtection);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::SetLinkPreferenceToHost()
{
	UNS_DEBUG(L"CPTHI_Commands::SetLinkPreferenceToHost\n");
#ifdef _DEBUG
	SHORT result;
	if (GetFromRegistry(L"DebugData", L"SetLinkPreferenceToHost", &result))
	{
		if (result == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(SetLinkPreferenceToHost_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.SetLinkPreferenceToHost();
	return LMSError2HRESULT(err);
}
STDMETHODIMP CPTHI_Commands::InitiateUserConnection(SHORT* pStatus)
{

	if (pStatus == nullptr)
		return E_POINTER;
	/*
	AMT_STATUS_NOT_PERMITTED	Entity has no permission to open a connection..
	AMT_STATUS_INTERNAL_ERROR	The operation could not be completed by AMT.
	AMT_STATUS_DATA_MISSING		No connectivity policy configured when AMT is outside the enterprise network.
	*/
	if (CheckCredentials(InitiateUserConnection_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.InitiateUserConnection(*pStatus);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::userInitiatedPolicyRuleExists(SHORT* pStatus)
{
	if (pStatus == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"userInitiatedPolicyRuleExists", pStatus))
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(userInitiatedPolicyRuleExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.userInitiatedPolicyRuleExists(*pStatus);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::userInitiatedPolicyRuleForLocalMpsExists(SHORT* pStatus)
{
	if (pStatus == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"userInitiatedPolicyRuleForLocalMpsExists", pStatus))
	{
		if (*pStatus == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(UserInitiatedPolicyRuleForLocalMpsExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.userInitiatedPolicyRuleForLocalMpsExists(*pStatus);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::snmpEventSubscriberExists(SHORT* pExist)
{

	if (pExist == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"snmpEventSubscriberExists", pExist))
	{
		if (*pExist == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(snmpEventSubscriberExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.snmpEventSubscriberExists(*pExist);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::CILAFilterCollectionSubscriptionExists(SHORT* pExist)
{
	if (pExist == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"CILAFilterCollectionSubscriptionExists", pExist))
	{
		if (*pExist == -1)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(CILAFilterCollectionSubscriptionExists_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.CILAFilterCollectionSubscriptionExists(*pExist);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::UpdateScreenSettings(EXTENDED_DISPLAY_PARAMETERS)
{
	UNS_DEBUG(L"CPTHI_Commands::UpdateScreenSettings - deprecated\n");
	return E_NOINTERFACE;
}

STDMETHODIMP CPTHI_Commands::UpdateScreenSettings2(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, SHORT numOfDisplays)
{
	if (CheckCredentials(UpdateScreenSettings_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.UpdateScreenSettings2(eExtendedDisplayParameters, numOfDisplays);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::GetRedirectionSessionLinkTechnology(REDIRECTION_SESSION_TYPE sessionType, SHORT* pLinkTechnology)
{
	if (pLinkTechnology == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"RedirectionSessionLinkTechnology", (SHORT*)pLinkTechnology))
	{
		if (*pLinkTechnology == -1)
			return E_FAIL;
		return S_OK;
	}
#endif
	if (CheckCredentials(GetRedirectionSessionLinkTechnology_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::PTHI_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetRedirectionSessionLinkTechnology(sessionType, *pLinkTechnology);
	return LMSError2HRESULT(err);
}

STDMETHODIMP CPTHI_Commands::IsRebootAfterProvisioningNeeded(VARIANT_BOOL *pNeeded)
{
	if (pNeeded == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CPTHI_Commands::IsRebootAfterProvisioningNeeded - deprecated\n");
	*pNeeded = false;
	return S_OK;
}

STDMETHODIMP CPTHI_Commands::ProxyAddProxyEntry(BSTR,
												USHORT,
												SAFEARRAY*,
												BSTR)

{
	UNS_DEBUG(L"CPTHI_Commands::ProxyAddProxyEntry - deprecated\n");
	return E_NOINTERFACE;
}

inline std::string ConvertBStrToString(BSTR bstr)
{
	USES_CONVERSION;

	return (SysStringLen(bstr) == 0) ? std::string() : std::string(ATL::CW2A(bstr));
}
