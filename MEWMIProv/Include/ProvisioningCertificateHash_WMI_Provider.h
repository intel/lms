/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: ProvisioningCertificateHash_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"
#include "PTHI_Commands.h"

class ProvisioningCertificateHash_WMI_Provider
{
public:
	std::wstring InstanceID;
	std::wstring ElementName;
	std::wstring Description;
	bool IsDefault;
	UINT8 HashType;
	vector<uint8> HashDataVec;
	bool Enabled;

	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT Get_Entry(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
	static HRESULT EnumerateProvisioningCertificateHash(
		vector<ProvisioningCertificateHash_WMI_Provider>& enumVec, 
		uint32& ReturnValue);

	~ProvisioningCertificateHash_WMI_Provider() {};
private:
	ProvisioningCertificateHash_WMI_Provider(HashEntry entry, std::wstring instanceID, std::wstring elementName);

};
