# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsHistoryEventHandler SHARED
  HistoryEventHandler.cpp
  IMSSFilter.cpp
  $<$<BOOL:${WIN32}>:HistoryEventHandler.rc>
)

if (WIN32)
  set_target_properties(LmsHistoryEventHandler PROPERTIES OUTPUT_NAME HistoryEventHandler)
endif (WIN32)

set_target_properties (LmsHistoryEventHandler PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsHistoryEventHandler PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsHistoryEventHandler PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsHistoryEventHandler
  LmsGMS_COMMON
  ACELIB
  Common
)

target_compile_definitions (LmsHistoryEventHandler PRIVATE
  HISTORYEVENTHANDLER_BUILD_DLL
)

install (TARGETS LmsHistoryEventHandler
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsHistoryEventHandler>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
