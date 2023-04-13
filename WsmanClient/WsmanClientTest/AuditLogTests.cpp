/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#include "gmock/gmock.h"
#include <sstream>
#include <iostream>
#include <string>
#include "AuditLogWSManClient.h"
#include "AuditLogWSManClientConsts.h"
#include "AuditLogAccessor.h"
#include <time.h>

using namespace Intel::Manageability::Cim::Typed;

#ifdef WIN32
#define timegm _mkgmtime
#endif

TEST_F(AuditLogAccessor, formatTime0)
{
	std::string timestr = formatTime(NULL);
	ASSERT_EQ("", timestr);
}

TEST_F(AuditLogAccessor, formatTime1)
{
	struct tm timeinfo;
	timeinfo.tm_year = 70;
	timeinfo.tm_mon = 0;
	timeinfo.tm_mday = 1;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;
	time_t time = timegm(&timeinfo);
	string timestr = formatTime(&time);
	ASSERT_EQ("1/1/1970 00:00:00", timestr);
}

TEST_F(AuditLogAccessor, formatTime2)
{
	struct tm timeinfo;
	timeinfo.tm_year = 142;
	timeinfo.tm_mon = 0;
	timeinfo.tm_mday = 25;
	timeinfo.tm_hour = 6;
	timeinfo.tm_min = 32;
	timeinfo.tm_sec = 4;
	time_t time = timegm(&timeinfo);
	string timestr = formatTime(&time);
	ASSERT_EQ("1/25/2042 06:32:04", timestr);
}

TEST_F(AuditLogAccessor, formatTime3)
{
	struct tm timeinfo;
	timeinfo.tm_year = 235;
	timeinfo.tm_mon = 7;
	timeinfo.tm_mday = 2;
	timeinfo.tm_hour = 21;
	timeinfo.tm_min = 6;
	timeinfo.tm_sec = 45;
	time_t time = timegm(&timeinfo);
	string timestr = formatTime(&time);
	ASSERT_EQ("8/2/2135 21:06:45", timestr);
}

TEST_F(AuditLogAccessor, PrintOptInPolicy1)
{
	uint8_t curData = 88;
	char title[1];
	title[0] = 0;
	string str = PrintOptInPolicy(curData, title);
	EXPECT_EQ(": None", str);
}

TEST_F(AuditLogAccessor, PrintOptInPolicy2)
{
	uint8_t curData = 45;
	char title[7] = "Title!";
	string str = PrintOptInPolicy(curData, title);
	EXPECT_EQ("Title!: KVM", str);
}

TEST_F(AuditLogAccessor, PrintOptInPolicy3)
{
	uint8_t curData = 74;
	char title[9] = "Cookies!";
	string str = PrintOptInPolicy(curData, title);
	EXPECT_EQ("Cookies!: ALL", str);
}

TEST_F(AuditLogAccessor, PrintUint32_1)
{
	uint8_t extData[sizeof(uint32_t)];
	int m = 0;
	for (int k=sizeof(uint32_t)-1; k>=0; k--)
	{
		m *= sizeof(uint8_t)*256;
		extData[k] = 21;
		m += 21;
	}
	uint8_t extendedDataLen = sizeof(uint32_t);
	char message[10] = "Message";
	int i = 0;
	string str = PrintUint32(extData, extendedDataLen, message, i);
	stringstream ss;
	ss << "Message: " << m << " ";
	EXPECT_EQ(ss.str(), str);
}

TEST_F(AuditLogAccessor, PrintUint32_2)
{
	uint8_t extData[sizeof(uint32_t)];
	uint8_t extendedDataLen = sizeof(uint32_t)-1;
	char message[10] = "Message";
	int i = 0;
	string str = PrintUint32(extData, extendedDataLen, message, i);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, PrintUint16_1)
{
	uint8_t extData[sizeof(uint16_t)];
	int m = 0;
	for (int k=sizeof(uint16_t)-1; k>=0; k--)
	{
		m *= sizeof(uint8_t)*256;
		extData[k] = 21;
		m += 21;
	}
	uint8_t extendedDataLen = sizeof(uint16_t);
	char message[10] = "Message";
	int i = 0;
	string str = PrintUint16(extData, extendedDataLen, message, i);
	stringstream ss;
	ss << "Message: " << m << " ";
	EXPECT_EQ(ss.str(), str);
}

TEST_F(AuditLogAccessor, PrintUint16_2)
{
	uint8_t extData[sizeof(uint16_t)];
	uint8_t extendedDataLen = sizeof(uint16_t)-1;
	char message[10] = "Message";
	int i = 0;
	string str = PrintUint16(extData, extendedDataLen, message, i);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, PrintInterfaceHandleUint32_1)
{
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 0, sizeof(uint32_t));
	uint8_t extendedDataLen = sizeof(uint32_t);
	int i = 0;
	string str = PrintInterfaceHandleUint32(extData, extendedDataLen, i);
	EXPECT_EQ("LAN", str);
}

TEST_F(AuditLogAccessor, PrintInterfaceHandleUint32_2)
{
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 0, sizeof(uint32_t));
	extData[sizeof(uint32_t)-1] = 1;
	uint8_t extendedDataLen = sizeof(uint32_t);
	int i = 0;
	string str = PrintInterfaceHandleUint32(extData, extendedDataLen, i);
	EXPECT_EQ("WLAN", str);
}

TEST_F(AuditLogAccessor, PrintInterfaceHandleUint32_3)
{
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 1, sizeof(uint32_t));
	uint8_t extendedDataLen = sizeof(uint32_t);
	int i = 0;
	string str = PrintInterfaceHandleUint32(extData, extendedDataLen, i);
	EXPECT_EQ("Unknown", str);
}

TEST_F(AuditLogAccessor, PrintInterfaceHandleUint32_4)
{
	uint8_t extData[sizeof(uint32_t)];
	uint8_t extendedDataLen = sizeof(uint32_t)-1;
	int i = 0;
	string str = PrintInterfaceHandleUint32(extData, extendedDataLen, i);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, DisplayWirelessProfileName0)
{
	uint8_t extData[10];
	extData[0] = 4;
	memset(extData+sizeof(uint8_t), 0, 4); //Name with '\0'
	uint8_t extendedDataLen = 5;
	int i = 0;
	string str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: .", str);
}

TEST_F(AuditLogAccessor, DisplayWirelessProfileName1)
{
	uint8_t extData[10];
	extData[0] = 4;
	memset(extData+sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 5;
	int i = 0;
	string str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AAAA.", str);
}

TEST_F(AuditLogAccessor, DisplayWirelessProfileName2)
{
	uint8_t extData[10];
	extData[0] = 4;
	memset(extData+sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 10;	//Larger size
	int i = 0;
	string str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AAAA.", str);
	extendedDataLen = 3;	//Smaller size
	i=0;
	str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AA.", str);
	i=0;
	extendedDataLen = 0;	//zero size
	str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, DisplayWirelessProfileName3)
{
	uint8_t extData[10];
	extData[0] = 10; //Larger size
	memset(extData+sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 5;	
	int i = 0;
	string str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AAAA.", str);
	extData[0] = 2; //Smaller size
	i=0;
	str = DisplayWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AA.", str);
}

TEST_F(AuditLogAccessor, DisplayBasicUsernameSidInformation_01)
{
	uint8_t extData[10];
	unsigned short numOfTabsToIdent = 5;
	extData[0] = 0;
	extData[1] = 4;
	memset(extData+2*sizeof(uint8_t), 0, 4); //Name with '\0'
	uint8_t extendedDataLen = 6;
	string str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: . ", str);
	memset(extData+2*sizeof(uint8_t), 'A', 4);
	str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: AAAA. ", str);
	extData[1] = 100; //Larger size
	str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: AAAA. ", str);
	extData[1] = 2; //Smaller size
	str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: AA. ", str);
}

TEST_F(AuditLogAccessor, DisplayBasicUsernameSidInformation_02)
{
	uint8_t extData[10];
	unsigned short numOfTabsToIdent = 5;
	extData[0] = 0;
	extData[1] = 4;
	memset(extData+2*sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 100; //Larger size
	string str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: AAAA. ", str);
	extendedDataLen = 3; //Smaller size
	str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Added ");
	EXPECT_EQ("Added user: Username: A. ", str);
}

TEST_F(AuditLogAccessor, DisplayBasicUsernameSidInformation_03)
{
	uint8_t extData[10];
	unsigned short numOfTabsToIdent = 25;
	extData[0] = 0;
	extData[1] = 4;
	memset(extData+2*sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 6;
	string str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Modified ");
	EXPECT_EQ("Modified user: Username: AAAA. ", str);
	numOfTabsToIdent = 300;
	str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Modified ");
	EXPECT_EQ("Modified user: Username: AAAA. ", str);
}

TEST_F(AuditLogAccessor, DisplayBasicUsernameSidInformation_11)
{
	uint8_t extData[20];
	unsigned short numOfTabsToIdent = 5;
	extData[0] = 1;
	memset(extData+sizeof(uint8_t), 7, sizeof(uint32_t));
	extData[1+sizeof(uint32_t)] = 4;
	memset(extData+(2+sizeof(uint32_t))*sizeof(uint8_t), 5, 4);
	uint8_t extendedDataLen = 6+sizeof(uint32_t);
	string str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Removed ");
	stringstream ss;
	ss << "Removed user: SID:";
	for (int k=0; k<sizeof(uint32_t); k++)
	{
		ss << " 7";
	}
	ss << ". Domain: 5 5 5 5. ";
	EXPECT_EQ(ss.str(), str);
}

TEST_F(AuditLogAccessor, DisplayBasicUsernameSidInformation_2)
{
	uint8_t extData[20];
	unsigned short numOfTabsToIdent = 5;
	extData[0] = 91;
	memset(extData+sizeof(uint8_t), 'm', 9);
	uint8_t extendedDataLen = 10;
	string str = DisplayBasicUsernameSidInformation(extData, extendedDataLen, numOfTabsToIdent, "Removed ");
	EXPECT_EQ("Removed user: ", str);
}

TEST_F(AuditLogAccessor, DisplayAuthenticationMode)
{
	string str = DisplayAuthenticationMode(NO_AUTHENTICATION);
	EXPECT_EQ(NO_AUTHENTICATION_STRING, str);
	str = DisplayAuthenticationMode(AUTHENTICATION);
	EXPECT_EQ(AUTHENTICATION_STRING, str);
	str = DisplayAuthenticationMode(DISABLE);
	EXPECT_EQ("Disable", str);
	str = DisplayAuthenticationMode(90);
	EXPECT_EQ("", str);
	str = DisplayAuthenticationMode(-64);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, DisplayAuthenticationStatus)
{
	string str = DisplayAuthenticationStatus(NO_AUTHEN);
	EXPECT_EQ(NO_AUTHENTICATION_STRING, str);
	str = DisplayAuthenticationStatus(SERVER_AUTHENTICATION);
	EXPECT_EQ(SERVER_AUTHENTICATION_STRING, str);
	str = DisplayAuthenticationStatus(MUTUAL_AUTHENTICATION);
	EXPECT_EQ(MUTUAL_AUTHENTICATION_STRING, str);
	str = DisplayAuthenticationStatus(90);
	EXPECT_EQ("", str);
	str = DisplayAuthenticationStatus(-64);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, DisplayFirmwareVerion)
{
	uint8_t extData[4*sizeof(uint16_t)];
	memset(extData, 0, 4*sizeof(uint16_t));
	extData[sizeof(uint16_t)-1] = 8;
	extData[4*sizeof(uint16_t)-2] = 4;
	extData[4*sizeof(uint16_t)-1] = 43;
	string str = DisplayFirmwareVerion(extData, 0);
	EXPECT_EQ("8.0.0.1067.", str);
}

TEST_F(AuditLogAccessor, DisplayTimeStamp0)
{
	uint8_t extData[sizeof(time_t)];
	memset(extData, 0, sizeof(time_t));
	string str = DisplayTimeStamp(extData);
	EXPECT_EQ("1/1/1970 00:00:00", str);
}

TEST_F(AuditLogAccessor, DisplayTimeStamp1)
{
	uint8_t extData[sizeof(unsigned int)];

	struct tm timeinfo;
	timeinfo.tm_year = 142;
	timeinfo.tm_mon = 0;
	timeinfo.tm_mday = 25;
	timeinfo.tm_hour = 8;
	timeinfo.tm_min = 32;
	timeinfo.tm_sec = 4;
	time_t time = timegm(&timeinfo);
	for (int k=sizeof(unsigned int)-1; k>=0; k--)
	{
		extData[k] = time%256;
		time = time/256;
	}
	string str = DisplayTimeStamp(extData);
	ASSERT_EQ("1/25/2042 08:32:04", str);
}

/////// Uses DisplayWirelessProfileName
TEST_F(AuditLogAccessor, DisplayFullWirelessProfileName0)
{
	uint8_t extData[40];
	memset(extData, 0, SSID_LEN); // SSID with '\0'
	extData[SSID_LEN] = 0; //Priority
	extData[SSID_LEN+1] = 4; //Length of profile name
	memset(extData+sizeof(uint8_t)*(SSID_LEN+2), 'A', 4);
	uint8_t extendedDataLen = SSID_LEN+6;
	int i = 0;
	string str = DisplayFullWirelessProfileName(extData, extendedDataLen, i);
	EXPECT_EQ("Profile Name: AAAA. SSID: . Profile Priority: 0. ", str);
}

/////// Uses DisplayWirelessProfileName
TEST_F(AuditLogAccessor, DisplayFullWirelessProfileName1)
{
	uint8_t extData[40];
	memset(extData, 97, SSID_LEN); // SSID
	extData[SSID_LEN] = 0; //Priority
	extData[SSID_LEN+1] = 4; //Length of profile name
	memset(extData+sizeof(uint8_t)*(SSID_LEN+2), 'A', 4);
	uint8_t extendedDataLen = SSID_LEN+6;
	int i = 0;
	string str = DisplayFullWirelessProfileName(extData, extendedDataLen, i);
	stringstream ss;
	ss << "Profile Name: AAAA. SSID: ";
	for (int k=0; k<SSID_LEN; k++)
	{
		ss << "a";
	}
	ss << ". Profile Priority: 0. ";
	EXPECT_EQ(ss.str(), str);
}

TEST_F(AuditLogAccessor, DisplayAgentID)
{
	uint8_t extData[AGENT_ID_LEN];
	memset(extData, 0, AGENT_ID_LEN);
	string str = DisplayAgentID(extData);
	EXPECT_EQ("Agent ID: 0000-0000-0000-0000. ", str);
	memset(extData, 73, AGENT_ID_LEN);
	str = DisplayAgentID(extData);
	EXPECT_EQ("Agent ID: 73737373-73737373-73737373-73737373. ", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminAmtProvisioningCompletedEvent1)
{
	uint8_t extData[50];
	uint8_t extendedDataLen = 50;
	extData[0] = 1; //PSK
	string str = DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
	EXPECT_EQ("Provisioning Method: PSK. ", str);
	extData[0] = 23; //Other
	str = DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
	EXPECT_EQ("Provisioning Method: Unknown. (23)", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminAmtProvisioningCompletedEvent2)
{
	uint8_t extData[50];
	uint8_t extendedDataLen = 50;
	memset(extData, 0, 50); //Will have '\0' in certs
	extData[0] = 2; //PKI
	extData[4] = 7; //NumOfCerts
	string str = DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
	EXPECT_EQ("Provisioning Method: PKI. Provisioning Server FQDN: . ", str);
	memset(extData+sizeof(uint8_t)*5, 'A', 4);
	str = DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
	EXPECT_EQ("Provisioning Method: PKI. Provisioning Server FQDN: AAAA. ", str);
	memset(extData+sizeof(uint8_t)*5, 'A', 10);
	str = DisplaySecurityAdminAmtProvisioningCompletedEvent(extData, extendedDataLen);
	EXPECT_EQ("Provisioning Method: PKI. Provisioning Server FQDN: AAAAAAA. ", str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryAddedRemovedEvent0)
{
	uint8_t extData[10];
	extData[0] = 0;
	extData[1] = 4;
	memset(extData+2*sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 6;
	string str = DisplaySecurityAdminAclEntryAddedEvent(extData, extendedDataLen);
	EXPECT_EQ("Added user: Username: AAAA. ", str);
	str = DisplaySecurityAdminAclEntryRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ("Removed user: Username: AAAA. ", str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryAddedRemovedEvent1)
{
	uint8_t extData[20];
	extData[0] = 1;
	memset(extData+sizeof(uint8_t), 7, sizeof(uint32_t));
	extData[1+sizeof(uint32_t)] = 4;
	memset(extData+(2+sizeof(uint32_t))*sizeof(uint8_t), 5, 4);
	uint8_t extendedDataLen = 6+sizeof(uint32_t);
	stringstream ss1, ss2, temp;
	temp << " user: SID:";
	for (int k=0; k<sizeof(uint32_t); k++)
	{
		temp << " 7";
	}
	temp << ". Domain: 5 5 5 5. ";
	ss1 << "Added" << temp.str();
	ss2 << "Removed" << temp.str();
	string str = DisplaySecurityAdminAclEntryAddedEvent(extData, extendedDataLen);
	EXPECT_EQ(ss1.str(), str);
	str = DisplaySecurityAdminAclEntryRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ(ss2.str(), str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryModifiedEvent0)
{
	uint8_t extData[10];
	extData[0] = 0;
	extData[1] = 0;
	extData[2] = 4;
	memset(extData+3*sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 7;
	string str = DisplaySecurityAdminAclEntryModifiedEvent(extData, extendedDataLen);
	EXPECT_EQ("Modified user: Username: AAAA. Modified fields: Username=false, Password=false, Local realms=false, Remote realms=false, Kerberos domain=false, SID=false", str);
	extData[0] = 63;
	str = DisplaySecurityAdminAclEntryModifiedEvent(extData, extendedDataLen);
	EXPECT_EQ("Modified user: Username: AAAA. Modified fields: Username=true, Password=true, Local realms=true, Remote realms=true, Kerberos domain=true, SID=true", str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryModifiedEvent1)
{
	uint8_t extData[7+sizeof(uint32_t)];
	extData[0] = 0;
	extData[1] = 1;
	memset(extData+2*sizeof(uint8_t), 7, sizeof(uint32_t));
	extData[2+sizeof(uint32_t)] = 4;
	memset(extData+(3+sizeof(uint32_t))*sizeof(uint8_t), 5, 4);
	uint8_t extendedDataLen = 7+sizeof(uint32_t);
	string str = DisplaySecurityAdminAclEntryModifiedEvent(extData, extendedDataLen);
	stringstream ss;
	ss << "Modified user: SID:";
	for (int k=0; k<sizeof(uint32_t); k++)
	{
		ss << " 7";
	}
	ss << ". Domain: 5 5 5 5. ";
	stringstream ss1, ss2;
	ss1 << ss.str() << "Modified fields: Username=false, Password=false, Local realms=false, Remote realms=false, Kerberos domain=false, SID=false";
	EXPECT_EQ(ss1.str(), str);
	extData[0] = 63;
	str = DisplaySecurityAdminAclEntryModifiedEvent(extData, extendedDataLen);
	ss2 << ss.str() << "Modified fields: Username=true, Password=true, Local realms=true, Remote realms=true, Kerberos domain=true, SID=true";
	EXPECT_EQ(ss2.str(), str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent)
{
	uint8_t extData[5];
	uint8_t extendedDataLen = 5;
	extData[0] = AMT_TYPE;
	string str = DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(extData, extendedDataLen);
	EXPECT_EQ("Invalid access from: Intel(R) AMT", str);
	extData[0] = MEBX_TYPE;
	str = DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(extData, extendedDataLen);
	EXPECT_EQ("Invalid access from: Intel(R) MEBx", str);
	extData[0] = 6;
	str = DisplaySecurityAdminAclAccessWithInvalidCredentialsEvent(extData, extendedDataLen);
	EXPECT_EQ("Invalid access from: Unknown", str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryEnabledEvent0)
{
	uint8_t extData[10];
	extData[0] = 0;
	extData[1] = 0;
	extData[2] = 4;
	memset(extData+3*sizeof(uint8_t), 'A', 4);
	uint8_t extendedDataLen = 7;
	string str = DisplaySecurityAdminAclEntryEnabledEvent(extData, extendedDataLen);
	EXPECT_EQ("Disabled user: Username: AAAA. ", str);
	extData[0] = 1;
	str = DisplaySecurityAdminAclEntryEnabledEvent(extData, extendedDataLen);
	EXPECT_EQ("Enabled user: Username: AAAA. ", str);
}

/////// Uses DisplayBasicUsernameSidInformation
TEST_F(AuditLogAccessor, DisplaySecurityAdminAclEntryEnabledEvent1)
{
	uint8_t extData[7+sizeof(uint32_t)];
	extData[0] = 0;
	extData[1] = 1;
	memset(extData+2*sizeof(uint8_t), 7, sizeof(uint32_t));
	extData[2+sizeof(uint32_t)] = 4;
	memset(extData+(3+sizeof(uint32_t))*sizeof(uint8_t), 5, 4);
	uint8_t extendedDataLen = 7+sizeof(uint32_t);
	string str = DisplaySecurityAdminAclEntryEnabledEvent(extData, extendedDataLen);
	stringstream ss;
	ss << " user: SID:";
	for (int k=0; k<sizeof(uint32_t); k++)
	{
		ss << " 7";
	}
	ss << ". Domain: 5 5 5 5. ";
	stringstream ss1, ss2;
	ss1 << "Disabled" << ss.str();
	ss2 << "Enabled" << ss.str();
	EXPECT_EQ(ss1.str(), str);
	extData[0] = 1;
	str = DisplaySecurityAdminAclEntryEnabledEvent(extData, extendedDataLen);
	EXPECT_EQ(ss2.str(), str);
}

/////// Uses DisplayAuthenticationStatus
TEST_F(AuditLogAccessor, DisplaySecurityAdminTlsStateChangedEvent)
{
	uint8_t extData[2];
	uint8_t extendedDataLen = 2;
	extData[0] = 0;
	extData[1] = 1;
	string str = DisplaySecurityAdminTlsStateChangedEvent(extData, extendedDataLen);
	EXPECT_EQ("Remote TLS State: No authentication, Local TLS State: Server Authentication", str);
	extData[0] = 2;
	extData[1] = 3;
	str = DisplaySecurityAdminTlsStateChangedEvent(extData, extendedDataLen);
	EXPECT_EQ("Remote TLS State: Mutual Authentication, Local TLS State: ", str);
	extendedDataLen = 0;
	str = DisplaySecurityAdminTlsStateChangedEvent(extData, extendedDataLen);
	EXPECT_EQ("", str);
	extendedDataLen = 1;
	str = DisplaySecurityAdminTlsStateChangedEvent(extData, extendedDataLen);
	EXPECT_EQ("Remote TLS State: Mutual Authentication", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminTlsCertificateRelatedEvent)
{
	uint8_t extData[25];
	uint8_t extendedDataLen = 25; //Actual should be 20 (= CERT_SERIAL_NUM_MAX_LEN)
	memset(extData, 44, 25);
	string str = DisplaySecurityAdminTlsCertificateRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Certificate Serial Number: 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C ", str);
	extendedDataLen = 0;
	str = DisplaySecurityAdminTlsCertificateRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("", str);
	extendedDataLen = 12;
	str = DisplaySecurityAdminTlsCertificateRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Certificate Serial Number: 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C 2C ", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminKerberosSettingsModifiedEvent)
{
	uint8_t extData[1];
	uint8_t extendedDataLen = 1;
	extData[0] = 0;
	string str = DisplaySecurityAdminKerberosSettingsModifiedEvent(extData, extendedDataLen);
	EXPECT_EQ("Time Tolerance: 0 minute(s)", str);
	extData[0] = 132;
	str = DisplaySecurityAdminKerberosSettingsModifiedEvent(extData, extendedDataLen);
	EXPECT_EQ("Time Tolerance: 132 minute(s)", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminPowerPackageModifiedEvent)
{
	uint8_t extData0[16] = {118 , 57 , 151 , 17 , 11 , 86 , 80 , 67 , 136 , 112 , 152 , 18 , 243 , 145 , 181 , 96};
	uint8_t extData1[16] = {38 , 211 , 28 , 118 , 135 , 8 , 199 , 75 , 187 , 95 , 56 , 116 , 67 , 21 , 165 , 255};
	uint8_t extData2[16] = {83 , 14 , 8 , 219 , 108 , 15 , 217 , 72 , 178 , 210 , 137 , 88 , 211 , 241 , 21 , 110};
	uint8_t extData3[16] = {5 , 93 , 213 , 182 , 76 , 164 , 135 , 77 , 165 , 168 , 180 , 124 , 20 , 222 , 218 , 95};
	uint8_t extData4[16] = {48 , 128 , 13 , 238 , 9 , 192 , 120 , 67 , 175 , 40 , 120 , 104 , 162 , 219 , 190 , 58};
	uint8_t extData5[16] = {148 , 79 , 131 , 18 , 251 , 16 , 79 , 220 , 150 , 142 , 30 , 35 , 43 , 12 , 144 , 101};
	uint8_t extData6[16] = {161 , 134 , 0 , 171 , 154 , 127 , 76 , 66 , 166 , 230 , 187 , 36 , 58 , 41 , 93 , 158};
	uint8_t extData7[16] = {114 , 134 , 171 , 172 , 150 , 180 , 72 , 226 , 155 , 158 , 155 , 125 , 249 , 28 , 127 , 212};
	uint8_t extData8[16] = {123 , 50 , 205 , 77 , 107 , 190 , 67 , 137 , 166 , 42 , 77 , 123 , 216 , 219 , 208 , 38};
	uint8_t extData9[16] = {115 , 34 , 115 , 70 , 35 , 220 , 67 , 47 , 169 , 138 , 19 , 211 , 121 , 130 , 216 , 85};
	uint8_t extData10[16] = {197 , 25 , 164 , 186 , 110 , 111 , 141 , 77 , 178 , 39 , 81 , 127 , 126 , 69 , 149 , 219};
	uint8_t extData11[16] = {214 , 11 , 227 , 237 , 4 , 197 , 44 , 70 , 183 , 114 , 209 , 128 , 24 , 238 , 47 , 196};
	
	uint8_t* extData[12] = {extData0, extData1, extData2, extData3, extData4, extData5, extData6, extData7, extData8, 
		extData9, extData10, extData11};
	string str;
	for (int k=0; k<12; k++)
	{
		stringstream ss;
		ss << "Power Package Modified to: " << powerPolicyStrings[k];
		str = DisplaySecurityAdminPowerPackageModifiedEvent(extData[k], 16);
		EXPECT_EQ(ss.str(), str);
	}
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminSetRealmAuthenticationModeEvent)
{
	uint8_t extData[sizeof(uint32_t)];
	uint8_t extendedDataLen = sizeof(uint32_t);
	memset(extData, 0, sizeof(uint32_t));
	string str;
	for (int k=0; k<=22; k++)
	{
		extData[sizeof(uint32_t)-1] = (uint8_t)k;
		str = DisplaySecurityAdminSetRealmAuthenticationModeEvent(extData, extendedDataLen);
		EXPECT_EQ(realmsStrings[k], str);
	}
	extData[sizeof(uint32_t)-1] = 23;
	str = DisplaySecurityAdminSetRealmAuthenticationModeEvent(extData, extendedDataLen);
	EXPECT_EQ("UnknownRealm", str);	
	memset(extData, 5, sizeof(uint32_t));
	str = DisplaySecurityAdminSetRealmAuthenticationModeEvent(extData, extendedDataLen);
	EXPECT_EQ("UnknownRealm", str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAdminUnprovisioningCompleted)
{
	uint8_t extData[1];
	uint8_t extendedDataLen = 1;
	extData[0] = 0;
	string str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("", str);
	extData[0] = 1;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("BIOS", str);
	extData[0] = 2;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("MEBx", str);
	extData[0] = 3;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("Local MEI", str);
	extData[0] = 4;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("Local WSMAN/SOAP", str);
	extData[0] = 5;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("Remote WSMAN/SOAP", str);
	extData[0] = 6;
	str = DisplaySecurityAdminUnprovisioningCompleted(extData, extendedDataLen);
	EXPECT_EQ("", str);
}

TEST_F(AuditLogAccessor, DisplayRemoteControlBootOptionsRelatedEvent)
{
	uint8_t extData[13];
	uint8_t extendedDataLen = 13; //Actual should be 7 (= BOOT_OPTIONS_LEN)
	memset(extData, 44, 13);
	string str = DisplayRemoteControlBootOptionsRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Boot Options: 2C 2C 2C 2C 2C 2C 2C ", str);
	extendedDataLen = 0;
	str = DisplayRemoteControlBootOptionsRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("", str);
	extendedDataLen = 5;
	str = DisplayRemoteControlBootOptionsRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Boot Options: 2C 2C 2C 2C 2C ", str);
}

/////// Uses DisplayFirmwareVerion
TEST_F(AuditLogAccessor, DisplayFirmwareUpdatedEvent)
{
	uint8_t extData[8*sizeof(uint16_t)];
	memset(extData, 0, 8*sizeof(uint16_t));

	extData[sizeof(uint16_t) - 1] = 8;
	extData[4 * sizeof(uint16_t) - 2] = 4;
	extData[4 * sizeof(uint16_t) - 1] = 43;

	extData[5 * sizeof(uint16_t) - 1] = 8;
	extData[8 * sizeof(uint16_t) - 2] = 4;
	extData[8 * sizeof(uint16_t) - 1] = 43;

	string str = DisplayFirmwareUpdatedEvent(extData, 8*sizeof(uint16_t));
	EXPECT_EQ("Old FW Version: 8.0.0.1067. New FW Version: 8.0.0.1067.", str);
}

/////// Uses PrintUint32
TEST_F(AuditLogAccessor, DisplayFirmwareUpdatedFailedEvent)
{
	uint8_t extData[sizeof(uint32_t)];
	int m = 0;
	for (int k=sizeof(uint32_t)-1; k>=0; k--)
	{
		m *= sizeof(uint8_t)*256;
		extData[k] = 76;
		m += 76;
	}
	string str = DisplayFirmwareUpdatedFailedEvent(extData, sizeof(uint32_t));
	stringstream ss;
	ss << "Failure Reason: " << m << " ";
	EXPECT_EQ(ss.str(), str);
}

TEST_F(AuditLogAccessor, DisplaySecurityAuditLogRecoveryEvent)
{
	uint8_t extData[1];
	uint8_t extendedDataLen = 1;
	string str;
	string r = "Reason: ";
	for (int k=0; k<=2; k++)
	{
		extData[0] = (uint8_t)k;
		str = DisplaySecurityAuditLogRecoveryEvent(extData, extendedDataLen);
		stringstream ss;
		ss << r << securityAuditLogRecoveryReason[k];
		EXPECT_EQ(ss.str(), str);
	}
	extData[0] = 3;
	str = DisplaySecurityAuditLogRecoveryEvent(extData, extendedDataLen);
	EXPECT_EQ("Reason: Unknown", str);
}

/////// Uses DisplayTimeStamp
TEST_F(AuditLogAccessor, DisplayNetworkTimeTimeSetEvent)
{
	uint8_t extData[sizeof(unsigned int)];

	struct tm timeinfo;
	timeinfo.tm_year = 142;
	timeinfo.tm_mon = 0;
	timeinfo.tm_mday = 25;
	timeinfo.tm_hour = 8;
	timeinfo.tm_min = 32;
	timeinfo.tm_sec = 4;
	time_t time = timegm(&timeinfo);
	for (int k=sizeof(unsigned int)-1; k>=0; k--)
	{
		extData[k] = time%256;
		time = time/256;
	}
	string str = DisplayNetworkTimeTimeSetEvent(extData, sizeof(unsigned int));
	ASSERT_EQ("Intel(R) AMT Time: 1/25/2042 08:32:04", str);
	str = DisplayNetworkTimeTimeSetEvent(extData, sizeof(unsigned int)-1);
	ASSERT_EQ("", str);
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminTcpIpParameterSetEvent1)
{
	uint8_t extData[sizeof(uint32_t)+21];
	memset(extData, 0, sizeof(uint32_t)+21);
	extData[sizeof(uint32_t)-1] = 0; //LAN
	extData[sizeof(uint32_t)] = 0; //DHCP disabled
	uint8_t extendedDataLen = 11+sizeof(uint32_t);
	string str = DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. DHCP Enabled: Disabled. IPv4 Address: 0.0.0.0 Subnet Mask: 0.0.0.0 ", str);
	extendedDataLen = 20+sizeof(uint32_t);
	str = DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. DHCP Enabled: Disabled. IPv4 Address: 0.0.0.0 Subnet Mask: 0.0.0.0 Default Gateway: 0.0.0.0 Preferred DNS Server: 0.0.0.0 ", str);
	extendedDataLen = 21+sizeof(uint32_t);
	str = DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. DHCP Enabled: Disabled. IPv4 Address: 0.0.0.0 Subnet Mask: 0.0.0.0 Default Gateway: 0.0.0.0 Preferred DNS Server: 0.0.0.0 Alternate DNS Server: 0.0.0.0 ", str);
	
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminTcpIpParameterSetEvent2)
{
	uint8_t extData[sizeof(uint32_t)+21];
	memset(extData, 0, sizeof(uint32_t)+21);
	extData[sizeof(uint32_t)-1] = 0; //LAN
	extData[sizeof(uint32_t)] = 0; //DHCP disabled
	uint8_t extendedDataLen = 21+sizeof(uint32_t);
	extData[sizeof(uint32_t)+1] = 192;
	extData[sizeof(uint32_t)+2] = 168;
	extData[sizeof(uint32_t)+3] = 1;
	extData[sizeof(uint32_t)+4] = 1;
	extData[sizeof(uint32_t)+5] = 255;
	extData[sizeof(uint32_t)+6] = 255;
	extData[sizeof(uint32_t)+7] = 255;
	extData[sizeof(uint32_t)+8] = 0;
	extData[sizeof(uint32_t)+9] = 192;
	extData[sizeof(uint32_t)+10] = 168;
	extData[sizeof(uint32_t)+11] = 1;
	extData[sizeof(uint32_t)+12] = 5;
	extData[sizeof(uint32_t)+13] = 192;
	extData[sizeof(uint32_t)+14] = 168;
	extData[sizeof(uint32_t)+15] = 1;
	extData[sizeof(uint32_t)+16] = 8;
	extData[sizeof(uint32_t)+17] = 192;
	extData[sizeof(uint32_t)+18] = 168;
	extData[sizeof(uint32_t)+19] = 1;
	extData[sizeof(uint32_t)+20] = 4;
	string str = DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. DHCP Enabled: Disabled. IPv4 Address: 192.168.1.1 Subnet Mask: 255.255.255.0 Default Gateway: 192.168.1.5 Preferred DNS Server: 192.168.1.8 Alternate DNS Server: 192.168.1.4 ", str);
	
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminTcpIpParameterSetEvent3)
{
	uint8_t extData[sizeof(uint32_t)+1];
	memset(extData, 0, sizeof(uint32_t));
	extData[sizeof(uint32_t)-1] = 1; //WLAN
	extData[sizeof(uint32_t)] = 1; //DHCP enabled
	uint8_t extendedDataLen = 1+sizeof(uint32_t);
	string str = DisplayNetworkAdminTcpIpParameterSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: WLAN. DHCP Enabled: Enabled. ", str);
}

TEST_F(AuditLogAccessor, DisplayNetworkAdminHostNameSetEvent)
{
	uint8_t extData[8];
	memset(extData, 0, 8);
	extData[0] = 5;
	string str = DisplayNetworkAdminHostNameSetEvent(extData, 8);
	EXPECT_EQ("Host Name: ", str);
	memset(extData+sizeof(uint8_t), 'g', 7);
	str = DisplayNetworkAdminHostNameSetEvent(extData, 8);
	EXPECT_EQ("Host Name: ggggg", str);
}

TEST_F(AuditLogAccessor, DisplayNetworkAdminDomainNameSetEvent)
{
	uint8_t extData[8];
	memset(extData, 0, 8);
	extData[0] = 5;
	string str = DisplayNetworkAdminDomainNameSetEvent(extData, 8);
	EXPECT_EQ("Domain Name: ", str);
	memset(extData+sizeof(uint8_t), 'g', 7);
	str = DisplayNetworkAdminDomainNameSetEvent(extData, 8);
	EXPECT_EQ("Domain Name: ggggg", str);
}

void LinkPolicySetEventHelper(bool *set, int *nums, int &sum, string &str)
{
	stringstream ss;
	sum = 0;
	ss << "Network Interface: WLAN. Link Policy: ";
	bool comma = false;
	for (int k=0; k<4; k++)
	{
		if (set[k])
		{
			if (comma)
				ss << ", ";
			sum += nums[k];
			ss << LinkPolicyValues[k];
			comma = true;
		}
	}
	str = ss.str();
}

/////// Uses PrintInterfaceHandleUint32 and ReverseMemCopy
TEST_F(AuditLogAccessor, DisplayNetworkAdminLinkPolicySetEvent)
{
	uint8_t extendedDataLen = 2*sizeof(uint32_t);
	uint8_t extData[2*sizeof(uint32_t)];
	memset(extData, 0, 2*sizeof(uint32_t));
	extData[sizeof(uint32_t)-1] = 1; //WLAN
	int nums[4] = {1, 14, 16, 224};
	bool set[4];
	memset(set, false, 4);
	int sum = 0;
	set[0] = true;
	set[2] = true;
	string compstr, str;
	LinkPolicySetEventHelper(set, nums, sum, compstr);
	extData[2*sizeof(uint32_t)-1] = (uint8_t)sum;
	str = DisplayNetworkAdminLinkPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ(compstr, str);
	set[0] = false;
	set[1] = true;
	set[2] = false;
	set[3] = true;
	LinkPolicySetEventHelper(set, nums, sum, compstr);
	extData[2*sizeof(uint32_t)-1] = (uint8_t)sum;
	str = DisplayNetworkAdminLinkPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ(compstr, str);
	set[0] = true;
	set[1] = false;
	set[2] = true;
	set[3] = true;
	LinkPolicySetEventHelper(set, nums, sum, compstr);
	extData[2*sizeof(uint32_t)-1] = (uint8_t)sum;
	str = DisplayNetworkAdminLinkPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ(compstr, str);
	memset(extData, 32, 2*sizeof(uint32_t));
	str = DisplayNetworkAdminLinkPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: Unknown. Link Policy: Disabled", str);
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminIPv6ParamsEvent1)
{
	uint8_t extendedDataLen = 74+sizeof(uint32_t);
	uint8_t extData[74+sizeof(uint32_t)];
	memset(extData, 0, 74+sizeof(uint32_t));
	string str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	extData[sizeof(uint32_t)] = 1; //IPv6 enabled
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Enabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	extendedDataLen = (74-31)+sizeof(uint32_t);
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Enabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 ", str);
	extendedDataLen = (74-32)+sizeof(uint32_t);
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Enabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 ", str);
	extendedDataLen = (74-33)+sizeof(uint32_t);
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Enabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 ", str);
	extendedDataLen = sizeof(uint32_t)+1;
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Enabled. ", str);
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminIPv6ParamsEvent2)
{
	uint8_t extendedDataLen = 26+sizeof(uint32_t);
	uint8_t extData[26+sizeof(uint32_t)];
	memset(extData, 0, 26+sizeof(uint32_t));
	string str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0:0:0 ", str);
	memset(extData+sizeof(uint32_t)+21, 17, 5);
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Random ID. IPv6 Address: 0:0:0:0:0:0011:1111:1111 ", str);
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayNetworkAdminIPv6ParamsEvent3)
{
	uint8_t extendedDataLen = 74+sizeof(uint32_t);
	uint8_t extData[74+sizeof(uint32_t)];
	memset(extData, 0, 74+sizeof(uint32_t));
	extData[sizeof(uint32_t)+1] = 1; //Intel ID
	//{"Random ID", "Intel ID", "Manual ID", "Invalid ID"};
	string str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Intel ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	extData[sizeof(uint32_t)+1] = 3; //Invalid ID
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Invalid ID. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	extData[sizeof(uint32_t)+1] = 4; //Unknown
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Unknown. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	extData[sizeof(uint32_t)+1] = 2; //Manual ID
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Manual ID. Interface ID: 0000000000000000. IPv6 Address: 0:0:0:0:0:0:0:0 Default Gateway: 0:0:0:0:0:0:0:0 Preferred DNS Server: 0:0:0:0:0:0:0:0 Alternate DNS Server: 0:0:0:0:0:0:0:0 ", str);
	memset(extData+sizeof(uint32_t)+2, 4, 72);
	str = DisplayNetworkAdminIPv6ParamsEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. IPv6 Disabled. Interface ID Type: Manual ID. Interface ID: 0404040404040404. IPv6 Address: 0404:0404:0404:0404:0404:0404:0404:0404 Default Gateway: 0404:0404:0404:0404:0404:0404:0404:0404 Preferred DNS Server: 0404:0404:0404:0404:0404:0404:0404:0404 Alternate DNS Server: 0404:0404:0404:0404:0404:0404:0404:0404 ", str);
}

/////// Uses PrintUint32
TEST_F(AuditLogAccessor, DisplayStorageAdminGlobalStorageAttributesSetEvent)
{
	uint8_t extendedDataLen = 2*sizeof(uint32_t);
	uint8_t extData[2*sizeof(uint32_t)];
	memset(extData, 0, 2*sizeof(uint32_t));
	string str = DisplayStorageAdminGlobalStorageAttributesSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Max Partner Storage: 0 byte(s) Max Non Partner Total Allocation Size: 0 byte(s) ", str);
	memset(extData, 43, 2*sizeof(uint32_t));
	str = DisplayStorageAdminGlobalStorageAttributesSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Max Partner Storage: 724249387 byte(s) Max Non Partner Total Allocation Size: 724249387 byte(s) ", str);
}

TEST_F(AuditLogAccessor, DisplayEventManagerAlertRelatedEvent1)
{
	uint8_t extendedDataLen = 23;
	uint8_t extData[23];
	memset(extData, 0, 23);
	string str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 0. Subscription Alert Type: Unknown. IP Address Type: IPv4. Alert Target IP Address: 0.0.0.0", str);
	extData[0] = 13;
	extData[1] = 1;
	str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 13. Subscription Alert Type: SNMP. IP Address Type: IPv4. Alert Target IP Address: 0.0.0.0", str);
	extData[1] = 2;
	str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 13. Subscription Alert Type: SOAP. IP Address Type: IPv4. Alert Target IP Address: 0.0.0.0", str);
}

TEST_F(AuditLogAccessor, DisplayEventManagerAlertRelatedEvent2)
{
	uint8_t extendedDataLen = 23;
	uint8_t extData[23];
	memset(extData, 0, 23);
	extData[1] = 1;
	extData[2] = 1;
	string str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 0. Subscription Alert Type: SNMP. IP Address Type: IPv6. Alert Target IP Address: 0:0:0:0:0:0:0:0", str);
	memset(extData+3*sizeof(uint8_t), 4, 16);
	str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 0. Subscription Alert Type: SNMP. IP Address Type: IPv6. Alert Target IP Address: 0404:0404:0404:0404:0404:0404:0404:0404", str);
	memset(extData+3*sizeof(uint8_t), 52, 16);
	str = DisplayEventManagerAlertRelatedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy ID: 0. Subscription Alert Type: SNMP. IP Address Type: IPv6. Alert Target IP Address: 3434:3434:3434:3434:3434:3434:3434:3434", str);
}


TEST_F(AuditLogAccessor, DisplayEventLogFrozenEvent)
{
	uint8_t extData[1];
	extData[0] = 54;
	string str = DisplayEventLogFrozenEvent(extData, 1);
	EXPECT_EQ("Unknown", str);
	extData[0] = 0;
	str = DisplayEventLogFrozenEvent(extData, 1);
	EXPECT_EQ(UNFREEZE_STRING, str);
	extData[0] = 1;
	str = DisplayEventLogFrozenEvent(extData, 1);
	EXPECT_EQ(FREEZE_STRING, str);
	str = DisplayEventLogFrozenEvent(extData, 0);
	EXPECT_EQ("", str);
}

/////// Uses PrintUint32
TEST_F(AuditLogAccessor, DisplayCircuitBreakerFilterRemovedEvent)
{
	uint8_t extendedDataLen = sizeof(uint32_t);
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 0, sizeof(uint32_t));
	string str = DisplayCircuitBreakerFilterRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ("Filter Handle: 0 ", str);
	memset(extData, 43, sizeof(uint32_t));
	str = DisplayCircuitBreakerFilterRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ("Filter Handle: 724249387 ", str);
	str = DisplayCircuitBreakerFilterRemovedEvent(extData, extendedDataLen-1);
	EXPECT_EQ("", str);
}

/////// Uses PrintUint32
TEST_F(AuditLogAccessor, DisplayCircuitBreakerPolicyRemovedEvent)
{
	uint8_t extendedDataLen = sizeof(uint32_t);
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 0, sizeof(uint32_t));
	string str = DisplayCircuitBreakerPolicyRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy Handle: 0 ", str);
	memset(extData, 43, sizeof(uint32_t));
	str = DisplayCircuitBreakerPolicyRemovedEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy Handle: 724249387 ", str);
	str = DisplayCircuitBreakerPolicyRemovedEvent(extData, extendedDataLen-1);
	EXPECT_EQ("", str);
}

/////// Uses PrintUint32 and PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayCircuitBreakerDefaultPolicySetEvent)
{
	uint8_t extendedDataLen = 2*sizeof(uint32_t);
	uint8_t extData[2*sizeof(uint32_t)];
	memset(extData, 0, 2*sizeof(uint32_t));
	string str = DisplayCircuitBreakerDefaultPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy Handle: 0 ", str);
	memset(extData+sizeof(uint32_t)*sizeof(uint8_t), 43, sizeof(uint32_t));
	str = DisplayCircuitBreakerDefaultPolicySetEvent(extData, extendedDataLen);
	EXPECT_EQ("Policy Handle: 724249387 ", str);
	str = DisplayCircuitBreakerDefaultPolicySetEvent(extData, extendedDataLen-1);
	EXPECT_EQ("Network Interface: LAN ", str);
}

/////// Uses PrintUint32 and PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayCircuitBreakerHeuristicsOptionSetEvent)
{
	uint8_t extendedDataLen = 2*sizeof(uint32_t)+2;
	uint8_t extData[2*sizeof(uint32_t)+2];
	memset(extData, 0, 2*sizeof(uint32_t)+2);
	string str = DisplayCircuitBreakerHeuristicsOptionSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: LAN. Block All: false. Block Offensive Port: false. Policy Handle: 0 ", str);
	str = DisplayCircuitBreakerHeuristicsOptionSetEvent(extData, extendedDataLen-1);
	EXPECT_EQ("Network Interface: LAN. Block All: false. Block Offensive Port: false. ", str);
	memset(extData, 1, 2*sizeof(uint32_t)+2);
	str = DisplayCircuitBreakerHeuristicsOptionSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: Unknown. Block All: true. Block Offensive Port: true. Policy Handle: 16843009 ", str);
	memset(extData, 43, 2*sizeof(uint32_t)+2);
	str = DisplayCircuitBreakerHeuristicsOptionSetEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: Unknown. Block All: true. Block Offensive Port: true. Policy Handle: 724249387 ", str);
}

/////// Uses PrintInterfaceHandleUint32
TEST_F(AuditLogAccessor, DisplayCircuitBreakerHeuristicsStateClearedEvent)
{
	uint8_t extData[sizeof(uint32_t)];
	memset(extData, 0, sizeof(uint32_t));
	extData[sizeof(uint32_t)-1] = 1; //WLAN
	uint8_t extendedDataLen = sizeof(uint32_t);
	string str = DisplayCircuitBreakerHeuristicsStateClearedEvent(extData, extendedDataLen);
	EXPECT_EQ("Network Interface: WLAN", str);
	str = DisplayCircuitBreakerHeuristicsStateClearedEvent(extData, extendedDataLen-1);
	EXPECT_EQ("", str);
}

/////// Uses DisplayAgentID and PrintUint16
TEST_F(AuditLogAccessor, DisplayAgentPresenceAgentWatchdogAddedEvent)
{
	uint8_t extendedDataLen = AGENT_ID_LEN+2*sizeof(uint16_t);
	uint8_t extData[AGENT_ID_LEN+2*sizeof(uint16_t)];
	memset(extData, 0, extendedDataLen);
	string str = DisplayAgentPresenceAgentWatchdogAddedEvent(extData, extendedDataLen);
	EXPECT_EQ("Agent ID: 0000-0000-0000-0000. Agent heart beat time: 0 seconds. Agent startup time: 0 seconds. ", str);
	str = DisplayAgentPresenceAgentWatchdogAddedEvent(extData, extendedDataLen-1);
	EXPECT_EQ("Agent ID: 0000-0000-0000-0000. Agent heart beat time: 0 seconds. ", str);
	memset(extData, 73, extendedDataLen);
	str = DisplayAgentPresenceAgentWatchdogAddedEvent(extData, extendedDataLen);
	EXPECT_EQ("Agent ID: 73737373-73737373-73737373-73737373. Agent heart beat time: 18761 seconds. Agent startup time: 18761 seconds. ", str);
}

/////// Uses DisplayAgentID
TEST_F(AuditLogAccessor, DisplayAgentPresenceAgentWatchdogRemovedEvent)
{
	uint8_t extData[AGENT_ID_LEN];
	memset(extData, 0, AGENT_ID_LEN);
	string str = DisplayAgentPresenceAgentWatchdogRemovedEvent(extData, AGENT_ID_LEN);
	EXPECT_EQ("Agent ID: 0000-0000-0000-0000. ", str);
	str = DisplayAgentPresenceAgentWatchdogRemovedEvent(extData, AGENT_ID_LEN-1);
	EXPECT_EQ("", str);
	memset(extData, 73, AGENT_ID_LEN);
	str = DisplayAgentPresenceAgentWatchdogRemovedEvent(extData, AGENT_ID_LEN);
	EXPECT_EQ("Agent ID: 73737373-73737373-73737373-73737373. ", str);
}

/////// Uses DisplayAgentID
TEST_F(AuditLogAccessor, DisplayAgentPresenceAgentWatchdogActionSetEvent)
{
	uint8_t extData[AGENT_ID_LEN];
	memset(extData, 0, AGENT_ID_LEN);
	string str = DisplayAgentPresenceAgentWatchdogActionSetEvent(extData, AGENT_ID_LEN);
	EXPECT_EQ("Agent ID: 0000-0000-0000-0000. ", str);
	str = DisplayAgentPresenceAgentWatchdogActionSetEvent(extData, AGENT_ID_LEN-1);
	EXPECT_EQ("", str);
	memset(extData, 73, AGENT_ID_LEN);
	str = DisplayAgentPresenceAgentWatchdogActionSetEvent(extData, AGENT_ID_LEN);
	EXPECT_EQ("Agent ID: 73737373-73737373-73737373-73737373. ", str);
}

/////// Uses PrintUint32
TEST_F(AuditLogAccessor, DisplayWirelessProfileLinkPreferenceChanged)
{
	uint8_t extendedDataLen = 2*sizeof(uint32_t);
	uint8_t extData[2*sizeof(uint32_t)];
	memset(extData, 0, 2*sizeof(uint32_t));
	string str = DisplayWirelessProfileLinkPreferenceChanged(extData, extendedDataLen);
	EXPECT_EQ("Link preference was set to: Unknown. Timeout: 0 ", str);
	str = DisplayWirelessProfileLinkPreferenceChanged(extData, extendedDataLen-1);
	EXPECT_EQ("Link preference was set to: Unknown. ", str);
	extData[0] = 1;
	str = DisplayWirelessProfileLinkPreferenceChanged(extData, extendedDataLen);
	EXPECT_EQ("Link preference was set to: ME. Timeout: 0 ", str);
	extData[0] = 2;
	str = DisplayWirelessProfileLinkPreferenceChanged(extData, extendedDataLen);
	EXPECT_EQ("Link preference was set to: Host. Timeout: 0 ", str);
}

TEST_F(AuditLogAccessor, DisplayEacSetOptionsEvent)
{
	uint8_t extendedDataLen = sizeof(uint32_t);
	uint8_t extData[sizeof(uint32_t)];
	string str = DisplayEacSetOptionsEvent(extData, extendedDataLen-1);
	EXPECT_EQ("", str);
	memset(extData, 0, sizeof(uint32_t));
	str = DisplayEacSetOptionsEvent(extData, extendedDataLen);
	EXPECT_EQ("Eac Vendors: Unknown", str);
	extData[sizeof(uint32_t)-1] = NUMBER_OF_EAC_VENDOR_STRINGS;
	str = DisplayEacSetOptionsEvent(extData, extendedDataLen);
	EXPECT_EQ("", str);
	extData[sizeof(uint32_t)-1] = NUMBER_OF_EAC_VENDOR_STRINGS-1;
	str = DisplayEacSetOptionsEvent(extData, extendedDataLen);
	EXPECT_EQ("Eac Vendors: EAC NAC and NAP", str);
}

/////// Uses PrintOptInPolicy
TEST_F(AuditLogAccessor, DisplayOptInPolicyChangeEvent)
{
	uint8_t extData[2];
	extData[0] = 1;
	extData[1] = 2;
	string str = DisplayOptInPolicyChangeEvent(extData, 0);
	EXPECT_EQ("", str);
	str = DisplayOptInPolicyChangeEvent(extData, 1);
	EXPECT_EQ("Previous Opt In Policy: KVM", str);
	str = DisplayOptInPolicyChangeEvent(extData, 2);
	EXPECT_EQ("Previous Opt In Policy: KVM Current Opt In Policy: ALL", str);
}

TEST_F(AuditLogAccessor, DisplaySendConsentCodeEvent)
{
	uint8_t extData[1];
	extData[0] = 0;
	string str = DisplaySendConsentCodeEvent(extData, 0);
	EXPECT_EQ("", str);
	stringstream ss, ss1;
	ss << "Operation Status: " << SUCCESSFUL_PASSWORD_STRING;
	ss1 << "Operation Status: " << UNSUCCESSFUL_PASSWORD_STRING;
	str = DisplaySendConsentCodeEvent(extData, 1);
	EXPECT_EQ(ss.str(), str);
	extData[0] = 1;
	str = DisplaySendConsentCodeEvent(extData, 1);
	EXPECT_EQ(ss1.str(), str);
}

TEST_F(AuditLogAccessor, DisplayUnknownEvent)
{
	uint8_t extData[6];
	memset(extData, 11, 6);
	string str = DisplayUnknownEvent(extData, 0);
	EXPECT_EQ("Unknown Event: Length = 0. Data =. ", str);
	str = DisplayUnknownEvent(extData, 6);
	EXPECT_EQ("Unknown Event: Length = 6. Data = B B B B B B. ", str);
	memset(extData, 34, 6);
	str = DisplayUnknownEvent(extData, 6);
	EXPECT_EQ("Unknown Event: Length = 6. Data = 22 22 22 22 22 22. ", str);
}

TEST_F(AuditLogAccessor, ReverseMemCopy0)
{
	uint8_t data[4];
	memset(data, 0, 4);
	data[3] = 1;
	uint32_t *pvalue = new uint32_t();
	if (pvalue)
	{
		ReverseMemCopy(pvalue, data, 4);
		EXPECT_EQ(*pvalue, 1);
		delete pvalue;
	}
}

TEST_F(AuditLogAccessor, ReverseMemCopy1)
{
	uint8_t data[22] = "txet desrever si sihT";
	uint8_t rev[23];
	memset(rev, 0, 23);
	ReverseMemCopy(rev, data, 0);
	for (int k=1; k<=21; k++)
	{
		EXPECT_EQ(rev[k], 0);
	}
	ReverseMemCopy(rev, data, 22);
	rev[0] = ' ';
	for (int k=1; k<=21; k++)
	{
		EXPECT_EQ(rev[k], data[21-k]);
	}
}



/*
	std::string DisplaySecurityAdminPowerPackageModifiedEvent(uint8_t* extData, uint8_t extendedDataLen); Need to implement with mock
*/



//TEST(AuditLogWSManClient, ParseLogs)
//{
//	string parsedRecords;
//	using namespace Intel::Manageability::Cim::Typed;
//	AuditLogWSManClient client;	
//	vector<BinaryData> records;	
//	vector<Base64> base64Records;
//	
//	try 
//	{
//		ASSERT_TRUE(client.readLogsFromFW(base64Records));
//		unsigned char* tmpData;
//		unsigned int tmpLength;
//		for(unsigned int i=0; i<base64Records.size(); i++)
//		{
//			tmpData = const_cast<unsigned char*>(base64Records.at(i).Data());
//			tmpLength = base64Records.at(i).Length();
//			records.push_back(BinaryData(tmpData, tmpLength));
//		}
//		ASSERT_TRUE(client.parseLogs (parsedRecords, records));
//	} 
//	catch (...) 
//	{
//		FAIL();
//	}
//}
