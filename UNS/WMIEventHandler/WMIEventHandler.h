/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#ifndef __WMIEVENTHANDLER_H_
#define __WMIEVENTHANDLER_H_
#include "global.h"
#include "EventManagment.h"
#include "EventHandler.h"
#include "WMIEVENTHANDLER_export.h"
#include "WMIFilter.h"

class WMIEVENTHANDLER_Export WMIEventHandler : public EventHandler
{
public:
	WMIEventHandler();

	virtual int init (int argc, ACE_TCHAR *argv[]);
protected:

	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual const ACE_TString name();

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}

private:
	int WMILogging(GMS_AlertIndication *alert);
	bool shouldAppendMessageArgToEnd(unsigned long id);
	std::shared_ptr<WMIFilter> filter_;
};

#endif /* __WMIEVENTHANDLER_H_ */