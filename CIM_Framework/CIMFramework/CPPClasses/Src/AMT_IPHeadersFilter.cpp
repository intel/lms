//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_IPHeadersFilter.cpp
//
//  Contents:   IPHeadersFilter contains the most commonly required properties for performing filtering on IP, TCP or UDP headers. Properties not present in an instance of the IPHeadersFilter are treated as 'all values'.
//
//              This file was automatically generated from AMT_IPHeadersFilter.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_IPHeadersFilter.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_IPHeadersFilter::_metadata[] = {
		{"HdrIPVersion", false, false, false },
		{"HdrSrcAddress", false, false, false },
		{"HdrSrcAddressEndOfRange", false, false, false },
		{"HdrSrcMask", false, false, false },
		{"HdrDestAddress", false, false, false },
		{"HdrDestAddressEndOfRange", false, false, false },
		{"HdrDestMask", false, false, false },
		{"HdrProtocolID", false, false, false },
		{"HdrSrcPortStart", false, false, false },
		{"HdrSrcPortEnd", false, false, false },
		{"HdrDestPortStart", false, false, false },
		{"HdrDestPortEnd", false, false, false },
		{"HdrDSCP", false, false, false },
		{"HdrFlowLabel", false, false, false },
		{"TCPFlagsOn", false, false, false },
		{"TCPFlagsOff", false, false, false },
		{"FilterProfile", false, true, false },
		{"FilterDirection", false, true, false },
		{"ActionEventOnMatch", false, true, false },
		{"FilterProfileData", false, false, false },
	};
	// class fields
	const unsigned char AMT_IPHeadersFilter::HdrIPVersion() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HdrIPVersion"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrIPVersion(const unsigned char &value)
	{
		SetOrAddField("HdrIPVersion", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrIPVersionExists() const
	{
		return ContainsField("HdrIPVersion");
	}
	void AMT_IPHeadersFilter::RemoveHdrIPVersion()
	{
		RemoveField("HdrIPVersion");
	}

	const HexBinary AMT_IPHeadersFilter::HdrSrcAddress() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrSrcAddress"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrSrcAddress(const HexBinary &value)
	{
		SetOrAddField("HdrSrcAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrSrcAddressExists() const
	{
		return ContainsField("HdrSrcAddress");
	}
	void AMT_IPHeadersFilter::RemoveHdrSrcAddress()
	{
		RemoveField("HdrSrcAddress");
	}

	const HexBinary AMT_IPHeadersFilter::HdrSrcAddressEndOfRange() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrSrcAddressEndOfRange"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrSrcAddressEndOfRange(const HexBinary &value)
	{
		SetOrAddField("HdrSrcAddressEndOfRange", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrSrcAddressEndOfRangeExists() const
	{
		return ContainsField("HdrSrcAddressEndOfRange");
	}
	void AMT_IPHeadersFilter::RemoveHdrSrcAddressEndOfRange()
	{
		RemoveField("HdrSrcAddressEndOfRange");
	}

	const HexBinary AMT_IPHeadersFilter::HdrSrcMask() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrSrcMask"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrSrcMask(const HexBinary &value)
	{
		SetOrAddField("HdrSrcMask", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrSrcMaskExists() const
	{
		return ContainsField("HdrSrcMask");
	}
	void AMT_IPHeadersFilter::RemoveHdrSrcMask()
	{
		RemoveField("HdrSrcMask");
	}

	const HexBinary AMT_IPHeadersFilter::HdrDestAddress() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrDestAddress"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDestAddress(const HexBinary &value)
	{
		SetOrAddField("HdrDestAddress", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDestAddressExists() const
	{
		return ContainsField("HdrDestAddress");
	}
	void AMT_IPHeadersFilter::RemoveHdrDestAddress()
	{
		RemoveField("HdrDestAddress");
	}

	const HexBinary AMT_IPHeadersFilter::HdrDestAddressEndOfRange() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrDestAddressEndOfRange"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDestAddressEndOfRange(const HexBinary &value)
	{
		SetOrAddField("HdrDestAddressEndOfRange", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDestAddressEndOfRangeExists() const
	{
		return ContainsField("HdrDestAddressEndOfRange");
	}
	void AMT_IPHeadersFilter::RemoveHdrDestAddressEndOfRange()
	{
		RemoveField("HdrDestAddressEndOfRange");
	}

	const HexBinary AMT_IPHeadersFilter::HdrDestMask() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrDestMask"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDestMask(const HexBinary &value)
	{
		SetOrAddField("HdrDestMask", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDestMaskExists() const
	{
		return ContainsField("HdrDestMask");
	}
	void AMT_IPHeadersFilter::RemoveHdrDestMask()
	{
		RemoveField("HdrDestMask");
	}

	const unsigned char AMT_IPHeadersFilter::HdrProtocolID() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("HdrProtocolID"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrProtocolID(const unsigned char &value)
	{
		SetOrAddField("HdrProtocolID", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrProtocolIDExists() const
	{
		return ContainsField("HdrProtocolID");
	}
	void AMT_IPHeadersFilter::RemoveHdrProtocolID()
	{
		RemoveField("HdrProtocolID");
	}

	const unsigned short AMT_IPHeadersFilter::HdrSrcPortStart() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HdrSrcPortStart"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrSrcPortStart(const unsigned short value)
	{
		SetOrAddField("HdrSrcPortStart", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrSrcPortStartExists() const
	{
		return ContainsField("HdrSrcPortStart");
	}
	void AMT_IPHeadersFilter::RemoveHdrSrcPortStart()
	{
		RemoveField("HdrSrcPortStart");
	}

	const unsigned short AMT_IPHeadersFilter::HdrSrcPortEnd() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HdrSrcPortEnd"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrSrcPortEnd(const unsigned short value)
	{
		SetOrAddField("HdrSrcPortEnd", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrSrcPortEndExists() const
	{
		return ContainsField("HdrSrcPortEnd");
	}
	void AMT_IPHeadersFilter::RemoveHdrSrcPortEnd()
	{
		RemoveField("HdrSrcPortEnd");
	}

	const unsigned short AMT_IPHeadersFilter::HdrDestPortStart() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HdrDestPortStart"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDestPortStart(const unsigned short value)
	{
		SetOrAddField("HdrDestPortStart", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDestPortStartExists() const
	{
		return ContainsField("HdrDestPortStart");
	}
	void AMT_IPHeadersFilter::RemoveHdrDestPortStart()
	{
		RemoveField("HdrDestPortStart");
	}

	const unsigned short AMT_IPHeadersFilter::HdrDestPortEnd() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HdrDestPortEnd"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDestPortEnd(const unsigned short value)
	{
		SetOrAddField("HdrDestPortEnd", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDestPortEndExists() const
	{
		return ContainsField("HdrDestPortEnd");
	}
	void AMT_IPHeadersFilter::RemoveHdrDestPortEnd()
	{
		RemoveField("HdrDestPortEnd");
	}

	const vector<unsigned char> AMT_IPHeadersFilter::HdrDSCP() const
	{
		vector<unsigned char> ret;
		TypeConverter::StringToType(GetField("HdrDSCP"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrDSCP(const vector<unsigned char> &value)
	{
		SetOrAddField("HdrDSCP", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrDSCPExists() const
	{
		return ContainsField("HdrDSCP");
	}
	void AMT_IPHeadersFilter::RemoveHdrDSCP()
	{
		RemoveField("HdrDSCP");
	}

	const HexBinary AMT_IPHeadersFilter::HdrFlowLabel() const
	{
		HexBinary ret;
		TypeConverter::StringToType(GetField("HdrFlowLabel"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::HdrFlowLabel(const HexBinary &value)
	{
		SetOrAddField("HdrFlowLabel", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::HdrFlowLabelExists() const
	{
		return ContainsField("HdrFlowLabel");
	}
	void AMT_IPHeadersFilter::RemoveHdrFlowLabel()
	{
		RemoveField("HdrFlowLabel");
	}

	const vector<unsigned short> AMT_IPHeadersFilter::TCPFlagsOn() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("TCPFlagsOn"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::TCPFlagsOn(const vector<unsigned short> &value)
	{
		SetOrAddField("TCPFlagsOn", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::TCPFlagsOnExists() const
	{
		return ContainsField("TCPFlagsOn");
	}
	void AMT_IPHeadersFilter::RemoveTCPFlagsOn()
	{
		RemoveField("TCPFlagsOn");
	}

	const vector<unsigned short> AMT_IPHeadersFilter::TCPFlagsOff() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("TCPFlagsOff"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::TCPFlagsOff(const vector<unsigned short> &value)
	{
		SetOrAddField("TCPFlagsOff", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::TCPFlagsOffExists() const
	{
		return ContainsField("TCPFlagsOff");
	}
	void AMT_IPHeadersFilter::RemoveTCPFlagsOff()
	{
		RemoveField("TCPFlagsOff");
	}

	const unsigned short AMT_IPHeadersFilter::FilterProfile() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FilterProfile"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::FilterProfile(const unsigned short value)
	{
		SetOrAddField("FilterProfile", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::FilterProfileExists() const
	{
		return ContainsField("FilterProfile");
	}
	void AMT_IPHeadersFilter::RemoveFilterProfile()
	{
		RemoveField("FilterProfile");
	}

	const unsigned short AMT_IPHeadersFilter::FilterDirection() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("FilterDirection"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::FilterDirection(const unsigned short value)
	{
		SetOrAddField("FilterDirection", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::FilterDirectionExists() const
	{
		return ContainsField("FilterDirection");
	}
	void AMT_IPHeadersFilter::RemoveFilterDirection()
	{
		RemoveField("FilterDirection");
	}

	const bool AMT_IPHeadersFilter::ActionEventOnMatch() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ActionEventOnMatch"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::ActionEventOnMatch(const bool value)
	{
		SetOrAddField("ActionEventOnMatch", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::ActionEventOnMatchExists() const
	{
		return ContainsField("ActionEventOnMatch");
	}
	void AMT_IPHeadersFilter::RemoveActionEventOnMatch()
	{
		RemoveField("ActionEventOnMatch");
	}

	const unsigned int AMT_IPHeadersFilter::FilterProfileData() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("FilterProfileData"), ret);
		return ret;
	}
	void AMT_IPHeadersFilter::FilterProfileData(const unsigned int value)
	{
		SetOrAddField("FilterProfileData", TypeConverter::TypeToString(value));
	}
	bool AMT_IPHeadersFilter::FilterProfileDataExists() const
	{
		return ContainsField("FilterProfileData");
	}
	void AMT_IPHeadersFilter::RemoveFilterProfileData()
	{
		RemoveField("FilterProfileData");
	}

	CimBase *AMT_IPHeadersFilter::CreateFromCimObject(const CimObject &object)
	{
		AMT_IPHeadersFilter *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_IPHeadersFilter>(object);
		}
		else
		{
			ret = new AMT_IPHeadersFilter(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_IPHeadersFilter> > AMT_IPHeadersFilter::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_IPHeadersFilter>(client, keys);
	}

	void AMT_IPHeadersFilter::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_IPHeadersFilter::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_IPHeadersFilter::CLASS_NAME = "AMT_IPHeadersFilter";
	const string AMT_IPHeadersFilter::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_IPHeadersFilter";
	const string AMT_IPHeadersFilter::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_IPHeadersFilter";
	const string AMT_IPHeadersFilter::CLASS_NS_PREFIX = "AIP720";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_IPHeadersFilter::_classMetaData;
}
}
}
}
