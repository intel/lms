# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWatchdogService STATIC
  WatchdogService.cpp
)

target_link_libraries (LmsWatchdogService
  LmsGMS_COMMON
  ACE::ACE
)

target_compile_definitions (LmsWatchdogService PRIVATE
  WATCHDOGSERVICE_HAS_DLL=0
)
