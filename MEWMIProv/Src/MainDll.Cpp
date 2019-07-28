/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: MainDll.Cpp

--*/

//***************************************************************************

//

//  MAINDLL.CPP

// 

//  Module: WMI Method provider sample code

//

//  Purpose: Contains DLL entry points.  Also has code that controls

//           when the DLL can be unloaded by tracking the number of

//           objects and locks as well as routines that support

//           self registration.

//

// Copyright (c)  Microsoft Corporation, All Rights Reserved
//
//***************************************************************************

#include "DebugPrints.h"
#include <objbase.h>
#include <initguid.h>
#include "XMLUtils.h"
#include "methprov.h"
#include "MEProvMessageUtil.h"
#include <strsafe.h>

HMODULE ghModule;

// TODO, GuidGen should be used to generate a unique number for any 
// providers that are going to be used for anything more extensive 
// than just testing.
                                 
// {73C0325A-D3BF-48af-9F37-1589CC58E788}
DEFINE_GUID(CLSID_IntelMEProv , 0x73c0325a, 0xd3bf, 0x48af, 0x9f, 0x37, 0x15, 0x89, 0xcc, 0x58, 0xe7, 0x88);
//Count number of objects and number of locks.

long       g_cObj=0;
long       g_cLock=0;

//***************************************************************************
//
// LibMain32
//
// Purpose: Entry point for DLL.
//
// Return: TRUE if OK.
//
//***************************************************************************

//BOOL WINAPI LibMain32(HINSTANCE hInstance, ULONG ulReason
  //  , LPVOID pvReserved)
BOOL WINAPI DllMain(HINSTANCE hInstance,  ULONG ulReason, LPVOID lpvReserved)
{
    if (DLL_PROCESS_DETACH==ulReason)
    {
        return TRUE;
    }
    else
    {
        if (DLL_PROCESS_ATTACH!=ulReason)
            return TRUE;
    }
	//InitXMLLibrary();

    ghModule = hInstance;


	ACE_LOG_MSG->open(0, ACE_Log_Msg::SYSLOG, 0);
	u_long mask = ACE_LOG_MSG->priority_mask(ACE_Log_Msg::PROCESS);
#ifdef _DEBUG
	u_long requiredLoggingMask = mask; // Debug Logging value is Trace
#else //_DEBUG
	u_long requiredLoggingMask = mask & ~LM_TRACE & ~LM_DEBUG & ~LM_WARNING; // Release Logging value is Error
#endif //_DEBUG
	ACE_LOG_MSG->priority_mask(requiredLoggingMask, ACE_Log_Msg::PROCESS);


	UNS_DEBUG("WMIProvider Started\n");

    return TRUE;
}

//***************************************************************************
//
//  DllGetClassObject
//
//  Purpose: Called by Ole when some client wants a class factory.  Return 
//           one only if it is the sort of class this DLL supports.
//
//***************************************************************************


STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, PPVOID ppv)
{
    HRESULT hr;
    CProvFactory *pObj;

    if (CLSID_IntelMEProv!=rclsid)
        return E_FAIL;

    pObj=new CProvFactory();

    if (NULL==pObj)
        return E_OUTOFMEMORY;

    hr=pObj->QueryInterface(riid, ppv);

    if (FAILED(hr))
        delete pObj;

    return hr;
}

//***************************************************************************
//
// DllCanUnloadNow
//
// Purpose: Called periodically by Ole in order to determine if the
//          DLL can be freed.
//
// Return:  S_OK if there are no objects in use and the class factory 
//          isn't locked.
//
//***************************************************************************

STDAPI DllCanUnloadNow(void)
{
    SCODE   sc;

    //It is OK to unload if there are no objects or locks on the 
    // class factory.
    
    sc=(0L==g_cObj && 0L==g_cLock) ? S_OK : S_FALSE;
    return sc;
}

//***************************************************************************
//
// DllRegisterServer
//
// Purpose: Called during setup or by regsvr32.
//
// Return:  NOERROR if registration successful, error otherwise.
//***************************************************************************

STDAPI DllRegisterServer(void)
{  
    char       szID[128];
    WCHAR      wcID[128];
    char       szCLSID[128];
    TCHAR      szModule[MAX_PATH + 1];
    char * pName = "IntelMEProv";
    char * pModel = "Both";
	size_t * intReturnValue = NULL;
    HKEY hKey1, hKey2;
 
   
  // Create the path.

	memset(wcID, NULL, sizeof(wcID));
	memset(szID, NULL, sizeof(szID));	

    StringFromGUID2(CLSID_IntelMEProv, wcID, sizeof(wcID)/sizeof(WCHAR) - 1);
    wcstombs_s(intReturnValue, szID, sizeof(szID), wcID,  sizeof(szID));
	StringCbCopyA(szCLSID, sizeof(szCLSID), "Software\\classes\\CLSID\\");
	StringCbCatA(szCLSID, sizeof(szCLSID), szID);


    // Create entries under CLSID

	LONG lRet = RegCreateKeyExA( HKEY_LOCAL_MACHINE, szCLSID, 0, NULL,
                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, 
                    &hKey1, NULL );
	if (lRet != ERROR_SUCCESS)
	{
		return E_FAIL;
	}

    lRet = RegSetValueExA(hKey1, NULL, 0, REG_SZ, (BYTE *)pName, strlen(pName)+1);
	if (lRet != ERROR_SUCCESS)
	{
		RegCloseKey(hKey1);
		return E_FAIL;
	}

	lRet = RegCreateKeyExA( hKey1, "InprocServer32", 0, NULL,
                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, 
                    &hKey2, NULL );
	if (lRet != ERROR_SUCCESS)
	{
		RegCloseKey(hKey1);
		return E_FAIL;
	}

	memset(&szModule, NULL, sizeof(szModule));
    GetModuleFileName(ghModule, szModule,  sizeof(szModule)/sizeof(TCHAR) - 1);
	//printf ("%s %d", szModule, strlen(szModule));
    lRet = RegSetValueEx(hKey2, NULL, 0, REG_SZ, (BYTE *)szModule, 
                                        (_tcslen(szModule)+1)*sizeof(TCHAR));
	if (lRet != ERROR_SUCCESS)
	{
	    RegCloseKey(hKey2);
		RegCloseKey(hKey1);
		return E_FAIL;
	}
    lRet = RegSetValueExA(hKey2, "ThreadingModel", 0, REG_SZ, 
                                        (BYTE *)pModel, strlen(pModel)+1);
	if (lRet != ERROR_SUCCESS)
	{
	    RegCloseKey(hKey2);
		RegCloseKey(hKey1);
		return E_FAIL;
	}
    RegCloseKey(hKey1);
    RegCloseKey(hKey2);
	
	WindowsEventLog windowsEventLog(EVENT_LOG_APPLICATION, ME_PPROV_NAME, EVENT_CATEGORY_NUMBER, "MEProv.dll");
    return NOERROR;
	
}

//***************************************************************************
//
// DllUnregisterServer
//
// Purpose: Called when it is time to remove the registry entries.
//
// Return:  NOERROR if registration successful, error otherwise.
//***************************************************************************

STDAPI DllUnregisterServer(void)
{
	char       szID[128];
    WCHAR      wcID[128];
    char  szCLSID[128];
	size_t * intReturnValue = NULL;
    HKEY hKey;

    // Create the path using the CLSID
	memset(wcID, NULL, sizeof(wcID));
	memset(szID, NULL, sizeof(szID));	
    StringFromGUID2(CLSID_IntelMEProv, wcID, sizeof(wcID)/sizeof(WCHAR));

    wcstombs_s(intReturnValue, szID, sizeof(szID), wcID, sizeof(szID));

	StringCbCopyA(szCLSID, sizeof(szCLSID), "Software\\classes\\CLSID\\");
	StringCbCatA(szCLSID, sizeof(szCLSID), szID);

     // First delete the InProcServer subkey.

    DWORD dwRet = RegOpenKeyExA(HKEY_LOCAL_MACHINE, szCLSID, 0, KEY_WRITE, &hKey);
    if(dwRet == NO_ERROR)
    {
        RegDeleteKeyA(hKey, "InProcServer32");
        RegCloseKey(hKey);
    }

    dwRet = RegOpenKeyExA(HKEY_LOCAL_MACHINE,"SOFTWARE\\CLASSES\\CLSID\\", 0, KEY_WRITE, &hKey);
    if(dwRet == NO_ERROR)
    {
        RegDeleteKeyA(hKey,szID);
        RegCloseKey(hKey);
    }
	WindowsEventLog::RemoveEventSource(EVENT_LOG_APPLICATION, TEXT(ME_PPROV_NAME));
    return NOERROR;

}


