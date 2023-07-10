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

class EthernetPortEntry
{
public:
	EthernetPortEntry() : LinkIsUp(false), DHCPEnabled(false) {}
	std::wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	std::wstring   IPAddress;
	std::wstring   SubnetMask;
	std::wstring   DefaultGateway;
	std::wstring   PrimaryDNS;
	std::wstring   SecondaryDNS;
};

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
	unsigned char SetProvisioningTLSModeValues(unsigned char provTLSMode);
public:
	unsigned int GetProvisioningState(SHORT* pProvisioningState);
	unsigned int GetTLSEnabled(bool* enabled);
	unsigned int isWiredLinkUp(bool* enabled);
	unsigned int isRemoteConfigEnabled(bool* enabled);
	unsigned int GetRemoteAccessConnectionStatus(SHORT* ConnectionTrigger, SHORT* NetworkConStatus, std::wstring* MPshostName, SHORT* RemoteAccessConStatus);

	unsigned int GetProvisioningInfo(std::wstring* pPKIDNSSuffix, std::wstring* pConfigServerFQDN);
	unsigned int GetAMTFQDN(std::wstring* FQDN);
	unsigned int GetConfigServerData(std::wstring* Address, unsigned short* port);
	unsigned int GetAMTState(unsigned int* LastMEResetReason, bool *cryptoFuseEnabled);
	unsigned int GetPowerPolicy(std::wstring* policy);
	unsigned int GetAMTVersion(std::wstring* AMTVersion);
	unsigned int GetMESetupAudit(MEAdminAudit *MEAudit);
	unsigned int getWebUIState(SHORT* pState);
	unsigned int GetRedirectionStatus(SHORT* pSOL, SHORT* pIDER);
	unsigned int GetCertificateHash(std::vector<HashEntry> &hashlist);
	unsigned int GetRedirectionState(bool *pSolEnable, bool *pIDEREnabled, bool *pKVMEnabled);
	unsigned int GetPortSettings(std::vector<EthernetPortEntry> &ethernetPortList);
	unsigned int GetLocalSystemAccount(LOCAL_SYSTEM_ACCOUNT *LocalAccount);
	unsigned int GetKVMSessionActivation(bool* activated);
	unsigned int Unprovision();

	unsigned int OpenCIRA(void);
	unsigned int CloseCIRA(void);
};