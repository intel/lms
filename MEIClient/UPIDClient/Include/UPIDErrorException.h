/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
/*++

@file: UPIDErrorException.h

--*/

#ifndef __UPID_ERROR_EXCEPTION_H
#define __UPID_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "MEIClientException.h"

namespace Intel { 
	namespace MEI_Client { 
		namespace UPID_Client {
			
			enum UPID_STATUS
			{
				UPID_STATUS_SUCCESS = 0x0,
				UPID_STATUS_FEATURE_NOT_SUPPORTED = 0x1,
				UPID_STATUS_INVALID_INPUT_PARAMETER = 0x2,
				UPID_STATUS_INTERNAL_ERROR = 0x3,
				UPID_STATUS_NOT_ALLOWED_AFTER_EOP = 0x4,
				UPID_STATUS_NOT_ALLOWED_AFTER_MANUF_LOCK = 0x5,
				UPID_STATUS_MAX_COUNTERS_EXCEEDED = 0x6,
			};

			static class upid_category_t : public std::error_category {
			public:
				virtual const char* name() const noexcept { return "upid"; }
				virtual std::string message(int ev) const {
					return std::to_string(ev);
				}
			} upid_category;

			class UPIDErrorException : public MEIClientException
			{
			public:
				UPIDErrorException(unsigned int err) : MEIClientException(err, upid_category) {}
				virtual ~UPIDErrorException() noexcept {}
				virtual unsigned int getErr() const noexcept
				{
					return code().value();
				}
			};
		} /* namespace UPID_Client */ 
	} /* namespace MEI_Client */ 
} /* namespace Intel */

#endif //__UPID_ERROR_EXCEPTION_H

