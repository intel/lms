/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPort_WMI_Provider.h

--*/

// WMI provider interface for CIM Wi-Fi port projection.

#ifndef WIFI_PORT_WMI_PROVIDER_H
#define WIFI_PORT_WMI_PROVIDER_H
#include "WMIInfrastructure.h"

class WiFiPort_WMI_Provider
{
public:
	// Enumerates Wi-Fi port instances for WMI exposure.
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
};

#endif // WIFI_PORT_WMI_PROVIDER_H

