/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: UNSRegistry.h

--*/

#ifndef __UNSREGISTRY_H
#define __UNSREGISTRY_H
#include <string>

#ifdef WIN32
#define LMS_REG_TEXT(STRING) L##STRING
typedef std::wstring LmsRegStr;
#else
#define LMS_REG_TEXT(STRING) STRING
typedef std::string LmsRegStr;
#endif // WIN32

#ifdef WIN32
static const LmsRegStr LMS_REG(LMS_REG_TEXT("SYSTEM\\CurrentControlSet\\Services\\LMS\\IntelAMTUNS\\"));
static const LmsRegStr LMS_REG_BACKUP(LMS_REG_TEXT("SOFTWARE\\Intel\\IntelAMTUNS\\"));
#ifdef _DEBUG
#include <atlbase.h>
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, BSTR* val);
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, SHORT*  val);
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, WCHAR* val, size_t size);
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, wchar_t* val, DWORD* valsz);
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, ULONG* val);
bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, BYTE* arr, ULONG* pLen);
#endif // _DEBUG
#else
static const LmsRegStr LMS_REG(LMS_REG_TEXT("IntelAMTUNS_"));
LmsRegStr GetLmsRegPosition();
#endif //WIN32
static const LmsRegStr LMS_REG_CONFIG_DATA(LMS_REG_TEXT("ConfigData"));

bool GetFromRegistry(const LmsRegStr &folder, const LmsRegStr &key, unsigned long* val, unsigned long defval);

#endif // __UNSREGISTRY_H
