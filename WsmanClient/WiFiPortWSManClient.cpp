/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPortWSManClient.cpp

--*/

#include "WiFiPortWSManClient.h"
#include "CIM_WiFiPort.h"
#include <memory>
#include <vector>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

WiFiPortWSManClient::WiFiPortWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

WiFiPortWSManClient::~WiFiPortWSManClient()
{
}

bool WiFiPortWSManClient::GetWiFiPorts(std::vector<WiFiPortWSMan>& ports)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::CIM_WiFiPort>> instances =
			Intel::Manageability::Cim::Typed::CIM_WiFiPort::Enumerate(m_client.get());
		for (const auto& inst : instances)
		{
			WiFiPortWSMan port;
			if (inst->EnabledStateExists())
				port.EnabledState = inst->EnabledState();
			if (inst->PermanentAddressExists())
				port.PermanentAddress = inst->PermanentAddress();
			ports.push_back(std::move(port));
		}
	}
	CATCH_exception_return("WiFiPortWSManClient::GetWiFiPorts")

	return true;
}
