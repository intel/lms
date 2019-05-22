/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: HOTHAMErrorException.h

--*/

#ifndef __HOTHAM_ERROR_EXCEPTION_H
#define __HOTHAM_ERROR_EXCEPTION_H

#include <stdexcept>

namespace Intel
{
	namespace MEI_Client
	{
		namespace HOTHAM_Client
		{
			class HOTHAMErrorException : public std::exception
			{
			private:
				unsigned int error;

			public:
				HOTHAMErrorException(unsigned int err)
					:error(err){}
				virtual ~HOTHAMErrorException() throw (){}
				virtual unsigned int getErr() const throw()
				{
					return error;
				}
			};
		} // namespace HOTHAM_Client
	} //namespace MEI_Client
} // namespace Intel

#endif //__HOTHAM_ERROR_EXCEPTION_H

