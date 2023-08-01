/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetAMTStateCommand.h

--*/

#ifndef __GET_AMT_STATE_COMMAND_H__
#define __GET_AMT_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			enum LINK_STATUS	//uint8_t
			{
				down	= 0,
				up		= 1
			};

			enum CRYPTO_FUSE	//uint8_t
			{
				CryptoFuseDisabled	= 0,
				CryptoFuseEnabled	= 1
			};

			enum FLASH_PROTECTION	//uint8_t
			{
				FlashProtectionDisabled	= 0,
				FlashProtectionEnabled	= 1
			};

			enum ME_RESET_TYPE	//uint8_t
			{
				RESET_NONE = 0,
				RESET_ME = 1,
				RESET_GLOBAL = 2,
				RESET_EXCEPTION = 3
			};

			union STATE_DATA
			{
				uint8_t data[5];
				
				struct {
					uint8_t LinkStatus;	//LINK_STATUS
					uint8_t reserved;
					uint8_t CryptoFuse;	//CRYPTO_FUSE
					uint8_t FlashProtection;	//FLASH_PROTECTION
					uint8_t LastMEResetType;	//ME_RESET_TYPE
				} Fields;
			};

			struct AMT_STATE_RESPONSE
			{
				AMT_STATE_RESPONSE() : StateDataIdentifier({ 0 }), StateData({ 0 }) {}
				AMT_UUID StateDataIdentifier;
				STATE_DATA StateData;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					parseData(StateDataIdentifier, itr, end);
					uint32_t arraySize;
					parseData(arraySize, itr, end);
					if (arraySize != 5)
					{
						throw MEIClientException("Error: Wrong buffer size!");
					}
					parseArray<uint8_t>(StateData.data, 5, itr, end);
				}
			};

			const AMT_UUID AMT_UUID_LINK_STATE = 
			{0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x01};

			class GetAMTStateRequest : public AMTHICommandRequest
			{
			public:
				GetAMTStateRequest(const AMT_UUID StateVariableIdentifier) :
					AMTHICommandRequest(REQUEST_COMMAND_NUMBER), m_stateVariableIdentifier(StateVariableIdentifier) {}
				virtual ~GetAMTStateRequest() {}

			private:
				AMT_UUID m_stateVariableIdentifier;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x01000001;

				virtual uint32_t requestDataSize()
				{
					return sizeof(AMT_UUID);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					std::vector<uint8_t> output(m_stateVariableIdentifier.amt_uuid, m_stateVariableIdentifier.amt_uuid + sizeof(AMT_UUID));
					return output;
				}
			};

			class GetAMTStateCommand : public AMTHICommand
			{
			public:

				GetAMTStateCommand(AMT_UUID StateVariableIdentifier = AMT_UUID_LINK_STATE)
				{
					m_request = std::make_shared<GetAMTStateRequest>(StateVariableIdentifier);
					Transact();
				}
				virtual ~GetAMTStateCommand() {}

				AMT_STATE_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<AMT_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<AMT_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x01800001;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_AMT_STATE_COMMAND_H__