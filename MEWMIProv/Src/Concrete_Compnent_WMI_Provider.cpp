/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: Concrete_Component_WMI_Provider.cpp

--*/

#include "Concrete_Component_WMI_Provider.h"
#include "EthernetPortSettings_WMI_Provider.h"
#include "ProvisioningCertificateHash_WMI_Provider.h"
#include "Audit_Record_WMI_Provider.h"
#include "pthi_commands.h"
#include "WMIHelper.h"


HRESULT Concrete_Component_WMI_Provider::Enumerate(
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
	try
	{
		do{
			//Enumerate EthernetPortSetting associations
			vector<EthernetPortSettings_WMI_Provider> ethernetPortList;
			hr = EthernetPortSettings_WMI_Provider::EnumerateEthernetPortSettings(
				ethernetPortList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				vector<EthernetPortSettings_WMI_Provider>::iterator ethernetPort;
				ethernetPort = ethernetPortList.begin();
				for (; ethernetPort != ethernetPortList.end(); ethernetPort++)
				{
					wstring partComponenet = (L"AMT_EtherenetPortSettings.InstanceID=\"") + 
						ethernetPort->InstanceID; 
					partComponenet += L"\"";
					CComPtr<IWbemClassObject> obj;
					RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_ConcreteComponent"));
					BREAKIF(WMIPut<1>(obj, L"GroupComponent", L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\""));
					BREAKIF(WMIPut<1>(obj, L"PartComponent", partComponenet));
			
					BREAKIF(pResponseHandler->Indicate(1, &obj.p));
				}
			}
			hr =0;
			ReturnValue = 0;
			//Enumerate Audit_Record associations
			vector<Audit_Record_WMI_Provider> auditRecordList;
			hr = Audit_Record_WMI_Provider::EnumerateAuditRecord(
				auditRecordList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				vector<Audit_Record_WMI_Provider>::iterator auditRecord;
				auditRecord = auditRecordList.begin();
				for (; auditRecord != auditRecordList.end(); auditRecord++)
				{
					wstring partComponenet = L"AMT_SetupAuditRecord.InstanceID=\"" + 
						auditRecord->InstanceID + 
						L"\"";
					CComPtr<IWbemClassObject> obj;
					RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_ConcreteComponent"));
					BREAKIF(WMIPut<1>(obj, L"GroupComponent", L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\""));
					BREAKIF(WMIPut<1>(obj, L"PartComponent", partComponenet));
			
					BREAKIF(pResponseHandler->Indicate(1, &obj.p));
				}
			}
			hr =0;
			ReturnValue = 0;
			//Enumerate Audit_Record associations
			vector<ProvisioningCertificateHash_WMI_Provider> hashList;
			hr = ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(
				hashList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				vector<ProvisioningCertificateHash_WMI_Provider>::iterator certHash;
				certHash = hashList.begin();
				for (; certHash != hashList.end(); certHash++)
				{
					wstring partComponenet = L"AMT_ProvisioningCertificateHash.InstanceID=\"" + 
						certHash->InstanceID + 
						L"\"";
					CComPtr<IWbemClassObject> obj;
					RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_ConcreteComponent"));
					BREAKIF(WMIPut<1>(obj, L"GroupComponent", L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\""));
					BREAKIF(WMIPut<1>(obj, L"PartComponent", partComponenet));
			
					BREAKIF(pResponseHandler->Indicate(1, &obj.p));
				}
			}

		} while(0);

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

bool Concrete_Component_WMI_Provider::IsGroupOobService(CComBSTR groupREF_BSTR)
{
	USES_CONVERSION;
	CComBSTR groupREF_int(groupREF_BSTR);
	groupREF_int.ToLower();
	wstring groupREF(groupREF_int);
	if (groupREF.find(L"oob_service.") == wstring::npos)
	{
		return false;
	}
	map <std::wstring, CComVariant> groupKeyList;
	map <std::wstring, CComVariant>::const_iterator groupIt ;
	GetKeysList(groupKeyList, (BSTR)groupREF_BSTR);
	if (groupKeyList.size() != 4)
	{
		return false;
	}
	
	groupIt = groupKeyList.find(L"CreationClassName");
	if (groupIt== groupKeyList.end() || !compareCaseInsensitive(groupIt->second.bstrVal, L"oob_service"))
	{
		return false;
	}
	groupIt = groupKeyList.find(L"Name");
	if (groupIt== groupKeyList.end() || !compareCaseInsensitive(groupIt->second.bstrVal, L"Intel ME Out of band service"))
	{
		return false;
	}
	groupIt = groupKeyList.find(L"SystemCreationClassName");
	if (groupIt== groupKeyList.end() || !compareCaseInsensitive(groupIt->second.bstrVal, L"me_system"))
	{
		return false;
	}
	groupIt = groupKeyList.find(L"SystemName");
	if (groupIt== groupKeyList.end() || !compareCaseInsensitive(groupIt->second.bstrVal, L"intel(r) AMT"))
	{
		return false;
	}
	return true;
}

bool Concrete_Component_WMI_Provider::compareCaseInsensitive(CComBSTR str1, CComBSTR str2)
{
	CComBSTR internalStr1(str1);
	CComBSTR internalStr2(str2);
	internalStr1.ToLower();
	internalStr2.ToLower();
	if (internalStr1 == internalStr2)
	{
		return true;
	}
	return false;
}

wstring Concrete_Component_WMI_Provider::analyzePartCompnent(CComBSTR partComponenetVal)
{
	wstring retValue(partComponenetVal);
	CComBSTR partComponenet(partComponenetVal);
	partComponenet.ToLower();
	wstring partREF(partComponenet);
	if (partREF.find(L"amt_setupauditrecord.") != wstring::npos)
	{
		if (!AuditRecordREFExists(partComponenet))
		{
			retValue = L"";
		}
	} else if (partREF.find(L"amt_provisioningcertificatehash.") != wstring::npos)
	{
		if (!ProvisioningHashREFExists(partComponenet))
		{
			retValue = L"";
		}
	} else if (partREF.find(L"amt_ethernetportsettings.") != wstring::npos)
	{
		if (!EthernetPortREFExists(partComponenet))
		{
			retValue = L"";
		}
	} else
	{
		retValue = L"";
	}
	return retValue;
}

bool Concrete_Component_WMI_Provider::ProvisioningHashREFExists(ATL::CComBSTR partComponenet)
{
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponenet);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	wstring inputInstanceID(it->second.bstrVal);
	vector<ProvisioningCertificateHash_WMI_Provider> instanceList;
	vector<ProvisioningCertificateHash_WMI_Provider>::const_iterator instanceIt;
	uint32 retVal;
	ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(instanceList, retVal);
	for (instanceIt = instanceList.begin(); instanceIt!= instanceList.end(); instanceIt++)
	{
		wstring instanceID = instanceIt->InstanceID;	
		
		if (_wcsnicmp(instanceID.c_str(), inputInstanceID.c_str(), instanceID.length()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Concrete_Component_WMI_Provider::EthernetPortREFExists(ATL::CComBSTR partComponenet)
{
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponenet);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	wstring inputInstanceID(it->second.bstrVal);
	vector<EthernetPortSettings_WMI_Provider> instanceList;
	vector<EthernetPortSettings_WMI_Provider>::const_iterator instanceIt;
	uint32 retVal;
	EthernetPortSettings_WMI_Provider::EnumerateEthernetPortSettings(instanceList, retVal);
	for (instanceIt = instanceList.begin(); instanceIt!= instanceList.end(); instanceIt++)
	{
		wstring instanceID = instanceIt->InstanceID;	
		
		if (_wcsnicmp(instanceID.c_str(), inputInstanceID.c_str(), instanceID.length()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Concrete_Component_WMI_Provider::AuditRecordREFExists(ATL::CComBSTR partComponent)
{	
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponent);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	wstring inputInstanceID(it->second.bstrVal);
	vector<Audit_Record_WMI_Provider> recordsList;
	vector<Audit_Record_WMI_Provider>::const_iterator recordsIt;
	uint32 retVal;
	Audit_Record_WMI_Provider::EnumerateAuditRecord(recordsList, retVal);
	for (recordsIt = recordsList.begin(); recordsIt!= recordsList.end(); recordsIt++)
	{
		wstring instanceID = recordsIt->InstanceID;	
		
		if (_wcsnicmp(instanceID.c_str(), inputInstanceID.c_str(), instanceID.length()) == 0)
		{
			return true;
		}
	}
	return false;
}

HRESULT Concrete_Component_WMI_Provider::GetConcrete_Component(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	USES_CONVERSION; 

	//_Module.logger.Detail(File,LOCATION, _T("SCS Server"), _T("Start function"),_T(""));
	uint32 hr = 0;
	uint32 ReturnValue = 0;
	map <std::wstring, CComVariant> keyList;
	map <std::wstring, CComVariant>::const_iterator it ;
	
	try
	{
		do 
		{
			GetKeysList(keyList, strObjectPath);
			it = keyList.find(L"GroupComponent");
			if (it == keyList.end())
			{
				//_Module.logger.Error(File,LOCATION, _T("WiFi Profile data"), _T("AddWiFiProfile"),_T("WBEM_E_INVALID_METHOD_PARAMETERS"));
				//_Module.SetLastErrorString(GETSCSMESSAGE1(ERROR_IN_PARAMETER,_T("InstanceID")));
				hr = WBEM_E_INVALID_METHOD_PARAMETERS;
				break;
			}
			CComBSTR groupREF_BSTR(it->second.bstrVal);
			if (!IsGroupOobService(groupREF_BSTR))
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}	
			it = keyList.find(L"PartComponent");
			if (it == keyList.end())
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}
			CComBSTR partComponenetVal(it->second.bstrVal);
			std::wstring partREF = analyzePartCompnent(partComponenetVal);
			if (partREF.compare(L"") == 0)
			{
				hr = WBEM_E_INVALID_ASSOCIATION;
				break;
			}
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"CIM_ConcreteComponent"));
			BREAKIF(WMIPut<1>(obj, L"GroupComponent", L"OOB_Service.CreationClassName=\"OOB_Service\",Name=\"Intel ME Out Of Band Service\",SystemCreationClassName=\"ME_system\",SystemName=\"Intel(r) AMT\""));
			BREAKIF(WMIPut<1>(obj, L"PartComponent", partREF));
			
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
