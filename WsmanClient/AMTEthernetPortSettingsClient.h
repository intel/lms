/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
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
	AMTEthernetPortSettingsClient(unsigned int port);
	virtual ~AMTEthernetPortSettingsClient();

	bool GetAMTEthernetPortSettings(unsigned int* pLinkPreference, unsigned int* pLinkControl, unsigned int* pLinkProtection, bool* pIsLink);
	bool SetLinkPreference(unsigned int LinkPreference);

private:
	bool Init(bool forceGet = false, bool actionGet = false);
	bool m_isInit;
	bool m_isLink;

	unsigned int	m_LinkControl;
	unsigned int	m_LinkPreference;
	unsigned int	m_LinkProtection;
};

#endif //_AMTEthernetPortSettingsClient_H
