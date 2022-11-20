# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2022 Intel Corporation
cmake_minimum_required (VERSION 3.1)

include (metee.cmake)

file (GLOB AMTHIClient
  AMTHIClient/Src/AmtAnsiString.cpp
  AMTHIClient/Src/AMTHICommand.cpp
  AMTHIClient/Src/CFG_SetOverrideProsetAdapterSwitchingCommand.cpp
  AMTHIClient/Src/CloseUserInitiatedConnectionCommand.cpp
  AMTHIClient/Src/EnumerateHashHandlesCommand.cpp
  AMTHIClient/Src/GetAMTStateCommand.cpp
  AMTHIClient/Src/GetCertificateHashEntryCommand.cpp
  AMTHIClient/Src/GetCodeVersionCommand.cpp
  AMTHIClient/Src/GetConfigServerDataCommand.cpp
  AMTHIClient/Src/GetCurrentPowerPolicyCommand.cpp
  AMTHIClient/Src/GetDNSSuffixCommand.cpp
  AMTHIClient/Src/GetDNSSuffixListCommand.cpp
  AMTHIClient/Src/GetEACStateCommand.cpp
  AMTHIClient/Src/GetFQDNCommand.cpp
  AMTHIClient/Src/GetIPv6LanInterfaceStatusCommand.cpp
  AMTHIClient/Src/GetKVMSessionStateCommand.cpp
  AMTHIClient/Src/GetLanInterfaceSettingsCommand.cpp
  AMTHIClient/Src/GetLastHostResetReasonCommand.cpp
  AMTHIClient/Src/GetLocalSystemAccountCommand.cpp
  AMTHIClient/Src/GetMESetupAuditRecordCommand.cpp
  AMTHIClient/Src/GetProvisioningModeCommand.cpp
  AMTHIClient/Src/GetProvisioningStateCommand.cpp
  AMTHIClient/Src/GetProvisioningTlsModeCommand.cpp
  AMTHIClient/Src/GetRedirectionSessionsStateCommand.cpp
  AMTHIClient/Src/GetRedirectionStateCommand.cpp
  AMTHIClient/Src/GetRemoteAccessConnectionStatusCommand.cpp
  AMTHIClient/Src/GetSecurityParametersCommand.cpp
  AMTHIClient/Src/GetSystemDefenseStateCommand.cpp
  AMTHIClient/Src/GetTcpipParametersCommand.cpp
  AMTHIClient/Src/GetUserInitiatedEnabledInterfacesCommand.cpp
  AMTHIClient/Src/GetUUIDCommand.cpp
  AMTHIClient/Src/GetWebUIStateCommand.cpp
  AMTHIClient/Src/GetZeroTouchEnabledCommand.cpp
  AMTHIClient/Src/OpenUserInitiatedConnectionCommand.cpp
  AMTHIClient/Src/SetDNSSuffixCommand.cpp
  AMTHIClient/Src/SetEnterpriseAccessCommand.cpp
  AMTHIClient/Src/SetHostFQDNCommand.cpp
  AMTHIClient/Src/SetProvisioningServerOTPCommand.cpp
  AMTHIClient/Src/StartConfigurationExCommand.cpp
  AMTHIClient/Src/StopConfigurationCommand.cpp
  AMTHIClient/Src/UnprovisionCommand.cpp
)

file (GLOB FWUpdateClient
  FWUpdateClient/Src/FWUGetInfoCommand.cpp
  FWUpdateClient/Src/FWUpdateCommand.cpp
)

file (GLOB HOTHAMClient
  HOTHAMClient/Src/HOTHAMCommand.cpp
  HOTHAMClient/Src/HTMGetFLogCommand.cpp
)

file (GLOB ManageabilityClient
  ManageabilityClient/Src/ManageabiltiyCommand.cpp
  ManageabilityClient/Src/MNGChangeToAMTCommand.cpp
  ManageabilityClient/Src/MNGIsChangeToAMTEnabledCommand.cpp
)

file (GLOB MKHIClient
  MKHIClient/Src/GetEOPStateCommand.cpp
  MKHIClient/Src/GetImageTypeCommand.cpp
  MKHIClient/Src/GetImageFWVersionCommand.cpp
  MKHIClient/Src/GetFWCapsCommand.cpp
  MKHIClient/Src/GetFWUpdateStateCommand.cpp
  MKHIClient/Src/GetFWVersionCommand.cpp
  MKHIClient/Src/GetPlatformTypeCommand.cpp
  MKHIClient/Src/GetMeasuredBootStateCommand.cpp
  MKHIClient/Src/MKHICommand.cpp
)

file (GLOB UPIDClient
  UPIDClient/Src/GetUPIDCommand.cpp
  UPIDClient/Src/GetUPIDFeatureOSControlCommand.cpp
  UPIDClient/Src/GetUPIDFeatureStateCommand.cpp
  UPIDClient/Src/GetUPIDFeatureSupportCommand.cpp
  UPIDClient/Src/SetUPIDFeatureStateCommand.cpp
  UPIDClient/Src/UPIDCommand.cpp
)

file (GLOB PSRClient
  PSRClient/Src/PSRCommand.cpp
  PSRClient/Src/PSRGetPlatformServiceRecordCommand.cpp
)

file (GLOB MCHIClient
  MCHIClient/Src/ReadFileExCommand.cpp
  MCHIClient/Src/MCHICommand.cpp
)

add_library (MEIClient STATIC
  src/MEICommand.cpp
  src/MEIparser.cpp
  src/heci.cpp
  ${AMTHIClient}
  ${FWUpdateClient}
  ${HOTHAMClient}
  ${ManageabilityClient}
  ${MKHIClient}
  ${UPIDClient}
  ${PSRClient}
  ${MCHIClient}
)

set_target_properties (MEIClient PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries (MEIClient
  metee::metee
  $<$<BOOL:${WIN32}>:CfgMgr32.lib>
)

target_include_directories (MEIClient PUBLIC
  "Include/"
  "AMTHIClient/Include/"
  "FWUpdateClient/Include/"
  "HOTHAMClient/Include/"
  "ManageabilityClient/Include/"
  "MKHIClient/Include/"
  "UPIDClient/Include/"
  "PSRClient/Include/"
  "MCHIClient/Include/"
)
if (BUILD_TESTS)
  add_subdirectory ("AMTHITestProject" "AMTHITestProject")
endif (BUILD_TESTS)
