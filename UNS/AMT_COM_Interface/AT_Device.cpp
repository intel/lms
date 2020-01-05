/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: AT_Device.cpp

--*/

// AT_Device.cpp : Implementation of CAT_Device

#include "stdafx.h"
#include "atlsafe.h"
#include "AT_Device.h"
#include "AT_Device_BE.h"
#include "UNSRegistry.h"
#include "DataStorageGenerator.h"
// CAT_Device


STDMETHODIMP CAT_Device::GetATDeviceInfo(SHORT* pState, BSTR* bstrInfo)
{
	if (pState == nullptr || bstrInfo == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"ATState", pState))
	{
		return S_OK;
	}
#endif

	if (CheckCredentials(GetATDeviceInfo_F) != S_OK)
		return E_ACCESSDENIED;

	Intel::LMS::LMS_ERROR err = Intel::LMS::AT_Device_BE(GetGmsPortForwardingStarted()).GetATDeviceInfo(*pState);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	char ValueStr[512];
	memset(ValueStr, 0, 512);
	ATL::CComBSTR bstr(ValueStr);
	*bstrInfo = bstr.Detach();

	return S_OK;
}

STDMETHODIMP CAT_Device::GetAuditLogs(BSTR* bstrAuditLogs)
{
	if (bstrAuditLogs == nullptr)
		return E_POINTER;

	if (CheckCredentials(GetAuditLogs_F) != S_OK)
		return E_ACCESSDENIED;

	std::string AuditLogs;
	
	Intel::LMS::LMS_ERROR err = Intel::LMS::AT_Device_BE(GetGmsPortForwardingStarted()).GetAuditLogs(AuditLogs);
	if (err != Intel::LMS::ERROR_OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(AuditLogs.c_str());
	*bstrAuditLogs = bstr.Detach();
	return S_OK;
}