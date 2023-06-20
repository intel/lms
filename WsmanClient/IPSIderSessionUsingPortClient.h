/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#ifndef _IPS_IDER_SESSION_USING_PORT_CLIENT_H
#define _IPS_IDER_SESSION_USING_PORT_CLIENT_H

#include "BaseWSManClient.h"

class IPSIderSessionUsingPortClient : public BaseWSManClient
{
public:
	IPSIderSessionUsingPortClient(unsigned int port);
	virtual ~IPSIderSessionUsingPortClient();

	bool GetSessionLinkTechnology(short *pLinkTechnology);
private:
	bool init();
	short m_LinkTechnology; 
};

#endif //_IPS_IDER_SESSION_USING_PORT_CLIENT_H