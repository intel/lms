/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: UNSRegistry.cpp

--*/
#include "UNSRegistry.h"

#ifdef WIN32
#include <atlbase.h>
#ifdef _DEBUG
#include "UNSDebug.h"
#include "Is64BitOs.h"

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, WCHAR *val, size_t size)
{
	CRegKey _RegistryKey;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	WCHAR szBuf[2048];
	ULONG nchars=2048;
	
	szRegPath+=folder;
	szRegPathBackup += folder;

	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryStringValue(key.c_str(), szBuf, &nchars) == ERROR_SUCCESS )
		{
			wcscpy_s(val, size, szBuf);
			return true;
		}
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryStringValue(key.c_str(), szBuf, &nchars) == ERROR_SUCCESS)
		{
			wcscpy_s(val, size, szBuf);
			return true;
		}
	}
	return false;

}

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, wchar_t* val, DWORD* valsz)
{
	if (val == NULL)
		return false;

	REGSAM RegSAM = KEY_READ;
	if (Is64BitOS())
		  RegSAM |= KEY_WOW64_64KEY;
	HKEY hKey;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	bool rc = false;
	DWORD type;

	szRegPath +=folder;
	szRegPathBackup += folder;

	if( ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, szRegPath.c_str(), 0, RegSAM, &hKey) )
	{
		if( ERROR_SUCCESS == RegQueryValueExW(hKey, key.c_str(), NULL, &type,(LPBYTE)val, valsz))
		{
			rc = true;
		}
		else
			DbgPrintW(L"RegQueryValueEx %s failed lastErr=%d\n",key.c_str(),GetLastError());

		RegCloseKey(hKey);
	}
	else if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), 0, RegSAM, &hKey))
	{
		if (ERROR_SUCCESS == RegQueryValueExW(hKey, key.c_str(), NULL, &type, (LPBYTE)val, valsz))
		{
			rc = true;
		}
		else
			DbgPrintW(L"RegQueryValueEx %s failed lastErr=%d\n", key.c_str(), GetLastError());

		RegCloseKey(hKey);
	}
	else
		DbgPrintW(L"RegOpenKeyEx %s failed lastErr=%d\n", key.c_str(), GetLastError());
	return rc;
}

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, BSTR* val)
{
	CRegKey _RegistryKey;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	TCHAR szBuf[2048]; 
	ULONG nchars=2048;

	szRegPath+=folder;
	szRegPathBackup += folder;

	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryStringValue(key.c_str(), szBuf, &nchars) == ERROR_SUCCESS )
		{
			DbgPrintW (L"Value for %s is %s\n",key.c_str(), szBuf);
			CComBSTR bstr(szBuf);
			*val=bstr.Detach();
			return true;
		}
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryStringValue(key.c_str(), szBuf, &nchars) == ERROR_SUCCESS)
		{
			DbgPrintW(L"Value for %s is %s\n", key.c_str(), szBuf);
			CComBSTR bstr(szBuf);
			*val = bstr.Detach();
			return true;
		}
	}
	return false;

}

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, SHORT* val)
{
	CRegKey _RegistryKey;
	DWORD dwVal;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	
	szRegPath+=folder;
	szRegPathBackup += folder;

	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS )
		{
			DbgPrintW (L"Value for %s is %d\n",key.c_str(), dwVal);
			*val=(SHORT) dwVal;
			return true;
		}
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS)
		{
			DbgPrintW(L"Value for %s is %d\n", key.c_str(), dwVal);
			*val = (SHORT)dwVal;
			return true;
		}
	}
	return false;

}

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, ULONG* val)
{
	CRegKey _RegistryKey;
	DWORD dwVal;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	
	szRegPath+=folder;
	szRegPathBackup += folder;

	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS )
		{
			*val=(ULONG) dwVal;
			return true;
		}
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS)
		{
			*val = (ULONG)dwVal;
			return true;
		}
	}
	return false;

}
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, BYTE* arr, ULONG* pLen)
{
	CRegKey _RegistryKey;
	//DWORD dwVal;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);

	szRegPath+=folder;
	szRegPathBackup += folder;

	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryBinaryValue(key.c_str(), arr, pLen) == ERROR_SUCCESS )
		{
			//*val=(ULONG) dwVal;
			return true;
		}
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryBinaryValue(key.c_str(), arr, pLen) == ERROR_SUCCESS)
		{
			//*val=(ULONG) dwVal;
			return true;
		}
	}
	return false;

}

#endif // _DEBUG

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, unsigned long* val, unsigned long defval)
{
	CRegKey _RegistryKey;
	DWORD dwVal;
	std::wstring szRegPath(LMS_REG);
	std::wstring szRegPathBackup(LMS_REG_BACKUP);
	
	*val=defval;
	szRegPath+=folder;
	szRegPathBackup += folder;
	
	if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPath.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS )
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS )
			*val=dwVal;
	}
	else if (_RegistryKey.Open(HKEY_LOCAL_MACHINE, szRegPathBackup.c_str(), KEY_READ | KEY_WOW64_64KEY) == ERROR_SUCCESS)
	{
		if (_RegistryKey.QueryDWORDValue(key.c_str(), dwVal) == ERROR_SUCCESS)
			*val = dwVal;
	}

	return true;
}
#else // WIN32
#include <fstream>
#include <cstdlib>
#include <linux/limits.h>

LmsRegStr GetLmsRegPosition()
{
	char *path = getenv("SNAP_COMMON");

	if (path) {
		LmsRegStr tmp(path);
		tmp += "/";
		if (tmp[0] == '/' &&
		    tmp.find("..") == std::string::npos &&
		    tmp.length() <= PATH_MAX)
			return tmp;
	}
	return LmsRegStr("/etc/lms/");
}

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, unsigned long* val, unsigned long defval)
{
	if (!val)
		return false;

	std::ifstream file(GetLmsRegPosition() + LMS_REG + folder + "/" + key);

	*val = defval;
	if (!file.is_open())
		return false;

	unsigned long type;

	file >> type;
	if (!file.good())
		return false;
	file >> *val;
	if (!file.eof())
		return false;

	return true;
}
#endif // WIN32
