/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2015 Intel Corporation
 */
#ifndef __SERVICES_BATCH_COMMAND_H_
#define __SERVICES_BATCH_COMMAND_H_

#include "ServiceNamesList.h"
#include "IServicesManager.h"
#include "AsyncActivationManager.h"
#include "LoadedServices.h"

class ServicesBatchCommand
{
public:
	virtual ~ServicesBatchCommand() {}
	
	static void SetServicesManager(IServicesManager *servicesManager)
		{s_servicesManager = servicesManager;}

	bool Execute(const ServiceNamesList &services) const;

protected:

	virtual bool DoOperation(const ACE_TString &service) const = 0;
	virtual bool DoneCriteria(const ACE_TString &service) const = 0;
	virtual AsyncActivationManager::OpType GetOperation() const = 0;
	virtual void GetPrerequisites(const ACE_TString &service, ServiceNamesList &dependencies ) const = 0;
	
	//utilities for derived classes
	void fillDependencies(const ACE_TString &service, ServiceNamesList &dependencies, bool serviceDependsOn = true) const;
	bool OperationAlreadyDone(const ACE_TString &service) const;

	static IServicesManager *s_servicesManager;
};

class ServicesBatchStartCommand :
	public ServicesBatchCommand
{
public:
	ServicesBatchStartCommand(void){}
private:
	virtual bool DoOperation(const ACE_TString &service) const
		{return s_servicesManager->StartAceService(service);}
	virtual bool DoneCriteria(const ACE_TString &service) const
		{return theLoadedServices::instance()->IsLoaded(service);}
	virtual AsyncActivationManager::OpType GetOperation() const 
		{return  AsyncActivationManager::OP_LOAD;}
	virtual void GetPrerequisites(const ACE_TString &service, ServiceNamesList &dependencies ) const
		{fillDependencies(service, dependencies);}
};

class ServicesBatchStopCommand :
	public ServicesBatchCommand
{
public:
	ServicesBatchStopCommand(void){}
private:
	virtual bool DoOperation(const ACE_TString &service) const
		{return s_servicesManager->StopAceService(service);}
	virtual bool DoneCriteria(const ACE_TString &service) const
		{return !theLoadedServices::instance()->IsLoaded(service);}
	virtual AsyncActivationManager::OpType GetOperation() const 
		{return  AsyncActivationManager::OP_UNLOAD;}
	virtual void GetPrerequisites(const ACE_TString &service, ServiceNamesList &dependencies ) const
		{fillDependencies(service, dependencies, false);}
};

class ServicesBatchResumeCommand :
	public ServicesBatchCommand
{
public:
	ServicesBatchResumeCommand(void){}
private:
	virtual bool DoOperation(const ACE_TString &service) const
		{return s_servicesManager->ResumeAceService(service);}
	virtual bool DoneCriteria(const ACE_TString &service) const
		{return theLoadedServices::instance()->IsLoaded(service) &&
			    theLoadedServices::instance()->IsActive(service);}	
	virtual AsyncActivationManager::OpType GetOperation() const 
		{return  AsyncActivationManager::OP_RESUME;}
	virtual void GetPrerequisites(const ACE_TString &service, ServiceNamesList &dependencies ) const
		{fillDependencies(service, dependencies);}
};

class ServicesBatchSuspendCommand :
	public ServicesBatchCommand
{
public:
	ServicesBatchSuspendCommand(void){}
private:
	virtual bool DoOperation(const ACE_TString &service) const
		{return s_servicesManager->SuspendAceService(service);}
	virtual bool DoneCriteria(const ACE_TString &service) const
		{return theLoadedServices::instance()->IsLoaded(service) &&
			    !theLoadedServices::instance()->IsActive(service);}	
	virtual AsyncActivationManager::OpType GetOperation() const
		{return  AsyncActivationManager::OP_SUSPEND;}
	virtual void GetPrerequisites(const ACE_TString &service, ServiceNamesList &dependencies ) const
		{fillDependencies(service, dependencies, false);}
};

#endif //__SERVICES_BATCH_COMMAND_H_