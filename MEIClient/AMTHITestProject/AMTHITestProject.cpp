/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
// AMTHITestProject.cpp : main project file.

#include "AMTHICommand.h"
#include "MEIClientException.h"
#include "HECIException.h"

#include "gtest/gtest.h"

#include "CloseUserInitiatedConnectionCommand.h"
#include "EnumerateHashHandlesCommand.h"
#include "GetAMTStateCommand.h"
#include "GetCertificateHashEntryCommand.h"
#include "GetCodeVersionCommand.h"
#include "GetConfigServerDataCommand.h"
#include "GetCurrentPowerPolicyCommand.h"
#include "GetDNSSuffixCommand.h"
#include "GetEACStateCommand.h"
#include "GetFQDNCommand.h"
#include "GetIPv6LanInterfaceStatusCommand.h"
#include "GetKVMSessionStateCommand.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "GetLastHostResetReasonCommand.h"
#include "GetLocalSystemAccountCommand.h"
#include "GetProvisioningStateCommand.h"
#include "GetRedirectionSessionsStateCommand.h"
#include "GetRedirectionStateCommand.h"
#include "GetRemoteAccessConnectionStatusCommand.h"
#include "GetSecurityParametersCommand.h"
#include "GetSystemDefenseStateCommand.h"
#include "GetTcpipParametersCommand.h"
#include "GetUserInitiatedEnabledInterfacesCommand.h"
#include "GetUUIDCommand.h"
#include "GetWebUIStateCommand.h"
#include "GetZeroTouchEnabledCommand.h"
#include "OpenUserInitiatedConnectionCommand.h"
#include "UnprovisionCommand.h"

#include "GetPlatformTypeCommand.h"
#include "GetFWUpdateStateCommand.h"

#include "GetDNSSuffixListCommand.h"
#include "GetMESetupAuditRecordCommand.h"
#include "SetEnterpriseAccessCommand.h"
#include "SetHostFQDNCommand.h"

#include "ReadFileExCommand.h"

#include "GetUPIDFeatureSupportCommand.h"
#include "GetUPIDFeatureOSControlCommand.h"

#include "MNGIsChangeToAMTEnabledCommand.h"

#include "MEIparser.h"

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#ifdef __linux__
	#include <netinet/ip.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
#endif // __linux__

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::endl;
using std::hex;
using std::dec;
using namespace Intel::MEI_Client::AMTHI_Client;
using namespace Intel::MEI_Client::MKHI_Client;
using namespace Intel::MEI_Client::UPID_Client;

TEST(instantiate, testOpenAndCloseUserInitiatedConnectionCommand)
{
	try {
		OpenUserInitiatedConnectionCommand connection;
	}
	catch (const AMTHIErrorException &ex) {
		if ((ex.getErr() == AMT_STATUS_INVALID_PT_MODE) ||
		    (ex.getErr() == AMT_STATUS_NOT_PERMITTED) ||
		    (ex.getErr() == AMT_STATUS_NOT_READY))
			return;
		FAIL() << "OpenUserInitiatedConnectionCommand AMTHIErrorException with error " << ex.getErr();
	}
	EXPECT_NO_THROW(
		CloseUserInitiatedConnectionCommand connection;
	);
}

string dateToString(TIME_DATE dt) {
	string str;
	stringstream s(str);
	s << dt.Day << "/" << dt.Month << "/" << dt.Year << " " << dt.Hour << ":" << dt.Minute << ":" << dt.Second ;
	return s.str();
}

TEST(instantiate, testGetAMTStateCommand)
{
	EXPECT_NO_THROW(
		GetAMTStateCommand amtState(AMT_UUID_LINK_STATE);
		AMT_STATE_RESPONSE re = amtState.getResponse();
		cout << re.StateDataIdentifier.amt_uuid << endl;
		cout << re.StateData.data << endl;
	);
}



TEST(instantiate, testGetCodeVersionCommand) 
{
	EXPECT_NO_THROW(
		GetCodeVersionCommand codeVersionCommand;
		CODE_VERSIONS codeVersion = codeVersionCommand.getResponse();
		cout << "code version: \n" << "bios version: "; 
		for (int i =0; i < BIOS_VERSION_LEN; i++){
			cout << codeVersion.BiosVersion[i];
		}
		cout << "\nversions: ";
		for (vector<AMT_VERSION_TYPE>::iterator it = codeVersion.Versions.begin(); it != 
			codeVersion.Versions.end(); it++) 
		{
			cout << it->Description << " " << it->Version << endl;
		}
	);
}



TEST(instantiate, testGetConfigServerDataCommand)
{
	EXPECT_NO_THROW(
		GetConfigServerDataCommand csdc;
		CFG_GET_CONFIG_SERVER_DATA_RESPONSE re = csdc.getResponse();

		cout<<"test_GetConfigServerDataCommand " << endl;
		cout<<"---------------------------------" << endl;
		cout<<"Server port is : " << re.ServerPort << endl;
		cout<<"Server address is : " << re.ServerAddr << endl;
		cout<<"Server FQDN is : " << re.FQDN << endl;
		
		cout<<endl;
	);
}

TEST(instantiate, testGetCurrentPowerPolicyCommand){
	EXPECT_NO_THROW(
		GetCurrentPowerPolicyCommand powerPolicy;
		string str = powerPolicy.getResponse();
		cout << "Current Power Policy: " << endl;
		cout << str << endl << endl;
	);
}

TEST(instantiate, testGetDnsSuffixCommand) {
	std::string dnsSuffix;
	EXPECT_NO_THROW(
		GetDNSSuffixCommand getDnsSuffixCommand;
		dnsSuffix = getDnsSuffixCommand.getResponse();
		cout << std::endl << "DNS suffix: " << dnsSuffix << std::endl;
	);
}

TEST(instantiate, testGetEACStateCommand){
	EXPECT_NO_THROW(
		GetEACStateCommand eac;
		GET_EAC_STATE_RESPONSE re = eac.getResponse();
		cout << "EAC: " << endl;
		cout << "Request Id: " << re.RequestId << endl;
		cout << "EAC enabled: " << re.EacEnabled << endl;
		cout << endl;
	);
}



TEST(instantiate, testGetFQDNCommand)
{
	string t[] = {"not",""};
	EXPECT_NO_THROW(
		GetFQDNCommand fc;
		cout<<"test_GetFQDNCommand "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"Domain name is "<<t[fc.getResponse().SharedFQDN]<<" shared"<<endl;
		cout<<"Dynamic DNS update is "<<t[fc.getResponse().DDNSUpdateEnabled]<<" enabled"<<endl;
		cout<<"Periodic update interval is : "<<dec<<fc.getResponse().DDNSPeriodicUpdateInterval<<endl;
		cout<<"TTL for RRs is : "<<fc.getResponse().DDNSTTL<<endl;
		cout<<"Host name length is : "<<fc.getResponse().HostNameLength<<endl;
		cout<<"FQDN is : "<<fc.getResponse().FQDN<<endl;
		cout<<endl;
	);
}

TEST(instantiate, testGetIPv6LanInterfaceStatusCommand)
{
	try {
		GetIPv6LanInterfaceStatusCommand gi6c((uint32_t)/*INTERFACE_SETTINGS::*/WIRED);
		
		cout<<"test_GetIPv6LanInterfaceStatusCommand((uint32_t)INTERFACE_SETTINGS::WIRED) "<<endl;
		cout<<"---------------------------------"<<endl;

		cout<<"IPv6DefaultRouter is : "<<gi6c.getResponse().IPv6DefaultRouter<<endl;
		cout<<"PrimaryDNS is : "<<gi6c.getResponse().PrimaryDNS<<endl;
		cout<<"SecondaryDNS is : "<<gi6c.getResponse().SecondaryDNS<<endl;

		for (unsigned int i =0; i<gi6c.getResponse().IPv6Addresses.size(); ++i)
		{
			cout<<"Address #"<<i<<" is : "<<gi6c.getResponse().IPv6Addresses[i].Address;
			cout<<" state : "<<gi6c.getResponse().IPv6Addresses[i].State<<" type : "<<gi6c.getResponse().IPv6Addresses[i].Type<<endl;
		}

		cout<<endl;
	}
	catch (const AMTHIErrorException &ex) {
		if (ex.getErr() != AMT_STATUS_IPV6_INTERFACE_DISABLED)
			FAIL() << "AMTHIErrorException with error " << ex.getErr();
	}
}



TEST(instantiate, testGetKVMSessionStateCommand){
	EXPECT_NO_THROW(
		GetKVMSessionStateCommand kvm;
		GET_KVM_SESSION_STATE_RESPONSE re = kvm.getResponse();
		cout << "KVM Session: " << endl;
		cout << "Request Id: " << re.RequestId << endl;
		cout << "Is KVM session active: " << re.kvmStatus.KvmSessionIsActive << endl;
		cout << "Reserved: " << re.kvmStatus.Reserved << endl;
		cout << "Wait for opt: " << re.kvmStatus.WaitForOpt << endl;
		cout << endl;
	);
}



TEST(instantiate, testGetLanInterfaceSettingsCommand)
{
	EXPECT_NO_THROW(
		GetLanInterfaceSettingsCommand lanCommand(WIRED);
		LAN_SETTINGS lanSettings = lanCommand.getResponse();
		cout << "\nlan settings: \nenabled: " << lanSettings.Enabled << "\nIpv4 Address: ";
		int ip4 = lanSettings.Ipv4Address % 256;
		int ip3 = lanSettings.Ipv4Address / 256 % 256;
		int ip2 = lanSettings.Ipv4Address / (256*256) % 256;
		int ip1 = lanSettings.Ipv4Address / (256*256*256) % 256;
		cout  << ip1 << "." << ip2 << "." << ip3 << "." << ip4;
		cout << "\nDhcp Enabled: " << lanSettings.DhcpEnabled ;
		cout << "\nDhcp Ip Mode: " << (int)lanSettings.DhcpIpMode << "\nLinkStatus: " << (int)lanSettings.LinkStatus << "\nMacAddress: ";
		for (int i = 0 ; i < 6; i++){
			cout << ((i != 0) ? ":" : " ") << hex << (int) lanSettings.MacAddress[i];
		}
		cout << endl;
	);
}



TEST(instantiate, testLastHostResetReasonCommand)
{
	EXPECT_NO_THROW(
		GetLastHostResetReasonCommand lastReset;
		LAST_HOST_RESET_REASON_RESPONSE re = lastReset.getResponse();
		cout << "Last Host Reset Reason Command" << endl << endl;
		cout << "The reason: ";
		if (re.Reason==0){
			cout << "Remote Control Reset" << endl;	
		}
		else{
			cout << "Other than Remote Control" << endl;	
		}
		cout << "Time of reset (seconds since 1/1/1970): " << re.RemoteControlTimeStamp << endl << endl;
	);
}



TEST(instantiate, testGetLocalSystemAcountCommand)
{
	EXPECT_NO_THROW(
		GetLocalSystemAccountCommand sac;

		cout<<"test_GetLocalSystemAcountCommand "<<endl;
		cout<<"---------------------------------"<<endl;
		
		cout<<"Name : "<<sac.getResponse().UserName<<endl;
		cout<<"Password : "<<sac.getResponse().Password<<endl;
		cout<<endl;
	);
}

TEST(instantiate, testGetProvisioningStateCommand) 
{
	EXPECT_NO_THROW(
		GetProvisioningStateCommand provisioningStateCommand;
		CFG_PROVISIONING_STATE stateMode = provisioningStateCommand.getResponse();
		cout << "\nProvisioning State: " << stateMode.ProvisioningState;
		cout << endl;
	);
}

TEST(instantiate, testGetRedirectionSessionsStateCommand)
{
	EXPECT_NO_THROW(
		GetRedirectionSessionsStateCommand redir;
		GET_REDIRECTION_SESSIONS_STATE_RESPONSE re = redir.getResponse();

		cout << "Redirection Sessions: " << endl;
		cout << "Request Id: " << re.RequestId << endl;
		cout << "IderOpen: " << re.IderOpen << endl;
		cout << "Reserved: " << re.Reserved << endl;
		cout << "SolOpen: " << re.SolOpen << endl;
		cout << endl;
	);
}



TEST(instantiate, testGetRedirectionStateCommand)
{
	string c[] = {"disabled","enabled"};
	EXPECT_NO_THROW(
		GetRedirectionStateCommand rsc;
		cout<<"test_GetRedirectionCommand "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"SOL is "<<c[rsc.getResponse().SOLEnabled]<<endl;
		cout<<"IDER is "<<c[rsc.getResponse().IDEREnabled]<<endl;
		//TODO - problem : contradicts GetRedirectionCommand
		cout<<"KVM is "<<c[rsc.getResponse().KVMEnabled]<<endl;
		cout<<endl;
	);
}



TEST(instantiate, testGetRemoteAccessConnectionStatusCommand)
{
	EXPECT_NO_THROW(
		GetRemoteAccessConnectionStatusCommand remote;
		REMOTE_ACCESS_STATUS re = remote.getResponse();
		cout << "AMT Network Connection Status: " << re.AmtNetworkConnectionStatus << endl;
		cout << "Mps Hostname: " << re.MpsHostname << endl;
		cout << "Remote Access Connection Status: " << re.RemoteAccessConnectionStatus << endl;
		cout << "Remote Access Connection Trigger: " << re.RemoteAccessConnectionTrigger << endl;
	);
}

TEST(instantiate, testGetSecurityParametersCommand)
{
	string mode[] = {"SMB", "Enterprise"};
	string t[] = {"not",""};
	string pstate[] = {"PROVISIONING_STATE_PRE", "PROVISIONING_STATE_IN", "PROVISIONING_STATE_POST"};
	string link[] = {"down","up"};

	EXPECT_NO_THROW(
		GetSecurityParametersCommand spc;

		cout<<"test_GetSecurityParametersCommand "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"AMT mode is : "<<mode[spc.getResponse().EnterpriseMode]<<endl;
		cout<<"TLS is  "<<t[spc.getResponse().TLSEnabled]<<" enabled"<<endl;
		cout<<"Crypto fuse is  "<<t[spc.getResponse().HWCryptoEnabled]<<" burned"<<endl;
		cout<<"Provisioning state is : "<<pstate[spc.getResponse().ProvisioningState]<<endl;
		cout<<"Network interface is  "<<t[spc.getResponse().NetworkInterfaceEnabled]<<" enabled"<<endl;
		cout<<"SOL is "<<t[spc.getResponse().SOLEnabled]<<" enabled"<<endl;
		cout<<"IDER is "<<t[spc.getResponse().IDEREnabled]<<" enabled"<<endl;
		cout<<"FW update is "<<t[spc.getResponse().FWUpdateEnabled]<<" enabled (from AMT 7.0 should be always false)"<<endl;
		cout<<"Link is "<<link[spc.getResponse().LinkIsUp]<<endl;
		cout<<"KVM is "<<t[spc.getResponse().KvmEnabled]<<" enabled"<<endl;

		cout<<endl;
	);
}



TEST(instantiate, testGetSystemDefenseStateCommand)
{
	EXPECT_NO_THROW(
		GetSystemDefenseStateCommand defense;
		GET_SYSTEM_DEFENSE_STATE_RESPONSE re = defense.getResponse();
		cout << "System Defense: " << endl;
		cout << "Request Id: " << re.RequestId << endl;
		cout << "System Defense Activated: " << re.SystemDefenseActivated << endl;
		cout << endl;
	);
}



TEST(instantiate, testGetTcpipParametersCommand)
{
	
	string dc[] = {"CFG_DHCP_MODE_NONE", "CFG_DHCP_MODE_DISABLED", "CFG_DHCP_MODE_ENABLED"};

	EXPECT_NO_THROW(
		GetTcpipParametersCommand tpc;

		cout<<"test_GetTcpipParametersCommand "<<endl;
		cout<<"---------------------------------"<<endl;

		cout<<"DHCP mode is : "<<dc[tpc.getResponse().DhcpMode]<<endl;
		cout<<"Local Address is : "<<hex<<tpc.getResponse().LocalAddress<<endl;
		cout<<"Primary Dns Address is : "<<hex<<tpc.getResponse().PrimaryDnsAddress<<endl;
		cout<<"Secondary Dns Address is : "<<hex<<tpc.getResponse().SecondaryDnsAddress<<endl;
		cout<<"Subnet Mask is : "<<hex<<tpc.getResponse().SubnetMask<<endl;
		cout<<"Default Gateway Address is : "<<hex<<tpc.getResponse().DefaultGatewayAddress<<endl;
		cout<<"Domain Name  is : "<<tpc.getResponse().DomainName<<endl;

		cout<<endl;
	);
}



TEST(instantiate, testGetUserInitialEnabledInterfaceCommand)
{
	EXPECT_NO_THROW(
		GetUserInitiatedEnabledInterfacesCommand com;
		GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE res = com.getResponse();
		std::cout << "enabled interfaces Bios: " << res.EnabledInterfaces.Bios << std::endl;
		std::cout << "enabled interfaces OS_Agent: " << res.EnabledInterfaces.OS_Agent << std::endl;
		std::cout << "enabled interfaces reserved: " << res.EnabledInterfaces.reserved << std::endl;
	);
}



TEST(instantiate, testGetUUIDCommand)
{
	EXPECT_NO_THROW(
		GetUUIDCommand get;
		GET_UUID_RESPONSE res = get.getResponse();
		cout << "\ntestGetUUID";
		for (int i =0; i< 8 ; i++ ){
			cout << res.UUID[i];
		}
	);
}



TEST(instantiate, testGetWebUIStateCommand)
{
	EXPECT_NO_THROW(
		GetWebUIStateCommand webUI;
		GET_WEB_UI_STATE_RESPONSE re = webUI.getResponse();
		cout << "Web UI: " << endl;
		cout << "Request Id: " << re.RequestId << endl;
		cout << "Web UI enabled: " << re.WebUiEnabled << endl;
		cout << endl;
	);
}

TEST(instantiate, DISABLED_testUnprovisionCommand)
{
	try {
		UnprovisionCommand upc(CFG_PROVISIONING_MODE_NONE);
	}
	catch (const AMTHIErrorException &ex) {
		if (ex.getErr() != AMT_STATUS_INVALID_PT_MODE)
			FAIL() << "AMTHIErrorException with error " << ex.getErr();
	}
}


TEST(instantiate, testGetDNSSuffixListCommand)
{//TODO : how to test	
	try {
		GetDNSSuffixListCommand getDNSSuffixListCommand;
		vector<uint8_t> vect = getDNSSuffixListCommand.getResponse().HashHandles;
		cout << "DNS Suffixes: ";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << vect[i] << " ";
		cout << endl;
	}
	catch (const AMTHIErrorException &ex) {
		if (ex.getErr() != AMT_STATUS_INVALID_PT_MODE)
				FAIL() << "AMTHIErrorException with error " << ex.getErr();
	}
}


TEST(instantiate, testGetMESetupAuditRecordCommand)
{
	EXPECT_THROW( //we expect AMT_STATUS_DATA_MISSING
		GetMESetupAuditRecordCommand getMESetupAuditRecordCommand,AMTHIErrorException
	);
}


TEST(instantiate, testSetEnterpriseAccessCommand)
{
	unsigned long localIp = inet_addr("192.168.1.2");
	std::vector<uint8_t> HostIPAddress(Intel::MEI_Client::AMTHI_Client::HOST_IP_ADDRESS_SIZE);
	uint8_t *addr = reinterpret_cast<uint8_t*>(&localIp);
	std::copy_n(addr, sizeof(in_addr), HostIPAddress.begin());
	EXPECT_THROW( //we expect AMT_STATUS_REMOTE_ACCESS_HOST_VPN_IS_DISABLED/AMT_STATUS_SUCCESS_WITHOUT_DDNS/AMT_STATUS_SUCCESS_WITH_DDNS
		SetEnterpriseAccessCommand setEnterpriseAccessCommand(0, HostIPAddress, 1), AMTHIErrorException
	);
}

TEST(instantiate, testSetHostFQDNCommand)
{
	EXPECT_NO_THROW( 
		SetHostFQDNCommand setHostFQDNCommand("test.intel.com");
	);
}

TEST(MKHI, testGetPlatformTypeCommand)
{	
	EXPECT_NO_THROW(
		GetPlatformTypeCommand getPT;
		MKHI_PLATFORM_TYPE MKHIres = getPT.getResponse();
	);
}

TEST(MKHI, testGetFWUpdateStateCommand)
{
	GetFWUpdateStateCommand getPT;
	FW_UPDATE_STATE MKHIres = getPT.getResponse();
	EXPECT_LE((uint32_t)FW_UPDATE_DISABLED, MKHIres.Data);
	EXPECT_GE((uint32_t)FW_UPDATE_PASSWORD_PROTECTED, MKHIres.Data);
}

TEST(MCHI, testReadFileExCommand)
{
	try
	{
		Intel::MEI_Client::MCHI_Client::ReadFileExCommand readFileEx(Intel::MEI_Client::MCHI_Client::MCA_FILE_ID::SKU_MGR_QUALIFIED_BRAND_ENTITLEMENTS, 0, 4, 0);
		Intel::MEI_Client::MCHI_Client::READ_FILE_EX_RESPONSE theFile = readFileEx.getResponse();
		EXPECT_EQ(4, theFile.Data.size());
		std::cout << "SKU_MGR_QUALIFIED_BRAND_ENTITLEMENTS data " << std::hex << "0x" << (uint32_t)theFile.Data[0]
			<< " 0x" << (uint32_t)theFile.Data[1]
			<< " 0x" << (uint32_t)theFile.Data[2]
			<< " 0x" << (uint32_t)theFile.Data[3]
			<< std::endl;
	}
	catch (const Intel::MEI_Client::HeciNoClientException&) {}
	catch (const Intel::MEI_Client::MCHI_Client::MCHIErrorExceptionNoFile&) {}
}

TEST(UPID, testGetUPIDFeatureSupportCommand)
{
	try
	{
		GetUPIDFeatureSupportCommand getSupport;
		UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response support = getSupport.getResponse();
		EXPECT_EQ(support.platformIdSupported & ~(UPID_PLATFORM_ID_UPID_IS_SUPPORTED | UPID_PLATFORM_ID_ATTESTATION_IS_SUPPORTED), 0);
	}
	catch (const Intel::MEI_Client::HeciNoClientException&) {}
}

TEST(UPID, testGetUPIDFeatureOSControlCommand)
{
	try
	{
		GetUPIDFeatureOSControlCommand getOSControl;
		UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response support = getOSControl.getResponse();
	}
	catch (const Intel::MEI_Client::HeciNoClientException&) {}
}

TEST(Manageabiltiy, testMNGIsChangeToAMTEnabledCommand)
{
	Intel::MEI_Client::Manageability_Client::MNGIsChangeToAMTEnabledCommand cmd;
	Intel::MEI_Client::Manageability_Client::IsChangedEnabledResponse res = cmd.getResponse();
}

TEST(MEIParser,too_small_data)
{
	vector<uint8_t> vec(1,0);
	uint32_t data;
	vector<uint8_t>::const_iterator itr = vec.begin();
	EXPECT_THROW(Intel::MEI_Client::parseData(data,itr,vec.end()),Intel::MEI_Client::MEIClientException);
}

TEST(MEIParser,big_data)
{
	vector<uint8_t> vec(4,0);
	vec[0] = 1;
	vec[1] = 0;
	vector<uint8_t>::const_iterator itr = vec.begin();
	uint32_t data;
	EXPECT_NO_THROW(
		Intel::MEI_Client::parseData(data,itr,vec.end());
	EXPECT_EQ(data,1);

	);
}

TEST(AMTHIException, simple_output)
{
	try
	{
		throw AMTHIErrorException(1);
	}
	catch (const AMTHIErrorException &e)
	{
		std::cout << "AMTHIErrorException.what == " << e.what() << std::endl;
	}
}

TEST(MKHIException, simple_output)
{
	try
	{
		throw MKHIErrorException(1);
	}
	catch (const MKHIErrorException &e)
	{
		std::cout << "MKHIErrorException.what == " << e.what() << std::endl;
	}
}

TEST(MEIClientException, simple_output)
{
	try
	{
		throw Intel::MEI_Client::MEIClientException("some message here", 1);
	}
	catch (const Intel::MEI_Client::MEIClientException &e)
	{
		std::cout << "MEIClientException.what == " << e.what() << std::endl;
	}
}

int main(int argc, char** argv)
{  
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
