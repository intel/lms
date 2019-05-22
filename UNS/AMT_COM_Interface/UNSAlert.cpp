/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: UNSAlert.cpp

--*/

// UNSAlert.cpp : Implementation of CUNSAlert

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
	DbgPrintW(L"CUNSAlert::RiseAlert\n");
	Fire_Alert(category,id,message,messageArg,messageID,dateTime);
	return S_OK;
}

STDMETHODIMP CUNSAlert::GetIMSSEventHistory(BSTR* bstrEventHistory)
{
#ifdef _DEBUG
	if (GetFromRegistry(L"DebugData", L"GetIMSSEventHistory", bstrEventHistory) == true)
	{
		if (strcmp((char*)bstrEventHistory, "exception") == 0)
			return E_FAIL;
		return S_OK;
	}
#endif

	if (CheckCredentials(GetIMSSEventHistory_F) != S_OK)
		return E_ACCESSDENIED;

	DbgPrintW(L"CUNSAlert::GetIMSSEventHistory\n");
	std::wstring EventHistory;
	Intel::LMS::LMS_ERROR err = Intel::LMS::UNSAlert_BE(GetGmsPortForwardingStarted()).GetIMSSEventHistory(EventHistory);
	if (err == Intel::LMS::ERROR_NOT_AVAILABLE_NOW)
		return E_NOT_VALID_STATE;
	if (err != Intel::LMS::ERROR_OK)
		return E_FAIL;

	CComBSTR bstr(EventHistory.c_str());
	*bstrEventHistory = bstr.Detach();
	return S_OK;
}

STDMETHODIMP CUNSAlert::ResetUNSstartedEvent()
{
	DbgPrintW(L"CUNSAlert::ResetUNSstartedEvent\n");
	HANDLE hUNSstarted=OpenEvent(EVENT_MODIFY_STATE,FALSE,L"Global\\UNSstarted");
	if (hUNSstarted==NULL)
	{
		DbgPrintW(L"CUNSAlert::OpenEvent UNSstarted failed, err=%d\n",GetLastError());
		if (GetLastError()==5)
			return E_ACCESSDENIED;
		else
			return E_HANDLE;
	}
	if (!ResetEvent(hUNSstarted))
	{
		DbgPrintW(L"CUNSAlert::ResetEvent UNSstarted failed, err=%d\n",GetLastError());
		CloseHandle(hUNSstarted);
		return E_FAIL;
	}
	CloseHandle(hUNSstarted);
	return S_OK;
}


