/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: OOB_Service_WMI_Provider.cpp

--*/

#include "OOB_Service_WMI_Provider.h"
#include "StringManipulator.h"
#include "pthi_commands.h"
#include "WMIHelper.h"
#include "MEProvMessageUtil.h" 
#include "CryptUtils_w.h" 
#include <iostream>
#include <sstream>
#include <string>
	  

HRESULT IsUserAdmin();
HRESULT getApplicationDetails(string& userNameStr, string& domainNameStr, string& applicationName);

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
	uint32 ReturnValue = 0;
	uint32 hr = 0;


	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		uint8 provisioningMode;
		PTHI_Commands pthic;
		ReturnValue = pthic.GetProvisioningMode(provisioningMode);

		ERROR_HANDLER(ReturnValue);

		WMIGetMethodOParams(pClass, L"GetAMTProvisioningMode", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		uint8 mode = (uint8)provisioningMode;
		WMIPut<1>( pOutParams, L"mode", mode);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetProvisioningState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;

 // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		SHORT state = 0;
		PTHI_Commands pthic;
		ReturnValue = pthic.GetProvisioningState(&state);
		ERROR_HANDLER(ReturnValue);
		
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetProvisioningState", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"state", state);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::Activate(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	USES_CONVERSION; 
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));
	if (IsUserAdmin() == S_FALSE)
	{
		hr = WBEM_E_ACCESS_DENIED;
		pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
		return hr ;
	}

	try
	{
		if(!pInParams)
			RETURNIF(WBEM_E_INVALID_METHOD_PARAMETERS);

		do{

			bool specified;
			GetParamBREAKIF(WMIGet<1>(pNamespace, pInParams, L"OTP", OTP, specified ), L"OTP");
			if (!specified)
				OTP = L"";
			GetParamBREAKIF(WMIGet<1>(pNamespace, pInParams, L"PKIDNSSuffix", PKIDNSSuffix, specified ),L"PKIDNSSuffix");
			if (!specified)
				PKIDNSSuffix = L"";
			if (OTP.length() >= 300 || PKIDNSSuffix.length() >= 300)
			{
				hr = WBEM_E_PROPERTY_NAME_TOO_WIDE;
				pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
				return hr ;
			}

			SHORT provTLSMode=0;
			PTHI_Commands pthic;
			ReturnValue = pthic.ZTCActivate(ToStr(OTP), ToStr(PKIDNSSuffix), &provTLSMode);


			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"Activate", &pOutParams.p);
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
			WMIPut<1>( pOutParams, L"provTLSMode", provTLSMode);

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while(0);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::isTLSEnabled(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		bool enabled = false;
		PTHI_Commands pthic;
		ReturnValue = pthic.GetTLSEnabled(&enabled);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"isTLSEnabled", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"enabled", enabled);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}



HRESULT OOB_Service_WMI_Provider::GetPID(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring pid = L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.GetPID(&pid);
		
		ERROR_HANDLER(ReturnValue);
		
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetPID", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"PID", pid);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetActivationTLSMode(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetActivationTLSMode", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		SHORT tlsMode = 0;
		PTHI_Commands pthic;
		pthic.GetProvisioningTlsMode(&tlsMode);

		ERROR_HANDLER(ReturnValue);

		WMIPut<1>( pOutParams, L"mode", tlsMode);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("Profile data"), _T("Enumerate started"),_T(""));
	//Get all keys in a colllection, from an internal function
	uint32 hr = 0;
	try
	{
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"OOB_Service"));
			WMIPut<1>(obj, L"CreationClassName", L"OOB_Service");
			WMIPut<1>(obj, L"Name", L"Intel ME Out Of Band Service");
			WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT");
			WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system");
			
			pResponseHandler->Indicate(1, &obj.p);

	}
	catch (...)
	{
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
	}
	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	//Enumarate the collection, retrieving params and creating return instances
	//if (STATUS_SUCCESS == hr)
	//{
	//	_Module.logger.Info(File,LOCATION,  _T("Profile data"), _T("Enumerate finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION,  _T("Profile data"), _T("Enumerate failed with error code"),_T("StringUtilsNamespace::convertTowString(hr)"));
	//}

	return hr;

}

HRESULT OOB_Service_WMI_Provider::isRemoteConfigEnabled(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		bool enabled=false;
		PTHI_Commands pthic;
		ReturnValue = pthic.isRemoteConfigEnabled(&enabled);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"isRemoteConfigEnabled", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"enabled", enabled);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetConfigServerAddressInfo(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring address;
		UINT16 port = 9971;//CHANGE!!
		PTHI_Commands pthic;
		ReturnValue = pthic.GetConfigServerData(&address, &port);

		ERROR_HANDLER(ReturnValue);

		//std::wstring temp(address.length(),L' ');
		//std::copy(address.begin(), address.end(), temp.begin());

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetHelloPacketDestInfo", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"address", address);
		WMIPut<1>( pOutParams, L"ConfigServerListeningPort", port);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::isWiredLinkUp(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		bool enabled=false;
		PTHI_Commands pthic;
		ReturnValue = pthic.isWiredLinkUp(&enabled);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"isWiredLinkUp", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"linkUp", enabled);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::GetProvisioningInfo(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring address=L"", dnssuffix=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.GetProvisioningInfo(&dnssuffix, &address);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetProvisioningInfo", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"PKIDNSSuffix", dnssuffix);
		WMIPut<1>( pOutParams, L"ConfigServerFQDN", address);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::GetRemoteAccessConnectionStatus(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring MPshostName=L"";
		SHORT NetworkConStatus=0, ConnectionTrigger=0, RemoteAccessConStatus=0;

		PTHI_Commands pthic;
		ReturnValue = pthic.GetRemoteAccessConnectionStatus(&ConnectionTrigger, &NetworkConStatus, &MPshostName, &RemoteAccessConStatus);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetRemoteAccessConnectionStatus", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"NetworkConStatus", NetworkConStatus);
		WMIPut<1>( pOutParams, L"ConnectionTrigger", ConnectionTrigger);
		WMIPut<1>( pOutParams, L"MPshostName", MPshostName);
		WMIPut<1>( pOutParams, L"RemoteAccessConStatus", RemoteAccessConStatus);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::GetAMTFQDN(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring FQDN=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.GetAMTFQDN(&FQDN);

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"GetAMTFQDN", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"FQDN", FQDN);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::OpenUserInitiatedConnection(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring FQDN=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.OpenCIRA();

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"OpenUserInitiatedConnection", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::CloseUserInitiatedConnection(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	try
	{
		wstring FQDN=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.CloseCIRA();

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"CloseUserInitiatedConnection", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}


HRESULT OOB_Service_WMI_Provider::CancelActivation(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	std::wstring OTP, PKIDNSSuffix;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));

	if (IsUserAdmin() == S_FALSE)
	{
		hr = WBEM_E_ACCESS_DENIED;
		pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
		return hr ;
	}

	try
	{
		wstring FQDN=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.StopConfiguration();

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"CloseUserInitiatedConnection", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	


	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}







HRESULT OOB_Service_WMI_Provider::GetOOB_Service(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));

	uint32 hr = 0;
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;

	try
	{
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"Name");
		if (it == keyList.end())
		{
			//_Module.logger.Error(File,LOCATION, _T("WiFi Profile data"), _T("AddWiFiProfile"),_T("WBEM_E_INVALID_METHOD_PARAMETERS"));
			//_Module.SetLastErrorString(GETSCSMESSAGE1(ERROR_IN_PARAMETER,_T("InstanceID")));
			return  WBEM_E_INVALID_METHOD_PARAMETERS;
		}

		//unsigned long id = 0;
		//std::wstring val = (it->second).bstrVal;
		//StringUtilsNamespace::FromwString(val,id);

		//_Module.logger.Info(File,LOCATION, _T("Profile data"), _T("Get profile object started"),_T("Profile:")+ StringUtilsNamespace::convertTowString(id));

		//SCS_Profile profile;
		do 
		{
			//hr = SCS_Profile_WMIProviderImpl::GetProfileObject(id,profile)	;

			//if (STATUS_SUCCESS != hr)
			//{
			//	break;
			//}

			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"OOB_Service"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel ME Out Of Band Service"));
			BREAKIF(WMIPut<1>(obj, L"SystemName", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"SystemCreationClassName", L"ME_system"));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		}while(0);

		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);

		//Enumarate the collection, retrieving params and creating return instances
		if (STATUS_SUCCESS == hr)
		{
			//_Module.logger.Info(File,LOCATION,  _T("Profile data"), _T("Get profile  finished successfully"),_T(""));
		}
		else
		{
			//_Module.logger.Error(File,LOCATION,  _T("Profile data"), _T("Get profile failed with error code"),_T("StringUtilsNamespace::convertTowString(hr)"));
		}
	}
	catch (...)
	{
		//_Module.SetLastErrorString(GETSCSMESSAGE(ERROR_EXCEPTION_IN_SERVICE));
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
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
	USES_CONVERSION; 
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	WindowsEventLog windowsEventLog(EVENT_LOG_APPLICATION, ME_PPROV_NAME, EVENT_CATEGORY_NUMBER, "MEProv.dll");
	string userName, domain, applicationName;
	getApplicationDetails(userName, domain, applicationName);
	std::wstring MEBxPwd;

   // _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));
	bool success = false;
	

	try
	{
		

		do{
			if (IsUserAdmin() == S_FALSE)
			{
				hr = WBEM_E_ACCESS_DENIED;
				pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
				break; ;
			}
			//if(!pInParams)
			//{
			//	hr = WBEM_E_INVALID_METHOD_PARAMETERS;
			//	break;
			//}
			PTHI_Commands pthic;
			ReturnValue = pthic.Unprovision();
			ERROR_HANDLER(ReturnValue);
			if (ReturnValue == S_OK)
			{
				success = true;
			}
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"Unconfigure", &pOutParams.p);
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);

			pResponseHandler->Indicate(1, &pOutParams.p);
			WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	
		} while(0);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	
	}

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	
	
	string successStr;
	if (success)
	{
		successStr = "succeeded";
	} else 
	{
		successStr = "failed";
	}
	string message;
	stringstream messageStream;
	messageStream << "Unconfigure request was invoked.\n";
	messageStream << "Request " << successStr << "\n";
		//"Calling application: " + applicationName\n" + 
	messageStream << "Calling User: " << domain << "/" << userName << "\n"; 
	message = messageStream.str();
	windowsEventLog.LogEvent(ME_PROVIDER_EVENT, LOCAL_ADMIN_REQUEST, EVENTLOG_INFORMATION_TYPE, message.c_str());
	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

HRESULT OOB_Service_WMI_Provider::GetLocalAdminCredentials(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	USES_CONVERSION; 
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	WindowsEventLog windowsEventLog(EVENT_LOG_APPLICATION, ME_PPROV_NAME, EVENT_CATEGORY_NUMBER, "MEProv.dll");
	// _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Step in"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList started"),_T(""));
	string userName, domain, applicationName;
	getApplicationDetails(userName, domain, applicationName);
	
	wstring userNameWStr;
	wstring passwordWStr;
	string passwordStr;

	bool success = false;	
	try
	{
		
		do{
			if (IsUserAdmin() == S_FALSE)
			{
				hr = WBEM_E_ACCESS_DENIED;
				pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
				break;
			}

			LOCAL_SYSTEM_ACCOUNT localAccount;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetLocalSystemAccount(&localAccount);
			ERROR_HANDLER(ReturnValue);

			if (ReturnValue == S_OK)
			{
				success = true;
				
				userNameWStr = wstring(ToWStr(localAccount.UserName.c_str()));

				passwordStr = WSmanCrypt::DecryptString(localAccount.Password);
				passwordWStr =  wstring(ToWStr(passwordStr.c_str()));

			}
			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"GetLocalAdminCredentials", &pOutParams.p);
			WMIPut<1>( pOutParams, L"Username", userNameWStr);
			WMIPut<1>( pOutParams, L"Password", passwordWStr);
			WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
	
			pResponseHandler->Indicate(1, &pOutParams.p);
			WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	
			
		} while(0);
	}
	catch(...)
	{
	   // _Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	
	}
	std::fill(passwordStr.begin(), passwordStr.end(), 0);
	std::fill(passwordWStr.begin(), passwordWStr.end(), 0);

	//wstring tmp_val = _T("return value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(ReturnValue);
	//tmp_val += _T(", hr value: ");
	//tmp_val += StringUtilsNamespace::convertTowString(hr);

	 //   _Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Done CreatePSKCredentialList"),tmp_val);


	
	
	string successStr;
	if (success)
	{
		successStr = "succeeded";
	} else 
	{
		successStr = "failed";
	}
	string message;
	stringstream messageStream;
	messageStream << "GetLocalAdminCredentials request was invoked.\n";
	messageStream << "Request " << successStr << "\n";
		//"Calling application: " + applicationName\n" + 
	messageStream << "Calling User: " << domain << "/" << userName << "\n"; 
	message = messageStream.str();
	windowsEventLog.LogEvent(ME_PROVIDER_EVENT, UNCONFIGURE_REQUEST, EVENTLOG_INFORMATION_TYPE, message.c_str());

	//if (hr == STATUS_SUCCESS)
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request finished successfully"),_T(""));
	//}
	//else
	//{
	//	_Module.logger.Info(File,LOCATION, _T("PSK Credential data"), _T("Create PSK CredentialList request failed with error code"),StringUtilsNamespace::convertTowString(hr));
	//}
	return hr;
}

