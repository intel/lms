# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsHostChangesNotificationService STATIC
  HostChangesNotificationService.cpp
)

target_link_libraries (LmsHostChangesNotificationService
  LmsGMS_COMMON
  ACELIB
  LmsMEIClient
)

target_compile_definitions (LmsHostChangesNotificationService PRIVATE
  HOSTCHANGESNOTIFICATIONSERVICE_HAS_DLL=0
)