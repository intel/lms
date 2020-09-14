/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: Audit_Record_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"
#include "PTHI_Commands.h"

class Audit_Record_WMI_Provider
{
public:
	std::wstring InstanceID;
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
	std::wstring    TlsStartTime;
	std::wstring		ProvServerFQDN;
			
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT GetAudit_Record(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
	static HRESULT EnumerateAuditRecord(
		std::vector<Audit_Record_WMI_Provider>& auditVec,
		uint32& ReturnValue);

	~Audit_Record_WMI_Provider() {};

private: 
	Audit_Record_WMI_Provider(const MEAdminAudit &MEAudit, const std::wstring &instanceID);
};
