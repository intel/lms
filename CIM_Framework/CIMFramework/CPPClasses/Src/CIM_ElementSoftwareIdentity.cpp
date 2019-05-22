//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementSoftwareIdentity.cpp
//
//  Contents:   ElementSoftwareIdentity allows a Managed Element to report its software related asset information (firmware, drivers, configuration software, and etc.)
//
//              This file was automatically generated from CIM_ElementSoftwareIdentity.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_ElementSoftwareIdentity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ElementSoftwareIdentity::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
		{"UpgradeCondition", false, false, false },
		{"OtherUpgradeCondition", false, false, false },
		{"ElementSoftwareStatus", false, false, false },
	};
	// class fields
	const unsigned short CIM_ElementSoftwareIdentity::UpgradeCondition() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("UpgradeCondition"), ret);
		return ret;
	}
	void CIM_ElementSoftwareIdentity::UpgradeCondition(const unsigned short value)
	{
		SetOrAddField("UpgradeCondition", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementSoftwareIdentity::UpgradeConditionExists() const
	{
		return ContainsField("UpgradeCondition");
	}
	void CIM_ElementSoftwareIdentity::RemoveUpgradeCondition()
	{
		RemoveField("UpgradeCondition");
	}

	const string CIM_ElementSoftwareIdentity::OtherUpgradeCondition() const
	{
		return GetField("OtherUpgradeCondition")[0];
	}
	void CIM_ElementSoftwareIdentity::OtherUpgradeCondition(const string &value)
	{
		SetOrAddField("OtherUpgradeCondition", value);
	}
	bool CIM_ElementSoftwareIdentity::OtherUpgradeConditionExists() const
	{
		return ContainsField("OtherUpgradeCondition");
	}
	void CIM_ElementSoftwareIdentity::RemoveOtherUpgradeCondition()
	{
		RemoveField("OtherUpgradeCondition");
	}

	const vector<unsigned short> CIM_ElementSoftwareIdentity::ElementSoftwareStatus() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ElementSoftwareStatus"), ret);
		return ret;
	}
	void CIM_ElementSoftwareIdentity::ElementSoftwareStatus(const vector<unsigned short> &value)
	{
		SetOrAddField("ElementSoftwareStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ElementSoftwareIdentity::ElementSoftwareStatusExists() const
	{
		return ContainsField("ElementSoftwareStatus");
	}
	void CIM_ElementSoftwareIdentity::RemoveElementSoftwareStatus()
	{
		RemoveField("ElementSoftwareStatus");
	}

	CimBase *CIM_ElementSoftwareIdentity::CreateFromCimObject(const CimObject &object)
	{
		CIM_ElementSoftwareIdentity *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ElementSoftwareIdentity>(object);
		}
		else
		{
			ret = new CIM_ElementSoftwareIdentity(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ElementSoftwareIdentity> > CIM_ElementSoftwareIdentity::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ElementSoftwareIdentity>(client, keys);
	}

	void CIM_ElementSoftwareIdentity::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ElementSoftwareIdentity::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ElementSoftwareIdentity::CLASS_NAME = "CIM_ElementSoftwareIdentity";
	const string CIM_ElementSoftwareIdentity::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementSoftwareIdentity";
	const string CIM_ElementSoftwareIdentity::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementSoftwareIdentity";
	const string CIM_ElementSoftwareIdentity::CLASS_NS_PREFIX = "AEl207";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ElementSoftwareIdentity::_classMetaData;
}
}
}
}
