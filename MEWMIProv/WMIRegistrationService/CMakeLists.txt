# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021 Intel Corporation
cmake_minimum_required (VERSION 3.1)

set(WMI_REG_SVC_MESSAGE_FILES
  ${CMAKE_CURRENT_BINARY_DIR}/EventLogMessages.h
  ${CMAKE_CURRENT_BINARY_DIR}/EventLogMessages.rc
)
include(FindMC)
#mc -v -r $(SolutionDir) -h $(SolutionDir) $(SolutionDir)EventLogMessages.mc
add_custom_command(
  OUTPUT ${WMI_REG_SVC_MESSAGE_FILES}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/EventLogMessages.mc
  COMMAND ${CMAKE_MC_COMPILER} -v -r ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/EventLogMessages.mc
)

add_custom_target(WMIRegSvcMessageFile
  DEPENDS ${WMI_REG_SVC_MESSAGE_FILES}
)

set_source_files_properties(
  ${WMI_REG_SVC_MESSAGE_FILES}
  PROPERTIES GENERATED TRUE
)

add_executable(WMIRegistrationService
  EventLog.cpp
  ServiceWin32API.cpp
  WMIRegistrationService.rc
  ${CMAKE_CURRENT_BINARY_DIR}/EventLogMessages.rc
)

target_include_directories(WMIRegistrationService PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}
)

target_link_libraries(WMIRegistrationService
  Shlwapi.lib
)

if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  set_target_properties(WMIRegistrationService PROPERTIES
    COMPILE_PDB_NAME WMIRegistrationService
    COMPILE_PDB_OUTPUT_DIR ${CMAKE_BINARY_DIR}
  )
  install(FILES $<TARGET_PDB_FILE:WMIRegistrationService>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif()

install(TARGETS WMIRegistrationService
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)