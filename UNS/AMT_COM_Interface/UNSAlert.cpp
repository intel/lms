/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: UNSAlert.cpp

--*/

// UNSAlert.cpp : Implementation of CUNSAlert
#include "global.h"
#include "stdafx.h"
#include "UNSAlert.h"
#include "UNSAlert_BE.h"
#include "resource.h"
#include "DataStorageGenerator.h"
#include "UNSRegistry.h"


// CUNSAlert
STDMETHODIMP CUNSAlert::RiseAlert(USHORT category,
								  ULONG id,
								  BSTR message,
								  BSTR messageArg,
								  BSTR messageID, 
								  BSTR dateTime)
{
	UNS_DEBUG(L"CUNSAlert::RiseAlert\n");
	Fire_Alert(category, id, message, messageArg, messageID, dateTime);
	return S_OK;
}

STDMETHODIMP CUNSAlert::GetIMSSEventHistory(BSTR* bstrEventHistory)
{
	if (bstrEventHistory == nullptr)
		return E_POINTER;

#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"GetIMSSEventHistory", bstrEventHistory))
	{
		if (strcmp((char *)bstrEventHistory, "exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetIMSSEventHistory_F) != S_OK)
		return E_ACCESSDENIED;

	UNS_DEBUG(L"CUNSAlert::GetIMSSEventHistory\n");
	std::wstring EventHistory;

	Intel::LMS::UNSAlert_BE be(GetGmsPortForwardingPort());
	Intel::LMS::LMS_ERROR err = be.GetIMSSEventHistory(EventHistory);
	if (err != Intel::LMS::LMS_ERROR::OK)
		return LMSError2HRESULT(err);

	ATL::CComBSTR bstr(EventHistory.c_str());
	*bstrEventHistory = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CUNSAlert::ResetUNSstartedEvent()
{
	UNS_DEBUG(L"CUNSAlert::ResetUNSstartedEvent - deprecated\n");
	return E_NOTIMPL;
}
