//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalConnector.cpp
//
//  Contents:   The PhysicalConnector class represents any PhysicalElement that is used to connect to other Elements. Any object that can be used to connect and transmit signals or power between two or more PhysicalElements is a descendant (or member) of this class. For example, Slots and D-shell connectors are types of PhysicalConnectors.
//
//              This file was automatically generated from CIM_PhysicalConnector.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_PhysicalConnector.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_PhysicalConnector::_metadata[] = {
		{"ConnectorPinout", false, false, false },
		{"ConnectorType", false, false, false },
		{"OtherTypeDescription", false, false, false },
		{"ConnectorGender", false, false, false },
		{"ConnectorElectricalCharacteristics", false, false, false },
		{"OtherElectricalCharacteristics", false, false, false },
		{"NumPhysicalPins", false, false, false },
		{"ConnectorLayout", false, false, false },
		{"ConnectorDescription", false, false, false },
	};
	// class fields
	const string CIM_PhysicalConnector::ConnectorPinout() const
	{
		return GetField("ConnectorPinout")[0];
	}
	void CIM_PhysicalConnector::ConnectorPinout(const string &value)
	{
		SetOrAddField("ConnectorPinout", value);
	}
	bool CIM_PhysicalConnector::ConnectorPinoutExists() const
	{
		return ContainsField("ConnectorPinout");
	}
	void CIM_PhysicalConnector::RemoveConnectorPinout()
	{
		RemoveField("ConnectorPinout");
	}

	const vector<unsigned short> CIM_PhysicalConnector::ConnectorType() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ConnectorType"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::ConnectorType(const vector<unsigned short> &value)
	{
		SetOrAddField("ConnectorType", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::ConnectorTypeExists() const
	{
		return ContainsField("ConnectorType");
	}
	void CIM_PhysicalConnector::RemoveConnectorType()
	{
		RemoveField("ConnectorType");
	}

	const string CIM_PhysicalConnector::OtherTypeDescription() const
	{
		return GetField("OtherTypeDescription")[0];
	}
	void CIM_PhysicalConnector::OtherTypeDescription(const string &value)
	{
		SetOrAddField("OtherTypeDescription", value);
	}
	bool CIM_PhysicalConnector::OtherTypeDescriptionExists() const
	{
		return ContainsField("OtherTypeDescription");
	}
	void CIM_PhysicalConnector::RemoveOtherTypeDescription()
	{
		RemoveField("OtherTypeDescription");
	}

	const unsigned short CIM_PhysicalConnector::ConnectorGender() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ConnectorGender"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::ConnectorGender(const unsigned short value)
	{
		SetOrAddField("ConnectorGender", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::ConnectorGenderExists() const
	{
		return ContainsField("ConnectorGender");
	}
	void CIM_PhysicalConnector::RemoveConnectorGender()
	{
		RemoveField("ConnectorGender");
	}

	const vector<unsigned short> CIM_PhysicalConnector::ConnectorElectricalCharacteristics() const
	{
		vector<unsigned short> ret;
		TypeConverter::StringToType(GetField("ConnectorElectricalCharacteristics"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::ConnectorElectricalCharacteristics(const vector<unsigned short> &value)
	{
		SetOrAddField("ConnectorElectricalCharacteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::ConnectorElectricalCharacteristicsExists() const
	{
		return ContainsField("ConnectorElectricalCharacteristics");
	}
	void CIM_PhysicalConnector::RemoveConnectorElectricalCharacteristics()
	{
		RemoveField("ConnectorElectricalCharacteristics");
	}

	const vector<string> CIM_PhysicalConnector::OtherElectricalCharacteristics() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("OtherElectricalCharacteristics"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::OtherElectricalCharacteristics(const vector<string> &value)
	{
		SetOrAddField("OtherElectricalCharacteristics", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::OtherElectricalCharacteristicsExists() const
	{
		return ContainsField("OtherElectricalCharacteristics");
	}
	void CIM_PhysicalConnector::RemoveOtherElectricalCharacteristics()
	{
		RemoveField("OtherElectricalCharacteristics");
	}

	const unsigned int CIM_PhysicalConnector::NumPhysicalPins() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("NumPhysicalPins"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::NumPhysicalPins(const unsigned int value)
	{
		SetOrAddField("NumPhysicalPins", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::NumPhysicalPinsExists() const
	{
		return ContainsField("NumPhysicalPins");
	}
	void CIM_PhysicalConnector::RemoveNumPhysicalPins()
	{
		RemoveField("NumPhysicalPins");
	}

	const unsigned short CIM_PhysicalConnector::ConnectorLayout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ConnectorLayout"), ret);
		return ret;
	}
	void CIM_PhysicalConnector::ConnectorLayout(const unsigned short value)
	{
		SetOrAddField("ConnectorLayout", TypeConverter::TypeToString(value));
	}
	bool CIM_PhysicalConnector::ConnectorLayoutExists() const
	{
		return ContainsField("ConnectorLayout");
	}
	void CIM_PhysicalConnector::RemoveConnectorLayout()
	{
		RemoveField("ConnectorLayout");
	}

	const string CIM_PhysicalConnector::ConnectorDescription() const
	{
		return GetField("ConnectorDescription")[0];
	}
	void CIM_PhysicalConnector::ConnectorDescription(const string &value)
	{
		SetOrAddField("ConnectorDescription", value);
	}
	bool CIM_PhysicalConnector::ConnectorDescriptionExists() const
	{
		return ContainsField("ConnectorDescription");
	}
	void CIM_PhysicalConnector::RemoveConnectorDescription()
	{
		RemoveField("ConnectorDescription");
	}

	CimBase *CIM_PhysicalConnector::CreateFromCimObject(const CimObject &object)
	{
		CIM_PhysicalConnector *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_PhysicalConnector>(object);
		}
		else
		{
			ret = new CIM_PhysicalConnector(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_PhysicalConnector> > CIM_PhysicalConnector::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_PhysicalConnector>(client, keys);
	}

	void CIM_PhysicalConnector::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_PhysicalConnector::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_PhysicalConnector::CLASS_NAME = "CIM_PhysicalConnector";
	const string CIM_PhysicalConnector::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalConnector";
	const string CIM_PhysicalConnector::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_PhysicalConnector";
	const string CIM_PhysicalConnector::CLASS_NS_PREFIX = "APh394";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_PhysicalConnector::_classMetaData;
}
}
}
}
