//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimException.cpp
//
//  Contents:   Exceptions for use by CIM framework, implementation.
//
//----------------------------------------------------------------------------

#include "CimException.h"



namespace Intel
{
namespace Manageability
{
namespace Exceptions 
{
	CimException::CimException()
		: logic_error("Unknown CIM Exception")
	{
	}

	CimException::CimException(const string &message)
		: logic_error(message)
	{
	}

	CimException::CimException(const CimException &other)
		: logic_error(other)
	{
	}

	CimException& CimException::operator=(const CimException& other)
	{
		if(this != &other)
		{
			logic_error::operator=(other);
		}
		return *this;
	}

	CimException::~CimException() throw()
	{
	}


	WSManException::WSManException()
		: runtime_error("Unknown WSMan Exception")
	{
	}

	WSManException::WSManException(const WSManException &Other)
		: runtime_error(Other)
	{
	}


	WSManException::WSManException(const string &message)
								: runtime_error(message)
	{
	}


	WSManException& WSManException::operator=(const WSManException& other)
	{
		if(this != &other)
		{
			runtime_error::operator=(other);
		}
		return *this;
	}

	WSManException::~WSManException() throw()
	{
	}

	HTTPException::HTTPException()
		: runtime_error("Unknown WSMan Exception")
	{
	}

	HTTPException::HTTPException(const HTTPException &Other)
		: runtime_error(Other)
	{
	}


	HTTPException::HTTPException(const string &message)
								: runtime_error(message)
	{
	}


	HTTPException& HTTPException::operator=(const HTTPException& other)
	{
		if(this != &other)
		{
			runtime_error::operator=(other);
		}
		return *this;
	}

	HTTPException::~HTTPException() throw()
	{
	}




	ConversionException::ConversionException()
		: invalid_argument("Unknown Conversion Exception")
	{
	}

	ConversionException::ConversionException(const string &message)
		: invalid_argument(message)
	{
	}

	ConversionException::ConversionException(const ConversionException &other)
		: invalid_argument(other)
	{
	}

	ConversionException& ConversionException::operator=(const ConversionException& other)
	{
		if(this != &other)
		{
			invalid_argument::operator=(other);
		}
		return *this;
	}

	ConversionException::~ConversionException() throw()
	{
	}
	 
	CimPropertyException::CimPropertyException()
	: CimException("Property access error in CIM Framework")
	{
	}

	CimPropertyException::CimPropertyException(const string message)
	: CimException(message)
	{
	}

	CimPropertyException::CimPropertyException(const CimPropertyException &other)
		: CimException(other)
	{
	}

	CimPropertyException& CimPropertyException::operator=(const CimPropertyException& other)
	{
		if(this != &other)
		{
			CimException::operator=(other);
		}
		return *this;
	}

	CimPropertyException::~CimPropertyException() throw()
	{
	}

};
};
};
