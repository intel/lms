/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"
#include "WMIHelper.h"
   
void WMIHelper::PTHIHandleSetStatus(IWbemServices* pNamespace,
									IWbemObjectSink  __RPC_FAR* pResponseHandler,
									unsigned long ReturnValue,
									HRESULT& hr)
{
	hr = WBEM_E_FAILED;
	ReturnValue = WMI_E_MESTATUS_BASE + ReturnValue;

	if (WMIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue) != STATUS_SUCCESS)
	{
		hr = WBEM_E_PROVIDER_FAILURE;
	}
}

bool WMIHelper::isMethodCallStatic(const BSTR strObjectPath)
{
	if (strObjectPath != NULL)
	{
		std::wstring objectPath(strObjectPath);
		size_t indexOfDot = objectPath.find(L".");
		if (indexOfDot == std::wstring::npos)
		{
			return true;
		}
	}
	return false;
}



