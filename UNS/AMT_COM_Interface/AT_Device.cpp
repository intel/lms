/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
/*++

@file: AT_Device.cpp

--*/

// AT_Device.cpp : Implementation of CAT_Device

#include "global.h"
#include "stdafx.h"
#include "atlsafe.h"
#include "AT_Device.h"
#include "AT_Device_BE.h"
#include "UNSRegistry.h"
#include "DataStorageGenerator.h"


STDMETHODIMP CAT_Device::GetATDeviceInfo(SHORT*, BSTR*)
{
	UNS_DEBUG(L"CAT_Device::GetATDeviceInfo - deprecated\n");
	return E_NOTIMPL;
}

STDMETHODIMP CAT_Device::GetAuditLogs(BSTR* bstrAuditLogs)
{
	if (bstrAuditLogs == nullptr)
		return E_POINTER;

	if (CheckCredentials(GetAuditLogs_F) != S_OK)
		return E_ACCESSDENIED;

	std::string AuditLogs;
	
	Intel::LMS::LMS_ERROR err = Intel::LMS::AT_Device_BE(GetGmsPortForwardingStarted()).GetAuditLogs(AuditLogs);
	if (err != Intel::LMS::LMS_ERROR::OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(AuditLogs.c_str());
	*bstrAuditLogs = bstr.Detach();
	return S_OK;
}