# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_subdirectory ("${TOP_DIR}/CIM_Framework" "CIM_Framework")

add_library (LmsWsmanClient SHARED
  AMTEthernetPortSettingsClient.cpp
  AMTFCFHWSmanClient.cpp
  AMTRedirectionServiceWSManClient.cpp
  AuditLogWSManClient.cpp
  BaseWSManClient.cpp
  CancelOptInClient.cpp
  CryptUtils_w.cpp
  EthernetSettingsWSManClient.cpp
  HBPWSManClient.cpp
  HostBootReasonClient.cpp
  IPSIderSessionUsingPortClient.cpp
  IPSKVMSessionUsingPortClient.cpp
  IPSSOLSessionUsingPortClient.cpp
  KVMScreenSettingClient.cpp
  KVMWSManClient.cpp
  PowerManagementCapabilitiesWsManClient.cpp
  RedirectionServiceWSManClient.cpp
  SIOWSManClient.cpp
  SyncIpClient.cpp
  TimeSynchronizationClient.cpp
  WlanWSManClient.cpp
  WifiPortClient.cpp
  $<$<BOOL:${WIN32}>:WsmanClient.rc>
)

if (CMAKE_COMPILER_IS_GNUCC)
target_compile_options (LmsWsmanClient PRIVATE
  -Wno-narrowing
)
endif (CMAKE_COMPILER_IS_GNUCC)

target_compile_definitions (LmsWsmanClient PRIVATE
  -DWSMAN_DLL_EXPORT
)

if (WIN32)
  set_target_properties(LmsWsmanClient PROPERTIES OUTPUT_NAME WsmanClient)
endif (WIN32)

set_target_properties (LmsWsmanClient PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWsmanClient PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWsmanClient PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsWsmanClient
  ACELIB
  CIMFramework
  CimFrameworkUntyped
  LmsMEIClient
  CimOpenWsmanClient
  LmsGMS_COMMON
)

target_include_directories (LmsWsmanClient PUBLIC
  "./"
)

install (TARGETS LmsWsmanClient
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsWsmanClient>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)

if (BUILD_TESTS)
  add_subdirectory ("WsmanClientTest" "WsmanClientTest")
endif (BUILD_TESTS)
