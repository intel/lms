/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: HTTPProxyAccessPoint_WMI_Provider.h

--*/

// WMI provider interface for exposing AMT HTTP proxy access points.

#ifndef HTTP_PROXY_ACCESS_POINT_WMI_PROVIDER_H
#define HTTP_PROXY_ACCESS_POINT_WMI_PROVIDER_H
#include "WMIInfrastructure.h"

class HTTPProxyAccessPoint_WMI_Provider
{
public:
	// Enumerates all HTTP proxy access point instances for WMI clients.
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
};

#endif // HTTP_PROXY_ACCESS_POINT_WMI_PROVIDER_H

