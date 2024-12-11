# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (FWCIRAWorkaroundService STATIC
  FWCIRAWorkaroundService.cpp
)

target_link_libraries (FWCIRAWorkaroundService
  GMS_COMMON
  ACE::ACE
  WsmanClient
)

target_compile_definitions (FWCIRAWorkaroundService PRIVATE
  FWCIRAWORKAROUNDSERVICE_HAS_DLL=0
)