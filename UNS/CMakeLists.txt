# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2023 Intel Corporation
cmake_minimum_required (VERSION 3.1)

if (WIN32)
  set (UNS_MESSAGE_FILES
    ${PROJECT_BINARY_DIR}/UNSMessageFile.h
    ${PROJECT_BINARY_DIR}/UNSMessageFile.rc
  )
  include(FindMC)
  #mc -v -r $(SolutionDir) -h $(SolutionDir) $(SolutionDir)UNSMessageFile.mc
  add_custom_command (
    OUTPUT ${UNS_MESSAGE_FILES}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/UNSMessageFile.mc
    COMMAND ${CMAKE_MC_COMPILER} -v -r ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/UNSMessageFile.mc
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
  )
else (WIN32)
  set (UNS_MESSAGE_FILES
    ${PROJECT_BINARY_DIR}/UNSMessageFile.h
    ${PROJECT_BINARY_DIR}/UNSMessageMap.h
  )
  find_package (PythonInterp REQUIRED 3)

  add_custom_command (
    OUTPUT ${UNS_MESSAGE_FILES}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/UNSMessageFile.mc
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/GenerateMessageFiles.py ${CMAKE_CURRENT_SOURCE_DIR}/UNSMessageFile.mc ${PROJECT_BINARY_DIR}/UNSMessageFile.h ${PROJECT_BINARY_DIR}/UNSMessageMap.h
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
endif (WIN32)

add_custom_target (UNSMessageFile
  DEPENDS ${UNS_MESSAGE_FILES}
)
set_source_files_properties (
  ${UNS_MESSAGE_FILES}
  PROPERTIES GENERATED TRUE
)

add_library (UNSMessageFileLib INTERFACE)
set_target_properties (UNSMessageFileLib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_BINARY_DIR}
)
add_dependencies (UNSMessageFileLib UNSMessageFile)

add_subdirectory ("GMS_COMMON" "GMS_COMMON")
add_subdirectory ("Configurator" "Configurator")
add_subdirectory ("EventManager" "EventManager")
add_subdirectory ("HistoryEventHandler" "HistoryEventHandler")
add_subdirectory ("HostChangesNotificationService" "HostChangesNotificationService")
if (WIN32)
  add_subdirectory ("IPRefreshService" "IPRefreshService")
  add_subdirectory ("AMT_COM_Interface" "AMT_COM_Interface")
  add_subdirectory ("WMIEventHandler" "WMIEventHandler")
  add_subdirectory ("COMEventHandler" "COMEventHandler")
  add_subdirectory ("WiFiProfileSyncService" "WiFiProfileSyncService")
  add_subdirectory ("PartialFWUpdateService" "PartialFWUpdateService")
endif (WIN32)
add_subdirectory ("PortForwardingService" "PortForwardingService")
add_subdirectory ("PowerOperationsService" "PowerOperationsService")
add_subdirectory ("SharedStaticIPService" "SharedStaticIPService")
add_subdirectory ("StatusEventHandler" "StatusEventHandler")
add_subdirectory ("TimeSyncService" "TimeSyncService")
add_subdirectory ("WinLogEventHandler" "WinLogEventHandler")
if (UNIX)
  add_subdirectory ("DBusService" "DBusService")
  add_subdirectory ("WatchdogService" "WatchdogService")
endif (UNIX)
add_subdirectory ("DataInterfaceBackend" "DataInterfaceBackend")

add_executable (lms WIN32
  UNSMain.cpp
  $<$<BOOL:${WIN32}>:${PROJECT_BINARY_DIR}/UNSMessageFile.rc>
)

target_link_libraries (lms
  ACE::ACE
  GMS_COMMON
  $<$<BOOL:${WIN32}>:AMT_COM_Interface>
  Configurator
  $<$<BOOL:${WIN32}>:COMEventHandler>
  $<$<BOOL:${UNIX}>:DBusService>
  EventManager
  HistoryEventHandler
  HostChangesNotificationService
  PortForwardingService
  PowerOperationsService
  SharedStaticIPService
  StatusEventHandler
  TimeSyncService
  WinLogEventHandler
  $<$<BOOL:${WIN32}>:IPRefreshService>
  $<$<BOOL:${WIN32}>:WiFiProfileSyncService>
  $<$<BOOL:${WIN32}>:PartialFWUpdateService>
  $<$<BOOL:${WIN32}>:WMIEventHandler>
  $<$<BOOL:${UNIX}>:WatchdogService>
  $<$<BOOL:${WIN32}>:Delayimp.lib>
)

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  set_target_properties(lms PROPERTIES
    COMPILE_PDB_NAME lms
    COMPILE_PDB_OUTPUT_DIR ${CMAKE_BINARY_DIR}
    LINK_FLAGS /MANIFESTUAC:"level='requireAdministrator' uiAccess='false'"
  )
  install (FILES $<TARGET_PDB_FILE:lms>
    DESTINATION ${LMS_LIBDIR_DBG} OPTIONAL
  )
  target_link_options(lms PUBLIC "/DELAYLOAD:wlanapi.dll")
endif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)

install(TARGETS lms
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (UNIX)
  include(FindPkgConfig)
  pkg_check_modules(SYSTEMD "systemd")
  if(SYSTEMD_FOUND)
    execute_process(COMMAND ${PKG_CONFIG_EXECUTABLE}
                    --variable=systemdsystemunitdir systemd
                    OUTPUT_VARIABLE SYSTEMD_SERVICES_INSTALL_DIR)
    string(REGEX REPLACE "[ \t\n]+" "" SYSTEMD_SERVICES_INSTALL_DIR
           "${SYSTEMD_SERVICES_INSTALL_DIR}")
  else()
    set(SYSTEMD_SERVICES_INSTALL_DIR "/lib/systemd/system/")
  endif()

  configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/linux_scripts/lms.service.in"
    "${CMAKE_CURRENT_BINARY_DIR}/lms.service"
  )

  install (FILES ${CMAKE_CURRENT_BINARY_DIR}/lms.service
    DESTINATION ${SYSTEMD_SERVICES_INSTALL_DIR}
  )

  install (FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/linux_scripts/70-persistent-mei.rules
    ${CMAKE_CURRENT_SOURCE_DIR}/linux_scripts/70-mei-wdt.rules
    DESTINATION /lib/udev/rules.d/
  )

  install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/linux_scripts/20-lms.conf
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/rsyslog.d/
  )

  install (FILES ${CMAKE_CURRENT_SOURCE_DIR}/linux_scripts/logrotate.lms
    DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/logrotate.d
    RENAME lms
  )

  if (BUILD_TESTS)
    install (PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tests/dbus_ut.py
      DESTINATION ${LMS_TESTDIR}
      RENAME lms_dbus_ut.py
    )
    install (PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tests/lms_webui_curl.sh
      DESTINATION ${LMS_TESTDIR}
    )
    install (PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tests/lms_webui_wget.sh
      DESTINATION ${LMS_TESTDIR}
    )
  endif (BUILD_TESTS)
else (UNIX)
  install (PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/windows_scripts/lms-installer.bat
    DESTINATION ${LMS_LIBDIR}
  )
  if (BUILD_TESTS)
    install (PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/tests/lms_webui.ps1
      DESTINATION ${LMS_TESTDIR}
    )
  endif (BUILD_TESTS)
endif (UNIX)
