/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */

#include "global.h"
#include "AsyncActivationManager.h"
#include "DependancyManager.h"
#include "LoadedServices.h"

AsyncActivationManager::AsyncActivationManager(int loadTimeout, int unloadTimeout):
m_loadTimeout(loadTimeout),
m_unloadTimeout(unloadTimeout)
{
}

void AsyncActivationManager::AddToWaiting(const ACE_TString &service, NamesSet &waitSet, int timeout) 
{
	if (waitSet.find(service) != waitSet.end())
		return;

	waitSet.insert(service);
	//todo set timeout
}

void AsyncActivationManager::RemoveWaiting(NamesList &services, NamesSet &waitSet)
{
	for (NamesList::iterator it = services.begin(); it != services.end(); ++it)
	{
		waitSet.erase(*it);
		// todo remove timeout
	}
}

bool AsyncActivationManager::RefreshOnLoad(ServiceNamesList &services)
{
	return RefreshOnOperation(services, OpType::OP_LOAD);
}

bool AsyncActivationManager::RefreshOnUnload(ServiceNamesList &services)
{
	return RefreshOnOperation(services, OpType::OP_UNLOAD);
}

bool AsyncActivationManager::RefreshOnSuspend( ServiceNamesList &services )
{
	return RefreshOnOperation(services, OpType::OP_SUSPEND);
}

bool AsyncActivationManager::RefreshOnResume( ServiceNamesList &services )
{
	return RefreshOnOperation(services, OpType::OP_RESUME);
}

bool AsyncActivationManager::RefreshOnOperation( ServiceNamesList &services, OpType operation)
{
	bool ret = false;

	NamesSet &waiting = GetWaiting(operation);

	if (waiting.empty())
		return ret;

	UNS_DEBUG(L"AsyncActivationManager: refreshing on operation %d, waiting %d\n", operation, waiting.size());

	NamesList toErase;

	NamesSet::iterator endIt = waiting.end();
	for(NamesSet::iterator it = waiting.begin(); it != endIt; ++it)
	{
		const ACE_TString &service = *it;
		if (!ReadyToOperation(service, operation, false))
			continue;

		ret = true;
		services.AddName(service);
		toErase.push_back(service);
	}

	RemoveWaiting(toErase, waiting);
	return ret;
}

bool AsyncActivationManager::ReadyToOperation(const ACE_TString &service, OpType operation, bool addTolist)
{
	LoadedServices* loadedServices = theLoadedServices::instance();
	DependencyManager* depMan = theDependencyManager::instance();
	NamesSet &waiting = GetWaiting(operation);
	bool ret = true;	

	NamesList dependencies;

	if ((operation == OpType::OP_LOAD) || (operation == OpType::OP_RESUME))
		depMan->GetServiceDependecies(service, dependencies);
	else
		depMan->GetDependeciesOf(service, dependencies);


	NamesList::iterator endIt = dependencies.end();
	bool isReady = true;

	for(NamesList::iterator it = dependencies.begin(); it != endIt; ++it)
	{
		ACE_TString &dep = *it;
		switch(operation)
		{
		case OpType::OP_LOAD:
			isReady &= loadedServices->IsLoaded(dep);
			break;
		case OpType::OP_UNLOAD:
			isReady &= !loadedServices->IsLoaded(dep);
			break;
		case OpType::OP_RESUME:
			isReady &= loadedServices->IsActive(dep);
			break;
		case OpType::OP_SUSPEND:
			isReady &= !loadedServices->IsActive(dep);
			break;
		}
		if (!isReady)
		{
			ret = false;
			break;
		}
	}

	if (addTolist && (ret == false))
	{
		AddToWaiting(service, waiting, m_loadTimeout);
	}

	return ret;
}

NamesSet& AsyncActivationManager::GetWaiting(OpType operation)
{
	return (operation == OpType::OP_LOAD) ? m_waitForLoad :
		(operation == OpType::OP_UNLOAD) ? m_waitForUnload :
		(operation == OpType::OP_SUSPEND) ? m_waitForSuspend :
		m_waitForResume;
}
