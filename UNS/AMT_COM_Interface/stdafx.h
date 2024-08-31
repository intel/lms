/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: stdafx.h

--*/

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER _WIN32_WINNT_WIN10		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT _WIN32_WINNT_WIN10	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS _WIN32_WINNT_WIN10 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

//#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit


#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <string>
#include <Windows.h>
#include "DataInterfaceBackend.h"

enum DATA_NAME : unsigned int;

HRESULT CheckCredentials(DATA_NAME funcName);
unsigned int GetGmsPortForwardingPort();
HRESULT LMSError2HRESULT(Intel::LMS::LMS_ERROR err);

template<class T>
bool CreateBSTR(const T& s, BSTR* bstr)
{
	try
	{
		ATL::CComBSTR cbstr(s.c_str());
		*bstr = cbstr.Detach();
		return true;
	}
	catch (const ATL::CAtlException&)
	{
		return false;
	}
}