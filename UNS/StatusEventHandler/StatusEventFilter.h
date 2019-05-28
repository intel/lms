/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#ifndef __STATUS_EVENT_FILTER_H_
#define __STATUS_EVENT_FILTER_H_

#include "EventManagment.h"
#include <ace/Containers_T.h>
#include "UNSEventsDefinition.h"
#include <memory>

class StatusEventFilter: public EventsFilter
{
public:
	StatusEventFilter(unsigned int maxEventID = MAX_EVENT_NUM);
	virtual ~StatusEventFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
	bool addEvent(unsigned int eventID);
	static bool defaultInitialization(std::shared_ptr<StatusEventFilter> filter);
private:
	ACE_Array<unsigned int> eventsIDList_;
	unsigned int arrayMaxElement_;
};
	

#endif /* __STATUS_EVENT_FILTER_H_ */