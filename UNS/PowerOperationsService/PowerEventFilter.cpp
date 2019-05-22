/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#include "UNSEventsDefinition.h"
#include "PowerEventFilter.h"

bool 
PowerEventFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	switch (alert->category)
	{
		case CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION:
			{
				switch (alert->id)
				{
					case EVENT_REMOTE_GRACEFUL_SHUTDOWN_REQUESTED:
					case EVENT_REMOTE_GRACEFUL_REBOOT_REQUESTED:
					case EVENT_REMOTE_SLEEP: 
					case EVENT_REMOTE_HIBERNATE:
						return true;
						break;
					default:
						break;
				}
			}
		break;

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

