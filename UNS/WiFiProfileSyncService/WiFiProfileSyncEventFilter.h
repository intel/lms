/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018 Intel Corporation
 */
#ifndef _WIFIPROFILE_SYNC_EVENT_FILTER_H
#define _WIFIPROFILE_SYNC_EVENT_FILTER_H


#include "EventManagment.h"

class WiFiProfileSyncEventFilter: public EventsFilter
{
public:
	virtual ~WiFiProfileSyncEventFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
};
#endif //_WIFIPROFILE_SYNC_EVENT_FILTER_H