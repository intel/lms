/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2023-2024 Intel Corporation
 */
#include "wmiinfrastructure.h"

template<>
HRESULT  WMIGetClass(IWbemServices* srv,
	IWbemClassObject* obj,
	LPCWSTR             name,
	std::vector<std::wstring>& vec)
{
	_variant_t  val;
	CIMTYPE     type;

	ASSERT(obj);
	vec.clear();
	RETURNIF(obj->Get(name, 0, &val, &type, NULL));

	if (val.vt != VT_NULL)
	{
		SAFEARRAY* array = val.parray;

		for (ULONG i = 0; i < array->rgsabound->cElements; i++)
		{
			LONG    ix = i;

			CComPtr<IWbemClassObject>   elem;
			BSTR data;
			SafeArrayGetElement(array, &ix, &data);
			// RETURNIF(WMIGetClass(srv, elem, NULL, var));

			vec.push_back(data);

			ix++;
		}
	}

	return  S_OK;
}

HRESULT WMIGetMember(
	IWbemServices* srv,
	IWbemClassObject* root,
	CComPtr<IWbemClassObject>& embedded,
	LPCWSTR                     name,
	LPCWSTR                     type)
{
	if (name)
	{
		_variant_t  var;

		ASSERT(root);

		RETURNIF(root->Get(name, 0, &var, NULL, NULL));
		if (var.vt != VT_NULL)
			RETURNIF(var.punkVal->QueryInterface(IID_IWbemClassObject, (void**)&embedded.p));
		else
			return  E_INVALIDARG;
	}
	else
	{
		embedded = root;
	}

	return S_OK;
}

HRESULT WMIPutMember(
	IWbemServices* srv,
	IWbemClassObject** root,
	LPCWSTR                     type)
{
	HRESULT hr = WBEM_S_NO_ERROR;

	CComPtr<IWbemClassObject>   spClass;

	ASSERT(srv);

	RETURNIF(srv->GetObject(CComBSTR(type), 0, NULL, &spClass.p, NULL));   ASSERT(spClass);
	RETURNIF(spClass->SpawnInstance(0, root));            ASSERT(root);

	return hr;
}

HRESULT WMIGetMethodOParams(
	IWbemClassObject* pOClass,
	LPCWSTR             name,
	IWbemClassObject** oparam)
{
	CComPtr<IWbemClassObject>   oParamClass;

	ASSERT(pOClass);

	RETURNIF(pOClass->GetMethod(name, 0, NULL, &oParamClass));  ASSERT(oParamClass);
	RETURNIF(oParamClass->SpawnInstance(0, oparam));            ASSERT(oparam);

	return  S_OK;
}

HRESULT WMIGetMethodIParams(
	IWbemServices* srv,
	IWbemClassObject* pOClass,
	LPCWSTR             name,
	IWbemClassObject** iparam)
{
	CComPtr<IWbemClassObject>   iParamClass;

	ASSERT(pOClass);

	RETURNIF(pOClass->GetMethod(name, 0, &iParamClass.p, NULL));
	RETURNIF(iParamClass->SpawnInstance(0, iparam));            ASSERT(iparam);

	return  S_OK;
}

HRESULT ProcessObjectPath(
	const wchar_t* member,
	std::wstring& root,
	std::wstring& tail,
	long& index)
{
	const wchar_t* dot = wcschr(member, L'.');
	const wchar_t* open = wcschr(member, L'[');

	root = member;
	index = -1;
	tail = L"";

	if (dot == NULL)
		return  S_OK;

	root = member;
	tail.assign(dot + 1);
	index = -1;

	if (open && open < dot && *(dot - 1) == ']')
	{
		root.assign(member, open - member);
		index = _wtoi(std::wstring(open + 1, dot - open - 1).c_str());
	}
	else
	{
		root.assign(member, dot - member);
	}

	return  S_OK;
}

HRESULT GetKeysList(std::map <std::wstring, CComVariant>& keyList, const std::wstring& strClass)
{

	HRESULT hr = WBEM_E_PROVIDER_FAILURE;
	try {
		CComPtr<IWbemPath>pParser;
		hr = CoCreateInstance(CLSID_WbemDefPath,
			0,
			CLSCTX_INPROC_SERVER,
			IID_IWbemPath,
			(LPVOID*)&pParser);
		// -- do something
		if (FAILED(hr))
		{
			return hr;
		}
		pParser->SetText(WBEMPATH_CREATE_ACCEPT_ALL, strClass.c_str());
		wchar_t className[256];
		unsigned long size = 256;
		pParser->GetClassName(&size, className);

		CComPtr<IWbemPathKeyList> pIKeyList;
		hr = pParser->GetKeyList(&pIKeyList);
		if (FAILED(hr))
		{
			return hr;
		}
		unsigned long ulNumKeys = 0;
		hr = pIKeyList->GetCount(&ulNumKeys);

		if (FAILED(hr))
		{
			return hr;
		}
		//Get values of key properties
		unsigned long uKeyNameBufferSize = 256;//strClass + 1;
		WCHAR* wKeyName = new WCHAR[uKeyNameBufferSize];
		if (NULL == wKeyName)
		{
			return WBEM_E_OUT_OF_MEMORY;
		}
		CComVariant vValue;
		unsigned long ulApparentCimType;
		for (unsigned long i = 0; i < ulNumKeys; i++)
		{
			uKeyNameBufferSize = 256;
			hr = pIKeyList->GetKey2(i, 0L, &uKeyNameBufferSize,
				wKeyName, &vValue, &ulApparentCimType);
			if (SUCCEEDED(hr))
				keyList[wKeyName] = vValue;
			//TODO: save vValue for later use
		}

		delete[] wKeyName;
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
	}
	return hr;
}

HRESULT WMIHandleSetStatus(IWbemServices* pNamespace, IWbemObjectSink  __RPC_FAR* pResponseHandler, unsigned long hrInput)
{
	try
	{
		if (hrInput == STATUS_SUCCESS)
		{
			pResponseHandler->SetStatus(WBEM_STATUS_COMPLETE, hrInput, NULL, NULL);
			return S_OK;
		}
		// not ok.
		CComPtr<IWbemClassObject> obj;
		do
		{
			HRESULT  hr; // used by BREAKIF
			RETURNIF(WMIPutMember(pNamespace, &obj, L"__ExtendedStatus"));
			std::wstringstream str;
			str << L"Function failed with return code = " << hrInput << std::endl;
			BREAKIF(WMIPut<1>(obj, L"Description", str.str()));
			uint32 xx = hrInput;
			BREAKIF(WMIPut<1>(obj, L"StatusCode", xx));
		} while (0);
		pResponseHandler->SetStatus(WBEM_STATUS_COMPLETE, WBEM_E_PROVIDER_FAILURE, CComBSTR(L"Error"), obj);
		UNS_ERROR("Function failed with return code = %u\n", hrInput);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
	}
	return S_OK;
}

template<bool log>
HRESULT WMIPut(IWbemClassObject* obj, LPCWSTR name, std::wstring& var)
{
	variant_t  val(var.c_str());

	if (0 == wcscmp(name, L"Password")) //Zero the memory of the decrypted password
	{
		HRESULT hr = obj->Put(name, 0, &val, 0);
		memset(val.bstrVal, 0, (var.size() * sizeof(wchar_t)));
		if (hr != S_OK)
		{
			UNS_ERROR("Bad WMI Param %W\n", name);
			return hr;
		}
	}
	else
	{
		RETURNIF(obj->Put(name, 0, &val, 0));
	}

	/*   if(log)
		   Debug.Param() << "    wmiput - " << name << " : " << var;
	   else
		   Debug.Param() << "    wmiput - " << name << " : ********";*/

	return  S_OK;
}