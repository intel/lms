/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2024 Intel Corporation
 */
#include "AMTEthernetPortSettingsClient.h"
#include "AMTFCFHWSmanClient.h"
#include "AMTRedirectionServiceWSManClient.h"
#include "AuditLogWSManClient.h"
#include "BaseWSManClient.h"
#include "CancelOptInClient.h"
#include "HBPWSManClient.h"
#include "KVMWSManClient.h"
#include "SIOWSManClient.h"
#include "SyncIpClient.h"
#include "TimeSynchronizationClient.h"
#include "Mock_AMT_EthernetPortSettings.h"
#include "MNGIsChangeToAMTEnabledCommand.h"
#include "KVMScreenSettingClient.h"
#include "EthernetSettingsWSManClient.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <string>

using ::testing::AtLeast;
using ::testing::Return;
using std::cout;
using std::endl;

//Not tested - constructor with username and password, for all classes
//Shouldn't init be private in all classes, since all methods call it anyway?

class WsmanClientTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Intel::MEI_Client::Manageability_Client::MNGIsChangeToAMTEnabledCommand cmd;
		Intel::MEI_Client::Manageability_Client::IsChangedEnabledResponse res = cmd.getResponse();
		m_port = (res.TlsOnLocalPorts) ? AMT_SECURE_PORT : AMT_NON_SECURE_PORT;
	}
	unsigned int m_port;
};

/*
* AMTEthernetPortSettings: 
* Link preference:	1 - ME
*			2 - HOST
*			3 - Reserved
*/
class AMTEthernetPortSettingsTest : public WsmanClientTest
{
};

TEST_F(AMTEthernetPortSettingsTest, Get)
{
	AMTEthernetPortSettingsClient settings(m_port);
	unsigned int pLinkPreference = 0;
	unsigned int pLinkControl = 0;
	unsigned int pLinkProtection = 0;
	bool pIsLink = false;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection, &pIsLink));
	if (ret && pIsLink){
		cout << "Link Preference: " << pLinkPreference << endl;
		cout << "Link Control: " << pLinkControl << endl << endl;
		cout << "Link Protection: " << pLinkProtection << endl << endl;
	}
}

TEST_F(AMTEthernetPortSettingsTest, Set1)
{
	Mock_AMT_EthernetPortSettings mock_settings;
	unsigned int preference = 1;
	AMT_EthernetPortSettings::SetLinkPreference_INPUT input;
	input.LinkPreference(preference);

	ON_CALL(mock_settings, LinkControlExists()).WillByDefault(Return(true));
	ON_CALL(mock_settings, LinkPreferenceExists()).WillByDefault(Return(true));
	ON_CALL(mock_settings, LinkControl()).WillByDefault(Return(1));
	ON_CALL(mock_settings, LinkPreference()).WillByDefault(Return(1));
	//ON_CALL(mock_settings, SetLinkPreference(input)).WillByDefault(Return(1));

	AMTEthernetPortSettingsClient client(m_port);
	EXPECT_TRUE(client.SetLinkPreference(1));
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool pIsLink = false;
	bool ret = false;
	EXPECT_TRUE(ret = client.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection, &pIsLink));
	if (ret && pIsLink){
		EXPECT_EQ(1, pLinkPreference);
		EXPECT_EQ(1, pLinkControl);
	}
}

TEST_F(AMTEthernetPortSettingsTest, Set2)
{
	AMTEthernetPortSettingsClient settings(m_port);
	EXPECT_TRUE(settings.SetLinkPreference(2));
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool pIsLink = false;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection, &pIsLink));
	if (ret && pIsLink){
		EXPECT_EQ(2, pLinkPreference);
		EXPECT_EQ(2, pLinkControl);
	}
}

TEST_F(AMTEthernetPortSettingsTest, SetInvalid)
{
	AMTEthernetPortSettingsClient settings(m_port);
	EXPECT_TRUE(settings.SetLinkPreference(3));
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool pIsLink = false;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection, &pIsLink));
	if (ret && pIsLink){
		EXPECT_NE((unsigned int)3, pLinkPreference);
		EXPECT_NE((unsigned int)3, pLinkControl);
	}
	EXPECT_TRUE(ret = settings.SetLinkPreference(345));
	if (ret && pIsLink){
		EXPECT_NE((unsigned int)345, pLinkPreference);
		EXPECT_NE((unsigned int)345, pLinkControl);
	}
}

class AMTFCFHWSmanTest : public WsmanClientTest
{
};

TEST_F(AMTFCFHWSmanTest, userInitiatedPolicyRule)
{
	AMTFCFHWSmanClient fcfh(m_port);
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.userInitiatedPolicyRuleExists(&pExist));
	if (ret){
		cout << "Does user initiated policy rule exist: " << ((pExist!=0) ? "Yes" : "No") << endl;
	}
}

TEST_F(AMTFCFHWSmanTest, snmpEventSubscriber)
{
	AMTFCFHWSmanClient fcfh(m_port);
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.snmpEventSubscriberExists(&pExist));
	if (ret){
		cout << "Does snmp event subscriber exist: " << ((pExist!=0) ? "Yes" : "No") << endl;
	}
}

TEST_F(AMTFCFHWSmanTest, CILAFilterCollectionSubscription)
{
	AMTFCFHWSmanClient fcfh(m_port);
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.CILAFilterCollectionSubscriptionExists(&pExist));
	if (ret){
		cout << "Does CILA filter collection subscription exist: " << ((pExist!=0) ? "Yes" : "No") << endl << endl;
	}
}

class AMTRedirectionServiceWSManTest : public WsmanClientTest
{
};

TEST_F(AMTRedirectionServiceWSManTest, terminateSession)
{
	AMTRedirectionServiceWSManClient redir(m_port);
	// Session types:
	// IDER: 0
	// SOL: 1
	// Reserved: 2
	unsigned int sessionType = 0; 
	EXPECT_TRUE(redir.TerminateSession(sessionType));
}

class CancelOptInTest : public WsmanClientTest
{
};

TEST_F(CancelOptInTest, cancelOption)
{
	CancelOptInClient cancelOpt(m_port);
	unsigned int retVal = 0;
	bool ret = false;
	EXPECT_TRUE(ret = cancelOpt.CancelOptIn(&retVal));
	if (ret){
		cout << "Did Cancel option succeed: " << ((retVal!=0) ? "Yes" : "No") << endl;
	}
}

TEST_F(CancelOptInTest, getUserConsentState)
{
	CancelOptInClient cancelOpt(m_port);
	bool ret = false;
	short state=0, policy=0;
	EXPECT_TRUE(ret = cancelOpt.GetUserConsentState(&state, &policy));
	if (ret){
		cout << "User consent state: " << state << endl;
		cout << "User policy: " << policy << endl << endl;
	}
}

class HBPWSManTest : public WsmanClientTest
{
};

TEST_F(HBPWSManTest, getConfigurationInfo)
{
	HBPWSManClient hbpw(m_port);
	short controlMode=0, provisioningMethod=0;
	string timeStamp;
	std::vector<unsigned char> pCertHash;
	bool ret = false;
	EXPECT_TRUE(ret = hbpw.GetConfigurationInfo(&controlMode, &provisioningMethod, timeStamp, pCertHash));
	if (ret){
		cout << "Control mode: " << controlMode << endl;
		cout << "Provisioning method: " << provisioningMethod << endl;
		cout << "Time stamp: " << timeStamp << endl;
	}
}

class KVMWSManTest : public WsmanClientTest
{
};

TEST_F(KVMWSManTest, KVMRedirectionState)
{
	KVMWSManClient kvm(m_port);
	unsigned short state = 0;
	bool ret = false;
	EXPECT_TRUE(ret = kvm.KVMRedirectionState(&state));
	if (ret) {
	}
}

TEST_F(KVMWSManTest, GetMEBxState)
{
	KVMWSManClient kvm(m_port);
	bool ret=false, state=false;
	EXPECT_TRUE(ret = kvm.GetMEBxState(&state));
	if (ret){
		cout << "MEBX state: " << state << endl;
	}
}

TEST_F(KVMWSManTest, TerminateKVMSession)
{
	KVMWSManClient kvm(m_port);
	EXPECT_TRUE(kvm.TerminateKVMSession());
}

class SIOWSManTest : public WsmanClientTest
{
};

TEST_F(SIOWSManTest, getSpriteLanguage)
{
	SIOWSManClient sio(m_port);
	unsigned short language=0;
	bool ret = false;
	EXPECT_TRUE(ret = sio.GetSpriteLanguage(&language));
	if (ret){
		cout << "Sprite language is: " << language << endl;
	}
}

TEST_F(SIOWSManTest, setValidSpriteZoom)
{
	SIOWSManClient sio(m_port);
	unsigned short lang2, zoom2 = 0;
	bool ret = 0;
	for (unsigned short zoom=1; zoom<=2; zoom++)
	{
		EXPECT_TRUE(ret = sio.SetSpriteZoom(zoom));
		if (ret)
		{
			EXPECT_TRUE(ret = sio.GetSpriteParameters(&lang2, &zoom2));
			if (ret)
			{
				EXPECT_EQ(zoom, zoom2);
			}
		}
	}
}

TEST_F(SIOWSManTest, setInvalidSpriteZoom)
{
	SIOWSManClient sio(m_port);
	EXPECT_FALSE(sio.SetSpriteZoom(100));
}

TEST_F(SIOWSManTest, getSpriteParameters)
{
	SIOWSManClient sio(m_port);
	unsigned short language, zoom, lang2;
	bool ret = false;
	EXPECT_TRUE(ret = sio.GetSpriteLanguage(&language));
	EXPECT_TRUE(sio.GetSpriteParameters(&lang2, &zoom));
	EXPECT_EQ(lang2, language);
}

class SyncIpTest : public WsmanClientTest
{
};

TEST_F(SyncIpTest, GetSharedStaticIpState)
{
	SyncIpClient syncIP(m_port);
	bool SharedStaticIpState = false;
	bool ret = false;
	EXPECT_TRUE(ret = syncIP.GetSharedStaticIpState(&SharedStaticIpState));
	if (ret){
		cout << "Shared static IP state: " << ((SharedStaticIpState==true) ? "Enabled" : "Disabled") << endl;
	}
}

TEST_F(SyncIpTest, GetNetworkData)
{
	SyncIpClient syncIP(m_port);
	bool ret=false, DHCPEnabled=false;
	string IPAddress, subnet, gateway, dnsAddress1, dnsAddress2;
	EXPECT_TRUE(ret = syncIP.GetNetworkData(DHCPEnabled, IPAddress, subnet, gateway, dnsAddress1, dnsAddress2));
	if (ret){
		cout << "Type of IP: " << "\t" << ((DHCPEnabled==true) ? "DHCP" : "Static") << endl;
		cout << "IP address: " << "\t" << ((IPAddress.compare("")==0) ? "N/A" : IPAddress) << endl;
		cout << "Subnet: " << "\t" << ((subnet.compare("")==0) ? "N/A" : subnet) << endl;
		cout << "Gateway: " << "\t" << ((gateway.compare("")==0) ? "N/A" : gateway) << endl;
		cout << "DNS Address 1: " << "\t" << ((dnsAddress1.compare("")==0) ? "N/A" : dnsAddress1) << endl;
		cout << "DNS Address 2: " << "\t" << ((dnsAddress2.compare("")==0) ? "N/A" : dnsAddress2) << endl;
	}
}

/*TEST_F(SyncIpTest, SetNetworkData)
{
	SyncIpClient syncIP(m_port);
	bool ret, DHCPEnabled;
	string IPAddress, subnet, gateway, dnsAddress1, dnsAddress2;
	// TODO: find inputs that will work 
	// Static --> DHCP	DHCP enabled (true\1)
	// Static --> Static true, 100.100.100.100, 255.255.255.0 100.100.100.3 11.11.11.11 22.22.22.22
	// DHSP --> Static	true, 100.100.100.100, 255.255.255.0 100.100.100.3 11.11.11.11 0.0.0.0
	//EXPECT_FALSE(syncIP.SetNetworkData(DHCPEnabled, IPAddress, subnet, gateway, dnsAddress1, dnsAddress2));
}*/

class KVMScreenSettingTest : public WsmanClientTest
{
};

TEST_F(KVMScreenSettingTest, updateScreenSettings1)
{
	KVMScreenSettingClient Client(m_port);
	KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

	extendedDisplayParameters.screenSettings[0].isActive = 1;
	extendedDisplayParameters.screenSettings[0].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[0].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[0].UpperLeftX = 0;
	extendedDisplayParameters.screenSettings[0].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[0].Pipe = 1;

	EXPECT_TRUE(Client.updateScreenSettings(extendedDisplayParameters, 1));
}

TEST_F(KVMScreenSettingTest, updateScreenSettings2)
{
	KVMScreenSettingClient Client(m_port);
	KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

	extendedDisplayParameters.screenSettings[0].isActive = 1;
	extendedDisplayParameters.screenSettings[0].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[0].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[0].UpperLeftX = 0;
	extendedDisplayParameters.screenSettings[0].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[0].Pipe = 1;
	extendedDisplayParameters.screenSettings[1].isActive = 1;
	extendedDisplayParameters.screenSettings[1].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[1].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[1].UpperLeftX = 640;
	extendedDisplayParameters.screenSettings[1].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[1].Pipe = 2;

	EXPECT_TRUE(Client.updateScreenSettings(extendedDisplayParameters, 2));
}

TEST_F(KVMScreenSettingTest, updateScreenSettings3)
{
	KVMScreenSettingClient Client(m_port);
	KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

	extendedDisplayParameters.screenSettings[0].isActive = 1;
	extendedDisplayParameters.screenSettings[0].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[0].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[0].UpperLeftX = 0;
	extendedDisplayParameters.screenSettings[0].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[0].Pipe = 1;
	extendedDisplayParameters.screenSettings[1].isActive = 1;
	extendedDisplayParameters.screenSettings[1].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[1].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[1].UpperLeftX = 640;
	extendedDisplayParameters.screenSettings[1].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[1].Pipe = 2;
	extendedDisplayParameters.screenSettings[2].isActive = 1;
	extendedDisplayParameters.screenSettings[2].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[2].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[2].UpperLeftX = 1280;
	extendedDisplayParameters.screenSettings[2].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[2].Pipe = 3;

	EXPECT_TRUE(Client.updateScreenSettings(extendedDisplayParameters, 3));
}

TEST_F(KVMScreenSettingTest, updateScreenSettings4)
{
	KVMScreenSettingClient Client(m_port);
	KVMScreenSettingClient::ExtendedDisplayParameters extendedDisplayParameters;

	extendedDisplayParameters.screenSettings[0].isActive = 1;
	extendedDisplayParameters.screenSettings[0].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[0].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[0].UpperLeftX = 0;
	extendedDisplayParameters.screenSettings[0].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[0].Pipe = 1;
	extendedDisplayParameters.screenSettings[1].isActive = 1;
	extendedDisplayParameters.screenSettings[1].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[1].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[1].UpperLeftX = 640;
	extendedDisplayParameters.screenSettings[1].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[1].Pipe = 2;
	extendedDisplayParameters.screenSettings[2].isActive = 1;
	extendedDisplayParameters.screenSettings[2].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[2].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[2].UpperLeftX = 1280;
	extendedDisplayParameters.screenSettings[2].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[2].Pipe = 3;
	extendedDisplayParameters.screenSettings[3].isActive = 1;
	extendedDisplayParameters.screenSettings[3].ResolutionX = 640;
	extendedDisplayParameters.screenSettings[3].ResolutionY = 480;
	extendedDisplayParameters.screenSettings[3].UpperLeftX = 1720;
	extendedDisplayParameters.screenSettings[3].UpperLeftY = 0;
	extendedDisplayParameters.screenSettings[3].Pipe = 3;

	EXPECT_TRUE(Client.updateScreenSettings(extendedDisplayParameters, 4));
}

void printTime(unsigned int time)
{
	time_t rawtime(time);
	cout << "Time is: " << ctime(&rawtime);
}

class TimeSynchronizationTest : public WsmanClientTest
{
};

TEST_F(TimeSynchronizationTest, getTime)
{
	TimeSynchronizationClient timeClient(m_port);
	unsigned int time;
	timeClient.GetAMTTime(time);
	printTime(time);
}


TEST_F(TimeSynchronizationTest, setTime)
{
	TimeSynchronizationClient timeClient(m_port);
	unsigned int AMTTime, LastAMTTime;
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "Current time: \t\t" << AMTTime << endl;
	cout << "Setting back 100 seconds..." << endl;
	AMTTime -= 100;
	LastAMTTime = AMTTime;
	cout << "Time should be: \t" << AMTTime << endl;
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	cout << "Time is now: \t\t" << AMTTime << endl;
	ASSERT_TRUE(AMTTime - LastAMTTime <= 2);
	cout << "Setting forward 100 seconds..." << endl;
	AMTTime += 100;
	LastAMTTime = AMTTime;
	cout << "Time should be: \t" << AMTTime << endl;
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "Time is now: \t\t" << AMTTime << endl;
	ASSERT_TRUE(AMTTime - LastAMTTime <= 2);
}

//Syncs FW time to local time
TEST_F(TimeSynchronizationTest, syncLocalTime)
{
	TimeSynchronizationClient timeClient(m_port);
	unsigned int AMTTime, LastAMTTime;
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "Current time: \t\t" << AMTTime << endl;
	cout << "Sync time..." << endl;
	time_t rawtime;
	rawtime = time(NULL);
	cout << "Local time: " << rawtime << endl;
	AMTTime = (unsigned int)rawtime;
	LastAMTTime = AMTTime;
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	ASSERT_TRUE(AMTTime-LastAMTTime<=1);
	cout << "New time: \t\t" << AMTTime << endl;
	printTime(AMTTime);
}

//Syncs FW time to UTC time
TEST_F(TimeSynchronizationTest, syncUTCTime)
{
	TimeSynchronizationClient timeClient(m_port);
	unsigned int AMTTime, UTCTime;
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "FW time: \t";
	printTime(AMTTime);
	time_t rawtime;
	struct tm* tmpTime;
	time(&rawtime);
	ASSERT_NE(rawtime, -1);
	tmpTime = gmtime(&rawtime);
	UTCTime = static_cast<unsigned int>(mktime(tmpTime));
	cout << "UTC time: \t";
	printTime(UTCTime);
	int diff = UTCTime-AMTTime;
	if (abs(diff)>30)
	{
		cout << "Difference is more than 30 seconds, sync will be performed" << endl;
		ASSERT_TRUE(timeClient.SetAMTTime(UTCTime));
		ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
		cout << "New FW time: ";
		printTime(AMTTime);
	}
}


TEST_F(TimeSynchronizationTest, getEnabledState)
{
	TimeSynchronizationClient timeClient(m_port);
	bool state;
	ASSERT_TRUE(timeClient.GetLocalTimeSyncEnabledState(state));
	cout << "Local time sync enabled state is: " << state << endl;
}

class EthernetSettingsWSManClientTest : public WsmanClientTest
{
};

TEST_F(EthernetSettingsWSManClientTest, Enumerate)
{
	EthernetSettingsWSManClient client(m_port);
	std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> ethernetSettings;
	std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>>::iterator settingsIterator;

	EXPECT_TRUE(client.Enumerate(ethernetSettings));
	std::cout << "EthernetSettingsWSManClient size: " << ethernetSettings.size() << std::endl;
	for (settingsIterator = ethernetSettings.begin();
		settingsIterator != ethernetSettings.end();
		settingsIterator++)
	{
		std::cout << "EthernetSettingsWSManClient data ip: " <<
			((settingsIterator->get()->IPAddressExists()) ? settingsIterator->get()->IPAddress() : "N/A") << std::endl;
	}
}

int main(int argc, char** argv)  
{  
	/*
	//Add this code for filtering tests
	argc = 2;
	argv[1] = "--gtest_filter=*-*AMTEthernetPortSettingsClient*";
	*/

	testing::InitGoogleMock(&argc, argv); 

	//getchar(); // keep console window open until Return keystroke 

	return RUN_ALL_TESTS();
} 
