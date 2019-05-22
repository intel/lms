/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: Manageability_Commands.cpp

--*/

// Manageability_Commands.cpp : Implementation of CManageability_Commands

#include "stdafx.h"
#include "Manageability_Commands.h"
#include "Manageability_Commands_BE.h"
#include "UNSRegistry.h"
#include "atlsafe.h"
#include "DataStorageGenerator.h"

// CManageability_Commands

HRESULT CManageability_Commands::GetTheFeatureState(FEATURES feat, FEATURE_STATE* pState)
{
#ifdef _DEBUG
	SHORT dbg_feat,state;
	switch (feat) 
		{
			case TDT:
				if ((GetFromRegistry(L"DebugData", L"ATState", &dbg_feat) == true)&&
					(GetFromRegistry(L"DebugData", L"GetATState_State", &state) == true))
				{
					*pState=(FEATURE_STATE)state;
					return S_OK;
				}
				break;
			case AMT:
			case IRWT:
			case QST:
			case SOFTCREEK:
			case VE:
			case DT:
			case NAND:
			case MPC:
			case ICC_OVER_CLOCK_IN:
			case PAV:
			case SPK:
			case RCA:
			case RPAT:
			case IPV6:
			case KVM:
			case OCH:
			case DAL:
			case TLS:
			case CILA:
			case LAKEHOUSTON:
				if ((GetFromRegistry(L"DebugData", L"GetTheFeatureState_Feat", &dbg_feat) == true)&&
					(GetFromRegistry(L"DebugData", L"GetTheFeatureState_State", &state) == true))
				{
					*pState=(FEATURE_STATE)state;
					return S_OK;
				}
				break;
	}
	
#endif

	if (CheckCredentials(GetTheFeatureState_F) != S_OK)
		return E_ACCESSDENIED;

	if (pState==NULL)
		return E_POINTER;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetTheFeatureState(feat, *pState);
	switch (err)
	{
	case Intel::LMS::ERROR_OK:
		return S_OK;
	case Intel::LMS::ERROR_INVALIDARG:
		return E_INVALIDARG;
	case Intel::LMS::ERROR_NOT_AVAILABLE_NOW:
		return E_NOT_VALID_STATE;
	}
	return E_FAIL;
}

HRESULT CManageability_Commands::GetFeaturesState(SAFEARRAY** ppStates)
{
	if (CheckCredentials(GetFeaturesState_F) != S_OK)
		return E_ACCESSDENIED;
	std::vector<FEATURE_STATE> states;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetFeaturesState(states);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE; 
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;

	CComSafeArray<SHORT> StatesArr(FEATURES_NUM);
	for(int i = 0; i < FEATURES_NUM; i++)
		StatesArr[i] = (ATL::_ATL_AutomationType<SHORT>::_typewrapper)states[i];
	*ppStates = StatesArr.Detach();

	return S_OK;	
}

HRESULT CManageability_Commands::GetCustomerType(CUSTOMER_TYPE* pType)
{
#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetCustomerType", &val) == true)
	{
		*pType=(CUSTOMER_TYPE)val;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetCustomerType_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetCustomerType(*pType);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE; 
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

HRESULT CManageability_Commands::GetPlatformType(PLATFORM_TYPE* pType)
{
#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetPlatformType", &val) == true)
	{
		*pType=(PLATFORM_TYPE)val;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetPlatformType_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetPlatformType(*pType);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE; 
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}

HRESULT CManageability_Commands::GetMenageabiltyMode(MENAGEABILTY_MODE* pMode)
{
#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetMenageabiltyMode", &val) == true)
	{
		*pMode=(MENAGEABILTY_MODE)val;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetMenageabiltyMode_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetMenageabiltyMode(*pMode);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE; 
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	return S_OK;
}
HRESULT CManageability_Commands::GetFWInfo(BSTR* pMEBxVersion, ULONG* pBiosBootState, VARIANT_BOOL* pCryptoFuseEnable, VARIANT_BOOL* pLocalFWupdateEnable)
{
#ifdef _DEBUG
	if ((GetFromRegistry(L"DebugData", L"MEBxVersion", pMEBxVersion)) &&
		(GetFromRegistry(L"DebugData", L"BiosBootState", pBiosBootState)) &&
		(GetFromRegistry(L"DebugData", L"CryptoFuseEnable", pCryptoFuseEnable)) &&
		(GetFromRegistry(L"DebugData", L"LocalFWupdateEnable", pLocalFWupdateEnable)))
	{
		return S_OK;
	}
#endif

	if (CheckCredentials(GetFWInfo_F) != S_OK)
		return E_ACCESSDENIED;
	std::string MEBxVersion;
	unsigned long BiosBootState;
	bool CryptoFuseEnable;
	bool LocalFWupdateEnable;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetFWInfo(MEBxVersion, BiosBootState, CryptoFuseEnable, LocalFWupdateEnable);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE; 
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;
	CComBSTR bstr(MEBxVersion.c_str());
	*pMEBxVersion = bstr.Detach();
	*pBiosBootState = BiosBootState;
	*pCryptoFuseEnable = CryptoFuseEnable;
	*pLocalFWupdateEnable = LocalFWupdateEnable;
	return S_OK;
}

HRESULT CManageability_Commands::GetPMCVersion(BSTR* pFwVer)
{
#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetPMCVersion", &val) == true)
	{
		return S_OK;
	}
#endif

	if (CheckCredentials(GetPMCVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string FwVer;

	Intel::LMS::LMS_ERROR err = Intel::LMS::Manageability_Commands_BE(GetGmsPortForwardingStarted()).GetPMCVersion(FwVer);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;

	CComBSTR bstr(FwVer.c_str());
	*pFwVer = bstr.Detach();

	return S_OK;
}