/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: FW_Commands.h

--*/

#pragma once
#include "stdafx.h"
#include "GetFWCapsCommand.h"
#include "GetPlatformTypeCommand.h"

class FWUpdate_Commands
{
public:
	UINT32 GetFWCapabilities(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI& capabilities);
	UINT32 GetFWFeaturesState(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI& features);
	UINT32 GetFWPlatformType(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE& platform);

	unsigned int GetFWUpdateStateCommand(bool* enabled);
};
