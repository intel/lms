/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: EthernetPortSettings_WMI_Provider.cpp

--*/

#include "EthernetPortSettings_WMI_Provider.h"
#include "pthi_commands.h"
#include "WSmanCommands.h"
#include "WMIHelper.h"

HRESULT EthernetPortSettings_WMI_Provider::Enumerate(
								IWbemServices* pNamespace,
								IWbemContext __RPC_FAR *pCtx,
								IWbemObjectSink __RPC_FAR *pResponseHandler)
{
	//Get all keys in a colllection, from an internal function
	uint32 ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::vector<EthernetPortSettings_WMI_Provider> ethernetPortList;
		hr = EnumerateEthernetPortSettings(ethernetPortList, ReturnValue);
		if (STATUS_SUCCESS == ReturnValue)
		{
			std::vector<EthernetPortSettings_WMI_Provider>::iterator entry;
			entry = ethernetPortList.begin();
			for (; entry != ethernetPortList.end(); entry++)
			{
				CComPtr<IWbemClassObject> obj;
				RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_EthernetPortSettings"));
				BREAKIF(WMIPut<1>(obj, L"ElementName", entry->ElementName));
				BREAKIF(WMIPut<1>(obj, L"InstanceID", entry->InstanceID));
				BREAKIF(WMIPut<1>(obj, L"MACAddress", entry->MACAddress));
				BREAKIF(WMIPut<1>(obj, L"LinkIsUp", entry->LinkIsUp));
				BREAKIF(WMIPut<1>(obj, L"DHCPEnabled", entry->DHCPEnabled));
				
				BREAKIF(WMIPut<1>(obj, L"IPAddress", entry->IPAddress ));
				BREAKIF(WMIPut<1>(obj, L"SubnetMask",entry->SubnetMask));
				BREAKIF(WMIPut<1>(obj, L"DefaultGateway",entry->DefaultGateway));
				BREAKIF(WMIPut<1>(obj, L"PrimaryDNS",entry->PrimaryDNS ));
				BREAKIF(WMIPut<1>(obj, L"SecondaryDNS",entry->SecondaryDNS));
		
				BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}
		}
		else
		{
			WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
			return hr;
		}
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
	}

	WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	return hr;
}

HRESULT EthernetPortSettings_WMI_Provider::EnumerateEthernetPortSettings(std::vector<EthernetPortSettings_WMI_Provider>& settingsVec, uint32& ReturnValue)
{
	ReturnValue = 0;
	HRESULT hr = 0;
	EntryExitLog log(__FUNCTION__, ReturnValue, hr);

	try
	{
		std::vector<EthernetPortEntry> ethernetPortList;
		ReturnValue = GetPortList(ethernetPortList);
		if (STATUS_SUCCESS == ReturnValue)
		{	
			std::vector<EthernetPortEntry>::iterator entry;
			entry = ethernetPortList.begin();
			int i = 1;
			for (; entry != ethernetPortList.end(); entry++)
			{
				std::wstring elementName = L"Intel(r) AMT Ethernet Port Settings";
				WCHAR str[256];
				swprintf_s(str, 256, L"Intel(r) AMT Ethernet Port Settings %d",i++);
				std::wstring instanceID(str);
				EthernetPortSettings_WMI_Provider setting(*entry, instanceID, elementName);
				settingsVec.push_back(setting);
			}
		}
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	return hr;
}

uint32 EthernetPortSettings_WMI_Provider::GetPortList(std::vector<EthernetPortEntry>& ethernetPortList)
{
	uint32 ReturnValue;
	PTHI_Commands pthic;
	std::vector<EthernetPortEntryWSMan> ethernetPortWSManList;
	WSmanCommands wsmc;

	ReturnValue = wsmc.GetPortSettings(ethernetPortWSManList);
	if (ReturnValue == STATUS_SUCCESS)
	{
		std::vector<EthernetPortEntryWSMan>::iterator portIterator;
		portIterator = ethernetPortWSManList.begin();	
		for (; portIterator != ethernetPortWSManList.end(); portIterator++)
		{
			EthernetPortEntry entry;
			entry.DefaultGateway = portIterator->DefaultGateway;
			entry.DHCPEnabled = portIterator->DHCPEnabled;
			entry.IPAddress = portIterator->IPAddress;
			entry.LinkIsUp = portIterator->LinkIsUp;
			entry.MACAddress = portIterator->MACAddress;
			entry.PrimaryDNS = portIterator->PrimaryDNS;
			entry.SecondaryDNS = portIterator->SecondaryDNS;
			entry.SubnetMask = portIterator->SubnetMask;
			ethernetPortList.push_back(entry);
		}
	}
	//if failed try using pthi
	else
	{
		ReturnValue = pthic.GetPortSettings(ethernetPortList);
	}
	return ReturnValue;
}

EthernetPortSettings_WMI_Provider::EthernetPortSettings_WMI_Provider(const EthernetPortEntry &port,
	const std::wstring &instanceID, const std::wstring &elementName)
{
	InstanceID = instanceID;
	ElementName = elementName;
	DefaultGateway = port.DefaultGateway;
	DHCPEnabled = port.DHCPEnabled;
	IPAddress = port.IPAddress;
	LinkIsUp = port.LinkIsUp;
	MACAddress = port.MACAddress;
	PrimaryDNS = port.PrimaryDNS;
	SecondaryDNS = port.SecondaryDNS;
	SubnetMask = port.SubnetMask;
}

HRESULT EthernetPortSettings_WMI_Provider::Get_PortSettings(
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
		std::wstring val = (it->second).bstrVal;
		const WCHAR* str = val.c_str();
		unsigned int num = _wtoi(str+wcslen(L"Intel(r) AMT Ethernet Port Settings"));

		do 
		{
			std::vector<EthernetPortEntry> ethernetPortList;
			ReturnValue = GetPortList(ethernetPortList);

			if (ReturnValue != S_OK)
			{
				WMIHelper::PTHIHandleSetStatus(pNamespace, pResponseHandler, ReturnValue, hr);
				return hr;
			}
			
			if (num < 1 || num > ethernetPortList.size())
			{
				hr = WBEM_E_PROVIDER_FAILURE;
				break;
			}
			
			
			if (ReturnValue == STATUS_SUCCESS)
			{
			const EthernetPortEntry &entry = ethernetPortList.at(num-1);
			CComPtr<IWbemClassObject> obj;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"AMT_EthernetPortSettings"));

			BREAKIF(WMIPut<1>(obj, L"ElementName", L"Intel(r) AMT Ethernet Port Settings"));
			WCHAR strEthPort[256];
			swprintf_s(strEthPort, 256, L"Intel(r) AMT Ethernet Port Settings %d",num);
			BREAKIF(WMIPut<1>(obj, L"InstanceID", strEthPort));

			BREAKIF(WMIPut<1>(obj, L"MACAddress", entry.MACAddress));
			BREAKIF(WMIPut<1>(obj, L"LinkIsUp", entry.LinkIsUp));

			BREAKIF(WMIPut<1>(obj, L"DHCPEnabled", entry.DHCPEnabled));
			BREAKIF(WMIPut<1>(obj, L"IPAddress", entry.IPAddress));
			BREAKIF(WMIPut<1>(obj, L"SubnetMask", entry.SubnetMask));
			BREAKIF(WMIPut<1>(obj, L"DefaultGateway", entry.DefaultGateway));
			BREAKIF(WMIPut<1>(obj, L"PrimaryDNS", entry.PrimaryDNS));
			BREAKIF(WMIPut<1>(obj, L"SecondaryDNS", entry.SecondaryDNS));

			
			BREAKIF(pResponseHandler->Indicate(1, &obj.p));
			}
		}while(0);

		WMIHandleSetStatus(pNamespace, pResponseHandler, hr);
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in %C: %C\n", __FUNCTION__, e.what());
		hr = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
		hr  = WBEM_E_PROVIDER_FAILURE;
		ReturnValue = ERROR_EXCEPTION_IN_SERVICE;
	}

	return hr;
}
