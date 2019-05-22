# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWiFiProfileSyncService SHARED
  WiFiProfileSyncService.cpp
  WiFiProfileSyncEventFilter.cpp
  WlanBL.cpp
  WlanNotifications.cpp
  WlanProfiles.cpp
  $<$<BOOL:${WIN32}>:WiFiProfileSyncService.rc>
)

if (WIN32)
  set_target_properties (LmsWiFiProfileSyncService PROPERTIES OUTPUT_NAME WiFiProfileSyncService)
endif (WIN32)

set_target_properties (LmsWiFiProfileSyncService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWiFiProfileSyncService PROPERTIES SOVERSION ${LMS_VERSION_STRING})

target_link_libraries (LmsWiFiProfileSyncService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  Iphlpapi.lib
  wlanapi.lib
)

target_compile_definitions (LmsWiFiProfileSyncService PRIVATE
  WIFIPROFILESYNCSERVICE_BUILD_DLL
)

install (TARGETS LmsWiFiProfileSyncService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsWiFiProfileSyncService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
