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
#include <system_error>

namespace Intel { namespace MEI_Client {
	static class heci_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "heci"; }
		virtual std::string message(int ev) const {
#define TEE_ERR_STATE(state) case TEE_##state: return #state
			switch (ev) {
				TEE_ERR_STATE(SUCCESS);
				TEE_ERR_STATE(INTERNAL_ERROR);
				TEE_ERR_STATE(DEVICE_NOT_FOUND);
				TEE_ERR_STATE(DEVICE_NOT_READY);
				TEE_ERR_STATE(INVALID_PARAMETER);
				TEE_ERR_STATE(UNABLE_TO_COMPLETE_OPERATION);
				TEE_ERR_STATE(TIMEOUT);
				TEE_ERR_STATE(NOTSUPPORTED);
				TEE_ERR_STATE(CLIENT_NOT_FOUND);
				TEE_ERR_STATE(BUSY);
				TEE_ERR_STATE(DISCONNECTED);
				TEE_ERR_STATE(INSUFFICIENT_BUFFER);
			default:
				return std::to_string(ev);
			}
#undef TEE_ERR_STATE
		}
	} heci_category;

	class HECIException : public std::system_error
	{
	public:
		HECIException(const std::string &what, int err = TEE_INTERNAL_ERROR) : std::system_error(err, heci_category, what) {}
	};

	class HeciNoClientException : public HECIException
	{
	public:
		HeciNoClientException(const std::string &what, int err = TEE_INTERNAL_ERROR)
			: HECIException(what, err) {}
	};
} /* namespace MEI_Client */ } /* namespace Intel */

#endif //__HECI_EXCEPTION_H