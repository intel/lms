/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#pragma once

/*++

@file: AMTRedirectionServiceWSManClient.h

--*/

#ifndef  _AMTRedirectionServiceWSManClient_H
#define  _AMTRedirectionServiceWSManClient_H


#include "AMT_RedirectionService.h"
#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API AMTRedirectionServiceWSManClient :
	public BaseWSManClient
{
public:
	AMTRedirectionServiceWSManClient(void);
	virtual ~AMTRedirectionServiceWSManClient(void);
	bool TerminateSession(unsigned int SessionType);
	bool Init(bool forceGet= false);
private:
	
	bool m_isInit;
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_RedirectionService	m_service;
	UNLOCK_AFTER;
};

#endif //_AMTRedirectionServiceWSManClient_H
