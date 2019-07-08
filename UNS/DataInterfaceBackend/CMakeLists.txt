# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required(VERSION 3.1)

add_library (DataInterfaceBackend STATIC
  Manageability_Commands_BE.cpp
  PTHI_Commands_BE.cpp
  AT_Device_BE.cpp
  UNSAlert_BE.cpp
  SMBIOS_Reader.cpp
)

set_target_properties (DataInterfaceBackend PROPERTIES POSITION_INDEPENDENT_CODE ON)

if (CMAKE_COMPILER_IS_GNUCC)
  target_compile_options (DataInterfaceBackend PRIVATE -Wno-narrowing)
endif (CMAKE_COMPILER_IS_GNUCC)

target_link_libraries (DataInterfaceBackend
  LmsGMS_COMMON
  ACELIB
  LmsMEIClient
  LmsWsmanClient
)

target_include_directories (DataInterfaceBackend PUBLIC
  .
  "${TOP_DIR}/UNS/AMT_COM_Interface/"
)
