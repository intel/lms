# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2023 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (ADAPTER_SRC AdapterListInfoLinux.cpp)
else (UNIX)
  set (ADAPTER_SRC AdapterListInfoWin32.cpp)
endif (UNIX)

add_library (PortForwardingService STATIC
  LMEConnection.cpp
  PortForwardingService.cpp
  Protocol.cpp
  ${ADAPTER_SRC}
  CimToEventTranslator.cpp
  SoapHandler.cpp
)

if (UNIX)
  find_package (PkgConfig)
  pkg_check_modules (NL3 REQUIRED libnl-3.0)
  pkg_check_modules (NL3-ROUTE REQUIRED libnl-route-3.0)
  pkg_check_modules (GIO REQUIRED gio-2.0)
  set (NET_LIBRARIES ${NL3_LIBRARIES} ${NL3-ROUTE_LIBRARIES} ${GIO_LIBRARIES})
  set (NET_INCLUDE_DIRS ${NL3_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})
  pkg_check_modules (IDN2 REQUIRED libidn2)
else (UNIX)
  set (NET_LIBRARIES Iphlpapi)
  set (NET_INCLUDE_DIRS "")
endif (UNIX)

target_compile_definitions (PortForwardingService PRIVATE
  _REMOTE_SUPPORT
  $<$<BOOL:${NETWORK_NM}>:USE_NM>
  $<$<BOOL:${NETWORK_CN}>:USE_CONNMAN>
  PORTFORWARDINGSERVICE_HAS_DLL=0
)

target_link_libraries (PortForwardingService
  GMS_COMMON
  WsmanClient
  ACE::ACE
  MEIClient
  ${NET_LIBRARIES}
  ${IDN2_LIBRARIES}
)

target_include_directories (PortForwardingService PRIVATE
  ${NET_INCLUDE_DIRS}
  ${IDN2_INCLUDE_DIRS}
)
