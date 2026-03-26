/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: AuditLogRecords_WMI_Provider.h

--*/

// WMI provider interface for AMT audit log record enumeration and single-record access.

#ifndef AUDIT_LOG_RECORDS_WMI_PROVIDER_H
#define AUDIT_LOG_RECORDS_WMI_PROVIDER_H
#include "WMIInfrastructure.h"

class AuditLogRecords_WMI_Provider
{
public:
	// Enumerates all AMT audit log records as WMI instances.
	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	// Resolves one audit log record by InstanceID from object path.
	static HRESULT GetAuditLogRecord(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
};

#endif // AUDIT_LOG_RECORDS_WMI_PROVIDER_H

