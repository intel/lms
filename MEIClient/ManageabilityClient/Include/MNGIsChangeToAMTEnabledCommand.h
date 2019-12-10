/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MNGIsChangeToAMTEnabledCommand.h

--*/

#ifndef __MNG_IS_CHANGE_TO_AMT_ENABLED_COMMAND_H__
#define __MNG_IS_CHANGE_TO_AMT_ENABLED_COMMAND_H__

#include "ManageabilityCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace Manageability_Client
		{
			struct IsChangedEnabledResponse
			{
				uint32_t Enabled;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class MNGIsChangeToAMTEnabledRequest;
			class MNGIsChangeToAMTEnabledCommand : public ManageabilityCommand
			{
			public:

				MNGIsChangeToAMTEnabledCommand();
				virtual ~MNGIsChangeToAMTEnabledCommand() {}

				IsChangedEnabledResponse getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<ManageabilityCommandResponse<IsChangedEnabledResponse>> m_response;
			};

			class MNGIsChangeToAMTEnabledRequest : public ManageabilityCommandRequest
			{
			public:
				MNGIsChangeToAMTEnabledRequest(){}
				virtual ~MNGIsChangeToAMTEnabledRequest() {}

			private:
				static const uint8_t REQUEST_COMMAND = 0x05;
				static const uint8_t REQUEST_SUB_CMD = 0x051;

				virtual uint8_t requestHeaderCMD()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND;
				}
				virtual uint8_t requestHeaderSubCMD()
				{
					//this is the sub command number (taken from the AMTHI document)
					return REQUEST_SUB_CMD;
				}
				virtual uint8_t requestDataSize()
				{
					return 0;
				}

				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__MNG_IS_CHANGE_TO_AMT_ENABLED_COMMAND_H__
