/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
/*++

@file: Manageability_Commands.cpp

--*/

// Manageability_Commands.cpp : Implementation of CManageability_Commands

#include "global.h"
#include "stdafx.h"
#include "Manageability_Commands.h"
#include "Manageability_Commands_BE.h"
#include "UNSRegistry.h"
#include "atlsafe.h"
#include "DataStorageGenerator.h"

// CManageability_Commands
HRESULT CManageability_Commands::GetTheFeatureState(FEATURES feat, FEATURE_STATE* pState)
{
	if (pState == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	SHORT dbg_feat,state;
	switch (feat)
		{
			case TDT:
				if (GetFromRegistry(L"DebugData", L"ATState", &dbg_feat) &&
				    GetFromRegistry(L"DebugData", L"GetATState_State", &state))
				{
					*pState = (FEATURE_STATE)state;
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
				if (GetFromRegistry(L"DebugData", L"GetTheFeatureState_Feat", &dbg_feat) &&
				    GetFromRegistry(L"DebugData", L"GetTheFeatureState_State", &state))
				{
					*pState = (FEATURE_STATE)state;
					return S_OK;
				}
				break;
	}
#endif

	if (CheckCredentials(GetTheFeatureState_F) != S_OK)
		return E_ACCESSDENIED;


	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetTheFeatureState(feat, *pState);
	return LMSError2HRESULT(err);
}

HRESULT CManageability_Commands::GetFeaturesState(SAFEARRAY** ppStates)
{
	if (ppStates == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CManageability_Commands::GetFeaturesState - deprecated\n");
	return E_NOTIMPL;
}

HRESULT CManageability_Commands::GetCustomerType(CUSTOMER_TYPE* pType)
{
	if (pType == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetCustomerType", &val))
	{
		*pType = (CUSTOMER_TYPE)val;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetCustomerType_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetCustomerType(*pType);
	return LMSError2HRESULT(err);
}

HRESULT CManageability_Commands::GetPlatformType(PLATFORM_TYPE* pType)
{
	if (pType == nullptr)
		return E_POINTER;

	UNS_DEBUG(L"CManageability_Commands::GetPlatformType - deprecated\n");
	return E_NOTIMPL;
}

HRESULT CManageability_Commands::GetMenageabiltyMode(MENAGEABILTY_MODE* pMode)
{
	if (pMode == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetMenageabiltyMode", &val))
	{
		*pMode = (MENAGEABILTY_MODE)val;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetMenageabiltyMode_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetMenageabiltyMode(*pMode);
	return LMSError2HRESULT(err);
}
HRESULT CManageability_Commands::GetFWInfo(BSTR* pMEBxVersion, ULONG* pBiosBootState, VARIANT_BOOL* pCryptoFuseEnable, VARIANT_BOOL* pLocalFWupdateEnable)
{

	if (pMEBxVersion == nullptr ||
	    pBiosBootState == nullptr ||
	    pCryptoFuseEnable == nullptr ||
	    pLocalFWupdateEnable == nullptr)
	{
		return E_POINTER;
	}

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

	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetFWInfo(MEBxVersion, BiosBootState, CryptoFuseEnable, LocalFWupdateEnable);
	if (err != Intel::LMS::LMS_ERROR::OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(MEBxVersion.c_str());
	*pMEBxVersion = bstr.Detach();
	*pBiosBootState = BiosBootState;
	*pCryptoFuseEnable = CryptoFuseEnable;
	*pLocalFWupdateEnable = LocalFWupdateEnable;

	return S_OK;
}

HRESULT CManageability_Commands::GetPMCVersion(BSTR* pFwVer)
{
	if (pFwVer == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	SHORT val;
	if (GetFromRegistry(L"DebugData", L"GetPMCVersion", &val))
	{
		return S_OK;
	}
#endif

	if (CheckCredentials(GetPMCVersion_F) != S_OK)
		return E_ACCESSDENIED;

	std::string FwVer;

	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetPMCVersion(FwVer);
	if (err != Intel::LMS::LMS_ERROR::OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(FwVer.c_str());
	*pFwVer = bstr.Detach();

	return S_OK;
}

STDMETHODIMP CManageability_Commands::IsMeasuredBootState(VARIANT_BOOL *pState)
{
	if (pState == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"IsMeasuredBootState", (SHORT*)pState))
	{
		return S_OK;
	}
#endif

	if (CheckCredentials(IsMeasuredBootState_F) != S_OK)
		return E_ACCESSDENIED;

	bool state;

	Intel::LMS::Manageability_Commands_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.IsMeasuredBootState(state);
	if (err != Intel::LMS::LMS_ERROR::OK)
		return LMSError2HRESULT(err);

	*pState = state ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}
