/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "UNSEventsDefinition.h"
#include "SharedStaticIPEventFilter.h"

bool 
SharedStaticIPEventFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	UNS_DEBUG(L"SharedStaticIPEventFilter::toSubscribe\n");

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

