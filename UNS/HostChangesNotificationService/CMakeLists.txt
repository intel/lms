# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (HostChangesNotificationService STATIC
  HostChangesNotificationService.cpp
)

target_link_libraries (HostChangesNotificationService
  GMS_COMMON
  ACE::ACE
  MEIClient
)

target_compile_definitions (HostChangesNotificationService PRIVATE
  HOSTCHANGESNOTIFICATIONSERVICE_HAS_DLL=0
)
