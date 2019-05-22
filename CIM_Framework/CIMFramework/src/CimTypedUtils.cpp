//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimUtils.cpp
//
//  Contents:   Utility classes and functions for C++ CIM Framework, implementation
//
//----------------------------------------------------------------------------

#include <cstdlib>

#include "CimTypedUtils.h"
#include "CimBase.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Utils 
{


	void TypedTypeConverter::StringToType(const string& str, CimBase& t)
	{
		t.Deserialize(str);
	}
	string TypedTypeConverter::TypeToString(const CimBase& t, const string &name)
	{
		return t.Serialize(name);
	}


};
};
};
};
