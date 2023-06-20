/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#ifndef _IPS_KVM_SESSION_USING_PORT_CLIENT_H
#define _IPS_KVM_SESSION_USING_PORT_CLIENT_H

#include "BaseWSManClient.h"

class IPSKVMSessionUsingPortClient : public BaseWSManClient
{
public:
	IPSKVMSessionUsingPortClient(unsigned int port);
	virtual ~IPSKVMSessionUsingPortClient();

	bool GetSessionLinkTechnology(short *pLinkTechnology);
private:
	bool init();
	short m_LinkTechnology; 
};

#endif //_IPS_KVM_SESSION_USING_PORT_CLIENT_H