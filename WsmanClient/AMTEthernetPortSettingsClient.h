/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: AMTEthernetPortSettingsClient.h

--*/

#ifndef  _AMTEthernetPortSettingsClient_H
#define  _AMTEthernetPortSettingsClient_H


#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API AMTEthernetPortSettingsClient : public BaseWSManClient
{
public:
	AMTEthernetPortSettingsClient();
	AMTEthernetPortSettingsClient(const std::string &User, const std::string &Password);
	virtual ~AMTEthernetPortSettingsClient();

	bool GetAMTEthernetPortSettings(unsigned int* pLinkPreference, unsigned int* pLinkControl, unsigned int* pLinkProtection);
	bool SetLinkPreference(unsigned int LinkPreference);

private:
	bool Init(bool forceGet = false, bool actionGet = false);
	bool m_isInit;
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;

	unsigned int	m_LinkControl;
	unsigned int	m_LinkPreference;
	unsigned int	m_LinkProtection;
};

#endif //_AMTEthernetPortSettingsClient_H
