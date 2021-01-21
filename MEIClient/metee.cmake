# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

find_package("metee")
if(METEE_FOUND)
  set(LIBMETEE_LIB ${metee_LIBRARIES})
  set(LIBMETEE_HEADER ${metee_INCLUDE_DIRS})
else()
  find_library(LIBMETEE_LIB NAMES metee PATHS ENV METEE_LIB_PATH)
  find_path(LIBMETEE_HEADER NAMES metee.h PATHS ENV METEE_HEADER_PATH)
endif()

if (${LIBMETEE_LIB} MATCHES "LIBMETEE_LIB-NOTFOUND" OR
    ${LIBMETEE_HEADER} MATCHES "LIBMETEE_HEADER-NOTFOUND")
  # Download and unpack metee at configure time
  configure_file (metee-down.cmake.in metee-download/CMakeLists.txt)
  execute_process (COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/metee-download
  )
  if (result)
    message(FATAL_ERROR "CMake step for metee failed: ${result}")
  endif (result)
  execute_process (COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/metee-download
  )
  if (result)
    message (FATAL_ERROR "Build step for metee failed: ${result}")
  endif (result)

  set (LIBMETEE_PATH ${CMAKE_CURRENT_BINARY_DIR}/metee)
  set (LIBMETEE_LIB ${LIBMETEE_PATH}/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}metee${CMAKE_STATIC_LIBRARY_SUFFIX})
  set (LIBMETEE_HEADER ${LIBMETEE_PATH}/include)
  include (ExternalProject)
  ExternalProject_Add (libmetee
    SOURCE_DIR ${LIBMETEE_PATH}
    BUILD_BYPRODUCTS ${LIBMETEE_LIB}
    BUILD_IN_SOURCE YES
    DOWNLOAD_COMMAND ""
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""
    INSTALL_COMMAND ""
  CMAKE_ARGS
    -DBUILD_MSVC_RUNTIME_STATIC=ON
  )
endif ()

add_library (LIBMETEE STATIC IMPORTED)
set_target_properties (LIBMETEE PROPERTIES
  IMPORTED_LOCATION ${LIBMETEE_LIB}
  IMPORTED_IMPLIB ${LIBMETEE_LIB}
  INTERFACE_INCLUDE_DIRECTORIES ${LIBMETEE_HEADER}
)
add_dependencies(LIBMETEE libmetee)
