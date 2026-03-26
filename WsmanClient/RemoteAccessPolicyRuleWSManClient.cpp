/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: RemoteAccessPolicyRuleWSManClient.cpp

--*/

#include "RemoteAccessPolicyRuleWSManClient.h"
#include "AMT_RemoteAccessPolicyRule.h"
#include <memory>
#include <vector>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

RemoteAccessPolicyRuleWSManClient::RemoteAccessPolicyRuleWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

RemoteAccessPolicyRuleWSManClient::~RemoteAccessPolicyRuleWSManClient()
{
}

bool RemoteAccessPolicyRuleWSManClient::GetRemoteAccessPolicyRules(std::vector<RemoteAccessPolicyRuleWSMan>& rules)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_RemoteAccessPolicyRule>> instances =
			Intel::Manageability::Cim::Typed::AMT_RemoteAccessPolicyRule::Enumerate(m_client.get());
		for (const auto& inst : instances)
		{
			RemoteAccessPolicyRuleWSMan rule;
			rule.PolicyRuleName = inst->PolicyRuleName();
			if (inst->TriggerExists())
				rule.Trigger = inst->Trigger();
			if (inst->TunnelLifeTimeExists())
				rule.TunnelLifeTime = inst->TunnelLifeTime();
			if (inst->ExtendedDataExists())
			{
				const Intel::Manageability::Cim::Utils::Base64& b64 = inst->ExtendedData();
				const unsigned char* data = b64.Data();
				const unsigned int len = b64.Length();
				if (data != nullptr && len > 0)
					rule.ExtendedData.assign(data, data + len);
			}
			rules.push_back(std::move(rule));
		}
	}
	CATCH_exception_return("RemoteAccessPolicyRuleWSManClient::GetRemoteAccessPolicyRules")

	return true;
}
