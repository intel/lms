//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAccessBySAP.cpp
//
//  Contents:   CIM_ServiceAccessBySAP is an association that identifies the access points for a Service. For example, a printer might be accessed by NetWare, MacIntosh or Windows ServiceAccessPoints, which might all be hosted on different Systems.
//
//              This file was automatically generated from CIM_ServiceAccessBySAP.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_ServiceAccessBySAP.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ServiceAccessBySAP::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *CIM_ServiceAccessBySAP::CreateFromCimObject(const CimObject &object)
	{
		CIM_ServiceAccessBySAP *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ServiceAccessBySAP>(object);
		}
		else
		{
			ret = new CIM_ServiceAccessBySAP(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ServiceAccessBySAP> > CIM_ServiceAccessBySAP::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ServiceAccessBySAP>(client, keys);
	}

	void CIM_ServiceAccessBySAP::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ServiceAccessBySAP::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ServiceAccessBySAP::CLASS_NAME = "CIM_ServiceAccessBySAP";
	const string CIM_ServiceAccessBySAP::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAccessBySAP";
	const string CIM_ServiceAccessBySAP::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ServiceAccessBySAP";
	const string CIM_ServiceAccessBySAP::CLASS_NS_PREFIX = "ASe450";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ServiceAccessBySAP::_classMetaData;
}
}
}
}
