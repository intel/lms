# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (SYNC_SRC SyncNetworkDataLinux.cpp)
else (UNIX)
  set (SYNC_SRC SyncNetworkDataWin32.cpp)
endif (UNIX)

add_library (LmsSharedStaticIPService SHARED
  SyncNetworkData.cpp
  ${SYNC_SRC}
  SharedStaticIPService.cpp
  SharedStaticIPEventFilter.cpp
  $<$<BOOL:${WIN32}>:SharedStaticIPService.rc>
)

if (WIN32)
  set_target_properties(LmsSharedStaticIPService PROPERTIES OUTPUT_NAME SharedStaticIPService)
endif (WIN32)

set_target_properties (LmsSharedStaticIPService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsSharedStaticIPService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsSharedStaticIPService PROPERTIES CXX_VISIBILITY_PRESET hidden)

if (UNIX)
  find_package (PkgConfig)
  pkg_check_modules (NL3 REQUIRED libnl-3.0)
  pkg_check_modules (NL3-ROUTE REQUIRED libnl-route-3.0)
  pkg_check_modules (GIO REQUIRED gio-2.0)

  pkg_check_modules (NETWORKMANAGER NetworkManager)
  pkg_check_modules (CONNMAN connman)

  if (NETWORKMANAGER_FOUND AND CONNMAN_FOUND)
    message(FATAL_ERROR "Both NetworkManager and Connman found. Can't choose.")
  endif (NETWORKMANAGER_FOUND AND CONNMAN_FOUND)
  set (NET_LIBRARIES ${NL3_LIBRARIES} ${NL3-ROUTE_LIBRARIES} ${GIO_LIBRARIES})
  set (NET_INCLUDE_DIRS ${NL3_INCLUDE_DIRS} ${GIO_INCLUDE_DIRS})
else (UNIX)
  set (NET_LIBRARIES Iphlpapi)
  set (NET_INCLUDE_DIRS "")
endif (UNIX)

target_compile_options (LmsSharedStaticIPService PRIVATE
  $<$<BOOL:${NETWORKMANAGER_FOUND}>:-DUSE_NM>
  $<$<BOOL:${CONNMAN_FOUND}>:-DUSE_CONNMAN>
)

target_link_libraries (LmsSharedStaticIPService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  LmsMEIClient
  ${NET_LIBRARIES}
)

include_directories (
  ${NET_INCLUDE_DIRS}
)

target_compile_definitions (LmsSharedStaticIPService PRIVATE
  SHAREDSTATICIPSERVICE_BUILD_DLL
)

install (TARGETS LmsSharedStaticIPService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsSharedStaticIPService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
