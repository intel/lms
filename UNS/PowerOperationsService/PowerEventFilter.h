/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef _POWER_EVENT_FILTER_H
#define _POWER_EVENT_FILTER_H


#include "EventManagment.h"

class PowerEventFilter: public EventsFilter
{
public:
	virtual ~PowerEventFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
};
#endif //_POWER_EVENT_FILTER_H