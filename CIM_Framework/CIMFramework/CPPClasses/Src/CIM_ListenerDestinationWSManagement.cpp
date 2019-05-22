//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ListenerDestinationWSManagement.cpp
//
//  Contents:   CIM_ListenerDestinationWSManagement describes the destination for CIM indications to be delivered via WS-Management.
//
//              This file was automatically generated from CIM_ListenerDestinationWSManagement.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_ListenerDestinationWSManagement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ListenerDestinationWSManagement::_metadata[] = {
		{"Destination", false, true, false },
		{"DestinationEndTo", false, false, false },
		{"Locale", false, false, false },
		{"ContentEncoding", false, false, false },
		{"DeliveryMode", false, false, false },
		{"Heartbeat", false, false, false },
		{"SendBookmark", false, false, false },
		{"MaxTime", false, false, false },
		{"DeliveryAuth", false, false, false },
		{"PolyMorphismMode", false, false, false },
	};
	// class fields
	const string CIM_ListenerDestinationWSManagement::DestinationEndTo() const
	{
		return GetField("DestinationEndTo")[0];
	}
	void CIM_ListenerDestinationWSManagement::DestinationEndTo(const string &value)
	{
		SetOrAddField("DestinationEndTo", value);
	}
	bool CIM_ListenerDestinationWSManagement::DestinationEndToExists() const
	{
		return ContainsField("DestinationEndTo");
	}
	void CIM_ListenerDestinationWSManagement::RemoveDestinationEndTo()
	{
		RemoveField("DestinationEndTo");
	}

	const string CIM_ListenerDestinationWSManagement::Locale() const
	{
		return GetField("Locale")[0];
	}
	void CIM_ListenerDestinationWSManagement::Locale(const string &value)
	{
		SetOrAddField("Locale", value);
	}
	bool CIM_ListenerDestinationWSManagement::LocaleExists() const
	{
		return ContainsField("Locale");
	}
	void CIM_ListenerDestinationWSManagement::RemoveLocale()
	{
		RemoveField("Locale");
	}

	const string CIM_ListenerDestinationWSManagement::ContentEncoding() const
	{
		return GetField("ContentEncoding")[0];
	}
	void CIM_ListenerDestinationWSManagement::ContentEncoding(const string &value)
	{
		SetOrAddField("ContentEncoding", value);
	}
	bool CIM_ListenerDestinationWSManagement::ContentEncodingExists() const
	{
		return ContainsField("ContentEncoding");
	}
	void CIM_ListenerDestinationWSManagement::RemoveContentEncoding()
	{
		RemoveField("ContentEncoding");
	}

	const unsigned short CIM_ListenerDestinationWSManagement::DeliveryMode() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DeliveryMode"), ret);
		return ret;
	}
	void CIM_ListenerDestinationWSManagement::DeliveryMode(const unsigned short value)
	{
		SetOrAddField("DeliveryMode", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestinationWSManagement::DeliveryModeExists() const
	{
		return ContainsField("DeliveryMode");
	}
	void CIM_ListenerDestinationWSManagement::RemoveDeliveryMode()
	{
		RemoveField("DeliveryMode");
	}

	const Uint64 CIM_ListenerDestinationWSManagement::Heartbeat() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("Heartbeat"), ret);
		return ret;
	}
	void CIM_ListenerDestinationWSManagement::Heartbeat(const Uint64 value)
	{
		SetOrAddField("Heartbeat", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestinationWSManagement::HeartbeatExists() const
	{
		return ContainsField("Heartbeat");
	}
	void CIM_ListenerDestinationWSManagement::RemoveHeartbeat()
	{
		RemoveField("Heartbeat");
	}

	const bool CIM_ListenerDestinationWSManagement::SendBookmark() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("SendBookmark"), ret);
		return ret;
	}
	void CIM_ListenerDestinationWSManagement::SendBookmark(const bool value)
	{
		SetOrAddField("SendBookmark", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestinationWSManagement::SendBookmarkExists() const
	{
		return ContainsField("SendBookmark");
	}
	void CIM_ListenerDestinationWSManagement::RemoveSendBookmark()
	{
		RemoveField("SendBookmark");
	}

	const Uint64 CIM_ListenerDestinationWSManagement::MaxTime() const
	{
		Uint64 ret = 0;
		TypeConverter::StringToType(GetField("MaxTime"), ret);
		return ret;
	}
	void CIM_ListenerDestinationWSManagement::MaxTime(const Uint64 value)
	{
		SetOrAddField("MaxTime", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestinationWSManagement::MaxTimeExists() const
	{
		return ContainsField("MaxTime");
	}
	void CIM_ListenerDestinationWSManagement::RemoveMaxTime()
	{
		RemoveField("MaxTime");
	}

	const string CIM_ListenerDestinationWSManagement::DeliveryAuth() const
	{
		return GetField("DeliveryAuth")[0];
	}
	void CIM_ListenerDestinationWSManagement::DeliveryAuth(const string &value)
	{
		SetOrAddField("DeliveryAuth", value);
	}
	bool CIM_ListenerDestinationWSManagement::DeliveryAuthExists() const
	{
		return ContainsField("DeliveryAuth");
	}
	void CIM_ListenerDestinationWSManagement::RemoveDeliveryAuth()
	{
		RemoveField("DeliveryAuth");
	}

	const unsigned short CIM_ListenerDestinationWSManagement::PolyMorphismMode() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PolyMorphismMode"), ret);
		return ret;
	}
	void CIM_ListenerDestinationWSManagement::PolyMorphismMode(const unsigned short value)
	{
		SetOrAddField("PolyMorphismMode", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestinationWSManagement::PolyMorphismModeExists() const
	{
		return ContainsField("PolyMorphismMode");
	}
	void CIM_ListenerDestinationWSManagement::RemovePolyMorphismMode()
	{
		RemoveField("PolyMorphismMode");
	}

	CimBase *CIM_ListenerDestinationWSManagement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ListenerDestinationWSManagement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ListenerDestinationWSManagement>(object);
		}
		else
		{
			ret = new CIM_ListenerDestinationWSManagement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ListenerDestinationWSManagement> > CIM_ListenerDestinationWSManagement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ListenerDestinationWSManagement>(client, keys);
	}

	void CIM_ListenerDestinationWSManagement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ListenerDestinationWSManagement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ListenerDestinationWSManagement::CLASS_NAME = "CIM_ListenerDestinationWSManagement";
	const string CIM_ListenerDestinationWSManagement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestinationWSManagement";
	const string CIM_ListenerDestinationWSManagement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestinationWSManagement";
	const string CIM_ListenerDestinationWSManagement::CLASS_NS_PREFIX = "ALi535";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ListenerDestinationWSManagement::_classMetaData;
}
}
}
}
