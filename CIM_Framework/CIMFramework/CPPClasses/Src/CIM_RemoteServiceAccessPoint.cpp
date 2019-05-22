//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteServiceAccessPoint.cpp
//
//  Contents:   RemoteServiceAccessPoint describes access or addressing information or a combination of this information for a remote connection that is known to a local network element. This information is scoped or contained by the local network element, because this is the context in which the connection is remote. 
//              The relevance of the remote access point and information on its use are described by subclassing RemoteServiceAccessPoint or by associating to it.
//
//              This file was automatically generated from CIM_RemoteServiceAccessPoint.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_RemoteServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_RemoteServiceAccessPoint::_metadata[] = {
		{"AccessInfo", false, false, false },
		{"InfoFormat", false, false, false },
		{"OtherInfoFormatDescription", false, false, false },
		{"AccessContext", false, false, false },
		{"OtherAccessContext", false, false, false },
	};
	// class fields
	const string CIM_RemoteServiceAccessPoint::AccessInfo() const
	{
		return GetField("AccessInfo")[0];
	}
	void CIM_RemoteServiceAccessPoint::AccessInfo(const string &value)
	{
		SetOrAddField("AccessInfo", value);
	}
	bool CIM_RemoteServiceAccessPoint::AccessInfoExists() const
	{
		return ContainsField("AccessInfo");
	}
	void CIM_RemoteServiceAccessPoint::RemoveAccessInfo()
	{
		RemoveField("AccessInfo");
	}

	const unsigned short CIM_RemoteServiceAccessPoint::InfoFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("InfoFormat"), ret);
		return ret;
	}
	void CIM_RemoteServiceAccessPoint::InfoFormat(const unsigned short value)
	{
		SetOrAddField("InfoFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteServiceAccessPoint::InfoFormatExists() const
	{
		return ContainsField("InfoFormat");
	}
	void CIM_RemoteServiceAccessPoint::RemoveInfoFormat()
	{
		RemoveField("InfoFormat");
	}

	const string CIM_RemoteServiceAccessPoint::OtherInfoFormatDescription() const
	{
		return GetField("OtherInfoFormatDescription")[0];
	}
	void CIM_RemoteServiceAccessPoint::OtherInfoFormatDescription(const string &value)
	{
		SetOrAddField("OtherInfoFormatDescription", value);
	}
	bool CIM_RemoteServiceAccessPoint::OtherInfoFormatDescriptionExists() const
	{
		return ContainsField("OtherInfoFormatDescription");
	}
	void CIM_RemoteServiceAccessPoint::RemoveOtherInfoFormatDescription()
	{
		RemoveField("OtherInfoFormatDescription");
	}

	const unsigned short CIM_RemoteServiceAccessPoint::AccessContext() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AccessContext"), ret);
		return ret;
	}
	void CIM_RemoteServiceAccessPoint::AccessContext(const unsigned short value)
	{
		SetOrAddField("AccessContext", TypeConverter::TypeToString(value));
	}
	bool CIM_RemoteServiceAccessPoint::AccessContextExists() const
	{
		return ContainsField("AccessContext");
	}
	void CIM_RemoteServiceAccessPoint::RemoveAccessContext()
	{
		RemoveField("AccessContext");
	}

	const string CIM_RemoteServiceAccessPoint::OtherAccessContext() const
	{
		return GetField("OtherAccessContext")[0];
	}
	void CIM_RemoteServiceAccessPoint::OtherAccessContext(const string &value)
	{
		SetOrAddField("OtherAccessContext", value);
	}
	bool CIM_RemoteServiceAccessPoint::OtherAccessContextExists() const
	{
		return ContainsField("OtherAccessContext");
	}
	void CIM_RemoteServiceAccessPoint::RemoveOtherAccessContext()
	{
		RemoveField("OtherAccessContext");
	}

	CimBase *CIM_RemoteServiceAccessPoint::CreateFromCimObject(const CimObject &object)
	{
		CIM_RemoteServiceAccessPoint *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_RemoteServiceAccessPoint>(object);
		}
		else
		{
			ret = new CIM_RemoteServiceAccessPoint(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_RemoteServiceAccessPoint> > CIM_RemoteServiceAccessPoint::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_RemoteServiceAccessPoint>(client, keys);
	}

	void CIM_RemoteServiceAccessPoint::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_RemoteServiceAccessPoint::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute CIM_RemoteServiceAccessPoint::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_RemoteServiceAccessPoint::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_RemoteServiceAccessPoint::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_RemoteServiceAccessPoint::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_RemoteServiceAccessPoint::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_RemoteServiceAccessPoint::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_RemoteServiceAccessPoint::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_RemoteServiceAccessPoint::CLASS_NAME = "CIM_RemoteServiceAccessPoint";
	const string CIM_RemoteServiceAccessPoint::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteServiceAccessPoint";
	const string CIM_RemoteServiceAccessPoint::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RemoteServiceAccessPoint";
	const string CIM_RemoteServiceAccessPoint::CLASS_NS_PREFIX = "ARe365";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_RemoteServiceAccessPoint::_classMetaData;
}
}
}
}
