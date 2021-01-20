# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsTimeSyncService STATIC
  TimeSyncService.cpp
  TimeSyncEventFilter.cpp
)

target_link_libraries (LmsTimeSyncService
  LmsGMS_COMMON
  ACE::ACE
  LmsWsmanClient
  LmsMEIClient
)

target_compile_definitions (LmsTimeSyncService PRIVATE
  TIMESYNCSERVICE_HAS_DLL=0
)
