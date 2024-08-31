# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (EventManager STATIC
  eventManager.cpp
)

target_link_libraries (EventManager
  GMS_COMMON
  ACE::ACE
)

target_compile_definitions (EventManager PRIVATE
  EVENTMANAGER_HAS_DLL=0
)
