/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
 */
#include "UNSEventsDefinition.h"
#include "WiFiProfileSyncEventFilter.h"

bool WiFiProfileSyncEventFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": alert->category %d, alert->id %d\n", alert->category, alert->id);
	switch (alert->category)
	{
		case CATEGORY_UNS:
		{
			switch (alert->id)
			{
				case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n");
					return true;
				}
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

