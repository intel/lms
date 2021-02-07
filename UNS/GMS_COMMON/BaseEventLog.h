/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2007, 2009-2021 Intel Corporation
 */
/*++

@file: BaseEventLog.h

--*/
//----------------------------------------------------------------------------
//
//  Notes:      Definistion of Abstract Class BaseEventLog used to set an Event to the log
//
//----------------------------------------------------------------------------

#ifndef _BASE_LOG_H
#define _BASE_LOG_H

#include <ace/ace_wchar.h>

#define ERROR_EVENT 0
#define DEBUG_EVENT 1
#define WARNING_EVENT 2


class BaseEventLog 
{

public:
	//*********************************************
	//BaseEventLog:
	//Ctor to BaseEventLog object
	//*********************************************
	BaseEventLog(){}

	//*********************************************
	//~BaseEventLog:
	//Dtor to BaseEventLog object
	//*********************************************
	virtual ~BaseEventLog(){};

	//*********************************************
	//LogEvent:
	//Record Events for debugging.
	//params:
	//@categoryID - category ID
	//@eventID    - event ID
	//*********************************************
	virtual void LogEvent(unsigned short CategoryID, unsigned long EventID, unsigned short EventType) = 0;


	virtual void LogEvent(	unsigned short CategoryID, unsigned long EventID, unsigned short EventType,
					const ACE_TCHAR* message) = 0;
	//*********************************************
	//LogEvent:
	//Record Events for debugging.
	//params:
	//@categoryID - category ID
	//@eventID    - event ID
	//@EventType
	//@ArrayOfStrings
	//@NumOfArrayStr
	//@RawData
	//@RawDataSize
	//*********************************************
	virtual void LogEvent(unsigned short CategoryID,unsigned long	EventID
		          , unsigned short EventType,const ACE_TCHAR * ArrayOfStrings[],
				  unsigned short NumOfArrayStr, void * RawData=NULL, unsigned long RawDataSize=0)=0;
};

#endif //_BASE_LOG_H
