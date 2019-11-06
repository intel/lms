/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "ServicesBatchCommand.h"
#include "DependancyManager.h"

IServicesManager *ServicesBatchCommand::s_servicesManager = NULL;


/************************************************************************/
/* This function executes the command, on all given services.           */
/* For each service, the function checks if there are dependencies that */
/* were not fulfilled yet, and if there are, it recursively executes the*/
/* command on them. If there are no dependencies, it executes the		*/
/* command on the service.												*/ 

/************************************************************************/
bool ServicesBatchCommand::Execute(const ServiceNamesList &services) const
{
	bool ret = true;
	bool operationAlreadyDoneForAllServices = true;

	NamesList serviceNames;
	services.GetNames(serviceNames);
	NamesList::const_iterator endIt = serviceNames.end();
	for(NamesList::const_iterator it = serviceNames.begin(); it != endIt; ++it)
	{
		const ACE_TString &service = *it;
		//if service is already in requested state - return true
		if (OperationAlreadyDone(service))
			continue;

		operationAlreadyDoneForAllServices = false;
		// if there are dependencies - call the command on them. the configurator will call 
		// "execute" again when the services that should have been completing the command before, 
		// have finished, and then execute will be called again.
		if (!theAsyncActivationManager::instance()->ReadyToOperation(service, GetOperation()))
		{
			ServiceNamesList dependencies;
			GetPrerequisites(service, dependencies);
			ret &= Execute(dependencies);
		}
		else //no dependencies - let's do the requested operation!
		{
			theLoadedServices::instance()->LockService(service);
			if(!DoOperation(service))
			{
				theLoadedServices::instance()->UnlockService(service);
				ret = false;
			}
		}
	}

	if (operationAlreadyDoneForAllServices)
	{
		ret = false; // in case that the operation already done for all services, and no operation occured here, we should return false, for TaskCompleted to be called
	}

	return ret;
}

bool ServicesBatchCommand::OperationAlreadyDone(const ACE_TString &service) const
{
	return theLoadedServices::instance()->IsLocked(service) ||	//if the service is already in transition from state to state
		   DoneCriteria(service);								// or the specific state already reached 
}

void ServicesBatchCommand::fillDependencies(const ACE_TString &service, ServiceNamesList &dependencies, bool serviceDependsOn) const
{
	NamesList dependenciesNames;
	theDependencyManager::instance()->GetPrerequisites(service, dependenciesNames, serviceDependsOn);
	dependencies = ServiceNamesList(dependenciesNames);	
}
