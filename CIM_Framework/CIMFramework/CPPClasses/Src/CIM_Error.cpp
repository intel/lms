//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Error.cpp
//
//  Contents:   CIM_Error is a specialized class that contains information about the severity, cause, recommended actions and other data related to the failure of a CIM Operation. Instances of this type MAY be included as part of the response to a CIM Operation.
//
//              This file was automatically generated from CIM_Error.mof,  version: 2.22.1
//
//----------------------------------------------------------------------------
#include "CIM_Error.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Error::_metadata[] = {
		{"ErrorType", false, false, false },
		{"OtherErrorType", false, false, false },
		{"OwningEntity", false, false, false },
		{"MessageID", false, true, false },
		{"Message", false, false, false },
		{"MessageArguments", false, false, false },
		{"PerceivedSeverity", false, false, false },
		{"ProbableCause", false, false, false },
		{"ProbableCauseDescription", false, false, false },
		{"RecommendedActions", false, false, false },
		{"ErrorSource", false, false, false },
		{"ErrorSourceFormat", false, false, false },
		{"OtherErrorSourceFormat", false, false, false },
		{"CIMStatusCode", false, false, false },
		{"CIMStatusCodeDescription", false, false, false },
	};
	// class fields
	const unsigned short CIM_Error::ErrorType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorType"), ret);
		return ret;
	}
	void CIM_Error::ErrorType(const unsigned short value)
	{
		SetOrAddField("ErrorType", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::ErrorTypeExists() const
	{
		return ContainsField("ErrorType");
	}
	void CIM_Error::RemoveErrorType()
	{
		RemoveField("ErrorType");
	}

	const string CIM_Error::OtherErrorType() const
	{
		return GetField("OtherErrorType")[0];
	}
	void CIM_Error::OtherErrorType(const string &value)
	{
		SetOrAddField("OtherErrorType", value);
	}
	bool CIM_Error::OtherErrorTypeExists() const
	{
		return ContainsField("OtherErrorType");
	}
	void CIM_Error::RemoveOtherErrorType()
	{
		RemoveField("OtherErrorType");
	}

	const string CIM_Error::OwningEntity() const
	{
		return GetField("OwningEntity")[0];
	}
	void CIM_Error::OwningEntity(const string &value)
	{
		SetOrAddField("OwningEntity", value);
	}
	bool CIM_Error::OwningEntityExists() const
	{
		return ContainsField("OwningEntity");
	}
	void CIM_Error::RemoveOwningEntity()
	{
		RemoveField("OwningEntity");
	}

	const string CIM_Error::MessageID() const
	{
		return GetField("MessageID")[0];
	}
	void CIM_Error::MessageID(const string &value)
	{
		SetOrAddField("MessageID", value);
	}
	bool CIM_Error::MessageIDExists() const
	{
		return ContainsField("MessageID");
	}
	void CIM_Error::RemoveMessageID()
	{
		RemoveField("MessageID");
	}

	const string CIM_Error::Message() const
	{
		return GetField("Message")[0];
	}
	void CIM_Error::Message(const string &value)
	{
		SetOrAddField("Message", value);
	}
	bool CIM_Error::MessageExists() const
	{
		return ContainsField("Message");
	}
	void CIM_Error::RemoveMessage()
	{
		RemoveField("Message");
	}

	const vector<string> CIM_Error::MessageArguments() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("MessageArguments"), ret);
		return ret;
	}
	void CIM_Error::MessageArguments(const vector<string> &value)
	{
		SetOrAddField("MessageArguments", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::MessageArgumentsExists() const
	{
		return ContainsField("MessageArguments");
	}
	void CIM_Error::RemoveMessageArguments()
	{
		RemoveField("MessageArguments");
	}

	const unsigned short CIM_Error::PerceivedSeverity() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("PerceivedSeverity"), ret);
		return ret;
	}
	void CIM_Error::PerceivedSeverity(const unsigned short value)
	{
		SetOrAddField("PerceivedSeverity", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::PerceivedSeverityExists() const
	{
		return ContainsField("PerceivedSeverity");
	}
	void CIM_Error::RemovePerceivedSeverity()
	{
		RemoveField("PerceivedSeverity");
	}

	const unsigned short CIM_Error::ProbableCause() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ProbableCause"), ret);
		return ret;
	}
	void CIM_Error::ProbableCause(const unsigned short value)
	{
		SetOrAddField("ProbableCause", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::ProbableCauseExists() const
	{
		return ContainsField("ProbableCause");
	}
	void CIM_Error::RemoveProbableCause()
	{
		RemoveField("ProbableCause");
	}

	const string CIM_Error::ProbableCauseDescription() const
	{
		return GetField("ProbableCauseDescription")[0];
	}
	void CIM_Error::ProbableCauseDescription(const string &value)
	{
		SetOrAddField("ProbableCauseDescription", value);
	}
	bool CIM_Error::ProbableCauseDescriptionExists() const
	{
		return ContainsField("ProbableCauseDescription");
	}
	void CIM_Error::RemoveProbableCauseDescription()
	{
		RemoveField("ProbableCauseDescription");
	}

	const vector<string> CIM_Error::RecommendedActions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("RecommendedActions"), ret);
		return ret;
	}
	void CIM_Error::RecommendedActions(const vector<string> &value)
	{
		SetOrAddField("RecommendedActions", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::RecommendedActionsExists() const
	{
		return ContainsField("RecommendedActions");
	}
	void CIM_Error::RemoveRecommendedActions()
	{
		RemoveField("RecommendedActions");
	}

	const string CIM_Error::ErrorSource() const
	{
		return GetField("ErrorSource")[0];
	}
	void CIM_Error::ErrorSource(const string &value)
	{
		SetOrAddField("ErrorSource", value);
	}
	bool CIM_Error::ErrorSourceExists() const
	{
		return ContainsField("ErrorSource");
	}
	void CIM_Error::RemoveErrorSource()
	{
		RemoveField("ErrorSource");
	}

	const unsigned short CIM_Error::ErrorSourceFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ErrorSourceFormat"), ret);
		return ret;
	}
	void CIM_Error::ErrorSourceFormat(const unsigned short value)
	{
		SetOrAddField("ErrorSourceFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::ErrorSourceFormatExists() const
	{
		return ContainsField("ErrorSourceFormat");
	}
	void CIM_Error::RemoveErrorSourceFormat()
	{
		RemoveField("ErrorSourceFormat");
	}

	const string CIM_Error::OtherErrorSourceFormat() const
	{
		return GetField("OtherErrorSourceFormat")[0];
	}
	void CIM_Error::OtherErrorSourceFormat(const string &value)
	{
		SetOrAddField("OtherErrorSourceFormat", value);
	}
	bool CIM_Error::OtherErrorSourceFormatExists() const
	{
		return ContainsField("OtherErrorSourceFormat");
	}
	void CIM_Error::RemoveOtherErrorSourceFormat()
	{
		RemoveField("OtherErrorSourceFormat");
	}

	const unsigned int CIM_Error::CIMStatusCode() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("CIMStatusCode"), ret);
		return ret;
	}
	void CIM_Error::CIMStatusCode(const unsigned int value)
	{
		SetOrAddField("CIMStatusCode", TypeConverter::TypeToString(value));
	}
	bool CIM_Error::CIMStatusCodeExists() const
	{
		return ContainsField("CIMStatusCode");
	}
	void CIM_Error::RemoveCIMStatusCode()
	{
		RemoveField("CIMStatusCode");
	}

	const string CIM_Error::CIMStatusCodeDescription() const
	{
		return GetField("CIMStatusCodeDescription")[0];
	}
	void CIM_Error::CIMStatusCodeDescription(const string &value)
	{
		SetOrAddField("CIMStatusCodeDescription", value);
	}
	bool CIM_Error::CIMStatusCodeDescriptionExists() const
	{
		return ContainsField("CIMStatusCodeDescription");
	}
	void CIM_Error::RemoveCIMStatusCodeDescription()
	{
		RemoveField("CIMStatusCodeDescription");
	}

	CimBase *CIM_Error::CreateFromCimObject(const CimObject &object)
	{
		CIM_Error *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Error>(object);
		}
		else
		{
			ret = new CIM_Error(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Error> > CIM_Error::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Error>(client, keys);
	}

	void CIM_Error::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Error::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Error::CLASS_NAME = "CIM_Error";
	const string CIM_Error::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Error";
	const string CIM_Error::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Error";
	const string CIM_Error::CLASS_NS_PREFIX = "AEr880";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Error::_classMetaData;
}
}
}
}
