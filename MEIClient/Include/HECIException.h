/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2020 Intel Corporation
 */
/*++

@file: HECIException.h

--*/

#ifndef __HECI_EXCEPTION_H
#define __HECI_EXCEPTION_H

#include <string>
#include <stdexcept>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client {
	static class heci_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "heci"; }
		virtual std::string message(int ev) const;
	} heci_category;

	class HECIException : public MEIClientException
	{
	public:
		HECIException(const std::string &what, int err) : MEIClientException(err, heci_category, what) {}
	};

	class HeciNoClientException : public HECIException
	{
	public:
		HeciNoClientException(const std::string &what, int err)
			: HECIException(what, err) {}
	};
} /* namespace MEI_Client */ } /* namespace Intel */

#endif //__HECI_EXCEPTION_H