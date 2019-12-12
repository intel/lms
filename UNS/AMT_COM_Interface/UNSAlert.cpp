/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
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

	Intel::LMS::UNSAlert_BE be(GetGmsPortForwardingStarted());
	Intel::LMS::LMS_ERROR err = be.GetIMSSEventHistory(EventHistory);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;

	ATL::CComBSTR bstr(EventHistory.c_str());
	*bstrEventHistory = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CUNSAlert::ResetUNSstartedEvent()
{
	UNS_DEBUG(L"CUNSAlert::ResetUNSstartedEvent\n");
	HANDLE hUNSstarted = OpenEvent(EVENT_MODIFY_STATE, FALSE, L"Global\\UNSstarted");
	if (hUNSstarted == nullptr)
	{
		UNS_DEBUG(L"CUNSAlert::OpenEvent UNSstarted failed, err=%d\n", GetLastError());
		if (GetLastError() == 5)
			return E_ACCESSDENIED;
		else
			return E_HANDLE;
	}

	if (!ResetEvent(hUNSstarted))
	{
		UNS_DEBUG(L"CUNSAlert::ResetEvent UNSstarted failed, err=%d\n", GetLastError());
		CloseHandle(hUNSstarted);
		return E_FAIL;
	}

	CloseHandle(hUNSstarted);
	return S_OK;
}
