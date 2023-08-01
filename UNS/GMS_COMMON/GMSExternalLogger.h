/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2006-2023 Intel Corporation
 */
/*++

@file: GMSExternalLogger.h

--*/

#ifndef _UNS_EVENT_LOGGER_H
#define _UNS_EVENT_LOGGER_H

#include <mutex>
#include "GMSCommonDllExport.h"
#include <ace/SString.h>

class BaseEventLog;

class GMS_COMMON_EXPORT GMSExternalLogger
{
	// This is a singleton use instance() instead of new
private:
	// Log of USE Events
	BaseEventLog *m_logger;

	std::mutex m_StateSemaphore;

	GMSExternalLogger();
public:

	~GMSExternalLogger();

	GMSExternalLogger(const GMSExternalLogger&) = delete;
	GMSExternalLogger& operator = (const GMSExternalLogger&) = delete;

	static GMSExternalLogger& instance() {
		static GMSExternalLogger t;
		return t;
	}

	// Log information event by id and category
	void LogInfoEvent(unsigned short	CategoryID,
					  unsigned long		EventID);
	// Log information event by id, category and message
	void LogInfoEvent(unsigned short	CategoryID,
					  unsigned long		EventID,
					  const ACE_TString &message);
	// Log warning event by id and category
	void LogWarningEvent(unsigned short	CategoryID,
					  unsigned long		EventID);
	// Log warning event by id, category and message
	void LogWarningEvent(unsigned short	CategoryID,
					  unsigned long		EventID,
					  const ACE_TString &message);


	// Record service start message.
	void ServiceStart();

	// Record service stop message.
	void ServiceStopped();

	// Record service stop message.
	void ServiceResume();

	// Record Events for debugging.
	void DebugLog(const ACE_TString &message);

	// Record warning events
	void WarningLog(const ACE_TString &message);

	// Record error events
	void ErrorLog(const ACE_TString &message);
};

#endif // _UNS_EVENT_LOGGER_H
