# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (TimeSyncService STATIC
  TimeSyncService.cpp
  TimeSyncEventFilter.cpp
)

target_link_libraries (TimeSyncService
  GMS_COMMON
  ACE::ACE
  WsmanClient
  MEIClient
)

target_compile_definitions (TimeSyncService PRIVATE
  TIMESYNCSERVICE_HAS_DLL=0
)
