/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
#ifndef FUNCENTRYEXIT_H
#define FUNCENTRYEXIT_H
#include "GMSCommonDllExport.h"

GMS_COMMON_EXPORT void FlowLog(const wchar_t *name, const wchar_t *pref, const wchar_t *func);
GMS_COMMON_EXPORT void FuncEntry(const wchar_t *name, const wchar_t *func);
GMS_COMMON_EXPORT void FuncExit(const wchar_t *name, const wchar_t *func);
GMS_COMMON_EXPORT void FuncExitWithStatus(const wchar_t * name, const wchar_t *func, uint64_t status);

template<typename T, typename O>
class FuncEntryExit_
{
public:
	FuncEntryExit_(const O* obj, const wchar_t * func, const T & status) :
		name_(obj->short_name()), func_(func), status_(status)
	{
		FuncEntry(name_, func_);
	}
	~FuncEntryExit_()
	{
		FuncExitWithStatus(name_, func_, status_);
	}

private:
	const wchar_t * name_;
	const wchar_t * func_;
	const T & status_;
};

template<typename O>
class FuncEntryExit_<void, O>
{
public:
	FuncEntryExit_(const O* obj, const wchar_t * func) : name_(obj->short_name()), func_(func)
	{
		FuncEntry(name_, func_);
	}
	~FuncEntryExit_()
	{
		FuncExit(name_, func_);
	}

private:
	const wchar_t * name_;
	const wchar_t * func_;
};
#endif // FUNCENTRYEXIT_H