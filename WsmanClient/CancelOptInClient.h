/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: CancelOptInClient.h

--*/

#ifndef  _CancelOptInClient_H
#define  _CancelOptInClient_H


#include "BaseWSManClient.h"
#include <string>
#include "IPS_OptInService.h"

class CancelOptInClient : public BaseWSManClient
{
public:
	CancelOptInClient(unsigned int port);
	virtual ~CancelOptInClient();

	/*Actual soap actions!*/
	
	bool CancelOptIn(unsigned int* pReturnValue);
	bool GetUserConsentState(short* pState, short* pPolicy);
	bool Init(bool forceGet = false);
private:
	
	bool m_isInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_OptInService m_service;
	UNLOCK_AFTER;
};

#endif //CancelOptInClient_H