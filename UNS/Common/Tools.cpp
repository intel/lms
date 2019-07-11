/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "Tools.h"
#include "time.h"
#include <string>
#include <codecvt>
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

using namespace std;

string getDateTime()
{
	time_t timestamp;
	timestamp = time(NULL);
	stringstream ss;
	tm *lcl = localtime(&timestamp);
	if (lcl == NULL)
		return ss.str();
	ss << (lcl->tm_year+1900) << "-" << (lcl->tm_mon+1) << "-" << lcl->tm_mday << "T" << lcl->tm_hour << ":" <<
		lcl->tm_min << ":" << lcl->tm_sec << ".000";
	return ss.str();
}

// Parse the MAC address from IP_ADAPTER_INFO Address field to string
string MacAddressToString(unsigned char addr[], unsigned int addrLen)
{

	string mac = "";
	if (addrLen == 6)
	{
		stringstream wiredMacAddress;
		
		wiredMacAddress.setf ( ios::hex, ios::basefield );  //shift to hex
		wiredMacAddress<<uppercase<<setfill('0')<<setw(2)<<(short)addr[0]<<":"<<setw(2)<<(short)addr[1]<<":"
												<<setw(2)<<(short)addr[2]<<":"<<setw(2)<<(short)addr[3]<<":"
												<<setw(2)<<(short)addr[4]<<":"<<setw(2)<<(short)addr[5];
		wiredMacAddress.setf ( ios::dec, ios::basefield );  //return to default	
		
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
	//This function was copied from PartialFWUpdateService::checkImageFileExist
	//TODO - need to be migrated to GMS-common and shared for all
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

bool checkFileExist(wstring path)
{
	ifstream ifs;
	ifs.open(path.c_str());
	ifs.close();
	if(ifs.fail())
		return false;
	return true;
}
#endif // WIN32

wstring StringToWString(const string& s)
{
	wstring temp(s.length(), L' ');
	copy(s.begin(), s.end(), temp.begin());
	return temp;
}

string WStringToString(const std::wstring& wstr)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converterX;
    return converterX.to_bytes(wstr);
}

#define FQDN_MAX_SIZE 256
#ifdef WIN32
bool GetLocalFQDN(std::string& fqdn)
{
	char localName[FQDN_MAX_SIZE] = "\0";
	DWORD len = FQDN_MAX_SIZE;
	if (GetComputerNameExA(ComputerNameDnsFullyQualified, localName, &len) == 0)
		return false;
	fqdn = localName;
	return true;
}
#else
bool GetLocalFQDN(std::string& fqdn)
{
	char buf[FQDN_MAX_SIZE];
	if (gethostname(buf, FQDN_MAX_SIZE))
		return false;
	struct addrinfo hints, *info = NULL;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_CANONNAME;

	int ret = getaddrinfo(buf, NULL, &hints, &info);
	if (ret) {//full search can fail, return local hostname
		fqdn = buf;
		return true;
	}

	if (info)
		fqdn = info->ai_canonname;
	freeaddrinfo(info);

	return (info != NULL);
}
#endif // WIN32
