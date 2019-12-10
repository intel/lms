/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: HostBootReasonClient.h

--*/

#ifndef  _HostBootReasonClient_H
#define  _HostBootReasonClient_H


#include "BaseWSManClient.h"
#include <string>


enum HOST_RESET_REASON {
	UNKNOWN = 0,
	Other = 1,
	RemoteControl = 2,
	Alarm = 3,
	Reserved = 4
};

enum SX_STATES {
	SX_Unknown = 0, 
	SX_Other = 1,
	SX_S0 = 2,
	SX_S1 = 3,
	SX_S2 = 4,
	SX_S3 = 5,
	SX_S4 = 6,
	SX_S5 = 7
};

class WSMAN_DLL_API HostBootReasonClient : public BaseWSManClient
{
public:
	HostBootReasonClient();
	HostBootReasonClient(const std::string &User, const std::string &Password);
	virtual ~HostBootReasonClient();

	bool GetHostResetReason(HOST_RESET_REASON& resetReason, SX_STATES& previousSxState);

private:
	bool Init();
	bool m_isInit;
};

#endif //_HostBootReasonClient_H
