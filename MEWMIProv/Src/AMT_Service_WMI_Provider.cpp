/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: AMT_Service_WMI_Provider.cpp

--*/

#include "AMT_Service_WMI_Provider.h"
#include "pthi_commands.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"


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
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		SHORT enabled=0;
		PTHI_Commands pthic;
		ReturnValue = pthic.getWebUIState(&enabled);
		
		ERROR_HANDLER(ReturnValue);

		WMIGetMethodOParams(pClass, L"isWebUIEnabled", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"enabled", enabled);

		pResponseHandler->Indicate(1, &pOutParams.p);
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
	uint32 hr = 0;
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
		
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getSOLState", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"active", SOLactive);
		WMIPut<1>( pOutParams, L"hardEnabled", SOLhardEnabledState);
		WMIPut<1>( pOutParams, L"softEnabled", SOLsoftEnabledState);

		pResponseHandler->Indicate(1, &pOutParams.p);
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
	uint32 hr = 0;
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
		
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getIDERState", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"hardEnabled", IDERhardEnabledState);
		WMIPut<1>( pOutParams, L"softEnabled", IDERsoftEnabledState);
		WMIPut<1>( pOutParams, L"active", IDERactive);

		pResponseHandler->Indicate(1, &pOutParams.p);
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
	uint32 hr = 0;
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
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"getKVMState", &pOutParams.p);
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
			WMIPut<1>( pOutParams, L"hardEnabled", KVMhardEnabledState);
			WMIPut<1>( pOutParams, L"softEnabled", KVMsoftEnabledState);
			WMIPut<1>( pOutParams, L"active", active);
			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
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
	uint32 hr = 0;
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
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
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
	uint32 hr = 0;
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
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
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

HRESULT AMT_Service_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, hr);

	try
	{
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_Service"));
			WMIPut<1>(obj, L"CreationClassName", L"AMT_Service");
			WMIPut<1>(obj, L"Name", L"Intel AMT Service");
			WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT");
			WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system");
			
			pResponseHandler->Indicate(1, &obj.p);
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
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, hr);

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
