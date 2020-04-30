/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: ME_System_WMI_Provider.cpp

--*/

#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "FWUpdate_Commands.h"
#include "GetFWVersionCommand.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"
#include "WMIHelper.h"
#include <sstream>



HRESULT ME_System_WMI_Provider::DispatchMethods(
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
			if(CComBSTR(strMethodName) == L"getLastMEResetReason")
				hr = getLastMEResetReason(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getCurrentPowerPolicy")
				hr = getCurrentPowerPolicy(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"IsFirmwareUpdateEnabled")
				hr = IsFirmwareUpdateEnabled(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getFwUpdateOverrideParams")
				hr = getFwUpdateOverrideParams(pClass, pInParams, pResponseHandler, pNamespace);
			else if(CComBSTR(strMethodName) == L"getCapabilities")
				hr = getCapabilitiesStrings(pClass, pInParams, pResponseHandler, pNamespace);
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

HRESULT ME_System_WMI_Provider::Enumerate(
	IWbemServices* pNamespace,
	IWbemContext __RPC_FAR *pCtx,
	IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	//Get all keys in a colllection, from an internal function
	uint32 hr = WBEM_S_NO_ERROR;
	uint32 ReturnValue = 0;
	try
	{
		do{
			wstring fwversion = L"";
			bool CryptoFuseEnabled = false;
			uint16 val;
			vector<sint16> OperationalStatus;
			uint32 type, segment, mode, capabilities, enabledCapabilities;

			ReturnValue = GetMESystem(fwversion, CryptoFuseEnabled, val,
										 OperationalStatus, type, segment, 
										 mode, capabilities, enabledCapabilities);
			if (ReturnValue != S_OK)
			{
				WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
				break;
			}
	
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"ME_System"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"ME_system"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"FWVersion", fwversion));
			BREAKIF(WMIPut<1>(obj, L"Capabilities", capabilities));
			BREAKIF(WMIPut<1>(obj, L"EnabledCapabilities", enabledCapabilities));
			BREAKIF(WMIPut<1>(obj, L"CryptoFuseEnabled", CryptoFuseEnabled));
			BREAKIF(WMIPut<1>(obj, L"PlatformType", type));
			BREAKIF(WMIPut<1>(obj, L"UserSegmentType", segment));
			BREAKIF(WMIPut<1>(obj, L"ManageabilityMode", mode));

			BREAKIF(WMIPut<1>(obj, L"ElementName", L"Intel(r) AMT Subsystem"));
			BREAKIF(WMIPut<1>(obj, L"EnabledDefault", val));
			BREAKIF(WMIPut<1>(obj, L"EnabledState", val));
			BREAKIF(WMIPut<1>(obj, L"HealthState", val));
			val = 12;
			BREAKIF(WMIPut<1>(obj, L"RequestedState", val));
			BREAKIF(WMIPut<1>(obj, L"NameFormat", L"Other"));
			BREAKIF(WMIPut<sint16>(obj, L"OperationalStatus", OperationalStatus));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		}while(0);

	}
	catch (...)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
	}
	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	return hr;

}

HRESULT ME_System_WMI_Provider::getLastMEResetReason(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	UINT32 ReturnValue = 0;
	HRESULT hr = S_OK;


	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		uint32 ReasonCode=0;
		bool cryptoFuseEnabled; 
		PTHI_Commands pthic; 
		ReturnValue = pthic.GetAMTState(&ReasonCode, &cryptoFuseEnabled);		
		
		if (ReturnValue != S_OK)
		{
			if (ReturnValue != WMI_E_HECI_CONNECTION &&
				ReturnValue != WMI_E_PTHI_CLIENT_CONNECTION &&
				ReturnValue != WMI_E_FWUPD_CLIENT_CONNECTION)
			{
				ReturnValue = WMI_E_MESTATUS_BASE + ReturnValue;
			}

		}

		WMIGetMethodOParams(pClass, L"getLastMEResetReason", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"ReasonCode", ReasonCode);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	

	return hr;
}

HRESULT ME_System_WMI_Provider::getCurrentPowerPolicy(
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
		wstring powerPolicy=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.GetPowerPolicy(&powerPolicy);
		WMIGetMethodOParams(pClass, L"getCurrentPowerPolicy", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"PowerPolicy", powerPolicy);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}



	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	

	return hr;
}

HRESULT ME_System_WMI_Provider::IsFirmwareUpdateEnabled(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;


	try
	{
		bool enabled = false;
		char str[256];

		FWUpdate_Commands FWUpdate;
		{
			using namespace Intel::MEI_Client;
		
			ReturnValue = FWUpdate.GetFWUpdateStateCommand(&enabled);
			if (ReturnValue != S_OK)
				enabled = false;
		}
		sprintf_s(str,256,"FWUpdate.MEGetFWUpdateVersion.EnabledUpdateInterfaces=%d rc=%d\n",enabled,ReturnValue);
		OutputDebugStringA(str);
		
		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"IsFirmwareUpdateEnabled", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"enabled", enabled);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch(...)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	

	return hr;
}

HRESULT ME_System_WMI_Provider::getCapabilitiesStrings(
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
		vector<wstring> capabilities, enabledCapabilities;
		FWUpdate_Commands FWUpdate;
		
		{
			using namespace Intel::MEI_Client;
			MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData = { 0 }, StateData = { 0 };
			MKHI_Client::MKHI_PLATFORM_TYPE Platform = { 0 };
			ReturnValue = FWUpdate.GetFWCapabilities(CapabilityData);
			if (ReturnValue == S_OK)
			{
				ReturnValue = FWUpdate.GetFWFeaturesState(StateData);
				
				if (ReturnValue == S_OK)
				{
					ReturnValue = FWUpdate.GetFWPlatformType(Platform);
				}
				MEFWCAPS_SKU_INT capabilities_int;
				capabilities_int.Data = GetCapabilities_int(StateData, Platform);
				GetCapabilities(capabilities_int, enabledCapabilities);	
			}
			ERROR_HANDLER(ReturnValue);
			MEFWCAPS_SKU_INT capabilities_int;
			capabilities_int.Data = GetCapabilities_int(CapabilityData, Platform);
			GetCapabilities(capabilities_int, capabilities);
		}

		WMIGetMethodOParams(pClass, L"getCapabilities", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"Capabilities", capabilities);
		WMIPut<1>( pOutParams, L"EnabledCapabilities", enabledCapabilities);

		pResponseHandler->Indicate(1, &pOutParams.p);
		
	}
	catch(...)
	{
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue  = ERROR_EXCEPTION_IN_SERVICE;
	}


	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);	

	return hr;
}


HRESULT ME_System_WMI_Provider::getFwUpdateOverrideParams(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	//RCR 1023415 (ME FW update simplification RCR) implementation
	uint32 hr = WBEM_E_NOT_SUPPORTED;
	pResponseHandler->SetStatus ( 0 , hr , NULL , NULL ) ;
	return hr;
}

HRESULT ME_System_WMI_Provider::GetME_System(
	IWbemServices* pNamespace,
	const BSTR strObjectPath,
	IWbemContext __RPC_FAR *pCtx,
	IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	uint32 hr = 0;
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;

	try
	{
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"Name");
		if (it == keyList.end())
		{
			return  WBEM_E_INVALID_METHOD_PARAMETERS;
		}

		do 
		{
			wstring fwversion = L"";
			bool CryptoFuseEnabled = false;
			uint16 val;
			vector<sint16> OperationalStatus;
			uint32 type, segment, mode, capabilities, enabledCapabilities;

			hr = GetMESystem(fwversion, CryptoFuseEnabled, val,
										 OperationalStatus, type, segment, 
										 mode, capabilities, enabledCapabilities);
			if (hr != 0)
				break;
	
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"ME_System"));
			BREAKIF(WMIPut<1>(obj, L"CreationClassName", L"ME_system"));
			BREAKIF(WMIPut<1>(obj, L"Name", L"Intel(r) AMT"));
			BREAKIF(WMIPut<1>(obj, L"FWVersion", fwversion));
			BREAKIF(WMIPut<1>(obj, L"Capabilities", capabilities));
			BREAKIF(WMIPut<1>(obj, L"EnabledCapabilities", enabledCapabilities));
			BREAKIF(WMIPut<1>(obj, L"CryptoFuseEnabled", CryptoFuseEnabled));
			BREAKIF(WMIPut<1>(obj, L"PlatformType", type));
			BREAKIF(WMIPut<1>(obj, L"UserSegmentType", segment));
			BREAKIF(WMIPut<1>(obj, L"ManageabilityMode", mode));

			BREAKIF(WMIPut<1>(obj, L"ElementName", L"Intel(r) AMT Subsystem"));
			BREAKIF(WMIPut<1>(obj, L"EnabledDefault", val));
			BREAKIF(WMIPut<1>(obj, L"EnabledState", val));
			BREAKIF(WMIPut<1>(obj, L"HealthState", val));
			val = 12;
			BREAKIF(WMIPut<1>(obj, L"RequestedState", val));
			BREAKIF(WMIPut<1>(obj, L"NameFormat", L"Other"));
			BREAKIF(WMIPut<sint16>(obj, L"OperationalStatus", OperationalStatus));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		}while(0);

		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);

		//Enumerate the collection, retrieving params and creating return instances
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
		hr  = WBEM_E_PROVIDER_FAILURE;
	}


	return hr;

}



ME_System_WMI_Provider::CUSTOMER_TYPE ME_System_WMI_Provider::GetPlatformTypeExt(const Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE * Platform)
{
	using namespace Intel::MEI_Client::MKHI_Client;			

	bool isME11 = true;
	 
	try
	{
		GetFWVersionCommand getFWVersionCommand;
		GET_FW_VER_RESPONSE res = getFWVersionCommand.getResponse();
		if (res.FTMajor < 11)
		{
			isME11 = false;
		}
	}
	catch (exception& e)
	{
		OutputDebugStringA(e.what());
	}

	if (isME11)
	{
		if (Platform->Fields.ImageType == MPT_IMAGE_TYPE_FULL_SKU)
		{
			return CORPORATE;
		}
		if (Platform->Fields.ImageType == MPT_IMAGE_TYPE_SMALL_SKU)
		{
			return CONSUMER;
		}
	}
	else
	{
		MKHI_PLATFORM_TYPE_ME10 * Platform10 = (MKHI_PLATFORM_TYPE_ME10 *)Platform;
		if (Platform10->Fields.Corporate)
		{
			return CORPORATE;
		}

		if (Platform10->Fields.Consumer)
		{
			return CONSUMER;
		}
	}
	return CORPORATE;
}



HRESULT ME_System_WMI_Provider::GetMESystem(wstring& fwversion, bool& CryptoFuseEnabled, uint16& val,
										 vector<sint16>& OperationalStatus, uint32& type, uint32& segment, 
										 uint32& mode, uint32& capabilities, uint32& enabledCapabilities)
{
	OutputDebugStringA("ME_System_WMI_Provider::GetMESystem\n");
			HRESULT hr = 0;		
			val  = 5;
			uint32 sku = 0;
			CryptoFuseEnabled = false;
			fwversion = L"";
			OperationalStatus.push_back(0);
			PTHI_Commands pthic;
			hr = pthic.GetAMTVersion(&fwversion, &sku);
			if (hr != 0)
				return hr;
			uint32 ReasonCode=0;
			//hr = pthic.GetAMTState(&ReasonCode, &CryptoFuseEnabled);
			//if (hr != 0)
			//	return hr;
			using namespace Intel::MEI_Client;
			FWUpdate_Commands FWUpdate;
			PLATFORM_TYPE platformType = DESKTOP; //default value,avoid uninitialized variable for security
			MKHI_Client::MKHI_PLATFORM_TYPE platform;
			hr = FWUpdate.GetFWPlatformType(platform);
			if (hr != 0)
				return hr;
			if (platform.Fields.Desktop)
				platformType=DESKTOP;
			else
				if (platform.Fields.Mobile)
					platformType=MOBILE;
				else
					if (platform.Fields.Server)
						platformType=SERVER;
					else
						if (platform.Fields.WorkStn)
							platformType=WORKSTATION;

			//default value = CORPORATE, avoid uninitialized variable for security
			CUSTOMER_TYPE customer = GetPlatformTypeExt(&platform); 

			MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData, StateData;
			MENAGEABILTY_MODE pMode;
			hr=FWUpdate.GetFWCapabilities(CapabilityData);
			if (hr==S_OK)
			{
				hr=FWUpdate.GetFWFeaturesState(StateData);
				if (hr==S_OK)
				{
					hr=MenageabiltyModeLogic(CapabilityData, StateData, platform, pMode);
				}
			}
			if (hr != 0)
				return hr;

			capabilities = GetCapabilities_int(CapabilityData, platform);
			enabledCapabilities = GetCapabilities_int(StateData, platform);
			type = (uint32)platformType;
			segment = (uint32)customer;
			mode = (uint32)pMode;
			CryptoFuseEnabled = CapabilityData.Fields.Tls;

			return hr;
}

UINT32 ME_System_WMI_Provider::GetCapabilities_int(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI		CapabilityData, 
											   Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE Platform)
{
	//uint32 capabilities = 0;
	int i = 1;
	int amt = 0, stdMng = 0, l3 = 0, sbt = 0;
	if (CapabilityData.Fields.Amt)
	{
		if (Platform.Fields.Brand == Intel::MEI_Client::MKHI_Client::BrandAMT)
			amt = 1;
		else if(Platform.Fields.Brand == Intel::MEI_Client::MKHI_Client::BrandStdMng)
			stdMng = 1;
		else if(Platform.Fields.Brand == Intel::MEI_Client::MKHI_Client::BrandL3)
			l3 = 1;
		else if (Platform.Fields.Brand == Intel::MEI_Client::MKHI_Client::BrandSBT)
			sbt = 1;
	}
	
	//capabilities = capabilities | (amt * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Irwt * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Qst * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Tdt * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.SoftCreek * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Ve * i); i = i *2;
	//capabilities = capabilities | (0 * i); i = i *2; //DT
	//capabilities = capabilities | (0 * i); i = i *2; //NAND
	//capabilities = capabilities | (0 * i); i = i *2; //MPC
	//capabilities = capabilities | (CapabilityData.Fields.IccOverClockin * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Pav * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Spk * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Rca * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Rpat * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Ipv6 * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Kvm * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Och * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.MEDAL * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Tls * i); i = i *2;
	//capabilities = capabilities | (CapabilityData.Fields.Cila * i); i = i *2;
	//capabilities = capabilities | (stdMng * i); i = i *2;
	//capabilities = capabilities | (l3 * i); i = i *2;
	wstring fwversion = L"";
	UINT32 sku;
	PTHI_Commands pthic;
	pthic.GetAMTVersion(&fwversion, &sku);
    std::wstringstream converter;
    int major = 0;
    converter << fwversion;
    converter >> major;
 

	MEFWCAPS_SKU_INT capabilities;
	capabilities.Data = 0;
	capabilities.Fields.Amt = amt;
	capabilities.Fields.Tdt = CapabilityData.Fields.Tdt;
	capabilities.Fields.SoftCreek = CapabilityData.Fields.SoftCreek;
	capabilities.Fields.Ve = CapabilityData.Fields.Ve;
	capabilities.Fields.Nand = (major < 9) ? CapabilityData.Fields.Nand29 : 0; // bit 9 is not used anymore for NAND since 9.0 project
	capabilities.Fields.IccOverClockin = CapabilityData.Fields.IccOverClockin;
	capabilities.Fields.Pav = CapabilityData.Fields.Pav;
	//capabilities.Fields.Spk = CapabilityData.Fields.Spk;
	//capabilities.Fields.Rca = CapabilityData.Fields.Rca;
	//capabilities.Fields.Rpat = CapabilityData.Fields.Rpat;
	capabilities.Fields.Ipv6 = CapabilityData.Fields.Ipv6;
	capabilities.Fields.Kvm = CapabilityData.Fields.Kvm;
	capabilities.Fields.Och = CapabilityData.Fields.Och;
	capabilities.Fields.Tls = CapabilityData.Fields.Tls;
	capabilities.Fields.Cila = CapabilityData.Fields.Cila;
	capabilities.Fields.StdMng = stdMng;
	capabilities.Fields.L3 = l3;
	capabilities.Fields.DAL = CapabilityData.Fields.MEDAL;
	capabilities.Fields.SBT = sbt;
	return capabilities.Data;
}

#define MAX_LINE_LEN                   300


void ME_System_WMI_Provider::GetCapabilities(MEFWCAPS_SKU_INT	CapabilityData, 
											 vector<wstring>& capabilities)
{
	
	if (CapabilityData.Fields.Amt)
	{
		capabilities.push_back(L"AMT");
	}
	if (CapabilityData.Fields.StdMng)
	{
		capabilities.push_back(L"StdMng");
	}
	if (CapabilityData.Fields.L3)
	{
		capabilities.push_back(L"L3");
	}
	if (CapabilityData.Fields.SBT)
	{
		capabilities.push_back(L"SBT");
	}
	if (CapabilityData.Fields.Irwt)
	{
		capabilities.push_back(L"IRWT");
	}
	if (CapabilityData.Fields.Qst)
	{
		capabilities.push_back(L"QST");
	}
	if (CapabilityData.Fields.Tdt)
	{
		capabilities.push_back(L"TDT");
	}
	if (CapabilityData.Fields.SoftCreek)
	{
		capabilities.push_back(L"SoftCreek");
	}
	if (CapabilityData.Fields.Ve)
	{
		capabilities.push_back(L"VE");
	}
	/*if (CapabilityData.Fields.Dt) 
	{
		capabilities.push_back(L"DT");
	}*/
	if (CapabilityData.Fields.Nand)
	{
		capabilities.push_back(L"NAND");
	}
	/*if (CapabilityData.Fields.Mpc)
	{
		capabilities.push_back(L"MPC");
	}*/
	if (CapabilityData.Fields.IccOverClockin)
	{
		capabilities.push_back(L"ICC Over Clocking");
	}
	if (CapabilityData.Fields.Pav)
	{
		capabilities.push_back(L"PAVP");
	}
	/*if (CapabilityData.Fields.Spk)
	{
		capabilities.push_back(L"SPK");
	}
	if (CapabilityData.Fields.Rca)
	{
		capabilities.push_back(L"RCA");
	}
	if (CapabilityData.Fields.Rpat)
	{
		capabilities.push_back(L"RPAT");
	}*/
	if (CapabilityData.Fields.Ipv6)
	{
		capabilities.push_back(L"IPv6");
	}
	if (CapabilityData.Fields.Kvm)
	{
		capabilities.push_back(L"KVM");
	}
	if (CapabilityData.Fields.Och)
	{
		capabilities.push_back(L"OCH");
	}
	if (CapabilityData.Fields.DAL)
	{
		capabilities.push_back(L"DAL");
	}
	if (CapabilityData.Fields.Tls)
	{
		capabilities.push_back(L"TLS");
	}
	if (CapabilityData.Fields.Cila)
	{
		capabilities.push_back(L"CILA");
	}
	return;
}

HRESULT ME_System_WMI_Provider::MenageabiltyModeLogic(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData, 
													  Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI StateData, 
													  Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE platform, 
													  MENAGEABILTY_MODE& pMode)
{
	HRESULT hr=S_OK;
	/*
	if (platform.Fields.Corporate)
	{
		if (CapabilityData.Fields.Amt) 
		{
			if (CapabilityData.Fields.MngFull)
				if (StateData.Fields.MngFull)
					pMode=VPRO;
				else
					if (StateData.Fields.MngStd)
						pMode=STANDARD;
					else
						hr=E_UNEXPECTED;
			else
				if (CapabilityData.Fields.MngStd)
					if (StateData.Fields.MngStd)
						pMode=STANDARD;
					else
						hr=E_UNEXPECTED;
		}
		else
			pMode=NONE;
	}
	else
		pMode=NOT_KNOWN;
		*/
	switch(platform.Fields.Brand)
	{

	case Intel::MEI_Client::MKHI_Client::NoBrand: 
		pMode=NONE;
		break;
	case Intel::MEI_Client::MKHI_Client::BrandAMT: 
		pMode=VPRO;
		break;
	case Intel::MEI_Client::MKHI_Client::BrandStdMng: 
		pMode=STANDARD;
		break;
	case Intel::MEI_Client::MKHI_Client::BrandL3: 
		pMode=L3;
		break;
	case Intel::MEI_Client::MKHI_Client::BrandSBT: 
		pMode=SBT;
		break;
	default:
		pMode=NOT_KNOWN;
	}

	return hr;
}
