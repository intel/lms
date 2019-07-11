/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "TimeSyncService.h"
#include "TimeSynchronizationClient.h"
#include "UNSEventsDefinition.h"
#include <cmath>

const unsigned long TimeSyncService::ms_SecondsInDay = 24 * 60 * GMS_ACE_MINUTE;//interval between every two synchs.
const unsigned long TimeSyncService::ms_FifteenMinutes = 15 * GMS_ACE_MINUTE; //interval between every two synchs for debug only.
#ifdef _DEBUG
const unsigned long TimeSyncService::ms_Interval = ms_FifteenMinutes;
#endif
#ifndef _DEBUG
const unsigned long TimeSyncService::ms_Interval = ms_SecondsInDay;
#endif
const unsigned long TimeSyncService::ms_MaxDiff = 30; //max difference in seconds between the UTC time to AMT time.
const unsigned int  TimeSyncService::ms_SizeOfTimeString = 26;
unsigned int TimeSyncService::ms_LastTimeSync = 0;

int
TimeSyncService::init (int argc, ACE_TCHAR *argv[])
{
	UNS_DEBUG(L"TimeSyncService::init\n");

	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);

		return retVal;
	}

	m_needToSyncOnResume = false;
	m_syncRequiredButNoPfw = false;
	ACE_Time_Value interval (ms_Interval);
	ACE_Reactor::instance()->schedule_timer (this,
											0,
											ACE_Time_Value::zero,
											interval);
	return 0;
}

int
TimeSyncService::fini (void)
{
	UNS_DEBUG(L"TimeSync service stopped\n");
	ACE_Reactor::instance()->cancel_timer (this);
	return 0;
}


const ACE_TString
TimeSyncService::name()
{
	return GMS_TIMESYNCSERVICE;
}


ACE_FACTORY_DEFINE (TIMESYNCSERVICE, TimeSyncService)

//Note : the return value is not used (see EventHandler::HandleAceMessage)
int TimeSyncService::handle_event (MessageBlockPtr mbPtr )
{
	UNS_DEBUG(L"%s::handle_event\n", name().c_str());

	int type = mbPtr->msg_type();
	switch (type)
	{
	case MB_TIMER_EXPIRED:
		PerformSync();
		return 1;
	case MB_PUBLISH_EVENT:
		GMS_AlertIndication * pGMS_AlertIndication = nullptr;
		pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
		if (pGMS_AlertIndication != nullptr)
		{
			return handlePublishEvent(*pGMS_AlertIndication);
		}
		else
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid data block.\n")), -1);
		}
	}

	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message.\n")), -1);
}


int TimeSyncService::handlePublishEvent(const GMS_AlertIndication & alert)
{
	switch (alert.category)
	{

	case CATEGORY_UNS:
		switch (alert.id)
		{
		case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
			UNS_DEBUG(L"%s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE. m_syncRequiredButNoPfw: %d\n", name().c_str(), m_syncRequiredButNoPfw);
			if (m_syncRequiredButNoPfw)
			{
				PerformSync();
				m_syncRequiredButNoPfw = false;
				return 1;
			}
			break;
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message id.\n")), -1);
			break;

		}
		break;

	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message category.\n")), -1);
		break;
	}
	return 1;
}


int
TimeSyncService::handle_timeout (const ACE_Time_Value &current_time,const void *arg)
{
	UNS_DEBUG(L"%s handle_timeout\n",name().c_str());

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_TIMER_EXPIRED);
	this->putq(mbPtr->duplicate());

	return 0;
}


#ifdef _DEBUG
//This function prints the message given, appended with the time (given as unsigned int)
void
TimeSyncService::printTime(std::wstring message, unsigned int time)
{
	//creates a time_t object from the unsigned int
	time_t rawtime(time);
	struct tm time_tm;
	//creates a tm from the time_t (to split it into day, month etc.)
#ifdef WIN32
	gmtime_s(&time_tm, &rawtime);
#else
	gmtime_r(&rawtime, &time_tm);
#endif // WIN32
	//convert the tm into a string
	char time_s[ms_SizeOfTimeString];
	strftime(time_s, ms_SizeOfTimeString, "%c", &time_tm);
	UNS_DEBUG(L"%s:: %W\t%C\n", name().c_str(), message.c_str(), time_s);

}
#endif

// This function returns the current UTC time, or -1 if fails.

//change to bool return value...
bool
TimeSyncService::GetUTCTime(unsigned int & UTCTime)
{
	time_t rawtime;
	rawtime = time(NULL);
	if (rawtime == -1)
	{
		UNS_ERROR(L"%s:: Get local time failed, aborting sync operation\n", name().c_str());
		return false;
	}
	UTCTime = (unsigned int)rawtime;
	return true;
}

int TimeSyncService::resume()
{
	GmsSubService::resume();
	if (m_needToSyncOnResume)
	{
		m_needToSyncOnResume = false;
		PerformSync();
	}

	return 0;
}


void
TimeSyncService::PerformSync()
{
	UNS_DEBUG(L"%s::PerformSync\n", name().c_str());

	if (!m_mainService->GetPortForwardingStarted()) {
		UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting sync operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
		m_syncRequiredButNoPfw = true;
		return;
	}


	bool timeSyncState;
	//Check if LocalTimeSyncEnable = DEFAULT_TRUE or CONFIGURED_TRUE
	TimeSynchronizationClient timeClient;
	if (!timeClient.GetLocalTimeSyncEnabledState(timeSyncState))//error getting the Time Sync state.
	{
		m_needToSyncOnResume = true;//update the bool to true if sync should be performed
		UNS_ERROR(L"%s:: Error - retrieving LocalTimeSyncEnable state, aborting sync operation\n", name().c_str());
		return;
	}
	else if(!timeSyncState) // The FW LocalTimeSyncEnable field is FALSE
	{
		UNS_DEBUG(L"%s:: FW LocalTimeSyncEnable is FALSE, aborting sync operation\n", name().c_str());
		return;
	}
	unsigned int AMTTime, UTCTime;
	//Get the AMT time
	bool ret = timeClient.GetAMTTime(AMTTime);
	if (!ret)
	{
		UNS_ERROR(L"%s:: GetAMTTime failed, aborting sync operation\n", name().c_str());
		return;
	}
#ifdef _DEBUG
	printTime(L"Time in FW is: ", AMTTime);
#endif

	//Get the UTC time
	if (!GetUTCTime(UTCTime))
	{
		UNS_ERROR(L"%s:: Cannot get UTC time. aborting sync operation\n", name().c_str());
		return;
	}
#ifdef _DEBUG
	printTime(L"UTC time is: ", UTCTime);
#endif

	//Updates the AMT time if it differs more than should from the UTC time
	double diff = difftime(UTCTime, AMTTime);
	if (std::abs(diff) > ms_MaxDiff)
	{
		UNS_DEBUG(L"%s:: Difference is more than %d seconds, time sync will be performed\n", name().c_str(), ms_MaxDiff);
		ret = timeClient.SetAMTTime(UTCTime);
		if (!ret)
		{
			UNS_ERROR(L"%s:: SetAMTTime failed, aborting sync operation\n", name().c_str());
			return;
		}
#ifdef _DEBUG
		//Print the new AMT time for debug
		ret = timeClient.GetAMTTime(AMTTime);
		if (!ret)
		{
			UNS_ERROR(L"%s:: GetAMTTime failed.\n", name().c_str());
			return;
		}
		printTime(L"Time in FW is now: ", AMTTime);
#endif
	}
	else
	{
		UNS_DEBUG(L"%s:: Difference is less than %d seconds, time sync will not be performed\n", name().c_str(), ms_MaxDiff);
	}
	ms_LastTimeSync = UTCTime;//update the ms_LastTimeSync value to hold the synchronization time.
	UNS_DEBUG(L"%s:: ms_LastTimeSync set to %d\n", name().c_str(), ms_LastTimeSync);
}

