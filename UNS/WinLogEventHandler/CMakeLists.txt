# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWinLogEventHandler SHARED
  WinLogFilter.cpp
  WinLogEventHandler.cpp
  GMSConfig.cpp
  $<$<BOOL:${WIN32}>:WinLogEventHandler.rc>
)

if (WIN32)
  set_target_properties(LmsWinLogEventHandler PROPERTIES OUTPUT_NAME WinLogEventHandler)
endif (WIN32)

set_target_properties (LmsWinLogEventHandler PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWinLogEventHandler PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWinLogEventHandler PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsWinLogEventHandler
  ACELIB
  LmsMEIClient
  LmsGMS_COMMON
)

target_compile_definitions (LmsWinLogEventHandler PRIVATE
  WINLOGEVENTHANDLER_BUILD_DLL
)

install (TARGETS LmsWinLogEventHandler
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsWinLogEventHandler>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
