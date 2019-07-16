# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsTimeSyncService SHARED
  TimeSyncService.cpp
  TimeSyncEventFilter.cpp
  $<$<BOOL:${WIN32}>:TimeSyncService.rc>
)

if (WIN32)
  set_target_properties(LmsTimeSyncService PROPERTIES OUTPUT_NAME TimeSyncService)
endif (WIN32)

set_target_properties (LmsTimeSyncService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsTimeSyncService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsTimeSyncService PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsTimeSyncService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  LmsMEIClient
)

target_compile_definitions (LmsTimeSyncService PRIVATE
  TIMESYNCSERVICE_BUILD_DLL
)

install (TARGETS LmsTimeSyncService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsTimeSyncService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
