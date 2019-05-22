/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "AuditLogAccessor.h"

std::string AuditLogAccessor::formatTime(time_t* time)
{
	return m_auditLog.formatTime(time);
}

std::string AuditLogAccessor::PrintOptInPolicy(uint8_t curData, char* title)
{
	return m_auditLog.PrintOptInPolicy(curData, title);
}

std::string AuditLogAccessor::PrintUint32(uint8_t* extData, uint8_t extendedDataLen, char* message, int & i)
{
	return m_auditLog.PrintUint32(extData, extendedDataLen, message, i);
}

std::string AuditLogAccessor::PrintUint16(uint8_t* extData, uint8_t extendedDataLen, char* message, int & i)
{
	return m_auditLog.PrintUint16(extData, extendedDataLen, message, i);
}

std::string AuditLogAccessor::PrintInterfaceHandleUint32(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	return m_auditLog.PrintInterfaceHandleUint32(extData, extendedDataLen, i);
}

std::string AuditLogAccessor::DisplayWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	return m_auditLog.DisplayWirelessProfileName(extData, extendedDataLen, i);
}

std::string AuditLogAccessor::DisplayBasicUsernameSidInformation(uint8_t* extData, uint8_t extendedDataLen, unsigned short numOfTabsToIdent, const char *action)
{
	return m_auditLog.DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, action);
}

std::string AuditLogAccessor::DisplayAuthenticationMode(int status)
{
	return m_auditLog.DisplayAuthenticationMode(status);
}

std::string AuditLogAccessor::DisplayAuthenticationStatus(int status)
{
	return m_auditLog.DisplayAuthenticationStatus(status);
}

std::string AuditLogAccessor::DisplayFirmwareVerion(uint8_t* extData, int i)
{
	return m_auditLog.DisplayFirmwareVerion(extData, i);
}
	
std::string AuditLogAccessor::DisplayTimeStamp(uint8_t* extData)
{
	return m_auditLog.DisplayTimeStamp(extData);
}
	
std::string AuditLogAccessor::DisplayFullWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	return m_auditLog.DisplayFullWirelessProfileName(extData, extendedDataLen, i);
}
	
std::string AuditLogAccessor::DisplayAgentID(uint8_t* extData)
{
	return m_auditLog.DisplayAgentID(extData);
}

std::string AuditLogAccessor::DisplaySecurityAdminAmtProvisioningCompletedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
}
	
std::string AuditLogAccessor::DisplaySecurityAdminAclEntryAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAclEntryAddedEvent(extData, extendedDataLen);
}
	
std::string AuditLogAccessor::DisplaySecurityAdminAclEntryModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAclEntryModifiedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminAclEntryRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAclEntryRemovedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminAclEntryEnabledEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminAclEntryEnabledEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminTlsStateChangedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminTlsStateChangedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminTlsCertificateRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminTlsCertificateRelatedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminKerberosSettingsModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminKerberosSettingsModifiedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminPowerPackageModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminPowerPackageModifiedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminSetRealmAuthenticationModeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminSetRealmAuthenticationModeEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAdminUnprovisioningCompleted(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayRemoteControlBootOptionsRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayRemoteControlBootOptionsRelatedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayFirmwareUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayFirmwareUpdatedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayFirmwareUpdatedFailedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayFirmwareUpdatedFailedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySecurityAuditLogRecoveryEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySecurityAuditLogRecoveryEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkTimeTimeSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkTimeTimeSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminTcpIpParameterSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminHostNameSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminHostNameSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminDomainNameSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminDomainNameSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminVlanParameterSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminVlanParameterSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminLinkPolicySetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminLinkPolicySetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayNetworkAdminIPv6ParamsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayStorageAdminGlobalStorageAttributesSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayStorageAdminGlobalStorageAttributesSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayEventManagerAlertRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayEventLogFrozenEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayEventLogFrozenEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayCircuitBreakerFilterRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayCircuitBreakerFilterRemovedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayCircuitBreakerPolicyRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayCircuitBreakerPolicyRemovedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayCircuitBreakerDefaultPolicySetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayCircuitBreakerDefaultPolicySetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayCircuitBreakerHeuristicsOptionSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayCircuitBreakerHeuristicsOptionSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayCircuitBreakerHeuristicsStateClearedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayCircuitBreakerHeuristicsStateClearedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayAgentPresenceAgentWatchdogAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayAgentPresenceAgentWatchdogAddedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayAgentPresenceAgentWatchdogRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayAgentPresenceAgentWatchdogRemovedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayAgentPresenceAgentWatchdogActionSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayAgentPresenceAgentWatchdogActionSetEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayWirelessProfileAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayWirelessProfileAddedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayWirelessProfileRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayWirelessProfileRemovedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayWirelessProfileUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayWirelessProfileUpdatedEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayWirelessProfileLinkPreferenceChanged(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayWirelessProfileLinkPreferenceChanged(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayWirelessProfileSyncChangeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayWirelessProfileSyncChangeEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayEacSetOptionsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayEacSetOptionsEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayOptInPolicyChangeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayOptInPolicyChangeEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplaySendConsentCodeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplaySendConsentCodeEvent(extData, extendedDataLen);
}

std::string AuditLogAccessor::DisplayUnknownEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	return m_auditLog.DisplayUnknownEvent(extData, extendedDataLen);
}

void AuditLogAccessor::ReverseMemCopy(void *dst, const void *src, size_t n)
{
	return m_auditLog.ReverseMemCopy(dst, src, n);
}