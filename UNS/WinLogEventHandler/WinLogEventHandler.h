/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#ifndef __WINLOGEVENTHANDLER_H_
#define __WINLOGEVENTHANDLER_H_
#include "global.h"
#include "GMSExternalLogger.h"
#include "EventHandler.h"
#include "WinLogFilter.h"
#include "WINLOGEVENTHANDLER_export.h"

class WINLOGEVENTHANDLER_Export WinLogEventHandler : public EventHandler
{
public:

	WinLogEventHandler();

	virtual int init (int argc, ACE_TCHAR *argv[]);

	virtual int fini (void);

protected:

	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual const ACE_TString name();

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}

private:

	int winLogging(GMS_AlertIndication *alert);

	GMSExternalLogger			*logger_;
	std::shared_ptr<WinLogFilter> filter_;
};

#endif /* __WINLOGEVENTHANDLER_H_ */