# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

add_library (LmsConfigurator STATIC
  AsyncActivationManager.cpp
  DependancyManager.cpp
  DummyServices.cpp
  LoadedServices.cpp
  ServiceNamesList.cpp
  ServicesBatchCommand.cpp
  Configurator.cpp
)

target_compile_definitions (LmsConfigurator PRIVATE
  CONFIGURATOR_HAS_DLL=0
  FIRSTSERVICE_HAS_DLL=0
  LASTSERVICE_HAS_DLL=0
  AMTENABLELASTSERVICE_HAS_DLL=0
  WAITINGFORPFWLASTSERVICE_HAS_DLL=0
)

if (WIN32 AND NOT BUILD_WIN_UNIVERSAL)
  set (PRW_LIB PowrProf)
endif (WIN32 AND NOT BUILD_WIN_UNIVERSAL)

target_link_libraries (LmsConfigurator
  LmsGMS_COMMON
  ACE::ACE
  LmsWsmanClient
  LmsMEIClient
  ${PRW_LIB}
)
