/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2026 Intel Corporation
 */
#include <iostream>
#include <iomanip>
#include <comdef.h>
#include <Wbemidl.h>
#include <gtest/gtest.h>
#include <atlsafe.h>
#include <comutil.h>
#include <ctime>

static const UINT32 AMT_STATUS_INVALID_AMT_MODE = 0x80873003;
static const UINT32 AMT_STATUS_NOT_PERMITTED = 0x80873010;
static const UINT32 AMT_STATUS_NOT_READY = 0x80873002;
static const UINT32 AMT_STATUS_HOTHAM_ERROR = 0x80873080;
static const UINT32 AMT_STATUS_WIFI_NOT_AVAIL = 0x808733E8U;
static const UINT32 AMT_STATUS_AMTHI_ZERO_LEN_RESP = 0x80875000;
static const std::string REQUEST = "SELECT * FROM ";

#pragma comment(lib, "wbemuuid.lib")
class InputParam
{
public:
	LPCWSTR name;
	CIMTYPE_ENUMERATION type;
	_variant_t value;
	InputParam(LPCWSTR param_name, CIMTYPE_ENUMERATION param_type, _variant_t param_value)
	{
		name = param_name;
		type = param_type;
		value = param_value;
	}
};

bool isReturnValueValid(UINT32 return_val)
{
	if (return_val == 0 || return_val == AMT_STATUS_NOT_READY)
		return true;
	return false;
}

bool isReturnValueValidEx(UINT32 return_val, const std::vector<UINT32> &additional_values)
{
	if (return_val == 0 || return_val == AMT_STATUS_NOT_READY)
		return true;
	for (std::vector<UINT32>::const_iterator it = additional_values.begin(); it != additional_values.end(); ++it)
		if (return_val == *it)
			return true;
	return false;
}
class MEProvTest : public ::testing::Test {
protected:
	IWbemLocator  *pLoc;
	IWbemServices *pSvc;

	MEProvTest() : pLoc(NULL), pSvc(NULL)
	{
	}

	void SetUp() override
	{
		HRESULT hres;

		hres = CoInitializeEx(0, COINIT_MULTITHREADED);
		if (FAILED(hres))
		{
			std::cerr << "Failed to initialize COM library. Error code = 0x"
				<< std::hex << hres << std::endl;
			throw std::exception("Failed to initialize COM library.", hres);
		}

		hres = CoInitializeSecurity(
			NULL,
			-1,                          // COM authentication
			NULL,                        // Authentication services
			NULL,                        // Reserved
			RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
			RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
			NULL,                        // Authentication info
			EOAC_NONE,                   // Additional capabilities
			NULL                         // Reserved
		);
		if (FAILED(hres))
		{
			std::cerr << "Failed to initialize security. Error code = 0x"
				<< std::hex << hres << std::endl;
			CoUninitialize();
			throw std::exception("Failed to initialize security.", hres);
		}

		hres = CoCreateInstance(
			CLSID_WbemLocator,
			0,
			CLSCTX_INPROC_SERVER,
			IID_IWbemLocator, (LPVOID *)&pLoc);
		if (FAILED(hres))
		{
			std::cerr << "Failed to create IWbemLocator object. Error code = 0x"
				<< std::hex << hres << std::endl;
			CoUninitialize();
			throw std::exception("Failed to create IWbemLocator object.", hres);
		}

		hres = pLoc->ConnectServer(
			_bstr_t(L"ROOT\\INTEL_ME"), // Object path of WMI namespace
			NULL,                    // User name. NULL = current user
			NULL,                    // User password. NULL = current
			0,                       // Locale. NULL indicates current
			NULL,                    // Security flags.
			0,                       // Authority (for example, Kerberos)
			0,                       // Context object
			&pSvc                    // pointer to IWbemServices proxy
		);
		if (FAILED(hres))
		{
			std::cout << "Could not connect. Error code = 0x"
				<< std::hex << hres << std::endl;
			pLoc->Release();
			CoUninitialize();
			throw std::exception("Could not connect.", hres);
		}

		hres = CoSetProxyBlanket(
			pSvc,                        // Indicates the proxy to set
			RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
			RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
			NULL,                        // Server principal name
			RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx
			RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
			NULL,                        // client identity
			EOAC_NONE                    // proxy capabilities
		);
		if (FAILED(hres))
		{
			std::cout << "Could not set proxy blanket. Error code = 0x"
				<< std::hex << hres << std::endl;
			throw std::exception("Could not set proxy blanket.", hres);
		}
	}

	void TearDown() override {

		pSvc->Release();
		pLoc->Release();
		CoUninitialize();
	}

	template<class T> bool runCommandOneReturn(const wchar_t* method_name, const wchar_t* class_name, const wchar_t* arg_name,
		UINT32& return_value, T& value)
	{
		// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--calling-a-provider-method
		HRESULT hres;
		BSTR MethodName = SysAllocString(method_name);
		BSTR ClassName = SysAllocString(class_name);

		IWbemClassObject* pClass = NULL;
		IWbemClassObject* pOutParams = NULL;
		hres = pSvc->GetObject(ClassName, 0, NULL, &pClass, NULL);
		if (FAILED(hres))
		{
			std::cerr << "failed to get class name. Error code = 0x" << std::hex << hres << std::endl;
			goto release;

		}
		hres = pSvc->ExecMethod(ClassName, MethodName, 0,
			NULL, NULL, &pOutParams, NULL);
		if (FAILED(hres))
		{
			std::cerr << "Could not execute method. Error code = 0x"
				<< std::hex << hres << std::endl;
			goto release;

		}
		VARIANT varReturnValue;
		hres = pOutParams->Get(_bstr_t(L"ReturnValue"), 0,
			&varReturnValue, NULL, 0);
		if (FAILED(hres))
		{
			std::cerr << "failed to get returnval. Error code = 0x";
			goto release;

		}
		return_value = varReturnValue.intVal;
		VariantClear(&varReturnValue);

		VARIANT varEnabled;
		hres = pOutParams->Get(_bstr_t(arg_name), 0,
			&varEnabled, NULL, 0);
		if (FAILED(hres))
		{
			std::cerr << "failed to get arg: " << arg_name << ". Error code = 0x" << std::hex << hres << std::endl;

			goto release;

		}
		value = static_cast<T>(varEnabled.llVal);
		VariantClear(&varEnabled);

	release:
		SysFreeString(ClassName);
		SysFreeString(MethodName);
		if (pClass)
		{
			pClass->Release();
		}
		if (pOutParams)
		{
			pOutParams->Release();
		}
		if (FAILED(hres))
		{
			return false;
		}
		return true;
	}

	bool runCommandMultipleArguments(const wchar_t* method_name,
									 const wchar_t* class_name,
									 UINT32& return_value,
									 const std::vector<std::string>& out_param_names,
									 std::vector<_variant_t>&out_param_values,
									 std::vector<InputParam>& input_params)
	{

		// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--calling-a-provider-method
		HRESULT hres;
		BSTR MethodName = SysAllocString(method_name);
		BSTR ClassName = SysAllocString(class_name);
		IWbemClassObject* pClass = NULL;
		IWbemClassObject* pOutParams = NULL;
		IWbemClassObject* pInParamsDefinition = NULL;
		IWbemClassObject* pClassInstance = NULL;
		if (input_params.size() > 0)
		{
			hres = pSvc->GetObject(ClassName, 0, NULL, &pClass, NULL);
			if (FAILED(hres))
			{
				std::cerr << "failed to get class name. Error code = 0x" << std::hex << hres << std::endl;
				goto release;
			}
			hres = pClass->GetMethod(MethodName, 0, &pInParamsDefinition, NULL);
			if (FAILED(hres))
			{
				std::cerr << "failed to GetMethod. Error code = 0x" << std::hex << hres << std::endl;
				goto release;
			}

			hres = pInParamsDefinition->SpawnInstance(0, &pClassInstance);
			if (FAILED(hres))
			{
				std::cerr << "failed to SpawnInstance. Error code = 0x" << std::hex << hres << std::endl;
				goto release;
			}
			for (std::vector<InputParam>::iterator it = input_params.begin(); it != input_params.end(); ++it)
			{
				hres = pClassInstance->Put(it->name, 0, &it->value, it->type);
				if (FAILED(hres))
				{
					std::cerr << "failed put input param " << it->name << ". Error code = 0x" << std::hex << hres << std::endl;
					goto release;
				}
			}

		}

		hres = pSvc->ExecMethod(ClassName, MethodName, 0,
			NULL, pClassInstance, &pOutParams, NULL);
		if (FAILED(hres))
		{
			std::cerr << "Could not execute method. Error code = 0x"
				<< std::hex << hres << std::endl;
			goto release;
		}
		VARIANT varReturnValue;
		hres = pOutParams->Get(_bstr_t(L"ReturnValue"), 0,
			&varReturnValue, NULL, 0);
		if (FAILED(hres))
		{

			std::cerr << "failed to get returnval. Error code = 0x"
				<< std::hex << hres << std::endl;
			goto release;
		}
		return_value = varReturnValue.intVal;
		VariantClear(&varReturnValue);

		for (std::vector<std::string>::const_iterator it = out_param_names.begin(); it != out_param_names.end(); ++it)
		{
			VARIANT varEnabled;
			hres = pOutParams->Get(_bstr_t((*it).c_str()), 0, &varEnabled, NULL, 0);
			if (FAILED(hres))
			{
				std::cerr << "failed to get val: " << (*it).c_str() << ". Error code = 0x" << std::hex << hres << std::endl;
				goto release;
			}
			out_param_values.push_back(varEnabled);
		}
		if (out_param_names.size() != out_param_values.size())
		{
			hres = E_FAIL;
			goto release;
		}

release:
		SysFreeString(ClassName);
		SysFreeString(MethodName);
		if (pClass)
		{
			pClass->Release();
		}
		if (pClassInstance)
		{
			pClassInstance->Release();
		}
		if (pInParamsDefinition)
		{
			pInParamsDefinition->Release();
		}
		if (pOutParams)
		{
			pOutParams->Release();
		}
		if (FAILED(hres))
		{
			return false;
		}
		return true;
	}

	void releaseArgs(std::vector<IUnknown*> args)
	{
		for (auto& arg : args)
		{
			if (arg)
			{
				arg->Release();
			}
		}
	}

	bool getWiFiPresent()
	{
		// Determine Wi-Fi presence using AMT-exposed classes in ROOT\INTEL_ME.
		// This avoids false negatives from OS-side adapter filtering.
		auto hasAnyInstance = [this](const char* query) -> bool
		{
			// Run a WQL enumeration query and return true if at least one instance exists.
			IEnumWbemClassObject* pEnum = nullptr;
			HRESULT hres = pSvc->ExecQuery(
				bstr_t("WQL"),
				bstr_t(query),
				WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
				NULL,
				&pEnum);
			if (FAILED(hres) || !pEnum)
				return false;

			IWbemClassObject* pObj = nullptr;
			ULONG uReturn = 0;
			// Next() returns one object and sets uReturn>0 when an instance is available.
			bool found = SUCCEEDED(pEnum->Next(WBEM_INFINITE, 1, &pObj, &uReturn)) && uReturn > 0;
			if (pObj)
				pObj->Release();
			pEnum->Release();
			return found;
		};

		// Treat Wi-Fi as present if AMT exposes at least one Wi-Fi port instance.
		return hasAnyInstance("SELECT * FROM CIM_WiFiPort");
	}

	void queryForObject(IEnumWbemClassObject*& pEnumerator, std::string objectName)
	{
		std::string request(REQUEST + objectName);
		HRESULT hres = pSvc->ExecQuery(
			bstr_t("WQL"),
			bstr_t(request.c_str()),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator);

		if (FAILED(hres))
		{
			std::cerr << "Query for operating system name: " << objectName << " failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator});
			FAIL();
		}

	}
};

//*********enumerators************
TEST_F(MEProvTest, GetFWVersion)
{
	//checks that element inside each object exists.
	//doesn't check if the list is empty (doesn't contain abny object)
	// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--getting-wmi-data-from-the-local-computer
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	std::string objectName = "ME_System";
	queryForObject(pEnumerator, objectName);
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		// Get the value of the property
		VARIANT vtProp;
		hres = pclsObj->Get(L"FWVersion", 0, &vtProp, 0, 0);
		std::wcout << " FWVersion: " << vtProp.bstrVal << std::endl;
		ASSERT_GE(wcslen(vtProp.bstrVal), 9U);
		ASSERT_LE(wcslen(vtProp.bstrVal), 15U);
		VariantClear(&vtProp);
		pclsObj->Release();
		pclsObj = NULL;

	}
	pEnumerator->Release();
}

TEST_F(MEProvTest, AMT_SetupAuditRecord)
{
	// checks only AMT_SetupAuditRecord.
	//doesn't check that element inside each object exists.
	//checks that the list is not empty (doesn't contain abny object)
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	hres = pSvc->ExecQuery(
		bstr_t("WQL"),
		bstr_t("SELECT * FROM AMT_SetupAuditRecord"),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
		NULL,
		&pEnumerator);
	if (hres == WBEM_E_PROVIDER_FAILURE)
	{
		goto release;
	}
	else if (FAILED(hres))
	{
		std::cerr << "Query for operating system name failed. Error code = 0x"
			<< std::hex << hres << std::endl;
		releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
		FAIL();
	}
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			if (hres == WBEM_E_PROVIDER_FAILURE)
			{
				std::cerr << "pEnumerator->Next failed. Error code = 0x" << std::hex << hres << std::endl;
				std::cerr << "error is ignored" << std::endl;
				goto release;
			}
			std::cerr << "pEnumerator->Next failed. Error code = 0x" << std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			items_count++;
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	ASSERT_GE(items_count, 1);
release:
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, CIM_ConcreteComponent)
{
	//checks that element inside each object exists.
	//checks that the list is not empty (doesn't contain abny object)
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	VARIANT vtProp;
	std::string objectName = "CIM_ConcreteComponent";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			items_count++;
			hres = pclsObj->Get(L"GroupComponent", 0, &vtProp, 0, 0);
			if (FAILED(hres))
			{
				std::cerr << "query for var GroupComponent failed. Error code = 0x"
					<< std::hex << hres << std::endl;
				releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
				FAIL();
			}
			std::wcout << "GroupComponent: " << vtProp.bstrVal << std::endl;
			VariantClear(&vtProp);
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	ASSERT_GE(items_count, 1);
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, AMT_EthernetPortSettings)
{
	//checks that element inside each object exists.
	//checks that the list is not empty (doesn't contain abny object)
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	VARIANT vtProp;
	std::string objectName = "AMT_EthernetPortSettings";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});

			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}

		else
		{
			items_count++;
			hres = pclsObj->Get(L"DefaultGateway", 0, &vtProp, 0, 0);
			if (FAILED(hres))
			{
				std::cerr << "query for var DefaultGateway failed. Error code = 0x"
					<< std::hex << hres << std::endl;
				releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
				FAIL();
			}
			EXPECT_EQ(vtProp.vt, VT_BSTR) << "DefaultGateway: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
			if (vtProp.vt == VT_BSTR)
				std::wcout << "  DefaultGateway:               " << vtProp.bstrVal << std::endl;
			VariantClear(&vtProp);

			if (SUCCEEDED(pclsObj->Get(L"MACAddress", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "MACAddress: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  MACAddress:                   " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"LinkIsUp", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BOOL) << "LinkIsUp: expected VT_BOOL (MOF boolean), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BOOL)
					std::wcout << "  LinkIsUp:                     " << (vtProp.boolVal != VARIANT_FALSE ? L"true" : L"false") << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"DHCPEnabled", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BOOL) << "DHCPEnabled: expected VT_BOOL (MOF boolean), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BOOL)
					std::wcout << "  DHCPEnabled:                  " << (vtProp.boolVal != VARIANT_FALSE ? L"true" : L"false") << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"IPAddress", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "IPAddress: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  IPAddress:                    " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"SubnetMask", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "SubnetMask: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  SubnetMask:                   " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"PrimaryDNS", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "PrimaryDNS: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  PrimaryDNS:                   " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"SecondaryDNS", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "SecondaryDNS: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  SecondaryDNS:                 " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"SharedStaticIp", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BOOL) << "SharedStaticIp: expected VT_BOOL (MOF boolean), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BOOL)
					std::wcout << "  SharedStaticIp:               " << (vtProp.boolVal != VARIANT_FALSE ? L"true" : L"false") << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"IpSyncEnabled", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BOOL) << "IpSyncEnabled: expected VT_BOOL (MOF boolean), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BOOL)
					std::wcout << "  IpSyncEnabled:                " << (vtProp.boolVal != VARIANT_FALSE ? L"true" : L"false") << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"LinkPolicy", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, (VARTYPE)(VT_ARRAY | VT_UI1))
					<< "LinkPolicy: expected VT_ARRAY|VT_UI1 (MOF uint8[]), got vt=" << vtProp.vt;
				if (vtProp.vt == (VT_ARRAY | VT_UI1))
				{
					SAFEARRAY* psa = vtProp.parray;
					LONG lBound = 0, uBound = -1;
					SafeArrayGetLBound(psa, 1, &lBound);
					SafeArrayGetUBound(psa, 1, &uBound);
					std::wcout << "  LinkPolicy:                   [";
					for (LONG i = lBound; i <= uBound; i++)
					{
						BYTE val = 0;
						SafeArrayGetElement(psa, &i, &val);
						if (i > lBound) std::wcout << L", ";
						std::wcout << (unsigned int)val;
					}
					std::wcout << L"]" << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"LinkPreference", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "LinkPreference: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
				{
					// ValueMap { "0"=Not Set, "1"=ME, "2"=HOST }
					EXPECT_LE(vtProp.uintVal, 2U) << "LinkPreference not in MOF ValueMap {0,1,2}";
					std::wcout << "  LinkPreference:               " << vtProp.uintVal << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"LinkControl", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "LinkControl: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
				{
					// ValueMap { "0"=Not Set, "1"=ME, "2"=HOST }
					EXPECT_LE(vtProp.uintVal, 2U) << "LinkControl not in MOF ValueMap {0,1,2}";
					std::wcout << "  LinkControl:                  " << vtProp.uintVal << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"ConsoleTcpMaxRetransmissions", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "ConsoleTcpMaxRetransmissions: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					std::wcout << "  ConsoleTcpMaxRetransmissions: " << vtProp.uintVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"WLANLinkProtectionLevel", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "WLANLinkProtectionLevel: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
				{
					// ValueMap { "0"=OVERRIDE, "1"=NONE, "2"=PASSIVE, "3"=HIGH }
					EXPECT_LE(vtProp.uintVal, 3U) << "WLANLinkProtectionLevel not in MOF ValueMap {0,1,2,3}";
					std::wcout << "  WLANLinkProtectionLevel:      " << vtProp.uintVal << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"PhysicalConnectionType", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "PhysicalConnectionType: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
				{
					// ValueMap { "0"=Integrated LAN NIC, "1"=Discrete LAN NIC, "2"=LAN via Thunderbolt, "3"=Wireless LAN }
					EXPECT_LE(vtProp.uintVal, 3U) << "PhysicalConnectionType not in MOF ValueMap {0,1,2,3}";
					std::wcout << "  PhysicalConnectionType:       " << vtProp.uintVal << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"PhysicalNicMedium", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "PhysicalNicMedium: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
				{
					// ValueMap { "0"=SMBUS, "1"=PCIe }
					EXPECT_LE(vtProp.uintVal, 1U) << "PhysicalNicMedium not in MOF ValueMap {0,1}";
					std::wcout << "  PhysicalNicMedium:            " << vtProp.uintVal << std::endl;
				}
				VariantClear(&vtProp);
			}
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
	ASSERT_GE(items_count, 1);
}

TEST_F(MEProvTest, CIM_HostedService)
{
	//checks that element inside each object exists.
	//doesn't check that the list is not empty (doesn't contain abny object)
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	VARIANT vtProp;
	std::string objectName = "CIM_HostedService";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});

			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}

		else
		{
			hres = pclsObj->Get(L"Antecedent", 0, &vtProp, 0, 0);
			if (FAILED(hres))
			{
				std::cerr << "query for var Antecedent failed. Error code = 0x"
					<< std::hex << hres << std::endl;
				releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
				FAIL();
			}
			std::wcout << "Antecedent: " << vtProp.bstrVal << std::endl;
			VariantClear(&vtProp);
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, AMT_ProvisioningCertificateHash)
{
	//doesn't check that element inside each object exists.
	//checks that the list is not empty (doesn't contain abny object)
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "AMT_ProvisioningCertificateHash";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}

		if (0 == uReturn)
		{
			break;
		}
		else
		{
			items_count++;
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
	ASSERT_GE(items_count, 1);
}

//*********one out param AMT service************
TEST_F(MEProvTest, isWebUIEnabled)
{
	SHORT enabled = 0;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"isWebUIEnabled", L"AMT_Service", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	std::wcout << " enabled: " << enabled << std::endl;
}

//*********one out param OOB************
TEST_F(MEProvTest, GetProvisioningState)
{
	SHORT state = 0;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"GetProvisioningState", L"OOB_Service", L"state", return_val, state);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_GE(state, 0);
	ASSERT_LE(state, 3);
	std::wcout << " state: " << state << std::endl;
}

TEST_F(MEProvTest, isRemoteConfigEnabled)
{
	bool enabled;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"isRemoteConfigEnabled", L"OOB_Service", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	std::wcout << " enabled: " << enabled << std::endl;
}

TEST_F(MEProvTest, GetActivationTLSMode)
{
	uint8_t mode;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"GetActivationTLSMode", L"OOB_Service", L"mode", return_val, mode);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_GE(mode, 0);
	ASSERT_LE(mode, 2U);
	std::wcout << " mode: " << mode << std::endl;
}

TEST_F(MEProvTest, isTLSEnabled)
{
	bool enabled;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"isTLSEnabled", L"OOB_Service", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	std::wcout << " enabled: " << enabled << std::endl;
}

TEST_F(MEProvTest, GetAMTFQDN)
{
	BSTR FQDN;
	UINT32 return_val;
	bool ret;

	std::vector<std::string> out_param_names = { "FQDN" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetAMTFQDN", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "FQDN: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		FQDN = (out_param_values[0]).bstrVal;
		std::wcout << " FQDN: " << FQDN << std::endl;
	}
}

//*********one out param ME system************
TEST_F(MEProvTest, getUniquePlatformIDFeatureState)
{
	bool state = false;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"getUniquePlatformIDFeatureState", L"ME_System", L"state", return_val, state);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	std::wcout << " state: " << state << std::endl;
}

TEST_F(MEProvTest, IsFirmwareUpdateEnabled)
{
	bool enabled = false;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"IsFirmwareUpdateEnabled", L"ME_System", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	std::wcout << " enabled: " << enabled << std::endl;
}

TEST_F(MEProvTest, getLastMEResetReason)
{
	UINT32 ReasonCode;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"getLastMEResetReason", L"ME_System", L"ReasonCode", return_val, ReasonCode);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_GE(ReasonCode, 0U);
	ASSERT_LE(ReasonCode, 3U);
	std::wcout << " ReasonCode: " << ReasonCode << std::endl;
}

TEST_F(MEProvTest, getCurrentPowerPolicy)
{
	BSTR PowerPolicy;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "PowerPolicy" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getCurrentPowerPolicy", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "PowerPolicy: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		PowerPolicy = (out_param_values[0]).bstrVal;
		std::wcout << " PowerPolicy: " << PowerPolicy << std::endl;
	}
}

TEST_F(MEProvTest, getFullFWVersion)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "FWVersion" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getFullFWVersion", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// Extract array of 3 strings; ASSERT_EQ on vt is the type check
		VARIANT& varArray = out_param_values[0];
		ASSERT_EQ(varArray.vt, (VT_ARRAY | VT_BSTR));

		SAFEARRAY* psa = varArray.parray;
		LONG lBound = 0;
		SafeArrayGetLBound(psa, 1, &lBound);
		LONG uBound = 0;
		SafeArrayGetUBound(psa, 1, &uBound);
		ASSERT_EQ(uBound - lBound + 1, 3L);

		// SafeArrayGetElement properly locks/unlocks the array and copies each BSTR.
		// Direct pvData access via operator[] is only valid after SafeArrayLock and
		// returns garbage for WMI-owned SAFEARRAYs where pvData has not been locked.
		BSTR bstr0 = NULL, bstr1 = NULL, bstr2 = NULL;
		LONG idx0 = lBound, idx1 = lBound + 1, idx2 = lBound + 2;
		SafeArrayGetElement(psa, &idx0, &bstr0);
		SafeArrayGetElement(psa, &idx1, &bstr1);
		SafeArrayGetElement(psa, &idx2, &bstr2);

		std::wcout << " FWVersion[0] (FT): "       << (bstr0 ? bstr0 : L"(null)") << std::endl;
		std::wcout << " FWVersion[1] (NFT): "      << (bstr1 ? bstr1 : L"(null)") << std::endl;
		std::wcout << " FWVersion[2] (Reserved): " << (bstr2 ? bstr2 : L"(null)") << std::endl;

		SysFreeString(bstr0);
		SysFreeString(bstr1);
		SysFreeString(bstr2);
	}
}

TEST_F(MEProvTest, getFLogSize)
{
	UINT32 fLogSize;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "fLogSize" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getFLogSize", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	// getFLogSize requires administrator privileges, so accept ACCESS_DENIED as valid
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ static_cast<UINT32>(WBEM_E_ACCESS_DENIED), AMT_STATUS_HOTHAM_ERROR }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "fLogSize: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		fLogSize = (out_param_values[0]).uintVal;
		std::wcout << " fLogSize: " << fLogSize << std::endl;
	}
}

TEST_F(MEProvTest, getFLog)
{
	BSTR fLog;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "fLog" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getFLog", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	// getFLog requires administrator privileges, so accept ACCESS_DENIED as valid
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ static_cast<UINT32>(WBEM_E_ACCESS_DENIED), AMT_STATUS_HOTHAM_ERROR }));

	if (return_val == 0)
	{
		ASSERT_EQ(out_param_values.size(), out_param_names.size());
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "fLog: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		fLog = (out_param_values[0]).bstrVal;
		std::wcout << " fLog (hex string, length): " << SysStringLen(fLog) << std::endl;
		// Display first 64 characters of the hex string as sample
		if (SysStringLen(fLog) > 64)
		{
			std::wstring sample(fLog, 64);
			std::wcout << " fLog sample: " << sample << "..." << std::endl;
		}
		else
		{
			std::wcout << " fLog: " << fLog << std::endl;
		}
	}
	else if (return_val == WBEM_E_ACCESS_DENIED)
	{
		std::wcout << " getFLog: Access denied (requires administrator privileges)" << std::endl;
	}
}

TEST_F(MEProvTest, getRTCValue)
{
	UINT32 rtcValue;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "rtcValue" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getRTCValue", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "rtcValue: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		rtcValue = (out_param_values[0]).uintVal;
		std::wcout << " rtcValue (UTC timestamp): " << rtcValue << std::endl;

		// Convert to human-readable format for verification
		time_t timestamp = static_cast<time_t>(rtcValue);
		char timeStr[64];
		struct tm timeInfo;
		gmtime_s(&timeInfo, &timestamp);
		strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S UTC", &timeInfo);
		std::cout << " rtcValue (readable): " << timeStr << std::endl;
	}
}

TEST_F(MEProvTest, getUniquePlatformIDFeatureSupported)
{
	bool supported = false;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"getUniquePlatformIDFeatureSupported", L"ME_System", L"supported", return_val, supported);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	std::wcout << " supported: " << supported << std::endl;
}

TEST_F(MEProvTest, getUniquePlatformIDFeatureOSControlState)
{
	bool state = false;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"getUniquePlatformIDFeatureOSControlState", L"ME_System", L"state", return_val, state);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	std::wcout << " state: " << state << std::endl;
}

//*********multiple out param ME system************
TEST_F(MEProvTest, getUniquePlatformID)
{
	UINT32 OEMPlatformIDType;
	BSTR OEMPlatformID;
	BSTR CSMEPlatformID;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "OEMPlatformIDType", "OEMPlatformID", "CSMEPlatformID" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getUniquePlatformID", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// OEMPlatformIDType: uint32, ValueMap {0=NotSet, 1=Binary, 2=PrintableString}
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "OEMPlatformIDType: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)
			<< "OEMPlatformID: expected VT_BSTR (MOF string), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BSTR)
			<< "CSMEPlatformID: expected VT_BSTR (MOF string), got vt=" << out_param_values[2].vt;

		OEMPlatformIDType = (out_param_values[0]).uintVal;
		EXPECT_LE(OEMPlatformIDType, 2U)
			<< "OEMPlatformIDType value " << OEMPlatformIDType << " not in MOF ValueMap {0,1,2}";
		std::wcout << " OEMPlatformIDType: " << OEMPlatformIDType << std::endl;
		OEMPlatformID = (out_param_values[1]).bstrVal;
		std::wcout << " OEMPlatformID: " << OEMPlatformID << std::endl;
		CSMEPlatformID = (out_param_values[2]).bstrVal;
		std::wcout << " CSMEPlatformID: " << CSMEPlatformID << std::endl;
	}
}

TEST_F(MEProvTest, getCapabilities)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "Capabilities","EnabledCapabilities" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getCapabilities", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_ARRAY | VT_BSTR)
			<< "Capabilities: expected VT_ARRAY|VT_BSTR (MOF string[]), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_ARRAY | VT_BSTR)
			<< "EnabledCapabilities: expected VT_ARRAY|VT_BSTR (MOF string[]), got vt=" << out_param_values[1].vt;

		CComSafeArray<BSTR> Capabilities(out_param_values[0].parray);
		std::wcout << " Capabilities: " << std::endl;
		for (LONG i = Capabilities.GetLowerBound(); i <= Capabilities.GetUpperBound(); i++)
		{
			BSTR bstr = NULL;
			LONG idx = i;
			SafeArrayGetElement(out_param_values[0].parray, &idx, &bstr);
			std::wcout << _com_util::ConvertBSTRToString(bstr) << std::endl;
			SysFreeString(bstr);
		}
		CComSafeArray<BSTR> EnabledCapabilities(out_param_values[1].parray);
		std::wcout << " EnabledCapabilities: " << std::endl;
		for (LONG i = EnabledCapabilities.GetLowerBound(); i <= EnabledCapabilities.GetUpperBound(); i++)
		{
			BSTR bstr = NULL;
			LONG idx = i;
			SafeArrayGetElement(out_param_values[1].parray, &idx, &bstr);
			std::wcout << _com_util::ConvertBSTRToString(bstr) << std::endl;
			SysFreeString(bstr);
		}
	}
}

//*********multiple out param OOB************
TEST_F(MEProvTest, GetRemoteAccessConnectionStatus)
{
	UINT32 NetworkConStatus;
	UINT32 ConnectionTrigger;
	BSTR MPshostName;
	UINT32 RemoteAccessConStatus;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "NetworkConStatus","ConnectionTrigger", "MPshostName","RemoteAccessConStatus" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetRemoteAccessConnectionStatus", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// ValueMap: NetworkConStatus {0=Direct,1=VPN,2=OutsideEnterprise,3=Unknown}
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "NetworkConStatus: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		// ValueMap: ConnectionTrigger {0=UserInitiated,1=Alert,2=Periodic,3=Provisioning}
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "ConnectionTrigger: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BSTR)
			<< "MPshostName: expected VT_BSTR (MOF string), got vt=" << out_param_values[2].vt;
		// ValueMap: RemoteAccessConStatus {0=notConnected,1=connecting,2=connected}
		EXPECT_TRUE(out_param_values[3].vt == VT_I4 || out_param_values[3].vt == VT_UI4)
			<< "RemoteAccessConStatus: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[3].vt;

		NetworkConStatus = (out_param_values[0]).uintVal;
		EXPECT_LE(NetworkConStatus, 3U);
		std::wcout << " NetworkConStatus: " << NetworkConStatus << std::endl;

		ConnectionTrigger = (out_param_values[1]).uintVal;
		EXPECT_LE(ConnectionTrigger, 3U);
		std::wcout << " ConnectionTrigger: " << ConnectionTrigger << std::endl;

		MPshostName = (out_param_values[2]).bstrVal;
		std::wcout << " MPshostName: " << MPshostName << std::endl;

		RemoteAccessConStatus = (out_param_values[3]).uintVal;
		EXPECT_LE(RemoteAccessConStatus, 2U);
		std::wcout << " RemoteAccessConStatus: " << RemoteAccessConStatus << std::endl;
	}
}

TEST_F(MEProvTest, GetHelloPacketDestInfo)
{
	BSTR Address;
	UINT16 ConfigServerListeningPort;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "Address","ConfigServerListeningPort" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetHelloPacketDestInfo", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "Address: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_I4)
			<< "ConfigServerListeningPort: expected VT_I4 (MOF uint16, widened by WMI), got vt=" << out_param_values[1].vt;

		Address = (out_param_values[0]).bstrVal;
		std::wcout << " Address: " << Address << std::endl;

		ConfigServerListeningPort = (out_param_values[1]).uintVal;
		ASSERT_NE(ConfigServerListeningPort, 0);
		std::wcout << " ConfigServerListeningPort: " << ConfigServerListeningPort << std::endl;
	}
}

TEST_F(MEProvTest, GetLocalAdminCredentials)
{
	BSTR Username;
	BSTR Password;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "Username","Password" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetLocalAdminCredentials", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "Username: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)
			<< "Password: expected VT_BSTR (MOF string), got vt=" << out_param_values[1].vt;

		Username = (out_param_values[0]).bstrVal;
		std::wcout << " Username: " << Username << std::endl;

		Password = (out_param_values[1]).bstrVal;
		std::wcout << " Password: " << Password << std::endl;
	}
}

TEST_F(MEProvTest, GetProvisioningInfo)
{
	BSTR PKIDNSSuffix;
	BSTR ConfigServerFQDN;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "PKIDNSSuffix","ConfigServerFQDN" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetProvisioningInfo", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "PKIDNSSuffix: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)
			<< "ConfigServerFQDN: expected VT_BSTR (MOF string), got vt=" << out_param_values[1].vt;

		PKIDNSSuffix = (out_param_values[0]).bstrVal;
		std::wcout << " PKIDNSSuffix: " << PKIDNSSuffix << std::endl;

		ConfigServerFQDN = (out_param_values[1]).bstrVal;
		std::wcout << " ConfigServerFQDN: " << ConfigServerFQDN << std::endl;
	}
}

//*********multiple out param AMT service************
TEST_F(MEProvTest, getKVMState)
{
	UINT32 hardEnabled;
	UINT32 softEnabled;
	bool active;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "hardEnabled","softEnabled" ,"active" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getKVMState", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// ValueMap { "0"=Enabled, "1"=Disabled, "2"=UNKNOWN }
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "hardEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "softEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BOOL)
			<< "active: expected VT_BOOL (MOF boolean), got vt=" << out_param_values[2].vt;

		hardEnabled = (out_param_values[0]).uintVal;
		EXPECT_LE(hardEnabled, 2U);
		std::wcout << " hardEnabled: " << hardEnabled << std::endl;

		softEnabled = (out_param_values[1]).uintVal;
		EXPECT_LE(softEnabled, 2U);
		std::wcout << " softEnabled: " << softEnabled << std::endl;

		active = (out_param_values[2]).boolVal;
		std::wcout << " active: " << active << std::endl;
	}
}

TEST_F(MEProvTest, getSOLState)
{
	UINT32 hardEnabled;
	UINT32 softEnabled;
	bool active;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "hardEnabled","softEnabled" ,"active" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getSOLState", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// ValueMap { "0"=Enabled, "1"=Disabled, "2"=UNKNOWN }
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "hardEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "softEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BOOL)
			<< "active: expected VT_BOOL (MOF boolean), got vt=" << out_param_values[2].vt;

		hardEnabled = (out_param_values[0]).uintVal;
		EXPECT_LE(hardEnabled, 2U);
		std::wcout << " hardEnabled: " << hardEnabled << std::endl;

		softEnabled = (out_param_values[1]).uintVal;
		EXPECT_LE(softEnabled, 2U);
		std::wcout << " softEnabled: " << softEnabled << std::endl;

		active = (out_param_values[2]).boolVal;
		std::wcout << " active: " << active << std::endl;
	}
}

TEST_F(MEProvTest, getIDERState)
{
	UINT32 hardEnabled;
	UINT32 softEnabled;
	bool active;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "hardEnabled","softEnabled" ,"active" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getIDERState", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// ValueMap { "0"=Enabled, "1"=Disabled, "2"=UNKNOWN }
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "hardEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "softEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BOOL)
			<< "active: expected VT_BOOL (MOF boolean), got vt=" << out_param_values[2].vt;

		hardEnabled = (out_param_values[0]).uintVal;
		EXPECT_LE(hardEnabled, 2U);
		std::wcout << " hardEnabled: " << hardEnabled << std::endl;

		softEnabled = (out_param_values[1]).uintVal;
		EXPECT_LE(softEnabled, 2U);
		std::wcout << " softEnabled: " << softEnabled << std::endl;

		active = (out_param_values[2]).boolVal;
		std::wcout << " active: " << active << std::endl;
	}
}
TEST_F(MEProvTest, setUniquePlatformIDFeatureState)
{
	//Save the original state
	bool org_state = false;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"getUniquePlatformIDFeatureState", L"ME_System", L"state", return_val, org_state);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	std::wcout << " org_state: " << org_state << std::endl;

	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params;
	VARIANT state;
	VariantInit(&state);
	state.vt = VT_BOOL;
	state.boolVal = !org_state;
	input_params.push_back(InputParam(L"state", CIM_EMPTY, state));
	ret = runCommandMultipleArguments(L"setUniquePlatformIDFeatureState", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	//Restoring original state
	state.boolVal = org_state;
	input_params.clear();
	input_params.push_back(InputParam(L"state", CIM_EMPTY, state));
	ret = runCommandMultipleArguments(L"setUniquePlatformIDFeatureState", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_INVALID_AMT_MODE }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

}

//*********no out param OOB************
TEST_F(MEProvTest, CloseUserInitiatedConnection)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"CloseUserInitiatedConnection", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_NOT_PERMITTED }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
}

TEST_F(MEProvTest, OpenUserInitiatedConnection)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"OpenUserInitiatedConnection", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_NOT_PERMITTED }));
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
}

//*********multiple out param AMT service************
TEST_F(MEProvTest, setSpriteZoom)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params;
	VARIANT zoom;
	VariantInit(&zoom);
	zoom.vt = VT_BSTR;
	zoom.bstrVal = SysAllocString(L"1");
	input_params.push_back(InputParam(L"zoom", CIM_UINT8, zoom));
	ret = runCommandMultipleArguments(L"setSpriteZoom", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
}

TEST_F(MEProvTest, setSpriteLocale)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params;
	VARIANT locale;
	VariantInit(&locale);
	locale.vt = VT_BSTR;
	locale.bstrVal = SysAllocString(L"0"); // 0 = English (MOF ValueMap)
	input_params.push_back(InputParam(L"locale", CIM_UINT8, locale));
	ret = runCommandMultipleArguments(L"setSpriteLocale", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	EXPECT_FALSE(ret) << "setSpriteLocale is expected to be unsupported (WBEM_E_NOT_SUPPORTED)";
	ASSERT_TRUE(out_param_values.empty());
}

TEST_F(MEProvTest, TerminateKVMSession)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"TerminateKVMSession", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
}

TEST_F(MEProvTest, getCIRALog)
{
	BSTR ciraLog;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "ciraLog" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getCIRALog", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_AMTHI_ZERO_LEN_RESP }));

	if (return_val == 0)
	{
		ASSERT_EQ(out_param_values.size(), out_param_names.size());
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)
			<< "ciraLog: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		ciraLog = (out_param_values[0]).bstrVal;
		std::wcout << " ciraLog (hex string, length): " << SysStringLen(ciraLog) << std::endl;
		if (SysStringLen(ciraLog) > 64)
		{
			std::wstring sample(ciraLog, 64);
			std::wcout << " ciraLog sample: " << sample << "..." << std::endl;
		}
		else
		{
			std::wcout << " ciraLog: " << ciraLog << std::endl;
		}
	}
	else if (return_val == AMT_STATUS_AMTHI_ZERO_LEN_RESP)
	{
		std::wcout << " getCIRALog: zero-length response from firmware (CIRA log not available)" << std::endl;
	}
}

TEST_F(MEProvTest, getBootCapabilities)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "IDER", "SOL", "BIOSReflash", "BIOSSetup", "BIOSPause",
		"ForcePXEBoot", "ForceHardDriveBoot", "ForceDiagnosticBoot", "ForceCDorDVDBoot",
		"VerbosityScreenBlank", "PowerButtonLock", "ResetButtonLock", "KeyboardLock",
		"SleepButtonLock", "UserPasswordBypass", "ForcedProgressEvents", "VerbosityVerbose",
		"VerbosityQuiet", "ConfigurationDataReset", "BIOSSecureBoot", "SecureErase",
		"ForceWinREBoot", "ForceUEFIPBABoot", "ForceUEFIHTTPSBoot", "AMTSecureBootControl",
		"UEFIWiFiCoExistenceAndProfileShare", "PlatformErase" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getBootCapabilities", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// Indices 0..25 are boolean; index 26 (PlatformErase) is uint32
		for (size_t i = 0; i < 26; ++i)
		{
			EXPECT_EQ(out_param_values[i].vt, VT_BOOL)
				<< out_param_names[i] << ": expected VT_BOOL (MOF boolean), got vt=" << out_param_values[i].vt;
		}
		EXPECT_TRUE(out_param_values[26].vt == VT_I4 || out_param_values[26].vt == VT_UI4)
			<< "PlatformErase: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[26].vt;

		for (size_t i = 0; i < 26; ++i)
		{
			std::wcout << " " << out_param_names[i].c_str() << ": "
				<< (out_param_values[i].boolVal != VARIANT_FALSE ? "true" : "false") << std::endl;
		}
		std::wcout << " PlatformErase: " << out_param_values[26].uintVal << std::endl;
	}
}

TEST_F(MEProvTest, getEnvironmentDetectionSettingData)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "DetectionAlgorithm", "DetectionStrings", "DetectionIPv6LocalPrefixes" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getEnvironmentDetectionSettingData", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// DetectionAlgorithm: MOF uint16, widened to VT_I4 by WMI; ValueMap {0=LocalDomains, 1=RemoteURLs}
		EXPECT_EQ(out_param_values[0].vt, VT_I4)
			<< "DetectionAlgorithm: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_ARRAY | VT_BSTR)
			<< "DetectionStrings: expected VT_ARRAY|VT_BSTR (MOF string[]), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_ARRAY | VT_BSTR)
			<< "DetectionIPv6LocalPrefixes: expected VT_ARRAY|VT_BSTR (MOF string[]), got vt=" << out_param_values[2].vt;

		UINT32 detectionAlgorithm = out_param_values[0].uintVal;
		EXPECT_LE(detectionAlgorithm, 1U)
			<< "DetectionAlgorithm value " << detectionAlgorithm << " not in MOF ValueMap {0,1}";
		std::wcout << " DetectionAlgorithm: " << detectionAlgorithm << std::endl;
	}
}

TEST_F(MEProvTest, getGeneralSettings)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "NetworkInterfaceEnabled", "DigestRealm", "IdleWakeTimeout",
		"HostName", "DomainName", "PingResponseEnabled", "WsmanOnlyMode", "PreferredAddressFamily",
		"DHCPv6ConfigurationTimeout", "SharedFQDN", "HostOSFQDN", "AMTNetworkEnabled",
		"RmcpPingResponseEnabled", "PresenceNotificationInterval", "PrivacyLevel",
		"PowerSource", "ThunderboltDockEnabled", "OemID" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getGeneralSettings", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// Type checks per MOF definition
		EXPECT_EQ(out_param_values[0].vt, VT_BOOL)   // NetworkInterfaceEnabled (boolean)
			<< "NetworkInterfaceEnabled: expected VT_BOOL, got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)   // DigestRealm (string)
			<< "DigestRealm: expected VT_BSTR, got vt=" << out_param_values[1].vt;
		EXPECT_TRUE(out_param_values[2].vt == VT_I4 || out_param_values[2].vt == VT_UI4)  // IdleWakeTimeout (uint32)
			<< "IdleWakeTimeout: expected VT_I4/VT_UI4, got vt=" << out_param_values[2].vt;
		EXPECT_EQ(out_param_values[3].vt, VT_BSTR)   // HostName (string)
			<< "HostName: expected VT_BSTR, got vt=" << out_param_values[3].vt;
		EXPECT_EQ(out_param_values[4].vt, VT_BSTR)   // DomainName (string)
			<< "DomainName: expected VT_BSTR, got vt=" << out_param_values[4].vt;
		EXPECT_EQ(out_param_values[5].vt, VT_BOOL)   // PingResponseEnabled (boolean)
			<< "PingResponseEnabled: expected VT_BOOL, got vt=" << out_param_values[5].vt;
		EXPECT_EQ(out_param_values[6].vt, VT_BOOL)   // WsmanOnlyMode (boolean)
			<< "WsmanOnlyMode: expected VT_BOOL, got vt=" << out_param_values[6].vt;
		EXPECT_TRUE(out_param_values[7].vt == VT_I4 || out_param_values[7].vt == VT_UI4)  // PreferredAddressFamily (uint32)
			<< "PreferredAddressFamily: expected VT_I4/VT_UI4, got vt=" << out_param_values[7].vt;
		EXPECT_EQ(out_param_values[8].vt, VT_I4)     // DHCPv6ConfigurationTimeout (uint16, widened)
			<< "DHCPv6ConfigurationTimeout: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[8].vt;
		EXPECT_EQ(out_param_values[9].vt, VT_BOOL)   // SharedFQDN (boolean)
			<< "SharedFQDN: expected VT_BOOL, got vt=" << out_param_values[9].vt;
		EXPECT_EQ(out_param_values[10].vt, VT_BSTR)  // HostOSFQDN (string)
			<< "HostOSFQDN: expected VT_BSTR, got vt=" << out_param_values[10].vt;
		EXPECT_TRUE(out_param_values[11].vt == VT_I4 || out_param_values[11].vt == VT_UI4)  // AMTNetworkEnabled (uint32)
			<< "AMTNetworkEnabled: expected VT_I4/VT_UI4, got vt=" << out_param_values[11].vt;
		EXPECT_EQ(out_param_values[12].vt, VT_BOOL)  // RmcpPingResponseEnabled (boolean)
			<< "RmcpPingResponseEnabled: expected VT_BOOL, got vt=" << out_param_values[12].vt;
		EXPECT_TRUE(out_param_values[13].vt == VT_I4 || out_param_values[13].vt == VT_UI4)  // PresenceNotificationInterval (uint32)
			<< "PresenceNotificationInterval: expected VT_I4/VT_UI4, got vt=" << out_param_values[13].vt;
		EXPECT_TRUE(out_param_values[14].vt == VT_I4 || out_param_values[14].vt == VT_UI4)  // PrivacyLevel (uint32)
			<< "PrivacyLevel: expected VT_I4/VT_UI4, got vt=" << out_param_values[14].vt;
		EXPECT_TRUE(out_param_values[15].vt == VT_I4 || out_param_values[15].vt == VT_UI4)  // PowerSource (uint32)
			<< "PowerSource: expected VT_I4/VT_UI4, got vt=" << out_param_values[15].vt;
		EXPECT_TRUE(out_param_values[16].vt == VT_I4 || out_param_values[16].vt == VT_UI4)  // ThunderboltDockEnabled (uint32)
			<< "ThunderboltDockEnabled: expected VT_I4/VT_UI4, got vt=" << out_param_values[16].vt;
		EXPECT_EQ(out_param_values[17].vt, VT_I4)    // OemID (uint16, widened)
			<< "OemID: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[17].vt;

		// Value range checks for fields with ValueMaps
		EXPECT_LE(out_param_values[7].uintVal, 2U)   // PreferredAddressFamily: {0=IPv4, 1=IPv6, 2=Reserved}
			<< "PreferredAddressFamily not in MOF ValueMap {0,1,2}";
		EXPECT_LE(out_param_values[11].uintVal, 2U)  // AMTNetworkEnabled: {0=Disabled, 1=Enabled, 2=Reserved}
			<< "AMTNetworkEnabled not in MOF ValueMap {0,1,2}";
		EXPECT_LE(out_param_values[14].uintVal, 3U)  // PrivacyLevel: {0=Default, 1=Enhanced, 2=Extreme, 3=Reserved}
			<< "PrivacyLevel not in MOF ValueMap {0,1,2,3}";
		EXPECT_LE(out_param_values[15].uintVal, 2U)  // PowerSource: {0=AC, 1=DC, 2=Reserved}
			<< "PowerSource not in MOF ValueMap {0,1,2}";
		EXPECT_LE(out_param_values[16].uintVal, 1U)  // ThunderboltDockEnabled: {0=Disabled, 1=Enabled}
			<< "ThunderboltDockEnabled not in MOF ValueMap {0,1}";

		std::wcout << " NetworkInterfaceEnabled: " << out_param_values[0].boolVal << std::endl;
		std::wcout << " DigestRealm: " << out_param_values[1].bstrVal << std::endl;
		std::wcout << " HostName: " << out_param_values[3].bstrVal << std::endl;
	}
}

TEST_F(MEProvTest, getAMTConfiguration)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "DhcpDNSSuffix", "TrustedDNSSuffix", "ZeroTouchConfigurationEnabled",
		"ProvisioningMode" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getAMTConfiguration", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)   // DhcpDNSSuffix (string)
			<< "DhcpDNSSuffix: expected VT_BSTR, got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)   // TrustedDNSSuffix (string)
			<< "TrustedDNSSuffix: expected VT_BSTR, got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_BOOL)   // ZeroTouchConfigurationEnabled (boolean)
			<< "ZeroTouchConfigurationEnabled: expected VT_BOOL, got vt=" << out_param_values[2].vt;
		EXPECT_TRUE(out_param_values[3].vt == VT_I4 || out_param_values[3].vt == VT_UI1)  // ProvisioningMode (uint8)
			<< "ProvisioningMode: expected VT_I4/VT_UI1 (MOF uint8), got vt=" << out_param_values[3].vt;

		UINT32 provisioningMode  = out_param_values[3].uintVal;

		// ProvisioningMode: ValueMap { "1"=AdminControlMode, "4"=ClientControlMode }
		EXPECT_TRUE(provisioningMode == 1 || provisioningMode == 4)
			<< "ProvisioningMode value " << provisioningMode << " not in MOF ValueMap {1,4}";

		std::wcout << " DhcpDNSSuffix: " << out_param_values[0].bstrVal << std::endl;
		std::wcout << " TrustedDNSSuffix: " << out_param_values[1].bstrVal << std::endl;
		std::wcout << " ProvisioningMode: " << provisioningMode << std::endl;
	}
}

TEST_F(MEProvTest, getWiFiPortConfiguration)
{
	bool wifi_present = getWiFiPresent();
	std::wcout << " WiFi present (AMT provider): " << (wifi_present ? L"Yes" : L"No") << std::endl;

	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "LastConnectedSsidUnderMeControl", "UEFIWiFiProfileShareEnabled",
		"LocalProfileSynchronizationEnabled" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getWiFiPortConfiguration", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		std::wcout << " getWiFiPortConfiguration: method not available (MOF not registered)" << std::endl;
		return;
	}
	if (!wifi_present)
	{
		EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_WIFI_NOT_AVAIL }));
		return;
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)   // LastConnectedSsidUnderMeControl (string)
			<< "LastConnectedSsidUnderMeControl: expected VT_BSTR, got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BOOL)   // UEFIWiFiProfileShareEnabled (boolean)
			<< "UEFIWiFiProfileShareEnabled: expected VT_BOOL, got vt=" << out_param_values[1].vt;
		EXPECT_TRUE(out_param_values[2].vt == VT_I4 || out_param_values[2].vt == VT_UI4)  // LocalProfileSynchronizationEnabled (uint32)
			<< "LocalProfileSynchronizationEnabled: expected VT_I4/VT_UI4, got vt=" << out_param_values[2].vt;

		std::wcout << " LastConnectedSsidUnderMeControl: " << out_param_values[0].bstrVal << std::endl;
		std::wcout << " UEFIWiFiProfileShareEnabled: " << out_param_values[1].boolVal << std::endl;
		std::wcout << " LocalProfileSynchronizationEnabled: " << out_param_values[2].uintVal << std::endl;

		// LocalProfileSynchronizationEnabled: ValueMap { "0"=Disabled, "1"=Enabled(User/IT), "2"=Enabled(IT only), "3"=Enabled(User only) }
		EXPECT_LE(out_param_values[2].uintVal, 3U)
			<< "LocalProfileSynchronizationEnabled not in MOF ValueMap {0,1,2,3}";
	}
}

TEST_F(MEProvTest, getWiFiEndpointState)
{
	bool wifi_present = getWiFiPresent();
	std::wcout << " WiFi present (AMT provider): " << (wifi_present ? L"Yes" : L"No") << std::endl;

	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "MACAddress", "HealthState", "EnabledState" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getWiFiEndpointState", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	if (!wifi_present)
	{
		EXPECT_PRED2(isReturnValueValidEx, return_val, std::vector<UINT32>({ AMT_STATUS_WIFI_NOT_AVAIL }));
		return;
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		EXPECT_EQ(out_param_values[0].vt, VT_BSTR)   // MACAddress (string)
			<< "MACAddress: expected VT_BSTR (MOF string), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_I4)     // HealthState (uint16, widened)
			<< "HealthState: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_I4)     // EnabledState (uint16, widened)
			<< "EnabledState: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[2].vt;

		std::wcout << " MACAddress: " << out_param_values[0].bstrVal << std::endl;
		std::wcout << " HealthState: " << out_param_values[1].uintVal << std::endl;
		std::wcout << " EnabledState: " << out_param_values[2].uintVal << std::endl;

		EXPECT_TRUE(out_param_values[0].bstrVal != nullptr && out_param_values[0].bstrVal[0] != L'\0')
			<< "WiFi hardware present but AMT MACAddress is empty";
		
		bool wifi_endpoint_found = out_param_values[0].bstrVal != nullptr && out_param_values[0].bstrVal[0] != L'\0';
		if (wifi_endpoint_found)
		{
			UINT32 healthState  = out_param_values[1].uintVal;
			UINT32 enabledState = out_param_values[2].uintVal;
			// HealthState: sparse ValueMap {0,5,10,15,20,25,30}
			EXPECT_LE(healthState, 30U) << "HealthState out of CIM range [0,30]";
			// EnabledState: sparse ValueMap {2=Enabled, 3=Disabled, 6=EnabledButOffline}
			EXPECT_TRUE(enabledState == 2 || enabledState == 3 || enabledState == 6)
				<< "EnabledState value " << enabledState << " not in MOF ValueMap {2,3,6}";
		}
	}
}

TEST_F(MEProvTest, getTimeSynchronizationConfig)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "AMTTime", "LocalTimeSyncEnabled", "TimeSource" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getTimeSynchronizationConfig", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// Verify VARIANT types match MOF: all three are uint32 -> VT_I4 or VT_UI4
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "AMTTime: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "LocalTimeSyncEnabled: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_TRUE(out_param_values[2].vt == VT_I4 || out_param_values[2].vt == VT_UI4)
			<< "TimeSource: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[2].vt;

		UINT32 amtTime             = out_param_values[0].uintVal;
		UINT32 localTimeSyncEnabled = out_param_values[1].uintVal;
		UINT32 timeSource          = out_param_values[2].uintVal;

		std::wcout << " AMTTime:             " << amtTime             << std::endl;
		std::wcout << " LocalTimeSyncEnabled: " << localTimeSyncEnabled << std::endl;
		std::wcout << " TimeSource:           " << timeSource          << std::endl;

		// LocalTimeSyncEnabled: ValueMap { "0"=DEFAULT_TRUE, "1"=CONFIGURED_TRUE, "2"=FALSE }
		EXPECT_LE(localTimeSyncEnabled, 2U)
			<< "LocalTimeSyncEnabled value " << localTimeSyncEnabled << " not in MOF ValueMap {0,1,2}";

		// TimeSource: ValueMap { "0"=BIOS_RTC, "1"=CONFIGURED }
		EXPECT_LE(timeSource, 1U)
			<< "TimeSource value " << timeSource << " not in MOF ValueMap {0,1}";
	}
}

TEST_F(MEProvTest, getOptInConfiguration)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "OptInCodeTimeout", "OptInRequired", "OptInState", "OptInDisplayTimeout" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getOptInConfiguration", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	if (return_val == 0)
	{
		// Verify VARIANT types match MOF: uint32 -> VT_I4/VT_UI4; WMI widens uint8/uint16 to VT_I4
		EXPECT_TRUE(out_param_values[0].vt == VT_I4 || out_param_values[0].vt == VT_UI4)
			<< "OptInCodeTimeout: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[0].vt;
		EXPECT_TRUE(out_param_values[1].vt == VT_I4 || out_param_values[1].vt == VT_UI4)
			<< "OptInRequired: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << out_param_values[1].vt;
		EXPECT_TRUE(out_param_values[2].vt == VT_I4 || out_param_values[2].vt == VT_UI1)
			<< "OptInState: expected VT_I4/VT_UI1 (MOF uint8), got vt=" << out_param_values[2].vt;
		EXPECT_TRUE(out_param_values[3].vt == VT_I4 || out_param_values[3].vt == VT_UI2)
			<< "OptInDisplayTimeout: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << out_param_values[3].vt;

		UINT32 optInCodeTimeout    = out_param_values[0].uintVal;
		UINT32 optInRequired       = out_param_values[1].uintVal;
		UINT32 optInState          = out_param_values[2].uintVal;
		UINT32 optInDisplayTimeout = out_param_values[3].uintVal;

		std::wcout << " OptInCodeTimeout:    " << optInCodeTimeout    << std::endl;
		std::wcout << " OptInRequired:       " << optInRequired       << std::endl;
		std::wcout << " OptInState:          " << optInState          << std::endl;
		std::wcout << " OptInDisplayTimeout: " << optInDisplayTimeout << std::endl;

		// OptInRequired: ValueMap { "0"=None, "1"=KVM, "4294967295"=All }
		EXPECT_TRUE(optInRequired == 0 || optInRequired == 1 || optInRequired == 4294967295U)
			<< "OptInRequired value " << optInRequired << " not in MOF ValueMap {0,1,4294967295}";

		// OptInState: ValueMap { "0"..="4" }
		EXPECT_LE(optInState, 4U)
			<< "OptInState value " << optInState << " not in MOF ValueMap {0..4}";
	}
}

TEST_F(MEProvTest, AMT_AuditLogRecords)
{
	// Flow:
	// 1) Enumerate AMT_AuditLogRecords instances from ROOT\INTEL_ME.
	// 2) Validate AuditLogRecord VARIANT type against MOF expectations.
	// 3) Print record summary/hex payload for manual inspection.
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "AMT_AuditLogRecords";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			items_count++;
			VARIANT vtProp;
			if (SUCCEEDED(pclsObj->Get(L"AuditLogRecord", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, (VARTYPE)(VT_ARRAY | VT_UI1)) << "AuditLogRecord: expected VT_ARRAY|VT_UI1 (MOF uint8[]), got vt=" << vtProp.vt;
				if (vtProp.vt == (VT_ARRAY | VT_UI1))
				{
					LONG lBound = 0, uBound = -1;
					SafeArrayGetLBound(vtProp.parray, 1, &lBound);
					SafeArrayGetUBound(vtProp.parray, 1, &uBound);
					LONG byteCount = uBound - lBound + 1;
					std::wcout << "  AuditLogRecord (" << byteCount << " bytes): ";
					BYTE* pData = nullptr;
					SafeArrayAccessData(vtProp.parray, reinterpret_cast<void**>(&pData));
					for (LONG b = 0; b < byteCount; ++b)
						std::wcout << std::hex << std::setw(2) << std::setfill(L'0') << (UINT32)pData[b];
					SafeArrayUnaccessData(vtProp.parray);
					std::wcout << std::dec << std::endl;
				}
				VariantClear(&vtProp);
			}
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	std::wcout << " AMT_AuditLogRecords: " << items_count << " record(s)" << std::endl;
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, AMT_RemoteAccessPolicyRule)
{
	// Flow:
	// 1) Enumerate AMT_RemoteAccessPolicyRule instances.
	// 2) Validate key field types and ValueMap-constrained values.
	// 3) Print rule details and tolerate empty result when CIRA is not configured.
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "AMT_RemoteAccessPolicyRule";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			items_count++;
			VARIANT vtProp;
			if (SUCCEEDED(pclsObj->Get(L"PolicyRuleName", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "PolicyRuleName: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  PolicyRuleName:   " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"Trigger", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "Trigger: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					// ValueMap { "0"=User Initiated, "1"=Alert, "2"=Periodic, "3"=Home Provisioning }
					EXPECT_LE(val, 3U) << "Trigger not in MOF ValueMap {0,1,2,3}";
					std::wcout << "  Trigger:          " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"TunnelLifeTime", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "TunnelLifeTime: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					std::wcout << "  TunnelLifeTime:   " << vtProp.uintVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"ExtendedData", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, (VARTYPE)(VT_ARRAY | VT_UI1)) << "ExtendedData: expected VT_ARRAY|VT_UI1 (MOF uint8[]), got vt=" << vtProp.vt;
				if (vtProp.vt == (VT_ARRAY | VT_UI1))
				{
					LONG lBound = 0, uBound = -1;
					SafeArrayGetLBound(vtProp.parray, 1, &lBound);
					SafeArrayGetUBound(vtProp.parray, 1, &uBound);
					std::wcout << "  ExtendedData (" << (uBound - lBound + 1) << " bytes)" << std::endl;
				}
				VariantClear(&vtProp);
			}
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	std::wcout << " AMT_RemoteAccessPolicyRule: " << items_count << " rule(s)" << std::endl;
	if (items_count == 0)
		std::wcout << " (No CIRA policies configured on this system - this is normal if Remote Access is not set up)" << std::endl;
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, AMT_WiFiProfiles)
{
	// Flow:
	// 1) Enumerate AMT_WiFiProfiles instances.
	// 2) Validate schema types and enum-backed fields (auth/encryption methods).
	// 3) Print profile details and allow zero profiles on systems without AMT Wi-Fi setup.
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "AMT_WiFiProfiles";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			VARIANT vtProp;
			if (SUCCEEDED(pclsObj->Get(L"ProfileName", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR)
					<< "ProfileName: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  ProfileName:          " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"SSID", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR)
					<< "SSID: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  SSID:                 " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"Priority", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI1)
					<< "Priority: expected VT_I4/VT_UI1 (MOF uint8), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI1)
				{
					UINT32 val = (vtProp.vt == VT_UI1) ? (UINT32)vtProp.bVal : vtProp.uintVal;
					std::wcout << "  Priority:             " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"EncryptionMethod", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "EncryptionMethod: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					// ValueMap {"1"=Other,"2"=WEP,"3"=TKIP,"4"=CCMP128,"5"=None,"32768"=GCMP256}
					EXPECT_TRUE(val == 1 || val == 2 || val == 3 || val == 4 || val == 5 || val == 32768)
						<< "EncryptionMethod value " << val << " not in MOF ValueMap {1,2,3,4,5,32768}";
					std::wcout << "  EncryptionMethod:     " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"AuthenticationMethod", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "AuthenticationMethod: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					// ValueMap {"1"=Other,...,"7"=WPA2 802.1x,"32768"=WPA3 SAE,"32769"=WPA3 OWE}
					EXPECT_TRUE(val == 1 || val == 2 || val == 3 || val == 4 || val == 5 || val == 6 || val == 7 || val == 32768 || val == 32769)
						<< "AuthenticationMethod value " << val << " not in MOF ValueMap {1..7,32768,32769}";
					std::wcout << "  AuthenticationMethod: " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			items_count++;
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	std::wcout << " AMT_WiFiProfiles: " << items_count << " profile(s)" << std::endl;
	if (items_count == 0)
		std::wcout << " (No WiFi profiles configured on this system - this is normal if WiFi is not set up in AMT)" << std::endl;
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, IPS_HTTPProxyAccessPoint)
{
	// Flow:
	// 1) Enumerate IPS_HTTPProxyAccessPoint instances.
	// 2) Validate projected field types from the provider.
	// 3) Print proxy settings and allow empty results when proxy is not configured.
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "IPS_HTTPProxyAccessPoint";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			VARIANT vtProp;
			if (SUCCEEDED(pclsObj->Get(L"AccessInfo", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "AccessInfo: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  AccessInfo:       " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"InfoFormat", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "InfoFormat: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					std::wcout << "  InfoFormat:       " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"Port", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "Port: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					std::wcout << "  Port:             " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"NetworkDnsSuffix", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "NetworkDnsSuffix: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_BSTR)
					std::wcout << "  NetworkDnsSuffix: " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"Priority", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					<< "Priority: expected VT_I4/VT_UI4 (MOF uint32), got vt=" << vtProp.vt;
			if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI4)
					std::wcout << "  Priority:         " << vtProp.uintVal << std::endl;
				VariantClear(&vtProp);
			}
			items_count++;
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	std::wcout << " IPS_HTTPProxyAccessPoint: " << items_count << " proxy(s)" << std::endl;
	if (items_count == 0)
		std::wcout << " (No HTTP proxy configured in AMT - this is normal if proxy is not set up)" << std::endl;
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, CIM_WiFiPort)
{
	// Flow:
	// 1) Enumerate CIM_WiFiPort instances.
	// 2) Validate enabled-state ValueMap and permanent-address type.
	// 3) Print discovered port state for visibility in test logs.
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;
	IWbemClassObject* pclsObj = NULL;
	ULONG uReturn = 0;
	int items_count = 0;
	std::string objectName = "CIM_WiFiPort";
	queryForObject(pEnumerator, objectName);
	while (pEnumerator)
	{
		hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (FAILED(hres))
		{
			std::cerr << "pEnumerator->Next failed. Error code = 0x"
				<< std::hex << hres << std::endl;
			releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
			FAIL();
		}
		if (0 == uReturn)
		{
			break;
		}
		else
		{
			VARIANT vtProp;
			if (SUCCEEDED(pclsObj->Get(L"EnabledState", 0, &vtProp, 0, 0)))
			{
				EXPECT_TRUE(vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
					<< "EnabledState: expected VT_I4/VT_UI2 (MOF uint16), got vt=" << vtProp.vt;
				if (vtProp.vt == VT_I4 || vtProp.vt == VT_UI2)
				{
					UINT32 val = (vtProp.vt == VT_UI2) ? (UINT32)vtProp.uiVal : vtProp.uintVal;
					// ValueMap { "3"=WiFi disabled, "32768"=enabled S0, "32769"=enabled S0+Sx/AC }
					EXPECT_TRUE(val == 3 || val == 32768 || val == 32769)
						<< "EnabledState value " << val << " not in MOF ValueMap {3,32768,32769}";
					std::wcout << "  EnabledState:      " << val << std::endl;
				}
				VariantClear(&vtProp);
			}
			if (SUCCEEDED(pclsObj->Get(L"PermanentAddress", 0, &vtProp, 0, 0)))
			{
				EXPECT_EQ(vtProp.vt, VT_BSTR) << "PermanentAddress: expected VT_BSTR (MOF string), got vt=" << vtProp.vt;
			if (vtProp.vt == VT_BSTR)
					std::wcout << "  PermanentAddress:  " << vtProp.bstrVal << std::endl;
				VariantClear(&vtProp);
			}
			items_count++;
		}
		if (pclsObj)
		{
			pclsObj->Release();
			pclsObj = NULL;
		}
	}
	std::wcout << " CIM_WiFiPort: " << items_count << " port(s)" << std::endl;
	releaseArgs(std::vector<IUnknown*> {pEnumerator, pclsObj});
}

TEST_F(MEProvTest, getManagementPresenceRemoteSAP)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "InfoFormat", "AccessInfo", "Port", "CN" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getManagementPresenceRemoteSAP", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_PRED1(isReturnValueValid, return_val);
	if (return_val == 0)
	{
		ASSERT_EQ(out_param_values.size(), out_param_names.size());
		// InfoFormat: MOF uint16, widened to VT_I4; sparse ValueMap {3=IPv4, 4=IPv6, 201=FQDN}
		EXPECT_EQ(out_param_values[0].vt, VT_I4)
			<< "InfoFormat: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[0].vt;
		EXPECT_EQ(out_param_values[1].vt, VT_BSTR)  // AccessInfo (string)
			<< "AccessInfo: expected VT_BSTR, got vt=" << out_param_values[1].vt;
		EXPECT_EQ(out_param_values[2].vt, VT_I4)    // Port (uint16, widened)
			<< "Port: expected VT_I4 (MOF uint16, widened), got vt=" << out_param_values[2].vt;
		EXPECT_EQ(out_param_values[3].vt, VT_BSTR)  // CN (string)
			<< "CN: expected VT_BSTR, got vt=" << out_param_values[3].vt;

		UINT32 infoFormat = (out_param_values[0]).uintVal;
		std::wcout << " InfoFormat: " << infoFormat << std::endl;
		BSTR accessInfo = (out_param_values[1]).bstrVal;
		std::wcout << " AccessInfo: " << accessInfo << std::endl;
		UINT32 port = (out_param_values[2]).uintVal;
		std::wcout << " Port:       " << port << std::endl;
		BSTR cn = (out_param_values[3]).bstrVal;
		std::wcout << " CN:         " << cn << std::endl;
		// Only validate InfoFormat when a server is actually configured
		if (port > 0 || (accessInfo && accessInfo[0] != L'\0'))
		{
			EXPECT_TRUE(infoFormat == 3 || infoFormat == 4 || infoFormat == 201)
				<< "InfoFormat value " << infoFormat << " not in MOF ValueMap {3,4,201}";
		}
		if (port == 0 && (!accessInfo || accessInfo[0] == L'\0'))
			std::wcout << " (No MPS server configured in AMT - this is normal if CIRA is not set up)" << std::endl;
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
