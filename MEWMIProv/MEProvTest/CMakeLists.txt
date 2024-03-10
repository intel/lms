# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2020-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_executable (MEProvTest
  MEProvTest.cpp
)

target_link_libraries (MEProvTest
  GTest::GTest
)

install (TARGETS MEProvTest
  RUNTIME DESTINATION ${LMS_TESTDIR}
)