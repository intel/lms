# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (REGISTRY_SRC LinuxRegistryStorage.cpp)
  set (SHARED_COMMON STATIC)  
else (UNIX)
  set (REGISTRY_SRC WindowsRegistryStorage.cpp)
  set (IS64BIT_SRC Is64BitOs.cpp)
  set (STRINGMANAGER_SRC StringManager.cpp)
  set (STRINGLOADER_SRC WindowsStringLoader.cpp)
  set (SHARED_COMMON SHARED)
endif (UNIX)

add_library (Common ${SHARED_COMMON}
  Tools.cpp
  UNSDebug.cpp
  UNSRegistry.cpp
  DataStorageWrapper.cpp
  RegistryStorage.cpp
  ${REGISTRY_SRC}
  ${IS64BIT_SRC}
  ${STRINGMANAGER_SRC}
  ${STRINGLOADER_SRC}
  $<$<BOOL:${WIN32}>:Common.rc>
)

set_target_properties (Common PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_definitions (Common PRIVATE
  COMMON_DLL_EXPORTS
  $<$<BOOL:${WIN32}>:_CRT_SECURE_NO_WARNINGS> 
)

target_include_directories (Common PUBLIC .)

if (WIN32)
  install (TARGETS Common
    RUNTIME DESTINATION ${LMS_LIBDIR}
  )
endif (WIN32)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:Common>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
