/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: MEIClientException.h

--*/

#ifndef __MEI_CLIENT_EXCEPTION_H
#define __MEI_CLIENT_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <system_error>

namespace Intel { namespace MEI_Client {
	static class mei_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "mei"; }
		virtual std::string message(int ev) const {
			return std::to_string(ev);
		}
	} mei_category;

	class MEIClientException : public std::system_error
	{
	public:
		MEIClientException(const std::string &what, int err = 0) : std::system_error(err, mei_category, what) {}
		MEIClientException(int err, const std::error_category& cat) : std::system_error(err, cat) {}
		MEIClientException(int err, const std::error_category& cat, const std::string& what)
			: std::system_error(err, cat, what) {}
		virtual ~MEIClientException() noexcept {}
	};
	class MEIClientExceptionZeroBuffer : public MEIClientException
	{
	public:
		MEIClientExceptionZeroBuffer(const std::string &what, int err = 0) : MEIClientException(what, err) {}
		virtual ~MEIClientExceptionZeroBuffer() noexcept {}
	};
} /* namespace MEI_Client */ } /* namespace Intel */

#endif //__MEI_CLIENT_EXCEPTION_H