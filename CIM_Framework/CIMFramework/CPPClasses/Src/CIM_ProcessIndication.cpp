//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProcessIndication.cpp
//
//  Contents:   An abstract superclass for specialized Indication classes, addressing specific changes and alerts published by providers and instrumentation. Subclasses include AlertIndication (with properties such as PerceivedSeverity and ProbableCause), and SNMPTrapIndication (which recasts Traps as CIM indications).
//
//              This file was automatically generated from CIM_ProcessIndication.mof,  version: 2.29.0
//
//----------------------------------------------------------------------------
#include "CIM_ProcessIndication.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// class fields
	CimBase *CIM_ProcessIndication::CreateFromCimObject(const CimObject &object)
	{
		CIM_ProcessIndication *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ProcessIndication>(object);
		}
		else
		{
			ret = new CIM_ProcessIndication(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ProcessIndication> > CIM_ProcessIndication::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ProcessIndication>(client, keys);
	}

	void CIM_ProcessIndication::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ProcessIndication::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ProcessIndication::CLASS_NAME = "CIM_ProcessIndication";
	const string CIM_ProcessIndication::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProcessIndication";
	const string CIM_ProcessIndication::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ProcessIndication";
	const string CIM_ProcessIndication::CLASS_NS_PREFIX = "APr909";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ProcessIndication::_classMetaData;
}
}
}
}
