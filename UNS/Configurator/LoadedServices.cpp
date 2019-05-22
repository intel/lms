/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
#include "LoadedServices.h"

void LoadedServices::RemoveService(const ACE_TString & serviceName)
{
	//if (m_loadedServices.find(serviceName) == m_loadedServices.end())
	//	return;
	m_loadedServices.erase(serviceName);
	m_activeServices.erase(serviceName);
	UnlockService(serviceName);
}

void LoadedServices::AddService(const ACE_TString & serviceName, bool isActive)
{
	m_loadedServices.insert(serviceName);
	
	if (isActive)
		m_activeServices.insert(serviceName);
	UnlockService(serviceName);
}

void LoadedServices::SetActive(const ACE_TString& serviceName, bool isActive)
{
	if (isActive)
	{
		if (m_loadedServices.find(serviceName) != m_loadedServices.end()) // So Configurator won't be added to active services on resume
			m_activeServices.insert(serviceName);
	}
	else
	{
		m_activeServices.erase(serviceName);
	}
	UnlockService(serviceName);
}

void LoadedServices::SetServicesToLoad(const NamesList &servicesToLoad)
{
	m_servicesToLoad.clear();
	NamesList::const_iterator endSrvIt = servicesToLoad.end();
	for(NamesList::const_iterator srvIt = servicesToLoad.begin(); srvIt != endSrvIt; ++srvIt)
		m_servicesToLoad.insert(*srvIt);
}

void LoadedServices::AddServiceToLoad(const ACE_TString &serviceName)
{
	m_servicesToLoad.insert(serviceName);
}

void LoadedServices::RemoveServiceToLoad(const ACE_TString &serviceName)
{
	m_servicesToLoad.erase(serviceName);
}

void LoadedServices::ClearServicesToLoad()
{
	m_servicesToLoad.clear();
}

bool LoadedServices::IsActive(const ACE_TString & serviceName) const
{
	return (m_activeServices.find(serviceName) != m_activeServices.end());
}

bool LoadedServices::IsLoaded(const ACE_TString & serviceName) const
{
	return (m_loadedServices.find(serviceName) != m_loadedServices.end());
}

bool LoadedServices::ToBeLoaded(const ACE_TString &serviceName) const
{
	return (m_servicesToLoad.find(serviceName) != m_servicesToLoad.end());
}

void LoadedServices::GetAllLoadedServices(NamesList &services)
{
	services.insert(services.end(), m_loadedServices.begin(), m_loadedServices.end());
}

void LoadedServices::GetAllActiveServices( NamesList &services )
{
	services.insert(services.end(), m_activeServices.begin(), m_activeServices.end());
}

void LoadedServices::LockService( const ACE_TString &serviceName )
{
	m_lockedServices.insert(serviceName);
}

bool LoadedServices::IsLocked( const ACE_TString &serviceName ) const
{
	return  (m_lockedServices.find(serviceName) != m_lockedServices.end());
}

void LoadedServices::UnlockService( const ACE_TString &serviceName )
{
	m_lockedServices.erase(serviceName);
}

void LoadedServices::AddServiceToWaitForPfw(const ACE_TString &serviceName)
{
	m_servicesToWaitForPfw.insert(serviceName);
}

void LoadedServices::ClearServicesToWaitForPfw()
{
	m_servicesToWaitForPfw.clear();
}

void LoadedServices::GetAllWaitingForPfwServices(NamesList &services)
{
	services.insert(services.end(), m_servicesToWaitForPfw.begin(), m_servicesToWaitForPfw.end());
}