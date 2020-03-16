/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
#include <sstream>
#include "global.h"
#include "FuncEntryExit.h"

void FlowLog(const wchar_t *name, const wchar_t *pref, const wchar_t *func)
{
	std::wstringstream ss;

	ss << name << L": " << pref << func;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}

void FuncEntry(const wchar_t *name, const wchar_t *func)
{
	FlowLog(name, L"--> ", func);
}

void FuncExit(const wchar_t *name, const wchar_t *func)
{
	FlowLog(name, L"<-- ", func);
}

void FuncExitWithStatus(const wchar_t *name, const wchar_t *func, uint64_t status)
{
	std::wstringstream ss;

	ss << name << L": <-- " << func << L" Status: " << status;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}