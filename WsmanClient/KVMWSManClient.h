/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: KVMWSManClient.h

--*/

#ifndef  _KVM_WSMAN_CLIENT_H
#define  _KVM_WSMAN_CLIENT_H

#include "IPS_KVMRedirectionSettingData.h"
#include "CIM_KVMRedirectionSAP.h"
#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API KVMWSManClient : public BaseWSManClient
{
public:
	KVMWSManClient();
	KVMWSManClient(const std::string &User, const std::string &Password);
	virtual ~KVMWSManClient();

	/*Actual soap actions!*/
	
	bool TerminateKVMSession(void);
	bool GetMEBxState(bool* MEBxState);
	bool KVMRedirectionState(unsigned short* state);
	
private:
	bool Init(bool forceGet = false);
	bool SAPInit(bool forceGet = false);
	bool m_isInit;
	bool m_isSAPInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_KVMRedirectionSettingData m_service;
	Intel::Manageability::Cim::Typed::CIM_KVMRedirectionSAP m_SAPService;
	UNLOCK_AFTER;
};

#endif //_KVM_SOAP_CLIENT_H