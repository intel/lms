/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: LinuxEventLog.cpp

--*/

#include <ace/ace_wchar.h>
#include <sstream>
#include <string>

#include "LinuxEventLog.h"
#include "UNSMessageFile.h"
#include "UNSMessageMap.h"

LinuxEventLog::LinuxEventLog(const char *eventLogSourceName): _ident(eventLogSourceName)
{
}

LinuxEventLog::~LinuxEventLog()
{
}

std::string loadString(unsigned int id)
{
	try
	{
		return UNSMessages.at(id);
	}
	catch (const std::out_of_range &)
	{
		return "Message not found";
	}
}

void LinuxEventLog::LogEvent(unsigned short CategoryID,
			     unsigned long EventID,
			     unsigned short EventType)
{
	std::string event = loadString(EventID);
	openlog(_ident.c_str(), LOG_CONS, LOG_DAEMON);
	syslog(EventType, "%s", event.c_str());
	openlog("lms_svc", LOG_CONS, LOG_DAEMON);
}

void LinuxEventLog::LogEvent(unsigned short CategoryID,
			     unsigned long EventID,
			     unsigned short EventType,
			     const ACE_TCHAR *message)
{
	if (!message)
		return;
	std::string event = loadString(EventID);
	openlog(_ident.c_str(), LOG_CONS, LOG_DAEMON);
	syslog(EventType, "%s %s", event.c_str(), ACE_TEXT_ALWAYS_CHAR(message));
	openlog("lms_svc", LOG_CONS, LOG_DAEMON);
}

void LinuxEventLog::LogEvent(unsigned short CategoryID,
			     unsigned long EventID,
			     unsigned short EventType,
			     const ACE_TCHAR *ArrayOfStrings[],
			     unsigned int NumOfArrayStr,
			     void *RawData,
			     unsigned long RawDataSize)
{
	if (!ArrayOfStrings)
		return;
	std::string event = loadString(EventID);
	//will replace '%i' with ArrayOfStrings[i]
	for (unsigned int i=0; i < NumOfArrayStr; i++) {
		std::ostringstream ss;
		ss << "%" << i + 1;
		std::string::size_type pos = event.find(ss.str());
		if (pos == std::string::npos)
			continue;
		if (!ArrayOfStrings[i])
			continue;
		event.replace(pos, ss.str().size(), ACE_TEXT_ALWAYS_CHAR(ArrayOfStrings[i]));
	}
	openlog(_ident.c_str(), LOG_CONS, LOG_DAEMON);
	syslog(EventType, "%s", event.c_str());
	openlog("lms_svc", LOG_CONS, LOG_DAEMON);
}
