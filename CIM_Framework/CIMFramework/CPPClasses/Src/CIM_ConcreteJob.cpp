//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ConcreteJob.cpp
//
//  Contents:   A concrete version of Job. This class represents a generic and instantiable unit of work, such as a batch or a print job.
//
//              This file was automatically generated from CIM_ConcreteJob.mof,  version: 2.31.1
//
//----------------------------------------------------------------------------
#include "CIM_ConcreteJob.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_ConcreteJob::_metadata[] = {
		{"InstanceID", true, false, false },
		{"Name", false, true, false },
		{"JobState", false, false, false },
		{"TimeOfLastStateChange", false, false, false },
		{"TimeBeforeRemoval", false, true, false },
	};
	// class fields
	const unsigned short CIM_ConcreteJob::JobState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("JobState"), ret);
		return ret;
	}
	void CIM_ConcreteJob::JobState(const unsigned short value)
	{
		SetOrAddField("JobState", TypeConverter::TypeToString(value));
	}
	bool CIM_ConcreteJob::JobStateExists() const
	{
		return ContainsField("JobState");
	}
	void CIM_ConcreteJob::RemoveJobState()
	{
		RemoveField("JobState");
	}

	const CimDateTime CIM_ConcreteJob::TimeOfLastStateChange() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastStateChange"), ret);
		return ret;
	}
	void CIM_ConcreteJob::TimeOfLastStateChange(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastStateChange", TypeConverter::TypeToString(value));
	}
	bool CIM_ConcreteJob::TimeOfLastStateChangeExists() const
	{
		return ContainsField("TimeOfLastStateChange");
	}
	void CIM_ConcreteJob::RemoveTimeOfLastStateChange()
	{
		RemoveField("TimeOfLastStateChange");
	}

	const CimDateTime CIM_ConcreteJob::TimeBeforeRemoval() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeBeforeRemoval"), ret);
		return ret;
	}
	void CIM_ConcreteJob::TimeBeforeRemoval(const CimDateTime &value)
	{
		SetOrAddField("TimeBeforeRemoval", TypeConverter::TypeToString(value));
	}
	bool CIM_ConcreteJob::TimeBeforeRemovalExists() const
	{
		return ContainsField("TimeBeforeRemoval");
	}
	void CIM_ConcreteJob::RemoveTimeBeforeRemoval()
	{
		RemoveField("TimeBeforeRemoval");
	}

	CimBase *CIM_ConcreteJob::CreateFromCimObject(const CimObject &object)
	{
		CIM_ConcreteJob *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_ConcreteJob>(object);
		}
		else
		{
			ret = new CIM_ConcreteJob(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_ConcreteJob> > CIM_ConcreteJob::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_ConcreteJob>(client, keys);
	}

	void CIM_ConcreteJob::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_ConcreteJob::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_ConcreteJob::CLASS_NAME = "CIM_ConcreteJob";
	const string CIM_ConcreteJob::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteJob";
	const string CIM_ConcreteJob::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ConcreteJob";
	const string CIM_ConcreteJob::CLASS_NS_PREFIX = "ACo72";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_ConcreteJob::_classMetaData;
}
}
}
}
