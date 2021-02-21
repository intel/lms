# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (StatusEventHandler STATIC
  StatusEventFilter.cpp
  StatusEventHandler.cpp
)

target_link_libraries (StatusEventHandler
  GMS_COMMON
  ACE::ACE
  WsmanClient
  MEIClient
)

target_include_directories (StatusEventHandler PRIVATE
  "${TOP_DIR}/UNS/AMT_COM_Interface/"
)

target_compile_definitions (StatusEventHandler PRIVATE
  STATUSEVENTHANDLER_HAS_DLL=0
)
