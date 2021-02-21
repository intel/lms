# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (WatchdogService STATIC
  WatchdogService.cpp
)

target_link_libraries (WatchdogService
  GMS_COMMON
  ACE::ACE
)

target_compile_definitions (WatchdogService PRIVATE
  WATCHDOGSERVICE_HAS_DLL=0
)
