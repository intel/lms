# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2023 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (WinLogEventHandler STATIC
  WinLogFilter.cpp
  WinLogEventHandler.cpp
)

target_link_libraries (WinLogEventHandler
  ACE::ACE
  MEIClient
  GMS_COMMON
)

target_compile_definitions (WinLogEventHandler PRIVATE
  WINLOGEVENTHANDLER_HAS_DLL=0
)
