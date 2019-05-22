/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#ifndef _IPS_KVM_SESSION_USING_PORT_CLIENT_H
#define _IPS_KVM_SESSION_USING_PORT_CLIENT_H

#include "BaseWSManClient.h"

class WSMAN_DLL_API IPSKVMSessionUsingPortClient : public BaseWSManClient
{
public:
	IPSKVMSessionUsingPortClient();
	IPSKVMSessionUsingPortClient(const std::string &User, const std::string &Password);
	virtual ~IPSKVMSessionUsingPortClient();

	bool GetSessionLinkTechnology(short *pLinkTechnology);
private:
	bool init();
	short m_LinkTechnology; 
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;
	
};

#endif //_IPS_KVM_SESSION_USING_PORT_CLIENT_H