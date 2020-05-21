# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2017-2020 Intel Corporation
cmake_minimum_required(VERSION 3.1)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/com.intel.amt.lms.service.in"
  "${CMAKE_CURRENT_BINARY_DIR}/com.intel.amt.lms.service"
)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/docs-dbus.xml.in"
  docs-dbus.xml
)

set_source_files_properties(
  docs-dbus.xml
  PROPERTIES GENERATED TRUE
)

find_program(GDBUSCODEGEN REQUIRED NAMES gdbus-codegen)

#Generate skeleton:
#gdbus-codegen --interface-prefix com.intel.amt --generate-c-code DBusSkeleton --generate-docbook docs com.intel.amt.lms.xml

set(DBUS_GEN_XML
  ${CMAKE_CURRENT_BINARY_DIR}/docs-com.intel.amt.lms.AT_Device.xml
  ${CMAKE_CURRENT_BINARY_DIR}/docs-com.intel.amt.lms.Manageability.xml
  ${CMAKE_CURRENT_BINARY_DIR}/docs-com.intel.amt.lms.PTHI.xml
  ${CMAKE_CURRENT_BINARY_DIR}/docs-com.intel.amt.lms.UNSAlert.xml
  ${CMAKE_CURRENT_BINARY_DIR}/docs-com.intel.amt.lms.xml
)

set(DBUS_GEN
  ${DBUS_GEN_XML}
  ${CMAKE_CURRENT_BINARY_DIR}/DBusSkeleton.c
  ${CMAKE_CURRENT_BINARY_DIR}/DBusSkeleton.h
)

add_custom_command(OUTPUT ${DBUS_GEN}
  COMMAND ${GDBUSCODEGEN} --interface-prefix com.intel.amt --generate-c-code DBusSkeleton --generate-docbook docs ${CMAKE_CURRENT_SOURCE_DIR}/com.intel.amt.lms.xml
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/com.intel.amt.lms.xml
)

set_source_files_properties(
  ${DBUS_GEN}
  PROPERTIES GENERATED TRUE
)

add_library(LmsDBusService SHARED
  DBusService.cpp
  DBusFilter.cpp
  DBusSkeleton.c
  DBus_Commands.cpp
  Manageability_Commands.cpp
  PTHI_Commands.cpp
  AT_Device.cpp
  UNSAlert.cpp
)

set_target_properties(LmsDBusService PROPERTIES VERSION ${LMS_VERSION_STRING})
set_target_properties(LmsDBusService PROPERTIES SOVERSION ${LMS_VERSION_STRING})
set_target_properties (LmsDBusService PROPERTIES CXX_VISIBILITY_PRESET hidden)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GIO_UNIX REQUIRED gio-unix-2.0)

target_link_libraries(LmsDBusService
  LmsGMS_COMMON
  ACELIB
  ${GIO_UNIX_LIBRARIES}
  DataInterfaceBackend
)

target_include_directories (LmsDBusService PUBLIC
  ${GIO_UNIX_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS LmsDBusService
  LIBRARY DESTINATION ${LMS_LIBDIR}
)

install(FILES com.intel.amt.lms.conf
  DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/dbus-1/system.d/
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/com.intel.amt.lms.service
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/system-services/
)

find_program(XSLTPROC_EXECUTABLE xsltproc)
find_file(DOCBOOK_XSL docbook.xsl /usr/share/xml/docbook/stylesheet/docbook-xsl/html/)
if(XSLTPROC_EXECUTABLE AND DOCBOOK_XSL)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/LmsDBus.html
  DEPENDS ${DBUS_GEN_XML}
  COMMENT "Building LmsDBus.html"
  COMMAND ${XSLTPROC_EXECUTABLE} --stringparam chunker.output.encoding UTF-8 -xinclude -o ${CMAKE_CURRENT_BINARY_DIR}/LmsDBus.html ${DOCBOOK_XSL} docs-dbus.xml
)
add_custom_target(DBus_doc ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/LmsDBus.html
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/LmsDBus.html
  DESTINATION ${CMAKE_INSTALL_DOCDIR}
)
ENDIF(XSLTPROC_EXECUTABLE AND DOCBOOK_XSL)
