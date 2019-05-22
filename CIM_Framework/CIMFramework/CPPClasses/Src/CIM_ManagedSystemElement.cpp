//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ManagedSystemElement.cpp
//
//  Contents:   CIM_ManagedSystemElement is the base class for the System Element hierarchy. Any distinguishable component of a System is a candidate for inclusion in this class. Examples of system components include: 
//              - software components such as application servers, databases, and applications 
//              - operating system components such as files, processes, and threads 
//              - device components such as disk drives, controllers, processors, and printers 
//              - physical components such as chips and cards.
//
//              This file was automatically generated from CIM_ManagedSystemElement.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#include "CIM_ManagedSystemElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ManagedSystemElement::_metadata[] = {
		{"InstallDate", false, false, false },
		{"Name", false, false, false },
		{"OperationalStatus", false, false, false },
		{"StatusDescriptions", false, false, false },
		{"Status", false, false, false },
		{"HealthState", false, false, false },
		{"CommunicationStatus", false, false, false },
		{"DetailedStatus", false, false, false },
		{"OperatingStatus", false, false, false },
		{"PrimaryStatus", false, false, false },
	};
	// class fields
	const CimDateTime CIM_ManagedSystemElement::InstallDate() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("InstallDate"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::InstallDate(const CimDateTime &value)
	{
		SetOrAddField("InstallDate", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::InstallDateExists() const
	{
		return ContainsField("InstallDate");
	}
	void CIM_ManagedSystemElement::RemoveInstallDate()
	{
		RemoveField("InstallDate");
	}

	const string CIM_ManagedSystemElement::Name() const
	{
		return GetField("Name")[0];
	}
	void CIM_ManagedSystemElement::Name(const string &value)
	{
		SetOrAddField("Name", value);
	}
	bool CIM_ManagedSystemElement::NameExists() const
	{
		return ContainsField("Name");
	}
	void CIM_ManagedSystemElement::RemoveName()
	{
		RemoveField("Name");
	}

	const vector<unsigned short> CIM_ManagedSystemElement::OperationalStatus() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("OperationalStatus"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::OperationalStatus(const vector<unsigned short> &value)
	{
		SetOrAddField("OperationalStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::OperationalStatusExists() const
	{
		return ContainsField("OperationalStatus");
	}
	void CIM_ManagedSystemElement::RemoveOperationalStatus()
	{
		RemoveField("OperationalStatus");
	}

	const vector<string> CIM_ManagedSystemElement::StatusDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("StatusDescriptions"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::StatusDescriptions(const vector<string> &value)
	{
		SetOrAddField("StatusDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::StatusDescriptionsExists() const
	{
		return ContainsField("StatusDescriptions");
	}
	void CIM_ManagedSystemElement::RemoveStatusDescriptions()
	{
		RemoveField("StatusDescriptions");
	}

	const string CIM_ManagedSystemElement::Status() const
	{
		return GetField("Status")[0];
	}
	void CIM_ManagedSystemElement::Status(const string &value)
	{
		SetOrAddField("Status", value);
	}
	bool CIM_ManagedSystemElement::StatusExists() const
	{
		return ContainsField("Status");
	}
	void CIM_ManagedSystemElement::RemoveStatus()
	{
		RemoveField("Status");
	}

	const unsigned short CIM_ManagedSystemElement::HealthState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("HealthState"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::HealthState(const unsigned short value)
	{
		SetOrAddField("HealthState", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::HealthStateExists() const
	{
		return ContainsField("HealthState");
	}
	void CIM_ManagedSystemElement::RemoveHealthState()
	{
		RemoveField("HealthState");
	}

	const unsigned short CIM_ManagedSystemElement::CommunicationStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CommunicationStatus"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::CommunicationStatus(const unsigned short value)
	{
		SetOrAddField("CommunicationStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::CommunicationStatusExists() const
	{
		return ContainsField("CommunicationStatus");
	}
	void CIM_ManagedSystemElement::RemoveCommunicationStatus()
	{
		RemoveField("CommunicationStatus");
	}

	const unsigned short CIM_ManagedSystemElement::DetailedStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DetailedStatus"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::DetailedStatus(const unsigned short value)
	{
		SetOrAddField("DetailedStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::DetailedStatusExists() const
	{
		return ContainsField("DetailedStatus");
	}
	void CIM_ManagedSystemElement::RemoveDetailedStatus()
	{
		RemoveField("DetailedStatus");
	}

	const unsigned short CIM_ManagedSystemElement::OperatingStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OperatingStatus"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::OperatingStatus(const unsigned short value)
	{
		SetOrAddField("OperatingStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::OperatingStatusExists() const
	{
		return ContainsField("OperatingStatus");
	}
	void CIM_ManagedSystemElement::RemoveOperatingStatus()
	{
		RemoveField("OperatingStatus");
	}

	const unsigned short CIM_ManagedSystemElement::PrimaryStatus() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PrimaryStatus"), ret);
		return ret;
	}
	void CIM_ManagedSystemElement::PrimaryStatus(const unsigned short value)
	{
		SetOrAddField("PrimaryStatus", TypeConverter::TypeToString(value));
	}
	bool CIM_ManagedSystemElement::PrimaryStatusExists() const
	{
		return ContainsField("PrimaryStatus");
	}
	void CIM_ManagedSystemElement::RemovePrimaryStatus()
	{
		RemoveField("PrimaryStatus");
	}

	CimBase *CIM_ManagedSystemElement::CreateFromCimObject(const CimObject &object)
	{
		CIM_ManagedSystemElement *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ManagedSystemElement>(object);
		}
		else
		{
			ret = new CIM_ManagedSystemElement(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ManagedSystemElement> > CIM_ManagedSystemElement::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ManagedSystemElement>(client, keys);
	}

	void CIM_ManagedSystemElement::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ManagedSystemElement::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ManagedSystemElement::CLASS_NAME = "CIM_ManagedSystemElement";
	const string CIM_ManagedSystemElement::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedSystemElement";
	const string CIM_ManagedSystemElement::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ManagedSystemElement";
	const string CIM_ManagedSystemElement::CLASS_NS_PREFIX = "AMa122";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ManagedSystemElement::_classMetaData;
}
}
}
}
