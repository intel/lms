# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

add_library (Configurator STATIC
  AsyncActivationManager.cpp
  DependancyManager.cpp
  DummyServices.cpp
  LoadedServices.cpp
  ServiceNamesList.cpp
  ServicesBatchCommand.cpp
  Configurator.cpp
)

target_compile_definitions (Configurator PRIVATE
  CONFIGURATOR_HAS_DLL=0
  FIRSTSERVICE_HAS_DLL=0
  LASTSERVICE_HAS_DLL=0
  AMTENABLELASTSERVICE_HAS_DLL=0
  WAITINGFORPFWLASTSERVICE_HAS_DLL=0
)

target_link_libraries (Configurator
  GMS_COMMON
  ACE::ACE
  WsmanClient
  MEIClient
)
