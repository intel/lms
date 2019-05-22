//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PETFilterForTarget.cpp
//
//  Contents:   This class associates an event filter (AMT_PETFilterSetting instance) to an events subscriber (AMT_SOAPEventSubscriber or AMT_SNMPEventSubscriber).
//
//              This file was automatically generated from AMT_PETFilterForTarget.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_PETFilterForTarget.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_PETFilterForTarget::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *AMT_PETFilterForTarget::CreateFromCimObject(const CimObject &object)
	{
		AMT_PETFilterForTarget *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_PETFilterForTarget>(object);
		}
		else
		{
			ret = new AMT_PETFilterForTarget(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_PETFilterForTarget> > AMT_PETFilterForTarget::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_PETFilterForTarget>(client, keys);
	}

	void AMT_PETFilterForTarget::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_PETFilterForTarget::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_PETFilterForTarget::CLASS_NAME = "AMT_PETFilterForTarget";
	const string AMT_PETFilterForTarget::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETFilterForTarget";
	const string AMT_PETFilterForTarget::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_PETFilterForTarget";
	const string AMT_PETFilterForTarget::CLASS_NS_PREFIX = "APE474";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_PETFilterForTarget::_classMetaData;
}
}
}
}
