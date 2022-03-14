//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2022 Intel Corporation

#include <string>
#include <windows.h>
#include "WMIRegistrationService.h"

namespace WMIRegistrationService
{
	const std::wstring& reg_name = L"SYSTEM\\CurrentControlSet\\Services\\WMIRegistrationService\\UninstallIMSS";

	bool RegistryRead(const std::wstring& name, unsigned long& value)
	{
		bool ret;
		LSTATUS res;
		HKEY hKey;
		unsigned long valsz = sizeof(value);

		res = RegOpenKeyExW(HKEY_LOCAL_MACHINE, reg_name.c_str(), 0, KEY_QUERY_VALUE, &hKey);
		if (res != ERROR_SUCCESS)
		{
			DbgPrint(L"RegOpenKeyExW falied %d", res);
			return false;
		}

		res = RegGetValueW(hKey, NULL, name.c_str(), RRF_RT_REG_DWORD, NULL, &value, &valsz);
		if (res != ERROR_SUCCESS)
		{
			DbgPrint(L"RegGetValueW falied %d", res);
			ret = false;
		}
		else
		{
			ret = true;

		}
		RegCloseKey(hKey);

		return ret;
	}

	bool RegistryWrite(const std::wstring& name, unsigned long value)
	{
		bool ret;
		LSTATUS res;
		HKEY hKey;
		unsigned long valsz = sizeof(value);

		res = RegOpenKeyExW(HKEY_LOCAL_MACHINE, reg_name.c_str(), 0, KEY_SET_VALUE, &hKey);
		if (res != ERROR_SUCCESS)
		{
			DbgPrint(L"RegOpenKeyExW falied %d", res);
			return false;
		}

		res = RegSetValueExW(hKey, name.c_str(), 0, REG_DWORD, (BYTE*)&value, valsz);
		if (res != ERROR_SUCCESS)
		{
			DbgPrint(L"RegGetValueW falied %d", res);
			ret = false;
		}
		else
		{
			ret = true;

		}
		RegCloseKey(hKey);

		return ret;
	}
};