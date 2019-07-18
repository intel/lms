/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#include "UNSAlert_BE.h"
#include "DataStorageGenerator.h"
#include "global.h"

namespace Intel {
	namespace LMS {
		UNSAlert_BE::UNSAlert_BE(bool isPfwUp) :Common_BE(isPfwUp)
		{
		}

		LMS_ERROR GetEventHistoryFromStorage(std::wstring &bstrEventHistory, DATA_NAME storageName)
		{
			UNS_DEBUG(L"GetEventHistory %d\n", storageName);
			bstrEventHistory = L"";
			if (!DSinstance().GetDataValue(storageName, bstrEventHistory, true))
			{
				bstrEventHistory = L"";
			}
			return ERROR_OK;
		}

		LMS_ERROR UNSAlert_BE::GetIMSSEventHistory(std::wstring &bstrEventHistory)
		{
			return GetEventHistoryFromStorage(bstrEventHistory, IMSS_EVENT_HISTORY);
		}
	}
}