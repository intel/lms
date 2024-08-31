# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_executable (WsmanClientTest
  WsmanClientTestProject.cpp
  AuditLogTests.cpp
  AuditLogAccessor.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  target_compile_definitions (WsmanClientTest PRIVATE _CRT_SECURE_NO_WARNINGS)
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)

target_link_libraries (WsmanClientTest
  GTest::GTest
  WsmanClient
  ACE::ACE
  MEIClient
)

install (TARGETS WsmanClientTest
  RUNTIME DESTINATION ${LMS_TESTDIR}
)
