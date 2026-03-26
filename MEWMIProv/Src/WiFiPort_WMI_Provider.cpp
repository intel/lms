/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPort_WMI_Provider.cpp

--*/

// Implements WMI projection of CIM Wi-Fi port state retrieved through WS-Man.

#include "WiFiPort_WMI_Provider.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"
#include "StringManipulator.h"

HRESULT WiFiPort_WMI_Provider::Enumerate(
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
		// 1) Fetch all Wi-Fi port instances from firmware via WSMan (GetWiFiPorts).
		// 2) For each port, create a CIM_WiFiPort WMI object and copy mapped fields.
		// 3) Submit each completed object to WMI via pResponseHandler->Indicate.
		do {
			std::vector<WiFiPortWSMan> ports;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetWiFiPorts(ports);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			for (size_t i = 0; i < ports.size(); ++i)
			{
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_WiFiPort"));

				std::wstring instanceID = L"Intel(R) AMT WiFi Port " + std::to_wstring(i);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", instanceID));
				BREAKIF(WMIPut<1>(obj, L"EnabledState", ports[i].EnabledState));
				BREAKIF(WMIPut<1>(obj, L"PermanentAddress", ToWStr(ports[i].PermanentAddress)));

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
