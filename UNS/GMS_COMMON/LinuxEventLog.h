/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: LinuxEventLog.h

--*/
#ifndef _LINUX_EVENT_LOG_H
#define _LINUX_EVENT_LOG_H

#include <syslog.h>
#include <string>
#include "BaseEventLog.h"

//Event types
#define EVENTLOG_SUCCESS          LOG_INFO
#define EVENTLOG_ERROR_TYPE       LOG_ERR
#define EVENTLOG_WARNING_TYPE     LOG_WARNING
#define EVENTLOG_INFORMATION_TYPE LOG_INFO

class LinuxEventLog : public BaseEventLog
{
public:
	LinuxEventLog(const char *eventLogSourceName);

	~LinuxEventLog();

	virtual void LogEvent(unsigned short CategoryID, unsigned long EventID, unsigned short EventType);

	virtual void LogEvent(unsigned short CategoryID, unsigned long EventID, unsigned short EventType,
			      const ACE_TCHAR *message);

	virtual void LogEvent(unsigned short CategoryID,unsigned long EventID, unsigned short EventType,
			      const ACE_TCHAR *ArrayOfStrings[], unsigned short NumOfArrayStr,
			      void *RawData=NULL, unsigned long RawDataSize=0);
private:
	std::string _ident;
};

#endif //_LINUX_EVENT_LOG_H
