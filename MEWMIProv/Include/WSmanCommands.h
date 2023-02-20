/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: WSmanCommands.h

--*/

#ifndef WSMAN_COMMANDS_H
#define WSMAN_COMMANDS_H

#include "stdafx.h"
#include <string>
#include <vector>

#define ERR_UKNOWN_CONNECTION_ERROR 1000
#define IDER_SOL_DISABLED 32768
#define IDER_ENABLED_SOL_DISABLED 32769
#define IDER_DISABLED_SOL_ENABLED 32770
#define IDER_SOL_ENABLED 32771

class EthernetPortEntryWSMan
{
public:
	EthernetPortEntryWSMan() : LinkIsUp(false), DHCPEnabled(false) {}
	std::wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	std::wstring IPAddress;
	std::wstring SubnetMask;
	std::wstring DefaultGateway;
	std::wstring PrimaryDNS;
	std::wstring SecondaryDNS;
};

class WSmanCommands
{
public:
	WSmanCommands();

	UINT32 setSpriteZoom(short zoom);
	UINT32 TerminateKVMSession(void);
	UINT32 isKVMActive(bool* enabled, bool* active);
	UINT32 GetPortSettings(std::vector<EthernetPortEntryWSMan> &ethernetPortList);
	UINT32 isSOLEnabled(bool* enabled);
	UINT32 isIDEREnabled(bool* enabled);

private:
	unsigned int m_port;
};
#endif // WSMAN_COMMANDS_H
