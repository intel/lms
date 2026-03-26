/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: HTTPProxyAccessPointWSManClient.cpp

--*/

// Implements WS-Man enumeration flow for Intel AMT HTTP proxy access point data.

#include "HTTPProxyAccessPointWSManClient.h"
#include "IPS_HTTPProxyAccessPoint.h"
#include <memory>
#include <vector>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

HTTPProxyAccessPointWSManClient::HTTPProxyAccessPointWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

HTTPProxyAccessPointWSManClient::~HTTPProxyAccessPointWSManClient()
{
}

bool HTTPProxyAccessPointWSManClient::GetHTTPProxyAccessPoints(std::vector<HTTPProxyAccessPointWSMan>& proxies)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::IPS_HTTPProxyAccessPoint>> instances =
			Intel::Manageability::Cim::Typed::IPS_HTTPProxyAccessPoint::Enumerate(m_client.get());
		for (const auto& inst : instances)
		{
			HTTPProxyAccessPointWSMan proxy;
			if (inst->AccessInfoExists())
				proxy.AccessInfo = inst->AccessInfo();
			if (inst->InfoFormatExists())
				proxy.InfoFormat = inst->InfoFormat();
			if (inst->PortExists())
				proxy.Port = inst->Port();
			if (inst->NetworkDnsSuffixExists())
				proxy.NetworkDnsSuffix = inst->NetworkDnsSuffix();
			if (inst->PriorityExists())
				proxy.Priority = inst->Priority();
			proxies.push_back(std::move(proxy));
		}
	}
	CATCH_exception_return("HTTPProxyAccessPointWSManClient::GetHTTPProxyAccessPoints")

	return true;
}
