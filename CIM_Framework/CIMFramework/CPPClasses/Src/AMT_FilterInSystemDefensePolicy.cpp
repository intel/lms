//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_FilterInSystemDefensePolicy.cpp
//
//  Contents:   This Class associates a System Defense Policy to a System Defense Filter.
//
//              This file was automatically generated from AMT_FilterInSystemDefensePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#include "AMT_FilterInSystemDefensePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute AMT_FilterInSystemDefensePolicy::_metadata[] = {
		{"Antecedent", true, false, true },
		{"Dependent", true, false, true },
	};
	// class fields
	CimBase *AMT_FilterInSystemDefensePolicy::CreateFromCimObject(const CimObject &object)
	{
		AMT_FilterInSystemDefensePolicy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<AMT_FilterInSystemDefensePolicy>(object);
		}
		else
		{
			ret = new AMT_FilterInSystemDefensePolicy(object);
		}
		return ret;
	}

	vector<shared_ptr<AMT_FilterInSystemDefensePolicy> > AMT_FilterInSystemDefensePolicy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<AMT_FilterInSystemDefensePolicy>(client, keys);
	}

	void AMT_FilterInSystemDefensePolicy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &AMT_FilterInSystemDefensePolicy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string AMT_FilterInSystemDefensePolicy::CLASS_NAME = "AMT_FilterInSystemDefensePolicy";
	const string AMT_FilterInSystemDefensePolicy::CLASS_URI = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_FilterInSystemDefensePolicy";
	const string AMT_FilterInSystemDefensePolicy::CLASS_NS = "http://intel.com/wbem/wscim/1/amt-schema/1/AMT_FilterInSystemDefensePolicy";
	const string AMT_FilterInSystemDefensePolicy::CLASS_NS_PREFIX = "AFi673";
	CIMFRAMEWORK_API vector <CimFieldAttribute> AMT_FilterInSystemDefensePolicy::_classMetaData;
}
}
}
}
