/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#ifndef __WMI_FILTER_H_
#define __WMI_FILTER_H_

#include "EventManagment.h"
#include <ace/Containers_T.h>
#include "UNSEventsDefinition.h"
#include <memory>
#include "WMIEVENTHANDLER_export.h"

class WMIEVENTHANDLER_Export WMIFilter: public EventsFilter
{
public:
	WMIFilter(unsigned int maxEventID = MAX_EVENT_NUM);
	virtual ~WMIFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
	bool addEvent(unsigned int eventID);
	static bool defaultInitialization(std::shared_ptr<WMIFilter> filter);
private:
	ACE_Array<unsigned int> eventsIDList_;
	unsigned int arrayMaxElement_;
};

#endif /* __WMI_FILTER_H_ */