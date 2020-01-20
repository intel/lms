/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: MKHIErrorException.h

--*/

#ifndef __MKHI_ERROR_EXCEPTION_H
#define __MKHI_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client { namespace MKHI_Client {
	enum MKHI_STATUS
	{
		MKHI_STATUS_SUCCESS = 0x0,
		MKHI_STATUS_INVALID_STATE = 0x1,
		MKHI_STATUS_MESSAGE_SKIPPED = 0x2,
		MKHI_STATUS_SIZE_ERROR = 0x5,
		MKHI_STATUS_ENINVAL = 0x16,
		MKHI_STATUS_NOT_FOUND = 0x81,
		MKHI_STATUS_INVALID_ACCESS = 0x84,
		MKHI_STATUS_INVALID_PARAMS = 0x85,
		MKHI_STATUS_NOT_READY = 0x88,
		MKHI_STATUS_NOT_SUPPORTED = 0x89,
		MKHI_STATUS_INVALID_ADDRESS = 0x8C,
		MKHI_STATUS_INVALID_COMMAND = 0x8D,
		MKHI_STATUS_FAILURE = 0x9E,
		MKHI_STATUS_GENERIC_FAILURE = 0x99,
		MKHI_STATUS_INVALID_RESOURCE = 0xE4,
		MKHI_STATUS_RESOURCE_IN_USE = 0xE5,
		MKHI_STATUS_NO_RESOURCE = 0xE6,
		MKHI_STATUS_RETRY = 0xFE,
		MKHI_STATUS_GENERAL_ERROR = 0xFF,
	};

	static class mkhi_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "mkhi"; }
		virtual std::string message(int ev) const {
#define MKHI_ERR_STATE(state) case MKHI_STATUS_##state: return #state + std::string(" (") + std::to_string(ev) + std::string(")")
			switch (ev) {
				MKHI_ERR_STATE(SUCCESS);
				MKHI_ERR_STATE(INVALID_STATE);
				MKHI_ERR_STATE(MESSAGE_SKIPPED);
				MKHI_ERR_STATE(SIZE_ERROR);
				MKHI_ERR_STATE(ENINVAL);
				MKHI_ERR_STATE(NOT_FOUND);
				MKHI_ERR_STATE(INVALID_ACCESS);
				MKHI_ERR_STATE(INVALID_PARAMS);
				MKHI_ERR_STATE(NOT_READY);
				MKHI_ERR_STATE(NOT_SUPPORTED);
				MKHI_ERR_STATE(INVALID_ADDRESS);
				MKHI_ERR_STATE(INVALID_COMMAND);
				MKHI_ERR_STATE(FAILURE);
				MKHI_ERR_STATE(GENERIC_FAILURE);
				MKHI_ERR_STATE(INVALID_RESOURCE);
				MKHI_ERR_STATE(RESOURCE_IN_USE);
				MKHI_ERR_STATE(NO_RESOURCE);
				MKHI_ERR_STATE(RETRY);
				MKHI_ERR_STATE(GENERAL_ERROR);
			default:
				return std::to_string(ev);
			}
#undef TEE_ERR_STATE
		}
	} mkhi_category;

	class MKHIErrorException : public MEIClientException
	{
	public:
		MKHIErrorException(unsigned int err): MEIClientException(err, mkhi_category){}
		virtual ~MKHIErrorException() throw (){}
		virtual unsigned int getErr() const throw()
		{
			return code().value();
		}
	};
} /* namespace MKHI_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__MKHI_ERROR_EXCEPTION_H

