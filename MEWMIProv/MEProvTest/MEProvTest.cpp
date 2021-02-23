/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2021 Intel Corporation
 */
#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>
#include <gtest/gtest.h>
#include <atlsafe.h>
#include <comutil.h>

static const UINT32 AMT_STATUS_INVALID_AMT_MODE = 0x80873003;
static const UINT32 AMT_STATUS_NOT_PERMITTED = 0x80873010;
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
		UINT32 &return_value, T &value)
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
			hres = pClass->GetMethod(MethodName, 0,&pInParamsDefinition, NULL);
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

		for(std::vector<std::string>::const_iterator it = out_param_names.begin(); it != out_param_names.end(); ++it)
		{
			VARIANT varEnabled;
			hres = pOutParams->Get(_bstr_t((*it).c_str()), 0, &varEnabled, NULL, 0);
			if (FAILED(hres))
			{
				std::cerr <<"failed to get val: "<< (*it).c_str()<<". Error code = 0x"<< std::hex << hres << std::endl;
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

	IWbemClassObject* pclsObj = NULL;
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
	ASSERT_EQ(return_val, 0);
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
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(state, 0);
	ASSERT_LE(state, 3);
	std::wcout << " state: " << state << std::endl;
}

TEST_F(MEProvTest, GetAMTProvisioningMode)
{
	uint8_t mode;
	UINT32 return_val;
	bool ret;

	ret = runCommandOneReturn(L"GetAMTProvisioningMode", L"OOB_Service", L"mode", return_val, mode);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(mode, 0);
	ASSERT_LE(mode, 3);
	std::wcout << " mode: " << mode << std::endl;
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
	ASSERT_EQ(return_val, 0);
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
	ASSERT_EQ(return_val, 0);
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
	ASSERT_EQ(return_val, 0);
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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	FQDN = (out_param_values[0]).bstrVal;
	std::wcout << " FQDN: " << FQDN << std::endl;
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
	EXPECT_TRUE(return_val == 0 || return_val == AMT_STATUS_INVALID_AMT_MODE);
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
	ASSERT_EQ(return_val, 0);
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
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(ReasonCode, 0U);
	ASSERT_LE(ReasonCode, 3U);
	std::wcout << " ReasonCode: " << ReasonCode << std::endl;
}

TEST_F(MEProvTest, getCurrentPowerPolicy)
{
	BSTR PowerPolicy;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "PowerPolicy"};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getCurrentPowerPolicy", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	PowerPolicy = (out_param_values[0]).bstrVal;
	std::wcout << " PowerPolicy: " << PowerPolicy << std::endl;
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
	EXPECT_TRUE(return_val == 0 || return_val == AMT_STATUS_INVALID_AMT_MODE);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	OEMPlatformIDType = (out_param_values[0]).uintVal;
	std::wcout << " OEMPlatformIDType: " << OEMPlatformIDType << std::endl;
	OEMPlatformID = (out_param_values[1]).bstrVal;
	std::wcout << " OEMPlatformID: " << OEMPlatformID << std::endl;
	CSMEPlatformID = (out_param_values[2]).bstrVal;
	std::wcout << " CSMEPlatformID: " << CSMEPlatformID << std::endl;
}

TEST_F(MEProvTest, DISABLED_getFwUpdateOverrideParams)
{
	UINT32 Counter;
	UINT32 OverrideQualifier;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "Counter","OverrideQualifier" };
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params ={};
	ret = runCommandMultipleArguments(L"getFwUpdateOverrideParams", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	Counter = (out_param_values[0]).uintVal;
	ASSERT_GE(Counter, 0U);
	ASSERT_LE(Counter, 255U);
	std::wcout << " Counter: " << Counter << std::endl;
	OverrideQualifier = (out_param_values[1]).uintVal;
	ASSERT_GE(OverrideQualifier, 0U);
	ASSERT_LE(OverrideQualifier, 2U);
	std::wcout << " OverrideQualifier: " << OverrideQualifier << std::endl;
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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	CComSafeArray<BSTR> Capabilities(out_param_values[0].parray);
	std::wcout << " Capabilities: " << std::endl;
	for (LONG i = Capabilities.GetLowerBound(); i <= Capabilities.GetUpperBound(); i++)
	{
		std::wcout << _com_util::ConvertBSTRToString(Capabilities.GetAt(i)) << std::endl;
	}
	CComSafeArray<BSTR> EnabledCapabilities(out_param_values[0].parray);
	std::wcout << " EnabledCapabilities: " << std::endl;
	for (LONG i = EnabledCapabilities.GetLowerBound(); i <= EnabledCapabilities.GetUpperBound(); i++)
	{
		std::wcout << _com_util::ConvertBSTRToString(EnabledCapabilities.GetAt(i)) << std::endl;
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
	std::vector<std::string> out_param_names = { "NetworkConStatus","ConnectionTrigger", "MPshostName","RemoteAccessConStatus"};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"GetRemoteAccessConnectionStatus", L"OOB_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
	NetworkConStatus = (out_param_values[0]).uintVal;
	ASSERT_GE(NetworkConStatus, 0U);
	ASSERT_LE(NetworkConStatus, 3U);
	std::wcout << " NetworkConStatus: " << NetworkConStatus << std::endl;

	ConnectionTrigger = (out_param_values[1]).uintVal;
	ASSERT_GE(ConnectionTrigger, 0U);
	ASSERT_LE(ConnectionTrigger, 3U);
	std::wcout << " ConnectionTrigger: " << ConnectionTrigger << std::endl;

	MPshostName = (out_param_values[2]).bstrVal;
	std::wcout << " MPshostName: " << MPshostName << std::endl;

	RemoteAccessConStatus = (out_param_values[3]).uintVal;
	ASSERT_GE(RemoteAccessConStatus, 0U);
	ASSERT_LE(RemoteAccessConStatus, 2U);
	std::wcout << " RemoteAccessConStatus: " << RemoteAccessConStatus << std::endl;
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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	Address = (out_param_values[0]).bstrVal;
	std::wcout << " Address: " << Address << std::endl;

	ConfigServerListeningPort = (out_param_values[1]).uintVal;
	ASSERT_NE(ConfigServerListeningPort, 0);
	std::wcout << " ConfigServerListeningPort: " << ConfigServerListeningPort << std::endl;

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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	Username = (out_param_values[0]).bstrVal;
	std::wcout << " Username: " << Username << std::endl;

	Password = (out_param_values[1]).bstrVal;
	std::wcout << " Password: " << Password << std::endl;

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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	PKIDNSSuffix = (out_param_values[0]).bstrVal;
	std::wcout << " PKIDNSSuffix: " << PKIDNSSuffix << std::endl;

	ConfigServerFQDN = (out_param_values[1]).bstrVal;
	std::wcout << " ConfigServerFQDN: " << ConfigServerFQDN << std::endl;

}

//*********multiple out param AMT service************
TEST_F(MEProvTest, getKVMState)
{
	UINT32 hardEnabled;
	UINT32 softEnabled;
	bool active;
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = { "hardEnabled","softEnabled" ,"active"};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params = {};
	ret = runCommandMultipleArguments(L"getKVMState", L"AMT_Service", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	hardEnabled = (out_param_values[0]).uintVal;
	ASSERT_GE(hardEnabled, 0U);
	ASSERT_LE(hardEnabled, 2U);
	std::wcout << " hardEnabled: " << hardEnabled << std::endl;

	softEnabled = (out_param_values[1]).uintVal;
	ASSERT_GE(softEnabled, 0U);
	ASSERT_LE(softEnabled, 2U);
	std::wcout << " softEnabled: " << softEnabled << std::endl;

	active = (out_param_values[2]).boolVal;
	std::wcout << " active: " << active << std::endl;
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
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());

	hardEnabled = (out_param_values[0]).uintVal;
	ASSERT_GE(hardEnabled, 0U);
	ASSERT_LE(hardEnabled, 2U);
	std::wcout << " hardEnabled: " << hardEnabled << std::endl;

	softEnabled = (out_param_values[1]).uintVal;
	ASSERT_GE(softEnabled, 0U);
	ASSERT_LE(softEnabled, 2U);
	std::wcout << " softEnabled: " << softEnabled << std::endl;

	active = (out_param_values[2]).boolVal;
	std::wcout << " active: " << active << std::endl;
}

//*********no out param ME_System************
TEST_F(MEProvTest, setUniquePlatformIDFeatureState)
{
	UINT32 return_val;
	bool ret;
	std::vector<std::string> out_param_names = {};
	std::vector<_variant_t> out_param_values = {};
	std::vector<InputParam> input_params;
	VARIANT state;
	VariantInit(&state);
	state.vt = VT_BOOL;
	state.boolVal = false;
	input_params.push_back(InputParam(L"state", CIM_EMPTY, state));
	ret = runCommandMultipleArguments(L"setUniquePlatformIDFeatureState", L"ME_System", return_val, out_param_names, out_param_values, input_params);
	if (!ret)
	{
		FAIL();
	}
	EXPECT_TRUE(return_val == 0 || return_val == AMT_STATUS_INVALID_AMT_MODE);
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
	EXPECT_TRUE(return_val == 0 || return_val == AMT_STATUS_NOT_PERMITTED);
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
	EXPECT_TRUE(return_val == 0 || return_val == AMT_STATUS_NOT_PERMITTED);
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
	EXPECT_TRUE(return_val == 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
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
	EXPECT_TRUE(return_val == 0);
	ASSERT_EQ(out_param_values.size(), out_param_names.size());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
