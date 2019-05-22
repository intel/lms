# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsPartialFWUpdateService SHARED
  PartialFWUpdateService.cpp
  PFWUpdateDllWrapperFactory.cpp
  PFWUpdateDllWrapperLegacy.cpp
  PFWUpdateDllWrapperME10.cpp
  PFWUpdateDllWrapperME11.cpp
  PFWUpdateDllWrapperME12.cpp
  errorlist.c
  $<$<BOOL:${WIN32}>:PartialFWUpdateService.rc>
)

if (WIN32)
  set_target_properties (LmsPartialFWUpdateService PROPERTIES OUTPUT_NAME PartialFWUpdateService)
endif (WIN32)

set_target_properties (LmsPartialFWUpdateService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsPartialFWUpdateService PROPERTIES SOVERSION ${LMS_VERSION_STRING})

target_link_libraries (LmsPartialFWUpdateService
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
)

target_compile_definitions (LmsPartialFWUpdateService PRIVATE
  PARTIALFWUPDATESERVICE_BUILD_DLL
)

install (TARGETS LmsPartialFWUpdateService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsPartialFWUpdateService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
