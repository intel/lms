# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsHistoryEventHandler STATIC
  HistoryEventHandler.cpp
  IMSSFilter.cpp
)


target_link_libraries (LmsHistoryEventHandler
  LmsGMS_COMMON
  ACE::ACE
)

target_compile_definitions (LmsHistoryEventHandler PRIVATE
  HISTORYEVENTHANDLER_HAS_DLL=0
)
