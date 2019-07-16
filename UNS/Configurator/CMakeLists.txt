# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsConfigurator SHARED
  AsyncActivationManager.cpp
  DependancyManager.cpp
  DummyServices.cpp
  LoadedServices.cpp
  ServiceNamesList.cpp
  ServicesBatchCommand.cpp
  Configurator.cpp
  $<$<BOOL:${WIN32}>:Configurator.rc>
)

if (WIN32)
  set_target_properties(LmsConfigurator PROPERTIES OUTPUT_NAME Configurator)
endif (WIN32)

set_target_properties (LmsConfigurator PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsConfigurator PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsConfigurator PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_compile_definitions (LmsConfigurator PRIVATE
  CONFIGURATOR_BUILD_DLL
  FIRSTSERVICE_BUILD_DLL
  LASTSERVICE_BUILD_DLL
  AMTENABLELASTSERVICE_BUILD_DLL
  WAITINGFORPFWLASTSERVICE_BUILD_DLL
)

if (WIN32 AND NOT BUILD_WIN_UNIVERSAL)
  set (PRW_LIB PowrProf)
endif (WIN32 AND NOT BUILD_WIN_UNIVERSAL)

target_link_libraries (LmsConfigurator
  LmsGMS_COMMON
  ACELIB
  LmsWsmanClient
  LmsMEIClient
  ${PRW_LIB}
)

install (TARGETS LmsConfigurator
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsConfigurator>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
