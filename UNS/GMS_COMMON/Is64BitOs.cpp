/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
 #ifdef _WIN32
#include "Is64BitOs.h"

#include <windows.h>
#include <tchar.h>


HMODULE SafeLoadDll(const TCHAR * FileName)
{
	auto back_slash = _TEXT("\\");
	auto dll_name_size =  _tcslen(back_slash) +  _tcslen(FileName);

	if (MAX_PATH<dll_name_size)
	{
		return NULL;
	}

	TCHAR full_path[MAX_PATH] = { 0 };
	auto buffer_size = ::GetSystemDirectory(full_path, MAX_PATH-dll_name_size);
	if (MAX_PATH-dll_name_size < buffer_size)
	{
		//something really wrong, logger?
		return NULL;
	}

	auto cat_res = _tcsncat_s(full_path, back_slash, _tcslen(back_slash));
	if (cat_res != 0)
	{
		//something really wrong, logger?
		return NULL;
	}
	cat_res = _tcsncat_s(full_path, FileName, _tcslen(FileName));
	if (cat_res != 0)
	{
		//something really wrong, logger?
		return NULL;
	}
	return LoadLibrary(full_path);
}



bool Is64BitOS()
{
	static BOOL bChecked = FALSE;
	static BOOL bIs64BitOS = FALSE;

	if (!bChecked)
	{
		bChecked = TRUE;

		auto hKernel32dll = SafeLoadDll(_TEXT("kernel32.dll"));
		if (hKernel32dll == NULL)
		{
			/* Failed to load kernel32.dll! assuming 32 bit os */
			return false;
		}
		typedef BOOL (WINAPI *FN_IS_WOW_64_PROCESS) (HANDLE, PBOOL);
		FN_IS_WOW_64_PROCESS fnIsWow64Process = (FN_IS_WOW_64_PROCESS)GetProcAddress(hKernel32dll, "IsWow64Process");
		if (fnIsWow64Process == NULL)
		{
			/*Couldn't get proc address for IsWow64Process - assuming 32 bit os.
			This could happen in windows 2000 and that's ok*/
			FreeLibrary(hKernel32dll);
			return false;
		}

		if (!fnIsWow64Process(GetCurrentProcess(), &bIs64BitOS))
		{
			/*IsWow64Process failed - assuming 32 bit os.*/
			FreeLibrary(hKernel32dll);
			return false;
		}

		FreeLibrary(hKernel32dll);
	}

	return bIs64BitOS ? true : false;
}
#endif
