/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#ifndef _IPS_SOL_SESSION_USING_PORT_CLIENT_H
#define _IPS_SOL_SESSION_USING_PORT_CLIENT_H

#include "BaseWSManClient.h"

class WSMAN_DLL_API IPSSolSessionUsingPortClient : public BaseWSManClient
{
public:
	IPSSolSessionUsingPortClient(unsigned int port);
	IPSSolSessionUsingPortClient(unsigned int port, const std::string &User, const std::string &Password);
	virtual ~IPSSolSessionUsingPortClient();

	bool GetSessionLinkTechnology(short *pLinkTechnology);
private:
	bool init();
	short m_LinkTechnology; 
};

#endif //_IPS_SOL_SESSION_USING_PORT_CLIENT_H