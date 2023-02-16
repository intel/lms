/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: HTMGetFLogCommand.cpp

--*/

#include "HTMGetFLogCommand.h"

namespace Intel { namespace MEI_Client { namespace HOTHAM_Client {
	HTMGetFatalErrorsCommand::HTMGetFatalErrorsCommand()
	{
		std::shared_ptr<MEICommandRequest> tmp(new HTMGetFatalErrorsRequest());
		m_request = tmp;
		Transact();
	}

	GET_FLOG_RESP HTMGetFatalErrorsCommand::getResponse()
	{
		return m_response->getResponse();
	}

	void  HTMGetFatalErrorsCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		std::shared_ptr<HOTHAMCommandResponse<GET_FLOG_RESP>> tmp(new HOTHAMCommandResponse<GET_FLOG_RESP>(buffer));
		m_response = tmp;
	}
} /* namespace HOTHAM_Client */ } /* namespace MEI_Client */ } /* namespace Intel */