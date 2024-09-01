/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: EtherenetSettingsWSManClient.h

--*/

#ifndef _ETHERNET_SETTINGS_WSMAN_CLIENT_H
#define _ETHERNET_SETTINGS_WSMAN_CLIENT_H

#include "AMT_EthernetPortSettings.h"
#include "BaseWSManClient.h"
#include <memory>
#include <vector>

class EthernetSettingsWSManClient : public BaseWSManClient
{
public:
	EthernetSettingsWSManClient(unsigned int port);
	virtual ~EthernetSettingsWSManClient();
	bool Enumerate(std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> &EthernetSettings);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings m_service;
	UNLOCK_AFTER;
};

#endif //_ETHERNET_SETTINGS_WSMAN_CLIENT_H