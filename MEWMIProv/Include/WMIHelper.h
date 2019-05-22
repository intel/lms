/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#ifndef __WMIUTILS_H
#define __WMIUTILS_H

#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"

#define ERROR_HANDLER(ReturnValue) \
		if (ReturnValue != S_OK) \
		{ \
			if (ReturnValue != WMI_E_HECI_CONNECTION && \
				ReturnValue != WMI_E_PTHI_CLIENT_CONNECTION && \
				ReturnValue != WMI_E_FWUPD_CLIENT_CONNECTION) \
			{ \
				ReturnValue = WMI_E_MESTATUS_BASE + ReturnValue; \
			} \
		} 



class WMIHelper 
{
public:
	static void PTHIHandleSetStatus(IWbemServices* pNamespace,
									IWbemObjectSink  __RPC_FAR* pResponseHandler,
									unsigned long ReturnValue,
									uint32& hr);
	static bool isMethodCallStatic(const BSTR strObjectPath);
};



inline string ToStr(const wstring& t)
{
	size_t len = t.length();
	if (len < 1)
		return string();
	string buff(len, '\0');
	size_t count;
	::wcstombs_s(&count, &buff.at(0), len+1, t.c_str(), len+1);
	if (count < len)
		buff.resize(count);
	return buff;
}

#endif