/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: EnvironmentDetectionWSManClient.h

--*/

// WS-Man client for reading AMT environment detection configuration.

#ifndef _ENVIRONMENT_DETECTION_WSMAN_CLIENT_H
#define _ENVIRONMENT_DETECTION_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>
#include <vector>

struct EnvironmentDetectionWSMan
{
	unsigned short DetectionAlgorithm = 0;
	std::vector<std::string> DetectionStrings;
	std::vector<std::string> DetectionIPv6LocalPrefixes;
};

class EnvironmentDetectionWSManClient : public BaseWSManClient
{
public:
	EnvironmentDetectionWSManClient(unsigned int port);
	virtual ~EnvironmentDetectionWSManClient();
	// Retrieves configured environment detection rules and prefixes.
	bool GetEnvironmentDetection(EnvironmentDetectionWSMan& detection);
private:
};

#endif //_ENVIRONMENT_DETECTION_WSMAN_CLIENT_H
