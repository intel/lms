//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ManagedElement.cpp
//
//  Contents:   ManagedElement is an abstract class that provides a common superclass (or top of the inheritance tree) for the non-association classes in the CIM Schema.
//
//              This file was automatically generated from CIM_ManagedElement.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ManagedElement::_metadata[] = {
		{"InstanceID", false, false, false },
		{"Caption", false, false, false },
		{"Description", false, false, false },
		{"ElementName", false, false, false },
	};
	// class fields
	const string CIM_ManagedElement::InstanceID() const
	{
		return GetField("InstanceID")[0];
	}
	void CIM_ManagedElement::InstanceID(const string &value)
	{
		SetOrAddField("InstanceID", value);
	}
	bool CIM_ManagedElement::InstanceIDExists() const
	{
		return ContainsField("InstanceID");
	}
	void CIM_ManagedElement::RemoveInstanceID()
	{
		RemoveField("InstanceID");
	}

	const string CIM_ManagedElement::Caption() const
	{
		return GetField("Caption")[0];
	}
	void CIM_ManagedElement::Caption(const string &value)
	{
		SetOrAddField("Caption", value);
	}
	bool CIM_ManagedElement::CaptionExists() const
	{
		return ContainsField("Caption");
	}
	void CIM_ManagedElement::RemoveCaption()
	{
		RemoveField("Caption");
	}

	const string CIM_ManagedElement::Description() const
	{
		return GetField("Description")[0];
	}
	void CIM_ManagedElement::Description(const string &value)
	{
		SetOrAddField("Description", value);
	}
	bool CIM_ManagedElement::DescriptionExists() const
	{
		return ContainsField("Description");
	}
	void CIM_ManagedElement::RemoveDescription()
	{
		RemoveField("Description");
	}

	const string CIM_ManagedElement::ElementName() const
	{
		return GetField("ElementName")[0];
	}
	void CIM_ManagedElement::ElementName(const string &value)
	{
		SetOrAddField("ElementName", value);
	}
	bool CIM_ManagedElement::ElementNameExists() const
	{
		return ContainsField("ElementName");
	}
	void CIM_ManagedElement::RemoveElementName()
	{
		RemoveField("ElementName");
	}

	CimBase *CIM_ManagedElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ManagedElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ManagedElement>(object);
		}
		else
		{
			ret = new CIM_ManagedElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ManagedElement> > CIM_ManagedElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ManagedElement>(client, keys);
	}

	void CIM_ManagedElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ManagedElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ManagedElement::CLASS_NAME = "CIM_ManagedElement";
	const string CIM_ManagedElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedElement";
	const string CIM_ManagedElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedElement";
	const string CIM_ManagedElement::CLASS_NS_PREFIX = "AMa213";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ManagedElement::_classMetaData;
}
}
}
}
