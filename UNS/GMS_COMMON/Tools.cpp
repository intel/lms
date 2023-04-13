/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#include "Tools.h"
#include <time.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#ifdef WIN32
#include <Userenv.h>
#else
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#endif // WIN32

std::string getDateTime()
{
	time_t timestamp = time(NULL);
	std::stringstream ss;
	tm lcl;
#ifdef WIN32
	if (localtime_s(&lcl, &timestamp))
#else
	if (localtime_r(&timestamp, &lcl) == NULL)
#endif // WIN32
		return ss.str();
	ss << (lcl.tm_year+1900) << "-" << (lcl.tm_mon+1) << "-" << lcl.tm_mday << "T" << lcl.tm_hour << ":" <<
		lcl.tm_min << ":" << lcl.tm_sec << ".000";
	return ss.str();
}

// Parse the MAC address from IP_ADAPTER_INFO Address field to string
std::string MacAddressToString(unsigned char addr[], unsigned int addrLen)
{
	std::string mac = "";
	if (addrLen == 6)
	{
		std::stringstream wiredMacAddress;

		wiredMacAddress.setf(std::ios::hex, std::ios::basefield);  //shift to hex
		wiredMacAddress << std::uppercase << std::setfill('0') << std::setw(2) <<
			(short)addr[0] << ":" << std::setw(2) << (short)addr[1] <<
			":" << std::setw(2) << (short)addr[2] << ":" << std::setw(2) <<
			(short)addr[3] <<":" << std::setw(2) << (short)addr[4] <<
			":" << std::setw(2) << (short)addr[5];
		wiredMacAddress.setf(std::ios::dec, std::ios::basefield);  //return to default

		mac.assign(wiredMacAddress.str());
	}
	// Return human readable MAC address 
	return mac;
}

#ifdef WIN32
/*
* Places directory of given service name in serviceFilePath
* The path's length is placed in pathLength
*/
bool GetServiceDirectory(const std::wstring serviceName, std::wstring& serviceFilePath)
{
	bool retVal = false;
	HKEY hKey;
	WCHAR ServiceKey[1024];
	DWORD bufCount = MAX_PATH;
	swprintf_s(ServiceKey, 1024, L"SYSTEM\\CurrentControlSet\\Services\\%s", serviceName.c_str());

	LONG RetValue = RegOpenKeyEx( HKEY_LOCAL_MACHINE, ServiceKey, 0, KEY_QUERY_VALUE, &hKey );
	if( RetValue != ERROR_SUCCESS )
	{
		//UNS_ERROR("GetServiceDirectory:RegOpenKeyEx failed err=%d\n", RetValue);
		return retVal;
	}
	WCHAR TempFilePath[MAX_PATH];
	DWORD pathLength = MAX_PATH;
	RetValue = RegQueryValueEx( hKey, L"ImagePath", NULL, NULL, (LPBYTE)TempFilePath, &pathLength);
	if( (RetValue != ERROR_SUCCESS) || (pathLength > MAX_PATH) )
	{
		//UNS_ERROR("GetServiceDirectory:RegQueryValueEx failed err=%d\n", RetValue);
		RegCloseKey( hKey );
		return retVal;
	}
	RegCloseKey( hKey );

	WCHAR expandedFilePath[MAX_PATH];
	bufCount = ExpandEnvironmentStrings(TempFilePath, expandedFilePath, MAX_PATH);
	if (bufCount > MAX_PATH)
	{
		//UNS_ERROR("ExpandEnvironmentStrings: Too small buffer for expanding %W\n", TempFilePath);
		return ERROR_SUCCESS;
	}
	else if (!bufCount)
	{
		//UNS_ERROR("ExpandEnvironmentStrings failed.\n");
		return ERROR_SUCCESS;
	}


	WCHAR* EndPath;
	if (expandedFilePath[0] == '"')
	{
		EndPath = wcschr(&expandedFilePath[1], '"');
		if (EndPath != NULL)
		{
			*EndPath = 0;
		}
		serviceFilePath.assign(&expandedFilePath[1]);
	}
	else
	{
		serviceFilePath.assign(expandedFilePath);
	}
	//UNS_ERROR("GetServiceDirectory:Success - got %W\n", serviceFilePath.c_str());
	return true;
}

bool checkFileExist(std::wstring path)
{
	std::ifstream ifs;
	ifs.open(path.c_str());
	ifs.close();
	if(ifs.fail())
		return false;
	return true;
}
#endif // WIN32

#define FQDN_MAX_SIZE 256
#ifdef WIN32
std::wstring UTF8ToWStr(const std::string& s)
{
	int wc_size = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.length(), NULL, 0);
	if (wc_size <= 0)
		return L"";
	std::wstring wc_str(wc_size, '\0');
	if (!MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.length(), &wc_str[0], wc_size))
		return L"";
	return wc_str;
}

static std::string WStrToUTF8(const wchar_t* str, int len)
{
	int utf8_size = WideCharToMultiByte(CP_UTF8, 0, str, len, NULL, 0, NULL, NULL);
	if (utf8_size <= 0)
		return "";
	std::string utf8_str(utf8_size, '\0');
	if (!WideCharToMultiByte(CP_UTF8, 0, str, len, &utf8_str[0], utf8_size, NULL, NULL))
		return "";
	return utf8_str;
}

bool GetLocalFQDN(std::string& fqdn)
{
	wchar_t localName[FQDN_MAX_SIZE] = L"\0";
	DWORD len = FQDN_MAX_SIZE;
	if (GetComputerNameExW(ComputerNameDnsFullyQualified, localName, &len) == 0)
		return false;
	fqdn = WStrToUTF8(localName, len);
	if (!fqdn.length())
		return false;
	return true;
}
#else
#include <idn2.h>
bool GetLocalFQDN(std::string& fqdn)
{
	char buf[FQDN_MAX_SIZE];
	if (gethostname(buf, FQDN_MAX_SIZE))
		return false;
	struct addrinfo hints, *info = NULL;
	char* fqdn_utf8 = NULL;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_CANONNAME;

	int ret = getaddrinfo(buf, NULL, &hints, &info);
	if (ret) {//full search can fail, return local hostname
		fqdn = buf;
		goto recode;
	}

	if (!info)
		return false;
	fqdn = info->ai_canonname;
	freeaddrinfo(info);

recode:
	if (idn2_to_unicode_8z8z(fqdn.c_str(), &fqdn_utf8, 0) != IDN2_OK)
		return false;

	fqdn = fqdn_utf8;
	free(fqdn_utf8);
	return true;
}
#endif // WIN32
