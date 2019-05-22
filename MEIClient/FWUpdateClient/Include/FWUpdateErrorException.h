/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: FWUpdateErrorException.h

--*/

#ifndef __FW_UPDATE_ERROR_EXCEPTION_H
#define __FW_UPDATE_ERROR_EXCEPTION_H

#include <string>
#include <stdexcept>

namespace Intel
{
	namespace MEI_Client
	{
		namespace FWUpdate_Client
		{
			class FWUpdateErrorException : public std::exception
			{
			private:
				unsigned int error;

			public:
				FWUpdateErrorException(unsigned int err)
					:error(err){}
				virtual ~FWUpdateErrorException() throw (){}

				virtual unsigned int getErr() const throw()
				{
					return error;
				}
			};
		} // namespace FWUpdate_Client
	} //namespace MEI_Client
} // namespace Intel

#endif //__FW_UPDATE_ERROR_EXCEPTION_H

