/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2026 Intel Corporation
 */
/*++

@file: AMT_Service_WMI_Provider.cpp

--*/

#include "AMT_Service_WMI_Provider.h"
#include "pthi_commands.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"
#include "StringManipulator.h"


HRESULT AMT_Service_WMI_Provider::DispatchMethods(
									  const BSTR strMethodName,
									  const BSTR strObjectPath,
									  IWbemServices  *pNamespace,
									  CComPtr<IWbemClassObject> pClass,
									  IWbemClassObject __RPC_FAR* pInParams,
									  IWbemObjectSink __RPC_FAR*  pResponseHandler)
{
	bool staticMethod = WMIHelper::isMethodCallStatic(strObjectPath);
	HRESULT                   hr = S_OK;
	try
	{
		if (staticMethod)
		{
			if(CComBSTR(strMethodName) == L"isWebUIEnabled")
				hr = isWebUIEnabled(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getSOLState")
				hr = getSOLState(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getIDERState")
				hr = getIDERState(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getKVMState")
				hr = getKVMState(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"TerminateKVMSession")
				hr = TerminateKVMSession(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"setSpriteZoom")
				hr = setSpriteZoom(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"setSpriteLocale")
				hr = setSpriteLocale(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getBootCapabilities")
				hr = getBootCapabilities(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getEnvironmentDetectionSettingData")
				hr = getEnvironmentDetectionSettingData(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getGeneralSettings")
				hr = getGeneralSettings(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getAMTConfiguration")
				hr = getAMTConfiguration(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getWiFiPortConfiguration")
				hr = getWiFiPortConfiguration(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getWiFiEndpointState")
				hr = getWiFiEndpointState(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getCIRALog")
				hr = getCIRALog(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getTimeSynchronizationConfig")
				hr = getTimeSynchronizationConfig(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getOptInConfiguration")
				hr = getOptInConfiguration(pClass, pInParams, pResponseHandler, pNamespace);
			else
			{
				hr = WBEM_E_NOT_SUPPORTED;
				WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
			}
		}
		else
		{
			//there are no non static methods in this class
			hr = WBEM_E_INVALID_METHOD;
			WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
		}
		
			
	}
	catch(...)
	{
		hr  = ERROR_EXCEPTION_IN_SERVICE;
	}

	return hr;
}

HRESULT AMT_Service_WMI_Provider::isWebUIEnabled(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{ 
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			SHORT enabled = 0;
			PTHI_Commands pthic;
			ReturnValue = pthic.getWebUIState(&enabled);

			ERROR_HANDLER(ReturnValue);

			WMIGetMethodOParams(pClass, L"isWebUIEnabled", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"enabled", enabled));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getSOLState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		SHORT SOLactive=0, IDERactive=0;
		bool IDERhardEnable = false, SOLhardEnable = false, KVMhardEnable = false;
		uint32 SOLhardEnabledState = UNKNOWN_STATE;
		uint32 SOLsoftEnabledState = UNKNOWN_STATE;

		PTHI_Commands pthic;
		ReturnValue = pthic.GetRedirectionState(&SOLhardEnable, &IDERhardEnable, &KVMhardEnable);
		ERROR_HANDLER(ReturnValue);
		
		if (SOLhardEnable)
		{
			SOLhardEnabledState = ENABLED_STATE;
		} else 
		{
			SOLhardEnabledState = DISABLED_STATE;
		}

		//if (SOLenabled) - prev command works only on AMT 6 but the next command work in earlier version - so for them we will get only the activated property
		ReturnValue = pthic.GetRedirectionStatus(&SOLactive, &IDERactive);
		ERROR_HANDLER(ReturnValue);
		
		//get softEnabled section
		if (SOLhardEnable)
		{
			WSmanCommands wsmc;
			bool SOLsoftEnabled;
			ReturnValue = wsmc.isSOLEnabled(&SOLsoftEnabled);
			if (ReturnValue == 0)
			{
				if (SOLsoftEnabled)
					SOLsoftEnabledState = ENABLED_STATE;
				else
					SOLsoftEnabledState = DISABLED_STATE;
			}
		}
		else
		{
			SOLsoftEnabledState = DISABLED_STATE;
		}
		
		ERROR_HANDLER(ReturnValue);

		do {
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"getSOLState", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"active", SOLactive));
			BREAKIF(WMIPut<1>(pOutParams, L"hardEnabled", SOLhardEnabledState));
			BREAKIF(WMIPut<1>(pOutParams, L"softEnabled", SOLsoftEnabledState));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getIDERState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		SHORT SOLactive=0, IDERactive=0;
		bool IDERhardEnable = false, SOLhardEnable = false, KVMhardEnable = false;
		uint32 IDERhardEnabledState = UNKNOWN_STATE;
		uint32 IDERsoftEnabledState = UNKNOWN_STATE;

		PTHI_Commands pthic;
		ReturnValue = pthic.GetRedirectionState(&SOLhardEnable, &IDERhardEnable, &KVMhardEnable);
		ERROR_HANDLER(ReturnValue);
		
		if (IDERhardEnable)
		{
			IDERhardEnabledState = ENABLED_STATE;
		} else 
		{
			IDERhardEnabledState = DISABLED_STATE;
		}

		//if (IDERenabled) - prev command works only on AMT 6 but the next command work in earlier version - so for them we will get only the activated property
		ReturnValue = pthic.GetRedirectionStatus(&SOLactive, &IDERactive);
		ERROR_HANDLER(ReturnValue);

		//get softEnabled section
		if (IDERhardEnable)
		{
			WSmanCommands wsmc;
			bool IDERsoftEnabled;
			ReturnValue = wsmc.isIDEREnabled(&IDERsoftEnabled);
			if (ReturnValue == 0)
			{
				if (IDERsoftEnabled)
					IDERsoftEnabledState = ENABLED_STATE;
				else
					IDERsoftEnabledState = DISABLED_STATE;
			}
		}
		else
		{
			IDERsoftEnabledState = DISABLED_STATE;
		}
		
		do {
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"getIDERState", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"hardEnabled", IDERhardEnabledState));
			BREAKIF(WMIPut<1>(pOutParams, L"softEnabled", IDERsoftEnabledState));
			BREAKIF(WMIPut<1>(pOutParams, L"active", IDERactive));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getKVMState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do{
			bool IDERhardEnable = false, SOLhardEnable = false, KVMhardEnable = false;
			bool active = false;
			uint32 KVMhardEnabledState = UNKNOWN_STATE;
			uint32 KVMsoftEnabledState =  UNKNOWN_STATE;

			PTHI_Commands pthic;
			ReturnValue = pthic.GetRedirectionState(&SOLhardEnable, &IDERhardEnable, &KVMhardEnable);
			ERROR_HANDLER(ReturnValue);
			if (ReturnValue == 0)
			{
				if (KVMhardEnable)
				{
					KVMhardEnabledState = ENABLED_STATE;
				}
				else
				{
					KVMhardEnabledState = DISABLED_STATE;
				}
			}
			//get sofEnabled and active state
			if (KVMhardEnabledState == ENABLED_STATE)
			{
				WSmanCommands wsmc;
				active = false;
				bool kvmSoftEnabled = false;
				bool kvmSoftEnabledUnknown = false;
				
				ReturnValue = wsmc.isKVMActive(&kvmSoftEnabled, &active);
				if (ReturnValue != S_OK)
				{
					ReturnValue = pthic.GetKVMSessionActivation(&active);
					if (active)
						kvmSoftEnabled = true;
					else
						kvmSoftEnabledUnknown = true;
				}
				if (kvmSoftEnabledUnknown)
				{
					KVMsoftEnabledState = UNKNOWN_STATE;
				}
				else if (kvmSoftEnabled)
				{
					KVMsoftEnabledState = ENABLED_STATE;
				} 
				else
				{
					KVMsoftEnabledState = DISABLED_STATE;
				}
				

				ERROR_HANDLER(ReturnValue);
			}
			do {
				CComPtr<IWbemClassObject> pOutParams;
				WMIGetMethodOParams(pClass, L"getKVMState", &pOutParams.p);
				BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
				BREAKIF(WMIPut<1>(pOutParams, L"hardEnabled", KVMhardEnabledState));
				BREAKIF(WMIPut<1>(pOutParams, L"softEnabled", KVMsoftEnabledState));
				BREAKIF(WMIPut<1>(pOutParams, L"active", active));
				pResponseHandler->Indicate(1, &pOutParams.p);
			} while (0);
		} while(0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);	
	return hr;
}

HRESULT AMT_Service_WMI_Provider::TerminateKVMSession(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	std::wstring OTP, PKIDNSSuffix;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do{
			WSmanCommands wsmc;
			ReturnValue = wsmc.TerminateKVMSession();
			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"TerminateKVMSession", &pOutParams.p);
			BREAKIF(WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue));
			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::setSpriteZoom(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	std::wstring OTP, PKIDNSSuffix;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		if(!pInParams)
			RETURNIF(WBEM_E_INVALID_METHOD_PARAMETERS);

		do{

			short zoom = 1;
			bool specified = false;
			GetParamBREAKIF(WMIGet<1>(pNamespace, pInParams, L"zoom", zoom, specified),L"zoom");
			if (!specified)
				return WBEM_E_INVALID_METHOD_PARAMETERS;
			WSmanCommands wsmc;
			ReturnValue = wsmc.setSpriteZoom(zoom);
			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"setSpriteZoom", &pOutParams.p);
			BREAKIF(WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue));
			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::setSpriteLocale(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 hr = 0;

	//since 8.0 this function is not supported anymore
	hr = WBEM_E_NOT_SUPPORTED;
	pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getBootCapabilities(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			BootCapabilitiesWSMan caps;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetBootCapabilities(caps);
			ERROR_HANDLER(ReturnValue);

			WMIGetMethodOParams(pClass, L"getBootCapabilities", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"IDER", caps.IDER));
			BREAKIF(WMIPut<1>(pOutParams, L"SOL", caps.SOL));
			BREAKIF(WMIPut<1>(pOutParams, L"BIOSReflash", caps.BIOSReflash));
			BREAKIF(WMIPut<1>(pOutParams, L"BIOSSetup", caps.BIOSSetup));
			BREAKIF(WMIPut<1>(pOutParams, L"BIOSPause", caps.BIOSPause));
			BREAKIF(WMIPut<1>(pOutParams, L"ForcePXEBoot", caps.ForcePXEBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceHardDriveBoot", caps.ForceHardDriveBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceDiagnosticBoot", caps.ForceDiagnosticBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceCDorDVDBoot", caps.ForceCDorDVDBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"VerbosityScreenBlank", caps.VerbosityScreenBlank));
			BREAKIF(WMIPut<1>(pOutParams, L"PowerButtonLock", caps.PowerButtonLock));
			BREAKIF(WMIPut<1>(pOutParams, L"ResetButtonLock", caps.ResetButtonLock));
			BREAKIF(WMIPut<1>(pOutParams, L"KeyboardLock", caps.KeyboardLock));
			BREAKIF(WMIPut<1>(pOutParams, L"SleepButtonLock", caps.SleepButtonLock));
			BREAKIF(WMIPut<1>(pOutParams, L"UserPasswordBypass", caps.UserPasswordBypass));
			BREAKIF(WMIPut<1>(pOutParams, L"ForcedProgressEvents", caps.ForcedProgressEvents));
			BREAKIF(WMIPut<1>(pOutParams, L"VerbosityVerbose", caps.VerbosityVerbose));
			BREAKIF(WMIPut<1>(pOutParams, L"VerbosityQuiet", caps.VerbosityQuiet));
			BREAKIF(WMIPut<1>(pOutParams, L"ConfigurationDataReset", caps.ConfigurationDataReset));
			BREAKIF(WMIPut<1>(pOutParams, L"BIOSSecureBoot", caps.BIOSSecureBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"SecureErase", caps.SecureErase));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceWinREBoot", caps.ForceWinREBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceUEFIPBABoot", caps.ForceUEFIPBABoot));
			BREAKIF(WMIPut<1>(pOutParams, L"ForceUEFIHTTPSBoot", caps.ForceUEFIHTTPSBoot));
			BREAKIF(WMIPut<1>(pOutParams, L"AMTSecureBootControl", caps.AMTSecureBootControl));
			BREAKIF(WMIPut<1>(pOutParams, L"UEFIWiFiCoExistenceAndProfileShare", caps.UEFIWiFiCoExistenceAndProfileShare));
			BREAKIF(WMIPut<1>(pOutParams, L"PlatformErase", caps.PlatformErase));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getEnvironmentDetectionSettingData(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			EnvironmentDetectionWSMan detection;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetEnvironmentDetection(detection);
			ERROR_HANDLER(ReturnValue);

			// WMIPut requires wstring arrays; convert each element of the string vectors returned by WSMan.
			std::vector<std::wstring> wDetectionStrings;
			for (const auto& s : detection.DetectionStrings)
				wDetectionStrings.push_back(ToWStr(s));

			std::vector<std::wstring> wDetectionIPv6LocalPrefixes;
			for (const auto& s : detection.DetectionIPv6LocalPrefixes)
				wDetectionIPv6LocalPrefixes.push_back(ToWStr(s));

			WMIGetMethodOParams(pClass, L"getEnvironmentDetectionSettingData", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"DetectionAlgorithm", detection.DetectionAlgorithm));
			BREAKIF(WMIPut<1>(pOutParams, L"DetectionStrings", wDetectionStrings));
			BREAKIF(WMIPut<1>(pOutParams, L"DetectionIPv6LocalPrefixes", wDetectionIPv6LocalPrefixes));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getGeneralSettings(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			GeneralSettingsWSMan settings;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetGeneralSettings(settings);
			ERROR_HANDLER(ReturnValue);

			std::wstring wDigestRealm = ToWStr(settings.DigestRealm);
			std::wstring wHostName = ToWStr(settings.HostName);
			std::wstring wDomainName = ToWStr(settings.DomainName);
			std::wstring wHostOSFQDN = ToWStr(settings.HostOSFQDN);

			WMIGetMethodOParams(pClass, L"getGeneralSettings", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"NetworkInterfaceEnabled", settings.NetworkInterfaceEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"DigestRealm", wDigestRealm));
			BREAKIF(WMIPut<1>(pOutParams, L"IdleWakeTimeout", settings.IdleWakeTimeout));
			BREAKIF(WMIPut<1>(pOutParams, L"HostName", wHostName));
			BREAKIF(WMIPut<1>(pOutParams, L"DomainName", wDomainName));
			BREAKIF(WMIPut<1>(pOutParams, L"PingResponseEnabled", settings.PingResponseEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"WsmanOnlyMode", settings.WsmanOnlyMode));
			BREAKIF(WMIPut<1>(pOutParams, L"PreferredAddressFamily", settings.PreferredAddressFamily));
			BREAKIF(WMIPut<1>(pOutParams, L"DHCPv6ConfigurationTimeout", settings.DHCPv6ConfigurationTimeout));
			BREAKIF(WMIPut<1>(pOutParams, L"SharedFQDN", settings.SharedFQDN));
			BREAKIF(WMIPut<1>(pOutParams, L"HostOSFQDN", wHostOSFQDN));
			BREAKIF(WMIPut<1>(pOutParams, L"AMTNetworkEnabled", settings.AMTNetworkEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"RmcpPingResponseEnabled", settings.RmcpPingResponseEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"PresenceNotificationInterval", settings.PresenceNotificationInterval));
			BREAKIF(WMIPut<1>(pOutParams, L"PrivacyLevel", settings.PrivacyLevel));
			BREAKIF(WMIPut<1>(pOutParams, L"PowerSource", settings.PowerSource));
			BREAKIF(WMIPut<1>(pOutParams, L"ThunderboltDockEnabled", settings.ThunderboltDockEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"OemID", settings.OemID));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getAMTConfiguration(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			AMTConfigurationWSMan config;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetAMTConfiguration(config);
			ERROR_HANDLER(ReturnValue);

			std::wstring wDhcpDNSSuffix = ToWStr(config.DhcpDNSSuffix);
			std::wstring wTrustedDNSSuffix = ToWStr(config.TrustedDNSSuffix);

			WMIGetMethodOParams(pClass, L"getAMTConfiguration", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"DhcpDNSSuffix", wDhcpDNSSuffix));
			BREAKIF(WMIPut<1>(pOutParams, L"TrustedDNSSuffix", wTrustedDNSSuffix));
			BREAKIF(WMIPut<1>(pOutParams, L"ZeroTouchConfigurationEnabled", config.ZeroTouchConfigurationEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"ProvisioningMode", config.ProvisioningMode));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getWiFiPortConfiguration(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			WiFiPortConfigWSMan wifiConfig;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetWiFiPortConfiguration(wifiConfig);
			ERROR_HANDLER(ReturnValue);

			std::wstring wLastConnectedSsid = ToWStr(wifiConfig.LastConnectedSsidUnderMeControl);

			WMIGetMethodOParams(pClass, L"getWiFiPortConfiguration", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"LastConnectedSsidUnderMeControl", wLastConnectedSsid));
			BREAKIF(WMIPut<1>(pOutParams, L"UEFIWiFiProfileShareEnabled", wifiConfig.UEFIWiFiProfileShareEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"LocalProfileSynchronizationEnabled", wifiConfig.LocalProfileSynchronizationEnabled));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getWiFiEndpointState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			WiFiEndpointStateWSMan wifiState;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetWiFiEndpointState(wifiState);
			ERROR_HANDLER(ReturnValue);

			std::wstring wMACAddress = ToWStr(wifiState.MACAddress);

			WMIGetMethodOParams(pClass, L"getWiFiEndpointState", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"MACAddress", wMACAddress));
			BREAKIF(WMIPut<1>(pOutParams, L"HealthState", wifiState.HealthState));
			BREAKIF(WMIPut<1>(pOutParams, L"EnabledState", wifiState.EnabledState));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getCIRALog(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			std::string ciraLogData = "";
			// CIRA log is not accessible via WSMan, hence PTHI instead of WSmanCommands.
			PTHI_Commands pthic;
			ReturnValue = pthic.GetCIRALog(ciraLogData);
			ERROR_HANDLER(ReturnValue);

			// Convert string to wstring as required for WMIPut
			std::wstring wciraLogData(ciraLogData.begin(), ciraLogData.end());

			WMIGetMethodOParams(pClass, L"getCIRALog", &pOutParams.p);

			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"ciraLog", wciraLogData));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getTimeSynchronizationConfig(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			TimeSyncConfigWSMan timeConfig;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetTimeSyncConfig(timeConfig);
			ERROR_HANDLER(ReturnValue);

			WMIGetMethodOParams(pClass, L"getTimeSynchronizationConfig", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"AMTTime", timeConfig.AMTTime));
			BREAKIF(WMIPut<1>(pOutParams, L"LocalTimeSyncEnabled", timeConfig.LocalTimeSyncEnabled));
			BREAKIF(WMIPut<1>(pOutParams, L"TimeSource", timeConfig.TimeSource));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::getOptInConfiguration(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do {
			CComPtr<IWbemClassObject> pOutParams;
			OptInConfigWSMan optInConfig;
			WSmanCommands wsmc;
			ReturnValue = wsmc.GetOptInConfig(optInConfig);
			ERROR_HANDLER(ReturnValue);

			WMIGetMethodOParams(pClass, L"getOptInConfiguration", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"OptInCodeTimeout", optInConfig.OptInCodeTimeout));
			BREAKIF(WMIPut<1>(pOutParams, L"OptInRequired", optInConfig.OptInRequired));
			BREAKIF(WMIPut<1>(pOutParams, L"OptInState", optInConfig.OptInState));
			BREAKIF(WMIPut<1>(pOutParams, L"OptInDisplayTimeout", optInConfig.OptInDisplayTimeout));

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	HRESULT hr = 0;
	EntryExitLogShort log(__FUNCTION__, hr);

	try
	{
		// Flow:
		// 1) Build the single AMT_Service WMI instance identity fields.
		// 2) Populate the class keys and naming properties.
		// 3) Publish the completed instance through pResponseHandler->Indicate.
		do {
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_Service"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"AMT_Service"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel AMT Service"));
			BREAKIF(WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system"));

			pResponseHandler->Indicate(1, &obj.p);
		} while (0);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT AMT_Service_WMI_Provider::GetAMT_Service(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	HRESULT hr = 0;
	EntryExitLogShort log(__FUNCTION__, hr);

	try
	{
		std::map <std::wstring, CComVariant> keyList;
		std::map <std::wstring, CComVariant>::const_iterator it;
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"Name");
		if (it == keyList.end())
		{
			hr = WBEM_E_INVALID_METHOD_PARAMETERS;
			return hr;
		}

		do 
		{
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_Service"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"AMT_Service"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel AMT Service"));
			BREAKIF(WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system"));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		}while(0);

		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}
