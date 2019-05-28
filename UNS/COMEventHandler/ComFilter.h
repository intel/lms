/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#ifndef __COM_FILTER_H_
#define __COM_FILTER_H_

#include "EventManagment.h"
#include <ace/Containers_T.h>
#include "UNSEventsDefinition.h"
#include <memory>

class ComFilter: public EventsFilter
{
public:
	ComFilter(unsigned int maxEventID = MAX_EVENT_NUM);
	virtual ~ComFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
	bool addEvent(unsigned int eventID);
	static bool defaultInitialization(std::shared_ptr<ComFilter> filter);
private:
	ACE_Array<unsigned int> eventsIDList_;
	unsigned int arrayMaxElement_;
};

#endif /* __COM_FILTER_H_ */