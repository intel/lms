/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
#ifndef __WATCHDOG_SERVICE_H_
#define __WATCHDOG_SERVICE_H_
#include "GmsSubService.h"
#include "WATCHDOGSERVICE_export.h"

class WATCHDOGSERVICE_Export WatchdogService : public GmsSubService
{
public:
	WatchdogService() : wd_fd(-1), wd_name("/dev/iamt_watchdog"), wd_identity("iamt_wdt"), wd_faults(0), wd_last_error(0) {}

	// ********************* ACE PART ********************************
	virtual int init(int argc, ACE_TCHAR *argv[]);
	virtual int fini(void);
	virtual int resume();
	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"WDG"; }
	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	//*********************** business logic ****************************

protected:
	virtual int handle_timeout(const ACE_Time_Value &current_time, const void *arg);

private:
	bool StartWatchdog();
	void PingWatchdog();
	void StopWatchdog();
	void CloseWatchdog();
	bool CheckIdentity();
	bool SetTimeout();
	void StartTimer();
	void StartShortTimer();

	int wd_fd;
	const std::string wd_name;
	const std::string wd_identity;
	const time_t wd_interval = 120; // seconds
	const time_t wd_short_interval = 1; // seconds
	const int wd_fault_tolerance = 3;
	int wd_faults;
	int wd_last_error;
};

#endif /* __WATCHDOG_SERVICE_H_ */
