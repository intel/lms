/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: HTTPProxyAccessPointWSManClient.h

--*/

// WS-Man client interface for querying Intel AMT HTTP proxy access point instances.

#ifndef _HTTP_PROXY_ACCESS_POINT_WSMAN_CLIENT_H
#define _HTTP_PROXY_ACCESS_POINT_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>
#include <vector>

struct HTTPProxyAccessPointWSMan
{
	std::string AccessInfo;
	uint16_t InfoFormat = 0;
	uint16_t Port = 0;
	std::string NetworkDnsSuffix;
	uint32_t Priority = 0;
};

class HTTPProxyAccessPointWSManClient : public BaseWSManClient
{
public:
	HTTPProxyAccessPointWSManClient(unsigned int port);
	virtual ~HTTPProxyAccessPointWSManClient();
	bool GetHTTPProxyAccessPoints(std::vector<HTTPProxyAccessPointWSMan>& proxies);
private:
};

#endif //_HTTP_PROXY_ACCESS_POINT_WSMAN_CLIENT_H
