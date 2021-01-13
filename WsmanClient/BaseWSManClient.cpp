/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: BaseWSManClient.cpp

--*/

#include "BaseWSManClient.h"
#include "WsmanClientLog.h"
#include "CimOpenWsmanClient.h"
#include "MEIClientException.h"
#include "AMTHIErrorException.h"
#include "GetLocalSystemAccountCommand.h"

const std::string BaseWSManClient::DEFAULT_USER = "$$uns";

//************************************************************************
// Default Constructor.
//************************************************************************
BaseWSManClient::BaseWSManClient() : m_defaultUser(DEFAULT_USER)
{
	Init();
}

BaseWSManClient::BaseWSManClient(const std::string &defaultUser, 
								 const std::string &defaultPass):
	m_defaultUser(defaultUser),
	m_defaultPass(defaultPass.c_str())
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
		GetLocalSystemAccount();
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
									  m_defaultPass.Get()));

	return WSMAN_STATUS_SUCCESS;
}

bool BaseWSManClient::GetLocalSystemAccount()
{
	bool rc=false;

	namespace MEIClient = Intel::MEI_Client;

	try 
	{
		MEIClient::AMTHI_Client::GetLocalSystemAccountCommand getLocalSystemAccountCommand;
		MEIClient::AMTHI_Client::GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE response = getLocalSystemAccountCommand.getResponse();
		m_defaultUser = response.UserName;
		m_defaultPass.Set(response.Password.c_str());
		rc = true;
	}
	catch (MEIClient::AMTHI_Client::AMTHIErrorException& e)
	{
		unsigned int errNo = e.getErr();
		WSMAN_ERROR("GetLocalSystemAccountCommand failed ret=%d\n", errNo);
	}
	catch (MEIClient::MEIClientException& e)
	{
		const char* reason = e.what();
		WSMAN_ERROR("GetLocalSystemAccountCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		const char* reason = e.what();
		WSMAN_ERROR("Exception in GetLocalSystemAccountCommand %C\n", reason);
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
	WSMAN_DEBUG("BaseWSManClient::WsmanInitializer::WsmanInitializer()\n");
	//generate instances of singletons (generation in first function call is not thread-safe)
	BaseWSManClient::WsManSemaphore();
	BaseWSManClient::CtorSemaphore();
}

BaseWSManClient::WsmanInitializer BaseWSManClient::WsmanInitializer::initializer;


//**********************
// BaseWSManPassword
//**********************

typedef void* (*memset_t)(void*, int, size_t);

// To make compiler always execute it
static volatile memset_t memset_func = memset;

BaseWSManPassword::~BaseWSManPassword()
{
	Clean();
}

void BaseWSManPassword::Set(const char *pwd)
{
	Clean();
	if ((pwd == nullptr) || strlen(pwd) == 0)
		return;

	m_size = strlen(pwd) + 1;
	m_pwd = new char[m_size];
	memcpy(m_pwd, pwd, m_size);
}

void BaseWSManPassword::Clean()
{
	if (!m_pwd)
		return;

	memset_func(m_pwd, m_size, 0);
	delete[] m_pwd;
	m_pwd = nullptr;
}