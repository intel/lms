//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Capabilities.cpp
//
//  Contents:   Capabilities is an abstract class whose subclasses describe abilities and/or potential for use. For example, one may describe the maximum number of VLANs that can be supported on a system using a subclass of Capabilities. Capabilities are tied to the elements which they describe using the ElementCapabilities association. Note that the cardinality of the ManagedElement reference is Min(1), Max(1). This cardinality mandates the instantiation of the ElementCapabilities association for the referenced instance of Capabilities. ElementCapabilities describes the existence requirements and context for the referenced instance of ManagedElement. Specifically, the ManagedElement MUST exist and provides the context for the Capabilities. Note that Capabilities do not indicate what IS configured or operational, but what CAN or CANNOT exist, be defined or be used. Note that it is possible to describe both supported and excluded abilities and functions (both capabilities and limitations) using this class.
//
//              This file was automatically generated from CIM_Capabilities.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Capabilities::_metadata[] = {
		{"InstanceID", true, false, false },
		{"ElementName", false, true, false },
	};
	// class fields
	CimBase *CIM_Capabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_Capabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Capabilities>(object);
		}
		else
		{
			ret = new CIM_Capabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Capabilities> > CIM_Capabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Capabilities>(client, keys);
	}

	void CIM_Capabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Capabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Capabilities::CLASS_NAME = "CIM_Capabilities";
	const string CIM_Capabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Capabilities";
	const string CIM_Capabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Capabilities";
	const string CIM_Capabilities::CLASS_NS_PREFIX = "ACa538";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Capabilities::_classMetaData;
}
}
}
}
