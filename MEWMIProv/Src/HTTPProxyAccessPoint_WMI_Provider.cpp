/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: HTTPProxyAccessPoint_WMI_Provider.cpp

--*/

// Implements WMI projection of AMT HTTP proxy access point data via WS-Man queries.

#include "HTTPProxyAccessPoint_WMI_Provider.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"
#include "StringManipulator.h"

HRESULT HTTPProxyAccessPoint_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		// Flow:
		// 1) Fetch all HTTP proxy access point instances from firmware via WSMan.
		// 2) For each instance, create an IPS_HTTPProxyAccessPoint WMI object and map fields.
		// 3) Submit each completed object to WMI via pResponseHandler->Indicate.
		do {
			std::vector<HTTPProxyAccessPointWSMan> proxies;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetHTTPProxyAccessPoints(proxies);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			for (size_t i = 0; i < proxies.size(); ++i)
			{
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"IPS_HTTPProxyAccessPoint"));

				std::wstring instanceID = L"Intel(R) AMT HTTP Proxy Access Point " + std::to_wstring(i);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", instanceID));
				BREAKIF(WMIPut<1>(obj, L"AccessInfo", ToWStr(proxies[i].AccessInfo)));
				BREAKIF(WMIPut<1>(obj, L"InfoFormat", proxies[i].InfoFormat));
				BREAKIF(WMIPut<1>(obj, L"Port", proxies[i].Port));
				BREAKIF(WMIPut<1>(obj, L"NetworkDnsSuffix", ToWStr(proxies[i].NetworkDnsSuffix)));
				BREAKIF(WMIPut<1>(obj, L"Priority", proxies[i].Priority));

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
