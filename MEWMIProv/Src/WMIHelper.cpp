/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2020 Intel Corporation
 */
#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"
#include "WMIHelper.h"
   
void WMIHelper::PTHIHandleSetStatus(IWbemServices* pNamespace,
									IWbemObjectSink  __RPC_FAR* pResponseHandler,
									unsigned long ReturnValue,
									uint32& hr)
{
	hr = WBEM_E_FAILED;

	if (ReturnValue == WMI_E_HECI_CONNECTION ||
		ReturnValue == WMI_E_PTHI_CLIENT_CONNECTION ||
		ReturnValue == WMI_E_FWUPD_CLIENT_CONNECTION ||
		ReturnValue == WMI_E_UPID_CLIENT_CONNECTION)
	{
		hr = WBEM_E_CONNECTION_FAILED;
	}				
	else
	{
		ReturnValue = WMI_E_MESTATUS_BASE + ReturnValue;
	}

	if (WMIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue) != STATUS_SUCCESS)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
	}


}

bool WMIHelper::isMethodCallStatic(const BSTR strObjectPath)
{
	if (strObjectPath != NULL)
	{
		
		wstring objectPath(strObjectPath);
		size_t indexOfDot = objectPath.find(L".");
		if (indexOfDot == wstring::npos)
		{
			return true;
		}
	}
	return false;
}



