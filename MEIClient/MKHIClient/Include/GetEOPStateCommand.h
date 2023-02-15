/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetEOPStateCommand.h

--*/

#ifndef __GET_EOP_STATE_COMMAND_H__
#define __GET_EOP_STATE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			struct GET_EOP_STATE_RESPONSE
			{
				union
				{
					uint32_t State;
					struct
					{
						uint8_t EopState;
						uint8_t Reserved[3];
					} Fields;
				};

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseData(State, itr, end);
				}
			};

			class GetEOPStateCommand : public MKHICommand
			{
			public:

				GetEOPStateCommand();
				virtual ~GetEOPStateCommand() {}

				GET_EOP_STATE_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<MKHICommandResponse<GET_EOP_STATE_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x1D;
			};

			class GetEOPStateRequest : public MKHICommandRequest
			{
			public:
				GetEOPStateRequest() {}
				virtual ~GetEOPStateRequest() {}

			private:

				static const uint32_t REQUEST_COMMAND_NUMBER = 0x1D;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the MKHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}

				virtual unsigned int requestHeaderGroupID()
				{
					//this is the command group (taken from the MKHI document)
					return MKHI_GEN_GROUP_ID;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_EOP_STATE_COMMAND_H__
