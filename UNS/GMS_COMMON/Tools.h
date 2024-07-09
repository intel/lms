/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2024 Intel Corporation
 */
#ifndef _TOOLS_H
#define _TOOLS_H

#include <string>

std::string getDateTime();

// Parse the MAC address from IP_ADAPTER_INFO Address field to human readable string
std::string MacAddressToString(unsigned char addr[], unsigned int addrLen);

#ifdef WIN32
bool GetServiceDirectory(const std::wstring serviceName, std::wstring& serviceFilePath);

bool checkFileExist(std::wstring path);

std::wstring UTF8ToWStr(const std::string& s);
#endif // WIN32

bool GetLocalFQDN(std::string& fqdn);

bool MEIEnabled(std::wstring& err);

void GetLMSProductVersion(std::string& sVersion);

#endif //_TOOLS_H
