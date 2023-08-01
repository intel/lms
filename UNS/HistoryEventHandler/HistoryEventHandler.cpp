/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2022 Intel Corporation
 */
#include "HistoryEventHandler.h"
#include "DataStorageGenerator.h"
#include <sstream>

HistoryEventHandler:: HistoryEventHandler():filter_(new IMSSFilter)
	{
		IMSSHistoryStorage_ = IMSS_EVENT_HISTORY;
	}


	int
	HistoryEventHandler::init (int argc, ACE_TCHAR *argv[])
	{
		std::wstring defaultValue = L"";
			
		std::wstring s;
		if (!DSinstance().GetDataValue(IMSSHistoryStorage_, s))
		{
			//This means registry is not exist and should be created
			if (!DSinstance().SetDataValue(IMSSHistoryStorage_, defaultValue))
			{
				UNS_ERROR(L"HistoryEventHandler::createHistoryRegistry failed err=%d\n", GetLastError());
			}			
		}
		
		int retVal = EventHandler::init(argc, argv);
		if (retVal != 0)
		{
			UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
			return retVal;
		}

		return 0;
	}

	int
	HistoryEventHandler::fini (void)
	{
		return EventHandler::fini();
	}


	int
	HistoryEventHandler::handle_event (MessageBlockPtr mbPtr )
	{	
		GMS_AlertIndication *pGMS_AlertIndication = nullptr;
		std::wstring str;
		std::wstringstream out;
		int type=mbPtr->msg_type();
		switch (type) {
			case MB_PUBLISH_EVENT:			
				pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
				if (pGMS_AlertIndication != nullptr)
				{
					out << pGMS_AlertIndication->category << ":" << pGMS_AlertIndication->id;
					out >> str;

					return setEventHistory(str, IMSSHistoryStorage_);
				}
				else
				{
					ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("HistoryEventHandler::Invalid data block.\n")), -1);
				}
				break;
			default:
			  ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT ("HistoryEventHandler::Invalid Message.\n")), -1);
			 }
		return 0;
	}
	
	int HistoryEventHandler::setEventHistory(std::wstring &newEvent, DATA_NAME storageName)
	{
		FuncEntryExit<void> fee(this, L"setEventHistory");
		
		std::wstring eventList = L"";
		std::wstring value;
		if (DSinstance().GetDataValue(storageName, value))
		{
			eventList = value;
		}
		int elementNum = 0;
		size_t index = 0;
		while ((index = eventList.find(L'|', index)) != std::wstring::npos)
		{
			++index;
			++elementNum;
		}
		if (elementNum >= 99)
		{
			std::wstring::iterator iter = eventList.begin();
			do 
			{ 
				iter = eventList.erase(iter);
			}
			while (*iter != '|');
			eventList.erase(iter);		
		}
		std::wstring newEventStr;
		newEventStr = L"|" + newEvent;
	
		time_t t;
		if (time (&t) == -1)
		{
			UNS_ERROR(L"time failed\n");
			return -1;
		}
		std::wstringstream ss;
		ss << t;
		std::wstring timeStr = L"";
		ss >> timeStr;
		newEventStr+= L":" + timeStr;

		eventList.append(newEventStr);
		if (!DSinstance().SetDataValue(storageName, eventList))
		{
			UNS_ERROR(L"SetDataValue failed\n");
			return -1;
		}
		
		return 1;
	}

	

	const ACE_TString
	HistoryEventHandler::name()
	{
		return HISTORY_EVENT_HANDLER;
	}

	LMS_SUBSERVICE_DEFINE (HISTORYEVENTHANDLER, HistoryEventHandler)


