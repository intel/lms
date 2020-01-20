/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: AMTHIErrorException.h

--*/

#ifndef __AMTHI_ERROR_EXCEPTION_H
#define __AMTHI_ERROR_EXCEPTION_H

#include <string>
#include <stdexcept>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client { namespace AMTHI_Client	{
	static class amthi_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "amthi"; }
		virtual std::string message(int ev) const {
			return std::to_string(ev);
		}
	} amthi_category;

	class AMTHIErrorException : public MEIClientException
	{
	public:
		AMTHIErrorException(unsigned int err) : MEIClientException(err, amthi_category) {}
		virtual ~AMTHIErrorException() throw () {}

		virtual unsigned int getErr() const throw()
		{
			return code().value();
		}
	};
} /* namespace AMTHI_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__AMTHI_ERROR_EXCEPTION_H