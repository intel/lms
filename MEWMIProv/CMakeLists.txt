# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2020 Intel Corporation
cmake_minimum_required (VERSION 3.1)

set (MEPROV_MESSAGE_FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MEProvMessageFile.h
  ${CMAKE_CURRENT_BINARY_DIR}/MEProvMessageFile.rc
)
find_program (MC_EXE mc REQUIRED)
#mc -v -r $(SolutionDir) -h $(SolutionDir) $(SolutionDir)MEProvMessageFile.mc
add_custom_command (
  OUTPUT ${MEPROV_MESSAGE_FILES}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/MEProvMessageFile.mc
  COMMAND ${MC_EXE} -v -r ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/MEProvMessageFile.mc
)

add_custom_target (MEProvMessageFile
  DEPENDS ${MEPROV_MESSAGE_FILES}
)
set_source_files_properties (
  ${MEPROV_MESSAGE_FILES}
  PROPERTIES GENERATED TRUE
)

add_library (MEProv SHARED
  Src/AMT_Service_WMI_Provider.cpp
  Src/Audit_Record_WMI_Provider.cpp
  Src/ClassFac.Cpp
  Src/Concrete_Compnent_WMI_Provider.cpp
  Src/EthernetPortSettings_WMI_Provider.cpp
  Src/FWUpdate_Commands.cpp
  Src/Hosted_Sevice_WMI_Provider.cpp
  Src/MainDll.Cpp
  Src/ME_System_WMI_Provider.cpp
  Src/MethProv.Cpp
  Src/OOB_Service_WMI_Provider.cpp
  Src/ProvisioningCertificateHash_WMI_Provider.cpp
  Src/PTHI_Commands.cpp
  Src/WindowsEventLog.cpp
  Src/WMIHelper.cpp
  Src/WSmanCommands.cpp
  Src/UPID_Commands.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/MEProvMessageFile.rc
  MEProv.rc
)

target_include_directories (MEProv PRIVATE
  Include
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}
)

target_compile_definitions (MEProv PRIVATE
  _CRT_SECURE_NO_DEPRECATE
)

target_link_libraries (MEProv
  ACELIB
  LmsMEIClient
  LmsWsmanClient
  wbemuuid.lib
)

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  set_target_properties(MEProv PROPERTIES
    COMPILE_PDB_NAME MEProv
    COMPILE_PDB_OUTPUT_DIR ${CMAKE_BINARY_DIR}
  )
  install (FILES $<TARGET_PDB_FILE:MEProv>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)

install (TARGETS MEProv
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ME
  DESTINATION ${CMAKE_INSTALL_DOCDIR}
)

if (BUILD_TESTS)
  add_subdirectory ("MEProvTest" "MEProvTest")
endif (BUILD_TESTS)
