/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: RemoteAccessPolicyRule_WMI_Provider.h

--*/

// WMI provider interface for AMT remote access policy rule objects.

#ifndef REMOTE_ACCESS_POLICY_RULE_WMI_PROVIDER_H
#define REMOTE_ACCESS_POLICY_RULE_WMI_PROVIDER_H
#include "WMIInfrastructure.h"

class RemoteAccessPolicyRule_WMI_Provider
{
public:
	// Enumerates remote access policy rules and publishes them through WMI.
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
};

#endif // REMOTE_ACCESS_POLICY_RULE_WMI_PROVIDER_H

