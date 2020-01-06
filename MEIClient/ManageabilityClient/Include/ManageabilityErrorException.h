/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: ManageabilityErrorException.h

--*/

#ifndef __MANAGEABILITY_ERROR_EXCEPTION_H
#define __MANAGEABILITY_ERROR_EXCEPTION_H

#include <stdexcept>
#include <system_error>
#include <string>

namespace Intel { namespace MEI_Client { namespace Manageability_Client {
	enum
	{
		STATUS_SUCCESS = 0x0,
		STATUS_WEAR_OUT_VIOLATION = 0xA0,
		STATUS_NOT_READY = 0x88,
		STATUS_NOT_SUPPORTED = 0x89,
		STATUS_FAILURE = 0x9E,
		STATUS_UPDATE_NOT_ALLOWED = 0xA8,
	};

	static class manageability_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "manageability"; }
		virtual std::string message(int ev) const {
#define MNG_ERR_STATE(state) case STATUS_##state: return #state + std::string(" (") + std::to_string(ev) + std::string(")")
			switch (ev) {
				MNG_ERR_STATE(SUCCESS);
				MNG_ERR_STATE(WEAR_OUT_VIOLATION);
				MNG_ERR_STATE(NOT_READY);
				MNG_ERR_STATE(NOT_SUPPORTED);
				MNG_ERR_STATE(FAILURE);
				MNG_ERR_STATE(UPDATE_NOT_ALLOWED);
			default:
				return std::to_string(ev);
			}
#undef MNG_ERR_STATE
		}
	} manageability_category;

	class ManageabilityErrorException : public std::system_error
	{
	public:
		ManageabilityErrorException(unsigned int err) : std::system_error(err, manageability_category) {}
		virtual ~ManageabilityErrorException() throw (){}
		virtual unsigned int getErr() const throw()
		{
			return code().value();
		}
	};
} /* namespace Manageability_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__MANAGEABILITY_ERROR_EXCEPTION_H
