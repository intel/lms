/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
#ifndef __DEPENDANCY_MANAGER_H_
#define __DEPENDANCY_MANAGER_H_
#include <vector>
#include "ConfCommonTypes.h"
#include "ace/Singleton.h"
#include "ace/Mutex.h"

class DependencyManager {

public:
	DependencyManager(); 

	void ReadDependencies();
	void GetServiceDependecies(const ACE_TString &service, NamesList &names) const;
	void GetDependeciesOf(const ACE_TString &service, NamesList &names) const;
	void GetPrerequisites(const ACE_TString &service, NamesList &names, bool serviceDependsOn = true) const;
	void FillAbsoluteDependencies(NamesList &services);
	void FillAbsoluteDependents(NamesList &services);
	//Add/remove the dependency of dummy subservices (to prevent removing of "last" services)
	void RemoveDummyDependencies(const ACE_TString &service);
	void AddDummyDependencies(const ACE_TString &service);

private:
	void Depends(const ACE_TString &whatService, const ACE_TString &onService);
	void Depends(const NamesList &whatServices, const NamesList &onServices);
	void DependsAbsolutely(const ACE_TString &whatService, const ACE_TString &onService);
	void GetCurrentDependencies(const NamesList &dependencies, NamesList &currentDependencies) const;
	void SetOrderDependencies(unsigned int serviceInd);
	void ReadAbsoluteDependencies();
	void ReadMountOrder();
	void FillAbsoluteRelations(NamesList &services, const DepMap& relationsMap);

	DepMap m_orderDependencies;
	DepMap m_orderDependents;
	DepMap m_absoluteDependencies;
	DepMap m_absoluteDependents;

	std::vector<NamesList> m_mountOrder;
	bool m_alreadyReadDependencies;
	//The dummy subservices to not remove although thet are formally dependent of others 
	NamesList m_dummeyServicesToRemove;
};

typedef ACE_Unmanaged_Singleton<DependencyManager, ACE_Mutex> theDependencyManager;

#endif //__DEPENDANCY_MANAGER_H_