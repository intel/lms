/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#ifndef __COMEVENTHANDLER_H_
#define __COMEVENTHANDLER_H_

#include "global.h"
#include "EventHandler.h"
#include "ComFilter.h"
#include "COMEVENTHANDLER_export.h"
#include <memory>

class COMEVENTHANDLER_Export COMEventHandler : public EventHandler
{
public:

	COMEventHandler();

protected:

	virtual int init (int argc, ACE_TCHAR *argv[]);

	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual const ACE_TString name();

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}

private:
	void initFilter();
	int COMLogging(GMS_AlertIndication *alert);
	std::shared_ptr<ComFilter> filter_;
};

#endif /* __COMEVENTHANDLER_H_ */