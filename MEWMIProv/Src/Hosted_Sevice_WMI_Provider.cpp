/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: Hosted_Service_WMI_Provider.cpp

--*/
#include "ME_System_WMI_Provider.h"
#include "Hosted_Service_WMI_Provider.h"
#include "pthi_commands.h"
#include "WMIHelper.h"

HRESULT Hosted_Service_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	USES_CONVERSION; 
	
	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("Profile data"), _T("Enumerate started"),_T(""));
	//Get all keys in a colllection, from an internal function
	uint32 ReturnValue = 0;
	uint32 hr = 1;
	try
	{
		std::wstring fwversion = L"";
		bool CryptoFuseEnabled = false;
		uint16 val;
		std::vector<sint16> OperationalStatus;
		uint32 type, segment, mode, capabilities, enabledCapabilities;
		ReturnValue = ME_System_WMI_Provider::GetMESystem(fwversion, CryptoFuseEnabled, val,
									 OperationalStatus, type, segment, 
									 mode, capabilities, enabledCapabilities);
		if (ReturnValue != S_OK)
		{
			return hr;
		}
		std::wstring me_ref = L"ME_System.CreationClassName=\"ME_system\",Name=\"Intel(r) AMT\"";
		std::wstring oob_ref = L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\"";
		std::wstring amt_ref = L"AMT_Service.CreationClassName=\"AMT_Service\",Name=\"Intel AMT Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\"";
							
		for (int i = 0; i < 2; ++i)
		{	
			CComPtr<IWbemClassObject> obj;
			BREAKIF(WMIPutMember(pNamespace, &obj, L"CIM_HostedService"));
			BREAKIF(WMIPut<1>(obj, L"Antecedent", me_ref));
			if (i == 0)
				BREAKIF(WMIPut<1>(obj, L"Dependent", oob_ref));
			if (i == 1)	
				BREAKIF(WMIPut<1>(obj, L"Dependent", amt_ref));
				
			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		
		}
	}
	catch (...)
	{
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	//Enumerate the collection, retrieving params and creating return instances
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

HRESULT Hosted_Service_WMI_Provider::GetHosted_Service(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	USES_CONVERSION; 

	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));

	uint32 hr = 0;
	uint32 ReturnValue = 0;
	std::map <std::wstring, CComVariant> keyList;
	std::map <std::wstring, CComVariant>::const_iterator antecedentIt, dependentIt ;
	
	

	try
	{
		GetKeysList(keyList, strObjectPath);
		antecedentIt = keyList.find(L"Antecedent");
		if (antecedentIt == keyList.end())
		{
			//_Module.logger.Error(File,LOCATION, _T("WiFi Profile data"), _T("AddWiFiProfile"),_T("WBEM_E_INVALID_METHOD_PARAMETERS"));
			//_Module.SetLastErrorString(GETSCSMESSAGE1(ERROR_IN_PARAMETER,_T("InstanceID")));
			return  WBEM_E_INVALID_METHOD_PARAMETERS;
		}
		dependentIt = keyList.find(L"Dependent");
		if (dependentIt == keyList.end())
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
			std::wstring fwversion = L"";
			bool CryptoFuseEnabled = false;
			uint16 val;
			std::vector<sint16> OperationalStatus;
			uint32 type, segment, mode, capabilities, enabledCapabilities;
			ReturnValue = ME_System_WMI_Provider::GetMESystem(fwversion, CryptoFuseEnabled, val,
										 OperationalStatus, type, segment, 
										 mode, capabilities, enabledCapabilities);
			if (ReturnValue != S_OK)
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}

			std::wstring antecedentVal = (antecedentIt->second).bstrVal;
			if (antecedentVal.find(L"Name=\"Intel(r) AMT\"") == std::wstring::npos)
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}
			std::wstring dependentVal = (dependentIt->second).bstrVal;
			if (dependentVal.find(L"Name=\"Intel ME Out Of Band Service\"") != std::wstring::npos)
			{	
				dependentVal = L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\"";
			}
			else if (dependentVal.find(L"Name=\"Intel AMT Service\"") != std::wstring::npos)
			{
				dependentVal = L"AMT_Service.CreationClassName=\"AMT_Service\",Name=\"Intel AMT Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\"";
			}
			else
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_HostedService"));
			BREAKIF(WMIPut<1>(obj, L"Antecedent", L"ME_System.CreationClassName=\"ME_system\",Name=\"Intel(r) AMT\""));
			BREAKIF(WMIPut<1>(obj, L"Dependent", dependentVal));
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
		//_Module.SetLastErrorString(GETSCSMESSAGE(ERROR_EXCEPTION_IN_SERVICE));
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
	}


	return hr;

}
