/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */

#include <iostream>

//#include <windows.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <gtest/gtest.h>

#pragma comment(lib, "wbemuuid.lib")

class MEProvTest : public ::testing::Test {
protected:
	IWbemLocator *pLoc;
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


	template<class T> bool runCommandOneReturn(const wchar_t *method_name, const wchar_t *class_name, const wchar_t *arg_name,
		int &return_value, T &value)
	{
		// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--calling-a-provider-method
		HRESULT hres;
		BSTR MethodName = SysAllocString(method_name);
		BSTR ClassName = SysAllocString(class_name);

		IWbemClassObject* pClass = NULL;
		hres = pSvc->GetObject(ClassName, 0, NULL, &pClass, NULL);

		IWbemClassObject* pOutParams = NULL;
		hres = pSvc->ExecMethod(ClassName, MethodName, 0,
			NULL, NULL, &pOutParams, NULL);
		if (FAILED(hres))
		{
			std::cerr << "Could not execute method. Error code = 0x"
				<< std::hex << hres << std::endl;
			SysFreeString(ClassName);
			SysFreeString(MethodName);
			pClass->Release();
			pOutParams->Release();

			return false;
		}
		VARIANT varReturnValue;
		hres = pOutParams->Get(_bstr_t(L"ReturnValue"), 0,
			&varReturnValue, NULL, 0);
		return_value = varReturnValue.intVal;
		VariantClear(&varReturnValue);

		VARIANT varEnabled;
		hres = pOutParams->Get(_bstr_t(arg_name), 0,
			&varEnabled, NULL, 0);
		value = static_cast<T>(varEnabled.llVal);
		VariantClear(&varEnabled);

		SysFreeString(ClassName);
		SysFreeString(MethodName);
		pClass->Release();
		pOutParams->Release();

		return true;
	}
};

TEST_F(MEProvTest, GetFWVersion)
{
	// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--getting-wmi-data-from-the-local-computer
	IEnumWbemClassObject* pEnumerator = NULL;
	HRESULT hres;

	hres = pSvc->ExecQuery(
		bstr_t("WQL"),
		bstr_t("SELECT * FROM ME_System"),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
		NULL,
		&pEnumerator);

	if (FAILED(hres))
	{
		std::cerr << "Query for operating system name failed. Error code = 0x"
			<< std::hex << hres << std::endl;
		FAIL();
	}

	IWbemClassObject *pclsObj = NULL;
	ULONG uReturn = 0;

	while (pEnumerator)
	{
		HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
		if (0 == uReturn)
		{
			break;
		}

		VARIANT vtProp;

		// Get the value of the property
		hr = pclsObj->Get(L"FWVersion", 0, &vtProp, 0, 0);
		std::wcout << " FWVersion: " << vtProp.bstrVal << std::endl;
		ASSERT_GE(wcslen(vtProp.bstrVal), 9U);
		ASSERT_LE(wcslen(vtProp.bstrVal), 15U);
		VariantClear(&vtProp);

		pclsObj->Release();
	}
	pEnumerator->Release();
}

TEST_F(MEProvTest, isWebUIEnabled)
{
	SHORT enabled = 0;
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"isWebUIEnabled", L"AMT_Service", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	std::wcout << " enabled: " << enabled << std::endl;
}

TEST_F(MEProvTest, GetProvisioningState)
{
	SHORT state = 0;
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"GetProvisioningState", L"OOB_Service", L"state", return_val, state);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(state, 0);
	ASSERT_LE(state, 3);
	std::wcout << " state: " << state << std::endl;
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
