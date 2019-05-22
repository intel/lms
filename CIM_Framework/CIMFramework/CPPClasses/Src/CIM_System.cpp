//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_System.cpp
//
//  Contents:   CIM_System represents an entity made up of component parts (defined by the SystemComponent relationship), that operates as a 'functional whole'. Systems are top-level objects in the CIM hierarchy, requiring no scoping or weak relationships in order to exist and have context. It should be reasonable to uniquely name and manage a System at an enterprise level. For example, a ComputerSystem is a kind of System that can be uniquely named and independently managed in an enterprise. However, these qualities are not true for the power supply (or the power supply sub-'system') within the computer. 
//              
//              Although a System can be viewed as a Collection, this view is not the correct model. A Collection is simply a 'bag' that 'holds' its members. A System is a higher-level abstraction, built out of its individual components. It is more than the sum of its parts. Note that System is a subclass of EnabledLogicalElement which allows the entire abstraction to be functionally enabled or disabled at a higher level than enabling or disabling its component parts.
//
//              This file was automatically generated from CIM_System.mof,  version: 2.15.0
//
//----------------------------------------------------------------------------
#include "CIM_System.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_System::_metadata[] = {
		{"CreationClassName", true, false, false },
		{"Name", true, false, false },
		{"NameFormat", false, false, false },
		{"PrimaryOwnerName", false, false, false },
		{"PrimaryOwnerContact", false, false, false },
		{"Roles", false, false, false },
		{"OtherIdentifyingInfo", false, false, false },
		{"IdentifyingDescriptions", false, false, false },
	};
	// class fields
	const string CIM_System::CreationClassName() const
	{
		return GetField("CreationClassName")[0];
	}
	void CIM_System::CreationClassName(const string &value)
	{
		SetOrAddField("CreationClassName", value);
	}

	const string CIM_System::NameFormat() const
	{
		return GetField("NameFormat")[0];
	}
	void CIM_System::NameFormat(const string &value)
	{
		SetOrAddField("NameFormat", value);
	}
	bool CIM_System::NameFormatExists() const
	{
		return ContainsField("NameFormat");
	}
	void CIM_System::RemoveNameFormat()
	{
		RemoveField("NameFormat");
	}

	const string CIM_System::PrimaryOwnerName() const
	{
		return GetField("PrimaryOwnerName")[0];
	}
	void CIM_System::PrimaryOwnerName(const string &value)
	{
		SetOrAddField("PrimaryOwnerName", value);
	}
	bool CIM_System::PrimaryOwnerNameExists() const
	{
		return ContainsField("PrimaryOwnerName");
	}
	void CIM_System::RemovePrimaryOwnerName()
	{
		RemoveField("PrimaryOwnerName");
	}

	const string CIM_System::PrimaryOwnerContact() const
	{
		return GetField("PrimaryOwnerContact")[0];
	}
	void CIM_System::PrimaryOwnerContact(const string &value)
	{
		SetOrAddField("PrimaryOwnerContact", value);
	}
	bool CIM_System::PrimaryOwnerContactExists() const
	{
		return ContainsField("PrimaryOwnerContact");
	}
	void CIM_System::RemovePrimaryOwnerContact()
	{
		RemoveField("PrimaryOwnerContact");
	}

	const vector<string> CIM_System::Roles() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("Roles"), ret);
		return ret;
	}
	void CIM_System::Roles(const vector<string> &value)
	{
		SetOrAddField("Roles", TypeConverter::TypeToString(value));
	}
	bool CIM_System::RolesExists() const
	{
		return ContainsField("Roles");
	}
	void CIM_System::RemoveRoles()
	{
		RemoveField("Roles");
	}

	const vector<string> CIM_System::OtherIdentifyingInfo() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherIdentifyingInfo"), ret);
		return ret;
	}
	void CIM_System::OtherIdentifyingInfo(const vector<string> &value)
	{
		SetOrAddField("OtherIdentifyingInfo", TypeConverter::TypeToString(value));
	}
	bool CIM_System::OtherIdentifyingInfoExists() const
	{
		return ContainsField("OtherIdentifyingInfo");
	}
	void CIM_System::RemoveOtherIdentifyingInfo()
	{
		RemoveField("OtherIdentifyingInfo");
	}

	const vector<string> CIM_System::IdentifyingDescriptions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("IdentifyingDescriptions"), ret);
		return ret;
	}
	void CIM_System::IdentifyingDescriptions(const vector<string> &value)
	{
		SetOrAddField("IdentifyingDescriptions", TypeConverter::TypeToString(value));
	}
	bool CIM_System::IdentifyingDescriptionsExists() const
	{
		return ContainsField("IdentifyingDescriptions");
	}
	void CIM_System::RemoveIdentifyingDescriptions()
	{
		RemoveField("IdentifyingDescriptions");
	}

	CimBase *CIM_System::CreateFromCimObject(const CimObject &object)
	{
		CIM_System *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_System>(object);
		}
		else
		{
			ret = new CIM_System(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_System> > CIM_System::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_System>(client, keys);
	}

	void CIM_System::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_System::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_System::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_System::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_System::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_System::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_System::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_System::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_System::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_System::CLASS_NAME = "CIM_System";
	const string CIM_System::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_System";
	const string CIM_System::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_System";
	const string CIM_System::CLASS_NS_PREFIX = "ASy217";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_System::_classMetaData;
}
}
}
}
