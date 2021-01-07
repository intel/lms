/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */

#include <iostream>

#include <comdef.h>
#include <Wbemidl.h>
#include <gtest/gtest.h>

#pragma comment(lib, "wbemuuid.lib")
class VariantVector
{
public:
	std::vector<VARIANT> vector;
	auto size()
	{
		return vector.size();
	}
	auto push_back(VARIANT val)
	{
		vector.push_back(val);
	}
	VARIANT operator [] (int idx) const
	{
		return vector[idx];
	}
	~VariantVector()
	{
		for (int i = 0; i < vector.size(); ++i)
			VariantClear(&vector[i]);
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
		int &return_value, T &value)
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
	
	bool runCommandMultipleArguments(const wchar_t* method_name, const wchar_t* class_name, int& return_value, 
	const std::vector<std::string>& param_names, VariantVector &param_values)
	{
		
		// https://docs.microsoft.com/en-us/windows/win32/wmisdk/example--calling-a-provider-method
		va_list arguments;
		HRESULT hres;
		BSTR MethodName = SysAllocString(method_name);
		BSTR ClassName = SysAllocString(class_name);
		
		IWbemClassObject* pClass = NULL;
		IWbemClassObject* pOutParams = NULL;
		hres = pSvc->GetObject(ClassName, 0, NULL, &pClass, NULL);
		if (FAILED(hres))
		{
			std::cerr << "failed to get class name. Error code = 0x"<< std::hex << hres << std::endl;
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

			std::cerr << "failed to get returnval. Error code = 0x"
				<< std::hex << hres << std::endl;
			goto release;
		}
		return_value = varReturnValue.intVal;
		VariantClear(&varReturnValue);
		
		for(std::vector<std::string>::const_iterator it = param_names.begin(); it != param_names.end(); ++it)
		{
			VARIANT varEnabled;
			hres = pOutParams->Get(_bstr_t((*it).c_str()), 0, &varEnabled, NULL, 0);
			if (FAILED(hres))
			{
				std::cerr <<"failed to get val: "<< (*it).c_str()<<". Error code = 0x"<< std::hex << hres << std::endl;
				goto release;
			}
			param_values.push_back(varEnabled);
		}
		if (param_names.size() != param_values.size())
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

//*********one out param OOB************
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

TEST_F(MEProvTest, GetAMTProvisioningMode)
{
	uint8_t mode;
	int return_val;
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
	int return_val;
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
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"GetActivationTLSMode", L"OOB_Service", L"mode", return_val, mode);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(mode, 0);
	ASSERT_LE(mode, 2);
	std::wcout << " mode: " << mode << std::endl;
}

TEST_F(MEProvTest, isTLSEnabled)
{
	bool enabled;
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"isTLSEnabled", L"OOB_Service", L"enabled", return_val, enabled);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	std::wcout << " enabled: " << enabled << std::endl;
}

//*********one out param ME system************
TEST_F(MEProvTest, DISABLED_getUniquePlatformIDFeatureState)
{
	bool state = false;
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"getUniquePlatformIDFeatureState", L"ME_System", L"state", return_val, state);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	std::wcout << " state: " << state << std::endl;
}

TEST_F(MEProvTest, IsFirmwareUpdateEnabled)
{
	bool enabled = false;
	int return_val;
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
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"getLastMEResetReason", L"ME_System", L"ReasonCode", return_val, ReasonCode);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_GE(ReasonCode, 0);
	ASSERT_LE(ReasonCode, 3);
	std::wcout << " ReasonCode: " << ReasonCode << std::endl;
}
/*
TEST_F(MEProvTest, DISABLED_getCurrentPowerPolicy)//todo write specialization to wsting
{
	std::wstring PowerPolicy;
	int return_val;
	bool ret;

	ret = runCommandOneReturn(L"getCurrentPowerPolicy", L"ME_System", L"PowerPolicy", return_val, PowerPolicy);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	std::wcout << " PowerPolicy: " << PowerPolicy << std::endl;
}
*/

//*********multiple out param ME system************
TEST_F(MEProvTest, DISABLED_getUniquePlatformID)
{
	UINT32 OEMPlatformIDType;
	BSTR OEMPlatformID;
	BSTR CSMEPlatformID;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "OEMPlatformIDType","OEMPlatformID","CSMEPlatformID" };
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"getUniquePlatformID", L"ME_System", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());
	OEMPlatformIDType = (param_values[0]).uintVal;
	std::wcout << " OEMPlatformIDType: " << OEMPlatformIDType << std::endl;
	OEMPlatformID = (param_values[1]).bstrVal;
	std::wcout << " OEMPlatformID: " << OEMPlatformID << std::endl;
	CSMEPlatformID = (param_values[2]).bstrVal;
	std::wcout << " CSMEPlatformID: " << CSMEPlatformID << std::endl;
}

TEST_F(MEProvTest, DISABLED_getFwUpdateOverrideParams)
{
	UINT32 Counter;
	UINT32 OverrideQualifier;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "Counter","OverrideQualifier" };
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"getFwUpdateOverrideParams", L"ME_System", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());
	Counter = (param_values[0]).uintVal;
	ASSERT_GE(Counter, 0);
	ASSERT_LE(Counter, 255);
	std::wcout << " Counter: " << Counter << std::endl;
	OverrideQualifier = (param_values[1]).uintVal;
	ASSERT_GE(OverrideQualifier, 0);
	ASSERT_LE(OverrideQualifier, 2);
	std::wcout << " OverrideQualifier: " << OverrideQualifier << std::endl;
}

//*********multiple out param OOB************
TEST_F(MEProvTest, GetRemoteAccessConnectionStatus)
{
	//todo ask what to test here
	UINT32 NetworkConStatus;
	UINT32 ConnectionTrigger;
	BSTR MPshostName;
	UINT32 RemoteAccessConStatus;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "NetworkConStatus","ConnectionTrigger", "MPshostName","RemoteAccessConStatus"};
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"GetRemoteAccessConnectionStatus", L"OOB_Service", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());
	NetworkConStatus = (param_values[0]).uintVal;
	ASSERT_GE(NetworkConStatus, 0);
	ASSERT_LE(NetworkConStatus, 3);
	std::wcout << " NetworkConStatus: " << NetworkConStatus << std::endl;

	ConnectionTrigger = (param_values[1]).uintVal;
	ASSERT_GE(ConnectionTrigger, 0);
	ASSERT_LE(ConnectionTrigger, 3);
	std::wcout << " ConnectionTrigger: " << ConnectionTrigger << std::endl;

	MPshostName = (param_values[2]).bstrVal;
	std::wcout << " MPshostName: " << MPshostName << std::endl;

	RemoteAccessConStatus = (param_values[3]).uintVal;
	ASSERT_GE(RemoteAccessConStatus, 0);
	ASSERT_LE(RemoteAccessConStatus, 2);
	std::wcout << " RemoteAccessConStatus: " << RemoteAccessConStatus << std::endl;
}

TEST_F(MEProvTest, GetHelloPacketDestInfo)
{
	BSTR Address;
	UINT16 ConfigServerListeningPort;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "Address","ConfigServerListeningPort" };
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"GetHelloPacketDestInfo", L"OOB_Service", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());

	Address = (param_values[0]).bstrVal;
	std::wcout << " Address: " << Address << std::endl;

	ConfigServerListeningPort = (param_values[1]).uintVal;
	ASSERT_NE(ConfigServerListeningPort, 0);
	std::wcout << " ConfigServerListeningPort: " << ConfigServerListeningPort << std::endl;

}

TEST_F(MEProvTest, GetLocalAdminCredentials)
{
	BSTR Username;
	BSTR Password;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "Username","Password" };
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"GetLocalAdminCredentials", L"OOB_Service", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());

	Username = (param_values[0]).bstrVal;
	std::wcout << " Username: " << Username << std::endl;

	Password = (param_values[1]).bstrVal;
	std::wcout << " Password: " << Password << std::endl;

}

TEST_F(MEProvTest, GetProvisioningInfo)
{
	BSTR PKIDNSSuffix;
	BSTR ConfigServerFQDN;
	int return_val;
	bool ret;
	std::vector<std::string> param_names = { "PKIDNSSuffix","ConfigServerFQDN" };
	VariantVector param_values = {};
	ret = runCommandMultipleArguments(L"GetProvisioningInfo", L"OOB_Service", return_val, param_names, param_values);
	if (!ret)
	{
		FAIL();
	}
	ASSERT_EQ(return_val, 0);
	ASSERT_EQ(param_values.size(), param_names.size());

	PKIDNSSuffix = (param_values[0]).bstrVal;
	std::wcout << " PKIDNSSuffix: " << PKIDNSSuffix << std::endl;

	ConfigServerFQDN = (param_values[1]).bstrVal;
	std::wcout << " ConfigServerFQDN: " << ConfigServerFQDN << std::endl;

}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
