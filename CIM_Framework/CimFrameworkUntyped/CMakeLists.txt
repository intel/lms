cmake_minimum_required (VERSION 3.1)

if (WIN32)  
  SET (XMLUtils_File "src/XMLUtils_MS.cpp")
else()
  SET (XMLUtils_File "src/XMLUtils_XRCS.cpp")
endif()  

add_library (CimFrameworkUntyped
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

set_target_properties (CimFrameworkUntyped PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories (CimFrameworkUntyped PUBLIC
  "include/"
)
