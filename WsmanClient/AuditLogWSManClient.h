/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: AuditLogWSManClient.h

--*/

#ifndef  _AuditLogWSManClient_H
#define  _AuditLogWSManClient_H


#include "BaseWSManClient.h"
#include "AMT_AuditLog.h"
#include "CimUtils.h"
#include <vector>
#include <string>

#pragma pack(1)

struct HTTPDigestInitiatorType {
	HTTPDigestInitiatorType() : UsernameLength(0) {}
	uint8_t					UsernameLength;
	std::vector<uint8_t>	Username;
};
struct KerberosSIDInitiatorType {
	KerberosSIDInitiatorType() : UserInDomain(0), DomainLength(0) {}
	uint32_t				UserInDomain;
	uint8_t					DomainLength;
	std::vector<uint8_t>	Domain;
};

struct AuditLogRecord {
	AuditLogRecord() : AuditAppID(0), EventID(0), InitType(0), TimeStamp(0), MCLocationType(0),
		NetAddressLength(0), ExtendedDataLength(0) {}
	uint16_t					AuditAppID;
	uint16_t					EventID;
	uint8_t						InitType;
	HTTPDigestInitiatorType		DigestInitiatorData;
	KerberosSIDInitiatorType	KerberosInitiatorData;
	uint32_t					TimeStamp;
	uint8_t						MCLocationType;
	uint8_t						NetAddressLength;
	std::vector<uint8_t>		NetAddress;
	uint8_t						ExtendedDataLength;
	std::vector<uint8_t>		ExtendedData;
};
#pragma pack()

typedef std::vector<unsigned char> BinaryData;

class AuditLogWSManClient : public BaseWSManClient
{
public:
	AuditLogWSManClient(unsigned int port);
	virtual ~AuditLogWSManClient();

	bool readLogsFromFW(std::vector<Intel::Manageability::Cim::Utils::Base64> &records);
	bool Init(bool forceGet = false);
	bool AuditLogRecordFromBinaryBase64Data(BinaryData binaryRecord, AuditLogRecord &structedRecord);
	bool parseLogs (std::string &parsed, const std::vector<BinaryData> &unParsed);

private:
	void ReverseMemCopy(void *dst, const void *src, size_t n);
	void GetCharPtrFromUint8Vector(uint8_t length, std::vector<uint8_t> data, char* parsedData);
	std::string formatTime(time_t* time);
	std::string DisplayExtendedData(unsigned short appId, unsigned short eventId, std::vector<uint8_t> extendedData,
		uint8_t extendedDataLen);
	std::string PrintOptInPolicy(uint8_t curData, const char* title);
	std::string PrintUint32(uint8_t* extData, uint8_t extendedDataLen, const char* message, int & i);
	std::string PrintUint16(uint8_t* extData, uint8_t extendedDataLen, const char* message, int & i);
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
	std::string DisplayWirelessProfileUefiEnabledChangedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayEacSetOptionsEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayOptInPolicyChangeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplaySendConsentCodeEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayWatchdogActionPairingChangedEvent(uint8_t* extData, uint8_t extendedDataLen);
	std::string DisplayUnknownEvent(uint8_t* extData, uint8_t extendedDataLen);


	bool m_isInit;

	Intel::Manageability::Cim::Typed::AMT_AuditLog m_service;
	friend class AuditLogAccessor;
};
#endif //AuditLogWSManClient_H
