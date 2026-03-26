/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: ManagementPresenceRemoteSAPWSManClient.cpp

--*/

#include "ManagementPresenceRemoteSAPWSManClient.h"
#include "AMT_ManagementPresenceRemoteSAP.h"
#include <memory>
#include <vector>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

ManagementPresenceRemoteSAPWSManClient::ManagementPresenceRemoteSAPWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

ManagementPresenceRemoteSAPWSManClient::~ManagementPresenceRemoteSAPWSManClient()
{
}

bool ManagementPresenceRemoteSAPWSManClient::GetManagementPresenceRemoteSAP(ManagementPresenceSAPWSMan& sap)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_ManagementPresenceRemoteSAP>> instances =
			Intel::Manageability::Cim::Typed::AMT_ManagementPresenceRemoteSAP::Enumerate(m_client.get());
		if (instances.empty())
			return true;
		const auto& inst = instances[0];
		if (inst->InfoFormatExists())
			sap.InfoFormat = inst->InfoFormat();
		if (inst->AccessInfoExists())
			sap.AccessInfo = inst->AccessInfo();
		if (inst->PortExists())
			sap.Port = inst->Port();
		if (inst->CNExists())
			sap.CN = inst->CN();
	}
	CATCH_exception_return("ManagementPresenceRemoteSAPWSManClient::GetManagementPresenceRemoteSAP")

	return true;
}
