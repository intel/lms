/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetZeroTouchEnabledCommand.h

--*/

#ifndef __GET_ZERO_TOUCH_ENABLED_COMMAND_H__
#define __GET_ZERO_TOUCH_ENABLED_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct ZTC_ENABLED_STATUS
			{
				ZTC_ENABLED_STATUS() : ZTCEnabled(false) {}
				bool ZTCEnabled;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData (ZTCEnabled,itr,end);
				}
			};

			class GetZeroTouchEnabledCommand : public AMTHICommand
			{
			public:

				GetZeroTouchEnabledCommand();
				virtual ~GetZeroTouchEnabledCommand() {}

				ZTC_ENABLED_STATUS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<ZTC_ENABLED_STATUS> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800030;
			};

			class GetZeroTouchEnabledRequest : public AMTHICommandRequest
			{
			public:
				GetZeroTouchEnabledRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetZeroTouchEnabledRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000030;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif // __GET_ZERO_TOUCH_ENABLED_COMMAND_H__