/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: AMT_Service_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"

class AMT_Service_WMI_Provider
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

	static HRESULT GetAMT_Service(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

private:
	static   HRESULT isWebUIEnabled(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);


	static   HRESULT getSOLState(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT getIDERState(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT getKVMState(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT TerminateKVMSession(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static   HRESULT setSpriteZoom(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static    HRESULT setSpriteLocale(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);


};
