/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
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
	//Get all keys in a colllection, from an internal function
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::vector<ProvisioningCertificateHash_WMI_Provider> hashVec;
		hr = EnumerateProvisioningCertificateHash(hashVec, ReturnValue);
		if (STATUS_SUCCESS == ReturnValue)
		{
			std::vector<ProvisioningCertificateHash_WMI_Provider>::iterator entry;

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
		}
		else
		{
			WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
			return hr;
		}
		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}

HRESULT ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(std::vector<ProvisioningCertificateHash_WMI_Provider>& enumVec, uint32& ReturnValue)
{
	ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::vector<HashEntry> hashlist;
		PTHI_Commands pthic;
		ReturnValue = pthic.GetCertificateHash(hashlist);
		if (STATUS_SUCCESS == ReturnValue)
		{
			std::vector<HashEntry>::iterator entry;
			int i = 1;
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
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}

ProvisioningCertificateHash_WMI_Provider::ProvisioningCertificateHash_WMI_Provider(const HashEntry &entry,
	const std::wstring &instanceID, const std::wstring &elementName)
{
	InstanceID = instanceID;
	ElementName = elementName;
	Description = entry.Description;
	Enabled = entry.Enabled;
	for (size_t i = 0; i < sizeof(entry.HashData) / sizeof(entry.HashData[0]); i++)
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
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::map <std::wstring, CComVariant> keyList;
		std::map <std::wstring, CComVariant>::const_iterator it;
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"InstanceID");
		if (it == keyList.end())
		{
			hr = WBEM_E_INVALID_METHOD_PARAMETERS;
			return hr;
		}

		std::wstring val = (it->second).bstrVal;
		const WCHAR* str = val.c_str();
		unsigned int num = _wtoi(str+wcslen(L"Certificate Hash"));
		do 
		{
			std::vector<HashEntry> hashlist;
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
				std::vector<uint8> HashData;
				for (size_t i = 0; i < sizeof(entry.HashData) / sizeof(entry.HashData[0]); i++)
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

		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}
