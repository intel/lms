/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: DataStorageGenerator.h

--*/
//----------------------------------------------------------------------------
//
//  Contents:   definition to the registry wrapper
//
//----------------------------------------------------------------------------

#ifndef _DATA_STORAGE_GENERATOR_H_
#define _DATA_STORAGE_GENERATOR_H_

#include "DataStorageWrapper.h"

#include "GMSCommonDllExport.h"

GMS_COMMON_EXPORT DataStorageWrapper& DSinstance();

//add a registry to the regMap in RegistryGenerator.cpp in the same line added here!
enum DATA_NAME : unsigned int
{
	IMSS_EVENT_HISTORY,
	GetUserInitiatedEnabled_F,
	GetKVMRedirectionState_F,
	CloseUserInitiatedConnection_F,
	GetIMSSEventHistory_F,
	GetAMTVersion_F,
	GetLMSVersion_F,
	GetHeciVersion_F,
	GetProvisioningState_F,
	GetNetworkConnectionStatus_F,
	userInitiatedPolicyRuleExists_F,
	snmpEventSubscriberExists_F,
	CILAFilterCollectionSubscriptionExists_F,
	GetPowerPolicy_F,
	GetLastResetReason_F,
	GetRedirectionStatus_F,
	GetSystemDefenseStatus_F,
	GetNetworkSettings_F,
	GetSystemUUID_F,
	GetIPv6NetworkSettings_F,
	SetSpriteLanguage_F,
	SetSpriteZoom_F,
	GetSpriteParameters_F,
	TerminateRemedySessions_F,
	GetAuditLogs_F,
	GetATDeviceInfo_F,
	GetTheFeatureState_F,
	GetCustomerType_F,
	GetMenageabiltyMode_F,
	GetConfigurationInfo_F,
	GetUserConsentState_F,
	GetWLANLinkInfo_F,
	SetLinkPreferenceToHost_F,
	GetFWInfo_F,
	InitiateUserConnection_F,
	LastLanguageUpdate,
	NETWORK_TRAFFIC_TX_CEASED_,
	ALLOW_FLASH_UPDATE,
	PARTIAL_FWU_IMAGE_PATH,
	AMT_ENABLE_S,
	SOL_ACTIVE_S,
	IDER_ACTIVE_S,
	KVM_ENABLE_S,
	KVM_SESSION_S,
	SYS_DEF_ACTIVE_S,
	AMT_PROVISIONING_STATE_S,
	ME_ENABLE_S,
	REMOTE_REBOOT_S,
	USER_CONSENT_S,
	CONTROL_MODE_S,
	EAC_ENABLE_S,
	IP_SYNC_ENABLE_S,
	UpdateScreenSettings_F,
	LINK_CONTROL_S,
	LINK_PROTECTION_S,
	GetRedirectionSessionLinkTechnology_F,
	TIME_SYNC_ENABLE_S,
	IsRebootAfterProvisioningNeeded_F,
	OverrideProsetAdapterSwitching,
	UserInitiatedPolicyRuleForLocalMpsExists_F,
	FLogSize,
	GetPMCVersion_F,
	WIFI_PROFILE_SYNC_ENABLE_S,
	LMSLoggingSeverity,
	RebootAfterProvsioningNeeded_S,
	IsMeasuredBootState_F,

	DATA_NAME_MAX_SENTINEL
};

#endif //_DATA_STORAGE_GENERATOR_H_