/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiProfilesWSManClient.cpp

--*/

// Implements enumeration of stored Wi-Fi profile settings in AMT firmware.

#include "WiFiProfilesWSManClient.h"
#include "CIM_WiFiEndpointSettings.h"
#include <memory>
#include <vector>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

WiFiProfilesWSManClient::WiFiProfilesWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

WiFiProfilesWSManClient::~WiFiProfilesWSManClient()
{
}

bool WiFiProfilesWSManClient::GetWiFiProfiles(std::vector<WiFiProfileWSMan>& profiles)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings>> instances =
			Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings::Enumerate(m_client.get());
		for (const auto& inst : instances)
		{
			WiFiProfileWSMan profile;
			if (inst->ElementNameExists())
				profile.ProfileName = inst->ElementName();
			if (inst->PriorityExists())
				profile.Priority = inst->Priority();
			if (inst->SSIDExists())
				profile.SSID = inst->SSID();
			if (inst->EncryptionMethodExists())
				profile.EncryptionMethod = inst->EncryptionMethod();
			if (inst->AuthenticationMethodExists())
				profile.AuthenticationMethod = inst->AuthenticationMethod();
			profiles.push_back(std::move(profile));
		}
	}
	CATCH_exception_return("WiFiProfilesWSManClient::GetWiFiProfiles")

	return true;
}
