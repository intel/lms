/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#include "UNSEventsDefinition.h"
#include "TimeSyncEventFilter.h"

bool 
TimeSyncEventFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	UNS_DEBUG(L"TimeSyncEventFilter::toSubscribe", L"\n");

	switch (alert->category)
	{
		case CATEGORY_UNS:
			{
				switch (alert->id)
				{
					case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
						return true;
						break;
					default:
						break;
				}
			}
		break;
		default:
			break;
	}

	return false;
}

