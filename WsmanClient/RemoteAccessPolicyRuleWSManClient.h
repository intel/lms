/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: RemoteAccessPolicyRuleWSManClient.h

--*/

// WS-Man client for AMT remote access policy rule enumeration.

#ifndef _REMOTE_ACCESS_POLICY_RULE_WSMAN_CLIENT_H
#define _REMOTE_ACCESS_POLICY_RULE_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>
#include <vector>

struct RemoteAccessPolicyRuleWSMan
{
	std::string PolicyRuleName;
	uint16_t Trigger = 0;
	uint32_t TunnelLifeTime = 0;
	std::vector<uint8_t> ExtendedData;
};

class RemoteAccessPolicyRuleWSManClient : public BaseWSManClient
{
public:
	RemoteAccessPolicyRuleWSManClient(unsigned int port);
	virtual ~RemoteAccessPolicyRuleWSManClient();
	bool GetRemoteAccessPolicyRules(std::vector<RemoteAccessPolicyRuleWSMan>& rules);
private:
};

#endif //_REMOTE_ACCESS_POLICY_RULE_WSMAN_CLIENT_H
