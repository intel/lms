/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#ifndef _TOOLS_H
#define _TOOLS_H

#pragma once
#include <string>
#include "GMSCommonDllExport.h"

std::string GMS_COMMON_EXPORT getDateTime();

// Parse the MAC address from IP_ADAPTER_INFO Address field to human readable string
std::string GMS_COMMON_EXPORT MacAddressToString(unsigned char addr[], unsigned int addrLen);

std::wstring GMS_COMMON_EXPORT StringToWString(const std::string& s);
std::string  GMS_COMMON_EXPORT WStringToString(const std::wstring& wstr);


#ifdef WIN32
bool GMS_COMMON_EXPORT GetServiceDirectory(const std::wstring serviceName, std::wstring& serviceFilePath);

bool GMS_COMMON_EXPORT checkFileExist(std::wstring path);

std::wstring UTF8ToWStr(const std::string& s);
#endif // WIN32

bool GMS_COMMON_EXPORT GetLocalFQDN(std::string& fqdn);

#endif //_TOOLS_H
