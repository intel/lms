/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: Audit_Record_WMI_Provider.cpp

--*/

#include "Audit_Record_WMI_Provider.h"
#include "pthi_commands.h"
#include "WMIHelper.h"

HRESULT Audit_Record_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	//Get all keys in a colllection, from an internal function
	try
	{
		do{
			std::vector<Audit_Record_WMI_Provider> auditVec;
			hr = EnumerateAuditRecord(auditVec, ReturnValue);
			if (ReturnValue == AMT_STATUS_DATA_MISSING)
			{
				hr = WBEM_E_NOT_SUPPORTED;
				break;
			}
			if (ReturnValue != S_OK)
			{
				WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
				return hr;
			}
			if (hr != 0)
			{
				break;
			}
			if(auditVec.size() == 0)
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}
			
			
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_SetupAuditRecord"));
			BREAKIF(WMIPut<1>(obj, L"InstanceID", auditVec[0].InstanceID));
			BREAKIF(WMIPut<1>(obj, L"ProvisioningTLSMode", auditVec[0].ProvisioningTLSMode));
			BREAKIF(WMIPut<1>(obj, L"SecureDNS", auditVec[0].SecureDNS));
			BREAKIF(WMIPut<1>(obj, L"HostInitiated", auditVec[0].HostInitiated));
			BREAKIF(WMIPut<1>(obj, L"SelectedHashType", auditVec[0].SelectedHashType));
			BREAKIF(WMIPut<uint8>(obj, L"SelectedHashData", auditVec[0].SelectedHashData));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial1", auditVec[0].CACertificateSerial1));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial2", auditVec[0].CACertificateSerial2));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial3", auditVec[0].CACertificateSerial3));
			BREAKIF(WMIPut<1>(obj, L"AdditionalCaSerialNums", auditVec[0].AdditionalCaSerialNums));
			BREAKIF(WMIPut<1>(obj, L"IsTimeValid", auditVec[0].IsTimeValid));
			BREAKIF(WMIPut<1>(obj, L"ProvServerIP", auditVec[0].ProvServerIP));
			BREAKIF(WMIPut<1>(obj, L"ProvServerFQDN", auditVec[0].ProvServerFQDN));
			BREAKIF(WMIPut<1>(obj, L"CreationTimeStamp", auditVec[0].TlsStartTime));

			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
		} while(0);

	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		
	}

	WMIHandleSetStatus(pNamespace,pResponseHandler, hr);
	return hr;
}

HRESULT Audit_Record_WMI_Provider::EnumerateAuditRecord(std::vector<Audit_Record_WMI_Provider>& auditVec, uint32& ReturnValue)
{
	ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		do{
			MEAdminAudit MEAudit;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetMESetupAudit(&MEAudit);
			if (ReturnValue != S_OK)
			{
				break;
			}
			std::wstring instanceID = L"Intel(R) AMT Setup Audit record";
			Audit_Record_WMI_Provider auditRecord(MEAudit, instanceID);
			auditVec.push_back(auditRecord);
		} while(0);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	return hr;
}

Audit_Record_WMI_Provider::Audit_Record_WMI_Provider(const MEAdminAudit &MEAudit, const std::wstring &instanceID)
{
	InstanceID = instanceID;
	ProvisioningTLSMode = MEAudit.ProvisioningTLSMode;
	SecureDNS = MEAudit.SecureDNS;
	HostInitiated = MEAudit.HostInitiated;
	SelectedHashType = MEAudit.SelectedHashType;
	SelectedHashData = MEAudit.SelectedHashData;
	CACertificateSerial1 = MEAudit.CACertificateSerial1;
	CACertificateSerial2 = MEAudit.CACertificateSerial2;
	CACertificateSerial3 = MEAudit.CACertificateSerial3;
	AdditionalCaSerialNums = MEAudit.AdditionalCaSerialNums;
	IsOemDefault = MEAudit.IsOemDefault;
	IsTimeValid = MEAudit.IsTimeValid;
	ProvServerIP = MEAudit.ProvServerIP;
	ProvServerFQDN = MEAudit.ProvServerFQDN;
	wchar_t sdate[256];
	swprintf_s(sdate, 256, L"%.4d%.2d%.2d%.2d%.2d%.2d.000000+000", MEAudit.TlsStartTime.Year,
		 MEAudit.TlsStartTime.Month,MEAudit.TlsStartTime.Day,
		 MEAudit.TlsStartTime.Hour,MEAudit.TlsStartTime.Minute,
		 MEAudit.TlsStartTime.Second);
	
	TlsStartTime = sdate; 
}

HRESULT Audit_Record_WMI_Provider::GetAudit_Record(
									 IWbemServices* pNamespace,
									 const BSTR strObjectPath,
									 IWbemContext __RPC_FAR *pCtx,
									 IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	HRESULT hr = 0;
	uint32 ReturnValue = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::map <std::wstring, CComVariant> keyList;
		std::map <std::wstring, CComVariant>::const_iterator it ;
		GetKeysList(keyList, strObjectPath);
		it = keyList.find(L"InstanceID");
		if (it == keyList.end())
		{
			hr = WBEM_E_INVALID_METHOD_PARAMETERS;
			return hr;
		}

		do 
		{
			MEAdminAudit MEAudit;
			PTHI_Commands pthic;
			ReturnValue = pthic.GetMESetupAudit(&MEAudit);

			if (ReturnValue != S_OK)
			{
				WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
				break;
			}

			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_SetupAuditRecord"));
			BREAKIF(WMIPut<1>(obj, L"InstanceID", L"Intel(R) AMT Setup Audit record"));
			BREAKIF(WMIPut<1>(obj, L"ProvisioningTLSMode", MEAudit.ProvisioningTLSMode));
			BREAKIF(WMIPut<1>(obj, L"SecureDNS", MEAudit.SecureDNS));
			BREAKIF(WMIPut<1>(obj, L"HostInitiated", MEAudit.HostInitiated));
			BREAKIF(WMIPut<1>(obj, L"SelectedHashType", MEAudit.SelectedHashType));
			BREAKIF(WMIPut<uint8>(obj, L"SelectedHashData", MEAudit.SelectedHashData));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial1", MEAudit.CACertificateSerial1));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial2", MEAudit.CACertificateSerial2));
			BREAKIF(WMIPut<uint8>(obj, L"CACertificateSerial3", MEAudit.CACertificateSerial3));
			BREAKIF(WMIPut<1>(obj, L"AdditionalCaSerialNums", MEAudit.AdditionalCaSerialNums));
			BREAKIF(WMIPut<1>(obj, L"IsTimeValid", MEAudit.IsTimeValid));
			BREAKIF(WMIPut<1>(obj, L"ProvServerIP", MEAudit.ProvServerIP));
			BREAKIF(WMIPut<1>(obj, L"ProvServerFQDN", MEAudit.ProvServerFQDN));
			
			wchar_t sdate[256];
			swprintf_s(sdate, 256, L"%.4d%.2d%.2d%.2d%.2d%.2d.000000+000", MEAudit.TlsStartTime.Year,
				 MEAudit.TlsStartTime.Month,MEAudit.TlsStartTime.Day,
				 MEAudit.TlsStartTime.Hour,MEAudit.TlsStartTime.Minute,
				 MEAudit.TlsStartTime.Second);
			std::wstring date = sdate;
			BREAKIF(WMIPut<1>(obj, L"CreationTimeStamp", date));
			
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
