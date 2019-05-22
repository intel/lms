/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
#ifndef _VERIFY_FILE
#define _VERIFY_FILE

#include <iostream>
#include "global.h"
#include <WinTrust.h>
#include <Softpub.h>
#include "GMSCommonDllExport.h"

typedef std::shared_ptr<CERT_INFO> CertificateInfoPtr;


class GMS_COMMON_EXPORT VerifyFile
{
public:
	VerifyFile(void);
	~VerifyFile(void);
	static bool Init();
	static bool VerifyService(std::wstring serviceName);
	static const HMODULE SafeLoadDll(const std::wstring & wcName);

private:
	//static bool GetServiceDirectory(const std::string serviceName, std::string& serviceFilePath);
	static bool GetAppVersion(const wchar_t* LibName, uint16_t *MajorVersion, uint16_t *MinorVersion,
		uint16_t *BuildNumber, uint16_t *RevisionNumber);
	static bool CompareVersions(std::wstring &file);

	static bool VerifyCommonDlls();
	static bool VerifyFileVersionAndSignature(const std::wstring &filename, bool compareVersions = true);
	static bool VerifyFileSignature(const std::wstring &filePath);
	static void InitWinTrust(WINTRUST_DATA &WinTrustData, WINTRUST_FILE_INFO &FileData, const std::wstring &filePath);
	static bool VerifyCertificateName(const std::wstring &filePath);

	static std::wstring m_UNSPath;
	static std::wstring m_UNSFilePath;
	//LMS's version
	static uint16_t m_MajorVersion;
	static uint16_t m_MinorVersion;
	static uint16_t m_BuildNumber;
	static uint16_t m_RevisionNumber;
};

#endif