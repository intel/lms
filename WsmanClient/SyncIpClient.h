/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: SyncIpClient.h

--*/

#ifndef  _SYNC_IP_CLIENT_H
#define  _SYNC_IP_CLIENT_H

#include "IPS_HostIPSettings.h"
#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API SyncIpClient : public BaseWSManClient
{
public:
	SyncIpClient(unsigned int port);
	virtual ~SyncIpClient();

	bool GetNetworkData(bool& DHCPEnabled, std::string& IPAddress, std::string& SubNet, std::string& GateWay,
		std::string& DNSAddress1, std::string& DNSAddress2);
	bool SetNetworkData(bool DHCPEnabled, const std::string &IPAddress, const std::string &SubNet,
		const std::string &GateWay, const std::string &DNSAddress1, const std::string &DNSAddress2);
	bool GetSharedStaticIpState(bool* SharedStaticIpState);
	bool Init(bool forceGet = false);
	bool InitEPS();
private:

	bool m_isInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_HostIPSettings m_HostIpSettings;
	UNLOCK_AFTER;
	bool						m_SharedStaticIpState;
};

#endif //_SYNC_IP_CLIENT_H
