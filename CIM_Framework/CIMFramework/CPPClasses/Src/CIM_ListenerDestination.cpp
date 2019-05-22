//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ListenerDestination.cpp
//
//  Contents:   The description of a CIM Listener destination. A CIM_Listener is an entity capable of receiving CIM Export Messages (e.g., Indications or responses to an asynchronous CIM Operation).
//
//              This file was automatically generated from CIM_ListenerDestination.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#include "CIM_ListenerDestination.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ListenerDestination::_metadata[] = {
		{"SystemCreationClassName", true, false, false },
		{"SystemName", true, false, false },
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"PersistenceType", false, false, false },
		{"OtherPersistenceType", false, false, false },
		{"Destination", false, false, false },
		{"OtherProtocol", false, false, false },
		{"Protocol", false, false, false },
	};
	// class fields
	const string CIM_ListenerDestination::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_ListenerDestination::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}

	const string CIM_ListenerDestination::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_ListenerDestination::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}

	const string CIM_ListenerDestination::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_ListenerDestination::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_ListenerDestination::Name() const
	{
		return GetField("Name")[0];
	}
	void CIM_ListenerDestination::Name(const string &value)
	{
		SetOrAddField("Name", value);
	}

	const unsigned short CIM_ListenerDestination::PersistenceType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PersistenceType"), ret);
		return ret;
	}
	void CIM_ListenerDestination::PersistenceType(const unsigned short value)
	{
		SetOrAddField("PersistenceType", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestination::PersistenceTypeExists() const
	{
		return ContainsField("PersistenceType");
	}
	void CIM_ListenerDestination::RemovePersistenceType()
	{
		RemoveField("PersistenceType");
	}

	const string CIM_ListenerDestination::OtherPersistenceType() const
	{
		return GetField("OtherPersistenceType")[0];
	}
	void CIM_ListenerDestination::OtherPersistenceType(const string &value)
	{
		SetOrAddField("OtherPersistenceType", value);
	}
	bool CIM_ListenerDestination::OtherPersistenceTypeExists() const
	{
		return ContainsField("OtherPersistenceType");
	}
	void CIM_ListenerDestination::RemoveOtherPersistenceType()
	{
		RemoveField("OtherPersistenceType");
	}

	const string CIM_ListenerDestination::Destination() const
	{
		return GetField("Destination")[0];
	}
	void CIM_ListenerDestination::Destination(const string &value)
	{
		SetOrAddField("Destination", value);
	}
	bool CIM_ListenerDestination::DestinationExists() const
	{
		return ContainsField("Destination");
	}
	void CIM_ListenerDestination::RemoveDestination()
	{
		RemoveField("Destination");
	}

	const string CIM_ListenerDestination::OtherProtocol() const
	{
		return GetField("OtherProtocol")[0];
	}
	void CIM_ListenerDestination::OtherProtocol(const string &value)
	{
		SetOrAddField("OtherProtocol", value);
	}
	bool CIM_ListenerDestination::OtherProtocolExists() const
	{
		return ContainsField("OtherProtocol");
	}
	void CIM_ListenerDestination::RemoveOtherProtocol()
	{
		RemoveField("OtherProtocol");
	}

	const unsigned short CIM_ListenerDestination::Protocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Protocol"), ret);
		return ret;
	}
	void CIM_ListenerDestination::Protocol(const unsigned short value)
	{
		SetOrAddField("Protocol", TypeConverter::TypeToString(value));
	}
	bool CIM_ListenerDestination::ProtocolExists() const
	{
		return ContainsField("Protocol");
	}
	void CIM_ListenerDestination::RemoveProtocol()
	{
		RemoveField("Protocol");
	}

	CimBase *CIM_ListenerDestination::CreateFromCimObject(const CimObject &object)
	{
		CIM_ListenerDestination *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ListenerDestination>(object);
		}
		else
		{
			ret = new CIM_ListenerDestination(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ListenerDestination> > CIM_ListenerDestination::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ListenerDestination>(client, keys);
	}

	void CIM_ListenerDestination::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ListenerDestination::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ListenerDestination::CLASS_NAME = "CIM_ListenerDestination";
	const string CIM_ListenerDestination::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestination";
	const string CIM_ListenerDestination::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestination";
	const string CIM_ListenerDestination::CLASS_NS_PREFIX = "ALi422";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ListenerDestination::_classMetaData;
}
}
}
}
