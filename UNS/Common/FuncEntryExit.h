/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#include <stdint.h>
void FlowLog(const wchar_t * pref, const wchar_t * func);
void FuncEntry(const wchar_t * func);
void FuncExit(const wchar_t * func);
void FuncExitWithStatus(const wchar_t * func, uint64_t status);


template<typename T>
class FuncEntryExit
{
public:
	FuncEntryExit(const wchar_t * func, const T & status): func_(func), status_(status) 
	{
		FuncEntry(func_);
	}
	~FuncEntryExit()
	{
		FuncExitWithStatus(func_, status_);
	}

private:
	const wchar_t * func_;
	const T & status_;
};


template<>
class FuncEntryExit<void>
{
public:
	FuncEntryExit(const wchar_t * func): func_(func)
	{
		FuncEntry(func_);
	}
	~FuncEntryExit()
	{
		FuncExit(func_);
	}

private:
	const wchar_t * func_;
};

