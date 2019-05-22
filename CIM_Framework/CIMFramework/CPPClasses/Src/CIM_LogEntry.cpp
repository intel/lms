//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogEntry.cpp
//
//  Contents:   The LogEntry object can describe the definitional format for entries in a Log, or can be used to instantiate the actual entries in the Log.
//
//              This file was automatically generated from CIM_LogEntry.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_LogEntry.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LogEntry::_metadata[] = {
		{"InstanceID", true, false, false },
		{"LogInstanceID", false, false, false },
		{"LogName", false, false, false },
		{"RecordID", false, false, false },
		{"CreationTimeStamp", false, false, false },
		{"MessageID", false, false, false },
		{"Message", false, false, false },
		{"MessageArguments", false, false, false },
		{"OwningEntity", false, false, false },
	};
	// class fields
	const string CIM_LogEntry::LogInstanceID() const
	{
		return GetField("LogInstanceID")[0];
	}
	void CIM_LogEntry::LogInstanceID(const string &value)
	{
		SetOrAddField("LogInstanceID", value);
	}
	bool CIM_LogEntry::LogInstanceIDExists() const
	{
		return ContainsField("LogInstanceID");
	}
	void CIM_LogEntry::RemoveLogInstanceID()
	{
		RemoveField("LogInstanceID");
	}

	const string CIM_LogEntry::LogName() const
	{
		return GetField("LogName")[0];
	}
	void CIM_LogEntry::LogName(const string &value)
	{
		SetOrAddField("LogName", value);
	}
	bool CIM_LogEntry::LogNameExists() const
	{
		return ContainsField("LogName");
	}
	void CIM_LogEntry::RemoveLogName()
	{
		RemoveField("LogName");
	}

	const string CIM_LogEntry::RecordID() const
	{
		return GetField("RecordID")[0];
	}
	void CIM_LogEntry::RecordID(const string &value)
	{
		SetOrAddField("RecordID", value);
	}
	bool CIM_LogEntry::RecordIDExists() const
	{
		return ContainsField("RecordID");
	}
	void CIM_LogEntry::RemoveRecordID()
	{
		RemoveField("RecordID");
	}

	const CimDateTime CIM_LogEntry::CreationTimeStamp() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("CreationTimeStamp"), ret);
		return ret;
	}
	void CIM_LogEntry::CreationTimeStamp(const CimDateTime &value)
	{
		SetOrAddField("CreationTimeStamp", TypeConverter::TypeToString(value));
	}
	bool CIM_LogEntry::CreationTimeStampExists() const
	{
		return ContainsField("CreationTimeStamp");
	}
	void CIM_LogEntry::RemoveCreationTimeStamp()
	{
		RemoveField("CreationTimeStamp");
	}

	const string CIM_LogEntry::MessageID() const
	{
		return GetField("MessageID")[0];
	}
	void CIM_LogEntry::MessageID(const string &value)
	{
		SetOrAddField("MessageID", value);
	}
	bool CIM_LogEntry::MessageIDExists() const
	{
		return ContainsField("MessageID");
	}
	void CIM_LogEntry::RemoveMessageID()
	{
		RemoveField("MessageID");
	}

	const string CIM_LogEntry::Message() const
	{
		return GetField("Message")[0];
	}
	void CIM_LogEntry::Message(const string &value)
	{
		SetOrAddField("Message", value);
	}
	bool CIM_LogEntry::MessageExists() const
	{
		return ContainsField("Message");
	}
	void CIM_LogEntry::RemoveMessage()
	{
		RemoveField("Message");
	}

	const vector<string> CIM_LogEntry::MessageArguments() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("MessageArguments"), ret);
		return ret;
	}
	void CIM_LogEntry::MessageArguments(const vector<string> &value)
	{
		SetOrAddField("MessageArguments", TypeConverter::TypeToString(value));
	}
	bool CIM_LogEntry::MessageArgumentsExists() const
	{
		return ContainsField("MessageArguments");
	}
	void CIM_LogEntry::RemoveMessageArguments()
	{
		RemoveField("MessageArguments");
	}

	const string CIM_LogEntry::OwningEntity() const
	{
		return GetField("OwningEntity")[0];
	}
	void CIM_LogEntry::OwningEntity(const string &value)
	{
		SetOrAddField("OwningEntity", value);
	}
	bool CIM_LogEntry::OwningEntityExists() const
	{
		return ContainsField("OwningEntity");
	}
	void CIM_LogEntry::RemoveOwningEntity()
	{
		RemoveField("OwningEntity");
	}

	CimBase *CIM_LogEntry::CreateFromCimObject(const CimObject &object)
	{
		CIM_LogEntry *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LogEntry>(object);
		}
		else
		{
			ret = new CIM_LogEntry(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LogEntry> > CIM_LogEntry::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LogEntry>(client, keys);
	}

	void CIM_LogEntry::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LogEntry::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_LogEntry::CLASS_NAME = "CIM_LogEntry";
	const string CIM_LogEntry::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogEntry";
	const string CIM_LogEntry::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LogEntry";
	const string CIM_LogEntry::CLASS_NS_PREFIX = "ALo118";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LogEntry::_classMetaData;
}
}
}
}
