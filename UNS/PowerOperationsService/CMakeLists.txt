# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsPowerOperationsService SHARED
  PowerEventFilter.cpp
  PowerOperationsService.cpp
  $<$<BOOL:${WIN32}>:PowerOperationsService.rc>
  $<$<BOOL:${WIN32}>:PowerOperationsStrings.rc>
)

if (WIN32)
  set_target_properties(LmsPowerOperationsService PROPERTIES OUTPUT_NAME PowerOperationsService)
endif (WIN32)

set_target_properties (LmsPowerOperationsService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsPowerOperationsService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsPowerOperationsService PROPERTIES CXX_VISIBILITY_PRESET hidden)

if (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GIO REQUIRED gio-2.0)
  set (PWR_LIBRARIES ${GIO_LIBRARIES})
  set (PWR_INCLUDE_DIRS ${GIO_INCLUDE_DIRS})
else (UNIX)
  if (NOT BUILD_WIN_UNIVERSAL)
    set (PWR_LIBRARIES powrprof)
  endif (NOT BUILD_WIN_UNIVERSAL)
  set (PWR_INCLUDE_DIRS "")
endif (UNIX)

target_link_libraries (LmsPowerOperationsService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  Common
  ${PWR_LIBRARIES}
)

include_directories (
  ${PWR_INCLUDE_DIRS}
)

target_compile_definitions (LmsPowerOperationsService PRIVATE
  POWEROPERATIONSSERVICE_BUILD_DLL
)

install (TARGETS LmsPowerOperationsService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsPowerOperationsService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
