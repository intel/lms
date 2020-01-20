/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: BaseWSManClient.cpp

--*/

#include "BaseWSManClient.h"
#include "CryptUtils_w.h"
#include "global.h"
#include "CimOpenWsmanClient.h"
#include "MEIClientException.h"
#include "AMTHIErrorException.h"
#include "GetLocalSystemAccountCommand.h"

const std::string BaseWSManClient::DEFAULT_USER = "$$uns";
const std::string BaseWSManClient::DEFAULT_PASS = "$$uns";

//************************************************************************
// Default Constructor.
//************************************************************************
BaseWSManClient::BaseWSManClient() : m_defaultUser(DEFAULT_USER), m_defaultPass(DEFAULT_PASS)
{
	Init();
}

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
	m_endpoint = false; // Endpoint not resolved yet.
	m_client.reset();
}

//************************************************************************
// Name			: SetEndpoint.
// Description	: Set soap endpoint  	
//************************************************************************
int BaseWSManClient::SetEndpoint()
{
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

	namespace MEIClient = Intel::MEI_Client;

	try 
	{
		MEIClient::AMTHI_Client::GetLocalSystemAccountCommand getLocalSystemAccountCommand;
		MEIClient::AMTHI_Client::GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE response = getLocalSystemAccountCommand.getResponse();
		user = response.UserName;
		password = WSmanCrypt::EncryptString(response.Password); //EncryptString will empty response.Password
		rc= true;	
	}
	catch (MEIClient::AMTHI_Client::AMTHIErrorException& e)
	{
		unsigned int errNo =  e.getErr();
		UNS_ERROR("GetLocalSystemAccountCommand failed ret=%d\n", errNo);
	}
	catch (MEIClient::MEIClientException& e)
	{
		const char* reason = e.what();
		UNS_ERROR("GetLocalSystemAccountCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		const char* reason =  e.what();
		UNS_ERROR("Exception in GetLocalSystemAccountCommand %C\n", reason);
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
	UNS_DEBUG("BaseWSManClient::WsmanInitializer::WsmanInitializer()\n");
	//generate instances of singletons (generation in first function call is not thread-safe)
	BaseWSManClient::WsManSemaphore();
	BaseWSManClient::CtorSemaphore();
}

BaseWSManClient::WsmanInitializer BaseWSManClient::WsmanInitializer::initializer;