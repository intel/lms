/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiProfiles_WMI_Provider.cpp

--*/

// Implements WMI projection of AMT-managed Wi-Fi profile definitions.

#include "WiFiProfiles_WMI_Provider.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"
#include "StringManipulator.h"

HRESULT WiFiProfiles_WMI_Provider::Enumerate(
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
		// 1) Fetch all AMT-managed Wi-Fi profiles from firmware via WSMan (GetWiFiProfiles).
		// 2) For each profile, create an AMT_WiFiProfiles WMI instance and copy WSMan fields.
		// 3) Submit each completed instance to WMI via pResponseHandler->Indicate.
		do {
			std::vector<WiFiProfileWSMan> profiles;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetWiFiProfiles(profiles);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			for (size_t i = 0; i < profiles.size(); ++i)
			{
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_WiFiProfiles"));

				std::wstring instanceID = L"Intel(R) AMT WiFi Profile " + std::to_wstring(i);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", instanceID));
				BREAKIF(WMIPut<1>(obj, L"ProfileName", ToWStr(profiles[i].ProfileName)));
				BREAKIF(WMIPut<1>(obj, L"Priority", profiles[i].Priority));
				BREAKIF(WMIPut<1>(obj, L"SSID", ToWStr(profiles[i].SSID)));
				BREAKIF(WMIPut<1>(obj, L"EncryptionMethod", profiles[i].EncryptionMethod));
				BREAKIF(WMIPut<1>(obj, L"AuthenticationMethod", profiles[i].AuthenticationMethod));

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
