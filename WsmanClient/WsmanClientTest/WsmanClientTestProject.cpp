/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
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

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>
#include <string>

using ::testing::AtLeast;
using ::testing::Return;
using namespace std;

//Not tested - constructor with username and password, for all classes
//Shouldn't init be private in all classes, since all methods call it anyway?


/*
* AMTEthernetPortSettings: 
* Link preference:	1 - ME
*					2 - HOST
*					3 - Reserved
*/

//TODO: Disable all AMTEthernetPortSettingsClient tests in case there's no wireless network
TEST(AMTEthernetPortSettingsClient, DISABLED_Get)
{
	AMTEthernetPortSettingsClient settings;
	unsigned int pLinkPreference = 0;
	unsigned int pLinkControl = 0;
	unsigned int pLinkProtection = 0;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection));
	if (ret){
		cout << "Link Preference: " << pLinkPreference << endl;
		cout << "Link Control: " << pLinkControl << endl << endl;
		cout << "Link Protection: " << pLinkProtection << endl << endl;
	}	
}

TEST(AMTEthernetPortSettingsClient, DISABLED_Set1)
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
	
	AMTEthernetPortSettingsClient client;
	EXPECT_TRUE(client.SetLinkPreference(1));	
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool ret = false;
	EXPECT_TRUE(ret = client.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection));
	if (ret){
		EXPECT_EQ(1, pLinkPreference);
		EXPECT_EQ(1, pLinkControl);
	}	
}

TEST(AMTEthernetPortSettingsClient, DISABLED_Set2)
{
	AMTEthernetPortSettingsClient settings;
	EXPECT_TRUE(settings.SetLinkPreference(2));
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection));
	if (ret){
		EXPECT_EQ(2, pLinkPreference);
		EXPECT_EQ(2, pLinkControl);
	}	
}

TEST(AMTEthernetPortSettingsClient, DISABLED_SetInvalid)
{
	AMTEthernetPortSettingsClient settings;
	EXPECT_TRUE(settings.SetLinkPreference(3));
	unsigned int pLinkPreference;
	unsigned int pLinkControl;
	unsigned int pLinkProtection;
	bool ret = false;
	EXPECT_TRUE(ret = settings.GetAMTEthernetPortSettings(&pLinkPreference, &pLinkControl, &pLinkProtection));
	if (ret){
		EXPECT_NE((unsigned int)3, pLinkPreference);
		EXPECT_NE((unsigned int)3, pLinkControl);
	}	
	EXPECT_TRUE(ret = settings.SetLinkPreference(345));
	if (ret){
		EXPECT_NE((unsigned int)345, pLinkPreference);
		EXPECT_NE((unsigned int)345, pLinkControl);
	}	
}

TEST(AMTFCFHWSmanClient, userInitiatedPolicyRule)
{
	AMTFCFHWSmanClient fcfh;
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.userInitiatedPolicyRuleExists(&pExist));
	if (ret){
		cout << "Does user initiated policy rule exist: " << ((pExist!=0) ? "Yes" : "No") << endl;
	}	
}

TEST(AMTFCFHWSmanClient, snmpEventSubscriber)
{
	AMTFCFHWSmanClient fcfh;
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.snmpEventSubscriberExists(&pExist));
	if (ret){
		cout << "Does snmp event subscriber exist: " << ((pExist!=0) ? "Yes" : "No") << endl;
	}	
}

TEST(AMTFCFHWSmanClient, CILAFilterCollectionSubscription)
{
	AMTFCFHWSmanClient fcfh;
	short pExist = 0;
	bool ret = false;
	EXPECT_TRUE(ret = fcfh.CILAFilterCollectionSubscriptionExists(&pExist));
	if (ret){
		cout << "Does CILA filter collection subscription exist: " << ((pExist!=0) ? "Yes" : "No") << endl << endl;
	}	
}

TEST(AMTRedirectionServiceWSManClient, terminateSession)
{
	AMTRedirectionServiceWSManClient redir;
	// Session types:
	// IDER: 0
	// SOL: 1
	// Reserved: 2
	unsigned int sessionType = 0; 
	EXPECT_TRUE(redir.TerminateSession(sessionType));
}

TEST(CancelOptInClient, cancelOption)
{
	CancelOptInClient cancelOpt;
	unsigned int retVal = 0;
	bool ret = false;
	EXPECT_TRUE(ret = cancelOpt.CancelOptIn(&retVal));
	if (ret){
		cout << "Did Cancel option succeed: " << ((retVal!=0) ? "Yes" : "No") << endl;
	}
}

TEST(CancelOptInClient, getUserConsentState)
{
	CancelOptInClient cancelOpt;
	bool ret = false;
	short state=0, policy=0;
	EXPECT_TRUE(ret = cancelOpt.GetUserConsentState(&state, &policy));
	if (ret){
		cout << "User consent state: " << state << endl;
		cout << "User policy: " << policy << endl << endl;
	}
}

TEST(HBPWSManClient, getConfigurationInfo)
{
	HBPWSManClient hbpw;
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

TEST(KVMWSManClient, KVMRedirectionState)
{
	KVMWSManClient kvm;
	unsigned short state = 0;
	bool ret = false;
	EXPECT_TRUE(ret = kvm.KVMRedirectionState(&state));
	if (ret) {
	}
}

TEST(KVMWSManClient, GetMEBxState)
{
	KVMWSManClient kvm;
	bool ret=false, state=false;
	EXPECT_TRUE(ret = kvm.GetMEBxState(&state));
	if (ret){
		cout << "MEBX state: " << state << endl;
	}
}

TEST(KVMWSManClient, TerminateKVMSession)
{
	KVMWSManClient kvm;
	EXPECT_TRUE(kvm.TerminateKVMSession());
}

TEST(SIOWSManClient, getSpriteLanguage)
{
	SIOWSManClient sio;
	unsigned short language=0;
	bool ret = false;
	EXPECT_TRUE(ret = sio.GetSpriteLanguage(&language));
	if (ret){
		cout << "Sprite language is: " << language << endl;
	}
}

TEST(SIOWSManClient, setValidSpriteLanguage)
{
	SIOWSManClient sio;
	unsigned short lang = 0;
	for (; lang<=26; lang++)
	{
		EXPECT_TRUE(sio.SetSpriteLanguage(lang));
	}
}

TEST(SIOWSManClient, setInvalidSpriteLanguage)
{
	SIOWSManClient sio;
	unsigned short lang = 1000;
	EXPECT_FALSE(sio.SetSpriteLanguage(lang));
	lang = 40000;
	EXPECT_FALSE(sio.SetSpriteLanguage(lang));
}

TEST(SIOWSManClient, getSpriteZoom)
{
	SIOWSManClient sio;
	unsigned short zoom = 0;
	bool ret = false;
	EXPECT_TRUE(ret = sio.GetSpriteZoom(&zoom));
	if (ret){
		cout << "Sprite zoom is: " << zoom << endl;
	}
}

TEST(SIOWSManClient, setValidSpriteZoom)
{
	SIOWSManClient sio;
	unsigned short zoom2 = 0;
	bool ret = 0;
	for (unsigned short zoom=1; zoom<=2; zoom++)
	{
		EXPECT_TRUE(ret = sio.SetSpriteZoom(zoom));
		if (ret)
		{
			EXPECT_TRUE(ret = sio.GetSpriteZoom(&zoom2));
			if (ret)
			{
				EXPECT_EQ(zoom, zoom2);
			}
		}
	}
}

TEST(SIOWSManClient, setInvalidSpriteZoom)
{
	SIOWSManClient sio;
	EXPECT_FALSE(sio.SetSpriteZoom(100));
}

TEST(SIOWSManClient, getSpriteParameters)
{
	SIOWSManClient sio;
	unsigned short language, zoom, lang2, zoom2;
	bool ret = false;
	EXPECT_TRUE(ret = sio.GetSpriteLanguage(&language));
	EXPECT_TRUE(ret = sio.GetSpriteZoom(&zoom));
	EXPECT_TRUE(sio.GetSpriteParameters(&lang2, &zoom2));
	EXPECT_EQ(lang2, language);
	EXPECT_EQ(zoom2, zoom);
}

TEST(SyncIpClient, GetSharedStaticIpState)
{
	SyncIpClient syncIP;
	bool SharedStaticIpState = false;
	bool ret = false;
	EXPECT_TRUE(ret = syncIP.GetSharedStaticIpState(&SharedStaticIpState));
	if (ret){
		cout << "Shared static IP state: " << ((SharedStaticIpState==true) ? "Enabled" : "Disabled") << endl;
	}
}

TEST(SyncIpClient, GetNetworkData)
{
	SyncIpClient syncIP;
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

/*TEST(SyncIpClient, SetNetworkData)
{
	SyncIpClient syncIP;
	bool ret, DHCPEnabled;
	string IPAddress, subnet, gateway, dnsAddress1, dnsAddress2;
	// TODO: find inputs that will work 
	// Static --> DHCP	DHCP enabled (true\1)
	// Static --> Static true, 100.100.100.100, 255.255.255.0 100.100.100.3 11.11.11.11 22.22.22.22
	// DHSP --> Static	true, 100.100.100.100, 255.255.255.0 100.100.100.3 11.11.11.11 0.0.0.0
	//EXPECT_FALSE(syncIP.SetNetworkData(DHCPEnabled, IPAddress, subnet, gateway, dnsAddress1, dnsAddress2));
}*/

void printTime(unsigned int time)
{
	time_t rawtime(time);
	cout << "Time is: " << ctime(&rawtime);
}

TEST(TimeSynchronizationClient, getTime)
{
	TimeSynchronizationClient timeClient;
	unsigned int time;
	timeClient.GetAMTTime(time);
	printTime(time);
}


TEST(TimeSynchronizationClient, setTime)
{
	TimeSynchronizationClient timeClient;
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
	ASSERT_TRUE(AMTTime-LastAMTTime<=1);
	cout << "Setting forward 100 seconds..." << endl;
	AMTTime += 100;
	LastAMTTime = AMTTime;
	cout << "Time should be: \t" << AMTTime << endl;
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "Time is now: \t\t" << AMTTime << endl;
	ASSERT_TRUE(AMTTime-LastAMTTime<=1);
}

//Syncs FW time to local time
TEST(TimeSynchronizationClient, syncLocalTime)
{
	TimeSynchronizationClient timeClient;
	unsigned int AMTTime, LastAMTTime;
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "Current time: \t\t" << AMTTime << endl;
	cout << "Sync time..." << endl;
	time_t rawtime;
	rawtime = time(NULL);
	cout << "Local time: " << rawtime << endl;
	printTime(rawtime);	
	AMTTime = (unsigned int)rawtime;
	LastAMTTime = AMTTime;
	ASSERT_TRUE(timeClient.SetAMTTime(AMTTime));
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	ASSERT_TRUE(AMTTime-LastAMTTime<=1);
	cout << "New time: \t\t" << AMTTime << endl;
	printTime(AMTTime);
}

//Syncs FW time to UTC time
TEST(TimeSynchronizationClient, syncUTCTime)
{
	TimeSynchronizationClient timeClient;
	unsigned int AMTTime, UTCTime;
	ASSERT_TRUE(timeClient.GetAMTTime(AMTTime));
	cout << "FW time: \t";
	printTime(AMTTime);
	time_t rawtime;
	struct tm* tmpTime;
	time(&rawtime);
	ASSERT_NE(rawtime, -1);
	tmpTime = gmtime(&rawtime);
	UTCTime = mktime(tmpTime);
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


TEST(TimeSynchronizationClient, getEnabledState)
{
	TimeSynchronizationClient timeClient;
	bool state;
	ASSERT_TRUE(timeClient.GetLocalTimeSyncEnabledState(state));
	cout << "Local time sync enabled state is: " << state << endl;
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

