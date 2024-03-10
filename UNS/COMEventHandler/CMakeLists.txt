# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (COMEventHandler STATIC
  COMEventHandler.cpp
  ComFilter.cpp
)


target_link_libraries (COMEventHandler
  GMS_COMMON
  ACE::ACE
)

target_compile_definitions (COMEventHandler PRIVATE
  COMEVENTHANDLER_HAS_DLL=0
)

target_include_directories (COMEventHandler PRIVATE
  $<TARGET_PROPERTY:AMT_COM_Interface,BINARY_DIR> # For build-time generated in binary dir AMT_COM_Interface.h
  $<TARGET_PROPERTY:AMT_COM_Interface,SOURCE_DIR> # For static AMT_COM_Interface.h dependencies
)

add_dependencies (COMEventHandler AMT_COM_Interface)
