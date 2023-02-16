/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
				bool Enabled;
				bool CurrentOperationalState;
				bool TlsOnLocalPorts;

				const uint8_t ENABLED_MASK = BIT(0);
				const uint8_t CURRENTOPERATIONALSTATE_MASK = BIT(1);
				const uint8_t TLSONLOCALPORTS_MASK = BIT(6);
				const uint8_t ISNEWINTERFACEVERSION_MASK = BIT(7);

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					uint8_t buf;
					Intel::MEI_Client::parseData(buf, itr, end);
					Enabled = buf & ENABLED_MASK;
					CurrentOperationalState = (buf & CURRENTOPERATIONALSTATE_MASK) && (buf & ISNEWINTERFACEVERSION_MASK);
					TlsOnLocalPorts = (buf & TLSONLOCALPORTS_MASK) && (buf & ISNEWINTERFACEVERSION_MASK);
				}
			};

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
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__MNG_IS_CHANGE_TO_AMT_ENABLED_COMMAND_H__
