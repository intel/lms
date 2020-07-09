# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (IPREFRESH_SRC IPRefreshLinux.cpp)
else (UNIX)
  set (IPREFRESH_SRC IPRefreshWin.cpp)
endif (UNIX)

add_library (LmsIPRefreshService STATIC
  IPRefreshService.cpp
  ${IPREFRESH_SRC}
)

if (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(NL3 REQUIRED libnl-3.0)
  pkg_check_modules(NL3-ROUTE REQUIRED libnl-route-3.0)
  set (NET_LIBRARIES ${NL3_LIBRARIES} ${NL3-ROUTE_LIBRARIES})
  set (NET_INCLUDE_DIRS ${NL3_INCLUDE_DIRS})
else (UNIX)
  set (NET_LIBRARIES Iphlpapi)
  set (NET_INCLUDE_DIRS "")
endif (UNIX)

target_link_libraries (LmsIPRefreshService
  LmsGMS_COMMON
  ACELIB
  LmsMEIClient
  ${NET_LIBRARIES}
)

target_include_directories (LmsIPRefreshService PRIVATE
  ${NET_INCLUDE_DIRS}
)

target_compile_definitions (LmsIPRefreshService PRIVATE
  IPREFRESHSERVICE_HAS_DLL=0
)
