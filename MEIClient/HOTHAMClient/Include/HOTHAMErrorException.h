/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: HOTHAMErrorException.h

--*/

#ifndef __HOTHAM_ERROR_EXCEPTION_H
#define __HOTHAM_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client { namespace HOTHAM_Client {
	static class hotham_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "hotham"; }
		virtual std::string message(int ev) const {
			return std::to_string(ev);
		}
	} hotham_category;

	class HOTHAMErrorException : public MEIClientException
	{
	public:
		HOTHAMErrorException(unsigned int err) : MEIClientException(err, hotham_category) {}
		virtual ~HOTHAMErrorException() throw (){}
		virtual unsigned int getErr() const throw()
		{
			return code().value();
		}
	};
} /* namespace HOTHAM_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__HOTHAM_ERROR_EXCEPTION_H

