# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsHostChangesNotificationService SHARED
  HostChangesNotificationService.cpp
  $<$<BOOL:${WIN32}>:HostChangesNotificationService.rc>
)

if (WIN32)
  set_target_properties(LmsHostChangesNotificationService PROPERTIES OUTPUT_NAME HostChangesNotificationService)
endif (WIN32)

set_target_properties (LmsHostChangesNotificationService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsHostChangesNotificationService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsHostChangesNotificationService PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsHostChangesNotificationService
  LmsGMS_COMMON
  ACELIB
  LmsMEIClient
)

target_compile_definitions (LmsHostChangesNotificationService PRIVATE
  HOSTCHANGESNOTIFICATIONSERVICE_BUILD_DLL
)

install (TARGETS LmsHostChangesNotificationService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsHostChangesNotificationService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
