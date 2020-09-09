/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
/*++

@file: UPID_Commands.cpp

--*/

#include "UPID_Commands.h"
#include "UPIDErrorException.h"
#include "DebugPrints.h"
#include "GetUPIDFeatureStateCommand.h"
#include "SetUPIDFeatureStateCommand.h"
#include "GetUPIDCommand.h"
#include <sstream>
#include <iomanip>

using namespace Intel::MEI_Client::UPID_Client;

uint32_t UPID_Commands::GetUPIDStateCommand(bool& state)
{
	uint32_t rc = UPID_STATUS_INTERNAL_ERROR;
	
	try {
		GetUPIDFeatureStateCommand command;
		UPID_PLATFORM_ID_FEATURE_STATE_GET_Response response = command.getResponse();
		state = response.FeatureEnabled;
		rc = 0;
	}
	catch (UPIDErrorException& e)
	{
		UNS_ERROR("GetUPIDStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR("GetUPIDStateCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetUPIDStateCommand %C\n", e.what());
	}
	return rc;
}


uint32_t UPID_Commands::SetUPIDStateCommand(bool state)
{
	uint32_t rc = UPID_STATUS_INTERNAL_ERROR;
	
	try {
		SetUPIDFeatureStateCommand command(state);
		UPID_PLATFORM_ID_FEATURE_STATE_SET_Response response = command.getResponse();
		rc = 0;
	}
	catch (Intel::MEI_Client::UPID_Client::UPIDErrorException& e)
	{
		UNS_ERROR("SetUPIDStateCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR("SetUPIDStateCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in SetUPIDStateCommand %C\n", e.what());
	}
	return rc;
}

uint32_t UPID_Commands::GetUPIDCommand(uint32_t& oemPlatformIdType, std::wstring& oemPlatformId, std::wstring& csmePlatformId)
{
	uint32_t rc = UPID_STATUS_INTERNAL_ERROR;
	try {
		Intel::MEI_Client::UPID_Client::GetUPIDCommand command;
		Intel::MEI_Client::UPID_Client::UPID_PLATFORM_ID_GET_Response response = command.getResponse();
		oemPlatformIdType = response.PlatformIdType;

		std::wstringstream oemPlatformIdStr, csmePlatformIdStr;
		if (oemPlatformIdType == UPID_OEM_PLATFORM_ID_TYPE_PRINTABLE_STRING)
		{
			std::string temp((char*)response.OEMPlatformId, Intel::MEI_Client::UPID_Client::UPID_LEN);
			oemPlatformIdStr << temp.c_str();
		}
		else { //When oemPlatformIdType is Binary - Show oemPlatformId as hex string
			for (int i = 0; i < UPID_LEN; i++)
			{
				oemPlatformIdStr << "0x" << std::hex << std::setfill(L'0') << std::setw(2) << unsigned(response.OEMPlatformId[i]) << " ";
			}
		}
		oemPlatformId.assign(oemPlatformIdStr.str());

		for (int i = 0; i < UPID_LEN; i++) //csmePlatformId is always Binary - Show it as hex string
		{
			csmePlatformIdStr << "0x" << std::hex << std::setfill(L'0') << std::setw(2) << unsigned(response.CSMEPlatformId[i]) << " ";
		}
		csmePlatformId.assign(csmePlatformIdStr.str());

		rc = 0;
	}
	catch (UPIDErrorException& e)
	{
		UNS_ERROR("GetUPIDCommand failed ret=%d\n", e.getErr());
		rc = e.getErr();
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR("GetUPIDCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR("Exception in GetUPIDCommand %C\n", e.what());
	}
	
	return rc;
}