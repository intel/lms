//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EnabledLogicalElement.cpp
//
//  Contents:   This class extends LogicalElement to abstract the concept of an element that is enabled and disabled, such as a LogicalDevice or a ServiceAccessPoint.
//
//              This file was automatically generated from CIM_EnabledLogicalElement.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_EnabledLogicalElement::_metadata[] = {
		{"EnabledState", false, false, false },
		{"OtherEnabledState", false, false, false },
		{"RequestedState", false, false, false },
		{"EnabledDefault", false, false, false },
		{"TimeOfLastStateChange", false, false, false },
		{"AvailableRequestedStates", false, false, false },
		{"TransitioningToState", false, false, false },
	};
	// class fields
	const unsigned short CIM_EnabledLogicalElement::EnabledState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EnabledState"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::EnabledState(const unsigned short value)
	{
		SetOrAddField("EnabledState", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::EnabledStateExists() const
	{
		return ContainsField("EnabledState");
	}
	void CIM_EnabledLogicalElement::RemoveEnabledState()
	{
		RemoveField("EnabledState");
	}

	const string CIM_EnabledLogicalElement::OtherEnabledState() const
	{
		return GetField("OtherEnabledState")[0];
	}
	void CIM_EnabledLogicalElement::OtherEnabledState(const string &value)
	{
		SetOrAddField("OtherEnabledState", value);
	}
	bool CIM_EnabledLogicalElement::OtherEnabledStateExists() const
	{
		return ContainsField("OtherEnabledState");
	}
	void CIM_EnabledLogicalElement::RemoveOtherEnabledState()
	{
		RemoveField("OtherEnabledState");
	}

	const unsigned short CIM_EnabledLogicalElement::RequestedState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RequestedState"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::RequestedStateExists() const
	{
		return ContainsField("RequestedState");
	}
	void CIM_EnabledLogicalElement::RemoveRequestedState()
	{
		RemoveField("RequestedState");
	}

	const unsigned short CIM_EnabledLogicalElement::EnabledDefault() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EnabledDefault"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::EnabledDefault(const unsigned short value)
	{
		SetOrAddField("EnabledDefault", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::EnabledDefaultExists() const
	{
		return ContainsField("EnabledDefault");
	}
	void CIM_EnabledLogicalElement::RemoveEnabledDefault()
	{
		RemoveField("EnabledDefault");
	}

	const CimDateTime CIM_EnabledLogicalElement::TimeOfLastStateChange() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastStateChange"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::TimeOfLastStateChange(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastStateChange", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::TimeOfLastStateChangeExists() const
	{
		return ContainsField("TimeOfLastStateChange");
	}
	void CIM_EnabledLogicalElement::RemoveTimeOfLastStateChange()
	{
		RemoveField("TimeOfLastStateChange");
	}

	const vector<unsigned short> CIM_EnabledLogicalElement::AvailableRequestedStates() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("AvailableRequestedStates"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::AvailableRequestedStates(const vector<unsigned short> &value)
	{
		SetOrAddField("AvailableRequestedStates", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::AvailableRequestedStatesExists() const
	{
		return ContainsField("AvailableRequestedStates");
	}
	void CIM_EnabledLogicalElement::RemoveAvailableRequestedStates()
	{
		RemoveField("AvailableRequestedStates");
	}

	const unsigned short CIM_EnabledLogicalElement::TransitioningToState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("TransitioningToState"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElement::TransitioningToState(const unsigned short value)
	{
		SetOrAddField("TransitioningToState", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElement::TransitioningToStateExists() const
	{
		return ContainsField("TransitioningToState");
	}
	void CIM_EnabledLogicalElement::RemoveTransitioningToState()
	{
		RemoveField("TransitioningToState");
	}

	CimBase *CIM_EnabledLogicalElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_EnabledLogicalElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_EnabledLogicalElement>(object);
		}
		else
		{
			ret = new CIM_EnabledLogicalElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_EnabledLogicalElement> > CIM_EnabledLogicalElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_EnabledLogicalElement>(client, keys);
	}

	void CIM_EnabledLogicalElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_EnabledLogicalElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_EnabledLogicalElement::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_EnabledLogicalElement::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_EnabledLogicalElement::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_EnabledLogicalElement::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_EnabledLogicalElement::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_EnabledLogicalElement::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_EnabledLogicalElement::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_EnabledLogicalElement::CLASS_NAME = "CIM_EnabledLogicalElement";
	const string CIM_EnabledLogicalElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EnabledLogicalElement";
	const string CIM_EnabledLogicalElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EnabledLogicalElement";
	const string CIM_EnabledLogicalElement::CLASS_NS_PREFIX = "AEn412";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_EnabledLogicalElement::_classMetaData;
}
}
}
}
