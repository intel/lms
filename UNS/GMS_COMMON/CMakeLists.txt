# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (EVENTLOG_SRC LinuxEventLog.cpp)
else (UNIX)
  set (EVENTLOG_SRC WindowsEventLog.cpp)
  set (VERIFYFILE_SRC VerifyFile.cpp)
  set (SECLIBS 
    crypt32.lib
    WinTrust.lib
    version.lib
  )
endif (UNIX)

add_library (LmsGMS_COMMON SHARED
  EventHandler.cpp
  GMSExternalLogger.cpp
  GmsSubService.cpp
  ${EVENTLOG_SRC}
  RegistryGenerator.cpp
  GmsService.cpp
  ${VERIFYFILE_SRC}
  $<$<BOOL:${WIN32}>:GmsCommon.rc>
)

if (WIN32)
  set_target_properties(LmsGMS_COMMON PROPERTIES OUTPUT_NAME GmsCommon)
endif (WIN32)

set_target_properties (LmsGMS_COMMON PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsGMS_COMMON PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsGMS_COMMON PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_link_libraries (LmsGMS_COMMON
  ACELIB
  Common
  ${SECLIBS}
  UNSMessageFileLib
)

target_compile_definitions (LmsGMS_COMMON PRIVATE
  GMS_COMMON_DLL_EXPORTS
  NO_STDOUT_DEBUG_LOG
)

target_include_directories (LmsGMS_COMMON PUBLIC .)

install (TARGETS LmsGMS_COMMON
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsGMS_COMMON>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
