/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
#ifndef __WIN_LOG_FILTER_H_
#define __WIN_LOG_FILTER_H_

#include "EventManagment.h"
#include <ace/Map_Manager.h>
#include <ace/Null_Mutex.h>

class WinLogFilter: public EventsFilter
{
public:
	WinLogFilter();
	virtual ~WinLogFilter() {
		eventsMap_.unbind_all ();
	}
	WinLogFilter(const WinLogFilter&) = delete;
	WinLogFilter& operator = (const WinLogFilter&) = delete;
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const ;
	bool toSubscribe(const GMS_AlertIndication* alert, GmsEventType& et) const ;
private:
	ACE_Map_Manager<int,GmsEventType,ACE_Null_Mutex> eventsMap_;
	bool CheckEventToPublish(unsigned long EventID) const;
	ACE_Map_Manager <unsigned long, int, ACE_Null_Mutex> m_EventsToPublish;
};

#endif /* __WIN_LOG_FILTER_H_ */