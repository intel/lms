/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
#ifndef __HISTORYEVENTHANDLER_H_
#define __HISTORYEVENTHANDLER_H_
#include "EventHandler.h"
#include "HISTORYEVENTHANDLER_export.h"
#include "IMSSFilter.h"
enum DATA_NAME : unsigned int;

	class HISTORYEVENTHANDLER_Export HistoryEventHandler : public EventHandler
	{
	  public:
					
		 HistoryEventHandler();

		virtual int init (int argc, ACE_TCHAR *argv[]);

		virtual int fini (void);

		virtual const wchar_t *short_name() const { return L"HEVH"; }

	protected:

		virtual int handle_event (MessageBlockPtr mbPtr);
		
		virtual const ACE_TString name();
		
		virtual std::shared_ptr<EventsFilter> getFilter()
		{
			return filter_;
		}

	  private:

		int setEventHistory(std::wstring &newEvent,DATA_NAME storageName);
		
		std::shared_ptr<IMSSFilter> filter_;
		DATA_NAME IMSSHistoryStorage_;
	};

#endif /* __HISTORYEVENTHANDLER_H_ */