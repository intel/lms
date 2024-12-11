/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
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
			const uint8_t ENABLED_MASK = BIT(0);
			const uint8_t CURRENTOPERATIONALSTATE_MASK = BIT(1);
			const uint8_t CIRAPERIODICTIMERFIX_MASK = BIT(5);
			const uint8_t TLSONLOCALPORTS_MASK = BIT(6);
			const uint8_t ISNEWINTERFACEVERSION_MASK = BIT(7);

			struct IsChangedEnabledResponse
			{
				IsChangedEnabledResponse() : Enabled(false), CurrentOperationalState(false), TlsOnLocalPorts(false), CIRAPeriodicTimerFix(false){}
				bool Enabled;
				bool CurrentOperationalState;
				bool TlsOnLocalPorts;
				bool CIRAPeriodicTimerFix;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					uint8_t buf;
					Intel::MEI_Client::parseData(buf, itr, end);
					Enabled = buf & ENABLED_MASK;
					CurrentOperationalState = (buf & CURRENTOPERATIONALSTATE_MASK) && (buf & ISNEWINTERFACEVERSION_MASK);
					TlsOnLocalPorts = (buf & TLSONLOCALPORTS_MASK) && (buf & ISNEWINTERFACEVERSION_MASK);
					CIRAPeriodicTimerFix = (buf & CIRAPERIODICTIMERFIX_MASK) && (buf & ISNEWINTERFACEVERSION_MASK);
				}
			};

			class MNGIsChangeToAMTEnabledRequest : public ManageabilityCommandRequest
			{
			public:
				MNGIsChangeToAMTEnabledRequest() {}
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

			class MNGIsChangeToAMTEnabledCommand : public ManageabilityCommand
			{
			public:

				MNGIsChangeToAMTEnabledCommand()
				{
					m_request = std::make_shared<MNGIsChangeToAMTEnabledRequest>();
					Transact();
				}
				virtual ~MNGIsChangeToAMTEnabledCommand() {}

				IsChangedEnabledResponse getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = ManageabilityCommandResponse<IsChangedEnabledResponse>(buffer);
				}

				ManageabilityCommandResponse<IsChangedEnabledResponse> m_response;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__MNG_IS_CHANGE_TO_AMT_ENABLED_COMMAND_H__
