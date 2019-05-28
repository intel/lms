/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2008-2019 Intel Corporation
 */
/*++

@file: CimToEventTranslator.h

--*/
//----------------------------------------------------------------------------
//
//  Notes:      Translate CIM_AlertIndication to internal event type
//
//----------------------------------------------------------------------------

#pragma once


#include "EventManagment.h"
#include <ace/Map_Manager.h>
#include <ace/Null_Mutex.h>
#include <string>

class CimToEventTranslator
{
private:
	ACE_Map_Manager< ACE_TString , GmsEventType,ACE_Null_Mutex> m_eventsMap;
	CimToEventTranslator(void);

	ACE_TString setMessage(GMS_AlertIndication &unsEvent, const std::string &cimMessageText, GmsEventType& et);


public:
	static CimToEventTranslator& instance() {
		static CimToEventTranslator p;
		return p; 
	}
	~CimToEventTranslator(void)
	{
	}
	bool translate(const std::string &cimMessageID, const std::string &cimMessageArg, const std::string &cimMessageText, GMS_AlertIndication &unsEvent);

};
