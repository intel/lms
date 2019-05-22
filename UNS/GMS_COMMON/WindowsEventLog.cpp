/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: WindowsEventLog.cpp

--*/

//*****************************************************************************
// WindowsEventLog.cpp: implementation of the WindowsEventLog class.
//
//*****************************************************************************
#include "WindowsEventLog.h"
#include "UNSDebug.h"
#include "global.h"
#include "ace/Stream.h"
//*****************************************************************************
// Construct with a specified event source name.
//*****************************************************************************
WindowsEventLog::WindowsEventLog(	const wchar_t * pszLogName, 
									const wchar_t * pszSrcName,  
									unsigned long	dwNum,
									const wchar_t * pszModuleName /*= NULL*/) : _hEventLinker(INVALID_HANDLE_VALUE)
{
	
    TCHAR szPath[1024];

	/*if pszModuleName is NULL, GetModuleHandle() will return the handle of the current process*/
	if( GetModuleFileName(GetModuleHandle(pszModuleName), szPath, 1023 ) == 0 ) {
		return;
	}

	//ACE_DEBUG ((GMS_DEBUG ACE_TEXT ("GetModuleFileName: %s\n", szPath)));
    // First add a source name to the registry.
	AddEventSource(pszLogName, pszSrcName, szPath, dwNum);
	
	// Returns a handle that links the source to the registry 	
	_hEventLinker = RegisterEventSource(NULL,pszSrcName);
    if (_hEventLinker == NULL) 
    {
		UNS_DEBUG(L"Could not register the event source",L"\n");
		//ACE_DEBUG ((GMS_DEBUG ACE_TEXT ("Could not register the event source.\n")));
        return;
    }
}

//*****************************************************************************
//	Destructor is used deregister the event source
//*****************************************************************************
WindowsEventLog::~WindowsEventLog()
{
	// Releases the handle to the registry
	DeregisterEventSource(_hEventLinker);
}

//*****************************************************************************
// Function: LogEvent.
// Purpose : Log the event into the Windows Event Log. 
// Params  : CategoryID is the events category classification
//			 EventID is the events event classification
//*****************************************************************************
void WindowsEventLog::LogEvent(	unsigned short CategoryID, unsigned long EventID, WORD	EventType)
{
	// Writes data to the event log
	LogEvent(CategoryID, EventID, EventType, NULL, 0, NULL, 0);
	
}

void WindowsEventLog::LogEvent(	unsigned short CategoryID, unsigned long EventID, WORD EventType, const ACE_TCHAR* message)
{
	ACE_TString szBuf = ACE_TString(message) + ACE_TEXT("\n");
	const ACE_TCHAR *lpStrings[] = {szBuf.c_str()};
	WORD NumOfStrings	= 1;
	// Writes data to the event log
	LogEvent(CategoryID, EventID, EventType, lpStrings,NumOfStrings, NULL, 0);
}

//*****************************************************************************
// Function: ReportEvent.
// Purpose : Log the event into the Windows Event Log. 
// Params  :	CategoryID		- The events category classification
//				EventID			- The events event classification
//				ArrayOfStrings	- An array of pointers to strings that are 
//								  passed for additional information gathering
//				NumOfArrayStr	- The number of of strings in ArrayOfStrings
//				RawData			- A void pointer to hold additional raw data for
//								  event reporting
//				RawDataSize		- The size of RawData in bytes
//*****************************************************************************
void WindowsEventLog::LogEvent(	unsigned short	CategoryID,
								unsigned long	EventID, 
								WORD			EventType, 
								const ACE_TCHAR *	ArrayOfStrings[],
								unsigned int	NumOfArrayStr, 
								void *			RawData /*= NULL*/ , 
								unsigned long	RawDataSize /*= 0*/)
{

	// Writes data to the event log
	BOOL rc=ReportEvent(_hEventLinker,				// Handle to the event log
				EventType,	// Type of event to be logged 
				CategoryID,					// Event category
				EventID,					// Event identifier
				NULL,						// lpUserSid 
				NumOfArrayStr,				// wNumStrings 
				RawDataSize,				// dwDataSize 
				ACE_TEXT_ALWAYS_WCHAR(ArrayOfStrings),				// lpStrings 
				RawData);					// lpRawData 
	if (!rc)
	{
		//UNS_ERROR("ReportEvent failed","\n",GetLastError());
		//ACE_ERROR((GMS_ERROR, ACE_TEXT ("ReportEvent failed, lasterr=%d\n"),GetLastError()));
	}
}

//////////////////////////////////////////////////////////////////////
// Function : AddEventSource 
// Purpose  : Add a new source name to the registry by opening a new 
//			  registry subkey under the Application key.
//			  adds a message-file name and a bitmask of supported types.
//
// Input    :	pszLogName	Application log or a custom log.
//				pszSrcName	The event source name. 
//				pszMsgDLL	The path of the message dll file.
//				dwNum		The number of categories id the message file.
//
//////////////////////////////////////////////////////////////////////
void WindowsEventLog::AddEventSource(	const wchar_t * pszLogName, 
										const wchar_t * pszSrcName, 
										const wchar_t * pszMsgDLL , 
										unsigned long	dwNum)
{
	std::basic_string<TCHAR> szBuf = _TEXT("SYSTEM\\CurrentControlSet\\Services\\EventLog\\")+std::basic_string<TCHAR>(pszLogName)
		+_TEXT("\\")+std::basic_string<TCHAR>(pszSrcName);

 	// creates or opens(if key already exists) the registry key
	if (_RegistryKey.Create(HKEY_LOCAL_MACHINE, szBuf.c_str()) == ERROR_SUCCESS)
	{

		// sets the default max size(512KB) of the event log file
		_RegistryKey.SetDWORDValue(L"MaxSize",524288);

		// sets the number of catergories in the message DLL/EXE
		_RegistryKey.SetDWORDValue(L"CategoryCount", dwNum);

		// sets the HD path to find the category message DLL/EXE
		_RegistryKey.SetStringValue(L"CategoryMessageFile", pszMsgDLL, REG_EXPAND_SZ);

		// sets the HD path to find the event message DLL/EXE
		_RegistryKey.SetStringValue(L"EventMessageFile", pszMsgDLL, REG_EXPAND_SZ );

		// sets the type of event the log supports
		_RegistryKey.SetDWORDValue(L"TypesSupported",EVENTLOG_WARNING_TYPE | EVENTLOG_INFORMATION_TYPE | EVENTLOG_ERROR_TYPE);
		
		// closes the registry key handle
		_RegistryKey.Close();
	}else
	{
		UNS_DEBUG(L"_RegistryKey.Create %s failed",L"\n",szBuf);
		//ACE_DEBUG ((GMS_DEBUG ACE_TEXT ("_RegistryKey.Create %s failed\n"),szBuf));
	}
	
}

void WindowsEventLog::RemoveEventSource(const wchar_t * pszLogName,
										const wchar_t *pszSrcName)
{
	// Registry key for adding the event source name. 
	CRegKey _RegistryKey;
	// Create the event source as a subkey of the log. 
	std::basic_string<TCHAR> szBuf = L"SYSTEM\\CurrentControlSet\\Services\\EventLog\\"+std::basic_string<WCHAR>(pszLogName)
		+L"\\"+std::basic_string<WCHAR>(pszSrcName);
	_RegistryKey.Open(HKEY_LOCAL_MACHINE, szBuf.c_str());
	_RegistryKey.DeleteSubKey(pszSrcName);
	_RegistryKey.Close();
}



// EOF