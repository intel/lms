/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2018 Intel Corporation
 */
#ifndef __TIME_SYNC_SERVICE_H_
#define __TIME_SYNC_SERVICE_H_
#include "EventHandler.h"
#include "TimeSyncEventFilter.h"
#include "TIMESYNCSERVICE_export.h"

class TIMESYNCSERVICE_Export TimeSyncService : public EventHandler
{
  public:

	  TimeSyncService() :m_needToSyncOnResume(false), m_syncRequiredButNoPfw(false), m_filter(new TimeSyncEventFilter) {}

	// ********************* ACE PART ********************************
	
	virtual int init (int argc, ACE_TCHAR *argv[]);

    virtual int fini (void);

	virtual int resume();

	virtual const ACE_TString name();

	//*********************** business logic ****************************
	
protected:


	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual int handle_timeout (const ACE_Time_Value &current_time,const void *arg);
	
	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return m_filter;
	}
	
private:

	int handlePublishEvent(const GMS_AlertIndication & alert);
	bool GetUTCTime(unsigned int & UTCTime); 
	void PerformSync();
	bool m_needToSyncOnResume;
	bool m_syncRequiredButNoPfw;
#ifdef _DEBUG
	void printTime(std::wstring message, unsigned int time);
#endif
	static const unsigned long ms_SecondsInDay;
	static const unsigned long ms_FifteenMinutes;
	static const unsigned long ms_Interval;
	static const unsigned long ms_MaxDiff;
	static const unsigned int  ms_SizeOfTimeString;
	static unsigned int ms_LastTimeSync; //saves the last time a valid time sync was performed

	std::shared_ptr<TimeSyncEventFilter> m_filter;
};

#endif /* __TIME_SYNC_SERVICE_H_ */