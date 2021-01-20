# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsEventManager STATIC
  eventManager.cpp
)


target_link_libraries (LmsEventManager
  LmsGMS_COMMON
  ACE::ACE
)

target_compile_definitions (LmsEventManager PRIVATE
  EVENTMANAGER_HAS_DLL=0
)
