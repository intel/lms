/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
/*++

@file: UPID_Commands.h

--*/

#ifndef __UPID_COMMANDS_H__
#define __UPID_COMMANDS_H__

#include "stdafx.h"
#include <string>


class UPID_Commands
{
	
public:
	uint32_t GetUPIDStateCommand(bool& state);
	uint32_t SetUPIDStateCommand(bool state);
	uint32_t GetUPIDCommand(uint32_t& oemPlatformIdType, std::wstring& oemPlatformId, std::wstring& csmePlatformId);
};

#endif //__UPID_COMMANDS_H__