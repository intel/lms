/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
#include <locale>
#include <codecvt>
#include <string>

#include "AMT_WiFiPortConfigurationService.h"
#include "CIM_WiFiEndpoint.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"
#include "WlanWSManClient.h"

const std::string InstanceIDUser = "Intel(r) AMT:WiFi Endpoint User Settings ";

typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings CIM_WiFiEndpointSettings;
typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpoint CIM_WiFiEndpoint;
typedef Intel::Manageability::Cim::Typed::AMT_WiFiPortConfigurationService AMT_WiFiPortConfigurationService;

WlanWSManClient::WlanWSManClient(unsigned int port): BaseWSManClient(port), m_isInit(false)
{
}

WlanWSManClient::~WlanWSManClient(void)
{
}

bool WlanWSManClient::Init(void)
{
	WSMAN_DEBUG("WlanWSManClient::Init\n");

	if (m_isInit)
	{
		return true;
	}

	try
	{
		if (!m_endpoint)
		{
			SetEndpoint();
		}

		m_isInit = true;
	}
	CATCH_exception("WlanWSManClient::Init")

	return m_isInit;
}

bool WlanWSManClient::LocalProfileSynchronizationEnabled(bool &enabled)
{
	try
	{
		if (!Init())
		{
			WSMAN_ERROR("LocalProfileSynchronizationEnabled - Init return false!\n");
			return false;
		}

		std::lock_guard<std::mutex> lock(WsManSemaphore());
		Intel::Manageability::Cim::Typed::AMT_WiFiPortConfigurationService svc(m_client.get());
		svc.Get();

		unsigned int data = svc.localProfileSynchronizationEnabled();
		WSMAN_DEBUG("WlanWSManClient::LocalProfileSynchronizationEnabled data %u\n", data);

		enabled = data == 1 || data == 3;
	}
	CATCH_exception_return("WlanWSManClient::LocalProfileSynchronizationEnabled")

	return true;
}

bool WlanWSManClient::Enumerate(MeProfileList &wifiSettings)
{
	WSMAN_DEBUG("WlanWSManClient::Enumerate\n");

	if (!Init())
	{
		WSMAN_ERROR("Enumerate - Init return false!\n");
		return false;
	}

	try
	{
		// Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		wifiSettings = CIM_WiFiEndpointSettings::Enumerate(m_client.get());
	}
	CATCH_exception_return("WlanWSManClient::Enumerate") // In case of exception, return false
		
	return true;
}

bool WlanWSManClient::DeleteProfile(SingleMeProfile& wifiSettings)
{
	WSMAN_DEBUG("DeleteProfile\n");

	if (!Init())
	{
		WSMAN_ERROR("DeleteProfile - Init return false!\n");
		return false;
	}

	// Delete the Profile
	try
	{
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		wifiSettings.Delete();
	}
	CATCH_exception_return("WlanWSManClient::DeleteProfile") // In case of exception, return false

	return true;
}

// Add Single Profile to ME
unsigned int WlanWSManClient::AddProfile(SingleMeProfile& wifiSettings)
{
	unsigned int ret = WSMAN_AMT_INTERNAL_ERROR;

	WSMAN_DEBUG("WlanWSManClient::AddProfile\n");

	if (!Init())
	{
		WSMAN_ERROR("AddProfile Init return false!\n");
		return ret;
	}

	try
	{
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		AMT_WiFiPortConfigurationService svc(m_client.get());
		CIM_WiFiEndpoint wifiEndpoint;
		try
		{
			wifiEndpoint.WsmanClient(m_client.get());
			wifiEndpoint.Get();
		}
		CATCH_exception_return_AMT_code("WlanWSManClient::AddProfile wifiEndpoint")

		// InstanceID
		wifiSettings.InstanceID(InstanceIDUser + wifiSettings.ElementName());

		WSMAN_DEBUG("WlanWSManClient::AddProfile Calling AddWiFiSettings...\n");
		AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT input;
		AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT output;

		input.WiFiEndpoint(wifiEndpoint.Reference());
		input.WiFiEndpointSettingsInput(wifiSettings);
		ret = svc.AddWiFiSettings(input, output);

		WSMAN_DEBUG("WlanWSManClient::AddProfile AddWiFiSettings ret = %u\n", ret);
	}
	CATCH_exception_return_AMT_code("WlanWSManClient::AddProfile AddWiFiSettings")

	return ret;
}

// Update Single Profile
unsigned int WlanWSManClient::UpdateProfile(SingleMeProfile& wifiSettings)
{
	unsigned int ret = WSMAN_AMT_INTERNAL_ERROR;

	if (!Init())
	{
		WSMAN_ERROR("UpdateProfile - Init return false!\n");
		return ret;
	}

	try
	{
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		AMT_WiFiPortConfigurationService svc(m_client.get());

		CIM_WiFiEndpoint wifiEndpoint;
		try
		{
			wifiEndpoint.WsmanClient(m_client.get());
			wifiEndpoint.Get();
		}
		CATCH_exception_return_AMT_code("WlanWSManClient::UpdateProfile wifiEndpoint")

		// InstanceID
		wifiSettings.InstanceID(InstanceIDUser + wifiSettings.ElementName());

		WSMAN_DEBUG("WlanWSManClient::UpdateProfile Calling UpdateWiFiSettings...\n");
		AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT input;
		AMT_WiFiPortConfigurationService::UpdateWiFiSettings_OUTPUT output;
		input.WiFiEndpointSettings(wifiSettings.Reference());
		input.WiFiEndpointSettingsInput(wifiSettings);
		ret = svc.UpdateWiFiSettings(input, output);

		WSMAN_DEBUG("WlanWSManClient::UpdateProfile UpdateWiFiSettings retVal %u\n", ret);

	}
	CATCH_exception_return_AMT_code("WlanWSManClient::UpdateProfile UpdateWiFiSettings")

	return ret;
}
