/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2026 Intel Corporation
 */
/*++

@file: WSmanCommands.h

--*/

#ifndef WSMAN_COMMANDS_H
#define WSMAN_COMMANDS_H

#include "stdafx.h"
#include <string>
#include <vector>
#include "BootCapabilitiesWSManClient.h"
#include "GeneralSettingsWSManClient.h"
#include "EnvironmentDetectionWSManClient.h"
#include "AMTConfigurationWSManClient.h"
#include "OptInConfigWSManClient.h"
#include "TimeSyncConfigWSManClient.h"
#include "WiFiPortConfigWSManClient.h"
#include "WiFiEndpointStateWSManClient.h"
#include "AuditLogWSManClient.h"
#include "RemoteAccessPolicyRuleWSManClient.h"
#include "WiFiProfilesWSManClient.h"
#include "HTTPProxyAccessPointWSManClient.h"
#include "WiFiPortWSManClient.h"
#include "ManagementPresenceRemoteSAPWSManClient.h"

#define ERR_UKNOWN_CONNECTION_ERROR 1000
#define IDER_SOL_DISABLED 32768
#define IDER_ENABLED_SOL_DISABLED 32769
#define IDER_DISABLED_SOL_ENABLED 32770
#define IDER_SOL_ENABLED 32771

class EthernetPortEntryWSMan
{
public:
	EthernetPortEntryWSMan() : LinkIsUp(false), DHCPEnabled(false), LinkPreference(0), LinkControl(0), SharedStaticIp(false), IpSyncEnabled(false), ConsoleTcpMaxRetransmissions(0), WLANLinkProtectionLevel(0), PhysicalConnectionType(0), PhysicalNicMedium(0) {}
	std::wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	std::wstring IPAddress;
	std::wstring SubnetMask;
	std::wstring DefaultGateway;
	std::wstring PrimaryDNS;
	std::wstring SecondaryDNS;
	std::vector<uint8_t> LinkPolicy;
	uint32_t LinkPreference;
	uint32_t LinkControl;
	boolean SharedStaticIp;
	boolean IpSyncEnabled;
	uint32_t ConsoleTcpMaxRetransmissions;
	uint32_t WLANLinkProtectionLevel;
	uint32_t PhysicalConnectionType;
	uint32_t PhysicalNicMedium;
};

class WSmanCommands
{
public:
	WSmanCommands();

	UINT32 setSpriteZoom(short zoom);
	UINT32 TerminateKVMSession(void);
	UINT32 isKVMActive(bool* enabled, bool* active);
	UINT32 GetPortSettings(std::vector<EthernetPortEntryWSMan> &ethernetPortList);
	UINT32 isSOLEnabled(bool* enabled);
	UINT32 isIDEREnabled(bool* enabled);

	UINT32 GetBootCapabilities(BootCapabilitiesWSMan& caps);
	UINT32 GetGeneralSettings(GeneralSettingsWSMan& settings);
	UINT32 GetEnvironmentDetection(EnvironmentDetectionWSMan& detection);
	UINT32 GetAMTConfiguration(AMTConfigurationWSMan& config);
	UINT32 GetWiFiPortConfiguration(WiFiPortConfigWSMan& wifiConfig);
	UINT32 GetWiFiEndpointState(WiFiEndpointStateWSMan& wifiState);
	UINT32 GetTimeSyncConfig(TimeSyncConfigWSMan& timeConfig);
	UINT32 GetOptInConfig(OptInConfigWSMan& optInConfig);
	UINT32 GetAuditLogRecords(std::vector<BinaryData>& records);
	UINT32 GetRemoteAccessPolicyRules(std::vector<RemoteAccessPolicyRuleWSMan>& rules);
	UINT32 GetWiFiProfiles(std::vector<WiFiProfileWSMan>& profiles);
	UINT32 GetHTTPProxyAccessPoints(std::vector<HTTPProxyAccessPointWSMan>& proxies);
	UINT32 GetWiFiPorts(std::vector<WiFiPortWSMan>& ports);
	UINT32 GetManagementPresenceRemoteSAP(ManagementPresenceSAPWSMan& sap);

private:
	unsigned int m_port;
};
#endif // WSMAN_COMMANDS_H
