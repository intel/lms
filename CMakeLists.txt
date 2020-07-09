# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)
project (lms)

option (BUILD_TESTS "Build tests" NO)
option (BUILD_WIN_UNIVERSAL "Build Windows Universal App" NO)
option (IGNORE_DLL_SIGNATURES "Skip Windows DLL signatures check" NO)
if (UNIX)
  option (NETWORK_NM "Use NetworkManager in netwoek manipulations" YES)
  option (NETWORK_CN "Use Connman in netwoek manipulations" NO)
  if (NETWORK_NM AND NETWORK_CN)
    message(FATAL_ERROR "Only one network manager can be supported.")
  endif (NETWORK_NM AND NETWORK_CN)
endif (UNIX)

set (CMAKE_CXX_STANDARD 11)

include (version.cmake)
include (GNUInstallDirs)

set (TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
if (WIN32)
  set (LMS_LIBDIR "${CMAKE_INSTALL_BINDIR}")
  set (LMS_LIBDIR_DBG "${CMAKE_INSTALL_BINDIR}/internal")
  set (LMS_BINPATH "${CMAKE_INSTALL_BINDIR}/lms")
  set (LMS_TESTDIR "${CMAKE_INSTALL_BINDIR}/tests")
else (WIN32)
  set (LMS_LIBDIR "${CMAKE_INSTALL_LIBDIR}")
  set (LMS_BINPATH "${CMAKE_INSTALL_FULL_BINDIR}/lms")
  set (LMS_TESTDIR "${CMAKE_INSTALL_DATAROOTDIR}/lms/tests")
endif (WIN32)

string(APPEND CMAKE_CXX_FLAGS_DEBUG " -DDEBUG -D_DEBUG")
string(APPEND CMAKE_C_FLAGS_DEBUG " -DDEBUG -D_DEBUG")

set (CMAKE_POSITION_INDEPENDENT_CODE ON)

if (UNIX)
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -z noexecstack -z relro -z now")
  set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -z noexecstack -z relro -z now")

  #CMake issue #14983
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pie")

  #Secure library usage and secure compile flags
  add_definitions (-fstack-protector-all -D_FORTIFY_SOURCE=2 -O2 -Wformat -Wformat-security)
  add_compile_options (
     $<$<CXX_COMPILER_ID:GNU>:-fno-strict-overflow>
     $<$<CXX_COMPILER_ID:GNU>:-fno-delete-null-pointer-checks>
     -fwrapv
  )
else (UNIX)
  set(DEFAULT_LINKER_FLAGS_RELEASE "${DEFAULT_LINKER_FLAGS_RELEASE} /GUARD:CF")
  set(DEFAULT_LINKER_FLAGS_RELWITHDEBINFO "${DEFAULT_LINKER_FLAGS_RELWITHDEBINFO} /GUARD:CF")
  add_definitions (/GS /sdl)
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SafeSEH /NXCompat /DynamicBase")
  add_definitions (/D UNICODE /D _UNICODE)
  add_compile_options ($<$<CONFIG:Release>:/O2>)
  add_compile_options (/MT$<$<CONFIG:Debug>:d>)
  if (BUILD_WIN_UNIVERSAL)
    set(MSVC_IGNORED_LIBRARIES "/NODEFAULTLIB:kernel32 /NODEFAULTLIB:advapi32 /NODEFAULTLIB:user32")
    find_library (ONE_CORE "OneCoreUap.lib")
    add_library (ONE_CORE_IMP SHARED IMPORTED)
    set_target_properties (ONE_CORE_IMP PROPERTIES
      IMPORTED_LOCATION ${ONE_CORE}
      IMPORTED_IMPLIB ${ONE_CORE}
    )
    find_library (ONE_CORE_DL "OneCoreUap_downlevel.lib")
    add_library (ONE_CORE_DL_IMP SHARED IMPORTED)
    set_target_properties (ONE_CORE_DL_IMP PROPERTIES
      IMPORTED_LOCATION ${ONE_CORE_DL}
      IMPORTED_IMPLIB ${ONE_CORE_DL}
    )
    link_libraries (
      ONE_CORE_IMP
      ONE_CORE_DL_IMP
    )
  endif (BUILD_WIN_UNIVERSAL)
endif (UNIX)

find_library (ACE_LIB ACE)
find_path (ACE_H ace/ACE.h)

if (ACE_LIB AND ACE_H)
  add_library (ACELIB SHARED IMPORTED)
  set_target_properties (ACELIB PROPERTIES IMPORTED_LOCATION ${ACE_LIB})
  set_target_properties (ACELIB PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${ACE_H})
else (ACE_LIB AND ACE_H)
  if (WIN32)
    add_library (ACELIB STATIC IMPORTED)
  else (WIN32)
    add_library (ACELIB SHARED IMPORTED)
  endif (WIN32)
  #ACE libraries compiled out-of-tree
  if (NOT DEFINED ENV{ACE_ROOT})
    message(FATAL_ERROR "Please define ACE_ROOT environment variable with path to ACE library sources.")
  endif (NOT DEFINED ENV{ACE_ROOT})
  set (ACE_ROOT $ENV{ACE_ROOT})
  if (DEFINED ENV{ACE_LIB})
    set (ACE_LIB_DIR $ENV{ACE_LIB})
  else (DEFINED ENV{ACE_LIB})
    set (ACE_LIB_DIR ${ACE_ROOT}/ace/)
  endif (DEFINED ENV{ACE_LIB})
  find_library (ACE_LIB_INT ACEs ACE PATHS ${ACE_LIB_DIR} NO_DEFAULT_PATH)
  set_target_properties (ACELIB PROPERTIES
    IMPORTED_LOCATION ${ACE_LIB_INT}
    IMPORTED_IMPLIB ${ACE_LIB_INT}
    INTERFACE_INCLUDE_DIRECTORIES ${ACE_ROOT}
  )
  if (WIN32)
    add_definitions (/D ACE_AS_STATIC_LIBS)
  else (WIN32)
    list (APPEND CMAKE_INSTALL_RPATH ${ACE_LIB_DIR})
    file (GLOB ACE_LIBS
      ${ACE_LIB_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}ACE${CMAKE_SHARED_LIBRARY_SUFFIX}*
    )
    file (TO_CMAKE_PATH "${ACE_LIBS}" ACE_LIBS_F)
    install (FILES ${ACE_LIBS_F}
      DESTINATION ${LMS_LIBDIR}
    )
  endif (WIN32)
endif (ACE_LIB AND ACE_H)

# for ver.h
include_directories (Common)

install (DIRECTORY Docs/Licenses
  DESTINATION ${CMAKE_INSTALL_DOCDIR}
  FILES_MATCHING PATTERN "LICENSE.*"
)

if (BUILD_TESTS)
  include (gtest.cmake)
endif (BUILD_TESTS)
add_subdirectory ("MEIClient" "MEIClient")
add_subdirectory ("WsmanClient" "WsmanClient")

add_subdirectory (UNS)
if (WIN32)
  add_subdirectory (MEWMIProv)
endif (WIN32)

# CPack
set (CPACK_PACKAGE_VERSION_MAJOR ${LMS_VERSION_MAJOR})
set (CPACK_PACKAGE_VERSION_MINOR ${LMS_VERSION_MINOR})
set (CPACK_PACKAGE_VERSION_PATCH ${LMS_VERSION_PATCH})
set (CPACK_PACKAGE_VENDOR "Intel(R) Corporation")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "Local Managability Service")
set (CPACK_PACKAGE_CONTACT "linux-mei@linux.intel.com")
if (EXISTS .gitignore)
  file (STRINGS .gitignore GIT_IGNORE)
  string (REPLACE "*." "\\\\." GIT_IGNORE "${GIT_IGNORE}")
  set (CPACK_SOURCE_IGNORE_FILES "${GIT_IGNORE}")
endif (EXISTS .gitignore)
set (CPACK_SOURCE_GENERATOR "TBZ2")
set (CPACK_SOURCE_PACKAGE_FILE_NAME ${CMAKE_PROJECT_NAME}-${LMS_VERSION_STRING})
add_custom_target (dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

if (UNIX)
  #Debian Specific
  set (CPACK_DEBIAN_PACKAGE_SECTION "utils")
  set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
  set (CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)

  set (CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    "${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/postinst;${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/prerm"
  )

  set (CPACK_GENERATOR "DEB")
else (UNIX)
  set (CPACK_GENERATOR "ZIP")
endif (UNIX)

include (CPack)
