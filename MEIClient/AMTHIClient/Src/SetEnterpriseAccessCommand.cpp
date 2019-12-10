/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetEnterpriseAccessCommand.cpp

--*/

#include "SetEnterpriseAccessCommand.h"
#include <string.h>

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {

			SetEnterpriseAccessRequest::SetEnterpriseAccessRequest(uint8_t Flags, const std::vector<uint8_t> &HostIPAddress, uint8_t EnterpiseAccess) :
				_Flags(Flags), _HostIPAddress(HostIPAddress), _EnterpiseAccess(EnterpiseAccess)
			{
				if (_HostIPAddress.size() != HOST_IP_ADDRESS_SIZE)
				{
					throw std::invalid_argument("HostIPAddress should have 16 byte length");
				}
			}

			SetEnterpriseAccessCommand::SetEnterpriseAccessCommand(uint8_t Flags, const std::vector<uint8_t> &HostIPAddress, uint8_t EnterpiseAccess)
			{
				std::shared_ptr<MEICommandRequest> tmp(new SetEnterpriseAccessRequest(Flags, HostIPAddress, EnterpiseAccess));
				m_request = tmp;
				Transact();
			}

			SetEnterpriseAccess_RESPONSE SetEnterpriseAccessCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void SetEnterpriseAccessCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>> tmp(
					new AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> SetEnterpriseAccessRequest::SerializeData()
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
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel
	

	