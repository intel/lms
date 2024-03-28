/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: Concrete_Component_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"

class Concrete_Component_WMI_Provider
{
public:

	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT GetConcrete_Component(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
	static bool IsGroupOobService(const CComBSTR &groupREF_BSTR);
	static std::wstring analyzePartCompnent(const CComBSTR &partComponenetVal);
	static bool compareCaseInsensitive(const CComBSTR &str1, const CComBSTR &str2);
	static bool ProvisioningHashREFExists(const CComBSTR &partComponenet);
	static bool EthernetPortREFExists(const CComBSTR &partComponenet);
	static bool AuditRecordREFExists(const CComBSTR &partComponenet);
};
