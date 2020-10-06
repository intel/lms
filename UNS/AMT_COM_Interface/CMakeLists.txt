# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required(VERSION 3.12)

add_library (AMT_COM_Interface STATIC
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
  _CRT_SECURE_NO_WARNINGS
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

# find_program (TLBIMP TlbImp REQUIRED)

# $(SolutionDir)..\Tools\mssdk\TlbImp $(OutDir)LMS.exe /out: AMT_COM_InterfaceLib.dll
# add_custom_command (
  # OUTPUT AMT_COM_InterfaceLib.dll
  # DEPENDS ${PROJECT_BINARY_DIR}/UNS/${CMAKE_CFG_INTDIR}/lms.exe
  # COMMAND ${TLBIMP} ${PROJECT_BINARY_DIR}/UNS/${CMAKE_CFG_INTDIR}/lms.exe /out: AMT_COM_InterfaceLib.dll
  # COMMENT "Generate AMT_COM_InterfaceLib.dll for PIcon"
# )

# add_custom_target (AMT_COM_INTERFACELIB_SRC ALL
  # DEPENDS AMT_COM_InterfaceLib.dll
# )

# add_dependencies(AMT_COM_INTERFACELIB_SRC lms)

# add_library(AMT_COM_INTERFACEDLL SHARED IMPORTED)
# set_target_properties (AMT_COM_INTERFACEDLL PROPERTIES IMPORTED_LOCATION AMT_COM_InterfaceLib.dll)
# add_dependencies(AMT_COM_INTERFACEDLL AMT_COM_INTERFACELIB_SRC)