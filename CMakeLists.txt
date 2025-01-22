# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2025 Intel Corporation
cmake_minimum_required (VERSION 3.15)
project (lms)

set(LICENSE Apache)

option (BUILD_TESTS "Build tests" NO)
option (IGNORE_DLL_SIGNATURES "Skip Windows DLL signatures check" NO)
option (BUILD_USE_CONAN "Use Conan for dependencies download" NO)
if (UNIX)
  option (NETWORK_NM "Use NetworkManager in network manipulations" YES)
  option (NETWORK_CN "Use Connman in network manipulations" NO)
  if (NETWORK_NM AND NETWORK_CN)

    message(FATAL_ERROR "Only one network manager can be supported.")
  endif (NETWORK_NM AND NETWORK_CN)
endif (UNIX)

set (CMAKE_CXX_STANDARD 17)

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
  set (LMS_LIBDIR_DBG "${CMAKE_INSTALL_LIBDIR}")
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
  add_compile_options(/GS)
  add_compile_options(/sdl)
  add_compile_options(/guard:cf)
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SafeSEH /NXCompat /DynamicBase")
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL:NO /DEBUG:FULL /OPT:REF /OPT:ICF /guard:cf")
  set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /INCREMENTAL:NO /DEBUG:FULL /OPT:REF /OPT:ICF /guard:cf")
  add_definitions(/DUNICODE)
  add_definitions(/D_UNICODE)
  add_compile_options ($<$<CONFIG:Release>:/O2>)
  if(${CMAKE_VERSION} VERSION_LESS "3.15.0")
    add_compile_options(/MT$<$<CONFIG:Debug>:d>)
  else()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  endif()
  add_compile_options(/MP)
  add_compile_options(/W3)
  #Generate pdb
  add_compile_options ($<$<CONFIG:Release>:/Zi>)

  # Universal build
  set(CMAKE_CXX_STANDARD_LIBRARIES " ") # space is intentional
  set(CMAKE_C_STANDARD_LIBRARIES ${CMAKE_CXX_STANDARD_LIBRARIES})
  set(MSVC_IGNORED_LIBRARIES "/NODEFAULTLIB:kernel32.lib /NODEFAULTLIB:advapi32.lib /NODEFAULTLIB:user32.lib /NODEFAULTLIB:setupapi.lib /NODEFAULTLIB:gdi32.lib /NODEFAULTLIB:winspool.lib /NODEFAULTLIB:shell32.lib /NODEFAULTLIB:ole32.lib /NODEFAULTLIB:oleaut32.lib  /NODEFAULTLIB:comdlg32.lib /NODEFAULTLIB:advapi32.lib")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MSVC_IGNORED_LIBRARIES}")
  link_libraries (
    OneCoreUap.lib
    OneCoreUap_downlevel.lib
  )
endif (UNIX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(BUILD_USE_CONAN)
  include(conan)
  conan_cmake_autodetect(settings)
  # conan.cmake failed to detect MT, force-replace it
  string(REPLACE "compiler.runtime=MD" "compiler.runtime=MT" flags "${settings}")
  if(BUILD_TESTS)
    set(BUILD_TESTS_OPTION True)
  else()
    set(BUILD_TESTS_OPTION False)
  endif()
  conan_cmake_install(PATH_OR_REFERENCE ${CMAKE_CURRENT_SOURCE_DIR} SETTINGS ${flags} OPTIONS build_tests=${BUILD_TESTS_OPTION})
endif()

find_package(ACE REQUIRED)

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
  find_program(DEB_EXE debuild)
  if(DEB_EXE)
    list(APPEND CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)

    set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
      "${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/postinst;${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/prerm;${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/postrm"
    )

    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libglib2.0-0)
    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libcurl4)
    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libxerces-c3.2)
    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libnl-3-200)
    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libnl-route-3-200)
    list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libxml2)
  endif(DEB_EXE)

  # RPM Specific
  find_program(RPM_EXE rpmbuild)
  if(RPM_EXE)
    list(APPEND CPACK_GENERATOR "RPM")
    set(CPACK_RPM_PACKAGE_RELEASE 1)
    set(CPACK_RPM_PACKAGE_LICENSE ${LICENSE})
    set(CPACK_RPM_PACKAGE_GROUP "System Tools")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/lib")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/lib/systemd")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/lib/systemd/system")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/lib")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/lib/udev")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/lib/udev/rules.d")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/lib/udev")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/lib/udev/rules.d")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/etc/dbus-1")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/etc/dbus-1/system.d")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/share/dbus-1")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/usr/share/dbus-1/system-services")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/etc/logrotate.d")
    list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "/etc/rsyslog.d")

    list(APPEND CPACK_RPM_RELOCATION_PATHS "/lib/udev/rules.d")
    list(APPEND CPACK_RPM_RELOCATION_PATHS "/etc/rsyslog.d")
    list(APPEND CPACK_RPM_RELOCATION_PATHS "/etc/logrotate.d")
    list(APPEND CPACK_RPM_RELOCATION_PATHS "/etc/dbus-1/system.d")

    set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/post.rpm)
    set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/UNS/linux_scripts/preun.rpm)
  endif(RPM_EXE)
else (UNIX)
  set (CPACK_GENERATOR "ZIP")
endif (UNIX)

include (CPack)
