/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: PowerManagementCapabilitiesWsManClient.h

--*/

#ifndef  _PWR_MNGMNT_CAPS_CLIENT_H
#define  _PWR_MNGMNT_CAPS_CLIENT_H

#include "BaseWSManClient.h"
#include "CIM_PowerManagementCapabilities.h"
#include <vector>

//Note : we assume only UNS will change CIM_PowerManagementCapabilities, and only using this wsman client
class PowerManagementCapabilitiesClient : public BaseWSManClient
{
public:
	PowerManagementCapabilitiesClient(unsigned int port);
	virtual ~PowerManagementCapabilitiesClient();

	/*Actual soap actions!*/
	
	// add/remove fields from CIM_PowerManagementCapabilities according to power capabilities
	// parameters : sleep/hibernate : is the system capable for sleep/hibernate
	bool addGracefulOperations(bool sleep,bool hibernate);
	//for Unit testing
#ifdef _DEBUG
	std::vector<unsigned short>  getCapsVector();
	std::string getOtherCapsString();
#endif

private:
	bool Init(bool forceGet = false);
	bool m_isInit;
	
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::CIM_PowerManagementCapabilities m_service;
	UNLOCK_AFTER;
};

#endif //_PWR_MNGMNT_CAPS_CLIENT_H