//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemotePort.cpp
//
//  Contents:   RemotePort adds port information to the access data (such as IP Address) that is specified in and inherited from RemoteServiceAccessPoint. For example, using the additional properties in this class, you could indicate that UDP Port 123 is accessed at IP Address xyz. The IP Address would be specified in the inherited AccessInfo property, while the UDP Port number would be specified in the PortInfo property of this class.
//
//              This file was automatically generated from CIM_RemotePort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_RemotePort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RemotePort::_metadata[] = {
		{"PortInfo", false, false, false },
		{"PortProtocol", false, false, false },
		{"OtherProtocolDescription", false, false, false },
	};
	// class fields
	const string CIM_RemotePort::PortInfo() const
	{
		return GetField("PortInfo")[0];
	}
	void CIM_RemotePort::PortInfo(const string &value)
	{
		SetOrAddField("PortInfo", value);
	}
	bool CIM_RemotePort::PortInfoExists() const
	{
		return ContainsField("PortInfo");
	}
	void CIM_RemotePort::RemovePortInfo()
	{
		RemoveField("PortInfo");
	}

	const unsigned short CIM_RemotePort::PortProtocol() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PortProtocol"), ret);
		return ret;
	}
	void CIM_RemotePort::PortProtocol(const unsigned short value)
	{
		SetOrAddField("PortProtocol", TypeConverter::TypeToString(value));
	}
	bool CIM_RemotePort::PortProtocolExists() const
	{
		return ContainsField("PortProtocol");
	}
	void CIM_RemotePort::RemovePortProtocol()
	{
		RemoveField("PortProtocol");
	}

	const string CIM_RemotePort::OtherProtocolDescription() const
	{
		return GetField("OtherProtocolDescription")[0];
	}
	void CIM_RemotePort::OtherProtocolDescription(const string &value)
	{
		SetOrAddField("OtherProtocolDescription", value);
	}
	bool CIM_RemotePort::OtherProtocolDescriptionExists() const
	{
		return ContainsField("OtherProtocolDescription");
	}
	void CIM_RemotePort::RemoveOtherProtocolDescription()
	{
		RemoveField("OtherProtocolDescription");
	}

	CimBase *CIM_RemotePort::CreateFromCimObject(const CimObject &object)
	{
		CIM_RemotePort *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RemotePort>(object);
		}
		else
		{
			ret = new CIM_RemotePort(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RemotePort> > CIM_RemotePort::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RemotePort>(client, keys);
	}

	void CIM_RemotePort::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RemotePort::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_RemotePort::CLASS_NAME = "CIM_RemotePort";
	const string CIM_RemotePort::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemotePort";
	const string CIM_RemotePort::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemotePort";
	const string CIM_RemotePort::CLASS_NS_PREFIX = "ARe127";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RemotePort::_classMetaData;
}
}
}
}
