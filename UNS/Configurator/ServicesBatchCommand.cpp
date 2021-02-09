/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2021 Intel Corporation
 */
#include "ServicesBatchCommand.h"
#include "DependancyManager.h"

IServicesManager *ServicesBatchCommand::s_servicesManager = NULL;


/************************************************************************/
/* This function executes the command, on all given services.           */
/* For each service, the function checks if there are dependencies that */
/* were not fulfilled yet, and if there are, it recursively executes the*/
/* command on them. If there are no dependencies, it executes the       */
/* command on the service.                                              */
/************************************************************************/
ServicesBatchCommand::ExecuteCommandResult ServicesBatchCommand::Execute(const ServiceNamesList &services) const
{
	ExecuteCommandResult ret = NOTHING_TO_DO;

	NamesList serviceNames;
	services.GetNames(serviceNames);
	NamesList::const_iterator endIt = serviceNames.end();
	for(NamesList::const_iterator it = serviceNames.begin(); it != endIt; ++it)
	{
		const ACE_TString &service = *it;
		//if service is already in requested state - return true
		if (OperationAlreadyDone(service))
			continue;

		if (ret != FAILURE)
		{
			ret = SUCCESS;
		}

		// if there are dependencies - call the command on them. The configurator will call
		// "execute" again when the services that should have been completing the command before,
		// have finished, and then execute will be called again.
		if (!theAsyncActivationManager::instance()->ReadyToOperation(service, GetOperation()))
		{
			ServiceNamesList dependencies;
			GetPrerequisites(service, dependencies);

			if (Execute(dependencies) == FAILURE)
				ret = FAILURE;
		}
		// If all dependencies are no-op no one calls the configurator so re-check to continue execution
		if (theAsyncActivationManager::instance()->ReadyToOperation(service, GetOperation()))
		{
			//no dependencies - let's do the requested operation!
			theLoadedServices::instance()->LockService(service);
			if(!DoOperation(service))
			{
				theLoadedServices::instance()->UnlockService(service);
				ret = FAILURE;
			}
		}
	}

	return ret;
}

bool ServicesBatchCommand::OperationAlreadyDone(const ACE_TString &service) const
{
	//if the service is already in transition from state to state
	//or the specific state already reached
	return theLoadedServices::instance()->IsLocked(service) ||
		   DoneCriteria(service);
}

void ServicesBatchCommand::fillDependencies(const ACE_TString &service, ServiceNamesList &dependencies, bool serviceDependsOn) const
{
	NamesList dependenciesNames;
	theDependencyManager::instance()->GetPrerequisites(service, dependenciesNames, serviceDependsOn);
	dependencies = ServiceNamesList(dependenciesNames);	
}
