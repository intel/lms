/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: FWUpdateErrorException.h

--*/

#ifndef __FW_UPDATE_ERROR_EXCEPTION_H
#define __FW_UPDATE_ERROR_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <system_error>

namespace Intel { namespace MEI_Client { namespace FWUpdate_Client {
	static class fwupd_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "fwupd"; }
		virtual std::string message(int ev) const {
			return std::to_string(ev);
		}
	} fwupd_category;

	class FWUpdateErrorException : public std::system_error
	{
	public:
		FWUpdateErrorException(unsigned int err) : std::system_error(err, fwupd_category) {}
		virtual ~FWUpdateErrorException() throw (){}
		virtual unsigned int getErr() const throw()
		{
			return code().value();
		}
	};
} /* namespace FWUpdate_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__FW_UPDATE_ERROR_EXCEPTION_H

