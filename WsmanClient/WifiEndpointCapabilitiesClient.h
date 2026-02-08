/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2025 Intel Corporation
 */
/*++

@file: WifiEndpointCapabilitiesClient.h

--*/

#ifndef  _WIFI_ENDPOINT_CAPABILITIES_CLIENT_H
#define  _WIFI_ENDPOINT_CAPABILITIES_CLIENT_H

#include "BaseWSManClient.h"

class WifiEndpointCapabilitiesClient : public BaseWSManClient
{
public:
	WifiEndpointCapabilitiesClient(unsigned int port);
	virtual ~WifiEndpointCapabilitiesClient();

	bool isTransitionModeSupported(bool &supported);
};

#endif //_WIFI_ENDPOINT_CAPABILITIES_CLIENT_H
