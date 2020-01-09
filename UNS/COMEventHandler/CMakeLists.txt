# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsCOMEventHandler SHARED
  COMEventHandler.cpp
  ComFilter.cpp
  $<$<BOOL:${WIN32}>:COMEventHandler.rc>
)

if (WIN32)
  set_target_properties (LmsCOMEventHandler PROPERTIES OUTPUT_NAME COMEventHandler)
endif (WIN32)

set_target_properties (LmsCOMEventHandler PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsCOMEventHandler PROPERTIES SOVERSION ${LMS_VERSION_STRING})

target_link_libraries (LmsCOMEventHandler
  LmsGMS_COMMON
  ACELIB
)

target_compile_definitions (LmsCOMEventHandler PRIVATE
  COMEVENTHANDLER_BUILD_DLL
)

target_include_directories (LmsCOMEventHandler PRIVATE
  $<TARGET_PROPERTY:AMT_COM_Interface,BINARY_DIR> # For build-time generated in binary dir AMT_COM_Interface.h
  $<TARGET_PROPERTY:AMT_COM_Interface,SOURCE_DIR> # For static AMT_COM_Interface.h dependencies
)

add_dependencies (LmsCOMEventHandler AMT_COM_Interface)

install (TARGETS LmsCOMEventHandler
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsCOMEventHandler>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)