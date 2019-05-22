cmake_minimum_required (VERSION 3.1)

if (UNIX)
  find_package (XercesC REQUIRED)
  find_package (CURL REQUIRED)
  set (NET_LIBRARIES
    ${CURL_LIBRARIES}
    ${XercesC_LIBRARIES}
  )
else (UNIX)
  set (NET_LIBRARIES
    Iphlpapi.lib
    Rpcrt4.lib
  )
endif (UNIX)

add_library (CimOpenWsmanClient STATIC
  CimOpenWsmanClient.cpp
)

set_target_properties (CimOpenWsmanClient PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries (CimOpenWsmanClient
  CimFrameworkUntyped
  WSMAN_CLIENTPP
  WSMAN_CLIENTT
  WSMAN_CLIENT
  WSMAN
  ${NET_LIBRARIES}
  ${LIBXML2_LIBRARIES}
)

target_include_directories (CimOpenWsmanClient PUBLIC
  "./"
)
