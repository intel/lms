/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
 */
/*++

@file: HECIException.h

--*/

#ifndef __HECI_EXCEPTION_H
#define __HECI_EXCEPTION_H

#include "MEIClientException.h"
#include <string>

namespace Intel
{
	namespace MEI_Client
	{
		class HECIException : public MEIClientException
		{
		private:
			unsigned long long _innerData;

		public:
			HECIException(const std::string &what)
				:MEIClientException(what), _innerData(0) {}

			HECIException(const std::string &what, unsigned long long innerData)
				:MEIClientException(what, innerData), _innerData(innerData) {}

			unsigned long long getInnerData()
			{
				return _innerData;
			}
		};

		class HeciNoClientException : public HECIException
		{
		public:
			HeciNoClientException(const std::string &what)
				:HECIException(what) {}

			HeciNoClientException(const std::string &what, unsigned long long innerData)
				:HECIException(what, innerData) {}
		};
	} //namespace MEI_Client
} // namespace Intel

#endif //__HECI_EXCEPTION_H

