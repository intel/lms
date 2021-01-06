# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsPartialFWUpdateService STATIC
  PartialFWUpdateService.cpp
  PFWUpdateDllWrapperFactory.cpp
  PFWUpdateDllWrapperLegacy.cpp
  PFWUpdateDllWrapperME11.cpp
  PFWUpdateDllWrapperME12.cpp
  errorlist.c
)

target_link_libraries (LmsPartialFWUpdateService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
)

target_compile_definitions (LmsPartialFWUpdateService PRIVATE
  PARTIALFWUPDATESERVICE_HAS_DLL=0
)
