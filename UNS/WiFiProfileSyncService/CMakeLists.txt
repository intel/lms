# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (WiFiProfileSyncService STATIC
  WiFiProfileSyncService.cpp
  WiFiProfileSyncEventFilter.cpp
  WlanBL.cpp
  WlanNotifications.cpp
  WlanProfiles.cpp
)

target_link_libraries (WiFiProfileSyncService
  GMS_COMMON
  ACE::ACE
  WsmanClient
  Iphlpapi.lib
  wlanapi.lib
)

target_compile_definitions (WiFiProfileSyncService PRIVATE
  WIFIPROFILESYNCSERVICE_HAS_DLL=0
)
