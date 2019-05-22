/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: OOB_Service_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"

class OOB_Service_WMI_Provider
{
public:
	static   HRESULT DispatchMethods(
		const BSTR                  strMethodName,
		const BSTR strObjectPath,
		IWbemServices  *pNamespace,
		CComPtr<IWbemClassObject> pClass,
		IWbemClassObject __RPC_FAR* pInParams,
		IWbemObjectSink __RPC_FAR*  pResponseHandler);

	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT GetOOB_Service(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
private:
	static   HRESULT GetAMTProvisioningMode(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);


	static   HRESULT GetProvisioningState(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT GetActivationTLSMode(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT GetPID(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT isTLSEnabled(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT Activate(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static    HRESULT isRemoteConfigEnabled(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT GetConfigServerAddressInfo(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT isWiredLinkUp(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT GetProvisioningInfo(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT GetRemoteAccessConnectionStatus(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT GetAMTFQDN(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT CancelActivation(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT OpenUserInitiatedConnection(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT CloseUserInitiatedConnection(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT Unconfigure(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT GetLocalAdminCredentials(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	
};
