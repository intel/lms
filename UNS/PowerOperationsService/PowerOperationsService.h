/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef __POWEROPERATIONSSERVICE_H_
#define __POWEROPERATIONSSERVICE_H_

#include "EventHandler.h"
#include "POWEROPERATIONSSERVICE_export.h"
#include "PowerEventFilter.h"

 

class POWEROPERATIONSSERVICE_Export PowerOperationsService : public EventHandler
{
	friend ACE_THR_FUNC_RETURN CallSetSuspendState(void*);
public:
	PowerOperationsService() :m_filter(new PowerEventFilter), m_addCapabilitiesRequiredButNoPfw(false), m_retryReboot(false), m_retryAttempt(0) {}
protected:
	virtual int init(int argc, ACE_TCHAR *argv[]);
	virtual int fini (void);
	virtual int suspend();
	virtual int handle_event (MessageBlockPtr mbPtr);
	virtual const ACE_TString name();
	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return m_filter;
	}
private:
	//get system's power capabilities from OS
	//returns false on faliure. sleep/hibernate parameters are filled according to OS API results.
	void addPowerCapabilities();
	int initiateShutDown(bool reboot, int attempt);
	void loadStrings();
	int handlePublishEvent(const GMS_AlertIndication & alert);
	int handleRemoteGracefulPowerEvents(GMS_AlertIndication OrgEvent);

	int handle_timeout (const ACE_Time_Value &current_time,const void *arg);

	bool suspendOp(bool hibernate);
	bool shutdownOp(bool reboot, int attempt, std::wstringstream &ss);

	std::shared_ptr<PowerEventFilter> m_filter;
	std::wstring m_shutdownMessageStr;
	std::wstring m_rebootMessageStr;

	bool m_addCapabilitiesRequiredButNoPfw;

	//to pass CallSetSuspendState
	struct CallSetSuspendStateArgs
	{
		PowerOperationsService* service;
		bool hibernate;
	};

	//Retry data
	bool m_retryReboot;
	int m_retryAttempt;

};

#endif /* __POWEROPERATIONSSERVICE_H_ */
