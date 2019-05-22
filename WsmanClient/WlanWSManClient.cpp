/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#include <locale>
#include <codecvt>
#include <string>
#include "UNSDebug.h"
#include "WsmanClientCatch.h"
#include "AMT_WiFiPortConfigurationService.h"
#include "CIM_WiFiEndpoint.h"
#include "WlanWSManClient.h"

const std::string WlanWSManClient::DEFAULT_USER = "$$uns";
const std::string WlanWSManClient::DEFAULT_PASS = "$$uns";
const std::string InstanceIDUser = "Intel(r) AMT:WiFi Endpoint User Settings ";

typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings CIM_WiFiEndpointSettings;
typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpoint CIM_WiFiEndpoint;
typedef Intel::Manageability::Cim::Typed::AMT_WiFiPortConfigurationService AMT_WiFiPortConfigurationService;

WlanWSManClient::WlanWSManClient(void): BaseWSManClient(DEFAULT_USER, DEFAULT_PASS), m_isInit(false)
{
}

WlanWSManClient::~WlanWSManClient(void)
{
}

bool WlanWSManClient::Init(void)
{
	DbgPrint("WlanWSManClient::Init\n");

	if (m_isInit)
	{
		return true;
	}

	try
	{
		if (!m_endpoint)
		{
			SetEndpoint(false);
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
			DbgPrint("LocalProfileSynchronizationEnabled - Init return false !\n");
			return false;
		}

		std::lock_guard<std::mutex> lock(WsManSemaphore());
		Intel::Manageability::Cim::Typed::AMT_WiFiPortConfigurationService svc(m_client.get());
		svc.Get();

		unsigned int data = svc.localProfileSynchronizationEnabled();
		DbgPrint("WlanWSManClient::LocalProfileSynchronizationEnabled data %d\n", data);

		enabled = data == 1 || data == 3;
	}
	CATCH_exception_return("WlanWSManClient::LocalProfileSynchronizationEnabled")

		return true;
}

bool WlanWSManClient::Enumerate(MeProfileList &wifiSettings)
{
	DbgPrint("WlanWSManClient::Enumerate\n");

	if (!Init())
	{
		DbgPrint("Enumerate - Init return false !\n");
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
	DbgPrint("DeleteProfile\n");

	if (!Init())
	{
		DbgPrint("DeleteProfile - Init return false !\n");
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
bool WlanWSManClient::AddProfile(SingleMeProfile& wifiSettings)
{
	unsigned int retVal;

	DbgPrint("WlanWSManClient::AddProfile\n");

	if (!Init())
	{
		DbgPrint("AddProfile Init return false !\n");
		return false;
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
		CATCH_exception_return("WlanWSManClient::AddProfile wifiEndpoint")

		// InstanceID
		wifiSettings.InstanceID(InstanceIDUser + wifiSettings.ElementName());

		DbgPrint("WlanWSManClient::AddProfile Calling AddWiFiSettings...\n");
		AMT_WiFiPortConfigurationService::AddWiFiSettings_INPUT input;
		AMT_WiFiPortConfigurationService::AddWiFiSettings_OUTPUT output;

		input.WiFiEndpoint(wifiEndpoint.Reference());
		input.WiFiEndpointSettingsInput(wifiSettings);
		retVal = svc.AddWiFiSettings(input, output);

		DbgPrint("WlanWSManClient::AddProfile AddWiFiSettings retVal %d\n", retVal);
	}
	CATCH_exception_return("WlanWSManClient::AddProfile AddWiFiSettings")

	return true;
}

// Update Single Profile
bool WlanWSManClient::UpdateProfile(SingleMeProfile& wifiSettings)
{
	unsigned int retVal;

	if (!Init())
	{
		DbgPrint("UpdateProfile - Init return false !\n");
		return false;
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
		CATCH_exception_return("WlanWSManClient::UpdateProfile wifiEndpoint")

		// InstanceID
		wifiSettings.InstanceID(InstanceIDUser + wifiSettings.ElementName());

		DbgPrint("WlanWSManClient::UpdateProfile Calling UpdateWiFiSettings...\n");
		AMT_WiFiPortConfigurationService::UpdateWiFiSettings_INPUT input;
		AMT_WiFiPortConfigurationService::UpdateWiFiSettings_OUTPUT output;
		input.WiFiEndpointSettings(wifiSettings.Reference());
		input.WiFiEndpointSettingsInput(wifiSettings);
		retVal = svc.UpdateWiFiSettings(input, output);

		DbgPrint("WlanWSManClient::UpdateProfile UpdateWiFiSettings retVal %d\n", retVal);

	}
	CATCH_exception_return("WlanWSManClient::UpdateProfile UpdateWiFiSettings")

	return true;
}
