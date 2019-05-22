/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: ManageabilityErrorException.h

--*/

#ifndef __MANAGEABILITY_ERROR_EXCEPTION_H
#define __MANAGEABILITY_ERROR_EXCEPTION_H

#include <stdexcept>

namespace Intel
{
	namespace MEI_Client
	{
		namespace Manageability_Client
		{
			class ManageabilityErrorException : public std::exception
			{
			private:
				unsigned int error;

			public:
				ManageabilityErrorException(unsigned int err)
					:error(err){}
				virtual ~ManageabilityErrorException() throw (){}
				virtual unsigned int getErr() const throw()
				{
					return error;
				}
			};
		} // namespace Manageability_Client
	} //namespace MEI_Client
} // namespace Intel

#endif //__MANAGEABILITY_ERROR_EXCEPTION_H

