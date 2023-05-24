/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: HostBootReasonClient.h

--*/

#ifndef  _HostBootReasonClient_H
#define  _HostBootReasonClient_H

#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API HostBootReasonClient : public BaseWSManClient
{
public:
	HostBootReasonClient(unsigned int port);
	virtual ~HostBootReasonClient();

	enum class HOST_RESET_REASON {
		UNKNOWN = 0,
		Other = 1,
		RemoteControl = 2,
		Alarm = 3,
		Reserved = 4
	};

	enum class SX_STATES {
		Unknown = 0,
		Other = 1,
		S0 = 2,
		S1 = 3,
		S2 = 4,
		S3 = 5,
		S4 = 6,
		S5 = 7
	};

	bool GetHostResetReason(HOST_RESET_REASON& resetReason, SX_STATES& previousSxState);

private:
	bool Init();
	bool m_isInit;
};

#endif //_HostBootReasonClient_H
