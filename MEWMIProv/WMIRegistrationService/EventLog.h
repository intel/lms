//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2021 Intel Corporation

#ifndef _EVENT_LOG_H
#define _EVENT_LOG_H
#include <Windows.h>

// logging levels
typedef enum _EVENT_LOG_TYPE
{
	EVENT_LOG_ERROR = EVENTLOG_ERROR_TYPE,
	EVENT_LOG_WARNING = EVENTLOG_WARNING_TYPE,
	EVENT_LOG_INFORMATION = EVENTLOG_INFORMATION_TYPE

}EVENT_LOG_TYPE;

void WriteToEventLog(EVENT_LOG_TYPE EventType, DWORD MessageID);

#endif
