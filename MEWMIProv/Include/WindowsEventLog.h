/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
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

#ifndef _WINDOWS_EVENT_LOG__H__
#define _WINDOWS_EVENT_LOG__H__

#include <windows.h>
#include <stdio.h>
#include <atlbase.h>
#include "BaseEventLog.h"


class WindowsEventLog : public BaseEventLog
{
private:
	// Data member which contain handle to registry.
	HANDLE _hEventLinker;
	CRegKey _RegistryKey;

public:
	WindowsEventLog(	const TCHAR * pszLogName,
						const TCHAR * pszSrcName,
						unsigned long	dwNum,
						const TCHAR * pszModuleName = NULL);			// Ctor.
	virtual ~WindowsEventLog();				// Dtor.
	WindowsEventLog(const WindowsEventLog&) = delete;
	WindowsEventLog& operator = (const WindowsEventLog&) = delete;

	// Wrapper for ReportEvent that take care of Handle and EventType
	void LogEvent(	unsigned short CategoryID, 
					unsigned long	EventID,
					unsigned short	EventType);
	void LogEvent(	unsigned short CategoryID, 
					unsigned long	EventID,
					unsigned short	EventType,
					const char* message);

	void LogEvent(	unsigned short	CategoryID,
					unsigned long	EventID, 
					unsigned short	EventType,
					const char *	ArrayOfStrings[],
					unsigned int	NumOfArrayStr, 
					void *			RawData = NULL , 
					unsigned long	RawDataSize = 0);

	// Add a new source name to the registry by opening a new registry subkey under 
	// the Application key, adds a message-file name and a bitmask of supported types.

	void AddEventSource(const TCHAR * pszLogName, // Application log or a custom log (e.g. "Application")
						const TCHAR * pszSrcName, // event source name (e.g. "Intel (R) AMT").
						const TCHAR * pszMsgDLL , // path for message DLL
						unsigned long	dwNum);     // number of categories
	static void RemoveEventSource(const TCHAR * pszLogName, // Application log or a custom log (e.g. "Application")
						const TCHAR * pszSrcName); // event source name (e.g. "Intel (R) AMT").

};


#endif		//_WINDOWS_EVENT_LOG__H__