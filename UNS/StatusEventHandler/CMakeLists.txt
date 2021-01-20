# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsStatusEventHandler STATIC
  StatusEventFilter.cpp
  StatusEventHandler.cpp
)

target_link_libraries (LmsStatusEventHandler
  LmsGMS_COMMON
  ACE::ACE
  LmsWsmanClient
  LmsMEIClient
)

target_include_directories (LmsStatusEventHandler PRIVATE
  "${TOP_DIR}/UNS/AMT_COM_Interface/"
)

target_compile_definitions (LmsStatusEventHandler PRIVATE
  STATUSEVENTHANDLER_HAS_DLL=0
)
