# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_executable (WsmanClientTest
  WsmanClientTestProject.cpp
  AuditLogTests.cpp
  AuditLogAccessor.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  target_compile_definitions (WsmanClientTest PRIVATE _CRT_SECURE_NO_WARNINGS)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)

target_link_libraries (WsmanClientTest
  GTest::GTest
  LmsWsmanClient
  ACE::ACE
  LmsMEIClient
)

install (TARGETS WsmanClientTest
  RUNTIME DESTINATION ${LMS_TESTDIR}
)
