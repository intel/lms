//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EnabledLogicalElementCapabilities.cpp
//
//  Contents:   EnabledLogicalElementCapabilities describes the capabilities supported for changing the state of the associated EnabledLogicalElement.
//
//              This file was automatically generated from CIM_EnabledLogicalElementCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_EnabledLogicalElementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_EnabledLogicalElementCapabilities::_metadata[] = {
		{"ElementNameEditSupported", false, false, false },
		{"MaxElementNameLen", false, false, false },
		{"RequestedStatesSupported", false, false, false },
		{"ElementNameMask", false, false, false },
	};
	// class fields
	const bool CIM_EnabledLogicalElementCapabilities::ElementNameEditSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ElementNameEditSupported"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElementCapabilities::ElementNameEditSupported(const bool value)
	{
		SetOrAddField("ElementNameEditSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElementCapabilities::ElementNameEditSupportedExists() const
	{
		return ContainsField("ElementNameEditSupported");
	}
	void CIM_EnabledLogicalElementCapabilities::RemoveElementNameEditSupported()
	{
		RemoveField("ElementNameEditSupported");
	}

	const unsigned short CIM_EnabledLogicalElementCapabilities::MaxElementNameLen() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("MaxElementNameLen"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElementCapabilities::MaxElementNameLen(const unsigned short value)
	{
		SetOrAddField("MaxElementNameLen", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElementCapabilities::MaxElementNameLenExists() const
	{
		return ContainsField("MaxElementNameLen");
	}
	void CIM_EnabledLogicalElementCapabilities::RemoveMaxElementNameLen()
	{
		RemoveField("MaxElementNameLen");
	}

	const vector<unsigned short> CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("RequestedStatesSupported"), ret);
		return ret;
	}
	void CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("RequestedStatesSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_EnabledLogicalElementCapabilities::RequestedStatesSupportedExists() const
	{
		return ContainsField("RequestedStatesSupported");
	}
	void CIM_EnabledLogicalElementCapabilities::RemoveRequestedStatesSupported()
	{
		RemoveField("RequestedStatesSupported");
	}

	const string CIM_EnabledLogicalElementCapabilities::ElementNameMask() const
	{
		return GetField("ElementNameMask")[0];
	}
	void CIM_EnabledLogicalElementCapabilities::ElementNameMask(const string &value)
	{
		SetOrAddField("ElementNameMask", value);
	}
	bool CIM_EnabledLogicalElementCapabilities::ElementNameMaskExists() const
	{
		return ContainsField("ElementNameMask");
	}
	void CIM_EnabledLogicalElementCapabilities::RemoveElementNameMask()
	{
		RemoveField("ElementNameMask");
	}

	CimBase *CIM_EnabledLogicalElementCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_EnabledLogicalElementCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_EnabledLogicalElementCapabilities>(object);
		}
		else
		{
			ret = new CIM_EnabledLogicalElementCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_EnabledLogicalElementCapabilities> > CIM_EnabledLogicalElementCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_EnabledLogicalElementCapabilities>(client, keys);
	}

	void CIM_EnabledLogicalElementCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_EnabledLogicalElementCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_EnabledLogicalElementCapabilities::CLASS_NAME = "CIM_EnabledLogicalElementCapabilities";
	const string CIM_EnabledLogicalElementCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EnabledLogicalElementCapabilities";
	const string CIM_EnabledLogicalElementCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_EnabledLogicalElementCapabilities";
	const string CIM_EnabledLogicalElementCapabilities::CLASS_NS_PREFIX = "AEn258";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_EnabledLogicalElementCapabilities::_classMetaData;
}
}
}
}
