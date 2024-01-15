/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */

#include "global.h"
#include "DependancyManager.h"
#include "servicesNames.h"
#include "LoadedServices.h"

DependencyManager::DependencyManager() : m_alreadyReadDependencies(false)
{ 
	m_dummeyServicesToRemove.push_back(LAST_SERVICE); 
	m_dummeyServicesToRemove.push_back(AMT_ENABLE_LAST_SERVICE);
	m_dummeyServicesToRemove.push_back(WAITING_FOR_PFW_LAST_SERVICE);
}

void DependencyManager::ReadMountOrder()
{
	m_mountOrder.resize(10);
	m_mountOrder[0].push_back(FIRST_SERVICE);
	m_mountOrder[1].push_back(EVENT_MANAGER);
	m_mountOrder[2].push_back(WINLOG_EVENT_HANDLER);
	m_mountOrder[2].push_back(COM_EVENT_HANDLER);
	m_mountOrder[2].push_back(WMI_EVENT_HANDLER);
	m_mountOrder[2].push_back(GMS_DBUSSERVICE);
	m_mountOrder[2].push_back(HISTORY_EVENT_HANDLER);
	m_mountOrder[3].push_back(STATUS_EVENT_HANDLER);
	m_mountOrder[5].push_back(GMS_PORTFORWARDINGSERVICE);
	m_mountOrder[6].push_back(GMS_PARTIALFWUPDATESERVICE);
	m_mountOrder[7].push_back(GMS_SHAREDSTATICIPSERVICE);
	m_mountOrder[7].push_back(GMS_TIMESYNCSERVICE);
	m_mountOrder[7].push_back(GMS_WIFIPROFILESYNCSERVICE);
	m_mountOrder[7].push_back(GMS_IPREFRESHSERVICE);
	m_mountOrder[7].push_back(POWER_OPERATIONS_SERVICE);
	m_mountOrder[7].push_back(GMS_WATCHDOGSERVICE);
	m_mountOrder[8].push_back(AMT_ENABLE_LAST_SERVICE);
	m_mountOrder[8].push_back(WAITING_FOR_PFW_LAST_SERVICE);
	m_mountOrder[9].push_back(LAST_SERVICE);
}

void DependencyManager::ReadAbsoluteDependencies()
{
	DependsAbsolutely(WINLOG_EVENT_HANDLER, EVENT_MANAGER);
	DependsAbsolutely(COM_EVENT_HANDLER, EVENT_MANAGER);
	DependsAbsolutely(WMI_EVENT_HANDLER, EVENT_MANAGER);
	DependsAbsolutely(GMS_DBUSSERVICE, EVENT_MANAGER);
	DependsAbsolutely(HISTORY_EVENT_HANDLER, EVENT_MANAGER);
	DependsAbsolutely(STATUS_EVENT_HANDLER, EVENT_MANAGER);

	DependsAbsolutely(GMS_TIMESYNCSERVICE, GMS_PORTFORWARDINGSERVICE);
	DependsAbsolutely(GMS_WIFIPROFILESYNCSERVICE, GMS_PORTFORWARDINGSERVICE);
	DependsAbsolutely(GMS_SHAREDSTATICIPSERVICE, GMS_PORTFORWARDINGSERVICE);
	DependsAbsolutely(GMS_PARTIALFWUPDATESERVICE, GMS_PORTFORWARDINGSERVICE);
	DependsAbsolutely(POWER_OPERATIONS_SERVICE, GMS_PORTFORWARDINGSERVICE);
}

void DependencyManager::ReadDependencies()
{
	if (m_alreadyReadDependencies)
		return;

	ReadAbsoluteDependencies();
	
	ReadMountOrder();
	for(unsigned int i=1; i< m_mountOrder.size(); i++)
	{
		SetOrderDependencies(i);
	}

	m_alreadyReadDependencies = true;
}

void DependencyManager::Depends(const ACE_TString &whatService, const ACE_TString &onService)
{
	m_orderDependencies[whatService].push_back(onService); 
	m_orderDependents[onService].push_back(whatService);
}

void DependencyManager::Depends(const NamesList &whatServices, const NamesList &onServices)
{
	NamesList::const_iterator whatSvcEndIt = whatServices.end();
	for(NamesList::const_iterator whatSvcIt = whatServices.begin(); whatSvcIt != whatSvcEndIt; ++whatSvcIt)
	{
		NamesList::const_iterator onSvcEndIt = onServices.end();
		for(NamesList::const_iterator onSvcIt = onServices.begin(); onSvcIt != onSvcEndIt; ++onSvcIt)
			Depends(*whatSvcIt, *onSvcIt);
	}
}

void DependencyManager::DependsAbsolutely(const ACE_TString &whatService, const ACE_TString &onService)
{
	m_absoluteDependencies[whatService].push_back(onService);
	m_absoluteDependents[onService].push_back(whatService);
}

void DependencyManager::GetCurrentDependencies(const NamesList &dependencies, NamesList &currentDependencies) const
{
	NamesList::const_iterator endIt  = dependencies.end();
	for(NamesList::const_iterator it = dependencies.begin(); it != endIt; ++it)
	{
		if(theLoadedServices::instance()->ToBeLoaded(*it))
			currentDependencies.push_back(*it);
	}
}

void DependencyManager::SetOrderDependencies(unsigned int startInd)
{
	if(startInd >= m_mountOrder.size())
		return;
	
	for(unsigned int i=0; i < startInd; ++i)
		Depends(m_mountOrder[startInd], m_mountOrder[i]);
}

void DependencyManager::GetServiceDependecies(const ACE_TString &service, NamesList &names) const
{
	if (m_orderDependencies.empty())
		return;

	DepMap::const_iterator it;
	if ((it = m_orderDependencies.find(service)) == m_orderDependencies.end())
		return;

	GetCurrentDependencies(it->second, names);
}

void DependencyManager::GetDependeciesOf(const ACE_TString &service, NamesList &names) const
{
	if (m_orderDependents.empty())
		return;

	DepMap::const_iterator it;
	if ((it = m_orderDependents.find(service)) == m_orderDependents.end())
		return;

	GetCurrentDependencies(it->second, names);
}

//This functions fills the names list with: 
//1. All services that "service" depends on (if serviceDependsOn = true),
//2. All the services that depend on "service" (if serviceDependsOn = false).
void DependencyManager::GetPrerequisites(const ACE_TString &service, NamesList &names, bool serviceDependsOn) const
{
	serviceDependsOn?
		GetServiceDependecies(service,names): //fills "names" with the services that the service depends on
		GetDependeciesOf(service,names); //fills "names" with all services that depend on this service
}

void DependencyManager::FillAbsoluteDependencies(NamesList &services)
{
	FillAbsoluteRelations(services, m_absoluteDependencies);
}

void DependencyManager::FillAbsoluteRelations(NamesList &services, const DepMap& relationsMap)
{
	if (relationsMap.empty())
		return;

	NamesSet servicesSet;
	servicesSet.insert(services.begin(), services.end());

	NamesSet::const_iterator srvEndIt  = servicesSet.end();
	for(NamesSet::const_iterator srvIt = servicesSet.begin(); srvIt != srvEndIt; ++srvIt)
	{
		
		DepMap::const_iterator it;
		if ((it = relationsMap.find(*srvIt)) != relationsMap.end())
		{
			NamesList relations = it->second;
			NamesList::const_iterator endRelIt = relations.end();
			for(NamesList::const_iterator relIt = relations.begin(); relIt != endRelIt; ++relIt)
			{
				servicesSet.insert(*relIt);
			}
		}
	}

	services.assign(servicesSet.begin(), servicesSet.end());
}

//Remove the dependency of dummy subservices (to prevent removing of "last" services)
void DependencyManager::RemoveDummyDependencies(const ACE_TString &service)
{
	if (m_orderDependents.empty())
		return;

	DepMap::iterator it;
	if ((it = m_orderDependents.find(service)) == m_orderDependents.end())
		return;

	UNS_DEBUG(L"DependencyManager::RemoveDummyDependencies for %s\n", service.c_str());

	for (NamesList::const_iterator itr = m_dummeyServicesToRemove.begin(); itr!= m_dummeyServicesToRemove.end(); ++itr)
	{
		UNS_DEBUG(L"DependencyManager::RemoveDummyDependencies removing %s\n", itr->c_str());
		it->second.remove(*itr);
	}
}

//For re-adding the dependency of dummy subservices after the "toggle service" task is completed
void DependencyManager::AddDummyDependencies(const ACE_TString &service)
{
	if (m_orderDependents.empty())
		return;

	DepMap::iterator it;
	if ((it = m_orderDependents.find(service)) == m_orderDependents.end())
		return;

	UNS_DEBUG(L"DependencyManager::ReturnDummyDependencies for %s\n", service.c_str());

	for (NamesList::const_iterator itr = m_dummeyServicesToRemove.begin(); itr!= m_dummeyServicesToRemove.end(); ++itr)
	{
		UNS_DEBUG(L"DependencyManager::ReturnDummyDependencies adding %s\n", itr->c_str());
		it->second.push_back(*itr);
	}
}