# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (WMIEventHandler STATIC
  WMIEventHandler.cpp
  WMIFilter.cpp
)

target_link_libraries (WMIEventHandler
  GMS_COMMON
  ACE::ACE
  wbemuuid.lib
)

target_compile_definitions (WMIEventHandler PRIVATE
  WMIEVENTHANDLER_HAS_DLL=0
)
