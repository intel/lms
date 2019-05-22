/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: AMTHIErrorException.h

--*/

#ifndef __AMTHI_ERROR_EXCEPTION_H
#define __AMTHI_ERROR_EXCEPTION_H

#include <string>
#include <stdexcept>

namespace Intel
{
namespace MEI_Client
{
namespace AMTHI_Client
{
	class AMTHIErrorException : public std::exception
	{
	private:
		unsigned int error;
		std::string _what;

		struct Formater
		{
			unsigned long long binaryData_;
			Formater(unsigned long long binaryData): binaryData_(binaryData) {}
			operator std::string() const { std::stringstream ss; ss << " Binary data: " << binaryData_; return ss.str(); }
		};

	public:
		AMTHIErrorException(unsigned int err)
			:error(err), _what(Formater(err)) {}
		virtual ~AMTHIErrorException() throw (){}

		virtual const char *what() const throw() 
		{ 
		  return _what.c_str(); 
		}
		virtual unsigned int getErr() const throw()
		{
			return error;
		}
	};
} // namespace AMTHI_Client

} //namespace MEI_Client

} // namespace Intel

#endif //__AMTHI_ERROR_EXCEPTION_H

