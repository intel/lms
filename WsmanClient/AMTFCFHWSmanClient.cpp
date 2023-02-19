/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: AMTFCFHWSmanClient.cpp

--*/

#include "AMTFCFHWSmanClient.h"
#include "CIM_FilterCollection.h"
#include "CimWsman.h"
#include "AMT_RemoteAccessPolicyAppliesToMPS.h"
#include "CIM_FilterCollectionSubscription.h"
#include "AMT_RemoteAccessPolicyRule.h"
#include <algorithm>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

namespace CimTyped = Intel::Manageability::Cim::Typed;

AMTFCFHWSmanClient::AMTFCFHWSmanClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

AMTFCFHWSmanClient::AMTFCFHWSmanClient(unsigned int port, const std::string &User, const std::string &Password) :
	BaseWSManClient(port, User, Password), m_isInit(false)
{
}

AMTFCFHWSmanClient::~AMTFCFHWSmanClient()
{
}

bool AMTFCFHWSmanClient::Init()
{
	if (m_isInit)
	{
		return true;
	}
	m_isInit = false;
	try {
		if (!m_endpoint)
		{
			SetEndpoint();
		
			m_isInit = true;
			
		}
	}
	CATCH_exception("AMTFCFHWSmanClient::Init")
	return m_isInit;
}

bool AMTFCFHWSmanClient::userInitiatedPolicyRuleExists(short* pExist)
{
    if (!Init())
	{
		return false;
	}
	try 
	{
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<CimTyped::AMT_RemoteAccessPolicyRule>> RemoteAccessPolicyRules =
			CimTyped::AMT_RemoteAccessPolicyRule::Enumerate(m_client.get());
		std::vector<std::shared_ptr<CimTyped::AMT_RemoteAccessPolicyRule>>::iterator RemoteAccessPolicyRulesIterator;
		*pExist=false;
		for (RemoteAccessPolicyRulesIterator = RemoteAccessPolicyRules.begin(); 
			 RemoteAccessPolicyRulesIterator != RemoteAccessPolicyRules.end() ; 
			 RemoteAccessPolicyRulesIterator++)
		{	
			CimTyped::AMT_RemoteAccessPolicyRule *currRule = RemoteAccessPolicyRulesIterator->get();
			if (!currRule)
				continue;

			if (currRule->TriggerExists())
			{
				if (currRule->Trigger() == 0)
				{
					*pExist=true;
					WSMAN_DEBUG("userInitiatedPolicyRuleExists:  user initiated policy rule exists\n");
					return true;
				}
			}
		}
		WSMAN_DEBUG("userInitiatedPolicyRuleExists:  user initiated policy rule doesn't exist\n");
		return true;
	}
	CATCH_exception("AMTFCFHWSmanClient::userInitiatedPolicyRuleExists")
	return false;
}


bool AMTFCFHWSmanClient::userInitiatedPolicyRuleForLocalMpsExists(short* pExist)
{
    if (!Init())
	{
		return false;
	}
	try 
	{
		*pExist=false;
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		auto mpsPolicyRules = CimTyped::AMT_RemoteAccessPolicyAppliesToMPS::Enumerate(m_client.get());
		
		for (auto it = mpsPolicyRules.begin(); it != mpsPolicyRules.end(); ++it)
		{	
			auto mpsPolicy = it->get();
			if (!mpsPolicy->MpsTypeExists())
				continue;

			if (mpsPolicy->MpsType() != 2  && mpsPolicy->MpsType() != 1)
				continue;

			CimTyped::AMT_RemoteAccessPolicyRule policyRule(m_client.get());
			policyRule.Get(mpsPolicy->PolicySet());

			if (!policyRule.TriggerExists())
				continue;

			if (policyRule.Trigger() == 0)
			{
				*pExist=true;
				break;
			}
		}
		return true;
	}
	CATCH_exception("AMTFCFHWSmanClient::userInitiatedPolicyRuleForLocalMpsExists")
	return false;
}

bool AMTFCFHWSmanClient::snmpEventSubscriberExists(short* pExist)
{
    if (!Init())
	{
		return false;
	}
	try
	{
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		*pExist = !CimTyped::AMT_SNMPEventSubscriber::Enumerate(m_client.get()).empty();
		WSMAN_DEBUG("snmpEventSubscriberExists: SNMP Event Subscriber %C exists\n", (*pExist) ? "" : "doesn't");
		return true;
	}
	CATCH_exception("AMTFCFHWSmanClient::snmpEventSubscriberExists")
	return false;
}

bool AMTFCFHWSmanClient::CILAFilterCollectionSubscriptionExists(short* pExist)
{
    if (!Init())
	{
		return false;
	}
	try 
	{
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		
		//Check for Filter_All subscription
		CILAFilterCollectionSubscriptionExists(pExist,"Intel(r) AMT:All");
		if (!(*pExist))
		{
			//Check for Filter_Features subscription
			CILAFilterCollectionSubscriptionExists(pExist,"Intel(r) AMT:Features");
			if (!(*pExist))
				WSMAN_DEBUG("CILAFilterCollectionSubscriptionExists: CILA filter collection subscription doesn't exist\n");
		}
		return true;
	}
	CATCH_exception_return("AMTFCFHWSmanClient::CILAFilterCollectionSubscriptionExists")
}

bool AMTFCFHWSmanClient::CILAFilterCollectionSubscriptionExists(short* pExist, const std::string &filterType)
{
	try 
	{
		CimTyped::CIM_FilterCollection filter(m_client.get());
		filter.InstanceID(filterType);
		filter.Get();
		Intel::WSManagement::EnumerateFilter filterEnumerator;
		filterEnumerator.reference =filter.Reference();;
		filterEnumerator.assocType = Intel::WSManagement::EnumerateFilter::AssociationInstance;
		filterEnumerator.resultClass = "CIM_FilterCollectionSubscription";
		std::vector<std::shared_ptr<CimTyped::CimReference> > filterSubscriptions =
			CimTyped::CIM_FilterCollectionSubscription::EnumerateRef(m_client.get(),filterEnumerator);
		if (filterSubscriptions.size()>0)
		{
			*pExist=true;
			WSMAN_DEBUG("CILAFilterCollectionSubscriptionExists: CILA %C subscription exists\n", filterType.c_str());
		}
	}
	catch (std::exception& e)
	{
		const char* reason =  e.what();
		WSMAN_DEBUG("Filter with InstanceID=%C doesn't exist, %C\n", filterType.c_str(), reason);
	}
	return true;
}