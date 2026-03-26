/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: RemoteAccessPolicyRule_WMI_Provider.cpp

--*/

// Implements WMI projection for AMT remote access policy rule instances.

#include "RemoteAccessPolicyRule_WMI_Provider.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"
#include "StringManipulator.h"

HRESULT RemoteAccessPolicyRule_WMI_Provider::Enumerate(
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
		// 1) Fetch all AMT remote access policy rules from firmware via WSMan.
		// 2) For each rule, create an AMT_RemoteAccessPolicyRule WMI object and map fields.
		// 3) Submit each completed object to WMI via pResponseHandler->Indicate.
		do {
			std::vector<RemoteAccessPolicyRuleWSMan> rules;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetRemoteAccessPolicyRules(rules);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}

			for (size_t i = 0; i < rules.size(); ++i)
			{
				CComPtr<IWbemClassObject> obj;
				BREAKIF(WMIPutMember(pNamespace, &obj, L"AMT_RemoteAccessPolicyRule"));

				std::wstring instanceID = L"Intel(R) AMT Remote Access Policy Rule " + std::to_wstring(i);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", instanceID));
				BREAKIF(WMIPut<1>(obj, L"PolicyRuleName", ToWStr(rules[i].PolicyRuleName)));
				BREAKIF(WMIPut<1>(obj, L"Trigger", rules[i].Trigger));
				BREAKIF(WMIPut<1>(obj, L"TunnelLifeTime", rules[i].TunnelLifeTime));
				// ExtendedData is a raw byte array; WMIPut<uint8> is used instead of WMIPut<1>.
				BREAKIF(WMIPut<uint8>(obj, L"ExtendedData", rules[i].ExtendedData));

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
