//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2021 Intel Corporation

#include "EventLog.h"

#define EVENT_LOG_SVCNAME L"WMIRegistrationService"

VOID WriteToEventLog(EVENT_LOG_TYPE EventType, DWORD MessageID)
{
	HANDLE  hEventSource;

	hEventSource = RegisterEventSource(NULL, EVENT_LOG_SVCNAME);

	if (hEventSource != NULL)
	{
		/* Write to the event log. */

		ReportEvent(hEventSource,// event log handle
			EventType,           // event type
			0,                   // event category
			MessageID,           // event identifier
			NULL,                // no security identifier
			0,                   // num of strings in the message array
			0,                   // no binary data
			NULL,                // the message
			NULL);               // no binary data

		DeregisterEventSource(hEventSource);
	}
}
