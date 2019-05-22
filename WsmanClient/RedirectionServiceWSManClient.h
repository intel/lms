/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: RedirectioServiceWSManClient.h

--*/

#ifndef  _REDIRECTION_SERVICE_WSMAN_CLIENT_H
#define  _REDIRECTION_SERVICE_WSMAN_CLIENT_H

#include "AMT_RedirectionService.h"
#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API RedirectionServiceWSManClient : public BaseWSManClient
{
public:
	RedirectionServiceWSManClient();
	virtual ~RedirectionServiceWSManClient();

	/*Actual soap actions!*/
	
	bool RedirectionState(unsigned short* state);
	bool Init(bool forceGet = false);
private:
	bool m_isInit;
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_RedirectionService m_service;	
	UNLOCK_AFTER;
};

#endif //_REDIRECTION_SERVICE_WSMAN_CLIENT_H