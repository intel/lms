/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#ifndef __WMIUTILS_H
#define __WMIUTILS_H

#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"
#include "DebugPrints.h"

#define ERROR_HANDLER(ReturnValue) \
		if (ReturnValue != S_OK) \
		{ \
			ReturnValue = WMI_E_MESTATUS_BASE + ReturnValue; \
		} 

HRESULT IsUserAdmin();

class WMIHelper 
{
public:
	static void PTHIHandleSetStatus(IWbemServices* pNamespace,
									IWbemObjectSink  __RPC_FAR* pResponseHandler,
									unsigned long ReturnValue,
									HRESULT& hr);
	static bool isMethodCallStatic(const BSTR strObjectPath);
};

inline std::string ToStr(const std::wstring& t)
{
	size_t len = t.length();
	if (len < 1)
		return std::string();
	std::string buff(len, '\0');
	size_t count;
	::wcstombs_s(&count, &buff.at(0), len+1, t.c_str(), len+1);
	if (count < len)
		buff.resize(count);
	return buff;
}

class EntryExitLog
{
public:
	EntryExitLog(const char *func, const uint32 &ret, const HRESULT &hr) :
		func_(func), ret_(ret), hr_(hr)
	{
		UNS_DEBUG("--> %C\n", func_);
	}
	~EntryExitLog()
	{
		UNS_DEBUG("<-- %C 0x%X 0x%X\n", func_, ret_, hr_);
	}

private:
	const char *func_;
	const uint32 &ret_;
	const HRESULT &hr_;
};

class EntryExitLogShort
{
public:
	EntryExitLogShort(const char* func, const HRESULT& hr) : func_(func), hr_(hr)
	{
		UNS_DEBUG("--> %C\n", func_);
	}
	~EntryExitLogShort()
	{
		UNS_DEBUG("<-- %C 0x%X\n", func_, hr_);
	}

private:
	const char* func_;
	const HRESULT& hr_;
};

#endif