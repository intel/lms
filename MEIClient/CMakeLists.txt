# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

include (metee.cmake)

add_library (MEIClient STATIC
  src/MEICommand.cpp
  src/MEIparser.cpp
  src/heci.cpp
  AMTHIClient/Src/AmtAnsiString.cpp
  AMTHIClient/Src/AMTHICommand.cpp
  FWUpdateClient/Src/FWUpdateCommand.cpp
  HOTHAMClient/Src/HOTHAMCommand.cpp
  ManageabilityClient/Src/ManageabiltiyCommand.cpp
  MKHIClient/Src/MKHICommand.cpp
  UPIDClient/Src/UPIDCommand.cpp
  PSRClient/Src/PSRCommand.cpp
  MCHIClient/Src/MCHICommand.cpp
)

set_target_properties (MEIClient PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries (MEIClient
  ACE::ACE
  metee::metee
  $<$<BOOL:${WIN32}>:CfgMgr32.lib>
)

target_include_directories (MEIClient PUBLIC
  "Include/"
  "AMTHIClient/Include/"
  "FWUpdateClient/Include/"
  "HOTHAMClient/Include/"
  "ManageabilityClient/Include/"
  "MKHIClient/Include/"
  "UPIDClient/Include/"
  "PSRClient/Include/"
  "MCHIClient/Include/"
)
if (BUILD_TESTS)
  add_subdirectory ("AMTHITestProject" "AMTHITestProject")
endif (BUILD_TESTS)
