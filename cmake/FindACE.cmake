# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021-2022 Intel Corporation
find_path(ACE_INCLUDE_DIR
          NAMES ace/ACE.h
          HINTS ENV ACE_INCLUDE_DIR
          PATHS /usr/include
)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(ACE_LIB_NAMES aced ACEd)
  set(ACE_LIB_NAMES_STATIC acesd ACEsd)
else()
  set(ACE_LIB_NAMES ace ACE)
  set(ACE_LIB_NAMES_STATIC aces ACEs)
endif()

find_library(ACE_LIBRARY NAMES ${ACE_LIB_NAMES} HINTS ENV ACE_LIBRARY)
if (${ACE_LIBRARY} MATCHES "ACE_LIBRARY-NOTFOUND")
  find_library(ACE_LIBRARY NAMES ${ACE_LIB_NAMES_STATIC} HINTS ENV ACE_LIBRARY)
  set(ACE_DEFINITIONS "ACE_AS_STATIC_LIBS")
endif()

if(ACE_INCLUDE_DIR AND EXISTS "${ACE_INCLUDE_DIR}/ace/Version.h")
   file(STRINGS "${ACE_INCLUDE_DIR}/ace/Version.h" ace_version_str
        REGEX "^#define[\t ]+ACE_VERSION[\t ]+\".*\"")

   string(REGEX REPLACE "^#define[\t ]+ACE_VERSION[\t ]+\"([^\"]*)\".*" "\\1"
          ACE_VERSION_STRING "${ace_version_str}")
   unset(ace_version_str)
endif()

set(ACE_INCLUDE_DIRS ${ACE_INCLUDE_DIR})
set(ACE_LIBRARIES ${ACE_LIBRARY})

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ACE FOUND_VAR ACE_FOUND
                                  REQUIRED_VARS ACE_LIBRARY ACE_INCLUDE_DIR
                                  VERSION_VAR ACE_VERSION_STRING)

mark_as_advanced(ACE_INCLUDE_DIR ACE_LIBRARY)

if(ACE_FOUND AND NOT TARGET ACE::ACE)
  add_library(ACE::ACE UNKNOWN IMPORTED)
  set_target_properties(ACE::ACE PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${ACE_INCLUDE_DIRS}")
  set_target_properties(ACE::ACE PROPERTIES INTERFACE_COMPILE_OPTIONS "${ACE_DEFINITIONS}")
  set_property(TARGET ACE::ACE APPEND PROPERTY IMPORTED_LOCATION "${ACE_LIBRARY}")
  set_property(TARGET ACE::ACE PROPERTY INTERFACE_LINK_LIBRARIES dl)
endif()
