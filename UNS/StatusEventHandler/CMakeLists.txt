# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsStatusEventHandler SHARED
  StatusEventFilter.cpp
  StatusEventHandler.cpp
  $<$<BOOL:${WIN32}>:StatusEventHandler.rc>
)

if (WIN32)
  set_target_properties(LmsStatusEventHandler PROPERTIES OUTPUT_NAME StatusEventHandler)
endif (WIN32)

set_target_properties (LmsStatusEventHandler PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsStatusEventHandler PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsStatusEventHandler PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsStatusEventHandler
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  LmsMEIClient
)

target_include_directories (LmsStatusEventHandler PRIVATE
  "${TOP_DIR}/UNS/AMT_COM_Interface/"
)

target_compile_definitions (LmsStatusEventHandler PRIVATE
  STATUSEVENTHANDLER_BUILD_DLL
)

install (TARGETS LmsStatusEventHandler
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsStatusEventHandler>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
