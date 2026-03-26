/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: EnvironmentDetectionWSManClient.cpp

--*/

// Implements retrieval of AMT environment-detection settings via WS-Man.

#include <memory>
#include "EnvironmentDetectionWSManClient.h"
#include "AMT_EnvironmentDetectionSettingData.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

EnvironmentDetectionWSManClient::EnvironmentDetectionWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

EnvironmentDetectionWSManClient::~EnvironmentDetectionWSManClient()
{
}

bool EnvironmentDetectionWSManClient::GetEnvironmentDetection(EnvironmentDetectionWSMan& detection)
{
	try
	{
		// Read the first available environment detection instance.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EnvironmentDetectionSettingData>> results =
			Intel::Manageability::Cim::Typed::AMT_EnvironmentDetectionSettingData::Enumerate(m_client.get());
		if (results.empty())
			return false;

		auto& ed = *results[0];
		if (ed.DetectionAlgorithmExists()) detection.DetectionAlgorithm = ed.DetectionAlgorithm();
		if (ed.DetectionStringsExists()) detection.DetectionStrings = ed.DetectionStrings();
		if (ed.DetectionIPv6LocalPrefixesExists()) detection.DetectionIPv6LocalPrefixes = ed.DetectionIPv6LocalPrefixes();
	}
	CATCH_exception_return("EnvironmentDetectionWSManClient::GetEnvironmentDetection")

	return true;
}
