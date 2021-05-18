/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
// AMT_COM_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlsafe.h>
#include "gtest/gtest.h"
#import "AMT_COM_Interface.tlb"

#define ASSERT_THROW_COM_(func, err)                                           \
	try {                                                                  \
		(func);                                                        \
		FAIL();                                                        \
	} catch (const _com_error& e) {                                        \
		if (e.Error() != err) {                                        \
			std::cout << "0x" << std::hex<< e.Error()<< std::endl; \
			FAIL();                                                \
		}                                                              \
	}                                                                      \

#define ASSERT_THROW_INVALIDARG(func)  ASSERT_THROW_COM_(func, E_INVALIDARG)
#define ASSERT_THROW_NOINTERFACE(func) ASSERT_THROW_COM_(func, E_NOINTERFACE)

#define ASSERT_NO_THROW_COM(func)                                              \
	try {                                                                  \
		(func);                                                        \
	} catch (const _com_error& e) {                                        \
		std::cout << "0x "<< std::hex << e.Error()<< std::endl;        \
		FAIL();                                                        \
	}                                                                      \

#define ASSERT_MAY_THROW_COM_(func, err)                                       \
	try {                                                                  \
		(func);                                                        \
	}                                                                      \
	catch (const _com_error& e) {                                          \
		if (e.Error() != err) {                                        \
			std::cout << "0x" << std::hex<< e.Error()<< std::endl; \
			FAIL();                                                \
		}                                                              \
	}                                                                      \

#define ASSERT_MAY_THROW_NOINTERFACE(func) \
	ASSERT_MAY_THROW_COM_(func, E_NOINTERFACE)

/* ------------------------- AMT_COM_Manageability ----------------------- */
class AMT_COM_Manageability : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		CoInitialize(NULL);
		amthi.CreateInstance(__uuidof(AMT_COM_InterfaceLib::Manageability_Commands));
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}

protected:
	AMT_COM_InterfaceLib::IManageability_CommandsPtr amthi;

};

TEST_F(AMT_COM_Manageability, GetFeaturesState)
{
	SAFEARRAY *states;
	ASSERT_THROW_NOINTERFACE(amthi->GetFeaturesState(&states));
}

TEST_F(AMT_COM_Manageability, GetTheFeatureState)
{
	enum AMT_COM_InterfaceLib::FEATURE_STATE State;
	for (int feat = AMT_COM_InterfaceLib::AMT; feat < AMT_COM_InterfaceLib::FEATURES_NUM; feat++)
	{
		if ((feat == AMT_COM_InterfaceLib::DT) || (feat == AMT_COM_InterfaceLib::MPC))
			continue;
		ASSERT_NO_THROW_COM(amthi->GetTheFeatureState((AMT_COM_InterfaceLib::FEATURES)feat, &State));
	}
	ASSERT_THROW_INVALIDARG(amthi->GetTheFeatureState(AMT_COM_InterfaceLib::DT, &State));
	ASSERT_THROW_INVALIDARG(amthi->GetTheFeatureState(AMT_COM_InterfaceLib::MPC, &State));
	ASSERT_THROW_INVALIDARG(amthi->GetTheFeatureState(AMT_COM_InterfaceLib::FEATURES_NUM, &State));
}

TEST_F(AMT_COM_Manageability, GetCustomerType)
{
	enum AMT_COM_InterfaceLib::CUSTOMER_TYPE Type;
	ASSERT_NO_THROW_COM(amthi->GetCustomerType(&Type));
}

TEST_F(AMT_COM_Manageability, GetPlatformType)
{
	enum AMT_COM_InterfaceLib::PLATFORM_TYPE Type;
	ASSERT_THROW_NOINTERFACE(amthi->GetPlatformType(&Type));
}

TEST_F(AMT_COM_Manageability, GetMenageabiltyMode)
{
	enum AMT_COM_InterfaceLib::MENAGEABILTY_MODE Type;
	ASSERT_NO_THROW_COM(amthi->GetMenageabiltyMode(&Type));
}

TEST_F(AMT_COM_Manageability, GetFWInfo)
{
	bstr_t MEBxVersion;
	ULONG BiosBootState;
	VARIANT_BOOL CryptoFuseEnable;
	VARIANT_BOOL LocalFWupdateEnable;
	ASSERT_NO_THROW_COM(amthi->GetFWInfo(&MEBxVersion.GetBSTR(), &BiosBootState, &CryptoFuseEnable, &LocalFWupdateEnable));
	ASSERT_GT(MEBxVersion.length(), 0U);
}

TEST_F(AMT_COM_Manageability, GetPMCVersion)
{
	bstr_t FwVer;
	ASSERT_NO_THROW_COM(amthi->GetPMCVersion(&FwVer.GetBSTR()));
}

TEST_F(AMT_COM_Manageability, IsMeasuredBootState)
{
	VARIANT_BOOL state;
	ASSERT_MAY_THROW_NOINTERFACE(amthi->IsMeasuredBootState(&state));
}

TEST_F(AMT_COM_Manageability, IsMeasuredBootState)
{
	VARIANT_BOOL state;
	ASSERT_MAY_THROW_NOINTERFACE(amthi->IsMeasuredBootState(&state));
}

/* ------------------------- AMT_COM_PTHI ----------------------- */
class AMT_COM_PTHI : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		CoInitialize(NULL);
		amthi.CreateInstance(__uuidof(AMT_COM_InterfaceLib::PTHI_Commands));
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}

protected:
	AMT_COM_InterfaceLib::IPTHI_CommandsPtr amthi;
};

TEST_F(AMT_COM_PTHI, GetAMTVersion)
{
	bstr_t str;
	ASSERT_NO_THROW_COM(amthi->GetAMTVersion(&str.GetBSTR()));
	ASSERT_GT(str.length(), 0U);
}

TEST_F(AMT_COM_PTHI, GetLMSVersion)
{
	bstr_t str;
	ASSERT_NO_THROW_COM(amthi->GetLMSVersion(&str.GetBSTR()));
	ASSERT_GT(str.length(), 0U);
}

TEST_F(AMT_COM_PTHI, GetHeciVersion)
{
	bstr_t str;
	ASSERT_NO_THROW_COM(amthi->GetHeciVersion(&str.GetBSTR()));
	ASSERT_GT(str.length(), 0U);
}

TEST_F(AMT_COM_PTHI, GetProvisioningMode)
{
	SHORT Mode;
	ASSERT_THROW_NOINTERFACE(amthi->GetProvisioningMode(&Mode));
}

TEST_F(AMT_COM_PTHI, GetProvisioningTlsMode)
{
	SHORT Mode;
	ASSERT_THROW_NOINTERFACE(amthi->GetProvisioningTlsMode(&Mode));
}

TEST_F(AMT_COM_PTHI, GetProvisioningState)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->GetProvisioningState(&Mode));
}

TEST_F(AMT_COM_PTHI, GetNetworkConnectionStatus)
{
	SHORT Status;
	SHORT ConnectionType;
	SHORT ConnectionTrigger;
	ASSERT_NO_THROW_COM(amthi->GetNetworkConnectionStatus(&Status, &ConnectionType, &ConnectionTrigger));
}

TEST_F(AMT_COM_PTHI, userInitiatedPolicyRuleExists)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->userInitiatedPolicyRuleExists(&Mode));
}

TEST_F(AMT_COM_PTHI, userInitiatedPolicyRuleForLocalMpsExists)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->userInitiatedPolicyRuleForLocalMpsExists(&Mode));
}

TEST_F(AMT_COM_PTHI, snmpEventSubscriberExists)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->snmpEventSubscriberExists(&Mode));
}

TEST_F(AMT_COM_PTHI, CILAFilterCollectionSubscriptionExists)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->CILAFilterCollectionSubscriptionExists(&Mode));
}

TEST_F(AMT_COM_PTHI, GetUserInitiatedEnabled)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->GetUserInitiatedEnabled(&Mode));
}

TEST_F(AMT_COM_PTHI, getWebUIState)
{
	SHORT Mode;
	ASSERT_THROW_NOINTERFACE(amthi->getWebUIState(&Mode));
}

TEST_F(AMT_COM_PTHI, GetPowerPolicy)
{
	bstr_t str;
	ASSERT_NO_THROW_COM(amthi->GetPowerPolicy(&str.GetBSTR()));
	ASSERT_GT(str.length(), 0U);
}

TEST_F(AMT_COM_PTHI, GetLastResetReason)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->GetLastResetReason(&Mode));
}

TEST_F(AMT_COM_PTHI, GetRedirectionStatus)
{
	SHORT SOL;
	SHORT IDER;
	ASSERT_NO_THROW_COM(amthi->GetRedirectionStatus(&SOL, &IDER));
}

TEST_F(AMT_COM_PTHI, GetSystemDefenseStatus)
{
	SHORT Mode;
	ASSERT_NO_THROW_COM(amthi->GetSystemDefenseStatus(&Mode));
}

TEST_F(AMT_COM_PTHI, GetNetworkSettings)
{
	SHORT DhcpEnabled;
	bstr_t strIpAddress;
	bstr_t strMacAddress;
	SHORT LinkStatus;
	SHORT WirelessControl;
	SHORT WirelessConfEnabled;

	ASSERT_NO_THROW_COM(amthi->GetNetworkSettings(0, &DhcpEnabled, &strIpAddress.GetBSTR(), &strMacAddress.GetBSTR(),
		&LinkStatus, &WirelessControl, &WirelessConfEnabled));
	ASSERT_NO_THROW_COM(amthi->GetNetworkSettings(1, &DhcpEnabled, &strIpAddress.GetBSTR(), &strMacAddress.GetBSTR(),
		&LinkStatus, &WirelessControl, &WirelessConfEnabled));
}

TEST_F(AMT_COM_PTHI, GetIPv6NetworkSettings)
{
	bstr_t IPv6DefaultRouter;
	bstr_t PrimaryDNS;
	bstr_t SecondaryDNS;
	VARIANT Response;
	VARIANT_BOOL Ipv6Enable;

	ASSERT_NO_THROW_COM(amthi->GetIPv6NetworkSettings(0, &IPv6DefaultRouter.GetBSTR(), &PrimaryDNS.GetBSTR(), &SecondaryDNS.GetBSTR(),
		&Response, &Ipv6Enable));
	ASSERT_NO_THROW_COM(amthi->GetIPv6NetworkSettings(1, &IPv6DefaultRouter.GetBSTR(), &PrimaryDNS.GetBSTR(), &SecondaryDNS.GetBSTR(),
		&Response, &Ipv6Enable));
}

TEST_F(AMT_COM_PTHI, GetSystemUUID)
{
	bstr_t str;
	ASSERT_NO_THROW_COM(amthi->GetSystemUUID(&str.GetBSTR()));
	ASSERT_GT(str.length(), 0U);
}

TEST_F(AMT_COM_PTHI, UserInitiatedConnection)
{
	SHORT Status;
	ASSERT_NO_THROW_COM(amthi->InitiateUserConnection(&Status));
	ASSERT_THROW_NOINTERFACE(amthi->OpenUserInitiatedConnection());
	ASSERT_NO_THROW_COM(amthi->CloseUserInitiatedConnection());
}

TEST_F(AMT_COM_PTHI, TerminateKVMSession)
{
	ASSERT_THROW_NOINTERFACE(amthi->TerminateKVMSession());
}

TEST_F(AMT_COM_PTHI, GetKVMRedirectionState)
{
	VARIANT_BOOL Enabled;
	VARIANT_BOOL Connected;
	ASSERT_NO_THROW_COM(amthi->GetKVMRedirectionState(&Enabled, &Connected));
}

TEST_F(AMT_COM_PTHI, Sprite)
{
	SHORT Language;
	ASSERT_NO_THROW_COM(amthi->SetSpriteLanguage(1));
	ASSERT_THROW_NOINTERFACE(amthi->GetSpriteLanguage(&Language));

	SHORT Zoom;
	ASSERT_NO_THROW_COM(amthi->SetSpriteZoom(2));
	ASSERT_THROW_NOINTERFACE(amthi->GetSpriteZoom(&Zoom));

	ASSERT_NO_THROW_COM(amthi->GetSpriteParameters(&Language, &Zoom));
	EXPECT_EQ(Language, 1);
	EXPECT_EQ(Zoom, 2);
}

TEST_F(AMT_COM_PTHI, GetConfigurationInfo)
{
	SHORT ControlMode;
	SHORT ProvisioningMethod;
	bstr_t CreationTimeStamp;
	SAFEARRAY* pCertHash;
	ASSERT_NO_THROW_COM(amthi->GetConfigurationInfo(&ControlMode, &ProvisioningMethod,
												    &CreationTimeStamp.GetBSTR(), &pCertHash));
}

TEST_F(AMT_COM_PTHI, TerminateRemedySessions)
{
	ASSERT_NO_THROW_COM(amthi->TerminateRemedySessions());
}

TEST_F(AMT_COM_PTHI, GetUserConsentState)
{
	SHORT State;
	AMT_COM_InterfaceLib::USER_CONSENT_POLICY Policy;
	ASSERT_NO_THROW_COM(amthi->GetUserConsentState(&State, &Policy));
}

TEST_F(AMT_COM_PTHI, GetWLANLinkInfo)
{
	UINT Preference;
	UINT Control;
	UINT Protection;
	ASSERT_NO_THROW_COM(amthi->GetWLANLinkInfo(&Preference, &Control, &Protection));
}

TEST_F(AMT_COM_PTHI, SetLinkPreferenceToHost)
{
	ASSERT_NO_THROW_COM(amthi->SetLinkPreferenceToHost());
}

TEST_F(AMT_COM_PTHI, UpdateScreenSettings)
{
	AMT_COM_InterfaceLib::EXTENDED_DISPLAY_PARAMETERS_ eExtendedDisplayParameters = 
	{ {0,1,2,3,4,5} };
	ASSERT_THROW_NOINTERFACE(amthi->UpdateScreenSettings(eExtendedDisplayParameters));
}

TEST_F(AMT_COM_PTHI, UpdateScreenSettings2)
{
	AMT_COM_InterfaceLib::EXTENDED_DISPLAY_PARAMETERS_ eExtendedDisplayParameters =
	{ { 0,1,2,3,4,5 } };
	ASSERT_NO_THROW_COM(amthi->UpdateScreenSettings2(eExtendedDisplayParameters, 1));
}

TEST_F(AMT_COM_PTHI, GetRedirectionSessionLinkTechnology)
{
	SHORT LinkTechnology;
	ASSERT_NO_THROW_COM(amthi->GetRedirectionSessionLinkTechnology(AMT_COM_InterfaceLib::SOL_S, &LinkTechnology));
	ASSERT_NO_THROW_COM(amthi->GetRedirectionSessionLinkTechnology(AMT_COM_InterfaceLib::IDER_S, &LinkTechnology));
	ASSERT_NO_THROW_COM(amthi->GetRedirectionSessionLinkTechnology(AMT_COM_InterfaceLib::KVM_S, &LinkTechnology));
}

TEST_F(AMT_COM_PTHI, IsRebootAfterProvisioningNeeded)
{
	VARIANT_BOOL Needed;
	ASSERT_NO_THROW_COM(amthi->IsRebootAfterProvisioningNeeded(&Needed));
}

TEST_F(AMT_COM_PTHI, ProxyAddProxyEntry)
{
	bstr_t proxy_fqdn = "1.2.3.4";
	USHORT proxy_port = 0;
	CComSafeArray<BYTE> gateway_mac_address(6);
	bstr_t network_dns_suffix = "1.2.3.4";
	ASSERT_THROW_NOINTERFACE(amthi->ProxyAddProxyEntry(proxy_fqdn, proxy_port, gateway_mac_address.Detach(), network_dns_suffix));
}

/* ------------------------- AMT_COM_AT_Device ----------------------- */
class AMT_COM_AT_Device : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		CoInitialize(NULL);
		amthi.CreateInstance(__uuidof(AMT_COM_InterfaceLib::AT_Device));
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}

protected:
	AMT_COM_InterfaceLib::IAT_DevicePtr amthi;

};

TEST_F(AMT_COM_AT_Device, GetATDeviceInfo)
{
	SHORT State;
	bstr_t strInfo;
	ASSERT_THROW_NOINTERFACE(amthi->GetATDeviceInfo(&State, &strInfo.GetBSTR()));
}

TEST_F(AMT_COM_AT_Device, GetAuditLogs)
{
	bstr_t bstrAuditLogs;
	ASSERT_NO_THROW_COM(amthi->GetAuditLogs(&bstrAuditLogs.GetBSTR()));
}

/* ------------------------- AMT_COM_UNSAlert ----------------------- */
class AMT_COM_UNSAlert : public ::testing::Test {
protected:
	virtual void SetUp()
	{
		CoInitialize(NULL);
		amthi.CreateInstance(__uuidof(AMT_COM_InterfaceLib::UNSAlert));
	}
	virtual void TearDown()
	{
		CoUninitialize();
	}

protected:
	AMT_COM_InterfaceLib::IUNSAlertPtr amthi;

}; 

TEST_F(AMT_COM_UNSAlert, GetIMSSEventHistory)
{
	bstr_t bstrEventHistory;
	ASSERT_NO_THROW_COM(amthi->GetIMSSEventHistory(&bstrEventHistory.GetBSTR()));
}

TEST_F(AMT_COM_UNSAlert, ResetUNSstartedEvent)
{
	ASSERT_THROW_NOINTERFACE(amthi->ResetUNSstartedEvent());
}

TEST_F(AMT_COM_UNSAlert, RiseAlert)
{
	USHORT category = 1;
	ULONG id = 2;
	bstr_t message = "Test";
	bstr_t messageArg = "Arg";
	bstr_t messageID = "ID";
	bstr_t dateTime = "01/01/01 00:00:00";
	ASSERT_NO_THROW_COM(amthi->RiseAlert(category, id, message, messageArg, messageID, dateTime));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
