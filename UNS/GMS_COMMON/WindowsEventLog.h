/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: WindowsEventLog.h

--*/

//*****************************************************************************
//
// Class:			EventLogging
// Author:			Assaf Weiner (assaf.weiner@intel.com)
// Date created:	5 May 2006
// Description:		The class EventLogger provide methods to access the Windows 
//					Event Log (Application partition).
//
//*****************************************************************************

#pragma once

#include <stdio.h>
#include <atlbase.h>
#include "BaseEventLog.h"
#include "GMSCommonDllExport.h"

class GMS_COMMON_EXPORT WindowsEventLog : public BaseEventLog
{
private:
	// Data member which contain handle to registry.
	HANDLE _hEventLinker;
	CRegKey _RegistryKey;

public:
	WindowsEventLog(	const wchar_t * pszLogName, 
						const wchar_t * pszSrcName,  
						unsigned long	dwNum,
						const wchar_t * pszModuleName = NULL);			// Ctor.
	virtual ~WindowsEventLog();				// Dtor.

	// Wrapper for ReportEvent that take care of Handle and EventType
	void LogEvent(	unsigned short CategoryID, 
					unsigned long	EventID,
					WORD			EventType);

	void LogEvent(	unsigned short CategoryID, 
					unsigned long	EventID,
					WORD			EventType,
					const ACE_TCHAR* message);

	void LogEvent(	unsigned short	CategoryID,
					unsigned long	EventID, 
					WORD			EventType,
					const ACE_TCHAR *	ArrayOfStrings[],
					unsigned int	NumOfArrayStr, 
					void *			RawData = NULL , 
					unsigned long	RawDataSize = 0);

	// Add a new source name to the registry by opening a new registry subkey under 
	// the Application key, adds a message-file name and a bitmask of supported types.

	void AddEventSource(const wchar_t * pszLogName, // Application log or a custom log (e.g. "Application")
						const wchar_t * pszSrcName, // event source name (e.g. "Intel (R) AMT").
						const wchar_t * pszMsgDLL , // path for message DLL
						unsigned long	dwNum);     // number of categories
	static void RemoveEventSource(const wchar_t * pszLogName, // Application log or a custom log (e.g. "Application")
						const wchar_t * pszSrcName); // event source name (e.g. "Intel (R) AMT").
};