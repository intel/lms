# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2026 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_subdirectory ("${TOP_DIR}/CIM_Framework" "CIM_Framework")

add_library (WsmanClient STATIC
  AMTConfigurationWSManClient.cpp
  AMTEthernetPortSettingsClient.cpp
  AMTFCFHWSmanClient.cpp
  AMTRedirectionServiceWSManClient.cpp
  AuditLogWSManClient.cpp
  BaseWSManClient.cpp
  BootCapabilitiesWSManClient.cpp
  CancelOptInClient.cpp
  EnvironmentDetectionWSManClient.cpp
  EthernetSettingsWSManClient.cpp
  GeneralSettingsWSManClient.cpp
  HBPWSManClient.cpp
  HostBootReasonClient.cpp
  HTTPProxyAccessPointWSManClient.cpp
  IPSIderSessionUsingPortClient.cpp
  IPSKVMSessionUsingPortClient.cpp
  IPSSOLSessionUsingPortClient.cpp
  KVMScreenSettingClient.cpp
  KVMWSManClient.cpp
  ManagementPresenceRemoteSAPWSManClient.cpp
  OptInConfigWSManClient.cpp
  PowerManagementCapabilitiesWsManClient.cpp
  RemoteAccessPolicyRuleWSManClient.cpp
  SIOWSManClient.cpp
  SyncIpClient.cpp
  TimeSyncConfigWSManClient.cpp
  TimeSynchronizationClient.cpp
  WiFiEndpointStateWSManClient.cpp
  WifiEndpointCapabilitiesClient.cpp
  WiFiPortConfigWSManClient.cpp
  WiFiPortWSManClient.cpp
  WiFiProfilesWSManClient.cpp
  WifiPortClient.cpp
  WlanWSManClient.cpp
)

target_link_libraries (WsmanClient
  ACE::ACE
  CPPCIMFramework
  CPPCimFrameworkUntyped
  MEIClient
  CimOpenWsmanClient
)

target_include_directories (WsmanClient PUBLIC
  "./"
)

if (BUILD_TESTS)
  add_subdirectory ("WsmanClientTest" "WsmanClientTest")
endif (BUILD_TESTS)
