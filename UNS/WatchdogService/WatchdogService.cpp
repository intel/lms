/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
#include "WatchdogService.h"
#include "UNSEventsDefinition.h"
#include <linux/watchdog.h>

int WatchdogService::init(int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"init");
	int ret = initSubService(argc, argv);
	if (ret)
		return ret;
	// Start timer to have first ping immediately
	ACE_Time_Value ace_interval((wd_interval / 2) * GMS_ACE_SECOND);
	ACE_Reactor::instance()->schedule_timer(this, 0, ACE_Time_Value::zero, ace_interval);
	startSubService();
	return 0;
}

int WatchdogService::fini(void)
{
	FuncEntryExit<void> fee(this, L"fini");
	ACE_Reactor::instance()->cancel_timer(this);
	StopWatchdog();
	return 0;
}

const ACE_TString WatchdogService::name()
{
	return GMS_WATCHDOGSERVICE;
}

LMS_SUBSERVICE_DEFINE (WATCHDOGSERVICE, WatchdogService)

void WatchdogService::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	FuncEntryExit<void> fee(this, L"HandleAceMessage");

	switch (type) 
	{
	case MB_TIMER_EXPIRED:
		PingWatchdog();
		break;
	default:
		GmsSubService::HandleAceMessage(type, mbPtr);
		break;
	}
}

int WatchdogService::handle_timeout(const ACE_Time_Value &current_time, const void *arg)
{
	FuncEntryExit<void> fee(this, L"handle_timeout");

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_TIMER_EXPIRED);
	this->putq(mbPtr->duplicate());

	return 0;
}

int WatchdogService::resume()
{
	GmsSubService::resume();
	PingWatchdog();

	return 0;
}

bool WatchdogService::CheckIdentity()
{
	errno = 0;
	struct watchdog_info wd_info = { 0 };

	if (::ioctl(wd_fd, WDIOC_GETSUPPORT, &wd_info) == -1)
	{
		UNS_ERROR(L"Watchdog device (%C) get support failed [%d]:%C\n",
				  wd_name.c_str(), errno, strerror(errno));
		return false;
	}
	if (wd_identity != (const char*)wd_info.identity)
	{
		UNS_ERROR(L"Watchdog device (%C) has unsupported identity %C\n",
				wd_name.c_str(), (const char*)wd_info.identity);
		return false;
	}
	return true;
}

bool WatchdogService::SetTimeout()
{
	errno = 0;
	if (::ioctl(wd_fd, WDIOC_SETTIMEOUT, &wd_interval) == -1)
	{
		UNS_ERROR(L"Watchdog device (%C) set timeout failed [%d]:%C\n",
				  wd_name.c_str(), errno, strerror(errno));
		return false;
	}
	return true;
}

bool WatchdogService::StartWatchdog()
{
	bool res = true;
	FuncEntryExit<decltype(res)> fee(this, L"StartWatchdog", res);
	ACE_TString err_str;

	if (wd_fd != -1)
	{
		goto out;
	}

	errno = 0;
	wd_fd = ::open(wd_name.c_str(), O_CLOEXEC | O_WRONLY);
	if (wd_fd == -1)
	{
		res = false;
		int err = wd_last_error = errno;
		wd_faults++;
		UNS_ERROR(L"Watchdog device (%C) open failed [%d]:%C (faults %d)\n",
				wd_name.c_str(), err, strerror(err), wd_faults);
		if (wd_faults >= wd_fault_tolerance)
		{
			UNS_ERROR(L"Stop polling watchdog device (%C) - too many failures\n",
					  wd_name.c_str());
			goto fail;
		}
		StartShortTimer();
		goto out;
	}
	if (wd_faults)
	{
		StartTimer();
	}
	wd_faults = 0;
	wd_last_error = 0;

	if(!CheckIdentity())
	{
		res = false;
		goto fail;
	}

	if (!SetTimeout())
	{
		res = false;
		goto fail;
	}
	goto out;

fail:
	ACE_Reactor::instance()->cancel_timer(this);
	switch (wd_last_error)
	{
		case ENOENT:
			err_str = ACE_TEXT("No device.");
			break;
		case EBUSY:
			err_str = ACE_TEXT("Device is busy.");
			break;
		default:
			err_str = ACE_TEXT("Internal error.");
			break;
	}
	sendAlertIndicationMessage(CATEGORY_GENERAL, EVENT_WATCHDOG_ERROR, ACE_TEXT("Failed to send watchdog keepalive."), err_str);
	CloseWatchdog();

out:
	return res;
}

void WatchdogService::PingWatchdog()
{
	FuncEntryExit<void> fee(this, L"PingWatchdog");

	if (!StartWatchdog())
		return;

	errno = 0;
	int ret = ::ioctl(wd_fd, WDIOC_KEEPALIVE, NULL);
	if (ret == -1)
	{
		int error = errno;
		UNS_ERROR(L"Watchdog device (%C) ping failed [%d]:%C\n",
				  wd_name.c_str(), error, strerror(error));
		CloseWatchdog();
		if (error == ENODEV)
		{ // on resume we should try to send ping in short interval
			wd_faults++;
			StartShortTimer();
		}
	}
}

void WatchdogService::StopWatchdog()
{
	FuncEntryExit<void> fee(this, L"StopWatchdog");

	CloseWatchdog();
}

void WatchdogService::CloseWatchdog()
{
	if (wd_fd != -1)
	{
		::close(wd_fd);
		wd_fd = -1;
	}
}

void WatchdogService::StartTimer()
{
	ACE_Reactor::instance()->cancel_timer(this);
	ACE_Time_Value ace_interval((wd_interval / 2) * GMS_ACE_SECOND);
	ACE_Reactor::instance()->schedule_timer(this, 0, ace_interval, ace_interval);
}

void WatchdogService::StartShortTimer()
{
	ACE_Reactor::instance()->cancel_timer(this);
	ACE_Time_Value ace_interval(wd_short_interval * GMS_ACE_SECOND);
	ACE_Reactor::instance()->schedule_timer(this, 0, ace_interval, ace_interval);
}