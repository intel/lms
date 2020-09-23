/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2020 Intel Corporation
 */
#ifndef _VERIFY_FILE
#define _VERIFY_FILE

#include <iostream>
#include "global.h"
#include <WinTrust.h>
#include <Softpub.h>
#include "GMSCommonDllExport.h"

class GMS_COMMON_EXPORT VerifyFile
{
public:
	VerifyFile(void);
	~VerifyFile(void);
	static bool Init();
	static const HMODULE SafeLoadDll(const std::wstring & wcName);

private:
	static bool VerifyFileSignature(const std::wstring &filePath, HANDLE hFile);
	static void InitWinTrust(WINTRUST_DATA &WinTrustData, WINTRUST_FILE_INFO &FileData, const std::wstring &filePath, HANDLE hFile);
	static bool VerifyCertificateName(const std::wstring &filePath);
	static bool VerifyNotSymbolicLink(const std::wstring &filePath, HANDLE hFile);
	static bool VerifyDll(const std::wstring &filePath, HANDLE hFile);

	static std::wstring m_UNSPath;
};

#endif // _VERIFY_FILE