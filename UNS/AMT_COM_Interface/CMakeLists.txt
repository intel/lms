# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required(VERSION 3.12)

add_library (AMT_COM_Interface OBJECT
  AMT_COM_Interface.cpp
  Manageability_Commands.cpp
  PTHI_Commands.cpp
  AT_Device.cpp
  UNSAlert.cpp
  stdafx.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface_i.c
  AMT_COM_Interface.rc
)

set_target_properties (AMT_COM_Interface PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_definitions (AMT_COM_Interface PRIVATE
  _CRT_NON_CONFORMING_WCSTOK
)

target_link_libraries (AMT_COM_Interface
  DataInterfaceBackend
)

target_include_directories (AMT_COM_Interface PUBLIC
  .
  ${CMAKE_CURRENT_BINARY_DIR} # For build-time generated in binary dir AMT_COM_Interface.h
)

set(MIDL_OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface.h
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface_i.c
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface_p.c
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface.tlb
)
set(MIDL_FILE
  ${CMAKE_CURRENT_SOURCE_DIR}/AMT_COM_Interface.idl
)
set(TLB_FILE
  ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface.tlb
)
add_custom_command(
  OUTPUT ${MIDL_OUTPUT}
  COMMAND midl /iid ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface_i.c /env win32 /h ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface.h /W1 /char signed /tlb ${TLB_FILE} /Oicf /target "NT60" /D "NDEBUG" /robust /nologo /proxy ${CMAKE_CURRENT_BINARY_DIR}/AMT_COM_Interface_p.c ${MIDL_FILE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${MIDL_FILE}
  VERBATIM
)
add_custom_target(midl-cmplr
  DEPENDS ${MIDL_OUTPUT}
)
add_dependencies(AMT_COM_Interface
  midl-cmplr
)
set_source_files_properties(
 ${MIDL_OUTPUT}
 PROPERTIES
 GENERATED TRUE
)

if (BUILD_TESTS)
  add_subdirectory ("AMT_COM_Test" "AMT_COM_Test")
endif (BUILD_TESTS)