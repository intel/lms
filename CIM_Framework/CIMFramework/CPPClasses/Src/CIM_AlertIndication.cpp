//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AlertIndication.cpp
//
//  Contents:   A concrete superclass for CIM Alert notifications. An AlertIndication is a specialized type of CIM_Indication that contains information about the severity, cause, recommended actions and other data of a real world event. This event and its data may or may not be modeled in the CIM class hierarchy.
//
//              This file was automatically generated from CIM_AlertIndication.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#include "CIM_AlertIndication.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_AlertIndication::_metadata[] = {
		{"Description", false, false, false },
		{"AlertingManagedElement", false, false, false },
		{"AlertingElementFormat", false, false, false },
		{"OtherAlertingElementFormat", false, false, false },
		{"AlertType", false, true, false },
		{"OtherAlertType", false, false, false },
		{"PerceivedSeverity", false, true, false },
		{"ProbableCause", false, true, false },
		{"ProbableCauseDescription", false, false, false },
		{"Trending", false, false, false },
		{"RecommendedActions", false, false, false },
		{"EventID", false, false, false },
		{"EventTime", false, false, false },
		{"SystemCreationClassName", false, false, false },
		{"SystemName", false, false, false },
		{"ProviderName", false, false, false },
		{"Message", false, false, false },
		{"MessageArguments", false, false, false },
		{"MessageID", false, false, false },
		{"OwningEntity", false, false, false },
	};
	// class fields
	const string CIM_AlertIndication::Description() const
	{
		return GetField("Description")[0];
	}
	void CIM_AlertIndication::Description(const string &value)
	{
		SetOrAddField("Description", value);
	}
	bool CIM_AlertIndication::DescriptionExists() const
	{
		return ContainsField("Description");
	}
	void CIM_AlertIndication::RemoveDescription()
	{
		RemoveField("Description");
	}

	const string CIM_AlertIndication::AlertingManagedElement() const
	{
		return GetField("AlertingManagedElement")[0];
	}
	void CIM_AlertIndication::AlertingManagedElement(const string &value)
	{
		SetOrAddField("AlertingManagedElement", value);
	}
	bool CIM_AlertIndication::AlertingManagedElementExists() const
	{
		return ContainsField("AlertingManagedElement");
	}
	void CIM_AlertIndication::RemoveAlertingManagedElement()
	{
		RemoveField("AlertingManagedElement");
	}

	const unsigned short CIM_AlertIndication::AlertingElementFormat() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AlertingElementFormat"), ret);
		return ret;
	}
	void CIM_AlertIndication::AlertingElementFormat(const unsigned short value)
	{
		SetOrAddField("AlertingElementFormat", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::AlertingElementFormatExists() const
	{
		return ContainsField("AlertingElementFormat");
	}
	void CIM_AlertIndication::RemoveAlertingElementFormat()
	{
		RemoveField("AlertingElementFormat");
	}

	const string CIM_AlertIndication::OtherAlertingElementFormat() const
	{
		return GetField("OtherAlertingElementFormat")[0];
	}
	void CIM_AlertIndication::OtherAlertingElementFormat(const string &value)
	{
		SetOrAddField("OtherAlertingElementFormat", value);
	}
	bool CIM_AlertIndication::OtherAlertingElementFormatExists() const
	{
		return ContainsField("OtherAlertingElementFormat");
	}
	void CIM_AlertIndication::RemoveOtherAlertingElementFormat()
	{
		RemoveField("OtherAlertingElementFormat");
	}

	const unsigned short CIM_AlertIndication::AlertType() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("AlertType"), ret);
		return ret;
	}
	void CIM_AlertIndication::AlertType(const unsigned short value)
	{
		SetOrAddField("AlertType", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::AlertTypeExists() const
	{
		return ContainsField("AlertType");
	}
	void CIM_AlertIndication::RemoveAlertType()
	{
		RemoveField("AlertType");
	}

	const string CIM_AlertIndication::OtherAlertType() const
	{
		return GetField("OtherAlertType")[0];
	}
	void CIM_AlertIndication::OtherAlertType(const string &value)
	{
		SetOrAddField("OtherAlertType", value);
	}
	bool CIM_AlertIndication::OtherAlertTypeExists() const
	{
		return ContainsField("OtherAlertType");
	}
	void CIM_AlertIndication::RemoveOtherAlertType()
	{
		RemoveField("OtherAlertType");
	}

	const unsigned short CIM_AlertIndication::ProbableCause() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ProbableCause"), ret);
		return ret;
	}
	void CIM_AlertIndication::ProbableCause(const unsigned short value)
	{
		SetOrAddField("ProbableCause", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::ProbableCauseExists() const
	{
		return ContainsField("ProbableCause");
	}
	void CIM_AlertIndication::RemoveProbableCause()
	{
		RemoveField("ProbableCause");
	}

	const string CIM_AlertIndication::ProbableCauseDescription() const
	{
		return GetField("ProbableCauseDescription")[0];
	}
	void CIM_AlertIndication::ProbableCauseDescription(const string &value)
	{
		SetOrAddField("ProbableCauseDescription", value);
	}
	bool CIM_AlertIndication::ProbableCauseDescriptionExists() const
	{
		return ContainsField("ProbableCauseDescription");
	}
	void CIM_AlertIndication::RemoveProbableCauseDescription()
	{
		RemoveField("ProbableCauseDescription");
	}

	const unsigned short CIM_AlertIndication::Trending() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("Trending"), ret);
		return ret;
	}
	void CIM_AlertIndication::Trending(const unsigned short value)
	{
		SetOrAddField("Trending", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::TrendingExists() const
	{
		return ContainsField("Trending");
	}
	void CIM_AlertIndication::RemoveTrending()
	{
		RemoveField("Trending");
	}

	const vector<string> CIM_AlertIndication::RecommendedActions() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("RecommendedActions"), ret);
		return ret;
	}
	void CIM_AlertIndication::RecommendedActions(const vector<string> &value)
	{
		SetOrAddField("RecommendedActions", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::RecommendedActionsExists() const
	{
		return ContainsField("RecommendedActions");
	}
	void CIM_AlertIndication::RemoveRecommendedActions()
	{
		RemoveField("RecommendedActions");
	}

	const string CIM_AlertIndication::EventID() const
	{
		return GetField("EventID")[0];
	}
	void CIM_AlertIndication::EventID(const string &value)
	{
		SetOrAddField("EventID", value);
	}
	bool CIM_AlertIndication::EventIDExists() const
	{
		return ContainsField("EventID");
	}
	void CIM_AlertIndication::RemoveEventID()
	{
		RemoveField("EventID");
	}

	const CimDateTime CIM_AlertIndication::EventTime() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("EventTime"), ret);
		return ret;
	}
	void CIM_AlertIndication::EventTime(const CimDateTime &value)
	{
		SetOrAddField("EventTime", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::EventTimeExists() const
	{
		return ContainsField("EventTime");
	}
	void CIM_AlertIndication::RemoveEventTime()
	{
		RemoveField("EventTime");
	}

	const string CIM_AlertIndication::SystemCreationClassName() const
	{
		return GetField("SystemCreationClassName")[0];
	}
	void CIM_AlertIndication::SystemCreationClassName(const string &value)
	{
		SetOrAddField("SystemCreationClassName", value);
	}
	bool CIM_AlertIndication::SystemCreationClassNameExists() const
	{
		return ContainsField("SystemCreationClassName");
	}
	void CIM_AlertIndication::RemoveSystemCreationClassName()
	{
		RemoveField("SystemCreationClassName");
	}

	const string CIM_AlertIndication::SystemName() const
	{
		return GetField("SystemName")[0];
	}
	void CIM_AlertIndication::SystemName(const string &value)
	{
		SetOrAddField("SystemName", value);
	}
	bool CIM_AlertIndication::SystemNameExists() const
	{
		return ContainsField("SystemName");
	}
	void CIM_AlertIndication::RemoveSystemName()
	{
		RemoveField("SystemName");
	}

	const string CIM_AlertIndication::ProviderName() const
	{
		return GetField("ProviderName")[0];
	}
	void CIM_AlertIndication::ProviderName(const string &value)
	{
		SetOrAddField("ProviderName", value);
	}
	bool CIM_AlertIndication::ProviderNameExists() const
	{
		return ContainsField("ProviderName");
	}
	void CIM_AlertIndication::RemoveProviderName()
	{
		RemoveField("ProviderName");
	}

	const string CIM_AlertIndication::Message() const
	{
		return GetField("Message")[0];
	}
	void CIM_AlertIndication::Message(const string &value)
	{
		SetOrAddField("Message", value);
	}
	bool CIM_AlertIndication::MessageExists() const
	{
		return ContainsField("Message");
	}
	void CIM_AlertIndication::RemoveMessage()
	{
		RemoveField("Message");
	}

	const vector<string> CIM_AlertIndication::MessageArguments() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("MessageArguments"), ret);
		return ret;
	}
	void CIM_AlertIndication::MessageArguments(const vector<string> &value)
	{
		SetOrAddField("MessageArguments", TypeConverter::TypeToString(value));
	}
	bool CIM_AlertIndication::MessageArgumentsExists() const
	{
		return ContainsField("MessageArguments");
	}
	void CIM_AlertIndication::RemoveMessageArguments()
	{
		RemoveField("MessageArguments");
	}

	const string CIM_AlertIndication::MessageID() const
	{
		return GetField("MessageID")[0];
	}
	void CIM_AlertIndication::MessageID(const string &value)
	{
		SetOrAddField("MessageID", value);
	}
	bool CIM_AlertIndication::MessageIDExists() const
	{
		return ContainsField("MessageID");
	}
	void CIM_AlertIndication::RemoveMessageID()
	{
		RemoveField("MessageID");
	}

	const string CIM_AlertIndication::OwningEntity() const
	{
		return GetField("OwningEntity")[0];
	}
	void CIM_AlertIndication::OwningEntity(const string &value)
	{
		SetOrAddField("OwningEntity", value);
	}
	bool CIM_AlertIndication::OwningEntityExists() const
	{
		return ContainsField("OwningEntity");
	}
	void CIM_AlertIndication::RemoveOwningEntity()
	{
		RemoveField("OwningEntity");
	}

	CimBase *CIM_AlertIndication::CreateFromCimObject(const CimObject &object)
	{
		CIM_AlertIndication *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_AlertIndication>(object);
		}
		else
		{
			ret = new CIM_AlertIndication(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_AlertIndication> > CIM_AlertIndication::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_AlertIndication>(client, keys);
	}

	void CIM_AlertIndication::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_AlertIndication::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_AlertIndication::CLASS_NAME = "CIM_AlertIndication";
	const string CIM_AlertIndication::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AlertIndication";
	const string CIM_AlertIndication::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AlertIndication";
	const string CIM_AlertIndication::CLASS_NS_PREFIX = "AAl952";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_AlertIndication::_classMetaData;
}
}
}
}
