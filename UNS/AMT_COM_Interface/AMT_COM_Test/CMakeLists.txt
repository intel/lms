# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2023 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_executable (AMT_COM_Test
  AMT_COM_Test/AMT_COM_Test.cpp
)

set_source_files_properties(AMT_COM_Test/AMT_COM_Test.cpp
  PROPERTIES COMPILE_DEFINITIONS /MP1
)

target_link_libraries (AMT_COM_Test
  GTest::GTest
)

target_include_directories (AMT_COM_Test PRIVATE
  ${CMAKE_BINARY_DIR}/UNS/AMT_COM_Interface/
)

add_dependencies (AMT_COM_Test
  AMT_COM_Interface
)

install (TARGETS AMT_COM_Test
  RUNTIME DESTINATION ${LMS_TESTDIR}
)
