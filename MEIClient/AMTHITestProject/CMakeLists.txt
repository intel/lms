# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2013-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_executable (AMTHITestProject
  AMTHITestProject.cpp
)

target_link_libraries (AMTHITestProject
  GTest::GTest
  MEIClient
  $<$<BOOL:${WIN32}>:Ws2_32.lib>
)

install (TARGETS AMTHITestProject
  RUNTIME DESTINATION ${LMS_TESTDIR}
)
