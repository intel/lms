/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021 Intel Corporation
 */
/*++

@file: PSRErrorException.h

--*/

#ifndef __PSR_ERROR_EXCEPTION_H
#define __PSR_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client { namespace PSR_Client {
	enum PSR_STATUS
	{
		PSR_STATUS_SUCCESS,
		PSR_STATUS_FEATURE_NOT_SUPPORTED,
		PSR_STATUS_UPID_DISABLED,
		PSR_STATUS_ACTION_NOT_ALLOWED,
		PSR_STATUS_INVALID_INPUT_PARAMETER,
		PSR_STATUS_INTERNAL_ERROR,
		PSR_STATUS_NOT_ALLOWED_AFTER_EOP,
	};

	static class psr_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "psr"; }
		virtual std::string message(int ev) const {
#define PSR_ERR_STATE(state) case PSR_STATUS_##state: return #state + std::string(" (") + std::to_string(ev) + std::string(")")
			switch (ev) {
				PSR_ERR_STATE(SUCCESS);
				PSR_ERR_STATE(FEATURE_NOT_SUPPORTED);
				PSR_ERR_STATE(UPID_DISABLED);
				PSR_ERR_STATE(ACTION_NOT_ALLOWED);
				PSR_ERR_STATE(INVALID_INPUT_PARAMETER);
				PSR_ERR_STATE(INTERNAL_ERROR);
				PSR_ERR_STATE(NOT_ALLOWED_AFTER_EOP);
			default:
				return std::to_string(ev);
			}
#undef PSR_ERR_STATE
		}
	} psr_category;

	class PSRErrorException : public MEIClientException
	{
	public:
		PSRErrorException(unsigned int err): MEIClientException(err, psr_category){}
		virtual ~PSRErrorException() noexcept {}
		virtual unsigned int getErr() const noexcept
		{
			return code().value();
		}
	};
} /* namespace PSR_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__PSR_ERROR_EXCEPTION_H

