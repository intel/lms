/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
#include "VerifyFile.h"
#include "DataStorageGenerator.h"
#include "Tools.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <new>

std::wstring VerifyFile::m_UNSPath;
std::wstring VerifyFile::m_UNSFilePath;
uint16_t VerifyFile::m_MajorVersion = 0;
uint16_t VerifyFile::m_MinorVersion = 0;
uint16_t VerifyFile::m_BuildNumber = 0;
uint16_t VerifyFile::m_RevisionNumber = 0;

const std::wstring IntelCertificateName(L"Intel(R) Embedded Subsystems and IP Blocks Group");


VerifyFile::VerifyFile(void)
{
}

VerifyFile::~VerifyFile(void)
{
}

bool VerifyFile::Init()
{
	if (!GetServiceDirectory(L"LMS", m_UNSFilePath))
	{
		return false;
	}

	m_UNSPath.assign(m_UNSFilePath, 0, m_UNSFilePath.length()-7); //7 is length of "LMS.exe"

	if (!GetAppVersion(m_UNSFilePath.c_str(), &m_MajorVersion, &m_MinorVersion, &m_BuildNumber, &m_RevisionNumber))
	{
		UNS_ERROR(L"Could not get file version for LMS.exe.\n");
		return false;
	}

	if (!VerifyCommonDlls())
	{
		return false;
	}
	return true;
}

bool VerifyFile::VerifyService(std::wstring serviceName)
{
	serviceName.append(L".dll");

	std::wstring filepath(m_UNSPath);
	filepath.append(serviceName);

	if(!checkFileExist(filepath))
	{
		UNS_ERROR(L"The configuration file for service: %s is not found or cannot be opened\n", serviceName.c_str());
		return false;
	}
	if (!VerifyFileVersionAndSignature(serviceName))
	{
	
		return false;
	}

	return true;
}

const HMODULE VerifyFile::SafeLoadDll(const std::wstring & wcName)
{
	std::wstring filepath(m_UNSPath);
	filepath.append(wcName);

	if(!checkFileExist(filepath))
	{
		UNS_ERROR(L"The configuration file for service: %s is not found or cannot be opened\n", wcName.c_str());
		return nullptr;
	}

	if (!VerifyFileVersionAndSignature(wcName, false)) //FWUpdateLib DLLs' version should not be compared to LMS' version
	{
		return nullptr;
	}

	return LoadLibrary(filepath.c_str());
}

/*
* Retrieves the file version
* Arguments:  		LibName - file to retrieve version of
* Return values:	true on success, false on failure
*/
bool VerifyFile::GetAppVersion(const wchar_t *LibName, uint16_t *MajorVersion, uint16_t *MinorVersion,
	uint16_t *BuildNumber, uint16_t *RevisionNumber)
{
	DWORD dwHandle, dwLen;
	UINT BufLen;
	LPWSTR lpData;
	VS_FIXEDFILEINFO *pFileInfo; 

	dwLen = GetFileVersionInfoSize((LPTSTR)LibName, &dwHandle );
	auto lastErr = GetLastError();
	if (!dwLen) 
	{
		UNS_ERROR(L"GetAppVersion: GetFileVersionInfoSize for file %s returned with %d error.\n", LibName, lastErr);
		return FALSE;
	}

	try
	{
		lpData = new TCHAR[dwLen];
	}
	catch (std::bad_alloc&)
	{
		UNS_ERROR(L"GetAppVersion: Failed to alloc memory\n");
		return FALSE;
	}
	
	if(!GetFileVersionInfo( LibName, dwHandle, dwLen, lpData ))
	{
		UNS_ERROR(L"GetAppVersion: GetFileVersionInfo return with %d error.\n", GetLastError());
		delete [] lpData;
		return FALSE;
	}
	if (VerQueryValue( lpData, L"\\", (LPVOID *) &pFileInfo, (PUINT)&BufLen )) 
	{
		*MajorVersion 	= HIWORD(pFileInfo->dwFileVersionMS);
		*MinorVersion 	= LOWORD(pFileInfo->dwFileVersionMS);
		*BuildNumber 	= HIWORD(pFileInfo->dwFileVersionLS);
		*RevisionNumber = LOWORD(pFileInfo->dwFileVersionLS);
		delete [] lpData;

		if ((*MajorVersion == 0) || (*MajorVersion > 9999) || (*MinorVersion > 9999) || (*BuildNumber > 9999) || (*RevisionNumber > 9999))
		{
			UNS_ERROR(L"GetAppVersion: Got out of bound values.\n");
			return FALSE;
		}
		else
		{
			UNS_DEBUG(L"GetAppVersion: Got version: %d.%d.%d.%d\n", *MajorVersion, *MinorVersion, *BuildNumber, *RevisionNumber);
			return TRUE;
		}
	}
	else
	{
		UNS_ERROR(L"GetAppVersion: VerQueryValue return with %d error.\n", GetLastError());
		delete [] lpData;
		return FALSE;
	}
}


/*
* Returns true if the version of given filepath is newer or equal to LMS's version
*/
bool VerifyFile::CompareVersions(std::wstring &filepath)
{
	uint16_t MajorVersion, MinorVersion, BuildNumber, RevisionNumber;
	if (!GetAppVersion(filepath.c_str(), &MajorVersion, &MinorVersion, &BuildNumber, &RevisionNumber))
	{
		UNS_ERROR(L"CompareVersions: Could not get file version.\n");
		return false;
	}
	if ((m_MajorVersion < MajorVersion) || 
		((m_MajorVersion == MajorVersion) && (m_MinorVersion < MinorVersion)) ||
		((m_MajorVersion == MajorVersion) && (m_MinorVersion == MinorVersion) && (m_BuildNumber < BuildNumber))|| 
		((m_MajorVersion == MajorVersion) && (m_MinorVersion == MinorVersion) && (m_BuildNumber == BuildNumber) && (m_RevisionNumber <= RevisionNumber)))
	{
		UNS_DEBUG(L"CompareVersions: %s version is equal or newer than LMS.\n", filepath.c_str());
		return true;
	}
	UNS_WARNING(L"CompareVersions: %s version is older than LMS.\n", filepath.c_str());
	return false;
}


bool VerifyFile::VerifyCommonDlls()
{
	std::wstring filename;

	filename = L"GmsCommon.dll";
	if (!VerifyFileVersionAndSignature(filename))
	{
		return false;
	}

#ifdef _DEBUG
	filename = L"WsmanClientD.dll";
#else
	filename = L"WsmanClient.dll";
#endif

	if (!VerifyFileVersionAndSignature(filename))
	{
		return false;
	}
	return true;
}

bool VerifyFile::VerifyFileVersionAndSignature(const std::wstring &filename, bool compareVersions)
{
	std::wstring path(m_UNSPath);
	path.append(filename);

#if !defined(IGNORE_DLL_SIGNATURES)
	std::wstring wpath(path.begin(), path.end());
	UNS_DEBUG(L"Checking signature for configuration file %s\n", filename.c_str());

	bool ret = true;

	UNS_DEBUG(L"Verifying signature\n");
	ret = VerifyFileSignature(wpath);	

	if (ret)
	{
		UNS_DEBUG(L"Verifying certificate name\n");
		ret = VerifyCertificateName(wpath);
	}
	if (!ret)
	{
		UNS_ERROR(L"Could not verify signature for configuration file %s\n", filename.c_str());
// PREPROCESSOR variable that enable signing on production releases 
#if SIGNING > 0			
		return false;
#endif // ndef _DEBUG
	}
#endif // !defined(IGNORE_DLL_SIGNATURES)
	if (compareVersions) 
	{
		UNS_DEBUG(L"Checking version for configuration file %s\n", filename.c_str());
		if (!CompareVersions(path))
		{
			return false;
		}
		UNS_DEBUG(L"Version is valid\n");
	}
	return true;
}


/*
* Verify the file signature.
* Arguments: 		filePath - file to verify
* Return values:	true on success, false on failure
*/
bool VerifyFile::VerifyFileSignature(const std::wstring &filePath)
{
	#ifdef _DEBUG
	return true;
#endif
	bool status = false;
	LONG lStatus;
    DWORD dwLastError;

    /*
    WVTPolicyGUID specifies the policy to apply on the file
    WINTRUST_ACTION_GENERIC_VERIFY_V2 policy checks:
    
    1) The certificate used to sign the file chains up to a root 
    certificate located in the trusted root certificate store. This 
    implies that the identity of the publisher has been verified by 
    a certification authority.
    
    2) In cases where user interface is displayed (which this example
    does not do), WinVerifyTrust will check for whether the  
    end entity certificate is stored in the trusted publisher store,  
    implying that the user trusts content from this publisher.
    
    3) The end entity certificate has sufficient permission to sign 
    code, as indicated by the presence of a code signing EKU or no 
    EKU.
    */

    GUID WVTPolicyGUID = WINTRUST_ACTION_GENERIC_VERIFY_V2; 
	WINTRUST_FILE_INFO FileData;
    WINTRUST_DATA WinTrustData;
	InitWinTrust(WinTrustData, FileData, filePath);

    
    // WinVerifyTrust verifies signatures as specified by the GUID and Wintrust_Data.
    lStatus = WinVerifyTrust(NULL, &WVTPolicyGUID, &WinTrustData);

    switch (lStatus) 
    {
        case ERROR_SUCCESS:
			{
				/*
				Signed file:
					- Hash that represents the subject is trusted.
					- Trusted publisher without any verification errors.
					- UI was disabled in dwUIChoice. No publisher or time stamp chain errors.
					- UI was enabled in dwUIChoice and the user clicked "Yes" when asked to install and run the signed subject.
				*/
			UNS_DEBUG(L"VerifyFileSignature: The file is signed and the signature was verified.\n");

				status = true;
				break;   
			}
	    case TRUST_E_NOSIGNATURE:	
	        // The file was not signed or had a signature that was not valid.
	        // Get the reason for no signature.
	        dwLastError = GetLastError();
			// The signature was not valid or there was an error opening the file.
			// The file was not signed.
			UNS_ERROR(L"VerifyFileSignature: The file is not signed, reason %d\n", dwLastError);
	        break;

        case TRUST_E_EXPLICIT_DISTRUST:
            // The hash that represents the subject or the publisher 
            // is not allowed by the admin or user.
			UNS_ERROR(L"VerifyFileSignature: The signature is present, but specifically disallowed.\n");
            break;

        case TRUST_E_SUBJECT_NOT_TRUSTED:
            // The user clicked "No" when asked to install and run.
			UNS_ERROR(L"VerifyFileSignature: The signature is present, but not trusted.\n");
            break;

        case CRYPT_E_SECURITY_SETTINGS:
            /*
            The hash that represents the subject or the publisher 
            was not explicitly trusted by the admin and the 
            admin policy has disabled user trust. No signature, 
            publisher or time stamp errors.
			*/
			UNS_ERROR(L"VerifyFileSignature: CRYPT_E_SECURITY_SETTINGS - The hash representing the subject or the publisher wasn't explicitly trusted by the admin and admin policy has disabled user trust. No signature, publisher or timestamp errors.\n");
			break;

        default:
            // The UI was disabled in dwUIChoice or the admin policy 
            // has disabled user trust. lStatus contains the 
            // publisher or time stamp chain error.
				/*LogEvent(EVENTLOG_ERROR_TYPE,LOCATION,L"VerifyFileSignature",
					L"Error is: 0x" + StrUtl::ToWStrHex(lStatus) + L"." ); */
            break;
	}

	// Any hWVTStateData must be released by a call with close.
	WinTrustData.dwStateAction = WTD_STATEACTION_CLOSE;

	lStatus = WinVerifyTrust(
		NULL,
		&WVTPolicyGUID,
		&WinTrustData);


    return status;
}


void VerifyFile::InitWinTrust(WINTRUST_DATA &WinTrustData, WINTRUST_FILE_INFO &FileData, const std::wstring &filePath)
{
	// Initialize the WINTRUST_FILE_INFO structure.
	memset(&FileData, 0, sizeof(FileData));
    FileData.cbStruct = sizeof(WINTRUST_FILE_INFO);
    FileData.pcwszFilePath = filePath.c_str();
    FileData.hFile = NULL;
    FileData.pgKnownSubject = NULL;

	// Initialize the WinVerifyTrust input data structure.

    // Default all fields to 0.
    memset(&WinTrustData, 0, sizeof(WinTrustData));

    WinTrustData.cbStruct = sizeof(WinTrustData);
    
    // Use default code signing EKU.
    WinTrustData.pPolicyCallbackData = NULL;

    // No data to pass to SIP.
    WinTrustData.pSIPClientData = NULL;

    // Disable WVT UI.
    WinTrustData.dwUIChoice = WTD_UI_NONE;

    // No revocation checking.
    WinTrustData.fdwRevocationChecks = WTD_REVOKE_NONE; 

    // Verify an embedded signature on a file.
    WinTrustData.dwUnionChoice = WTD_CHOICE_FILE;

    // Default verification.
	WinTrustData.dwStateAction = WTD_STATEACTION_IGNORE;

    // Not applicable for default verification of embedded signature.
    WinTrustData.hWVTStateData = NULL;

    // Not used.
    WinTrustData.pwszURLReference = NULL;

    // WTD_CACHE_ONLY_URL_RETRIEVAL not supported in XP
    WinTrustData.dwProvFlags = WTD_CACHE_ONLY_URL_RETRIEVAL | WTD_SAFER_FLAG;

    // This is not applicable if there is no UI because it changes 
    // the UI to accommodate running applications instead of installing applications.
	WinTrustData.dwUIContext = WTD_UICONTEXT_EXECUTE;

    // Set pFile.
    WinTrustData.pFile = &FileData;
}



/*
 * Verifies that Certificate of given file was signed by Intel
 */
bool VerifyFile::VerifyCertificateName(const std::wstring &filePath)
{
	bool ret = false;
	HCERTSTORE hCertStore = 0;
	HCRYPTMSG hMsg = 0;
	PCMSG_SIGNER_INFO pSignerInfo = NULL;
	PCCERT_CONTEXT pCertContext = NULL;

	do
	{
		// Get store handle from the signed file.
		bool fResult = CryptQueryObject( 
			CERT_QUERY_OBJECT_FILE,
			filePath.c_str(),
			CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED,
			CERT_QUERY_FORMAT_FLAG_BINARY,
			0,
			0,
			0,
			0,
			&hCertStore,
			&hMsg,
			0);

		if(!fResult)
		{
			UNS_ERROR(L"VerifyCertificateName: CryptQueryObject Error\n");
			break;
		}
		// Get signer information size.
		DWORD dwSignerInfo;
		fResult = CryptMsgGetParam( 
			hMsg, 
			CMSG_SIGNER_INFO_PARAM, 
			0, 
			0, 
			&dwSignerInfo);

		if (!fResult)
		{
			UNS_ERROR(L"VerifyCertificateName: CryptMsgGetParam: Error\n");
			break;
		}

		// Allocate memory for signer information.
		pSignerInfo = new CMSG_SIGNER_INFO[dwSignerInfo];
		if (!pSignerInfo)
		{
			UNS_ERROR(L"VerifyCertificateName: CryptQueryObject Error\n");
			break;
		}
		// Get Signer Information.
		fResult = CryptMsgGetParam( 
			hMsg, 
			CMSG_SIGNER_INFO_PARAM, 
			0, 
			pSignerInfo, 
			&dwSignerInfo);

		if (!fResult)
		{
			UNS_ERROR(L"VerifyCertificateName: CryptMsgGetParam: Error\n");
			break;
		}

		// Search for the signer certificate in the certificate store.
		CERT_INFO certInfo;
		certInfo.Issuer = pSignerInfo->Issuer;
		certInfo.SerialNumber = pSignerInfo->SerialNumber;

		pCertContext = CertFindCertificateInStore( 
			hCertStore,
			(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING),
			0,
			CERT_FIND_SUBJECT_CERT,
			&certInfo,
			0);

		if (!pCertContext)
		{
			UNS_ERROR(L"VerifyCertificateName: CertFindCertificateInStore: Invalid pCertContext\n");
			break;
		}


		DWORD certNameLen = 0;
		// Verify publisher (Subject Name in cert)
		// Get Subject name size.
		if ( (certNameLen = CertGetNameString(pCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, NULL, 0) ) == 0)
		{
			UNS_ERROR(L"VerifyCertificateName: CertGetNameString: Empty Certificate Name\n");
			break;
		}
		
		try {
			auto certNameMem = std::unique_ptr<wchar_t[]>(new wchar_t[certNameLen * sizeof(wchar_t)]);

			// Get subject name.
			if ( (CertGetNameString(pCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, certNameMem.get(), certNameLen)) != certNameLen )
			{
				UNS_ERROR(L"VerifyCertificateName: CertGetNameString: Wrong buffer size\n");
				break;
			} 
			std::wstring certName(certNameMem.get());

			if (certName == IntelCertificateName)
			{
				UNS_DEBUG(L"VerifyCertificateName: File is signed by Intel\n");
				ret = true;
			}
			else
			{
				UNS_ERROR(L"VerifyCertificateName: File is not signed by Intel\n");
			}
		}
		catch (std::bad_alloc & )
		{
			UNS_ERROR(L"VerifyCertificateName: new failed\n");
		}


	} while (false);

	
	// Free resources.
	if(pCertContext != 0)
		CertFreeCertificateContext(pCertContext);

    if(hCertStore != 0)
        CertCloseStore(hCertStore, 0);

    if(hMsg != 0)
        CryptMsgClose(hMsg);

    if(pSignerInfo != 0)
        delete[] pSignerInfo;

	return ret;
}
