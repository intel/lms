/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
/*++

@file: HOTHAMCommand.cpp

--*/

#include "HOTHAMCommand.h"
#include "HECI_if.h"

namespace Intel { namespace MEI_Client { namespace HOTHAM_Client {
	const GUID& HOTHAMCommand::getGUID()
	{
		return HECI_HOTHAM_GUID;
	}

	std::vector<uint8_t> HOTHAMCommandRequest::Serialize()
	{
		HTM_MSG_HDR_REQUEST header;
		header.ul = 0; //initialize to 0
		//put data in correct bits

		header.ReqHeaderCommon.Fields.HeaderType = 0;
		header.ReqHeaderType0.Fields.ReqCode = requestHeaderReqCode();
		header.ReqHeaderType0.Fields.MsgClass = requestHeaderMsgClass();
		header.ReqHeaderType0.Fields.MsgLength = 0;
		header.ReqHeaderType0.Fields.SequenceNo = 0;
		header.ReqHeaderType0.Fields.TargetId = 1;

		std::vector<uint8_t> output = serializeHeader(header);
		std::vector<uint8_t> dataOutput = SerializeData();
		output.insert(output.end(), dataOutput.begin(), dataOutput.end());
		return output;
	}

	std::vector<uint8_t> HOTHAMCommandRequest::serializeHeader(const HTM_MSG_HDR_REQUEST& header)
	{
		return Intel::MEI_Client::serializeHeader<HTM_MSG_HDR_REQUEST>(header);
	}

	std::mutex& HOTHAMCommand::getInternalSemaphore()
	{
		static std::mutex internalSemaphore;

		return internalSemaphore;
	}

	HOTHAMCommand::SemaphoreInitializer::SemaphoreInitializer()
	{
		HOTHAMCommand::getInternalSemaphore();
	}

	HOTHAMCommand::SemaphoreInitializer HOTHAMCommand::SemaphoreInitializer::initializer;
} /* namespace HOTHAM_Client */ } /* namespace MEI_Client */ } /* namespace Intel */