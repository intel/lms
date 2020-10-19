/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
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

	//Get all keys in a colllection, from an internal function
	uint32 ReturnValue = 0;
	uint32 hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do{
			//Enumerate EthernetPortSetting associations
			std::vector<EthernetPortSettings_WMI_Provider> ethernetPortList;
			hr = EthernetPortSettings_WMI_Provider::EnumerateEthernetPortSettings(
				ethernetPortList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				std::vector<EthernetPortSettings_WMI_Provider>::iterator ethernetPort;
				ethernetPort = ethernetPortList.begin();
				for (; ethernetPort != ethernetPortList.end(); ethernetPort++)
				{
					std::wstring partComponenet = (L"AMT_EtherenetPortSettings.InstanceID=\"") +
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
			std::vector<Audit_Record_WMI_Provider> auditRecordList;
			hr = Audit_Record_WMI_Provider::EnumerateAuditRecord(
				auditRecordList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				std::vector<Audit_Record_WMI_Provider>::iterator auditRecord;
				auditRecord = auditRecordList.begin();
				for (; auditRecord != auditRecordList.end(); auditRecord++)
				{
					std::wstring partComponenet = L"AMT_SetupAuditRecord.InstanceID=\"" +
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
			std::vector<ProvisioningCertificateHash_WMI_Provider> hashList;
			hr = ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(
				hashList, ReturnValue);
			if (ReturnValue == STATUS_SUCCESS || hr == STATUS_SUCCESS)
			{
				std::vector<ProvisioningCertificateHash_WMI_Provider>::iterator certHash;
				certHash = hashList.begin();
				for (; certHash != hashList.end(); certHash++)
				{
					std::wstring partComponenet = L"AMT_ProvisioningCertificateHash.InstanceID=\"" +
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
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

bool Concrete_Component_WMI_Provider::IsGroupOobService(CComBSTR groupREF_BSTR)
{
	USES_CONVERSION;
	CComBSTR groupREF_int(groupREF_BSTR);
	groupREF_int.ToLower();
	std::wstring groupREF(groupREF_int);
	if (groupREF.find(L"oob_service.") == std::wstring::npos)
	{
		return false;
	}
	std::map <std::wstring, CComVariant> groupKeyList;
	std::map <std::wstring, CComVariant>::const_iterator groupIt ;
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

std::wstring Concrete_Component_WMI_Provider::analyzePartCompnent(CComBSTR partComponenetVal)
{
	std::wstring retValue(partComponenetVal);
	CComBSTR partComponenet(partComponenetVal);
	partComponenet.ToLower();
	std::wstring partREF(partComponenet);
	if (partREF.find(L"amt_setupauditrecord.") != std::wstring::npos)
	{
		if (!AuditRecordREFExists(partComponenet))
		{
			retValue = L"";
		}
	} else if (partREF.find(L"amt_provisioningcertificatehash.") != std::wstring::npos)
	{
		if (!ProvisioningHashREFExists(partComponenet))
		{
			retValue = L"";
		}
	} else if (partREF.find(L"amt_ethernetportsettings.") != std::wstring::npos)
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
	std::map <std::wstring, CComVariant> keyList;
	std::map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponenet);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	std::wstring inputInstanceID(it->second.bstrVal);
	std::vector<ProvisioningCertificateHash_WMI_Provider> instanceList;
	std::vector<ProvisioningCertificateHash_WMI_Provider>::const_iterator instanceIt;
	uint32 retVal;
	ProvisioningCertificateHash_WMI_Provider::EnumerateProvisioningCertificateHash(instanceList, retVal);
	for (instanceIt = instanceList.begin(); instanceIt!= instanceList.end(); instanceIt++)
	{
		std::wstring instanceID = instanceIt->InstanceID;
		
		if (_wcsnicmp(instanceID.c_str(), inputInstanceID.c_str(), instanceID.length()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Concrete_Component_WMI_Provider::EthernetPortREFExists(ATL::CComBSTR partComponenet)
{
	std::map <std::wstring, CComVariant> keyList;
	std::map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponenet);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	std::wstring inputInstanceID(it->second.bstrVal);
	std::vector<EthernetPortSettings_WMI_Provider> instanceList;
	std::vector<EthernetPortSettings_WMI_Provider>::const_iterator instanceIt;
	uint32 retVal;
	EthernetPortSettings_WMI_Provider::EnumerateEthernetPortSettings(instanceList, retVal);
	for (instanceIt = instanceList.begin(); instanceIt!= instanceList.end(); instanceIt++)
	{
		std::wstring instanceID = instanceIt->InstanceID;
		
		if (_wcsnicmp(instanceID.c_str(), inputInstanceID.c_str(), instanceID.length()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Concrete_Component_WMI_Provider::AuditRecordREFExists(ATL::CComBSTR partComponent)
{	
	std::map <std::wstring, CComVariant> keyList;
	std::map <std::wstring, CComVariant>::const_iterator it ;
	GetKeysList(keyList, (BSTR)partComponent);
	it = keyList.find(L"instanceid");
	if (it == keyList.end())
	{
		return false;
	}
	std::wstring inputInstanceID(it->second.bstrVal);
	std::vector<Audit_Record_WMI_Provider> recordsList;
	std::vector<Audit_Record_WMI_Provider>::const_iterator recordsIt;
	uint32 retVal;
	Audit_Record_WMI_Provider::EnumerateAuditRecord(recordsList, retVal);
	for (recordsIt = recordsList.begin(); recordsIt!= recordsList.end(); recordsIt++)
	{
		std::wstring instanceID = recordsIt->InstanceID;
		
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

	uint32 hr = 0;
	uint32 ReturnValue = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);
	
	try
	{
		do 
		{
			std::map <std::wstring, CComVariant> keyList;
			std::map <std::wstring, CComVariant>::const_iterator it ;
			GetKeysList(keyList, strObjectPath);
			it = keyList.find(L"GroupComponent");
			if (it == keyList.end())
			{
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
		
		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}
