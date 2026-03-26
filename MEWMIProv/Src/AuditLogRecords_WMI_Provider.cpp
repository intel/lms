/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: AuditLogRecords_WMI_Provider.cpp

--*/

// Implements WMI materialization of AMT audit log records retrieved via WS-Man.

#include "AuditLogRecords_WMI_Provider.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"

HRESULT AuditLogRecords_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			// Flow:
			// 1) Fetch all AMT audit log records from firmware via WSMan (GetAuditLogRecords).
			// 2) For each record, create an AMT_AuditLogRecords WMI instance and set fields.
			// 3) Submit each completed instance to WMI via pResponseHandler->Indicate.
			std::vector<BinaryData> records;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetAuditLogRecords(records);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			for (size_t i = 0; i < records.size(); ++i)
			{
				CComPtr<IWbemClassObject> obj;
				BREAKIF(WMIPutMember(pNamespace, &obj, L"AMT_AuditLogRecords"));

				std::wstring instanceID = L"Intel(R) AMT Audit Log Record " + std::to_wstring(i);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", instanceID));
				BREAKIF(WMIPut<uint8>(obj, L"AuditLogRecord", records[i]));

				BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}
		} while (0);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AuditLogRecords_WMI_Provider::GetAuditLogRecord(
								IWbemServices* pNamespace,
								const BSTR strObjectPath,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	HRESULT hr = 0;
	uint32 ReturnValue = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::map <std::wstring, CComVariant> keyList;
		std::map <std::wstring, CComVariant>::const_iterator it;
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"InstanceID");
		if (it == keyList.end())
		{
			hr = WBEM_E_INVALID_METHOD_PARAMETERS;
			return hr;
		}

		do
		{
			// Fetch current records and return the entry resolved from InstanceID parsing.
			if (it->second.vt != VT_BSTR || it->second.bstrVal == nullptr)
			{
				hr = WBEM_E_INVALID_METHOD_PARAMETERS;
				break;
			}

			const std::wstring instanceID(it->second.bstrVal);
			const std::wstring instanceIDPrefix = L"Intel(R) AMT Audit Log Record ";
			if (instanceID.compare(0, instanceIDPrefix.size(), instanceIDPrefix) != 0)
			{
				hr = WBEM_E_NOT_FOUND;
				break;
			}

			size_t parsedLength = 0;
			size_t recordIndex = 0;
			try
			{
				recordIndex = std::stoul(instanceID.substr(instanceIDPrefix.size()), &parsedLength);
			}
			catch (...)
			{
				hr = WBEM_E_INVALID_METHOD_PARAMETERS;
				break;
			}

			// Verify that stoul consumed the entire suffix.
			// Trailing non-numeric characters (e.g. " 5abc") would not be caught by the exception alone.
			if (parsedLength != (instanceID.size() - instanceIDPrefix.size()))
			{
				hr = WBEM_E_INVALID_METHOD_PARAMETERS;
				break;
			}

			std::vector<BinaryData> records;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetAuditLogRecords(records);

			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			if (records.empty())
			{
				hr = WBEM_E_NOT_FOUND;
				break;
			}

			if (recordIndex >= records.size())
			{
				hr = WBEM_E_NOT_FOUND;
				break;
			}

			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_AuditLogRecords"));
			BREAKIF(WMIPut<1>(obj, L"InstanceID", it->second));
			BREAKIF(WMIPut<uint8>(obj, L"AuditLogRecord", records[recordIndex]));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		} while (0);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}
