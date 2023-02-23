/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: SetEnterpriseAccessCommand.h

--*/

#ifndef __SET_ENTERPRISE_ACCESS_COMMAND_H__
#define __SET_ENTERPRISE_ACCESS_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SetEnterpriseAccess_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator)
				{
					return;
				}
			};

			const static uint32_t HOST_IP_ADDRESS_SIZE = 16;

			class SetEnterpriseAccessRequest : public AMTHICommandRequest
			{
			public:
				SetEnterpriseAccessRequest(uint8_t Flags, const std::vector<uint8_t>& HostIPAddress, uint8_t EnterpiseAccess) :
					AMTHICommandRequest(REQUEST_COMMAND_NUMBER), _Flags(Flags), _HostIPAddress(HostIPAddress), _EnterpiseAccess(EnterpiseAccess)
				{
					if (_HostIPAddress.size() != HOST_IP_ADDRESS_SIZE)
					{
						throw std::invalid_argument("HostIPAddress should have 16 byte length");
					}
				}
				SetEnterpriseAccessRequest(const SetEnterpriseAccessRequest&) = delete;
				SetEnterpriseAccessRequest& operator = (const SetEnterpriseAccessRequest&) = delete;
				virtual ~SetEnterpriseAccessRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400003F;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint8_t) + sizeof(uint8_t) * HOST_IP_ADDRESS_SIZE + sizeof(uint8_t);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					const uint32_t outputSize = requestDataSize();
					std::vector<uint8_t> output(outputSize, 0);
					std::vector<uint8_t>::iterator it = output.begin();

					*it = _Flags;
					it++;
					it = std::copy(_HostIPAddress.begin(), _HostIPAddress.end(), it);
					*it = _EnterpiseAccess;
					return output;
				}

				uint8_t _Flags;
				std::vector<uint8_t> _HostIPAddress;
				uint8_t _EnterpiseAccess;
			};

			class SetEnterpriseAccessCommand : public AMTHICommand
			{
			public:

				SetEnterpriseAccessCommand(uint8_t Flags, const std::vector<uint8_t> &HostIPAddress, uint8_t EnterpiseAccess)
				{
					m_request = std::make_shared<SetEnterpriseAccessRequest>(Flags, HostIPAddress, EnterpiseAccess);
					Transact();
				}
				virtual ~SetEnterpriseAccessCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<SetEnterpriseAccess_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480003F;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_ENTERPRISE_ACCESS_COMMAND_H__