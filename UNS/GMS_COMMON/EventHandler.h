/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#ifndef __EVENTHANDLER_H_
#define __EVENTHANDLER_H_
#include "GmsSubService.h"
#include "EventManagment.h"
#include <memory>
#include "GMSCommonDllExport.h"

class GMS_COMMON_EXPORT EventHandler : public GmsSubService
{

public:

	EventHandler(){};

	virtual int init (int argc, ACE_TCHAR *argv[]);

	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	virtual bool ShouldPass() {return true;}

protected:

	virtual int handle_event(MessageBlockPtr mbPtr) = 0;

	virtual const ACE_TString name() = 0;

	virtual std::shared_ptr<EventsFilter> getFilter() = 0;
};

#endif /* __EVENTHANDLER_H_ */