//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPortCapabilities.cpp
//
//  Contents:   NetworkPortCapabilities describes the capabilities supported for properties that are configurable in NetworkPort.
//
//              This file was automatically generated from CIM_NetworkPortCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_NetworkPortCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_NetworkPortCapabilities::_metadata[] = {
		{"SpeedConfigurable", false, false, false },
		{"PortSpeedsSupported", false, false, false },
		{"NetworkIDsConfigurable", false, false, false },
		{"NetworkIDsFormat", false, false, false },
		{"LinkTechnologiesSupported", false, false, false },
	};
	// class fields
	const bool CIM_NetworkPortCapabilities::SpeedConfigurable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SpeedConfigurable"), ret);
		return ret;
	}
	void CIM_NetworkPortCapabilities::SpeedConfigurable(const bool value)
	{
		SetOrAddField("SpeedConfigurable", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPortCapabilities::SpeedConfigurableExists() const
	{
		return ContainsField("SpeedConfigurable");
	}
	void CIM_NetworkPortCapabilities::RemoveSpeedConfigurable()
	{
		RemoveField("SpeedConfigurable");
	}

	const vector<Uint64> CIM_NetworkPortCapabilities::PortSpeedsSupported() const
	{
		vector<Uint64> ret;
		TypeConverter::StringToType(GetField("PortSpeedsSupported"), ret);
		return ret;
	}
	void CIM_NetworkPortCapabilities::PortSpeedsSupported(const vector<Uint64> &value)
	{
		SetOrAddField("PortSpeedsSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPortCapabilities::PortSpeedsSupportedExists() const
	{
		return ContainsField("PortSpeedsSupported");
	}
	void CIM_NetworkPortCapabilities::RemovePortSpeedsSupported()
	{
		RemoveField("PortSpeedsSupported");
	}

	const bool CIM_NetworkPortCapabilities::NetworkIDsConfigurable() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("NetworkIDsConfigurable"), ret);
		return ret;
	}
	void CIM_NetworkPortCapabilities::NetworkIDsConfigurable(const bool value)
	{
		SetOrAddField("NetworkIDsConfigurable", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPortCapabilities::NetworkIDsConfigurableExists() const
	{
		return ContainsField("NetworkIDsConfigurable");
	}
	void CIM_NetworkPortCapabilities::RemoveNetworkIDsConfigurable()
	{
		RemoveField("NetworkIDsConfigurable");
	}

	const unsigned short CIM_NetworkPortCapabilities::NetworkIDsFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("NetworkIDsFormat"), ret);
		return ret;
	}
	void CIM_NetworkPortCapabilities::NetworkIDsFormat(const unsigned short value)
	{
		SetOrAddField("NetworkIDsFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPortCapabilities::NetworkIDsFormatExists() const
	{
		return ContainsField("NetworkIDsFormat");
	}
	void CIM_NetworkPortCapabilities::RemoveNetworkIDsFormat()
	{
		RemoveField("NetworkIDsFormat");
	}

	const vector<unsigned short> CIM_NetworkPortCapabilities::LinkTechnologiesSupported() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("LinkTechnologiesSupported"), ret);
		return ret;
	}
	void CIM_NetworkPortCapabilities::LinkTechnologiesSupported(const vector<unsigned short> &value)
	{
		SetOrAddField("LinkTechnologiesSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_NetworkPortCapabilities::LinkTechnologiesSupportedExists() const
	{
		return ContainsField("LinkTechnologiesSupported");
	}
	void CIM_NetworkPortCapabilities::RemoveLinkTechnologiesSupported()
	{
		RemoveField("LinkTechnologiesSupported");
	}

	CimBase *CIM_NetworkPortCapabilities::CreateFromCimObject(const CimObject &object)
	{
		CIM_NetworkPortCapabilities *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_NetworkPortCapabilities>(object);
		}
		else
		{
			ret = new CIM_NetworkPortCapabilities(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_NetworkPortCapabilities> > CIM_NetworkPortCapabilities::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_NetworkPortCapabilities>(client, keys);
	}

	void CIM_NetworkPortCapabilities::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_NetworkPortCapabilities::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_NetworkPortCapabilities::CLASS_NAME = "CIM_NetworkPortCapabilities";
	const string CIM_NetworkPortCapabilities::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPortCapabilities";
	const string CIM_NetworkPortCapabilities::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_NetworkPortCapabilities";
	const string CIM_NetworkPortCapabilities::CLASS_NS_PREFIX = "ANe501";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_NetworkPortCapabilities::_classMetaData;
}
}
}
}
