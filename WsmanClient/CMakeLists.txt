# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_subdirectory ("${TOP_DIR}/CIM_Framework" "CIM_Framework")

add_library (WsmanClient STATIC
  AMTEthernetPortSettingsClient.cpp
  AMTFCFHWSmanClient.cpp
  AMTRedirectionServiceWSManClient.cpp
  AuditLogWSManClient.cpp
  BaseWSManClient.cpp
  CancelOptInClient.cpp
  EthernetSettingsWSManClient.cpp
  HBPWSManClient.cpp
  HostBootReasonClient.cpp
  IPSIderSessionUsingPortClient.cpp
  IPSKVMSessionUsingPortClient.cpp
  IPSSOLSessionUsingPortClient.cpp
  KVMScreenSettingClient.cpp
  KVMWSManClient.cpp
  PowerManagementCapabilitiesWsManClient.cpp
  SIOWSManClient.cpp
  SyncIpClient.cpp
  TimeSynchronizationClient.cpp
  WlanWSManClient.cpp
  WifiPortClient.cpp
)

target_compile_definitions (WsmanClient PUBLIC
  WSMAN_NO_DLL
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
