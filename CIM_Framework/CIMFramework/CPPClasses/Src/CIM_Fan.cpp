//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Fan.cpp
//
//  Contents:   Capabilities and management of a Fan CoolingDevice.
//
//              This file was automatically generated from CIM_Fan.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_Fan.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Fan::_metadata[] = {
		{"VariableSpeed", false, false, false },
		{"DesiredSpeed", false, false, false },
	};
	// class fields
	const bool CIM_Fan::VariableSpeed() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("VariableSpeed"), ret);
		return ret;
	}
	void CIM_Fan::VariableSpeed(const bool value)
	{
		SetOrAddField("VariableSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_Fan::VariableSpeedExists() const
	{
		return ContainsField("VariableSpeed");
	}
	void CIM_Fan::RemoveVariableSpeed()
	{
		RemoveField("VariableSpeed");
	}

	const Uint64 CIM_Fan::DesiredSpeed() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("DesiredSpeed"), ret);
		return ret;
	}
	void CIM_Fan::DesiredSpeed(const Uint64 value)
	{
		SetOrAddField("DesiredSpeed", TypeConverter::TypeToString(value));
	}
	bool CIM_Fan::DesiredSpeedExists() const
	{
		return ContainsField("DesiredSpeed");
	}
	void CIM_Fan::RemoveDesiredSpeed()
	{
		RemoveField("DesiredSpeed");
	}

	CimBase *CIM_Fan::CreateFromCimObject(const CimObject &object)
	{
		CIM_Fan *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Fan>(object);
		}
		else
		{
			ret = new CIM_Fan(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Fan> > CIM_Fan::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Fan>(client, keys);
	}

	void CIM_Fan::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Fan::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_Fan::SetSpeed_INPUT::_metadata[] = {
		{"DesiredSpeed", false, false },
	};
	void CIM_Fan::SetSpeed_INPUT::DesiredSpeed(const Uint64 value)
	{
		SetOrAddField("DesiredSpeed", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Fan::SetSpeed_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_Fan::SetSpeed(const SetSpeed_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetSpeed", input, output);
	}
	const string CIM_Fan::CLASS_NAME = "CIM_Fan";
	const string CIM_Fan::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Fan";
	const string CIM_Fan::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Fan";
	const string CIM_Fan::CLASS_NS_PREFIX = "AFa155";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Fan::_classMetaData;
}
}
}
}
