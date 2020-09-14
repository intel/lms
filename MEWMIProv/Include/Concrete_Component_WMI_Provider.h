/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
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
	static bool IsGroupOobService(CComBSTR groupREF_BSTR);
	static std::wstring analyzePartCompnent(CComBSTR partComponenetVal);
	static bool compareCaseInsensitive(CComBSTR str1, CComBSTR str2);
	static bool ProvisioningHashREFExists(CComBSTR partComponenet);
	static bool EthernetPortREFExists(CComBSTR partComponenet);
	static bool AuditRecordREFExists(CComBSTR partComponenet);
};
