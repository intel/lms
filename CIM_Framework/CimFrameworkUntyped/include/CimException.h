//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimException.h
//
//  Contents:   Exceptions for use by CIM framework, declarations.
//
//----------------------------------------------------------------------------

#ifndef CIMEXCEPTION_H
#define CIMEXCEPTION_H 1

#include <stdexcept>
#include "CimUntypedDllExport.h"

namespace Intel
{
	namespace Manageability
	{
		namespace Exceptions 
		{
			using std::logic_error;
			using std::runtime_error;
			using std::invalid_argument;
			using std::string;

			// Exception class which represents general logic error.
			class CIMUNTYPEDFRAMEWORK_API CimException : public logic_error
			{
				public:
					// Constructors.
					CimException();	
					explicit CimException(const string &message);
					CimException& operator=(const CimException& other);
					CimException(const CimException &other);
					~CimException() throw();
					

				
			};

			// Exception class which represents error in WS-Management operation.
			class CIMUNTYPEDFRAMEWORK_API WSManException : public runtime_error
			{
			public:
				/*enum ExceptionType
				{
					HTTP_EXCEPTION,
					WSMAN_EXCEPTION,
					UNKNOWN_EXCEPTION
				};*/

				// Constructors.
				WSManException();
				WSManException(const WSManException &Other);
				explicit WSManException(const string &message);//, ExceptionType ex_type = UNKNOWN_EXCEPTION);
				WSManException& operator=(const WSManException& other);
				~WSManException() throw();
				//ExceptionType type;
			};

			// Exception class which represents HTTP connection error.
			class CIMUNTYPEDFRAMEWORK_API HTTPException : public runtime_error
			{
			public:
				// Constructors.
				HTTPException();
				HTTPException(const HTTPException &Other);
				explicit HTTPException(const string &message);
				HTTPException& operator=(const HTTPException& other);
				~HTTPException() throw();
			};

			// Exception class which represents error when attempting to convert a value to / from string.
			class CIMUNTYPEDFRAMEWORK_API ConversionException : public invalid_argument
			{
			public:
				// Constructors.
				ConversionException();
				ConversionException(const ConversionException &other);
				ConversionException& operator=(const ConversionException& other);
				explicit ConversionException(const string &message);
				~ConversionException() throw();
			};

			// Exception class which represents a property access error in the framework.
			class CIMUNTYPEDFRAMEWORK_API CimPropertyException : public CimException
			{  
			public:
				CimPropertyException();
				CimPropertyException(const CimPropertyException &other);
				CimPropertyException& operator=(const CimPropertyException& other);
				explicit CimPropertyException(const string message);
				~CimPropertyException() throw();
			};
		};
	};
};

#endif // CIMEXCEPTION_H
