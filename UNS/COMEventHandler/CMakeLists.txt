# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsCOMEventHandler STATIC
  COMEventHandler.cpp
  ComFilter.cpp
)


target_link_libraries (LmsCOMEventHandler
  LmsGMS_COMMON
  ACE::ACE
)

target_compile_definitions (LmsCOMEventHandler PRIVATE
  COMEVENTHANDLER_HAS_DLL=0
)

target_include_directories (LmsCOMEventHandler PRIVATE
  $<TARGET_PROPERTY:AMT_COM_Interface,BINARY_DIR> # For build-time generated in binary dir AMT_COM_Interface.h
  $<TARGET_PROPERTY:AMT_COM_Interface,SOURCE_DIR> # For static AMT_COM_Interface.h dependencies
)

add_dependencies (LmsCOMEventHandler AMT_COM_Interface)
