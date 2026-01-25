//----------------------------------------------------------------------------
//
// Copyright (C) 2003 Intel Corporation
//
//  File:       
//
//  Contents:   
//
//----------------------------------------------------------------------------

#ifndef CIMPARAM_H
#define CIMPARAM_H 1
#include "CimData.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	// This class exists to enforce type checking on the Invoke function
	// in CimObject, to prevent passing it objects of type CimData.
	class CIMUNTYPEDFRAMEWORK_API CimParam : public CimData {
	public:
		CimParam()
		{
		}

	};
};
};
};
};

#endif // CIMPARAM_H