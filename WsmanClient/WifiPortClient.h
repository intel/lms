/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: WifiPortClient.h

--*/

#ifndef  _WIFI_PORT_CLIENT_H
#define  _WIFI_PORT_CLIENT_H

#include "BaseWSManClient.h"

class WifiPortClient : public BaseWSManClient
{
public:
	WifiPortClient(unsigned int port);
	virtual ~WifiPortClient();

	bool PortsNum(size_t &ports);
};

#endif //_WIFI_PORT_CLIENT_H
