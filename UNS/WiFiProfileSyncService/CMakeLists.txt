# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWiFiProfileSyncService STATIC
  WiFiProfileSyncService.cpp
  WiFiProfileSyncEventFilter.cpp
  WlanBL.cpp
  WlanNotifications.cpp
  WlanProfiles.cpp
)

target_link_libraries (LmsWiFiProfileSyncService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  Iphlpapi.lib
  wlanapi.lib
)

target_compile_definitions (LmsWiFiProfileSyncService PRIVATE
  WIFIPROFILESYNCSERVICE_HAS_DLL=0
)