/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetKVMSessionStateCommand.h

--*/

#ifndef __GET_KVM_SESSION_STATE_COMMAND_H__
#define __GET_KVM_SESSION_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			typedef struct KVM_STATUS_t
			{
				uint32_t KvmSessionIsActive:1;
				uint32_t WaitForOpt:1;
				uint32_t Reserved:30;
			} KVM_STATUS;

			struct GET_KVM_SESSION_STATE_RESPONSE
			{
				GET_KVM_SESSION_STATE_RESPONSE() : RequestId(0), kvmStatus({ 0 }) {}
				uint32_t RequestId;
				KVM_STATUS kvmStatus;
			
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseData(RequestId, itr, end);
					Intel::MEI_Client::parseData(kvmStatus, itr, end);
				}
			};

			class GetKVMSessionStateRequest : public AMTHICommandRequest
			{
			public:
				GetKVMSessionStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetKVMSessionStateRequest() {}

			private:
				static const uint32_t KVM_SESSION_ID = 4;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000049;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					uint32_t id = KVM_SESSION_ID;
					std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
					return output;
				}
			};

			class GetKVMSessionStateCommand : public AMTHICommand
			{
			public:

				GetKVMSessionStateCommand()
				{
					m_request = std::make_shared<GetKVMSessionStateRequest>();
					Transact();
				}
				virtual ~GetKVMSessionStateCommand() {}

				GET_KVM_SESSION_STATE_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800049;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_KVM_SESSION_STATE_COMMAND_H__