/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: WSmanCommands.h

--*/

#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
#include    <vector>
#include "EthernetSettingsWSManClient.h"

#define ERR_UKNOWN_CONNECTION_ERROR 1000
#define IDER_SOL_DISABLED 32768
#define IDER_ENABLED_SOL_DISABLED 32769
#define IDER_DISABLED_SOL_ENABLED 32770
#define IDER_SOL_ENABLED 32771

typedef struct _EthernetPortEntryWSMan
{
	wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	wstring   IPAddress;
	wstring   SubnetMask;
	wstring   DefaultGateway;
	wstring   PrimaryDNS;
	wstring   SecondaryDNS;
} EthernetPortEntryWSMan;

class WSmanCommands
{
	public:
		UINT32 setSpriteZoom(short zoom);
		UINT32 setSpriteLocale(short locale);
		UINT32 TerminateKVMSession(void);
		UINT32 isKVMActive(bool* enabled, bool* active);
		UINT32 GetPortSettings(
			vector<EthernetPortEntryWSMan> &ethernetPortList,
			std::string userName,
			std::string password);
		UINT32 isSOLEnabled(bool* enabled);
		UINT32 isIDEREnabled(bool* enabled);
};
