/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: EnumerateHashHandlesCommand.cpp

--*/

#include "EnumerateHashHandlesCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			EnumerateHashHandlesCommand::EnumerateHashHandlesCommand ()
			{
				std::shared_ptr<MEICommandRequest> tmp(new EnumerateHashHandlesRequest ());
				m_request = tmp;
				Transact();
			}

			ENUMERATE_HASH_HANDLES_RESPONSE EnumerateHashHandlesCommand::getResponse() 
			{
				return m_response->getResponse();
			}

			void EnumerateHashHandlesCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<ENUMERATE_HASH_HANDLES_RESPONSE>> tmp(
					new AMTHICommandResponse<ENUMERATE_HASH_HANDLES_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> EnumerateHashHandlesRequest::SerializeData()
			{	
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel