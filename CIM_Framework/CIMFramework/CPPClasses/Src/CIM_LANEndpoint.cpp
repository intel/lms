//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LANEndpoint.cpp
//
//  Contents:   A communication endpoint which, when its associated interface device is connected to a LAN, may send and receive data frames. LANEndpoints include Ethernet, Token Ring and FDDI interfaces.
//
//              This file was automatically generated from CIM_LANEndpoint.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#include "CIM_LANEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_LANEndpoint::_metadata[] = {
		{"LANID", false, false, false },
		{"LANType", false, false, false },
		{"OtherLANType", false, false, false },
		{"MACAddress", false, false, false },
		{"AliasAddresses", false, false, false },
		{"GroupAddresses", false, false, false },
		{"MaxDataSize", false, false, false },
	};
	// class fields
	const string CIM_LANEndpoint::LANID() const
	{
		return GetField("LANID")[0];
	}
	void CIM_LANEndpoint::LANID(const string &value)
	{
		SetOrAddField("LANID", value);
	}
	bool CIM_LANEndpoint::LANIDExists() const
	{
		return ContainsField("LANID");
	}
	void CIM_LANEndpoint::RemoveLANID()
	{
		RemoveField("LANID");
	}

	const unsigned short CIM_LANEndpoint::LANType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("LANType"), ret);
		return ret;
	}
	void CIM_LANEndpoint::LANType(const unsigned short value)
	{
		SetOrAddField("LANType", TypeConverter::TypeToString(value));
	}
	bool CIM_LANEndpoint::LANTypeExists() const
	{
		return ContainsField("LANType");
	}
	void CIM_LANEndpoint::RemoveLANType()
	{
		RemoveField("LANType");
	}

	const string CIM_LANEndpoint::OtherLANType() const
	{
		return GetField("OtherLANType")[0];
	}
	void CIM_LANEndpoint::OtherLANType(const string &value)
	{
		SetOrAddField("OtherLANType", value);
	}
	bool CIM_LANEndpoint::OtherLANTypeExists() const
	{
		return ContainsField("OtherLANType");
	}
	void CIM_LANEndpoint::RemoveOtherLANType()
	{
		RemoveField("OtherLANType");
	}

	const string CIM_LANEndpoint::MACAddress() const
	{
		return GetField("MACAddress")[0];
	}
	void CIM_LANEndpoint::MACAddress(const string &value)
	{
		SetOrAddField("MACAddress", value);
	}
	bool CIM_LANEndpoint::MACAddressExists() const
	{
		return ContainsField("MACAddress");
	}
	void CIM_LANEndpoint::RemoveMACAddress()
	{
		RemoveField("MACAddress");
	}

	const vector<string> CIM_LANEndpoint::AliasAddresses() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("AliasAddresses"), ret);
		return ret;
	}
	void CIM_LANEndpoint::AliasAddresses(const vector<string> &value)
	{
		SetOrAddField("AliasAddresses", TypeConverter::TypeToString(value));
	}
	bool CIM_LANEndpoint::AliasAddressesExists() const
	{
		return ContainsField("AliasAddresses");
	}
	void CIM_LANEndpoint::RemoveAliasAddresses()
	{
		RemoveField("AliasAddresses");
	}

	const vector<string> CIM_LANEndpoint::GroupAddresses() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("GroupAddresses"), ret);
		return ret;
	}
	void CIM_LANEndpoint::GroupAddresses(const vector<string> &value)
	{
		SetOrAddField("GroupAddresses", TypeConverter::TypeToString(value));
	}
	bool CIM_LANEndpoint::GroupAddressesExists() const
	{
		return ContainsField("GroupAddresses");
	}
	void CIM_LANEndpoint::RemoveGroupAddresses()
	{
		RemoveField("GroupAddresses");
	}

	const unsigned int CIM_LANEndpoint::MaxDataSize() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxDataSize"), ret);
		return ret;
	}
	void CIM_LANEndpoint::MaxDataSize(const unsigned int value)
	{
		SetOrAddField("MaxDataSize", TypeConverter::TypeToString(value));
	}
	bool CIM_LANEndpoint::MaxDataSizeExists() const
	{
		return ContainsField("MaxDataSize");
	}
	void CIM_LANEndpoint::RemoveMaxDataSize()
	{
		RemoveField("MaxDataSize");
	}

	CimBase *CIM_LANEndpoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_LANEndpoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_LANEndpoint>(object);
		}
		else
		{
			ret = new CIM_LANEndpoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_LANEndpoint> > CIM_LANEndpoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_LANEndpoint>(client, keys);
	}

	void CIM_LANEndpoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_LANEndpoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_LANEndpoint::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_LANEndpoint::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_LANEndpoint::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_LANEndpoint::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_LANEndpoint::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_LANEndpoint::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_LANEndpoint::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_LANEndpoint::CLASS_NAME = "CIM_LANEndpoint";
	const string CIM_LANEndpoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LANEndpoint";
	const string CIM_LANEndpoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_LANEndpoint";
	const string CIM_LANEndpoint::CLASS_NS_PREFIX = "ALA14";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_LANEndpoint::_classMetaData;
}
}
}
}
