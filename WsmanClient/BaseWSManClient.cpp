/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: BaseWSManClient.cpp

--*/
#define _CRT_SECURE_NO_WARNINGS
#include "BaseWSManClient.h"
#include "CryptUtils_w.h"
#include "UNSDebug.h"
#include "CimOpenWsmanClient.h"
#include "MEIClientException.h"
#include "AMTHIErrorException.h"
#include "GetLocalSystemAccountCommand.h"
#include "CryptUtils_w.h"

#ifdef _WIN32
#include <iphlpapi.h>
#else
#include <netdb.h>
#include <unistd.h>
#include <limits.h>
#endif

#include <string>

#define WSMAN_PATH           "/wsman"
#define WSMAN_HTTPS_SCHEME   "https"
#define WSMAN_HTTP_SCHEME    "http"
#define WSMAN_AUTH_DIGEST    "digest"

//************************************************************************
// Default Constructor.
//************************************************************************
BaseWSManClient::BaseWSManClient(const std::string &defaultUser, 
								 const std::string &defaultPass):
	m_defaultUser(defaultUser),
	m_defaultPass(defaultPass)
{
	Init();
}

//************************************************************************
// Name			: BaseWSManClient
// Description	: Destructor.
//************************************************************************
BaseWSManClient::~BaseWSManClient()
{		
	
}


//************************************************************************
// Name:		BaseWSManClient::Init
// Description: Get AMT FQDN, and set wsman endpoint.
//************************************************************************
void BaseWSManClient::Init()	
{
	m_ip = "localhost";

	if ((m_defaultUser.empty()) || (m_defaultUser == "$$uns"))
	{
		GetLocalSystemAccount(m_defaultUser,m_defaultPass);
	}
	
	// Init some flags.
	m_endpoint   = false; // Endpoint not resolved yet.
	m_client.reset();
}

//************************************************************************
// Name			: SetEndpoint.
// Description	: Set soap endpoint  	
//************************************************************************
int BaseWSManClient::SetEndpoint(bool secure)
{
	int status;
	std::string fqdn;

	// Get FQDN of local host
	if (m_fqdn.empty() && secure)
	{
		// First try to get the FQDN from the hosts file.
		status = FindHostsFileFQDN(fqdn);
		// If FQDN wasn't found, try to get the local host FQDN.
		if (status != 1) {
			status = GetNetworkFQDN(fqdn);
		}

		// IF both failed return ERROR.
		if (status != 1)
		{
			return WSMAN_STATUS_SUBSCRIPTION_ERROR;
		}
		m_fqdn = fqdn;
	}

	//Lock WsMan to prevent reentry
	std::lock_guard<std::mutex> lock(WsManSemaphore());
		
	m_client.reset(new Intel::WSManagement::CimOpenWsmanClient(m_ip,
									  AMT_NON_SECURE_PORT,
									  false,
									  Intel::WSManagement::DIGEST,
									  m_defaultUser,
									  GetPassword()));	//In CIMFramework we will decrypt the password.

	return WSMAN_STATUS_SUCCESS;
}


//************************************************************************
// Name			: FindHostsFileFQDN 
// Description	: Find the LMS inserted FQDN in the hosts file.
// Params		: fqdn - A pointer to a buffer at least FQDN_MAX_SIZE in length
//
// Returns		: 1 if FQDN was found (it is placed in @fqdn)
//		          0 if FQDN wasn't found
//				  < 0 on error.
//************************************************************************
int	BaseWSManClient::FindHostsFileFQDN (std::string& fqdn)
{
	const char *sig = "# LMS GENERATED LINE";
	bool hasFqdn = false;
#ifdef _WIN32
	const char *dir = "\\system32\\drivers\\etc\\";
	const char *hostFile = "hosts";

	auto sysDrive = getenv("SystemRoot");
	if (sysDrive == NULL) {
		// Can't find hosts file
		return -1;
	}
	std::string inFileName(sysDrive);
	inFileName.append(dir);
	inFileName.append(hostFile);
	
#else
	std::string inFileName("/etc/hosts");
#endif

	FILE *ifp = fopen(inFileName.c_str(), "r");
	if (ifp == NULL) {
		// Can't open hosts file
		return -1;
	}

	char line[1024];

	// Go over each line and check for LMS signature
	while (fgets(line, sizeof(line), ifp)) {
		if (strstr(line, sig) != NULL) {
			char tmpFqdn[FQDN_MAX_SIZE + 1];

			memset(tmpFqdn, 0, sizeof(tmpFqdn));

			if (sscanf(line, "127.0.0.1       %256s #", tmpFqdn) == 1) {
				fqdn = std::string(tmpFqdn);
				hasFqdn = true;
				break;
			}


			// Badly formatted line, even though it has LMS sig; ignore it.
		}
	}

	fclose(ifp);

	return (hasFqdn) ? 1 : 0;
}

//************************************************************************
// Name			: GetNetworkFQDN.
// Description	: Use the GetNetworkParams to query the local fqdn.
// Params		: fqdn - A pointer to a buffer at least FQDN_MAX_SIZE in length
// Returns		: 1 if FQDN was found (it is placed in @fqdn)
//		          <= 0 on error        
//************************************************************************
int	BaseWSManClient::GetNetworkFQDN(std::string& fqdn)
{
#ifdef _WIN32
	FIXED_INFO *FixedInfo;
	ULONG		ulOutBufLen;
	DWORD		dwRetVal;


	// Allocate memory.
	FixedInfo	= (FIXED_INFO *) GlobalAlloc( GPTR, sizeof( FIXED_INFO ) );
	ulOutBufLen = sizeof( FIXED_INFO );

	// If GetNetworkParams returns ERROR_BUFFER_OVERFLOW, realloc the required memory.
	if( ERROR_BUFFER_OVERFLOW == GetNetworkParams( FixedInfo, &ulOutBufLen ) ) {
		GlobalFree( FixedInfo );
		FixedInfo = (FIXED_INFO *) GlobalAlloc( GPTR, ulOutBufLen );
	}
	dwRetVal = GetNetworkParams( FixedInfo, &ulOutBufLen );
	if ( dwRetVal ) {
		DbgPrint("Call to GetNetworkParams failed. Return Value: %08x\n", dwRetVal );
		GlobalFree( FixedInfo );

		return -1;
	}

	if ((strlen(FixedInfo -> HostName) + strlen(FixedInfo -> DomainName) + 2) > FQDN_MAX_SIZE){
		DbgPrint("FQDN too long: %s.%s\n",  FixedInfo -> HostName, FixedInfo -> DomainName);
		GlobalFree( FixedInfo );
		return -1;
	}
	std::string s_fqdn(FixedInfo -> HostName);
	s_fqdn.append(".");
	s_fqdn.append(FixedInfo -> DomainName);
	fqdn = s_fqdn;
	GlobalFree( FixedInfo );
#else // LINUX
	char hostname[HOST_NAME_MAX];
	if (gethostname(hostname, HOST_NAME_MAX) != 0) {
		return -1;
	}
	struct hostent *ent = gethostbyname(hostname);
	if (ent == NULL) {
		return -1;
	}
	fqdn = std::string(ent->h_name);
#endif
	return 1;	
}



//************************************************************************
// Name			: GetPassword.
// Description	: Return encrypted password
// Returns		: encrypted password in string class
//************************************************************************
std::string BaseWSManClient::GetPassword()
{
	return m_defaultPass;
}


bool BaseWSManClient::GetLocalSystemAccount(std::string& user, std::string& password)
{
	bool rc=false;
	using namespace Intel::MEI_Client::AMTHI_Client;
	using namespace Intel::MEI_Client; 

	try 
	{
		GetLocalSystemAccountCommand getLocalSystemAccountCommand;
		GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE response = getLocalSystemAccountCommand.getResponse();
		user = response.UserName;
		password = WSmanCrypt::EncryptString(response.Password); //EncryptString will empty response.Password
		rc= true;	
	}
	catch (MEIClientException& e)
	{	
		const char* reason =  e.what();
		DbgPrint("GetLocalSystemAccountCommand failed %s\n",e.what());
	}
	catch (AMTHIErrorException& e)
	{
		unsigned int errNo =  e.getErr();
		DbgPrint("GetLocalSystemAccountCommand failed ret=%d\n", errNo);
	}
	catch (std::exception& e)
	{
		const char* reason =  e.what();
		DbgPrint("\nException in GetLocalSystemAccountCommand %s\n", reason);
	}
	return rc;
}

std::mutex& BaseWSManClient::WsManSemaphore()
{  
	static std::mutex wsmanSemaphore;
	return wsmanSemaphore;
}

std::mutex& BaseWSManClient::CtorSemaphore()
{
	static std::mutex ctorSemaphore;
	return ctorSemaphore;
}

BaseWSManClient::Locker::Locker()
{
	BaseWSManClient::CtorSemaphore().lock();
}

BaseWSManClient::Unlocker::Unlocker()
{
	BaseWSManClient::CtorSemaphore().unlock();
}

//--
BaseWSManClient::WsmanInitializer::WsmanInitializer()
{
	DbgPrint("BaseWSManClient::WsmanInitializer::WsmanInitializer()");
	//generate instances of singletons (generation in first function call is not thread-safe)
	BaseWSManClient::WsManSemaphore();
	BaseWSManClient::CtorSemaphore();
	//Intel::Manageability::Cim::Untyped::CimSerializer::GetSerializer(); 
}

BaseWSManClient::WsmanInitializer BaseWSManClient::WsmanInitializer::initializer;
