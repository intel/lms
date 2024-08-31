# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2024 Intel Corporation
cmake_minimum_required (VERSION 3.15)

find_package("metee")
if(NOT METEE_FOUND)
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

  if (CMAKE_TOOLCHAIN_FILE)
    set (USE_TOOLCHAIN "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")
  endif (CMAKE_TOOLCHAIN_FILE)

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
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_SYSTEM_VERSION=${CMAKE_SYSTEM_VERSION}
    -DBUILD_SHARED_LIBS=OFF
    -DBUILD_MSVC_RUNTIME_STATIC=ON
    ${USE_TOOLCHAIN}
  )

  add_library (metee::metee STATIC IMPORTED)
  set_target_properties (metee::metee PROPERTIES
    IMPORTED_LOCATION ${LIBMETEE_LIB}
    IMPORTED_IMPLIB ${LIBMETEE_LIB}
    INTERFACE_INCLUDE_DIRECTORIES ${LIBMETEE_HEADER}
  )
  add_dependencies(metee::metee libmetee)
endif()
