/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: OOB_Service_WMI_Provider.cpp

--*/

#include "OOB_Service_WMI_Provider.h"
#include "StringManipulator.h"
#include "pthi_commands.h"
#include "WMIHelper.h"
#include "MEProvMessageUtil.h" 
#include <iostream>
#include <sstream>
#include <string>

HRESULT getApplicationDetails(std::string& userNameStr, std::string& domainNameStr, std::string& applicationName);

HRESULT OOB_Service_WMI_Provider::DispatchMethods(
									  const BSTR                  strMethodName,
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
			if(CComBSTR(strMethodName) == L"GetProvisioningState")
				hr = GetProvisioningState(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetAMTProvisioningMode")
				hr = GetAMTProvisioningMode(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"Activate")
				hr = Activate(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"isTLSEnabled")
				hr = isTLSEnabled(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetPID")
				hr = GetPID(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetActivationTLSMode")
				hr = GetActivationTLSMode(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"isRemoteConfigEnabled")
				hr = isRemoteConfigEnabled(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetHelloPacketDestInfo")
				hr = GetConfigServerAddressInfo(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"isWiredLinkUp")
				hr = isWiredLinkUp(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetProvisioningInfo")
				hr = GetProvisioningInfo(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetRemoteAccessConnectionStatus")
				hr = GetRemoteAccessConnectionStatus(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetAMTFQDN")
				hr = GetAMTFQDN(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"CancelActivation")
				hr = CancelActivation(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"OpenUserInitiatedConnection")
				hr = OpenUserInitiatedConnection(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"CloseUserInitiatedConnection")
				hr = CloseUserInitiatedConnection(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"Unconfigure")
				hr = Unconfigure(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"GetLocalAdminCredentials")
				hr = GetLocalAdminCredentials(pClass, pInParams, pResponseHandler, pNamespace);
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

HRESULT OOB_Service_WMI_Provider::GetAMTProvisioningMode(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 hr = WBEM_E_NOT_SUPPORTED;

	pResponseHandler->SetStatus(0, hr, NULL, NULL);
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetProvisioningState(
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
			SHORT state = 0;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetProvisioningState(&state);
			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetProvisioningState", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"state", state));

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

HRESULT OOB_Service_WMI_Provider::Activate(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 hr = WBEM_E_NOT_SUPPORTED;

	pResponseHandler->SetStatus(0, hr, NULL, NULL);
	return hr;
}

HRESULT OOB_Service_WMI_Provider::isTLSEnabled(
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
			bool enabled = false;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetTLSEnabled(&enabled);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"isTLSEnabled", &pOutParams.p);
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

HRESULT OOB_Service_WMI_Provider::GetPID(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 hr = WBEM_E_NOT_SUPPORTED;

	pResponseHandler->SetStatus(0, hr, NULL, NULL);
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetActivationTLSMode(
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
			const SHORT PKI_TLS_MODE = 0x2;
			SHORT tlsMode = PKI_TLS_MODE;
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetActivationTLSMode", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"mode", tlsMode));

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

HRESULT OOB_Service_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	//Get all keys in a colllection, from an internal function
	HRESULT hr = 0;
	EntryExitLogShort log(__FUNCTION__, hr);
	try
	{
		do {
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel ME Out Of Band Service"));
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

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	return hr;
}

HRESULT OOB_Service_WMI_Provider::isRemoteConfigEnabled(
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
			bool enabled = false;
			PTHI_Commands pthic;
			ReturnValue = pthic.isRemoteConfigEnabled(&enabled);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"isRemoteConfigEnabled", &pOutParams.p);
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

HRESULT OOB_Service_WMI_Provider::GetConfigServerAddressInfo(
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
			std::wstring address;
			UINT16 port = 9971;//CHANGE!!
			PTHI_Commands pthic;
			ReturnValue = pthic.GetConfigServerData(&address, &port);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetHelloPacketDestInfo", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"address", address));
			BREAKIF(WMIPut<1>(pOutParams, L"ConfigServerListeningPort", port));

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

HRESULT OOB_Service_WMI_Provider::isWiredLinkUp(
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
			bool enabled = false;
			PTHI_Commands pthic;
			ReturnValue = pthic.isWiredLinkUp(&enabled);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"isWiredLinkUp", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"linkUp", enabled));

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

HRESULT OOB_Service_WMI_Provider::GetProvisioningInfo(
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
			std::wstring address = L"", dnssuffix = L"";
			PTHI_Commands pthic;
			ReturnValue = pthic.GetProvisioningInfo(&dnssuffix, &address);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetProvisioningInfo", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"PKIDNSSuffix", dnssuffix));
			BREAKIF(WMIPut<1>(pOutParams, L"ConfigServerFQDN", address));

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

HRESULT OOB_Service_WMI_Provider::GetRemoteAccessConnectionStatus(
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
			std::wstring MPshostName = L"";
			SHORT NetworkConStatus = 0, ConnectionTrigger = 0, RemoteAccessConStatus = 0;

			PTHI_Commands pthic;
			ReturnValue = pthic.GetRemoteAccessConnectionStatus(&ConnectionTrigger, &NetworkConStatus, &MPshostName, &RemoteAccessConStatus);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetRemoteAccessConnectionStatus", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"NetworkConStatus", NetworkConStatus));
			BREAKIF(WMIPut<1>(pOutParams, L"ConnectionTrigger", ConnectionTrigger));
			BREAKIF(WMIPut<1>(pOutParams, L"MPshostName", MPshostName));
			BREAKIF(WMIPut<1>(pOutParams, L"RemoteAccessConStatus", RemoteAccessConStatus));

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

HRESULT OOB_Service_WMI_Provider::GetAMTFQDN(
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
			std::wstring FQDN = L"";
			PTHI_Commands pthic;
			ReturnValue = pthic.GetAMTFQDN(&FQDN);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetAMTFQDN", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));
			BREAKIF(WMIPut<1>(pOutParams, L"FQDN", FQDN));

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

HRESULT OOB_Service_WMI_Provider::OpenUserInitiatedConnection(
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
			PTHI_Commands pthic;
			ReturnValue = pthic.OpenCIRA();

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"OpenUserInitiatedConnection", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));

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

HRESULT OOB_Service_WMI_Provider::CloseUserInitiatedConnection(
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
			PTHI_Commands pthic;
			ReturnValue = pthic.CloseCIRA();

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"CloseUserInitiatedConnection", &pOutParams.p);
			BREAKIF(WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue));

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

HRESULT OOB_Service_WMI_Provider::CancelActivation(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 hr = WBEM_E_NOT_SUPPORTED;

	pResponseHandler->SetStatus(0, hr, NULL, NULL);
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetOOB_Service(
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
		std::map <std::wstring, CComVariant>::const_iterator it ;
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
			RETURNIF(WMIPutMember(pNamespace, &obj, L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel ME Out Of Band Service"));
			BREAKIF(WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system"));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		}while(0);

		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}

HRESULT OOB_Service_WMI_Provider::Unconfigure(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);
	WindowsEventLog windowsEventLog(EVENT_LOG_APPLICATION, ME_PPROV_NAME, EVENT_CATEGORY_NUMBER, L"MEProv.dll");
	std::string userName, domain, applicationName;
	getApplicationDetails(userName, domain, applicationName);

	bool success = false;

	try
	{
		do {
			if (IsUserAdmin() == S_FALSE)
			{
				hr = WBEM_E_ACCESS_DENIED;
				pResponseHandler->SetStatus(0, hr, NULL, NULL);
				break;
			}
			PTHI_Commands pthic;
			ReturnValue = pthic.Unprovision();
			ERROR_HANDLER(ReturnValue);
			if (ReturnValue == S_OK)
			{
				success = true;
			}
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"Unconfigure", &pOutParams.p);
			BREAKIF(WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue));

			pResponseHandler->Indicate(1, &pOutParams.p);
			WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
		} while(0);
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}

	std::stringstream messageStream;
	messageStream << "Unconfigure request was invoked.\n";
	messageStream << "Request " << ((success) ? "succeeded" : "failed") << "\n";
	messageStream << "Calling User: " << domain << "/" << userName << "\n"; 
	windowsEventLog.LogEvent(ME_PROVIDER_EVENT, LOCAL_ADMIN_REQUEST, EVENTLOG_INFORMATION_TYPE, messageStream.str().c_str());

	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetLocalAdminCredentials(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);
	WindowsEventLog windowsEventLog(EVENT_LOG_APPLICATION, ME_PPROV_NAME, EVENT_CATEGORY_NUMBER, L"MEProv.dll");
	std::string userName, domain, applicationName;
	getApplicationDetails(userName, domain, applicationName);
	
	std::wstring userNameWStr;
	std::wstring passwordWStr;

	bool success = false;
	try
	{
		
		do {
			if (IsUserAdmin() == S_FALSE)
			{
				hr = WBEM_E_ACCESS_DENIED;
				pResponseHandler->SetStatus(0 , hr, NULL, NULL);
				break;
			}

			LOCAL_SYSTEM_ACCOUNT localAccount;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetLocalSystemAccount(&localAccount);
			ERROR_HANDLER(ReturnValue);

			if (ReturnValue == S_OK)
			{
				success = true;
				userNameWStr = ToWStr(localAccount.UserName);
				passwordWStr = ToWStr(localAccount.Password);
			}
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetLocalAdminCredentials", &pOutParams.p);
			BREAKIF(WMIPut<1>( pOutParams, L"Username", userNameWStr));
			BREAKIF(WMIPut<1>( pOutParams, L"Password", passwordWStr));
			BREAKIF(WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue));
	
			pResponseHandler->Indicate(1, &pOutParams.p);
			WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
			
		} while(0);
	}
	catch(...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	std::fill(passwordWStr.begin(), passwordWStr.end(), 0);

	std::stringstream messageStream;
	messageStream << "GetLocalAdminCredentials request was invoked.\n";
	messageStream << "Request " << ((success) ? "succeeded" : "failed") << "\n";
	messageStream << "Calling User: " << domain << "/" << userName << "\n"; 
	windowsEventLog.LogEvent(ME_PROVIDER_EVENT, UNCONFIGURE_REQUEST, EVENTLOG_INFORMATION_TYPE, messageStream.str().c_str());

	return hr;
}
