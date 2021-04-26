/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: BaseWSManClient.h

--*/

#ifndef _BASE_WSMAN_CLIENT_H
#define _BASE_WSMAN_CLIENT_H

#include <string>
#include <memory>
#include <mutex>
#include "CimWsman.h"
#include "WsmanClientDllExport.h"

typedef enum _WSMAN_STATUS
{
	WSMAN_STATUS_SUCCESS				= 0x0,
	WSMAN_STATUS_INIT_FAILURE			= 0x1,
	WSMAN_STATUS_SOAP_SERVER_ERROR	= 0x2,
	WSMAN_STATUS_BIND_ERROR			= 0x3,
	WSMAN_STATUS_SUBSCRIPTION_ERROR   = 0x4,
	WSMAN_STATUS_CENCEL_ERROR			= 0x5,
	WSMAN_GET_NET_PARAM_ERROR			= 0x6,
	WSMAN_STATUS_UPDATE_REG_MODE		= 0x7,
	WSMAN_STATUS_CONNECTION_ERROR		= 0x8
} WSMAN__STATUS;

// Constants for the common use
static const int AMT_NON_SECURE_PORT = 16992;
static const int AMT_SECURE_PORT	 = 16993;

// AMT errors
enum
{
	WSMAN_AMT_ERROR_SUCCESS = 0x0,
	WSMAN_AMT_INTERNAL_ERROR = 0x1,
	WSMAN_AMT_UNSUPPORTED = 0x812,
};

class WSMAN_DLL_API BaseWSManPassword
{
public:
	BaseWSManPassword(): m_pwd(nullptr), m_size(0) {}
	BaseWSManPassword(const char *pwd) : m_pwd(nullptr), m_size(0) { Set(pwd); }
	BaseWSManPassword(const BaseWSManPassword&) = delete;
	BaseWSManPassword &operator = (const BaseWSManPassword&) = delete;
	~BaseWSManPassword();
	void Set(const char *pwd);
	const char* Get() { return m_pwd; }
private:
	void Clean();
	char *m_pwd;
	size_t m_size;
};

class WSMAN_DLL_API BaseWSManClient
{
public:

	// Constructors and Destructor.
	BaseWSManClient();
	BaseWSManClient(const std::string &defaultUser, const std::string &defaultPass);

	virtual ~BaseWSManClient();

protected:
	void SetEndpoint();		// Set endpoint for wsman request.
	static std::mutex& WsManSemaphore();// For locking Wsman library

	// Data members
	std::string							endpoint;
	bool								m_endpoint;		// True if endpoint is correct.

	//This class only acquires the CtorSemaphore in the constructor (or blocks until it can)
	struct Locker
	{
		Locker();
	};
	//This class only releases the CtorSemaphore in the constructor
	struct Unlocker
	{
		Unlocker();
	};

	//see explanation for the usage of these classes below

private:
	void Init();						// Initialize soap client.
	bool GetLocalSystemAccount();

	friend class WsmanInitializer;
	class WsmanInitializer
	{
		WsmanInitializer();
		static WsmanInitializer initializer;
	};

	//This semaphore is used to prevent concurrent calls to constructors of CIM-framework classes, since 
	//these classes access static objects in the constructor without using any synchronization mechanism 
	static std::mutex& CtorSemaphore();

	// Data members
protected:
	std::shared_ptr<Intel::WSManagement::ICimWsmanClient>			m_client;		// WSMan client.
	std::string							m_ip;
private:
	std::string							m_defaultUser;
	BaseWSManPassword					m_defaultPass;

	static const std::string DEFAULT_USER;

	BaseWSManClient& operator= (const BaseWSManClient& ){ return *this; } //to avoid misuse

};

//since class members are constructed in the order of declaration, declaring a Locker before CIM-framework objects and an Unlocker after them (using
//the macros defined below) will prevent concurrent calls to constructors of CIM-framework classes 

#define LOCK_BEFORE Locker __locker
#define UNLOCK_AFTER Unlocker __unlocker

#endif //_BASE_WSMAN_CLIENT_H
