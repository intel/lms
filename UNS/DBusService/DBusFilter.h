/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2019 Intel Corporation
 */
#ifndef __DBUS_FILTER_H_
#define __DBUS_FILTER_H_

#include "EventManagment.h"
#include <ace/Containers_T.h>
#include "UNSEventsDefinition.h"
#include <memory>

class DBusFilter: public EventsFilter
{
public:
	DBusFilter(unsigned int maxEventID = MAX_EVENT_NUM);
	virtual ~DBusFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
	bool addEvent(unsigned int eventID);
	static bool defaultInitialization(std::shared_ptr<DBusFilter> filter);
private:
	ACE_Array<unsigned int> eventsIDList_;
	unsigned int arrayMaxElement_;
};

#endif /* __DBUS_FILTER_H_ */
