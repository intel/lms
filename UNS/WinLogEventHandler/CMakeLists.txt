# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWinLogEventHandler STATIC
  WinLogFilter.cpp
  WinLogEventHandler.cpp
  GMSConfig.cpp
)

target_link_libraries (LmsWinLogEventHandler
  ACE::ACE
  LmsMEIClient
  LmsGMS_COMMON
)

target_compile_definitions (LmsWinLogEventHandler PRIVATE
  WINLOGEVENTHANDLER_HAS_DLL=0
)
