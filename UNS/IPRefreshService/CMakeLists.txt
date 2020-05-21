# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (UNIX)
  set (IPREFRESH_SRC IPRefreshLinux.cpp)
else (UNIX)
  set (IPREFRESH_SRC IPRefreshWin.cpp)
endif (UNIX)

add_library (LmsIPRefreshService SHARED
  IPRefreshService.cpp
  ${IPREFRESH_SRC}
  $<$<BOOL:${WIN32}>:IPRefreshService.rc>
)

if (WIN32)
  set_target_properties(LmsIPRefreshService PROPERTIES OUTPUT_NAME IPRefreshService)
endif (WIN32)

set_target_properties (LmsIPRefreshService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties (LmsIPRefreshService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsIPRefreshService PROPERTIES CXX_VISIBILITY_PRESET hidden)

if (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(NL3 REQUIRED libnl-3.0)
  pkg_check_modules(NL3-ROUTE REQUIRED libnl-route-3.0)
  set (NET_LIBRARIES ${NL3_LIBRARIES} ${NL3-ROUTE_LIBRARIES})
  set (NET_INCLUDE_DIRS ${NL3_INCLUDE_DIRS})
else (UNIX)
  set (NET_LIBRARIES Iphlpapi)
  set (NET_INCLUDE_DIRS "")
endif (UNIX)

target_link_libraries (LmsIPRefreshService
  LmsGMS_COMMON
  ACELIB
  LmsMEIClient
  ${NET_LIBRARIES}
)

target_include_directories (LmsIPRefreshService PRIVATE
  ${NET_INCLUDE_DIRS}
)

target_compile_definitions (LmsIPRefreshService PRIVATE
  IPREFRESHSERVICE_BUILD_DLL
)

install (TARGETS LmsIPRefreshService
  LIBRARY DESTINATION ${LMS_LIBDIR}
  RUNTIME DESTINATION ${LMS_LIBDIR}
)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  install (FILES $<TARGET_PDB_FILE:LmsIPRefreshService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
