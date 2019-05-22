//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareFeature.cpp
//
//  Contents:   The CIM_SoftwareFeature class defines a particular function or capability of a product or application system. This class captures a level of granularity describing a unit of installation, rather than the units that reflect how the product is built or packaged. The latter detail is captured using a CIM_SoftwareElement class. When a SoftwareFeature can exist on multiple platforms or operating systems (for example, a client component of a three tiered client/server application that runs on Solaris, Windows NT, and Windows 95), the Feature is a collection of all the SoftwareElements for these different platforms. In this case, the users of the model must be aware of this situation since typically they will be interested in a sub-collection of the SoftwareElements required for a particular platform. 
//              SoftwareFeatures are always defined in the context of a CIM_Product, using the CIM_ProductSoftwareFeature association. Features are delivered through Products. Optionally, SoftwareFeatures from one or more Products can be organized into ApplicationSystems using the CIM_ApplicationSystemSoftwareFeature association.
//
//              This file was automatically generated from CIM_SoftwareFeature.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_SoftwareFeature.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SoftwareFeature::_metadata[] = {
		{"IdentifyingNumber", true, false, false },
		{"ProductName", true, false, false },
		{"Vendor", true, false, false },
		{"Version", true, false, false },
		{"Name", true, false, false },
	};
	// class fields
	const string CIM_SoftwareFeature::IdentifyingNumber() const
	{
		return GetField("IdentifyingNumber")[0];
	}
	void CIM_SoftwareFeature::IdentifyingNumber(const string &value)
	{
		SetOrAddField("IdentifyingNumber", value);
	}

	const string CIM_SoftwareFeature::ProductName() const
	{
		return GetField("ProductName")[0];
	}
	void CIM_SoftwareFeature::ProductName(const string &value)
	{
		SetOrAddField("ProductName", value);
	}

	const string CIM_SoftwareFeature::Vendor() const
	{
		return GetField("Vendor")[0];
	}
	void CIM_SoftwareFeature::Vendor(const string &value)
	{
		SetOrAddField("Vendor", value);
	}

	const string CIM_SoftwareFeature::Version() const
	{
		return GetField("Version")[0];
	}
	void CIM_SoftwareFeature::Version(const string &value)
	{
		SetOrAddField("Version", value);
	}

	CimBase *CIM_SoftwareFeature::CreateFromCimObject(const CimObject &object)
	{
		CIM_SoftwareFeature *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SoftwareFeature>(object);
		}
		else
		{
			ret = new CIM_SoftwareFeature(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SoftwareFeature> > CIM_SoftwareFeature::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SoftwareFeature>(client, keys);
	}

	void CIM_SoftwareFeature::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SoftwareFeature::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SoftwareFeature::CLASS_NAME = "CIM_SoftwareFeature";
	const string CIM_SoftwareFeature::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareFeature";
	const string CIM_SoftwareFeature::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SoftwareFeature";
	const string CIM_SoftwareFeature::CLASS_NS_PREFIX = "ASo919";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SoftwareFeature::_classMetaData;
}
}
}
}
