/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: FWUpdate_Commands.cpp

--*/

#include "FWUpdate_Commands.h"
#include "DebugPrints.h"
#include "GetFWUpdateStateCommand.h"

UINT32 
FWUpdate_Commands::GetFWCapabilities(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI& capabilities)
{
	using namespace Intel::MEI_Client;
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		MKHI_Client::GetFWCapsCommand command(MKHI_Client::FEATURES_CAPABLE);
		capabilities = command.getResponse();
		rc = 0;
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetFWCapsCommand failed %C\n", e.what());
	}

	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetFWCapsCommand %C\n", e.what());
	}
return rc;
}

UINT32 
FWUpdate_Commands::GetFWFeaturesState(Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI& features)
{
	using namespace Intel::MEI_Client;
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		MKHI_Client::GetFWCapsCommand command(MKHI_Client::FEATURES_ENABLED);
		features = command.getResponse();
		rc = 0;
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetFWCapsCommand failed %C\n", e.what());
	}
	
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetFWCapsCommand %C\n", e.what());
	}
	return rc;
}

UINT32 
FWUpdate_Commands::GetFWPlatformType(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE& platform)
{
	using namespace Intel::MEI_Client;
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		MKHI_Client::GetPlatformTypeCommand command;
		platform = command.getResponse();
		rc = 0;
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR("GetPlatformTypeCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetPlatformTypeCommand %C\n", e.what());
	}
	return rc;
}

unsigned int FWUpdate_Commands::GetFWUpdateStateCommand(bool* enabled)
{
	unsigned int rc = AMT_STATUS_INTERNAL_ERROR;
	try {
		Intel::MEI_Client::MKHI_Client::GetFWUpdateStateCommand command;
		Intel::MEI_Client::MKHI_Client::FW_UPDATE_STATE response = command.getResponse();
		*enabled = (response.Data == Intel::MEI_Client::MKHI_Client::FW_UPDATE_ENABLED) ||
				   (response.Data == Intel::MEI_Client::MKHI_Client::FW_UPDATE_PASSWORD_PROTECTED);
		rc = 0;
	}
	catch (Intel::MEI_Client::MKHI_Client::MKHIErrorException& e)
	{
		UNS_ERROR("GetFWUpdateStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR("GetFWUpdateStateCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetFWUpdateStateCommand %C\n", e.what());
	}
	return rc;
}