/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
#ifndef __LOADED_SERVICES_H_
#define __LOADED_SERVICES_H_

#include "ConfCommonTypes.h"
#include "ace/Singleton.h"

class LoadedServices { //Note: if multithreading add locking

public:
	void RemoveService(const ACE_TString &serviceName);
	void AddService(const ACE_TString &serviceName, bool isActive = true);
	void SetActive(const ACE_TString &serviceName, bool isActive = true);
	void LockService(const ACE_TString &serviceName );
	void UnlockService(const ACE_TString &serviceName );
	void SetServicesToLoad(const NamesList &servicesToLoad);
	void AddServiceToLoad(const ACE_TString &serviceName);
	void RemoveServiceToLoad(const ACE_TString &serviceName);
	void ClearServicesToLoad();
	void AddServiceToWaitForPfw(const ACE_TString & serviceName);
	void ClearServicesToWaitForPfw();
	
	bool IsActive(const ACE_TString &serviceName) const;
	bool IsLoaded(const ACE_TString &serviceName) const;
	bool IsLocked(const ACE_TString &serviceName) const;
	bool ToBeLoaded(const ACE_TString &serviceName) const;

	void GetAllLoadedServices(NamesList &services);
	void GetAllActiveServices(NamesList &services);
	void GetAllWaitingForPfwServices(NamesList & services);
private:
	//all loaded services
	NamesSet m_loadedServices;
	//all active (not suspended) services
	NamesSet m_activeServices;
	//all locked services (in the middle of action)
	NamesSet m_lockedServices;
	//list of services that supposed to be loaded in this running
	NamesSet m_servicesToLoad;
	//list of services that supposed to be loaded, but are waiting now for Port Forwarding to load before (for their special check to be able to be performed)
	NamesSet m_servicesToWaitForPfw;
};

typedef ACE_Unmanaged_Singleton<LoadedServices, ACE_Mutex> theLoadedServices;

#endif //__LOADED_SERVICES_H_