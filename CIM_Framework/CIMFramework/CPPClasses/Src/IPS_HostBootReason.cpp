//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HostBootReason.cpp
//
//  Contents:   The IPS_HostBootReason class returns the details of the last host boot.
//
//              This file was automatically generated from IPS_HostBootReason.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_HostBootReason.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_HostBootReason::_metadata[] = {
		{"InstanceID", true, false, false },
		{"Reason", false, true, false },
		{"ReasonDetails", false, false, false },
		{"PreviousSxState", false, true, false },
	};
	// class fields
	const unsigned int IPS_HostBootReason::Reason() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("Reason"), ret);
		return ret;
	}
	void IPS_HostBootReason::Reason(const unsigned int value)
	{
		SetOrAddField("Reason", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBootReason::ReasonExists() const
	{
		return ContainsField("Reason");
	}
	void IPS_HostBootReason::RemoveReason()
	{
		RemoveField("Reason");
	}

	const string IPS_HostBootReason::ReasonDetails() const
	{
		return GetField("ReasonDetails")[0];
	}
	void IPS_HostBootReason::ReasonDetails(const string &value)
	{
		SetOrAddField("ReasonDetails", value);
	}
	bool IPS_HostBootReason::ReasonDetailsExists() const
	{
		return ContainsField("ReasonDetails");
	}
	void IPS_HostBootReason::RemoveReasonDetails()
	{
		RemoveField("ReasonDetails");
	}

	const unsigned int IPS_HostBootReason::PreviousSxState() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("PreviousSxState"), ret);
		return ret;
	}
	void IPS_HostBootReason::PreviousSxState(const unsigned int value)
	{
		SetOrAddField("PreviousSxState", TypeConverter::TypeToString(value));
	}
	bool IPS_HostBootReason::PreviousSxStateExists() const
	{
		return ContainsField("PreviousSxState");
	}
	void IPS_HostBootReason::RemovePreviousSxState()
	{
		RemoveField("PreviousSxState");
	}

	CimBase *IPS_HostBootReason::CreateFromCimObject(const CimObject &object)
	{
		IPS_HostBootReason *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_HostBootReason>(object);
		}
		else
		{
			ret = new IPS_HostBootReason(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_HostBootReason> > IPS_HostBootReason::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_HostBootReason>(client, keys);
	}

	void IPS_HostBootReason::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_HostBootReason::GetMetaData() const
	{
		return _classMetaData;
	}
	const string IPS_HostBootReason::CLASS_NAME = "IPS_HostBootReason";
	const string IPS_HostBootReason::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostBootReason";
	const string IPS_HostBootReason::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_HostBootReason";
	const string IPS_HostBootReason::CLASS_NS_PREFIX = "AHo633";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_HostBootReason::_classMetaData;
}
}
}
}
