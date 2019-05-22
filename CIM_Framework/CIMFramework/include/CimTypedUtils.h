//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimUtils.h
//
//  Contents:   Utility classes and functions for C++ CIM Framework, declarations
//
//----------------------------------------------------------------------------

#ifndef CIMTYPEDUTILS_H
#define CIMTYPEDUTILS_H 1

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>

#include "CimTypedDllExport.h"
#include "CimUtils.h"

#include "CimException.h"
#include "CimNamespaces.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Utils 
{
	using Intel::Manageability::Cim::Typed::CimBase;

	class CIMFRAMEWORK_API TypedTypeConverter
	{
	public:		
		// Type conversion function declarations		
		static void StringToType(const string& str, CimBase& t);
		static string TypeToString(const CimBase& t, const string &name = "");	
	};


}
}
}
}

#endif // CIMTYPEDUTILS_H
