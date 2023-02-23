/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: ME_System_WMI_Provider.cpp

--*/

#include "ME_System_WMI_Provider.h"
#include "pthi_commands.h"
#include "FWUpdate_Commands.h"
#include "UPID_Commands.h"
#include "ErrorCodes.h"
#include "StatusCodeDefinitions.h"
#include "WMIHelper.h"

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
			else if (CComBSTR(strMethodName) == L"getUniquePlatformIDFeatureState")
				hr = getUPIDFeatureState(pClass, pInParams, pResponseHandler, pNamespace);
			else if (CComBSTR(strMethodName) == L"setUniquePlatformIDFeatureState")
				hr = setUPIDFeatureState(pClass, pInParams, pResponseHandler, pNamespace);
			else if (CComBSTR(strMethodName) == L"getUniquePlatformID")
				hr = getUPID(pClass, pInParams, pResponseHandler, pNamespace);
			else if (CComBSTR(strMethodName) == L"getUniquePlatformIDFeatureSupported")
				hr = getUniquePlatformIDFeatureSupported(pClass, pInParams, pResponseHandler, pNamespace);
			else if (CComBSTR(strMethodName) == L"getUniquePlatformIDFeatureOSControlState")
				hr = getUniquePlatformIDFeatureOSControlState(pClass, pInParams, pResponseHandler, pNamespace);
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
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do{
			std::wstring fwversion = L"";
			bool CryptoFuseEnabled = false;
			uint16 val = 5;
			std::vector<sint16> OperationalStatus({ 0 });
			uint32 type, segment, mode, capabilities, enabledCapabilities;
			bool uniquePlatformIDFeatureSupported;
			bool uniquePlatformIDFeatureOSControlState;
			bool uniquePlatformIDFeatureState;

			ReturnValue = GetMESystem(fwversion, CryptoFuseEnabled,
										 type, segment,
										 mode, capabilities, enabledCapabilities, uniquePlatformIDFeatureSupported,
										 uniquePlatformIDFeatureOSControlState, uniquePlatformIDFeatureState);
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
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureSupported", uniquePlatformIDFeatureSupported));
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureOSControlState", uniquePlatformIDFeatureOSControlState));
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureState", uniquePlatformIDFeatureState));

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
		UNS_ERROR("%C Bad catch", __FUNCTION__);
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
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		uint32 ReasonCode=0;
		bool cryptoFuseEnabled;
		PTHI_Commands pthic;
		ReturnValue = pthic.GetAMTState(&ReasonCode, &cryptoFuseEnabled);
		ERROR_HANDLER(ReturnValue);
		
		WMIGetMethodOParams(pClass, L"getLastMEResetReason", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"ReasonCode", ReasonCode);

		pResponseHandler->Indicate(1, &pOutParams.p);
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

HRESULT ME_System_WMI_Provider::getCurrentPowerPolicy(
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
		std::wstring powerPolicy=L"";
		PTHI_Commands pthic;
		ReturnValue = pthic.GetPowerPolicy(&powerPolicy);
		WMIGetMethodOParams(pClass, L"getCurrentPowerPolicy", &pOutParams.p);
		WMIPut<1>( pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>( pOutParams, L"PowerPolicy", powerPolicy);

		pResponseHandler->Indicate(1, &pOutParams.p);
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

HRESULT ME_System_WMI_Provider::IsFirmwareUpdateEnabled(
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
		bool enabled = false;

		FWUpdate_Commands FWUpdate;
		{
			using namespace Intel::MEI_Client;
		
			ReturnValue = FWUpdate.GetFWUpdateStateCommand(&enabled);
			if (ReturnValue != S_OK)
				enabled = false;
		}
		UNS_DEBUG("FWUpdate.GetFWUpdateStateCommand=%d rc=%d\n", enabled, ReturnValue);
		
		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"IsFirmwareUpdateEnabled", &pOutParams.p);
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
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		CComPtr<IWbemClassObject> pOutParams;
		std::vector<std::wstring> capabilities, enabledCapabilities;
		FWUpdate_Commands FWUpdate;
		
		{
			using namespace Intel::MEI_Client;
			MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData, StateData;
			MKHI_Client::MKHI_PLATFORM_TYPE Platform;
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
		UNS_ERROR("%C Bad catch", __FUNCTION__);
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
			std::wstring fwversion = L"";
			bool CryptoFuseEnabled = false;
			uint16 val = 5;
			std::vector<sint16> OperationalStatus({ 0 });
			uint32 type, segment, mode, capabilities, enabledCapabilities;
			bool uniquePlatformIDFeatureSupported;
			bool uniquePlatformIDFeatureOSControlState;
			bool uniquePlatformIDFeatureState;
			hr = GetMESystem(fwversion, CryptoFuseEnabled,
										 type, segment,
										 mode, capabilities, enabledCapabilities, uniquePlatformIDFeatureSupported,
										 uniquePlatformIDFeatureOSControlState, uniquePlatformIDFeatureState);
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
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureSupported", uniquePlatformIDFeatureSupported));
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureOSControlState", uniquePlatformIDFeatureOSControlState));
			BREAKIF(WMIPut<1>(obj, L"UniquePlatformIDFeatureState", uniquePlatformIDFeatureState));

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

		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}

ME_System_WMI_Provider::CUSTOMER_TYPE ME_System_WMI_Provider::GetPlatformTypeExt(const Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE *Platform)
{
	if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_FULL_SKU)
	{
		return CORPORATE;
	}
	if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_SMALL_SKU)
	{
		return CONSUMER;
	}
	return CORPORATE;
}

HRESULT ME_System_WMI_Provider::GetMESystem(std::wstring& fwversion, bool& CryptoFuseEnabled,
											uint32& type, uint32& segment,
											uint32& mode, uint32& capabilities, uint32& enabledCapabilities,
											bool& uniquePlatformIDFeatureSupported,
											bool& uniquePlatformIDFeatureOSControlState,
											bool& uniquePlatformIDFeatureState)
{
	HRESULT hr = 0;
	EntryExitLogShort log(__FUNCTION__, hr);

	CryptoFuseEnabled = false;
	fwversion = L"";
	PTHI_Commands pthic;
	hr = pthic.GetAMTVersion(&fwversion);
	if (hr != 0)
		return hr;
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
			hr = MenageabiltyModeLogic(platform, pMode);
		}
	}
	if (hr != 0)
		return hr;

	UPID_Commands UPID;
	bool UPIDSupported = false;
	hr = UPID.GetUPIDFeatureSupported(UPIDSupported);
	if (hr != S_OK)
	{
		if (hr == AMT_STATUS_INVALID_PT_MODE)
			UPIDSupported = false;
		else
			return hr;
	}
	bool osControlState = false;
	hr = UPID.GetUPIDFeatureOSControl(osControlState);
	if (hr != S_OK)
	{
		if (hr == AMT_STATUS_INVALID_PT_MODE)
			osControlState = false;
		else
			return hr;
	}
	bool UPIDState = false;
	hr = UPID.GetUPIDStateCommand(UPIDState);
	if (hr != S_OK)
	{
		if (hr == AMT_STATUS_INVALID_PT_MODE)
			UPIDState = false;
		else
			return hr;
	}

	hr = 0;

	capabilities = GetCapabilities_int(CapabilityData, platform);
	enabledCapabilities = GetCapabilities_int(StateData, platform);
	type = (uint32)platformType;
	segment = (uint32)customer;
	mode = (uint32)pMode;
	CryptoFuseEnabled = CapabilityData.Fields.Tls;
	uniquePlatformIDFeatureOSControlState = osControlState;
	uniquePlatformIDFeatureSupported = UPIDSupported;
	uniquePlatformIDFeatureState = UPIDState;

	return hr;
}

UINT32 ME_System_WMI_Provider::GetCapabilities_int(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData,
											   Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE Platform)
{
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

	MEFWCAPS_SKU_INT capabilities;
	capabilities.Data = 0;
	capabilities.Fields.Amt = amt;
	capabilities.Fields.Tdt = 0; // was CapabilityData.Fields.Tdt;
	capabilities.Fields.SoftCreek = CapabilityData.Fields.SoftCreek;
	capabilities.Fields.Ve = 0; // was CapabilityData.Fields.Ve;
	capabilities.Fields.Nand = 0; // bit 9 is not used anymore for NAND since 9.0 project
	capabilities.Fields.IccOverClockin = 0; // was  CapabilityData.Fields.IccOverClockin;
	capabilities.Fields.Pav = CapabilityData.Fields.Pav;
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

void ME_System_WMI_Provider::GetCapabilities(MEFWCAPS_SKU_INT CapabilityData, std::vector<std::wstring>& capabilities)
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
	if (CapabilityData.Fields.Tdt)
	{
		capabilities.push_back(L"TDT");
	}
	if (CapabilityData.Fields.SoftCreek)
	{
		capabilities.push_back(L"SoftCreek");
	}
	if (CapabilityData.Fields.Pav)
	{
		capabilities.push_back(L"PAVP");
	}
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
}

HRESULT ME_System_WMI_Provider::MenageabiltyModeLogic(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE platform,
													  MENAGEABILTY_MODE& pMode)
{
	HRESULT hr=S_OK;

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


HRESULT ME_System_WMI_Provider::getUPIDFeatureState(
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
		bool state = false;

		UPID_Commands UPID;
		{
			ReturnValue = UPID.GetUPIDStateCommand(state);
			if (ReturnValue != S_OK)
				state = false;
		}

		ERROR_HANDLER(ReturnValue);
		
		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getUniquePlatformIDFeatureState", &pOutParams.p);
		WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>(pOutParams, L"state", state);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}


HRESULT ME_System_WMI_Provider::setUPIDFeatureState(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	bool state;
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	if (IsUserAdmin() == S_FALSE)
	{
		hr = WBEM_E_ACCESS_DENIED;
		pResponseHandler->SetStatus(0, hr, NULL, NULL);
		return hr;
	}

	try
	{
		if (!pInParams)
			RETURNIF(WBEM_E_INVALID_METHOD_PARAMETERS);

		do {

			bool specified;
			GetParamBREAKIF(WMIGet<1>(pNamespace, pInParams, L"state", state, specified), L"state");
			if (!specified)
				RETURNIF(WBEM_E_INVALID_METHOD_PARAMETERS);

			UPID_Commands UPID;
			ReturnValue = UPID.SetUPIDStateCommand(state);

			ERROR_HANDLER(ReturnValue);

			CComPtr<IWbemClassObject> pOutParams;
			WMIGetMethodOParams(pClass, L"setUniquePlatformIDFeatureState", &pOutParams.p);
			WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue);

			pResponseHandler->Indicate(1, &pOutParams.p);
		} while (0);

	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}


HRESULT ME_System_WMI_Provider::getUPID(
	IWbemClassObject*              pClass,
	IWbemClassObject __RPC_FAR*    pInParams,
	IWbemObjectSink  __RPC_FAR*    pResponseHandler,
	IWbemServices*                 pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	if (IsUserAdmin() == S_FALSE)
	{
		hr = WBEM_E_ACCESS_DENIED;
		pResponseHandler->SetStatus(0, hr, NULL, NULL);
		return hr;
	}

	try
	{
		uint32_t oemPlatformIdType = 0;
		std::wstring oemPlatformId, csmePlatformId;

		UPID_Commands UPID;
		{
			ReturnValue = UPID.GetUPIDCommand(oemPlatformIdType, oemPlatformId, csmePlatformId);
		}

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getUniquePlatformID", &pOutParams.p);
		WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>(pOutParams, L"OEMPlatformIDType", oemPlatformIdType);
		WMIPut<1>(pOutParams, L"OEMPlatformID", oemPlatformId);
		WMIPut<1>(pOutParams, L"CSMEPlatformID", csmePlatformId);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT ME_System_WMI_Provider::getUniquePlatformIDFeatureSupported(
	IWbemClassObject* pClass,
	IWbemClassObject __RPC_FAR* pInParams,
	IWbemObjectSink  __RPC_FAR* pResponseHandler,
	IWbemServices* pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		bool supported = false;

		UPID_Commands UPID;
		{
			ReturnValue = UPID.GetUPIDFeatureSupported(supported);
			if (ReturnValue != S_OK)
				supported = false;
		}

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getUniquePlatformIDFeatureSupported", &pOutParams.p);
		WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>(pOutParams, L"supported", supported);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT ME_System_WMI_Provider::getUniquePlatformIDFeatureOSControlState(
	IWbemClassObject* pClass,
	IWbemClassObject __RPC_FAR* pInParams,
	IWbemObjectSink  __RPC_FAR* pResponseHandler,
	IWbemServices* pNamespace)
{
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		bool state = false;

		UPID_Commands UPID;
		{
			ReturnValue = UPID.GetUPIDFeatureOSControl(state);
			if (ReturnValue != S_OK)
				state = false;
		}

		ERROR_HANDLER(ReturnValue);

		CComPtr<IWbemClassObject> pOutParams;
		WMIGetMethodOParams(pClass, L"getUniquePlatformIDFeatureOSControlState", &pOutParams.p);
		WMIPut<1>(pOutParams, L"ReturnValue", ReturnValue);
		WMIPut<1>(pOutParams, L"state", state);

		pResponseHandler->Indicate(1, &pOutParams.p);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}