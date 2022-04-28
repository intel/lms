/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2022 Intel Corporation
 */
#ifndef __ASYNC_MANAGER_H_
#define __ASYNC_MANAGER_H_

#include "ConfCommonTypes.h"
#include "ServiceNamesList.h"

#include "ace/Singleton.h"

// from service name to timeout (in milliseconds)

class AsyncActivationManager
{
public:
	enum class OpType {OP_LOAD, OP_UNLOAD, OP_RESUME, OP_SUSPEND};

	AsyncActivationManager(int loadTimeout = 10000, int unloadTimeout = 10000);
	// The below ReadyX() functions returns true if the service is ready for X
	// and if not add the service to X-waiting list
	bool ReadyToLoad(const ACE_TString &service);
	bool ReadyToUnload(const ACE_TString &service);
	bool ReadyToSuspend(const ACE_TString &service);
	bool ReadyToResume(const ACE_TString &service);

	bool ReadyToOperation(const ACE_TString &service, OpType operation, bool addTolist = true);
	
	// The below RefreshOnX() functions check if there were other services 
	// that wait for X action. If there are, add them to _services parameter.
	// For simplicity, we check all waiting services regardless on what triggered X.
	// Returns true if the services list was updated, false otherwise.
	bool RefreshOnLoad(ServiceNamesList &services);
	bool RefreshOnUnload(ServiceNamesList &services);
	bool RefreshOnSuspend(ServiceNamesList &services);
	bool RefreshOnResume(ServiceNamesList &services);

private:
	void AddToWaiting(const ACE_TString &service, NamesSet &waitSet, int timeout);
	void RemoveWaiting(NamesList &services, NamesSet &waitSet);
	bool RefreshOnOperation(ServiceNamesList &services, OpType operation);
	NamesSet& GetWaiting(OpType operation);
	NamesSet m_waitForUnload;
	NamesSet m_waitForLoad;
	NamesSet m_waitForSuspend;
	NamesSet m_waitForResume;

	int m_loadTimeout;
	int m_unloadTimeout;
};

typedef ACE_Unmanaged_Singleton<AsyncActivationManager, ACE_Mutex> theAsyncActivationManager;
#endif //__ASYNC_MANAGER_H_