//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IndicationService.cpp
//
//  Contents:   An IndicationService is a Service of the CIM Object Manager that is responsible for delivering indications to Indication Handlers.
//
//              This file was automatically generated from CIM_IndicationService.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#include "CIM_IndicationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_IndicationService::_metadata[] = {
		{"FilterCreationEnabled", false, false, false },
		{"DeliveryRetryAttempts", false, false, false },
		{"DeliveryRetryInterval", false, false, false },
		{"SubscriptionRemovalAction", false, false, false },
		{"SubscriptionRemovalTimeInterval", false, false, false },
	};
	// class fields
	const bool CIM_IndicationService::FilterCreationEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("FilterCreationEnabled"), ret);
		return ret;
	}
	void CIM_IndicationService::FilterCreationEnabled(const bool value)
	{
		SetOrAddField("FilterCreationEnabled", TypeConverter::TypeToString(value));
	}
	bool CIM_IndicationService::FilterCreationEnabledExists() const
	{
		return ContainsField("FilterCreationEnabled");
	}
	void CIM_IndicationService::RemoveFilterCreationEnabled()
	{
		RemoveField("FilterCreationEnabled");
	}

	const unsigned short CIM_IndicationService::DeliveryRetryAttempts() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("DeliveryRetryAttempts"), ret);
		return ret;
	}
	void CIM_IndicationService::DeliveryRetryAttempts(const unsigned short value)
	{
		SetOrAddField("DeliveryRetryAttempts", TypeConverter::TypeToString(value));
	}
	bool CIM_IndicationService::DeliveryRetryAttemptsExists() const
	{
		return ContainsField("DeliveryRetryAttempts");
	}
	void CIM_IndicationService::RemoveDeliveryRetryAttempts()
	{
		RemoveField("DeliveryRetryAttempts");
	}

	const unsigned int CIM_IndicationService::DeliveryRetryInterval() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("DeliveryRetryInterval"), ret);
		return ret;
	}
	void CIM_IndicationService::DeliveryRetryInterval(const unsigned int value)
	{
		SetOrAddField("DeliveryRetryInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_IndicationService::DeliveryRetryIntervalExists() const
	{
		return ContainsField("DeliveryRetryInterval");
	}
	void CIM_IndicationService::RemoveDeliveryRetryInterval()
	{
		RemoveField("DeliveryRetryInterval");
	}

	const unsigned short CIM_IndicationService::SubscriptionRemovalAction() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SubscriptionRemovalAction"), ret);
		return ret;
	}
	void CIM_IndicationService::SubscriptionRemovalAction(const unsigned short value)
	{
		SetOrAddField("SubscriptionRemovalAction", TypeConverter::TypeToString(value));
	}
	bool CIM_IndicationService::SubscriptionRemovalActionExists() const
	{
		return ContainsField("SubscriptionRemovalAction");
	}
	void CIM_IndicationService::RemoveSubscriptionRemovalAction()
	{
		RemoveField("SubscriptionRemovalAction");
	}

	const unsigned int CIM_IndicationService::SubscriptionRemovalTimeInterval() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("SubscriptionRemovalTimeInterval"), ret);
		return ret;
	}
	void CIM_IndicationService::SubscriptionRemovalTimeInterval(const unsigned int value)
	{
		SetOrAddField("SubscriptionRemovalTimeInterval", TypeConverter::TypeToString(value));
	}
	bool CIM_IndicationService::SubscriptionRemovalTimeIntervalExists() const
	{
		return ContainsField("SubscriptionRemovalTimeInterval");
	}
	void CIM_IndicationService::RemoveSubscriptionRemovalTimeInterval()
	{
		RemoveField("SubscriptionRemovalTimeInterval");
	}

	CimBase *CIM_IndicationService::CreateFromCimObject(const CimObject &object)
	{
		CIM_IndicationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_IndicationService>(object);
		}
		else
		{
			ret = new CIM_IndicationService(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_IndicationService> > CIM_IndicationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_IndicationService>(client, keys);
	}

	void CIM_IndicationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_IndicationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_IndicationService::CLASS_NAME = "CIM_IndicationService";
	const string CIM_IndicationService::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationService";
	const string CIM_IndicationService::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationService";
	const string CIM_IndicationService::CLASS_NS_PREFIX = "AIn49";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_IndicationService::_classMetaData;
}
}
}
}
