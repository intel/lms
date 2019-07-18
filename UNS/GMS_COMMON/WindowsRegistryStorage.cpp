/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: WindowsRegistryStorage.cpp

--*/

#include "RegistryStorage.h"
#include <winsock2.h>
#include <Accctrl.h>
#include <Aclapi.h>
#include <tchar.h>
#define SECURITY_WIN32
#include <Security.h>
#include <iptypes.h>
#include "RegistryCache.h"
#include "Is64BitOs.h"
#include <Windows.h>
#include <Strsafe.h>
#include "Tools.h"
#define NUM_OF_ENTRIES 3

// https://msdn.microsoft.com/en-us/library/windows/desktop/aa446595(v=vs.85).aspx 
// Creating a Security Descriptor for a New Object in C++ 
bool
SetKeySecurity(HKEY hKey)
{

	bool res = false;
	DWORD dwRes;
	PSID pEveryoneSID = NULL, pSystemSID = NULL;
	PACL pACL = NULL;
	PSECURITY_DESCRIPTOR pSD = NULL;
	EXPLICIT_ACCESS ea[NUM_OF_ENTRIES];
	SID_IDENTIFIER_AUTHORITY SIDAuthWorld = SECURITY_WORLD_SID_AUTHORITY;
	/**SID_IDENTIFIER_AUTHORITY SIDAuthNT = SECURITY_NT_AUTHORITY;*/
	HKEY hkSub = NULL;
	PSID systemSid = NULL;
	PSID adminSid = NULL;

	// Create a well-known SID for the Everyone group.
	if (!AllocateAndInitializeSid(&SIDAuthWorld, 1,
		SECURITY_WORLD_RID,
		0, 0, 0, 0, 0, 0, 0,
		&pEveryoneSID))
	{
		goto Cleanup;
	}

	// Initialize an EXPLICIT_ACCESS structure for an ACE.
	// The ACE will allow Everyone read access to the key.
	ZeroMemory(&ea, NUM_OF_ENTRIES * sizeof(EXPLICIT_ACCESS));
	ea[0].grfAccessPermissions = KEY_READ;
	ea[0].grfAccessMode = SET_ACCESS;
	ea[0].grfInheritance = NO_INHERITANCE;
	ea[0].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	ea[0].Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
	ea[0].Trustee.ptstrName = (LPTSTR)pEveryoneSID;

	DWORD sidSize = SECURITY_MAX_SID_SIZE;
	if ((systemSid = LocalAlloc(LMEM_FIXED, sidSize)) == 0)
	{
		goto Cleanup;
	}

	if (CreateWellKnownSid(WinLocalSystemSid, NULL, systemSid, &sidSize) == 0)
	{
		goto Cleanup;
	}

	// Initialize an EXPLICIT_ACCESS structure for an ACE.
	// The ACE will allow the local System full access to the key.
	ea[1].grfAccessPermissions = KEY_ALL_ACCESS;
	ea[1].grfAccessMode = SET_ACCESS;
	ea[1].grfInheritance = NO_INHERITANCE;
	ea[1].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	ea[1].Trustee.TrusteeType = TRUSTEE_IS_UNKNOWN;
	ea[1].Trustee.ptstrName = (LPTSTR)systemSid;

	sidSize = SECURITY_MAX_SID_SIZE;
	if ((adminSid = LocalAlloc(LMEM_FIXED, sidSize)) == 0)
	{
		goto Cleanup;
	}

	if (CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, adminSid, &sidSize) == 0)
	{
		goto Cleanup;
	}

	// Initialize an EXPLICIT_ACCESS structure for an ACE.
	// The ACE will allow the administrator full access to the key.
	ea[2].grfAccessPermissions = KEY_ALL_ACCESS;
	ea[2].grfAccessMode = SET_ACCESS;
	ea[2].grfInheritance = NO_INHERITANCE;
	ea[2].Trustee.TrusteeForm = TRUSTEE_IS_SID;
	ea[2].Trustee.TrusteeType = TRUSTEE_IS_UNKNOWN;
	ea[2].Trustee.ptstrName = (LPTSTR)adminSid;
	try {
		// Create a new ACL that contains the new ACEs.
		dwRes = SetEntriesInAcl(NUM_OF_ENTRIES, ea, NULL, &pACL);
	}
	catch (std::exception&)
	{
		goto Cleanup;
	}

	if (ERROR_SUCCESS != dwRes)
	{
		goto Cleanup;
	}

	// Initialize a security descriptor.  
	pSD = (PSECURITY_DESCRIPTOR)LocalAlloc(LPTR,
		SECURITY_DESCRIPTOR_MIN_LENGTH);
	if (NULL == pSD)
	{
		goto Cleanup;
	}

	if (!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION))
	{
		goto Cleanup;
	}

	// Add the ACL to the security descriptor. 
	if (!SetSecurityDescriptorDacl(pSD,
		TRUE,     // bDaclPresent flag   
		pACL,
		FALSE))   // not a default DACL 
	{
		goto Cleanup;
	}

	// Use the security attributes to set the security descriptor.
	res = (RegSetKeySecurity(hKey, DACL_SECURITY_INFORMATION, pSD) == ERROR_SUCCESS);

Cleanup:

	if (pEveryoneSID)
		FreeSid(pEveryoneSID);
	if (pSystemSID)
		FreeSid(pSystemSID);
	if (adminSid)
		FreeSid(adminSid);
	if (pACL)
		LocalFree(pACL);
	if (pSD)
		LocalFree(pSD);
	if (hkSub)
		RegCloseKey(hkSub);
	if (systemSid)
		LocalFree(systemSid);

	return res;
}

//*************************************************************
//
//  RegDelnodeRecurse()
//
//  Purpose:    Deletes a registry key and all its subkeys / values.
//
//  Parameters: hKeyRoot    -   Root key
//              lpSubKey    -   SubKey to delete
//
//  Return:     TRUE if successful.
//              FALSE if an error occurs.
//
//*************************************************************

bool RegDelnodeRecurse (HKEY hKeyRoot, LPTSTR lpSubKey)
{
    LPTSTR lpEnd;
    LONG lResult;
    DWORD dwSize;
    TCHAR szName[MAX_PATH];
    HKEY hKey;
    FILETIME ftWrite;

	HMODULE hAdvapi32dll = NULL;
    // First, see if we can delete the key without having
    // to recurse.   
	try
	{
		typedef LONG (WINAPI *REG_DELETE_KEY_EX_PTR)(HKEY, LPCTSTR, REGSAM, DWORD);
		REGSAM RegSAM = KEY_ALL_ACCESS;
		
		/*We need to check in runtime whether we're in a 64 bit OS. If so, we're loading a special RegDeleteKeyEx()
		function from Advapi32.dll, to enable us to delete from the 64 bit version of the registry. Otherwise, we
		just call the normal RegDeleteKey() function.*/
		REG_DELETE_KEY_EX_PTR RegDeleteKeyExPtr = NULL;
		if (Is64BitOS())
		{
			RegSAM |= KEY_WOW64_64KEY;
			hAdvapi32dll = SafeLoadDll(L"Advapi32.dll");
			if (hAdvapi32dll != NULL)
				RegDeleteKeyExPtr = (REG_DELETE_KEY_EX_PTR) GetProcAddress(hAdvapi32dll, "RegDeleteKeyExW");
		}

		if (RegDeleteKeyExPtr != NULL)
		{
			//If we have a pointer to this function, we're in a 64 bit OS and so we need to use it.
			lResult = RegDeleteKeyExPtr(hKeyRoot, lpSubKey, RegSAM, 0);
		}
		else
		{
			lResult = RegDeleteKey(hKeyRoot, lpSubKey);
		}

		if (lResult == ERROR_SUCCESS) 
		{
			if (hAdvapi32dll != NULL) 
				FreeLibrary(hAdvapi32dll);
			return true;
		}

		lResult = RegOpenKeyEx (hKeyRoot, lpSubKey, 0, RegSAM, &hKey);

		if (lResult != ERROR_SUCCESS) 
		{
			if (hAdvapi32dll != NULL) 
				FreeLibrary(hAdvapi32dll);

			if (lResult == ERROR_FILE_NOT_FOUND) {
				return true;
			} 
			else {
				return false;
			}
		}

		// Check for an ending slash and add one if it is missing.

		auto lpSubKeyLen = lstrlen(lpSubKey);

		lpEnd = lpSubKey + lpSubKeyLen;

		if (*(lpEnd - 1) != TEXT('\\')) 
		{

			if ( lpSubKeyLen == ((2 * MAX_PATH)-1) )
			{
				if (hAdvapi32dll != NULL) 
					FreeLibrary(hAdvapi32dll);

				RegCloseKey (hKey);
				return false;
			}

			*lpEnd =  TEXT('\\');
			lpEnd++;
			++lpSubKeyLen;
			*lpEnd =  TEXT('\0');
		}

		// Enumerate the keys

		dwSize = MAX_PATH;
		lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
							   NULL, NULL, &ftWrite);

		if (lResult == ERROR_SUCCESS) 
		{
			do {

				if (StringCchCopy (lpEnd, MAX_PATH*2 - lpSubKeyLen, szName) != S_OK)
				{
					break;
				}

				if (!RegDelnodeRecurse(hKeyRoot, lpSubKey)) {
					break;
				}

				dwSize = MAX_PATH;

				lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
									   NULL, NULL, &ftWrite);

			} while (lResult == ERROR_SUCCESS);
		}

		lpEnd--;
		*lpEnd = TEXT('\0');

		RegCloseKey (hKey);

		// Try again to delete the key.
		if (RegDeleteKeyExPtr != NULL)
		{
			//If we have a pointer to this function, we're in a 64 bit OS and so we need to use it.
			lResult = RegDeleteKeyExPtr(hKeyRoot, lpSubKey, RegSAM, 0);
		}
		else
		{
			lResult = RegDeleteKey(hKeyRoot, lpSubKey);
		}

		//Free the dll if it was loaded.
		if (hAdvapi32dll != NULL) 
			FreeLibrary(hAdvapi32dll);

	
		if (lResult == ERROR_SUCCESS) 
			return true;
	}
	catch (std::exception&)
	{
		if (hAdvapi32dll != NULL) 
			FreeLibrary(hAdvapi32dll);
		return FALSE;
	}
    
	return false;
}

//*************************************************************
//
//  RegDelnode()
//
//  Purpose:    Deletes a registry key and all its subkeys / values.
//
//  Parameters: 
//              lpSubKey    -   SubKey to delete
//
//  Return:     TRUE if successful.
//              FALSE if an error occurs.
//
//*************************************************************

bool RegistryStorage::RegDelnode(const LmsRegStr &lpSubKey)
{
    TCHAR szDelKey[MAX_PATH];

	if (FAILED(StringCchCopy(szDelKey, MAX_PATH, lpSubKey.c_str())))
	{
		return FALSE;
	}
    return RegDelnodeRecurse(HKEY_LOCAL_MACHINE, szDelKey);

}

bool 
RegistryStorage::DeleteRegEntry(RegEntry& entry)
{
	LmsRegStr dummy(LMS_REG_TEXT(""));
	RegistryCache::DeleteData(dummy, entry.first, entry.second);
	bool retval = true;
	HKEY hKey;

    // get handle to correct registry path
	REGSAM RegSAM = KEY_ALL_ACCESS;
	if (Is64BitOS())
		RegSAM |= KEY_WOW64_64KEY;

	if( ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, entry.first.c_str() , 0, RegSAM, &hKey) ) {
		long res = RegDeleteValue(hKey, entry.second.c_str());
        if( (ERROR_SUCCESS != res) && (res != ERROR_FILE_NOT_FOUND)) {
            retval = false;
        } 
		RegCloseKey(hKey);
	}
   

	return retval;	
}

bool
RegistryStorage::GetRegistryData(void* value, unsigned long* valsz, unsigned long* type,
	const LmsRegStr &key, const LmsRegStr &valueName, bool withCache)
{
	LmsRegStr dummy(LMS_REG_TEXT(""));
	bool retval = true;
    HKEY hKey;
	do
	{
		//compose full base path
		if (withCache)
		{
			
			
			if (RegistryCache::GetData(value, valsz, type,  dummy, key, valueName) == true)
			{
				return true;
			}		
		}
		// get handle to correct registry path
		REGSAM RegSAM = KEY_READ;
		if (Is64BitOS())
			RegSAM |= KEY_WOW64_64KEY;

		if( ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, key.c_str(), 0, RegSAM, &hKey) ) {
			if( ERROR_SUCCESS != RegQueryValueEx(hKey, valueName.c_str(), NULL, 
									type, (LPBYTE)value, valsz)) {
				retval = false;
			}
			RegCloseKey(hKey);	
		}
		else
		{
			retval = false;
		}
	}while(false);
	if (withCache && retval == true && value!=NULL)
	{
		RegistryCache::SetData(value, *valsz, *type, dummy, key, valueName);
	}
    return retval;
}

bool 
RegistryStorage::SetRegistryData(const void* value, unsigned long valsz, unsigned long type,
	const LmsRegStr &key, const LmsRegStr &valueName, bool withCache)
{
	LmsRegStr dummy(LMS_REG_TEXT(""));

	bool retval = true;
    HKEY hKey;
    
	DWORD dwDisposition;
    // get handle to correct registry path
	REGSAM RegSAM = KEY_ALL_ACCESS;
	if (Is64BitOS())
		RegSAM |= KEY_WOW64_64KEY;

	if( ERROR_SUCCESS == RegCreateKeyEx(HKEY_LOCAL_MACHINE, key.c_str(), 0, NULL, 
		0, RegSAM, NULL, &hKey, &dwDisposition)) 
	{
		if( ERROR_SUCCESS != RegSetValueEx(hKey, valueName.c_str(), 0, type, (LPBYTE)value, valsz)) {
            retval = false;
        } 
		else {
			bool ret = SetKeySecurity(hKey);
			retval = (bool) ret;
		}
        RegCloseKey(hKey);
    }
    else
    {
        retval = false;
    }

	if (withCache && retval == true)
	{
		RegistryCache::SetData(value, valsz, type, dummy, key, valueName);
	}

    return retval;
}