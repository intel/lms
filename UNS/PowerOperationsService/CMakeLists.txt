# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsPowerOperationsService STATIC
  PowerEventFilter.cpp
  PowerOperationsService.cpp
)

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
  ACE::ACE
  LmsWsmanClient
  ${PWR_LIBRARIES}
)

target_include_directories (LmsPowerOperationsService PRIVATE
  ${PWR_INCLUDE_DIRS}
)

target_compile_definitions (LmsPowerOperationsService PRIVATE
  POWEROPERATIONSSERVICE_HAS_DLL=0
)
