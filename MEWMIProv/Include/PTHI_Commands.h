/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: PTHI_Commands.h

--*/

#pragma once
#include "stdafx.h"
#include <string>
#include <vector>

#define NET_TLS_CERT_PKI_MAX_SERIAL_NUM_LENGTH  16

#define ENABLED_STATE 	0
#define DISABLED_STATE	1
#define UNKNOWN_STATE 	2

typedef struct _CFG_TIMEDATE
{
	UINT16	Year;
	UINT16	Month;
	UINT16	DayOfWeek;
	UINT16	Day;
	UINT16	Hour;
	UINT16	Minute;
	UINT16	Second;
} TIME_DATE_;
typedef struct _MEAdminAudit
{
	UINT8       ProvisioningTLSMode;
	bool		SecureDNS;
	bool        HostInitiated;
	UINT32  	SelectedHashType;	
	std::vector<UINT8> SelectedHashData;
	std::vector<UINT8> CACertificateSerial1;
	std::vector<UINT8> CACertificateSerial2;
	std::vector<UINT8> CACertificateSerial3;
	bool        AdditionalCaSerialNums;
	bool		IsOemDefault;
	bool		IsTimeValid;
	std::wstring     ProvServerIP; 
	TIME_DATE_    TlsStartTime;
	std::wstring		ProvServerFQDN;
} MEAdminAudit;

typedef struct _HashEntry
{
	std::wstring Description;
	bool IsDefault;
	UINT8 HashType;
	UINT8 HashData[64];
	bool Enabled;
} HashEntry;

typedef struct _EthernetPortEntry
{
	std::wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	std::wstring   IPAddress;
	std::wstring   SubnetMask;
	std::wstring   DefaultGateway;
	std::wstring   PrimaryDNS;
	std::wstring   SecondaryDNS;
} EthernetPortEntry;

typedef struct _LOCAL_SYSTEM_ACCOUNT
{
	// contains null terminated string
	std::string UserName;
	// contains null terminated string
	std::string Password;

}LOCAL_SYSTEM_ACCOUNT;

class PTHI_Commands
{
private:
	UINT8 SetProvisioningTLSModeValues(unsigned char provTLSMode);
public:
	UINT32 GetProvisioningState(SHORT* pProvisioningState);
	UINT32 GetTLSEnabled(bool* enabled);
	UINT32 isWiredLinkUp(bool* enabled);
	UINT32 isRemoteConfigEnabled(bool* enabled);
	UINT32 GetRemoteAccessConnectionStatus(SHORT* ConnectionTrigger, SHORT* NetworkConStatus, std::wstring* MPshostName, SHORT* RemoteAccessConStatus);

	UINT32 GetProvisioningInfo(std::wstring* pPKIDNSSuffix, std::wstring* pConfigServerFQDN);
	UINT32 GetAMTFQDN(std::wstring* FQDN);
	UINT32 GetConfigServerData(std::wstring* Address, unsigned short* port);
	UINT32 GetAMTState(unsigned int* LastMEResetReason, bool *cryptoFuseEnabled);
	UINT32 GetPowerPolicy(std::wstring* policy);
	UINT32 StopConfiguration(void);
	UINT32 GetAMTVersion(std::wstring* AMTVersion);
	UINT32 GetMESetupAudit(MEAdminAudit *MEAudit);
	UINT32 getWebUIState(SHORT* pState);
	UINT32 GetRedirectionStatus(SHORT* pSOL, SHORT* pIDER);
	UINT32 GetCertificateHash(std::vector<HashEntry> &hashlist);
	UINT32 GetRedirectionState(bool *pSolEnable, bool *pIDEREnabled, bool *pKVMEnabled);
	UINT32 GetPortSettings(std::vector<EthernetPortEntry> &ethernetPortList);
	UINT32 GetLocalSystemAccount(LOCAL_SYSTEM_ACCOUNT *LocalAccount);
	UINT32 GetKVMSessionActivation(bool* activated);
	UINT32 Unprovision();

	UINT32 OpenCIRA(void);
	UINT32 CloseCIRA(void);
};