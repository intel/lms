//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_Hdr8021Filter.cpp
//
//  Contents:   8021Filter allows 802.1.source and destination MAC addresses, as well as the 802.1 protocol ID, priority, and VLAN identifier fields, to be expressed in a single object to classify and identify traffic.
//
//              This file was automatically generated from AMT_Hdr8021Filter.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#include "AMT_Hdr8021Filter.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_Hdr8021Filter::_metadata[] = {
		{"HdrSrcMACAddr8021", false, false, false },
		{"HdrSrcMACMask8021", false, false, false },
		{"HdrDestMACAddr8021", false, false, false },
		{"HdrDestMACMask8021", false, false, false },
		{"HdrProtocolID8021", false, true, false },
		{"HdrPriorityValue8021", false, false, false },
		{"HdrVLANID8021", false, false, false },
		{"FilterProfile", false, true, false },
		{"FilterDirection", false, true, false },
		{"ActionEventOnMatch", false, true, false },
		{"FilterProfileData", false, false, false },
	};
	// class fields
	const Base64 AMT_Hdr8021Filter::HdrSrcMACAddr8021() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("HdrSrcMACAddr8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrSrcMACAddr8021(const Base64 &value)
	{
		SetOrAddField("HdrSrcMACAddr8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrSrcMACAddr8021Exists() const
	{
		return ContainsField("HdrSrcMACAddr8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrSrcMACAddr8021()
	{
		RemoveField("HdrSrcMACAddr8021");
	}

	const Base64 AMT_Hdr8021Filter::HdrSrcMACMask8021() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("HdrSrcMACMask8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrSrcMACMask8021(const Base64 &value)
	{
		SetOrAddField("HdrSrcMACMask8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrSrcMACMask8021Exists() const
	{
		return ContainsField("HdrSrcMACMask8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrSrcMACMask8021()
	{
		RemoveField("HdrSrcMACMask8021");
	}

	const Base64 AMT_Hdr8021Filter::HdrDestMACAddr8021() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("HdrDestMACAddr8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrDestMACAddr8021(const Base64 &value)
	{
		SetOrAddField("HdrDestMACAddr8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrDestMACAddr8021Exists() const
	{
		return ContainsField("HdrDestMACAddr8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrDestMACAddr8021()
	{
		RemoveField("HdrDestMACAddr8021");
	}

	const Base64 AMT_Hdr8021Filter::HdrDestMACMask8021() const
	{
		Base64 ret;
		TypeConverter::StringToType(GetField("HdrDestMACMask8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrDestMACMask8021(const Base64 &value)
	{
		SetOrAddField("HdrDestMACMask8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrDestMACMask8021Exists() const
	{
		return ContainsField("HdrDestMACMask8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrDestMACMask8021()
	{
		RemoveField("HdrDestMACMask8021");
	}

	const unsigned short AMT_Hdr8021Filter::HdrProtocolID8021() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HdrProtocolID8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrProtocolID8021(const unsigned short value)
	{
		SetOrAddField("HdrProtocolID8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrProtocolID8021Exists() const
	{
		return ContainsField("HdrProtocolID8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrProtocolID8021()
	{
		RemoveField("HdrProtocolID8021");
	}

	const unsigned char AMT_Hdr8021Filter::HdrPriorityValue8021() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HdrPriorityValue8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrPriorityValue8021(const unsigned char &value)
	{
		SetOrAddField("HdrPriorityValue8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrPriorityValue8021Exists() const
	{
		return ContainsField("HdrPriorityValue8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrPriorityValue8021()
	{
		RemoveField("HdrPriorityValue8021");
	}

	const unsigned int AMT_Hdr8021Filter::HdrVLANID8021() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("HdrVLANID8021"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::HdrVLANID8021(const unsigned int value)
	{
		SetOrAddField("HdrVLANID8021", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::HdrVLANID8021Exists() const
	{
		return ContainsField("HdrVLANID8021");
	}
	void AMT_Hdr8021Filter::RemoveHdrVLANID8021()
	{
		RemoveField("HdrVLANID8021");
	}

	const unsigned short AMT_Hdr8021Filter::FilterProfile() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FilterProfile"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::FilterProfile(const unsigned short value)
	{
		SetOrAddField("FilterProfile", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::FilterProfileExists() const
	{
		return ContainsField("FilterProfile");
	}
	void AMT_Hdr8021Filter::RemoveFilterProfile()
	{
		RemoveField("FilterProfile");
	}

	const unsigned short AMT_Hdr8021Filter::FilterDirection() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FilterDirection"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::FilterDirection(const unsigned short value)
	{
		SetOrAddField("FilterDirection", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::FilterDirectionExists() const
	{
		return ContainsField("FilterDirection");
	}
	void AMT_Hdr8021Filter::RemoveFilterDirection()
	{
		RemoveField("FilterDirection");
	}

	const bool AMT_Hdr8021Filter::ActionEventOnMatch() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActionEventOnMatch"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::ActionEventOnMatch(const bool value)
	{
		SetOrAddField("ActionEventOnMatch", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::ActionEventOnMatchExists() const
	{
		return ContainsField("ActionEventOnMatch");
	}
	void AMT_Hdr8021Filter::RemoveActionEventOnMatch()
	{
		RemoveField("ActionEventOnMatch");
	}

	const unsigned int AMT_Hdr8021Filter::FilterProfileData() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("FilterProfileData"), ret);
		return ret;
	}
	void AMT_Hdr8021Filter::FilterProfileData(const unsigned int value)
	{
		SetOrAddField("FilterProfileData", TypeConverter::TypeToString(value));
	}
	bool AMT_Hdr8021Filter::FilterProfileDataExists() const
	{
		return ContainsField("FilterProfileData");
	}
	void AMT_Hdr8021Filter::RemoveFilterProfileData()
	{
		RemoveField("FilterProfileData");
	}

	CimBase *AMT_Hdr8021Filter::CreateFromCimObject(const CimObject &object)
	{
		AMT_Hdr8021Filter *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_Hdr8021Filter>(object);
		}
		else
		{
			ret = new AMT_Hdr8021Filter(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_Hdr8021Filter> > AMT_Hdr8021Filter::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_Hdr8021Filter>(client, keys);
	}

	void AMT_Hdr8021Filter::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_Hdr8021Filter::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_Hdr8021Filter::CLASS_NAME = "AMT_Hdr8021Filter";
	const string AMT_Hdr8021Filter::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_Hdr8021Filter";
	const string AMT_Hdr8021Filter::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_Hdr8021Filter";
	const string AMT_Hdr8021Filter::CLASS_NS_PREFIX = "AHd318";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_Hdr8021Filter::_classMetaData;
}
}
}
}
