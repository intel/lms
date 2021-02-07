/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2006-2007, 2009-2021 Intel Corporation
 */
/*++

@file: GMSExternalLogger.cpp

--*/

//*****************************************************************************
//
// Class:			GMSExternalLogger
// Date created:	28 May 2006
// Description:		EventLogger for Local Management Service.
//
//*****************************************************************************
#include "GMSExternalLogger.h"
#include <iostream>
#ifdef WIN32
#include "WindowsEventLog.h"
#else
#include "LinuxEventLog.h"
#endif
#include "UNSMessageFile.h"

// Constructor
#ifdef WIN32
const wchar_t EVENT_LOG_UNS_SOURCE_NAME[] = L"LMS";
const wchar_t EVENT_LOG_LOG_NAME[] = L"Application";
const unsigned long EVENT_LOG_CATEGORY_COUNT = 9;
#else
const char EVENT_LOG_UNS_SOURCE_NAME[] = "LMS";
#endif // WIN32

const ACE_TCHAR	UNS_SERVICE_START[] = ACE_TEXT("Local Management Service started.");
const ACE_TCHAR	UNS_SERVICE_STOPPED[] = ACE_TEXT("Local Management Service stopped.");
const ACE_TCHAR	UNS_SERVICE_RESUME[] = ACE_TEXT("Local Management Service resumed.");

GMSExternalLogger::GMSExternalLogger() 
{
#ifdef WIN32
	m_logger = new WindowsEventLog(EVENT_LOG_LOG_NAME, EVENT_LOG_UNS_SOURCE_NAME, EVENT_LOG_CATEGORY_COUNT);
#else
	m_logger = new LinuxEventLog(EVENT_LOG_UNS_SOURCE_NAME);
#endif
}

GMSExternalLogger::~GMSExternalLogger()
{
	if (m_logger != NULL) 
	{
		delete m_logger;
		m_logger=NULL;
	}
}

// Log information event by id and category
void GMSExternalLogger::LogInfoEvent(unsigned short	CategoryID, 
			  	  unsigned long		EventID) 
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	if (m_logger != NULL) {
		m_logger->LogEvent(CategoryID , EventID, EVENTLOG_INFORMATION_TYPE);
	}
	
}

// Log information event by id, category and message
void GMSExternalLogger::LogInfoEvent(unsigned short	CategoryID, 
			  		unsigned long EventID, const ACE_TString &message)
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	if (m_logger != NULL) {
		m_logger->LogEvent(CategoryID , EventID, EVENTLOG_INFORMATION_TYPE, message.c_str());
	}
}

void GMSExternalLogger::LogWarningEvent(unsigned short	CategoryID, 
			  	  unsigned long		EventID) 
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	if (m_logger != NULL) {
		m_logger->LogEvent(CategoryID , EventID, EVENTLOG_WARNING_TYPE);
	}
	
}

// Log warning event by id, category and message
void GMSExternalLogger::LogWarningEvent(unsigned short	CategoryID, 
			  	  unsigned long EventID, const ACE_TString &message)
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	if (m_logger != NULL) {
		m_logger->LogEvent(CategoryID , EventID, EVENTLOG_WARNING_TYPE, message.c_str());
	}
}

	

// Record service start message.
void GMSExternalLogger::ServiceStart()
{
	DebugLog(UNS_SERVICE_START);
}

// Record service stop message.
void GMSExternalLogger::ServiceStopped()
{
	DebugLog(UNS_SERVICE_STOPPED);
}

// Record service resume message.
void GMSExternalLogger::ServiceResume()
{
	DebugLog(UNS_SERVICE_RESUME);
}
	
// Record Events for debugging.
void GMSExternalLogger::DebugLog(const ACE_TString &message)
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	const ACE_TCHAR *lpStrings[] = { message.c_str() };
	unsigned int NumOfStrings = 1;
	if (m_logger != NULL)
	{
		m_logger->LogEvent(UNS_GENERAL, UNS_INFO_MESSAGE, EVENTLOG_INFORMATION_TYPE, lpStrings, NumOfStrings, NULL, 0);
	}
#ifndef NO_STDOUT_DEBUG_LOG
	std::cout << message.c_str();
#endif
}


// Record warning events
void GMSExternalLogger::WarningLog(const ACE_TString &message)
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	const ACE_TCHAR *lpStrings[] = { message.c_str() };
	unsigned int NumOfStrings = 1;
	if (m_logger != NULL)
	{
		m_logger->LogEvent(UNS_GENERAL, UNS_WARNING_MESSAGE, EVENTLOG_WARNING_TYPE, lpStrings, NumOfStrings, NULL, 0);
	}
#ifndef NO_STDOUT_DEBUG_LOG
	std::cout << message.c_str();
#endif
}

// Record error events
void GMSExternalLogger::ErrorLog(const ACE_TString &message)
{
	std::lock_guard<std::mutex> lock(m_StateSemaphore);
	const ACE_TCHAR *lpStrings[] = { message.c_str() };
	unsigned int NumOfStrings = 1;
	if (m_logger != NULL) {
		m_logger->LogEvent(UNS_GENERAL, UNS_ERROR_MESSAGE, EVENTLOG_ERROR_TYPE, lpStrings, NumOfStrings, NULL, 0);
	}
#ifndef NO_STDOUT_DEBUG_LOG
	std::cout << message.c_str();
#endif
}
