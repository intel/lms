# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (SYNC_SRC SyncNetworkDataLinux.cpp)
else (UNIX)
  set (SYNC_SRC SyncNetworkDataWin32.cpp)
endif (UNIX)

add_library (LmsSharedStaticIPService STATIC
  SyncNetworkData.cpp
  ${SYNC_SRC}
  SharedStaticIPService.cpp
  SharedStaticIPEventFilter.cpp
)

if (UNIX)
  find_package (PkgConfig)
  pkg_check_modules (NL3 REQUIRED libnl-3.0)
  pkg_check_modules (NL3-ROUTE REQUIRED libnl-route-3.0)
  pkg_check_modules (GIO REQUIRED gio-2.0)
  set (NET_LIBRARIES ${NL3_LIBRARIES} ${NL3-ROUTE_LIBRARIES} ${GIO_LIBRARIES})
  set (NET_INCLUDE_DIRS ${NL3_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})
else (UNIX)
  set (NET_LIBRARIES Iphlpapi)
  set (NET_INCLUDE_DIRS "")
endif (UNIX)

target_compile_definitions (LmsSharedStaticIPService PRIVATE
  $<$<BOOL:${NETWORK_NM}>:USE_NM>
  $<$<BOOL:${NETWORK_CN}>:USE_CONNMAN>
  SHAREDSTATICIPSERVICE_HAS_DLL=0
)

target_link_libraries (LmsSharedStaticIPService
  LmsGMS_COMMON
  ACE::ACE
  LmsWsmanClient
  LmsMEIClient
  ${NET_LIBRARIES}
)

target_include_directories (LmsSharedStaticIPService PRIVATE
  ${NET_INCLUDE_DIRS}
)
