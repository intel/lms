/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
#include "Tools.h"
#include <time.h>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#ifdef WIN32
#include <Userenv.h>
#include <Wbemidl.h>
#include <atlbase.h>
#else
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#endif // WIN32
#include "version.h"

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
	DWORD bufCount;
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

#ifdef WIN32
bool MEIEnabled(std::wstring &err)
{
	bool meiEnabled = false;
	IWbemLocator* loc = NULL;
	IWbemServices* svc = NULL;
	IWbemClassObject* obj = NULL;
	ULONG uReturn = 0;
	std::wstringstream ss;

	try
	{
		HRESULT hres = CoCreateInstance(__uuidof(WbemLocator), 0, CLSCTX_INPROC_SERVER, __uuidof(IWbemLocator), (LPVOID*)&loc);

		if (!FAILED(hres))
		{
			// Connect to the root\cimv2 namespace with
			// the current user and obtain pointer pSvc
			// to make IWbemServices calls.
			hres = loc->ConnectServer(CComBSTR(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &svc);
			if (!FAILED(hres))
			{
				IEnumWbemClassObject* enumerator = NULL;
				hres = svc->ExecQuery(CComBSTR(L"WQL"),
					CComBSTR(L"SELECT Status FROM Win32_PnPEntity where Caption = \'Intel(R) Management Engine Interface \' or Caption = \'Intel(R) Management Engine Interface #1\'"),
					WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &enumerator);
				if (!FAILED(hres))
				{
					if (enumerator)//we have only one instance
					{
						hres = enumerator->Next(WBEM_INFINITE, 1, &obj, &uReturn);
						if (uReturn != 0)
						{
							VARIANT vtProp;
							hres = obj->Get(L"Status", 0, &vtProp, 0, 0);
							if (SUCCEEDED(hres))
							{
								if (wcscmp(vtProp.bstrVal, L"OK") == 0)
								{
									meiEnabled = true;
								}
							}
							else
							{
								ss << L"isMEIEnabled() failed to get status " << hres;
							}
						}
						else
						{
							ss << L"isMEIEnabled() failed to enumerate device " <<  hres;
						}
					}
				}
				else
				{
					ss << L"isMEIEnabled() failed to connect to exec WMI query";
				}
			}
			else
			{
				ss << L"isMEIEnabled() failed to connect to WMI server";
			}
		}
		else
		{
			ss << L"isMEIEnabled() failed in CoCreateInstance()";
		}
	}
	catch (const ATL::CAtlException& e)
	{
		ss << "isMEIEnabled() AtlException hr = 0x" << std::hex << e.m_hr;
	}
	if (svc != NULL) svc->Release();
	if (loc != NULL) loc->Release();
	if (obj != NULL) obj->Release();
	err = ss.str();
	return meiEnabled;
}
#else
bool MEIEnabled(std::wstring& err)
{
	struct stat buf;
	static const std::vector<std::string> devnode =
	{ "/dev/mei", "/dev/mei0", "/dev/mei1", "/dev/mei2", "/dev/mei3" };

	for (std::vector<std::string>::const_iterator it = devnode.begin();
		it != devnode.end(); ++it)
	{
		if (!lstat(it->c_str(), &buf))
			return true;
	}
	err = L"Mei device is not found";
	return false;
}
#endif //WIN32

#ifdef WIN32
void GetLMSProductVersion(std::string& sVersion)
{
	DWORD dwHandle = 0;
	DWORD FileSize;
	WCHAR Filename[MAX_PATH + 1] = { 0 };

	if (GetModuleFileNameW(NULL, Filename, MAX_PATH) == 0)
	{
		std::stringstream err;
		err << "GetModuleFileName failed with err=" << GetLastError();
		throw std::exception(err.str().c_str());
	}

	FileSize = GetFileVersionInfoSize(Filename, &dwHandle);
	if (FileSize == 0)
	{
		std::stringstream err;
		err << "GetFileVersionInfoSize failed err=" << GetLastError();
		throw std::exception(err.str().c_str());
	}

	std::vector<BYTE> FileValues(FileSize);
	if (GetFileVersionInfo(Filename, NULL, FileSize, FileValues.data()) == 0)
	{
		std::stringstream err;
		err << "GetFileVersionInfoSize failed err=" << GetLastError();
		throw std::exception(err.str().c_str());
	}

	VS_FIXEDFILEINFO* fileQuerInfo;
	UINT InfoSize = 0;
	if (!VerQueryValue(FileValues.data(), TEXT("\\"), (LPVOID*)&fileQuerInfo, &InfoSize) ||
		!InfoSize || InfoSize < sizeof(VS_FIXEDFILEINFO))
	{
		std::stringstream err;
		err << "VerQueryValue failed err=" << GetLastError();
		throw std::exception(err.str().c_str());
	}
	std::stringstream ss;
	ss << HIWORD(fileQuerInfo->dwProductVersionMS) << "."
		<< LOWORD(fileQuerInfo->dwProductVersionMS) << "."
		<< HIWORD(fileQuerInfo->dwProductVersionLS) << "."
		<< LOWORD(fileQuerInfo->dwProductVersionLS);
	sVersion = ss.str();
}

#else
void GetLMSProductVersion(std::string& sVersion)
{
	std::stringstream str;
	str << MAJOR_VERSION << "." << MINOR_VERSION << "." <<
		QUICK_FIX_NUMBER << "." << VER_BUILD;
	sVersion = str.str();
}
#endif // WIN32