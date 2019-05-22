//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Indication.cpp
//
//  Contents:   CIM_Indication is the abstract root class for all notifications about changes in schema, objects and their data, and about events detected by providers and instrumentation. Subclasses represent specific types of notifications. 
//              
//              To receive an Indication, a consumer (or subscriber) must create an instance of CIM_IndicationFilter describing the criteria of the notification, an instance of CIM_ListenerDestination describing the delivery of the notification, and an instance of CIM_IndicationSubscription associating the Filter and Handler.
//
//              This file was automatically generated from CIM_Indication.mof,  version: 2.24.0
//
//----------------------------------------------------------------------------
#include "CIM_Indication.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Indication::_metadata[] = {
		{"IndicationIdentifier", false, false, false },
		{"CorrelatedIndications", false, false, false },
		{"IndicationTime", false, false, false },
		{"PerceivedSeverity", false, false, false },
		{"OtherSeverity", false, false, false },
		{"IndicationFilterName", false, false, false },
		{"SequenceContext", false, false, false },
		{"SequenceNumber", false, false, false },
	};
	// class fields
	const string CIM_Indication::IndicationIdentifier() const
	{
		return GetField("IndicationIdentifier")[0];
	}
	void CIM_Indication::IndicationIdentifier(const string &value)
	{
		SetOrAddField("IndicationIdentifier", value);
	}
	bool CIM_Indication::IndicationIdentifierExists() const
	{
		return ContainsField("IndicationIdentifier");
	}
	void CIM_Indication::RemoveIndicationIdentifier()
	{
		RemoveField("IndicationIdentifier");
	}

	const vector<string> CIM_Indication::CorrelatedIndications() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("CorrelatedIndications"), ret);
		return ret;
	}
	void CIM_Indication::CorrelatedIndications(const vector<string> &value)
	{
		SetOrAddField("CorrelatedIndications", TypeConverter::TypeToString(value));
	}
	bool CIM_Indication::CorrelatedIndicationsExists() const
	{
		return ContainsField("CorrelatedIndications");
	}
	void CIM_Indication::RemoveCorrelatedIndications()
	{
		RemoveField("CorrelatedIndications");
	}

	const CimDateTime CIM_Indication::IndicationTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("IndicationTime"), ret);
		return ret;
	}
	void CIM_Indication::IndicationTime(const CimDateTime &value)
	{
		SetOrAddField("IndicationTime", TypeConverter::TypeToString(value));
	}
	bool CIM_Indication::IndicationTimeExists() const
	{
		return ContainsField("IndicationTime");
	}
	void CIM_Indication::RemoveIndicationTime()
	{
		RemoveField("IndicationTime");
	}

	const unsigned short CIM_Indication::PerceivedSeverity() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PerceivedSeverity"), ret);
		return ret;
	}
	void CIM_Indication::PerceivedSeverity(const unsigned short value)
	{
		SetOrAddField("PerceivedSeverity", TypeConverter::TypeToString(value));
	}
	bool CIM_Indication::PerceivedSeverityExists() const
	{
		return ContainsField("PerceivedSeverity");
	}
	void CIM_Indication::RemovePerceivedSeverity()
	{
		RemoveField("PerceivedSeverity");
	}

	const string CIM_Indication::OtherSeverity() const
	{
		return GetField("OtherSeverity")[0];
	}
	void CIM_Indication::OtherSeverity(const string &value)
	{
		SetOrAddField("OtherSeverity", value);
	}
	bool CIM_Indication::OtherSeverityExists() const
	{
		return ContainsField("OtherSeverity");
	}
	void CIM_Indication::RemoveOtherSeverity()
	{
		RemoveField("OtherSeverity");
	}

	const string CIM_Indication::IndicationFilterName() const
	{
		return GetField("IndicationFilterName")[0];
	}
	void CIM_Indication::IndicationFilterName(const string &value)
	{
		SetOrAddField("IndicationFilterName", value);
	}
	bool CIM_Indication::IndicationFilterNameExists() const
	{
		return ContainsField("IndicationFilterName");
	}
	void CIM_Indication::RemoveIndicationFilterName()
	{
		RemoveField("IndicationFilterName");
	}

	const string CIM_Indication::SequenceContext() const
	{
		return GetField("SequenceContext")[0];
	}
	void CIM_Indication::SequenceContext(const string &value)
	{
		SetOrAddField("SequenceContext", value);
	}
	bool CIM_Indication::SequenceContextExists() const
	{
		return ContainsField("SequenceContext");
	}
	void CIM_Indication::RemoveSequenceContext()
	{
		RemoveField("SequenceContext");
	}

	const Int64 CIM_Indication::SequenceNumber() const
	{
		Int64 ret = 0;
		TypeConverter::StringToType(GetField("SequenceNumber"), ret);
		return ret;
	}
	void CIM_Indication::SequenceNumber(const Int64 value)
	{
		SetOrAddField("SequenceNumber", TypeConverter::TypeToString(value));
	}
	bool CIM_Indication::SequenceNumberExists() const
	{
		return ContainsField("SequenceNumber");
	}
	void CIM_Indication::RemoveSequenceNumber()
	{
		RemoveField("SequenceNumber");
	}

	CimBase *CIM_Indication::CreateFromCimObject(const CimObject &object)
	{
		CIM_Indication *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Indication>(object);
		}
		else
		{
			ret = new CIM_Indication(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Indication> > CIM_Indication::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Indication>(client, keys);
	}

	void CIM_Indication::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Indication::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Indication::CLASS_NAME = "CIM_Indication";
	const string CIM_Indication::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Indication";
	const string CIM_Indication::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Indication";
	const string CIM_Indication::CLASS_NS_PREFIX = "AIn732";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Indication::_classMetaData;
}
}
}
}
