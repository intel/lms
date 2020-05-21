# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (ADAPTER_SRC AdapterListInfoLinux.cpp)
else (UNIX)
  set (ADAPTER_SRC AdapterListInfoWin32.cpp)
endif (UNIX)

add_library (LmsPortForwardingService SHARED
  Common.cpp
  LMEConnection.cpp
  PortForwardingService.cpp
  Protocol.cpp
  ${ADAPTER_SRC}
  CimToEventTranslator.cpp
  SoapHandler.cpp
  $<$<BOOL:${WIN32}>:PortForwardingService.rc>
)

if (WIN32)
  set_target_properties(LmsPortForwardingService PROPERTIES OUTPUT_NAME PortForwardingService)
endif (WIN32)

set_target_properties (LmsPortForwardingService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsPortForwardingService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsPortForwardingService PROPERTIES CXX_VISIBILITY_PRESET hidden)

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

target_compile_definitions (LmsPortForwardingService PRIVATE
  _REMOTE_SUPPORT
  $<$<BOOL:${NETWORK_NM}>:USE_NM>
  $<$<BOOL:${NETWORK_CN}>:USE_CONNMAN>
  PORTFORWARDINGSERVICE_BUILD_DLL
)

target_link_libraries (LmsPortForwardingService
  LmsGMS_COMMON
  LmsWsmanClient
  ACELIB
  LmsMEIClient
  ${NET_LIBRARIES}
)

target_include_directories (LmsPortForwardingService PRIVATE
  ${NET_INCLUDE_DIRS}
)

install (TARGETS LmsPortForwardingService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsPortForwardingService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
