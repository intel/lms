/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2021 Intel Corporation
 */
/*++

@file: GetCodeVersionCommand.h

--*/

#ifndef CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_COMMAND_H
#define CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_COMMAND_H

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
namespace MEI_Client
{
namespace AMTHI_Client
{
	typedef struct AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_REQUEST_t
	{
		uint32_t         OverrideEnabled;
	}  AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_REQUEST;

	typedef struct AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE_t
	{
		AMT_STATUS      Status;
		void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
		{
			Intel::MEI_Client::parseData(Status, itr, end);
		}
	} AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE;

	class CFG_SetOverrideProsetAdapterSwitchingCommandRequest;
	class CFG_SetOverrideProsetAdapterSwitchingCommand : public AMTHICommand
	{
	public:

		CFG_SetOverrideProsetAdapterSwitchingCommand(bool OverrideEnabled);
		virtual ~CFG_SetOverrideProsetAdapterSwitchingCommand();

		AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE getResponse();

	private:
		virtual void parseResponse(const std::vector<uint8_t>& buffer);

		std::shared_ptr<AMTHICommandResponse<AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE>> m_response;

		static const uint32_t RESPONSE_COMMAND_NUMBER = 0x4800086 ;
	};

	class CFG_SetOverrideProsetAdapterSwitchingCommandRequest : public AMTHICommandRequest
	{
	public:
		CFG_SetOverrideProsetAdapterSwitchingCommandRequest(bool OverrideEnabled);
		virtual ~CFG_SetOverrideProsetAdapterSwitchingCommandRequest();

	private:
		static const uint32_t REQUEST_COMMAND_NUMBER = 0x4000086;
		virtual unsigned int requestHeaderCommandNumber()
		{
			//this is the command number (taken from the AMTHI document)
			return REQUEST_COMMAND_NUMBER;
		}

		virtual uint32_t requestDataSize()
		{
			return sizeof(AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_REQUEST);
		}

		virtual std::vector<uint8_t> SerializeData();
		bool overrideEnabled_;
	};
} // namespace AMTHI_Client
} // namespace MEI_Client
} // namespace Intel

#endif //CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_COMMAND_H