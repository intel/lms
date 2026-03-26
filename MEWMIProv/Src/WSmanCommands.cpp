/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2026 Intel Corporation
 */
/*++

@file: WSmanCommands.cpp

--*/

#include "stdafx.h"
#include "WSmanCommands.h"
#include "SIOWSManClient.h"
#include "KVMWSManClient.h"
#include "AMTRedirectionServiceWSManClient.h"
#include "EthernetSettingsWSManClient.h"
#include "StringManipulator.h"
#include "MNGIsChangeToAMTEnabledCommand.h"
#include "DebugPrints.h"

WSmanCommands::WSmanCommands()
{
	Intel::MEI_Client::Manageability_Client::MNGIsChangeToAMTEnabledCommand cmd;
	Intel::MEI_Client::Manageability_Client::IsChangedEnabledResponse res = cmd.getResponse();
	m_port = (res.TlsOnLocalPorts) ? AMT_SECURE_PORT : AMT_NON_SECURE_PORT;
}

UINT32 WSmanCommands::setSpriteZoom(short zoom)
{
	try
	{
		SIOWSManClient sio(m_port);
		if (sio.SetSpriteZoom(zoom) != true)
			return 1;
		else
			return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in SetSpriteZoom %C\n", exc.what());
		return 1;
	}
}

UINT32 WSmanCommands::TerminateKVMSession(void)
{
	try
	{
		KVMWSManClient kvm(m_port);

		if (kvm.TerminateKVMSession() != true)
			return 1;

		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in TerminateKVMSession %C\n", exc.what());
		return 1;
	}
}

UINT32 WSmanCommands::isIDEREnabled(bool *enabled)
{
	try
	{
		AMTRedirectionServiceWSManClient redirectionClient(m_port);
		unsigned short state;
		*enabled = false;

		if (redirectionClient.RedirectionState(&state) != true)
			return 1;

		switch (state)
		{
		case IDER_SOL_ENABLED:
			*enabled = true;
			break;
		case IDER_ENABLED_SOL_DISABLED:
			*enabled = true;
			break;
		case IDER_DISABLED_SOL_ENABLED:
			*enabled = false;
			break;
		case IDER_SOL_DISABLED:
			*enabled = false;
			break;
		default:
			return 1;
		}
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in RedirectionState %C\n", exc.what());
		return 1;
	}
}

UINT32 WSmanCommands::isSOLEnabled(bool *enabled)
{
	try
	{
		AMTRedirectionServiceWSManClient redirectionClient(m_port);
		unsigned short state;
		*enabled = false;

		if (redirectionClient.RedirectionState(&state) != true)
			return 1;

		switch (state)
		{
		case IDER_SOL_ENABLED:
			*enabled = true;
			break;
		case IDER_ENABLED_SOL_DISABLED:
			*enabled = false;
			break;
		case IDER_DISABLED_SOL_ENABLED:
			*enabled = true;
			break;
		case IDER_SOL_DISABLED:
			*enabled = false;
			break;
		default:
			return 1;
		}
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in RedirectionState %C\n", exc.what());
		return 1;
	}
}

UINT32 WSmanCommands::isKVMActive(bool* enabled, bool* active)
{
	try
	{
		KVMWSManClient kvm(m_port);
		unsigned short state;
		*enabled = false;

		if (kvm.KVMRedirectionState(&state) != true)
			return 1;

		switch (state)
		{
		case 2:
			*enabled = true;
			*active = true;
			break;
		case 3:
			*enabled = false;
			*active = false;
			break;
		case 6:
			*enabled = true;
			*active = false;
			break;
		default:
			return 1;
		}
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in RedirectionState %C\n", exc.what());
		return 1;
	}
}

UINT32 WSmanCommands::GetPortSettings(std::vector<EthernetPortEntryWSMan> &ethernetPortList)
{
	try
	{
		EthernetSettingsWSManClient client(m_port);
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> ethernetSettings;
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>>::iterator settingsIterator;

		if (!client.Enumerate(ethernetSettings))
			return ERR_UKNOWN_CONNECTION_ERROR;

		for (settingsIterator = ethernetSettings.begin();
			settingsIterator != ethernetSettings.end();
			settingsIterator++)
		{
			EthernetPortEntryWSMan entry;

			if(settingsIterator->get()->DefaultGatewayExists())
				entry.DefaultGateway = ToWStr(settingsIterator->get()->DefaultGateway());
			if (settingsIterator->get()->DHCPEnabledExists())
				entry.DHCPEnabled = settingsIterator->get()->DHCPEnabled();
			if (settingsIterator->get()->IPAddressExists())
				entry.IPAddress = ToWStr(settingsIterator->get()->IPAddress());
			if (settingsIterator->get()->LinkIsUpExists())
				entry.LinkIsUp = settingsIterator->get()->LinkIsUp();
			if (settingsIterator->get()->MACAddressExists())
				entry.MACAddress = ToWStr(settingsIterator->get()->MACAddress());
			if (settingsIterator->get()->PrimaryDNSExists())
				entry.PrimaryDNS = ToWStr(settingsIterator->get()->PrimaryDNS());
			if (settingsIterator->get()->SecondaryDNSExists())
				entry.SecondaryDNS = ToWStr(settingsIterator->get()->SecondaryDNS());
			if (settingsIterator->get()->SubnetMaskExists())
				entry.SubnetMask = ToWStr(settingsIterator->get()->SubnetMask());
			if (settingsIterator->get()->LinkPolicyExists())
				entry.LinkPolicy = settingsIterator->get()->LinkPolicy();
			if (settingsIterator->get()->LinkPreferenceExists())
				entry.LinkPreference = settingsIterator->get()->LinkPreference();
			if (settingsIterator->get()->LinkControlExists())
				entry.LinkControl = settingsIterator->get()->LinkControl();
			if (settingsIterator->get()->SharedStaticIpExists())
				entry.SharedStaticIp = settingsIterator->get()->SharedStaticIp();
			if (settingsIterator->get()->IpSyncEnabledExists())
				entry.IpSyncEnabled = settingsIterator->get()->IpSyncEnabled();
			if (settingsIterator->get()->ConsoleTcpMaxRetransmissionsExists())
				entry.ConsoleTcpMaxRetransmissions = settingsIterator->get()->ConsoleTcpMaxRetransmissions();
			if (settingsIterator->get()->WLANLinkProtectionLevelExists())
				entry.WLANLinkProtectionLevel = settingsIterator->get()->WLANLinkProtectionLevel();
			if (settingsIterator->get()->PhysicalConnectionTypeExists())
				entry.PhysicalConnectionType = settingsIterator->get()->PhysicalConnectionType();
			if (settingsIterator->get()->PhysicalNicMediumExists())
				entry.PhysicalNicMedium = settingsIterator->get()->PhysicalNicMedium();
			ethernetPortList.push_back(std::move(entry));
		}

		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in EthernetSettingsWSManClient %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetBootCapabilities(BootCapabilitiesWSMan& caps)
{
	try
	{
		BootCapabilitiesWSManClient client(m_port);
		if (!client.GetBootCapabilities(caps))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetBootCapabilities %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetGeneralSettings(GeneralSettingsWSMan& settings)
{
	try
	{
		GeneralSettingsWSManClient client(m_port);
		if (!client.GetGeneralSettings(settings))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetGeneralSettings %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetEnvironmentDetection(EnvironmentDetectionWSMan& detection)
{
	try
	{
		EnvironmentDetectionWSManClient client(m_port);
		if (!client.GetEnvironmentDetection(detection))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetEnvironmentDetection %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetAMTConfiguration(AMTConfigurationWSMan& config)
{
	try
	{
		AMTConfigurationWSManClient client(m_port);
		if (!client.GetAMTConfiguration(config))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetAMTConfiguration %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetWiFiPortConfiguration(WiFiPortConfigWSMan& wifiConfig)
{
	try
	{
		WiFiPortConfigWSManClient client(m_port);
		if (!client.GetWiFiPortConfiguration(wifiConfig))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetWiFiPortConfiguration %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetWiFiEndpointState(WiFiEndpointStateWSMan& wifiState)
{
	try
	{
		WiFiEndpointStateWSManClient client(m_port);
		if (!client.GetWiFiEndpointState(wifiState))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetWiFiEndpointState %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetTimeSyncConfig(TimeSyncConfigWSMan& timeConfig)
{
	try
	{
		TimeSyncConfigWSManClient client(m_port);
		if (!client.GetTimeSyncConfig(timeConfig))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetTimeSyncConfig %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetOptInConfig(OptInConfigWSMan& optInConfig)
{
	try
	{
		OptInConfigWSManClient client(m_port);
		if (!client.GetOptInConfig(optInConfig))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetOptInConfig %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetAuditLogRecords(std::vector<BinaryData>& records)
{
	try
	{
		AuditLogWSManClient client(m_port);
		if (!client.GetAuditLogRecords(records))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetAuditLogRecords %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetRemoteAccessPolicyRules(std::vector<RemoteAccessPolicyRuleWSMan>& rules)
{
	try
	{
		RemoteAccessPolicyRuleWSManClient client(m_port);
		if (!client.GetRemoteAccessPolicyRules(rules))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetRemoteAccessPolicyRules %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetWiFiProfiles(std::vector<WiFiProfileWSMan>& profiles)
{
	try
	{
		WiFiProfilesWSManClient client(m_port);
		if (!client.GetWiFiProfiles(profiles))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetWiFiProfiles %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetHTTPProxyAccessPoints(std::vector<HTTPProxyAccessPointWSMan>& proxies)
{
	try
	{
		HTTPProxyAccessPointWSManClient client(m_port);
		if (!client.GetHTTPProxyAccessPoints(proxies))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetHTTPProxyAccessPoints %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetWiFiPorts(std::vector<WiFiPortWSMan>& ports)
{
	try
	{
		WiFiPortWSManClient client(m_port);
		if (!client.GetWiFiPorts(ports))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetWiFiPorts %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}

UINT32 WSmanCommands::GetManagementPresenceRemoteSAP(ManagementPresenceSAPWSMan& sap)
{
	try
	{
		ManagementPresenceRemoteSAPWSManClient client(m_port);
		if (!client.GetManagementPresenceRemoteSAP(sap))
			return ERR_UKNOWN_CONNECTION_ERROR;
		return 0;
	}
	catch (const std::exception& exc)
	{
		UNS_DEBUG("Exception in GetManagementPresenceRemoteSAP %C\n", exc.what());
		return ERR_UKNOWN_CONNECTION_ERROR;
	}
}
