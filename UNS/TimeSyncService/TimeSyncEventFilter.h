/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef _TIME_SYNC_EVENT_FILTER_H
#define _TIME_SYNC_EVENT_FILTER_H


#include "EventManagment.h"

class TimeSyncEventFilter: public EventsFilter
{
public:
	virtual ~TimeSyncEventFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
};
#endif //_TIME_SYNC_EVENT_FILTER_H