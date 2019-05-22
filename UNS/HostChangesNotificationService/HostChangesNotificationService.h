/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
#ifndef __HOSTCHANGESNOTIFICATIONSERVICE_H_
#define __HOSTCHANGESNOTIFICATIONSERVICE_H_

#include "HostChangesNotificationService_Export.h"
#include "GmsSubService.h"

class HostChangesNotificationService : public GmsSubService
{
  public:

	HostChangesNotificationService();

	// ********************* ACE PART ********************************
    virtual int init (int argc, ACE_TCHAR *argv[]);

    virtual int fini (void);

	virtual const ACE_TString name();
	
	virtual int resume();

	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);

protected:

	virtual int handle_timeout (const ACE_Time_Value &current_time,const void *arg);

	void Action();

private:
	std::string m_hostFQDN;
	// ******************************************************************
};


#endif