/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: AuditLogWSManClient.cpp

--*/

#include "AuditLogWSManClient.h"
#include "AuditLogWSManClientConsts.h"
#include <time.h>
#include <iomanip>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

AuditLogWSManClient::AuditLogWSManClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

AuditLogWSManClient::~AuditLogWSManClient(){}

bool AuditLogWSManClient::readLogsFromFW(std::vector<Intel::Manageability::Cim::Utils::Base64> &records)
{
	try	
	{
		if (!Init(true))
			return false;

		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		namespace CimTyped = Intel::Manageability::Cim::Typed;
		CimTyped::AMT_AuditLog::ReadRecords_INPUT input;
		CimTyped::AMT_AuditLog::ReadRecords_OUTPUT output;
		// Read Records
		unsigned int recordsRead = 0;
		unsigned int totalRecordsCount;// = output.TotalRecordCount();
		do
		{
			input.StartIndex(recordsRead + 1);

			// Call SOAP Method.
			unsigned int response = m_service.ReadRecords(input, output);				

			// Check Return Value.
			if (response != 0)
			{
				WSMAN_ERROR("Error: Failed Getting Audit-Log records.\n");
				return false;
			}	
			if (!output.EventRecordsExists() || !output.TotalRecordCountExists())
			{
				WSMAN_DEBUG("No Audit-log records exist.\n");
				return true;
			}
	
			totalRecordsCount = output.TotalRecordCount();
			unsigned int outputSize = (unsigned int)output.EventRecords().size();
			// Insert Records to new vector
			for(unsigned int i=0; i<outputSize; i++)
			{
				records.push_back(CimTyped::Base64(output.EventRecords().at(i)));
			}
			// update number of records that were read 
			recordsRead += outputSize;
				
		}while(recordsRead < totalRecordsCount);			
	}
	CATCH_exception_return("AuditLogWSManClient::readLogsFromFW")
	return true;
}

bool AuditLogWSManClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit) return true;
	m_isInit = false;			

	try
	{
		if (!m_endpoint)
			SetEndpoint();

		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get(); 
		m_isInit = true;
	}
	CATCH_exception("AuditLogWSManClient::Init")
	return m_isInit;
}

bool AuditLogWSManClient::AuditLogRecordFromBinaryBase64Data( BinaryData binaryRecord,
										  AuditLogRecord &structedRecord)
{
	// Get Audit Records 
	try
	{
		unsigned char* recordPtr = binaryRecord.data();
		size_t recordLen = binaryRecord.size();
		
		if (recordLen < sizeof(structedRecord.AuditAppID))
			return false;
		ReverseMemCopy(&structedRecord.AuditAppID, recordPtr, sizeof(structedRecord.AuditAppID));
		recordPtr += sizeof(structedRecord.AuditAppID);
		recordLen -= sizeof(structedRecord.AuditAppID);
		
		if (recordLen < sizeof(structedRecord.EventID))
			return false;
		ReverseMemCopy(&structedRecord.EventID, recordPtr, sizeof(structedRecord.EventID));
		recordPtr += sizeof(structedRecord.EventID);
		recordLen -= sizeof(structedRecord.EventID);

		if (recordLen < sizeof(structedRecord.InitType))
			return false;
		ReverseMemCopy(&structedRecord.InitType, recordPtr, sizeof(structedRecord.InitType));
		recordPtr += sizeof(structedRecord.InitType);
		recordLen -= sizeof(structedRecord.InitType);

		switch(structedRecord.InitType)
		{
		case HTTP_DIGEST:
		{
			if (recordLen < sizeof(structedRecord.DigestInitiatorData.UsernameLength))
				return false;
			ReverseMemCopy(&structedRecord.DigestInitiatorData.UsernameLength, recordPtr, sizeof(structedRecord.DigestInitiatorData.UsernameLength));
			recordPtr += sizeof(structedRecord.DigestInitiatorData.UsernameLength);
			recordLen -= sizeof(structedRecord.DigestInitiatorData.UsernameLength);

			structedRecord.DigestInitiatorData.Username.clear();
			for (int i=0 ; i<structedRecord.DigestInitiatorData.UsernameLength ; i++)
			{
				if (recordLen < sizeof(uint8_t))
					return false;
				structedRecord.DigestInitiatorData.Username.push_back(*(reinterpret_cast<uint8_t*>(recordPtr)));
				recordPtr += sizeof(structedRecord.DigestInitiatorData.Username[i]);
				recordLen -= sizeof(structedRecord.DigestInitiatorData.Username[i]);
			}
		}
			break;
		case KERBEROS_SID:
		{
			if (recordLen < sizeof(structedRecord.KerberosInitiatorData.UserInDomain))
				return false;
			ReverseMemCopy(&structedRecord.KerberosInitiatorData.UserInDomain, recordPtr, sizeof(structedRecord.KerberosInitiatorData.UserInDomain));
			recordPtr += sizeof(structedRecord.KerberosInitiatorData.UserInDomain);
			recordLen -= sizeof(structedRecord.KerberosInitiatorData.UserInDomain);

			if (recordLen < sizeof(structedRecord.KerberosInitiatorData.DomainLength))
				return false;
			ReverseMemCopy(&structedRecord.KerberosInitiatorData.DomainLength, recordPtr, sizeof(structedRecord.KerberosInitiatorData.DomainLength));
			recordPtr += sizeof(structedRecord.KerberosInitiatorData.DomainLength);
			recordLen -= sizeof(structedRecord.KerberosInitiatorData.DomainLength);

			structedRecord.KerberosInitiatorData.Domain.clear();
			for (int i=0 ; i<structedRecord.KerberosInitiatorData.DomainLength ; i++)
			{
				if (recordLen < sizeof(uint8_t))
					return false;
				structedRecord.KerberosInitiatorData.Domain.push_back(*(reinterpret_cast<uint8_t*>(recordPtr)));
				recordPtr += sizeof(structedRecord.KerberosInitiatorData.Domain[i]);
				recordLen -= sizeof(structedRecord.KerberosInitiatorData.Domain[i]);
			}
		}
			break;
		case LOCAL_INITIATOR:
			break;
		default:
			break;
		}

		if (recordLen < sizeof(structedRecord.TimeStamp))
			return false;
		ReverseMemCopy(&structedRecord.TimeStamp, recordPtr, sizeof(structedRecord.TimeStamp));
		recordPtr += sizeof(structedRecord.TimeStamp);
		recordLen -= sizeof(structedRecord.TimeStamp);

		if (recordLen < sizeof(structedRecord.MCLocationType))
			return false;
		ReverseMemCopy(&structedRecord.MCLocationType, recordPtr, sizeof(structedRecord.MCLocationType));
		recordPtr += sizeof(structedRecord.MCLocationType);
		recordLen -= sizeof(structedRecord.MCLocationType);

		if (recordLen < sizeof(structedRecord.NetAddressLength))
			return false;
		ReverseMemCopy(&structedRecord.NetAddressLength, recordPtr, sizeof(structedRecord.NetAddressLength));
		recordPtr += sizeof(structedRecord.NetAddressLength);
		recordLen -= sizeof(structedRecord.NetAddressLength);

		structedRecord.NetAddress.clear();
		for (int i=0 ; i<structedRecord.NetAddressLength ; i++)
		{
			if (recordLen < sizeof(uint8_t))
				return false;
			structedRecord.NetAddress.push_back(*(reinterpret_cast<uint8_t*>(recordPtr)));
			recordPtr += sizeof(structedRecord.NetAddress[i]);
			recordLen -= sizeof(structedRecord.NetAddress[i]);
		}

		if (recordLen < sizeof(structedRecord.ExtendedDataLength))
			return false;
		ReverseMemCopy(&structedRecord.ExtendedDataLength, recordPtr, sizeof(structedRecord.ExtendedDataLength));
		recordPtr += sizeof(structedRecord.ExtendedDataLength);
		recordLen -= sizeof(structedRecord.ExtendedDataLength);

		structedRecord.ExtendedData.clear();
		for (int i=0 ; i<structedRecord.ExtendedDataLength ; i++)
		{
			if (recordLen < sizeof(uint8_t))
				return false;
			structedRecord.ExtendedData.push_back(*(reinterpret_cast<uint8_t*>(recordPtr)));
			recordPtr += sizeof(structedRecord.ExtendedData[i]);
			recordLen -= sizeof(structedRecord.ExtendedData);
		}
	}
	catch(...)
	{
		WSMAN_ERROR("Error occurs while trying to parse the record binary data!!!\n");
		return false;
	}
	return true;
}

void AuditLogWSManClient::ReverseMemCopy(void *dst, const void *src, size_t n)
{
  char *d, *s;
  size_t i;

  d = (char *) dst;
  s = (char *) src + n - 1;

  for (i=0; i<n; i++)
    *(d++) = *(s--);
}

void AuditLogWSManClient::GetCharPtrFromUint8Vector(uint8_t length, std::vector<uint8_t> data, char* parsedData)
{
	if (0==length)
	{
		parsedData[0] = '\0';
	}
	else
	{
		for (int i=0 ; i<(length-1) ; i++)
		{
			parsedData[i] = data[i];
		}
		parsedData[length-1] = '\0';
	}
}

bool AuditLogWSManClient::parseLogs(std::string &out, const std::vector<BinaryData> &records) 
{
	std::stringstream parsed;
	BinaryData* rec = NULL;
	std::vector<BinaryData>::const_iterator itr;
	AuditLogRecord structedRecord;
	
	bool res = false;
	char* netAddress = NULL;
	char* name = NULL;
	parsed << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<MsInfo>\n<Category name=\"Access Monitor Reporting\">\n";
	for(itr = records.begin(); itr != records.end(); itr++)
	{
		delete rec;
		try
		{
			rec = new BinaryData(*itr);
		}
		catch (std::bad_alloc&)
		{
			WSMAN_ERROR("Error: Can't Alloc memory.\n");
			goto EXIT;
		}

		if (false == AuditLogRecordFromBinaryBase64Data(*rec, structedRecord))
		{
			WSMAN_ERROR("Error occur while parsing audit log record from binary base 64!\n");
			parsed << "<Data><Application><![CDATA[ERROR]]></Application><Event><![CDATA[NA]]></Event><InitiatorType><![CDATA[]]></InitiatorType><InitiatorData><![CDATA[]]></InitiatorData><Time><![CDATA[]]></Time><InitiatorNetAddress><![CDATA[]]></InitiatorNetAddress><ExtendedData><![CDATA[]]></ExtendedData></Data>";
			continue;
		}

		std::string eventIdString = "";
		std::string appIdString = "";

		if ((structedRecord.AuditAppID >= APP_ID_START_INDEX)&&
			    (structedRecord.AuditAppID <= APP_ID_END_INDEX))
		{
			appIdString = appIdStrings[structedRecord.AuditAppID - APP_ID_START_INDEX];

			//Check if the event ID is in the legal range
			if (structedRecord.EventID < endStringsArrayIndices[structedRecord.AuditAppID - APP_ID_START_INDEX])
			{
				unsigned int startIndex = 0;
				for (unsigned int i =  0; i < (structedRecord.AuditAppID - APP_ID_START_INDEX); i++)
				{
					startIndex += endStringsArrayIndices[i];
				}
				if ((startIndex + structedRecord.EventID) < (sizeof(eventIdStrings) / sizeof(eventIdStrings[0])))
				{
					eventIdString = eventIdStrings[startIndex + structedRecord.EventID];
				}
				else
				{
					eventIdString = "Unknown";
				}
			}
			else
			{
				eventIdString = "Unknown";
			}
		}
		else
		{
			eventIdString = "Unknown";
			appIdString = "Unknown";
		}

		parsed << "<Data>\n<Application><![CDATA[" << appIdString <<
			"]]></Application>\n<Event><![CDATA[" << eventIdString <<
			"]]></Event>\n<Initiator><![CDATA[";

		switch(structedRecord.InitType)
		{
		case HTTP_DIGEST:
			
			if (NULL != name)
			{
				delete[] name;
				name = NULL;
			}

			try
			{
				name = new char[structedRecord.DigestInitiatorData.UsernameLength+1];
			}
			catch (std::bad_alloc&)
			{
				WSMAN_ERROR("Error: Can't Alloc memory.\n");
				goto EXIT;
			}

			GetCharPtrFromUint8Vector(structedRecord.DigestInitiatorData.UsernameLength+1, structedRecord.DigestInitiatorData.Username, name);

			parsed << name;

			break;
		case KERBEROS_SID:
			parsed << std::hex << std::uppercase;

			for (unsigned int i=1 ; i<=sizeof(uint32_t) ; i++)
			{
				parsed << (int)((uint8_t*)(&structedRecord.KerberosInitiatorData.UserInDomain))[sizeof(uint32_t)-i] << " ";
			}
			parsed << std::dec << std::nouppercase;
			if (NULL != name)
			{
				delete[] name;
				name = NULL;
			}

			try
			{
				name = new char[structedRecord.KerberosInitiatorData.DomainLength];
			}
			catch (std::bad_alloc&)
			{
				WSMAN_ERROR("Error: Can't Alloc memory.\n");
				goto EXIT;
			}

			// Display domain data to screen
			parsed << std::hex << std::uppercase;
			for (unsigned int i=0 ; (i<structedRecord.KerberosInitiatorData.Domain.size()) && 
									(i<structedRecord.KerberosInitiatorData.DomainLength); i++)
			{
				parsed << (int)structedRecord.KerberosInitiatorData.Domain[i] << " ";
			}
			parsed << std::dec << std::nouppercase;

			break;
		case LOCAL_INITIATOR:
			parsed << "Local user";
			break;
		case KVM_DEFAULT_PORT:
			parsed << "KVM user";
			break;
		default:
			WSMAN_ERROR("Unknown InitiatorType\n");
			parsed << "Unknown";
			break;
		}

		time_t timeStamp = structedRecord.TimeStamp;

		parsed << "]]></Initiator>\n<Time><![CDATA[" << 
			formatTime (&timeStamp) << "]]></Time>\n<InitiatorNetAddress><![CDATA[";

		if (NULL != netAddress)
		{
			delete[] netAddress;
			netAddress = NULL;
		}

		try
		{
			netAddress = new char[structedRecord.NetAddressLength+1];
		}
		catch (std::bad_alloc&)
		{
			WSMAN_ERROR("Error: Can't Alloc memory.\n");
			goto EXIT;
		}

		GetCharPtrFromUint8Vector(structedRecord.NetAddressLength+1, structedRecord.NetAddress, netAddress);

		switch(structedRecord.MCLocationType)
		{
		case IPV4_ADDR:
			parsed << netAddress;
			break;
		case IPV6_ADDR:
			parsed << netAddress;
			break;
		case NON:
			WSMAN_DEBUG("None net Address\n");
			break;
		default:
			break;
		}
		
		// Display Extended Data
		parsed << "]]></InitiatorNetAddress>\n<ExtendedData><![CDATA[";
		try
		{
			parsed << DisplayExtendedData(structedRecord.AuditAppID, 
				structedRecord.EventID, structedRecord.ExtendedData, 
				structedRecord.ExtendedDataLength) ;
		}
		catch(std::exception &e)
		{
			const char* reason =  e.what();
			WSMAN_DEBUG("%C\n", reason);
			parsed << "Exception while parsing extended data"; 
		}
		parsed << "]]></ExtendedData>\n</Data>\n";
	}
	parsed << "</Category>\n</MsInfo>\n";
	out = parsed.str();
	res = true;
/* Clean Up Code */
EXIT:

	if (NULL != name)
	{
		delete[] name;
	}
	if (NULL != netAddress)
	{
		delete[] netAddress;
	}
	if (NULL != rec)
	{
		delete rec;
	}
	return res;
}

std::string
AuditLogWSManClient::formatTime(time_t* time)
{
	std::stringstream ss;
	if (time == NULL) 
		return ss.str();
	tm *gmt = gmtime(time);
	if (gmt == NULL)
		return ss.str();
	ss << (gmt->tm_mon+1) << "/" << (gmt->tm_mday) << "/" << (gmt->tm_year+1900) << " ";
	ss << std::setfill('0') << std::setw(2) << gmt->tm_hour << ":" << std::setw(2) << 
		gmt->tm_min << ":" << std::setw(2) << gmt->tm_sec; //<< " UTC";
	return ss.str();
}

std::string AuditLogWSManClient::DisplayExtendedData(unsigned short appId, unsigned short eventId, std::vector<uint8_t> extendedData,
						 uint8_t extendedDataLen)
{
	// Check if we have Extended Data.
	if (extendedDataLen == 0 || extendedDataLen != extendedData.size())
	{
		return std::string("");
	}
	
	std::stringstream s;
	
	switch(appId)
	{
	case SECURITY_ADMIN_APPID:
		switch(eventId)
		{
		case AMT_PROVISIONING_COMPLETED: 
			s << DisplaySecurityAdminAmtProvisioningCompletedEvent(extendedData.data(), extendedDataLen);
			break;
		case ACL_ENTRY_ADDED:
			s << DisplaySecurityAdminAclEntryAddedEvent(extendedData.data(), extendedDataLen);
			break;
		case ACL_ENTRY_MODIFIED:
			s << DisplaySecurityAdminAclEntryModifiedEvent(extendedData.data(), extendedDataLen);
			break;	
		case ACL_ENTRY_REMOVED:
			s << DisplaySecurityAdminAclEntryRemovedEvent(extendedData.data(), extendedDataLen);
			break;
		case ACL_ACCESS_WITH_INVALID_CREDENTIALS:
			s << DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(extendedData.data(), extendedDataLen);
			break;	
		case ACL_ENTRY_ENABLED:
			s << DisplaySecurityAdminAclEntryEnabledEvent(extendedData.data(), extendedDataLen);
			break;
		case TLS_STATE_CHANGED:
			s << DisplaySecurityAdminTlsStateChangedEvent(extendedData.data(), extendedDataLen);
			break;
		case TLS_SERVER_CERTIFICATE_SET:
		case TLS_SERVER_CERTIFICATE_REMOVE:
		case TLS_TRUSTED_ROOT_CERTIFICATE_ADDED:
		case TLS_TRUSTED_ROOT_CERTIFICATE_REMOVED:
			s << DisplaySecurityAdminTlsCertificateRelatedEvent(extendedData.data(), extendedDataLen);
			break;
		case KERBEROS_SETTINGS_MODIFIED:
			s << DisplaySecurityAdminKerberosSettingsModifiedEvent(extendedData.data(), extendedDataLen);
			break;
		case POWER_PACKAGE_MODIFIED:
			s << DisplaySecurityAdminPowerPackageModifiedEvent(extendedData.data(), extendedDataLen);
			break;
		case SET_REALM_AUTHENTICATION_MODE:
			s << DisplaySecurityAdminSetRealmAuthenticationModeEvent(extendedData.data(), extendedDataLen);
			break;
		case UNPROVISIONING_COMPLETED:
			s << DisplaySecurityAdminUnprovisioningCompleted(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case RCO_APPID:
		switch(eventId)
		{
		case PERFORMED_POWER_UP:
		case PERFORMED_POWER_CYCLE:
		case PERFORMED_RESET:
		case SET_BOOT_OPTIONS:
			s << DisplayRemoteControlBootOptionsRelatedEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case FIRMWARE_UPDATE_MANAGER_APPID:
		switch(eventId)
		{
		case FIRMWARE_UPDATED:
			s << DisplayFirmwareUpdatedEvent(extendedData.data(), extendedDataLen);
			break;
		case FIRMWARE_UPDATED_FAILED:
			s << DisplayFirmwareUpdatedFailedEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case SECURITY_AUDIT_LOG_APPID:
		switch(eventId)
		{
		case AUDIT_LOG_RECOVERY:
			s << DisplaySecurityAuditLogRecoveryEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case NETWORK_TIME_APPID:
		switch(eventId)
		{
		case AMT_TIME_SET:
			s << DisplayNetworkTimeTimeSetEvent(extendedData.data(), extendedDataLen);
			break;
		}		
		break;
	case NETWORK_ADMIN_APPID:
		switch(eventId)
		{
		case TCPIP_PARAMETERS_SET:
			s << DisplayNetworkAdminTcpIpParameterSetEvent(extendedData.data(), extendedDataLen);
			break;
		case HOST_NAME_SET:
			s << DisplayNetworkAdminHostNameSetEvent(extendedData.data(), extendedDataLen);
			break;
		case DOMAIN_NAME_SET:
			s << DisplayNetworkAdminDomainNameSetEvent(extendedData.data(), extendedDataLen);
			break;
		case VLAN_PARAMETERS_SET:
			// Deprecated
			break;
		case LINK_POLICY_SET:
			s << DisplayNetworkAdminLinkPolicySetEvent(extendedData.data(), extendedDataLen);
			break;
		case IPV6_PARAMS_SET:
			s << DisplayNetworkAdminIPv6ParamsEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case STORAGE_ADMIN_APPID:
		switch(eventId)
		{
		case GLOBAL_STORAGE_ATTRIBUTES_SET:
			s << DisplayStorageAdminGlobalStorageAttributesSetEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case EVENT_MANAGER_APPID:
		switch(eventId)
		{
		case ALERT_SUBSCRIBED:
		case ALERT_UNSUBSCRIBED:
			s << DisplayEventManagerAlertRelatedEvent(extendedData.data(), extendedDataLen);
			break;
		case EVENT_LOG_FROZEN:
			s << DisplayEventLogFrozenEvent(extendedData.data(), extendedDataLen);
		}
		break;
	case CB_MANAGER_APPID:
		switch(eventId)
		{
		case CB_FILTER_REMOVE:
			s << DisplayCircuitBreakerFilterRemovedEvent(extendedData.data(), extendedDataLen);
			break;
		case CB_POLICY_REMOVE:
			s << DisplayCircuitBreakerPolicyRemovedEvent(extendedData.data(), extendedDataLen);
			break;
		case CB_DEFAULT_POLICY_SET:
			s << DisplayCircuitBreakerDefaultPolicySetEvent(extendedData.data(), extendedDataLen);
			break;
		case CB_HEURISTICS_OPTION_SET:
			s << DisplayCircuitBreakerHeuristicsOptionSetEvent(extendedData.data(), extendedDataLen);
			break;
		case CB_HEURISTICS_STATE_CLEARED:
			s << DisplayCircuitBreakerHeuristicsStateClearedEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case AGENT_PRESENCE_MANAGER_APPID:
		switch(eventId)
		{
		case AGENT_WATCHDOG_ADDED:
			s << DisplayAgentPresenceAgentWatchdogAddedEvent(extendedData.data(), extendedDataLen);
			break;
		case AGENT_WATCHDOG_REMOVED:
			s << DisplayAgentPresenceAgentWatchdogRemovedEvent(extendedData.data(), extendedDataLen);
			break;
		case AGENT_WATCHDOG_ACTION_SET:
			s << DisplayAgentPresenceAgentWatchdogActionSetEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case WIRELESS_CONFIG_APPID:
		switch(eventId)
		{
		case WIRELESS_PROFILE_ADDED:
			s << DisplayWirelessProfileAddedEvent(extendedData.data(), extendedDataLen);
			break;
		case WIRELESS_PROFILE_REMOVED:
			s << DisplayWirelessProfileRemovedEvent(extendedData.data(), extendedDataLen);
			break;
		case WIRELESS_PROFILE_UPDATED:
			s << DisplayWirelessProfileUpdatedEvent(extendedData.data(), extendedDataLen);
			break;
		case WIRELESS_PROFILE_SYNC: 
			s << DisplayWirelessProfileSyncChangeEvent(extendedData.data(), extendedDataLen);
			break; 
		case WIRELESS_LINK_PREFERENCE_CHANGED: 
			s << DisplayWirelessProfileLinkPreferenceChanged(extendedData.data(), extendedDataLen);
			break;
		case WIRELESS_UEFI_PROFILE_SYNC:
			s << DisplayWirelessProfileUefiEnabledChangedEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case EAC_APPID:
		switch(eventId)
		{
		case EAC_SET_OPTIONS:
			s << DisplayEacSetOptionsEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;
	case KVM_APPID:
		// Event has no parameters to display.
		break;
	case USER_OPT_IN_APPID:
		switch(eventId)
		{
		case OPT_IN_POLICY_CHANGE:
			s << DisplayOptInPolicyChangeEvent(extendedData.data(), extendedDataLen);
			break;
		case SEND_CONSENT_CODE_EVENT:
			s << DisplaySendConsentCodeEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;

	case BIOS_MANAGEMENT_APPID:
		break;
	case SCREEN_BLANKING:
		break;
	case WATCHDOG_APPID:
		switch(eventId)
		{
		case WEI_WATCHDOG_ACTION_PAIRING_CHANGED:
			s << DisplayWatchdogActionPairingChangedEvent(extendedData.data(), extendedDataLen);
			break;
		}
		break;

	default: /* Unknown Event */
		s << DisplayUnknownEvent(extendedData.data(), extendedDataLen);
		break;
	}

	return s.str();
}

std::string AuditLogWSManClient::PrintUint32(uint8_t* extData, uint8_t extendedDataLen, const char* message, int & i)
{
	std::stringstream ss;
	ss << "";
	uint32_t* pvalue = NULL;
	
	try
	{
		pvalue = new uint32_t();
	}
	catch (std::bad_alloc&)
	{
		return ss.str();
	}
	if ((i+sizeof(uint32_t))<=extendedDataLen)
	{
		ReverseMemCopy(pvalue, extData+i, sizeof(uint32_t));
		ss << message << ": " << *pvalue << " ";
		i+=sizeof(uint32_t);
	}
	delete pvalue;
	return ss.str();
}

/*****************************************************************************
 * Function that prints the data in Uint16 format. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 *  message				- Data title.
 *  i					- Spaces number.
 ****************************************************************************/
std::string AuditLogWSManClient::PrintUint16(uint8_t* extData, uint8_t extendedDataLen, const char* message, int & i)
{
	std::stringstream ss ("");
	uint16_t* pvalue = NULL;
	try
	{
		pvalue = new uint16_t();
	}
	catch (std::bad_alloc&)
	{
		return ss.str();
	}
	if ((i+sizeof(uint16_t))<=extendedDataLen)
	{
		ReverseMemCopy(pvalue, extData+i, sizeof(uint16_t));
		ss << message << ": " << *pvalue << " ";
		i+=sizeof(uint16_t);
	}
	delete pvalue;
	return ss.str();
}

/*****************************************************************************
 * Function that prints the Interface Handle in Uint32 format. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 *  i					- Spaces number.
 ****************************************************************************/
std::string AuditLogWSManClient::PrintInterfaceHandleUint32(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	std::stringstream ss;
	uint32_t* pvalue = NULL;
	try
	{
		pvalue = new uint32_t();
	}
	catch (std::bad_alloc&)
	{
		return ss.str();
	}
	if ((i+sizeof(uint32_t))<=extendedDataLen)
	{
		ReverseMemCopy(pvalue, extData+i, sizeof(uint32_t));
		switch(*pvalue)
		{
		case 0:
			ss << "LAN";
			break;
		case 1:
			ss << "WLAN";
			break;
		default:
			ss << "Unknown";
			break;
		}
		i+=sizeof(uint32_t);
	}
	delete pvalue;
	//ss << " ";
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin AMT provisioning completed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAmtProvisioningCompletedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	int provisioningMethod = 0;
	int hashType = 0;
	int numberOfCerts = 0;
	int provServFqdnLength = 0;

	if (i<extendedDataLen)
	{
		ss << "Provisioning Method: ";
		switch((unsigned int)extData[i])
		{
		case PSK:
			ss << PSK_STRING << ". ";
			break;
		case PKI:
			ss << PKI_STRING << ". ";
			break;
		case MANUAL_PROVISIONING:
			ss << MANUAL_STRING << ". ";
			break;
		case ACM:
			ss << ACM_STRING << ". ";
			break;
		case DAL_PROVISIONING:
			ss << DAL_STRING << ". ";
			break;
		default:
			ss << "Unknown. (" << (unsigned int)extData[i] << ")";
			break;
		}
		provisioningMethod = extData[i];
		i++;
	}

	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			hashType = extData[i];
	/*		ss << "Hash Type = " << (unsigned int)extData[i] << "(";			
			switch(hashType)
			{
			case SHA1_160:
				ss << "SHA1_160";
				break;
			case SHA2_256:
				ss << "SHA2_256";
				break;
			case SHA2_384:
				ss << "SHA2_384";
				break;
			case SHA2_512:
				ss << "SHA2_512";
				break;
			}
			ss << ") ";
	*/		i++;
		}
	}

	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			if ((SHA1_160 == hashType) || (SHA2_256 == hashType) || (SHA2_384 == hashType) || (SHA2_512 == hashType))
			{

				unsigned short hashLength = 0;
				switch(hashType)
				{
				case SHA1_160:
					hashLength =  TRUSTED_ROOT_CERT_SHA1_160_HASH_LEN;
					break;
				case SHA2_256:
					hashLength =  TRUSTED_ROOT_CERT_SHA2_256_HASH_LEN;
					break;
				case SHA2_384:
					hashLength =  TRUSTED_ROOT_CERT_SHA2_384_HASH_LEN;
					break;
				case SHA2_512:
					hashLength =  TRUSTED_ROOT_CERT_SHA2_512_HASH_LEN;
					break;
				}

				//ss << hex << uppercase;
				for (int j=0 ; (j<hashLength) && (i<extendedDataLen); j++)
				{
				//	ss << (int)extData[i] << " ";
					i++;
				}
				//ss << dec << nouppercase;
			}
		}
	}
				
	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			numberOfCerts = extData[i];
			i++;
		}
	}
	
	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			for (int j=0 ; j <numberOfCerts ; j++)
			{
				for (int x=0 ; (x<CERT_SERIAL_NUM_LEN) && (i<extendedDataLen); x++)
				{

					i++;
				}

			}
		}
	}

	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			i++;
		}
	}

	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			provServFqdnLength =  extData[i];
			i++;
		}
	}
	
	if (i<extendedDataLen)
	{
		if (PKI == provisioningMethod)
		{
			ss << "Provisioning Server FQDN: ";
			for (int j=0 ; (extData[i]!=0) && (j<provServFqdnLength) && (i<extendedDataLen) ; j++)
			{
				ss << (char)extData[i];
				i++;
			}
			ss  << ". ";
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the basic user name SID information. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 *  numOfTabsToIdent	- Number of tabs for indentation.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayBasicUsernameSidInformation(uint8_t* extData, uint8_t extendedDataLen, unsigned short numOfTabsToIdent, const char *action)
{
	std::stringstream ss;
	int i = 0;
	int initiatorType = 0;
	int length = 0;

	if (i<extendedDataLen)
	{
		initiatorType = extData[i];
		i++;
	}

	ss << action << "user: ";

	if (i<extendedDataLen)
	{
		if (HTTP_DIGEST == initiatorType) 
		{
			length = extData[i];
		}
		else 
		if (KERBEROS_SID == initiatorType)
		{
			ss << "SID";
			ss << ":" << std::hex << std::uppercase;

			for (size_t j=0 ; (j<sizeof(uint32_t)) && (i<extendedDataLen) ; j++)
			{
				ss << " " << (int)extData[i];
				i++;
			}
			ss << std::dec << std::nouppercase << ". ";
			
			if ( i < extendedDataLen)
			{
				length = extData[i];
			}
		}
		i++;
	}

	if (i<extendedDataLen)
	{
		if (HTTP_DIGEST == initiatorType)
		{
			ss << "Username: ";
			for (int j = 0; (extData[i]!=0) && (j<length) && (i<extendedDataLen) ; i++, j++)
			{
				ss << (char)extData[i];
			}
			ss << ". ";
		} 
		else if (KERBEROS_SID == initiatorType)
		{
			ss << "Domain:" << std::hex << std::uppercase;
			for (int j=0 ; (j<length) && (i<extendedDataLen) ; i++, j++)
			{
				ss << " " <<  (int)extData[i];
			}
			ss << std::dec << std::nouppercase << ". ";
		}		
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin ACL entry added event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAclEntryAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	const char *action = "Added ";
	ss << DisplayBasicUsernameSidInformation(extData, extendedDataLen, 1, action);
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin ACL entry modified event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAclEntryModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss, temp;
	uint8_t i =0;
	if (i < extendedDataLen)
	{

		temp << "Modified fields:";
		temp << " Username="	 <<     (((extData[i] & 0x1) != 0) ? "true" : "false");
		temp << ", Password="     <<	(((extData[i] & 0x2) != 0) ? "true" : "false");
		temp << ", Local realms="   <<  (((extData[i] & 0x4) != 0) ? "true" : "false");
		temp << ", Remote realms="  <<  (((extData[i] & 0x8) != 0) ? "true" : "false");
		temp << ", Kerberos domain=" << (((extData[i] & 0x10) != 0) ? "true" : "false");
		temp << ", SID="		<<		(((extData[i] & 0x20) != 0) ? "true" : "false");
		i++;
	}
	
	if (i < extendedDataLen)
	{
		ss << DisplayBasicUsernameSidInformation(extData+i, extendedDataLen-i, 2, "Modified ");
	}
	ss << temp.str();
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin ACL entry removed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAclEntryRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	ss << DisplayBasicUsernameSidInformation(extData, extendedDataLen, 1, "Removed ");
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin ACL access with invalid credentials event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		ss << "Invalid access from: ";
		switch(extData[0])
		{
		case AMT_TYPE:
			ss << AMT_TYPE_STRING;
			break;
		case MEBX_TYPE:
			ss << MEBX_TYPE_STRING;
			break;
		default:
			ss << "Unknown";
			break;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin ACL entry enabled event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminAclEntryEnabledEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	uint8_t i =0;
	if (i < extendedDataLen)
	{
		ss << (extData[i] ? "Enabled" : "Disabled") << " ";
		i++;
	}
	
	if (i < extendedDataLen)
	{
		ss << DisplayBasicUsernameSidInformation(extData+i, extendedDataLen-i, 1, "");
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the authentication mode. 
 * Arguments:
 *  status		- Mode of authentication.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAuthenticationMode (int status)
{
	std::stringstream ss;
	if (NO_AUTHENTICATION == status)
	{
		ss << NO_AUTHENTICATION_STRING;
	} 
	else if (AUTHENTICATION == status)
	{
		ss << AUTHENTICATION_STRING;
	}
	else if (DISABLE == status)
	{
		ss << "Disable";
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the authentication status. 
 * Arguments:
 *  status		- Status of authentication.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAuthenticationStatus (int status)
{
	std::stringstream ss;
	if (NO_AUTHEN == status)
	{
		ss << NO_AUTHENTICATION_STRING;
	} 
	else if (SERVER_AUTHENTICATION == status)
	{
		ss << SERVER_AUTHENTICATION_STRING;
	}
	else if (MUTUAL_AUTHENTICATION == status)
	{
		ss << MUTUAL_AUTHENTICATION_STRING;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin TLS state changed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminTlsStateChangedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i =0;

	if (i < extendedDataLen)
	{
		ss << "Remote TLS State: " << DisplayAuthenticationStatus(extData[i]);
		i++;
	}
	
	if (i < extendedDataLen)
	{
		ss << ", Local TLS State: " << DisplayAuthenticationStatus(extData[i]) ;
		i++;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin TLS certificate related event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminTlsCertificateRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	if (i<extendedDataLen)
	{
		ss << "Certificate Serial Number: " << std::hex << std::uppercase;
		for (int x=0 ; (x<CERT_SERIAL_NUM_MAX_LEN) && (i<extendedDataLen); x++)
		{
			ss << (int)extData[i] << " ";
			i++;
		}
		ss << std::dec << std::nouppercase;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin kerberos settings modified event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminKerberosSettingsModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		ss << "Time Tolerance: " << (unsigned int)extData[0] << " minute(s)";
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin power package modified event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminPowerPackageModifiedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	ss << "Power Package Modified to: ";
	std::stringstream data;
	data << std::hex << std::uppercase << std::setfill('0');
	for (uint8_t k = 0; k < 16 && k < extendedDataLen; k++)
	{
		data << std::setw(2) << (int)extData[k];
	}
	data << std::dec << std::nouppercase;
	for (int k=0; k<12; k++)
	{
		if (data.str().compare(powerPolicyFW[k]) == 0)
		{
			ss << powerPolicyStrings[k];
			return ss.str();
		}
	}
	ss << "Unknown";
	return ss.str();
}

/*****************************************************************************
 * Function that displays the security admin set realm authentication mode event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminSetRealmAuthenticationModeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i=0;
	
	if (i < extendedDataLen)
	{
		uint32_t* pvalue = NULL;
		try
		{
			pvalue = new uint32_t();
		}
		catch (std::bad_alloc&)
		{
			return ss.str();
		}
		if ((i+sizeof(uint32_t))<=extendedDataLen)
		{
			ReverseMemCopy(pvalue, extData+i, sizeof(uint32_t));
			ss << (((*pvalue)>MAX_REALM)?"UnknownRealm":realmsStrings[*pvalue].c_str());
			i+=sizeof(uint32_t);
		}
		delete pvalue;
	}

	if (i < extendedDataLen)
	{
		ss << ", Authentication mode: " << DisplayAuthenticationMode(extData[i]);
		i++;
	}
	return ss.str();
}
/*****************************************************************************
 * Function that displays the security admin Unprovisioning mode event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAdminUnprovisioningCompleted(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;

	if (extendedDataLen == 1)
	{		
		switch(extData[0])
		{
			case 1:
				ss << "BIOS";		
				break;
			case 2:
				ss << "MEBx";
				break;
			case 3:
				ss << "Local MEI";
				break;
			case 4:
				ss << "Local WSMAN/SOAP";
				break;			
			case 5:
				ss << "Remote WSMAN/SOAP";
				break;
		}
	}
		
	return ss.str();
}

/*****************************************************************************
 * Function that displays the remote control boot options related event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayRemoteControlBootOptionsRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i=0;
	if (i<extendedDataLen)
	{
		ss << "Boot Options: " << std::hex << std::uppercase;
		for (int x=0 ; (x<BOOT_OPTIONS_LEN) && (i<extendedDataLen); x++)
		{
			ss << (int)extData[i] << " ";
			i++;
		}
		ss << std::dec << std::nouppercase;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the firmware version.
 * Arguments:
 *  extData				- Extended data.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayFirmwareVerion(uint8_t* extData, int i)
{
	std::stringstream ss;
	uint16_t* tmp = NULL;

	try
	{
		tmp = new uint16_t();
	}
	catch (std::bad_alloc&)
	{
		return ss.str();
	}
	for (int j =0; j < 4; j++, i+=sizeof(uint16_t)) 
	{
		ReverseMemCopy(tmp, extData+(i*sizeof(uint8_t)), sizeof(uint16_t));
		ss << (unsigned int)*tmp << ".";
	}
	delete tmp;
	return ss.str();
}

/*****************************************************************************
 * Function that displays the firmware updated event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayFirmwareUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i =0;

	if (i < extendedDataLen)
	{
		ss << "Old FW Version: ";
		if ((i+(FW_VERSION_NUM_OF_FIELDS*2*sizeof(uint8_t)))<=extendedDataLen)
		{
			ss << DisplayFirmwareVerion(extData, i);
			i+=(FW_VERSION_NUM_OF_FIELDS*2*sizeof(uint8_t));
		}
	}
	if (i < extendedDataLen)
	{
		ss << " New FW Version: ";
		if ((i+(FW_VERSION_NUM_OF_FIELDS*2*sizeof(uint8_t)))<=extendedDataLen)
		{
			ss << DisplayFirmwareVerion(extData, i);
			i+=(FW_VERSION_NUM_OF_FIELDS*2*sizeof(uint8_t));
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the firmware updated failed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayFirmwareUpdatedFailedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	int i =0;
	if (i < extendedDataLen)
	{
		return PrintUint32(extData, extendedDataLen, "Failure Reason", i);
	}
	return std::string("");
}

/*****************************************************************************
 * Function that displays the security audit log recovery event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySecurityAuditLogRecoveryEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		ss << "Reason: " << 
			((((unsigned int)(extData[0]))>MAX_SECURITY_AUDIT_RECOVERY_REASON) ? 
			"Unknown" :	securityAuditLogRecoveryReason[extData[0]].c_str());
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the time stamp. 
 * Arguments:
 *  extData				- Extended data.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayTimeStamp(uint8_t* extData)
{
	std::stringstream ss;
	time_t* time = NULL;
	try
	{
		time = new time_t();
	}
	catch (std::bad_alloc&)
	{
		return ss.str();
	}
	ReverseMemCopy(time, extData, sizeof(unsigned int));
	ss <<  formatTime(time);
	delete time;
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network time time set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkTimeTimeSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen >= sizeof(unsigned int))
	{
		ss << "Intel(R) AMT Time: " << DisplayTimeStamp(extData);
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network admin TCP/IP parameter set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkAdminTcpIpParameterSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	bool DHCPenabled = false;

	if (i < extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i) << ". ";
	}

	if (i < extendedDataLen)
	{
		DHCPenabled = ((int)extData[i] != 0);
		ss << "DHCP Enabled: " << (extData[i]?"Enabled":"Disabled") << ". ";
		i++;
	}

	if (!DHCPenabled)
	{
		std::string addresses[] = { "IPv4 Address: ", "Subnet Mask: " , "Default Gateway: " ,"Preferred DNS Server: ", "Alternate DNS Server: " };

		for (int j =0; j < 5; j++) 
		{
			if ((i+4)<=extendedDataLen)
			{
				ss << addresses[j] << (unsigned int)extData[i] << "." << (unsigned int)extData[i+1] <<
					 "." << (unsigned int)extData[i+2] << "." << (unsigned int)extData[i+3] << " ";
				i+=4;
			}
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network admin host name set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkAdminHostNameSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	int length = 0;

	if (i<extendedDataLen)
	{
		length = extData[i];
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "Host Name: ";
		for (int j=0 ; (extData[i]!=0) && (j<length) && (i<extendedDataLen) ; j++)
		{
			ss << (char)extData[i];
			i++;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network admin domain name set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkAdminDomainNameSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	int length = 0;

	if (i<extendedDataLen)
	{
		length = extData[i];
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "Domain Name: ";
		for (int j=0 ; (extData[i]!=0) && (j<length) && (i<extendedDataLen) ; j++)
		{
			ss << (char)extData[i];
			i++;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network admin link policy set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkAdminLinkPolicySetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if (i < extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i)<<". ";
	}

	if (i<extendedDataLen)
	{
		uint32_t *pvalue = NULL;
		try
		{
			pvalue = new uint32_t();
		}
		catch (std::bad_alloc&)
		{
			return ss.str();
		}
		ReverseMemCopy(pvalue, extData+i, sizeof(uint32_t));
		ss << "Link Policy: ";
		switch(*pvalue)
		{
			case 1:
				ss << LinkPolicyValues[0];
			break;
			case 15:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[1];
			break;
			case 31:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[1]<<", "<< LinkPolicyValues[2];
			break;
			case 255:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[1]<<", "<< LinkPolicyValues[2]<<", "<< LinkPolicyValues[3];
			break;
			case 239:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[1]<<", "<< LinkPolicyValues[3];
			break;
			case 17:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[2];
			break;
			case 241:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[2]<<", "<< LinkPolicyValues[3];
			break;
			case 225:
				ss << LinkPolicyValues[0]<<", "<< LinkPolicyValues[3];
			break;
			case 14:
				ss << LinkPolicyValues[1];
			break;
			case 30:
				ss << LinkPolicyValues[1]<<", "<< LinkPolicyValues[2];
			break;
			case 254:
				ss << LinkPolicyValues[1]<<", "<< LinkPolicyValues[2]<<", "<< LinkPolicyValues[3];
			break;
			case 238:
				ss << LinkPolicyValues[1]<<", "<< LinkPolicyValues[3];
			break;
			case 16:
				ss << LinkPolicyValues[2];
			break;
			case 240:
				ss << LinkPolicyValues[2]<<", "<< LinkPolicyValues[3];
			break;
			case 224:
				ss << LinkPolicyValues[3];
			break;
			default:
				ss << "Disabled";
			break;
		}
		delete pvalue;	
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the network admin IPv6 params event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayNetworkAdminIPv6ParamsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	int interfaceIDGenType = 0;

	if (i < extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i) << ". ";
	}

	if (i < extendedDataLen)
	{
		ss << "IPv6 " << ( extData[i]?"Enabled":"Disabled") << ". ";
		i++;
	}

	if (i < extendedDataLen)
	{
		interfaceIDGenType = extData[i];
		std::string interfaceIDGenTypeString = "Unknown";
		if ((interfaceIDGenType >= 0) && (interfaceIDGenType <= MAX_INTERFACE_ID_GEN_TYPE_STRINGS))
		{
			interfaceIDGenTypeString = interfaceIDGenTypeStrings[interfaceIDGenType];
		}
		ss << "Interface ID Type: " << interfaceIDGenTypeString.c_str() << ". ";

		i++;
	}

	if (i < extendedDataLen)
	{
		if (MANUAL_ID == interfaceIDGenType)
		{
			ss << "Interface ID: " << std::hex << std::uppercase;
			for (int j=0 ; (j<INTERFCAE_ID_LEN) && (i<extendedDataLen); j++)
			{
				if ((int)extData[i] < 10)
				{
					ss << "0";
				}
				ss << (int)extData[i];
				i++;
			}
			ss << std::dec << std::nouppercase << ". ";
		}
		else
		{
			i+=8;
		}
	}
	
	std::string addresses[] = { "IPv6 Address: " , "Default Gateway: " ,  "Preferred DNS Server: ", "Alternate DNS Server: "};
	for (int j = 0; j < 4; j++)
	{
		if ((i+16) <= extendedDataLen)
		{
			ss << addresses[j] << std::hex << std::uppercase;
			for ( int k = 0; k < 16; k++ )
			{
				if (!(k%2) && (int)extData[i+k] == 0 && (int)extData[i+k+1] == 0)  // put 0 instead of 0000
				{
					ss << "0";
					k++;
				}
				else 
				{
					if ((int)extData[i+k] < 10)
						ss << "0"; // otherwise there will be only one digit
					ss << (int)extData[i+k];
				}
				if (k != 15 && (k+1)%2 == 0)
				{
					ss << ":";
				}
			}
			ss << std::dec << std::nouppercase << " ";
			i+=16;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the storage admin global storage attributes set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayStorageAdminGlobalStorageAttributesSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if (i<extendedDataLen)
	{
		ss << PrintUint32(extData, extendedDataLen, "Max Partner Storage", i);
	}
	ss << "byte(s) ";

	if (i<extendedDataLen)
	{
		ss << PrintUint32(extData, extendedDataLen, "Max Non Partner Total Allocation Size", i);
	}
	ss << "byte(s) ";

	return ss.str();
}

/*****************************************************************************
 * Function that displays the event manager alert related event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayEventManagerAlertRelatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;
	bool ipv4 = false;
	bool ipv6 = false;

	if (i<extendedDataLen)
	{
		ss << "Policy ID: " << (unsigned int)extData[i] << ". ";
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "Subscription Alert Type: ";
		switch(extData[i])
		{
		case SNMP:
			ss << SNMP_STRING;
			break;
		case SOAP:
			ss << SOAP_STRING;
			break;
		default:
			ss << "Unknown";
			break;
		}
		ss << ". ";
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "IP Address Type: ";
		if (0==extData[i])
		{
			ss << "IPv4";
			ipv4 = true;
		}
		else if (1==extData[i])
		{
			ss << "IPv6";
			ipv6 = true;
		}
		else
		{
			ss << "Unknown";
		}
		ss << ". ";
		i++;
	}


	if (ipv4)
	{
		if ((i+4)<=extendedDataLen)
		{
			ss << "Alert Target IP Address: " << (int)extData[i] << "." << (int)extData[i+1] <<
			 "." << (int)extData[i+2] << "." << (int)extData[i+3];
			// no need i+=4;
		}
	}
	else if (ipv6)
	{
		if ((i+16)<=extendedDataLen)
		{
			ss << "Alert Target IP Address: " << std::hex << std::uppercase;
			for ( int k = 0; k < 16; k++ )
			{
				if (k%2 == 0 && (int)extData[i+k] == 0 && (int)extData[i+k+1] == 0)
				{
					ss << "0"; //put o instead of 0000
					k++;
				}
				else 
				{
					if ((int)extData[i+k] < 10) 
						ss << "0"; // otherwise there will be only one digit 
					ss << (int)extData[i+k];
				}
				if ((k+1)%2 == 0 && k != 15)
				{
					ss << ":";
				}
			}
			// no need i+=16;
			ss << std::dec << std::nouppercase;
		}
	}

	return ss.str();
}

/*****************************************************************************
 * Function that displays the event log frozen event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayEventLogFrozenEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		switch(extData[0])
		{
		case UNFREEZE:
			ss << UNFREEZE_STRING;
			break;
		case FREEZE:
			ss << FREEZE_STRING;
			break;
		default:
			ss << "Unknown";
			break;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the circuit breaker filter removed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayCircuitBreakerFilterRemovedEvent (uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;

	if (i<extendedDataLen)
	{
		return PrintUint32(extData, extendedDataLen, "Filter Handle", i);
	}
	return std::string("");
}

/*****************************************************************************
 * Function that displays the circuit breaker policy removed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayCircuitBreakerPolicyRemovedEvent (uint8_t* extData, uint8_t extendedDataLen)
{

	int i = 0;

	if (i<extendedDataLen)
	{
		return PrintUint32(extData, extendedDataLen, "Policy Handle", i);
	}
	return std::string("");
}

/*****************************************************************************
 * Function that displays the circuit breaker default policy set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayCircuitBreakerDefaultPolicySetEvent (uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if (i<extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i) << " ";
	}
	if ((i+sizeof(uint32_t))<=extendedDataLen)
	{
		return PrintUint32(extData, extendedDataLen, "Policy Handle", i);
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the circuit breaker heuristics option set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayCircuitBreakerHeuristicsOptionSetEvent (uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if (i<extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i) << ". ";
		//i += sizeof(uint32_t); // because  the above line was removed
	}

	if (i<extendedDataLen)
	{
		ss << "Block All: " << ((unsigned int)extData[i]?"true":"false") << ". ";
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "Block Offensive Port: " << ((unsigned int)extData[i]?"true":"false") << ". ";
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << PrintUint32(extData, extendedDataLen, "Policy Handle", i);
		//i += sizeof(uint32_t); // because  the above line was removed
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the circuit breaker heuristics state cleared event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayCircuitBreakerHeuristicsStateClearedEvent (uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;
	std::stringstream ss;

	if ((i+sizeof(uint32_t))<=extendedDataLen)
	{
		ss << "Network Interface: " << PrintInterfaceHandleUint32(extData, extendedDataLen, i);
		//i += sizeof(uint32_t); // because  the above line was removed
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the agent ID. 
 * Arguments:
 *  extData				- Extended data.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAgentID(uint8_t* extData)
{
	std::stringstream ss;
	ss << "Agent ID: ";
	for (int i=0 ; i<AGENT_ID_LEN ; i++)
	{
		if ((i!=0) && (0==i%4))
		{
			ss << "-";
		}
		ss << (unsigned int)extData[i];
	}
	ss << ". ";
	return ss.str();
}

/*****************************************************************************
 * Function that displays the agent presence agent watchdog added event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAgentPresenceAgentWatchdogAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if ((i+AGENT_ID_LEN)<=extendedDataLen)
	{
		ss << DisplayAgentID(extData);
		i+=AGENT_ID_LEN;
	}

	if ((i+sizeof(uint16_t))<=extendedDataLen)
	{
		ss << PrintUint16(extData, extendedDataLen, "Agent heart beat time", i) << "seconds. ";
	}

	if ((i+sizeof(uint16_t))<=extendedDataLen)
	{
		ss << PrintUint16(extData, extendedDataLen, "Agent startup time", i) << "seconds. ";
	}

	return ss.str();
}

/*****************************************************************************
 * Function that displays the agent presence agent watchdog removed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAgentPresenceAgentWatchdogRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;

	if (AGENT_ID_LEN <= extendedDataLen)
	{
		ss << DisplayAgentID(extData);
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the agent presence agent watchdog action set event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayAgentPresenceAgentWatchdogActionSetEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;

	if (AGENT_ID_LEN <= extendedDataLen)
	{
		ss << DisplayAgentID(extData);
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the wireless profile name. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 *  i					- Char index.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	std::stringstream ss;
	int length = 0;

	if (i<extendedDataLen)
	{
		length = extData[i];
		i++;
	}

	if (i<extendedDataLen)
	{
		ss << "Profile Name: ";
		for (int j=0; (extData[i]!=0) && (j<length) && (i<extendedDataLen); j++, i++)
		{
			ss << (char)extData[i];
		}
		ss << ".";
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the full wireless profile name. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 *  i					- Char index.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayFullWirelessProfileName(uint8_t* extData, uint8_t extendedDataLen, int & i)
{
	std::stringstream ss, temp;
	if (i<extendedDataLen)
	{
		temp << "SSID: ";
		for (int j=0 ; (extData[i]!=0) && (j<SSID_LEN) && (i<extendedDataLen) ; j++, i++)
		{
			temp << (char)extData[i];
		}
		temp << ". ";
		i = SSID_LEN;
		if (extendedDataLen < SSID_LEN)
		{
			i = extendedDataLen;
		}
	}

	if (i<extendedDataLen)
	{
		temp << "Profile Priority: " << (int)extData[i] << ". ";
		i++;
	}

	ss << DisplayWirelessProfileName(extData, extendedDataLen, i) << " " << temp.str();
	return ss.str();
}

/*****************************************************************************
 * Function that displays the wireless profile added event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileAddedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;
	return DisplayFullWirelessProfileName(extData, extendedDataLen, i);
}

/*****************************************************************************
 * Function that displays the wireless profile removed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileRemovedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;
	return DisplayWirelessProfileName(extData, extendedDataLen, i);
}

/*****************************************************************************
 * Function that displays the wireless profile updated event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileUpdatedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;
	return DisplayFullWirelessProfileName(extData, extendedDataLen, i);
}

/*****************************************************************************
 * Function that displays the wireless profile link preference changed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileSyncChangeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	ss << "";
	if (extendedDataLen >= sizeof (uint32_t)) 
	{
//		ss << "new profile sync enablement: ";
		switch (((uint32_t *)extData)[0]) { 
		case PROFILE_SYNC_DISABLED : 
			ss << "Profile sync is disabled"; 
			break;
		case PROFILE_SYNC_USER:
			ss << "Profile sync user"; 
			break;
		case PROFILE_SYNC_ADMIN:
			ss << "Profile sync admin"; 
			break;
		case PROFILE_SYNC_UNRESTRICTED:
			ss << "Profile sync is unrestricted"; 
			break;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the wireless profile link preference changed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileLinkPreferenceChanged(uint8_t* extData, uint8_t extendedDataLen)
{
	int i = 0;
	std::stringstream ss;
	ss << "";
	if (extendedDataLen >= sizeof (uint32_t)) 
	{
		ss << "Link preference was set to: ";
		switch(((uint32_t *)extData)[i])
		{
		case LINK_PREFERENCE_ME:
			ss << "ME. ";
			break;
		case LINK_PREFERENCE_HOST:
			ss << "Host. ";
			break;
		default:
			ss << "Unknown. ";
			break;
		}
	}
	i += sizeof (uint32_t);
	if (extendedDataLen >= sizeof (uint32_t)) 
	{
		ss << PrintUint32(extData, extendedDataLen, "Timeout", i);
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the wireless profile share with UEFI enabled setting changed event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWirelessProfileUefiEnabledChangedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen >= sizeof(uint8_t))
	{
		ss << "UEFI WiFi Profile Share is ";
		switch (extData[0])
		{
		case UEFI_WIFI_PROFILE_SHARE_DISABLED:
			ss << "Disabled. ";
			break;
		case UEFI_WIFI_PROFILE_SHARE_ENABLED:
			ss << "Enabled. ";
			break;
		default:
			ss << "Unknown. ";
			break;
		}
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the EAC set options event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayEacSetOptionsEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i = 0;

	if ((i+sizeof(uint32_t))<=extendedDataLen)
	{
		uint32_t *pvalue = NULL;
		try
		{
			pvalue = new uint32_t();
		}
		catch (std::bad_alloc&)
		{
			return ss.str();
		}
		ReverseMemCopy(pvalue, extData+i, sizeof(uint32_t));
		
		if (*pvalue < NUMBER_OF_EAC_VENDOR_STRINGS)
		{
			ss << "Eac Vendors: " << EACVendors[*pvalue];
		}
		delete pvalue;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the User Opt-In policy change event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayOptInPolicyChangeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	int i=0;
	
	if (i < extendedDataLen)
	{
		ss << PrintOptInPolicy(extData[i], "Previous Opt In Policy");	
		i++;
	}
	if (i < extendedDataLen)
	{
		ss << PrintOptInPolicy(extData[i], " Current Opt In Policy");
		i++;
	}
	return ss.str();
}

/*****************************************************************************
 * Function that prints the User Opt-In policy. 
 * Arguments:
 *  curData		- Current data.
 *  title		- The title of the data.
 ****************************************************************************/
std::string AuditLogWSManClient::PrintOptInPolicy(uint8_t curData, const char* title)
{
	std::stringstream ss;
	ss << title << ": ";
	if (((curData & 2) != 0)) 
	{
		ss << "ALL";
	}
	else if (((curData & 1) != 0)) 
	{
		ss << "KVM";
	}
	else 
	{
		ss << "None";
	}
	return ss.str();
}

/*****************************************************************************
 * Function that displays the User Opt-In send consent code event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplaySendConsentCodeEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		ss << "Operation Status: ";
		switch(extData[0])
		{
		case SUCCESFUL_TYPE:
			ss << SUCCESSFUL_PASSWORD_STRING;
			break;
		case UNSUCCESFUL_TYPE:
			ss << UNSUCCESSFUL_PASSWORD_STRING;
			break;
		default:
			ss << "Unknown";
		}
	}
	return ss.str();
}


/*****************************************************************************
 * Function that displays the Watchdog  Action Pairing Changed Event
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayWatchdogActionPairingChangedEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	if (extendedDataLen > 0)
	{
		switch(extData[0])
		{
		case 0:
			ss << SUCCESSFUL_PASSWORD_STRING;
			break;
		case 1:
			ss << UNSUCCESSFUL_PASSWORD_STRING;
			break;
		default:
			ss << "Unknown";
		}
	}
	return ss.str();
}


/*****************************************************************************
 * Function that displays the unknown event. 
 * Arguments:
 *  extData				- Extended data.
 *  extendedDataLen		- Extended data length.
 ****************************************************************************/
std::string AuditLogWSManClient::DisplayUnknownEvent(uint8_t* extData, uint8_t extendedDataLen)
{
	std::stringstream ss;
	ss << "Unknown Event: Length = " << (unsigned int)extendedDataLen << ". Data =" << std::hex << std::uppercase;

	for(int i=0 ; i<extendedDataLen; i++)
	{
		ss << " " << (int)extData[i];
	}
	ss << std::dec << std::nouppercase  << ". ";
	return ss.str();
}
