/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
#ifndef __PORTFORWARDINGSERVICE_H_
#define __PORTFORWARDINGSERVICE_H_

#include "GmsSubService.h"
#include "PORTFORWARDINGSERVICE_export.h"



class LMS_Thread_Impl;

class PORTFORWARDINGSERVICE_Export PortForwardingService : public GmsSubService
{
  public:

	PortForwardingService();


	// ********************* ACE PART ********************************
    virtual int init (int argc, ACE_TCHAR *argv[]);

    virtual int fini (void);

	virtual const ACE_TString name();

	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);

	virtual int suspend();
	virtual int resume();


	// ******************************************************************

	//*********************** business logic ****************************
	void AddWarningToMessageLog(const char* message);
	void AddDebugToMessageLog(const char* message);
	HDEVNOTIFY _registerDeviceNotifications(HANDLE drvHandle);
	void _unregisterDeviceNotifications(HDEVNOTIFY notifyHandle);
	void BroadcastActive();
	void BroadcastFailure(bool failure);

	bool GetUnregisterDeviceEvents();
	void SetUnregisterDeviceEvents(bool unreg);

	void CloseHeciHandle();
	void NotifyHeciEnable();

protected:

  private:


	void OnStop();

	// Data members.
	LMS_Thread_Impl *m_lmsMainThread;
	bool m_needBroadcastStarted;
	bool m_needBroadcastResumed;
	bool m_needBroadcastPfwActivated;
};



#endif /* __PORTFORWARDINGSERVICE_H_ */