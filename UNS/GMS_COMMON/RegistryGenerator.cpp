/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#include "RegistryStorage.h"
#include "DataStorageGenerator.h"
#include "UNSRegistry.h"

static const LmsRegStr AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS(LMS_REG + LMS_REG_TEXT("credentials"));
static const LmsRegStr AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE(LMS_REG + LMS_REG_TEXT("AMT State"));
static const LmsRegStr AMT_REG_ENTRY_UNS_PREFIX_EVENT_HISTORY(LMS_REG + LMS_REG_TEXT("Event History"));
static const LmsRegStr AMT_REG_ENTRY_UNS_PREFIX_CONFIG_DATA(LMS_REG + LMS_REG_CONFIG_DATA);

std::shared_ptr<RegEntryMap> generateRegMap()
{
	//When adding to this regMap - add to the same place you added to the DataStorageGenerator.h!!!!
	std::shared_ptr<RegEntryMap> regMap(new RegEntryMap);
	regMap->resize(DATA_NAME_MAX_SENTINEL);
	regMap->at(IMSS_EVENT_HISTORY) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_EVENT_HISTORY,LMS_REG_TEXT("IMSS Event History"));
	regMap->at(GetUserInitiatedEnabled_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetUserInitiatedEnabled"));
	regMap->at(GetKVMRedirectionState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetKVMRedirectionState"));
	regMap->at(CloseUserInitiatedConnection_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("CloseUserInitiatedConnection"));
	regMap->at(GetIMSSEventHistory_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetIMSSEventHistory"));
	regMap->at(GetAMTVersion_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetAMTVersion"));
	regMap->at(GetLMSVersion_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetLMSVersion"));
	regMap->at(GetHeciVersion_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetHeciVersion"));
	regMap->at(GetProvisioningState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetProvisioningState"));
	regMap->at(GetNetworkConnectionStatus_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetNetworkConnectionStatus"));
	regMap->at(userInitiatedPolicyRuleExists_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("userInitiatedPolicyRuleExists"));
	regMap->at(snmpEventSubscriberExists_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("snmpEventSubscriberExists"));
	regMap->at(CILAFilterCollectionSubscriptionExists_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("CILAFilterCollectionSubscriptionExists"));
	regMap->at(GetPowerPolicy_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetPowerPolicy"));
	regMap->at(GetLastResetReason_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetLastResetReason"));
	regMap->at(GetRedirectionStatus_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetRedirectionStatus"));
	regMap->at(GetSystemDefenseStatus_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetSystemDefenseStatus"));
	regMap->at(GetNetworkSettings_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetNetworkSettings"));
	regMap->at(GetSystemUUID_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetSystemUUID"));
	regMap->at(GetIPv6NetworkSettings_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetIPv6NetworkSettings"));
	regMap->at(SetSpriteLanguage_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("SetSpriteLanguage"));
	regMap->at(SetSpriteZoom_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("SetSpriteZoom"));
	regMap->at(GetSpriteParameters_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetSpriteParameters"));
	regMap->at(TerminateRemedySessions_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("TerminateRemedySessions"));
	regMap->at(GetAuditLogs_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetAuditLogs"));
	regMap->at(GetTheFeatureState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetTheFeatureState"));
	regMap->at(GetCustomerType_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetCustomerType"));
	regMap->at(GetMenageabiltyMode_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetMenageabiltyMode"));
	regMap->at(GetConfigurationInfo_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetConfigurationInfo"));
	regMap->at(GetUserConsentState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetUserConsentState"));
	regMap->at(GetWLANLinkInfo_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetWLANLinkInfo"));
	regMap->at(SetLinkPreferenceToHost_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("SetLinkPreferenceToHost"));
	regMap->at(GetFWInfo_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetFWInfo"));
	regMap->at(InitiateUserConnection_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("InitiateUserConnection"));
	regMap->at(LastLanguageUpdate) = RegEntry(LMS_REG,LMS_REG_TEXT("LastLanguageUpdate"));
	regMap->at(NETWORK_TRAFFIC_TX_CEASED_) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CONFIG_DATA,LMS_REG_TEXT("NETWORK_TRAFFIC_TX_CEASED"));
	regMap->at(ALLOW_FLASH_UPDATE) = RegEntry(LMS_REG,LMS_REG_TEXT("AllowFlashUpdate"));
	regMap->at(PARTIAL_FWU_IMAGE_PATH) = RegEntry(LMS_REG,LMS_REG_TEXT("PartialFWUImagePath"));
	regMap->at(AMT_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("AMT Enable"));
	regMap->at(SOL_ACTIVE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("SOL ACTIVE"));
	regMap->at(IDER_ACTIVE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("IDER ACTIVE"));
	regMap->at(KVM_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("KVM ENABLE"));
	regMap->at(KVM_SESSION_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("KVM SESSION"));
	regMap->at(SYS_DEF_ACTIVE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("System Defence ACTIVE"));
	regMap->at(AMT_PROVISIONING_STATE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("AMT PROVISIONING STATE"));
	regMap->at(ME_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("ME Enable"));
	regMap->at(REMOTE_REBOOT_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("REMOTE REBOOT"));
	regMap->at(USER_CONSENT_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("USER CONSENT STATE"));
	regMap->at(CONTROL_MODE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("Control Mode"));
	regMap->at(EAC_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("EAC Enable"));
	regMap->at(IP_SYNC_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("IP SYNC ENABLE"));
	regMap->at(UpdateScreenSettings_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("UpdateScreenSettings"));
	regMap->at(LINK_CONTROL_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("Link Control"));
	regMap->at(LINK_PROTECTION_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("Link Protection"));
	regMap->at(GetRedirectionSessionLinkTechnology_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetRedirectionSessionLinkTechnology"));
	regMap->at(TIME_SYNC_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE,LMS_REG_TEXT("Time Sync Enable"));
	regMap->at(UserInitiatedPolicyRuleForLocalMpsExists_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("UserInitiatedPolicyRuleForLocalMpsExists"));
	regMap->at(FLogSize) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("FLogSize"));
	regMap->at(GetPMCVersion_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS,LMS_REG_TEXT("GetPMCVersion"));
	regMap->at(WIFI_PROFILE_SYNC_ENABLE_S) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_AMT_STATE, LMS_REG_TEXT("WIFI_PROFILE_SYNC_ENABLE"));
	regMap->at(LMSLoggingSeverity) = RegEntry(LMS_REG, LMS_REG_TEXT("LMSLoggingSeverity"));
	regMap->at(IsMeasuredBootState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("GetMeasuredBootState"));
	regMap->at(GetPlatformServiceRecord_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("GetPlatformServiceRecord"));
	regMap->at(GetPlatformServiceRecordRaw_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("GetPlatformServiceRecordRaw"));
	regMap->at(GetUPIDFeatureState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("GetUPIDFeatureState"));
	regMap->at(SetUPIDFeatureState_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("SetUPIDFeatureState"));
	regMap->at(SkuMgrQualifiedBrandEntitlements_F) = RegEntry(AMT_REG_ENTRY_UNS_PREFIX_CREDENTIALS, LMS_REG_TEXT("SkuMgrQualifiedBrandEntitlements"));
	//When adding to this regMap - add to the same place you added to the DataStorageGenerator.h!!!!
	return regMap;
}

std::shared_ptr<MajorSubKeysList> generateMajorSubKeys()
{
	std::shared_ptr<MajorSubKeysList> majorKeys(new MajorSubKeysList);
	majorKeys->push_back(LMS_REG);
	return majorKeys;
}



DataStorageWrapper& GenerateDS()
{
	static DataStorageWrapper ds(std::shared_ptr<DataStorageWrapperImpl>(new RegistryStorage(generateRegMap(), generateMajorSubKeys())));
	return ds;
}

DataStorageWrapper& DSinstance()
{
	return GenerateDS();
}

RegistryStorage::RegistryInitializer::RegistryInitializer() 
{
	GenerateDS();
}

RegistryStorage::RegistryInitializer RegistryStorage::RegistryInitializer::initializer;
