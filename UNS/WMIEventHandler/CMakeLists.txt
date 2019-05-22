# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsWMIEventHandler SHARED
  WMIEventHandler.cpp
  WMIFilter.cpp
  $<$<BOOL:${WIN32}>:WMIEventHandler.rc>
)

if (WIN32)
  set_target_properties (LmsWMIEventHandler PROPERTIES OUTPUT_NAME WMIEventHandler)
endif (WIN32)

set_target_properties (LmsWMIEventHandler PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsWMIEventHandler PROPERTIES SOVERSION ${LMS_VERSION_STRING})

target_link_libraries (LmsWMIEventHandler
  LmsGMS_COMMON
  ACELIB
  wbemuuid.lib
)

target_compile_definitions (LmsWMIEventHandler PRIVATE
  WMIEVENTHANDLER_BUILD_DLL
)

install (TARGETS LmsWMIEventHandler
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsWMIEventHandler>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
