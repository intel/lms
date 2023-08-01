/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022 Intel Corporation
 */
/*++

@file: MCHIErrorException.h

--*/

#ifndef __MCHI_ERROR_EXCEPTION_H
#define __MCHI_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "MEIClientException.h"

namespace Intel { namespace MEI_Client { namespace MCHI_Client {
	enum MCA_STATUS
	{
		MCA_STATUS_SUCCESS = 0x0,
		MCA_STATUS_NO_FILE = 0x3,
		MCA_STATUS_NO_FILE_ATTRIBUTE = 0x7,
		MCA_STATUS_MANUF_NOT_ALLOWED = 0x9,
		MCA_STATUS_INVALID_INPUT = 0xB,
		MCA_STATUS_SIZE_EXCEED_LIMIT = 0xD,
		MCA_STATUS_INVALID_ATTR_HASH = 0xE,
		MCA_STATUS_FPF_INTERNAL = 0x10,
		MCA_STATUS_FPF_FATAL = 0x12,
		MCA_STATUS_GENERAL_ERROR = 0x18,
	};


	static class mchi_category_t : public std::error_category {
	public:
		virtual const char* name() const noexcept { return "mchi"; }
		virtual std::string message(int ev) const {
#define MCHI_ERR_STATE(state) case MCA_STATUS_##state: return #state + std::string(" (") + std::to_string(ev) + std::string(")")
			switch (ev) {
				MCHI_ERR_STATE(SUCCESS);
				MCHI_ERR_STATE(NO_FILE);
				MCHI_ERR_STATE(NO_FILE_ATTRIBUTE);
				MCHI_ERR_STATE(MANUF_NOT_ALLOWED);
				MCHI_ERR_STATE(INVALID_INPUT);
				MCHI_ERR_STATE(SIZE_EXCEED_LIMIT);
				MCHI_ERR_STATE(INVALID_ATTR_HASH);
				MCHI_ERR_STATE(FPF_FATAL);
				MCHI_ERR_STATE(GENERAL_ERROR);
			default:
				return std::to_string(ev);
			}
#undef MCHI_ERR_STATE
		}
	} mchi_category;

	class MCHIErrorException : public MEIClientException
	{
	public:
		MCHIErrorException(unsigned int err): MEIClientException(err, mchi_category){}
		virtual ~MCHIErrorException() noexcept {}
		virtual unsigned int getErr() const noexcept
		{
			return code().value();
		}
	};
	class MCHIErrorExceptionNoFile : public MCHIErrorException
	{
	public:
		MCHIErrorExceptionNoFile(int err)
			: MCHIErrorException(err) {}
	};
} /* namespace MCHI_Client */ } /* namespace MEI_Client */ } /* namespace Intel */

#endif //__MCHI_ERROR_EXCEPTION_H

