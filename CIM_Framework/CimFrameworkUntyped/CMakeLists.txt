# Copyright (c) Intel Corporation, 2019-2021 All Rights Reserved.
cmake_minimum_required (VERSION 3.1)

if (WIN32)
  set (XMLUtils_File "src/XMLUtils_MS.cpp")
else()
  find_package (XercesC REQUIRED)
  set (XMLUtils_File "src/XMLUtils_XRCS.cpp")
  set (XML_LIBRARIES ${XercesC_LIBRARIES})
endif()

add_library (CPPCimFrameworkUntyped
  src/cdecode.cpp
  src/cencode.cpp
  src/CimData.cpp
  src/CimDateTime.cpp
  src/CimException.cpp
  src/CimObject.cpp
  src/CimReference.cpp
  src/CimSerializer.cpp
  src/CimUtils.cpp
  src/CimWsman.cpp
  src/WSIdentify.cpp
  ${XMLUtils_File}
)

target_link_libraries (CPPCimFrameworkUntyped
  ${XML_LIBRARIES}
)

file (GLOB CIMFRAMEWORKUNTYPED_INCLUDES
  include/*.h
)

set_target_properties (CPPCimFrameworkUntyped PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties (CPPCimFrameworkUntyped PROPERTIES PUBLIC_HEADER "${CIMFRAMEWORKUNTYPED_INCLUDES}")

target_include_directories (CPPCimFrameworkUntyped PUBLIC
  "include/"
)
