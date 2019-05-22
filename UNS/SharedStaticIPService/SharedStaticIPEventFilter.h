/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef _SHARED_STATIC_IP_EVENT_FILTER_H
#define _SHARED_STATIC_IP_EVENT_FILTER_H


#include "EventManagment.h"

class SharedStaticIPEventFilter: public EventsFilter
{
public:
	virtual ~SharedStaticIPEventFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
};
#endif //_SHARED_STATIC_IP_EVENT_FILTER_H