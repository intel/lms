/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: MKHIErrorException.h

--*/

#ifndef __MKHI_ERROR_EXCEPTION_H
#define __MKHI_ERROR_EXCEPTION_H

#include <stdexcept>

namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			class MKHIErrorException : public std::exception
			{
			private:
				unsigned int error;

			public:
				MKHIErrorException(unsigned int err)
					:error(err){}
				virtual ~MKHIErrorException() throw (){}
				virtual unsigned int getErr() const throw()
				{
					return error;
				}
			};
		} // namespace MKHI_Client
	} //namespace MEI_Client
} // namespace Intel

#endif //__MKHI_ERROR_EXCEPTION_H

