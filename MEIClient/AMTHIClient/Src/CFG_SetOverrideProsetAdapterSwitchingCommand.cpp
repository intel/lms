/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: CFG_SetOverrideProsetAdapterSwitchingCommand.cpp

--*/

#include "CFG_SetOverrideProsetAdapterSwitchingCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			CFG_SetOverrideProsetAdapterSwitchingCommand::~CFG_SetOverrideProsetAdapterSwitchingCommand()
			{}

			CFG_SetOverrideProsetAdapterSwitchingCommandRequest::~CFG_SetOverrideProsetAdapterSwitchingCommandRequest()
			{}

			CFG_SetOverrideProsetAdapterSwitchingCommandRequest::CFG_SetOverrideProsetAdapterSwitchingCommandRequest(bool OverrideEnabled) :
				AMTHICommandRequest(REQUEST_COMMAND_NUMBER), overrideEnabled_(OverrideEnabled)
			{}

			std::vector<uint8_t> CFG_SetOverrideProsetAdapterSwitchingCommandRequest::SerializeData()
			{
				std::vector<uint8_t> tmp((uint8_t*)&overrideEnabled_, (uint8_t*)&overrideEnabled_ + sizeof(overrideEnabled_));
				return tmp;
			}

			CFG_SetOverrideProsetAdapterSwitchingCommand::CFG_SetOverrideProsetAdapterSwitchingCommand(bool OverrideEnabled)
			{
				std::shared_ptr<MEICommandRequest> tmp(new CFG_SetOverrideProsetAdapterSwitchingCommandRequest(OverrideEnabled));
				m_request = tmp;
				Transact();
			}

			AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE CFG_SetOverrideProsetAdapterSwitchingCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void CFG_SetOverrideProsetAdapterSwitchingCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE>> tmp(new AMTHICommandResponse<AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel