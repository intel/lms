/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiProfiles_WMI_Provider.h

--*/

// WMI provider interface for exposing AMT-managed Wi-Fi profiles.

#ifndef WIFI_PROFILES_WMI_PROVIDER_H
#define WIFI_PROFILES_WMI_PROVIDER_H
#include "WMIInfrastructure.h"

class WiFiProfiles_WMI_Provider
{
public:
	// Enumerates stored Wi-Fi profiles and publishes them as WMI instances.
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
};

#endif // WIFI_PROFILES_WMI_PROVIDER_H

