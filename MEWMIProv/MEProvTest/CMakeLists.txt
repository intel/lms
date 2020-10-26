# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2020 Intel Corporation
cmake_minimum_required (VERSION 3.10)

add_executable (MEProvTest
  MEProvTest.cpp
)

target_link_libraries (MEProvTest
  gtest_main
)

install (TARGETS MEProvTest
  RUNTIME DESTINATION ${LMS_TESTDIR}
)