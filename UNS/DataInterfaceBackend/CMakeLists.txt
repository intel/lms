# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required(VERSION 3.1)

add_library (DataInterfaceBackend STATIC
  Manageability_Commands_BE.cpp
  PTHI_Commands_BE.cpp
  AT_Device_BE.cpp
  UNSAlert_BE.cpp
  SMBIOS_Reader.cpp
)

set_target_properties (DataInterfaceBackend PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries (DataInterfaceBackend
  GMS_COMMON
  ACE::ACE
  MEIClient
  WsmanClient
)

target_include_directories (DataInterfaceBackend PUBLIC
  .
  "${TOP_DIR}/UNS/AMT_COM_Interface/"
)
