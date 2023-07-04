# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (PowerOperationsService STATIC
  PowerEventFilter.cpp
  PowerOperationsService.cpp
)

if (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GIO REQUIRED gio-2.0)
  set (PWR_LIBRARIES ${GIO_LIBRARIES})
  set (PWR_INCLUDE_DIRS ${GIO_INCLUDE_DIRS})
else (UNIX)
  set (PWR_LIBRARIES "")
  set (PWR_INCLUDE_DIRS "")
endif (UNIX)

target_link_libraries (PowerOperationsService
  GMS_COMMON
  ACE::ACE
  WsmanClient
  ${PWR_LIBRARIES}
)

target_include_directories (PowerOperationsService PRIVATE
  ${PWR_INCLUDE_DIRS}
)

target_compile_definitions (PowerOperationsService PRIVATE
  POWEROPERATIONSSERVICE_HAS_DLL=0
)
