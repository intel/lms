# Copyright (c) Intel Corporation, 2019-2024 All Rights Reserved.
cmake_minimum_required (VERSION 3.15)

add_library (CimOpenWsmanClient STATIC
  CimOpenWsmanClient.cpp
)

set_target_properties (CimOpenWsmanClient PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties (CimOpenWsmanClient PROPERTIES PUBLIC_HEADER CimOpenWsmanClient.h)

target_link_libraries (CimOpenWsmanClient
  CPPCimFrameworkUntyped
  WSMAN_CLIENTPP
  WSMAN_CLIENTT
  WSMAN_CLIENT
  WSMAN
)

target_include_directories (CimOpenWsmanClient PUBLIC
  "./"
)