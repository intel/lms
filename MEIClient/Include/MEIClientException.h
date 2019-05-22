/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: MEIClientException.h

--*/

#ifndef __MEI_CLIENT_EXCEPTION_H
#define __MEI_CLIENT_EXCEPTION_H

#include <string>
#include <stdexcept>
#include <sstream>

namespace Intel
{
	namespace MEI_Client
	{
		class MEIClientException : public std::exception
		{
		private:
			std::string _what;

			struct Formater
			{
				const std::string &what_;
				unsigned long long binaryData_;
				Formater(const std::string &what, unsigned long long binaryData):
					what_(what), binaryData_(binaryData) {}
				operator std::string() const { std::stringstream ss; ss << what_ << " Inner data: " << binaryData_; return ss.str(); }
			};

		public:
			MEIClientException(const std::string &what)
				:_what(what){}

			MEIClientException(const std::string &what, unsigned long long innerData)
				:_what(Formater(what, innerData)){}

			virtual ~MEIClientException() throw (){}
			virtual std::string getDetail()
			{
				return _what;
			}
			virtual const char *what() const throw() 
			{ 
			  return _what.c_str(); 
			}
		};
	} //namespace MEI_Client
} // namespace Intel

#endif //__MEI_CLIENT_EXCEPTION_H

