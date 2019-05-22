/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef __IMSS_FILTER_H_
#define __IMSS_FILTER_H_

#include "EventManagment.h"


class IMSSFilter: public EventsFilter
{
public:
	IMSSFilter() {}
	virtual ~IMSSFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
};

#endif /* __IMSS_FILTER_H_ */