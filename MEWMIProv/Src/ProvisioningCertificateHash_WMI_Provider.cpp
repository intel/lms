/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: ProvisioningCertificateHash_WMI_Provider.cpp

--*/

#include "ProvisioningCertificateHash_WMI_Provider.h"
#include "pthi_commands.h"
#include "WMIHelper.h"


HRESULT ProvisioningCertificateHash_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	USES_CONVERSION;
	
	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));
	//_Module.logger.Info(File,LOCATION, _T("Profile data"), _T("Enumerate started"),_T(""));
	//Get all keys in a colllection, from an internal function
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	int i=1;
	try
	{
		vector<ProvisioningCertificateHash_WMI_Provider> hashVec;
		hr = EnumerateProvisioningCertificateHash(hashVec, ReturnValue);
		if (STATUS_SUCCESS == ReturnValue)
		{
			/////////////////
			vector<ProvisioningCertificateHash_WMI_Provider>::iterator entry;

		    entry = hashVec.begin();
			for (; entry != hashVec.end(); entry++)
			{
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_ProvisioningCertificateHash"));
				BREAKIF(WMIPut<1>(obj, L"ElementName", entry->ElementName));
				BREAKIF(WMIPut<1>(obj, L"InstanceID", entry->InstanceID));
				BREAKIF(WMIPut<1>(obj, L"Description", entry->Description));
				BREAKIF(WMIPut<1>(obj, L"IsDefault", entry->IsDefault));
				BREAKIF(WMIPut<1>(obj, L"HashType", entry->HashType));
				BREAKIF(WMIPut<uint8>(obj, L"HashData", entry->HashDataVec));
				BREAKIF(WMIPut<1>(obj, L"Enabled", entry->Enabled));
				BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}
			
			////////////////////
/*			while (hashlist.size() > 0)
			{
				HashEntry entry = hashlist.back();
				hashlist.pop_back();
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_ProvisioningCertificateHash"));
				BREAKIF(WMIPut<1>(obj, L"ElementName", L"Intel(r) AMT: Provisioning Certificate Hash"));
				WCHAR str[256];
				swprintf_s(str, 256, L"Certificate Hash %d",i++);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", str));
				BREAKIF(WMIPut<1>(obj, L"Description", entry.Description));
				BREAKIF(WMIPut<1>(obj, L"IsDefault", entry.IsDefault));
				BREAKIF(WMIPut<1>(obj, L"HashType", entry.HashType));
				vector<uint8> HashData;
				for (int i=0; i < sizeof(entry.HashData) / sizeof(entry.HashData[0]); i++)
					HashData.push_back(entry.HashData[i]);

				BREAKIF(WMIPut<uint8>(obj, L"HashData", HashData));
				BREAKIF(WMIPut<1>(obj, L"Enabled", entry.Enabled));
		
				BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}*/
		}
		else
		{
			WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
			return hr;

		}
		WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
		//Enumarate the collection, retrieving params and creating return instances
		//if (STATUS_SUCCESS == hr)
		//{
		//	_Module.logger.Info(File,LOCATION,  _T("Profile data"), _T("Enumerate finished successfully"),_T(""));
		//}
		//else
		//{
		//	_Module.logger.Error(File,LOCATION,  _T("Profile data"), _T("Enumerate failed with error code"),_T("StringUtilsNamespace::convertTowString(hr)"));
		//}

	}
	catch (...)
	{
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
	}
	return hr;

}

HRESULT ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(vector<ProvisioningCertificateHash_WMI_Provider>& enumVec, uint32& ReturnValue)
{
	USES_CONVERSION;
	
	ReturnValue = 0;
	uint32 hr = 0;
	int i=1;
	try
	{
		vector<HashEntry> hashlist;
		PTHI_Commands pthic;
		
		
		ReturnValue = pthic.GetCertificateHash(hashlist);

		if (STATUS_SUCCESS == ReturnValue)
		{
			/////////////////
			vector<HashEntry>::iterator entry;
			
		    entry = hashlist.begin();
			for (; entry != hashlist.end(); entry++)
			{
				std::wstring elementName = L"Intel(r) AMT: Provisioning Certificate Hash";
				WCHAR str[256];
				swprintf_s(str, 256, L"Certificate Hash %d",i++);
				std::wstring instanceID(str);
				ProvisioningCertificateHash_WMI_Provider provisioningCertHash(*entry, instanceID, elementName);
				enumVec.push_back(provisioningCertHash);
			} 
			
		}
	}
	
	catch (...)
	{
		//_Module.logger.Error(File,LOCATION, _T("SCS Server"), _T(""), _T("Bad catch"));
		hr  = WBEM_E_PROVIDER_FAILURE;
	}
	return hr;

}

ProvisioningCertificateHash_WMI_Provider::ProvisioningCertificateHash_WMI_Provider(HashEntry entry, std::wstring instanceID, std::wstring elementName)
{
	InstanceID = instanceID;
	ElementName = elementName;
	Description = entry.Description;
	Enabled = entry.Enabled;
	for (int i=0; i < sizeof(entry.HashData) / sizeof(entry.HashData[0]); i++)
		HashDataVec.push_back(entry.HashData[i]);
	HashType = entry.HashType;
	IsDefault = entry.IsDefault;
}


HRESULT ProvisioningCertificateHash_WMI_Provider::Get_Entry(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));

	uint32 ReturnValue = 0;
	uint32 hr = 0;
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;

	try
	{
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"InstanceID");
		if (it == keyList.end())
		{
			//_Module.logger.Error(File,LOCATION, _T("WiFi Profile data"), _T("AddWiFiProfile"),_T("WBEM_E_INVALID_METHOD_PARAMETERS"));
			//_Module.SetLastErrorString(GETSCSMESSAGE1(ERROR_IN_PARAMETER,_T("InstanceID")));
			return  WBEM_E_INVALID_METHOD_PARAMETERS;
		}

		//unsigned long id = 0;
		std::wstring val = (it->second).bstrVal;
		const WCHAR* str = val.c_str();
		unsigned int num = _wtoi(str+wcslen(L"Certificate Hash"));
		

		//_Module.logger.Info(File,LOCATION, _T("Profile data"), _T("Get profile object started"),_T("Profile:")+ StringUtilsNamespace::convertTowString(id));

		//SCS_Profile profile;
		do 
		{
			vector<HashEntry> hashlist;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetCertificateHash(hashlist);
			if (num < 1 || num > hashlist.size())
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}
			if (STATUS_SUCCESS == ReturnValue)
			{
				const HashEntry &entry = hashlist.at(num-1);
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_ProvisioningCertificateHash"));
				BREAKIF(WMIPut<1>(obj, L"ElementName", L"Intel(r) AMT: Provisioning Certificate Hash"));
				WCHAR str[256];
				swprintf_s(str, 256, L"Certificate Hash %d",num);
				BREAKIF(WMIPut<1>(obj, L"InstanceID", str));
				BREAKIF(WMIPut<1>(obj, L"Description", entry.Description));
				BREAKIF(WMIPut<1>(obj, L"IsDefault", entry.IsDefault));
				BREAKIF(WMIPut<1>(obj, L"HashType", entry.HashType));
				vector<uint8> HashData;
				for (int i=0; i < sizeof(entry.HashData) / sizeof(entry.HashData[0]); i++)
					HashData.push_back(entry.HashData[i]);

				BREAKIF(WMIPut<uint8>(obj, L"HashData", HashData));
				BREAKIF(WMIPut<1>(obj, L"Enabled", entry.Enabled));
		
				BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}
			else
			{
				ERROR_HANDLER(ReturnValue);
			}
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




