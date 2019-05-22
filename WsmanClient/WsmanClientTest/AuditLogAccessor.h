/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "gmock/gmock.h"
#include <sstream>
#include <iostream>
#include <string>
#include "AuditLogWSManClient.h"
#include <time.h>


class AuditLogAccessor : public ::testing::Test 
{
protected:

	AuditLogWSManClient m_auditLog;

	void formatTime0();

	std::string formatTime(time_t* time);
	std::string PrintOptInPolicy(uint8_t curData, char* title);
	std::string PrintUint32(uint8_t* extData, uint8_t extendedDataLen, char* message, int & i);
	std::string PrintUint16(uint8_t* extData, uint8_t extendedDataLen, char* message, int & i);
	std::string PrintInterfaceHandleUint32(uint8_t* extData, uint8_t extendedDataLen, int & i);
	std::string DisplayWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i);
	std::string DisplayBasicUsernameSidInformation(uint8_t* extData, uint8_t extendedDataLen, unsigned short numOfTabsToIdent, const char *action);
	std::string DisplayAuthenticationMode (int status);
	std::string DisplayAuthenticationStatus (int status);	
	std::string DisplayFirmwareVerion(uint8_t* extData, int i);
	std::string DisplayTimeStamp(uint8_t* extData);
	std::string DisplayFullWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i);
	std::string DisplayAgentID(uint8_t* extData);
	std::string DisplaySecurityAdminAmtProvisioningCompletedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminAclEntryAddedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminAclEntryModifiedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminAclEntryRemovedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminAclEntryEnabledEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminTlsStateChangedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminTlsCertificateRelatedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminKerberosSettingsModifiedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminPowerPackageModifiedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminSetRealmAuthenticationModeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAdminUnprovisioningCompleted(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayRemoteControlBootOptionsRelatedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayFirmwareUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayFirmwareUpdatedFailedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySecurityAuditLogRecoveryEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkTimeTimeSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminTcpIpParameterSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminHostNameSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminDomainNameSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminVlanParameterSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminLinkPolicySetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayNetworkAdminIPv6ParamsEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayStorageAdminGlobalStorageAttributesSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayEventManagerAlertRelatedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayEventLogFrozenEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayCircuitBreakerFilterRemovedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayCircuitBreakerPolicyRemovedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayCircuitBreakerDefaultPolicySetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayCircuitBreakerHeuristicsOptionSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayCircuitBreakerHeuristicsStateClearedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayAgentPresenceAgentWatchdogAddedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayAgentPresenceAgentWatchdogRemovedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayAgentPresenceAgentWatchdogActionSetEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWirelessProfileAddedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWirelessProfileRemovedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWirelessProfileUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWirelessProfileLinkPreferenceChanged(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWirelessProfileSyncChangeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayEacSetOptionsEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayOptInPolicyChangeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySendConsentCodeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayUnknownEvent(uint8_t* extData, uint8_t extendedDataLen);

	void ReverseMemCopy(void *dst, const void *src, size_t n);
};