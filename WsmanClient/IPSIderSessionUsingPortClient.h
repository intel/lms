/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#ifndef _IPS_IDER_SESSION_USING_PORT_CLIENT_H
#define _IPS_IDER_SESSION_USING_PORT_CLIENT_H

#include "BaseWSManClient.h"

class WSMAN_DLL_API IPSIderSessionUsingPortClient : public BaseWSManClient
{
public:
	IPSIderSessionUsingPortClient();
	IPSIderSessionUsingPortClient(const std::string &User, const std::string &Password);
	virtual ~IPSIderSessionUsingPortClient();

	bool GetSessionLinkTechnology(short *pLinkTechnology);
private:
	bool init();
	short m_LinkTechnology; 
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;
	
};

#endif //_IPS_IDER_SESSION_USING_PORT_CLIENT_H