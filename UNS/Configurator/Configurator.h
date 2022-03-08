/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2022 Intel Corporation
 */
#ifndef __CONFIGURATOR_H_
#define __CONFIGURATOR_H_
#include "global.h"
#include "IServicesManager.h"
#include "EventManagment.h"
#include "ServicesBatchCommand.h"
#include "GmsSubService.h"

#include "GetPlatformTypeCommand.h"
#include "GetFWCapsCommand.h"
#include "GetFWVersionCommand.h"

#include "ace/Svc_Handler.h"
#include "ace/Containers.h"
#include "ace/Map_Manager.h"
#include "ace/Synch.h"


#include "CONFIGURATOR_export.h"
#include <memory>
#include <queue>
#include <map>

typedef bool CheckLoadFunc();

class CONFIGURATOR_Export Configurator : public GmsSubService, public IServicesManager
{
	public:

	Configurator(): m_SkuAndBrandScanned(false), m_scanningNum(0),
		m_LME_exists(false), m_needToStop(false), m_meiEnabled(true), m_gotMeiEnabled(false), m_inProcessType(MB_SUBSCRIBE_EVENT-1), m_inProcess(false), m_onToggleService(false), deferredResumeTimerId_(-1) {}

	~Configurator(){}

	// ********************* ACE PART ********************************
	virtual int init (int argc, ACE_TCHAR *argv[]);
	virtual int fini (void);
	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"CONF"; }

	//******************* IServicesManager Part *********************
	virtual bool StartAceService(const ACE_TString &serviceName);
	virtual bool StopAceService(const ACE_TString &serviceName);
	virtual bool SuspendAceService(const ACE_TString &serviceName);
	virtual bool ResumeAceService(const ACE_TString &serviceName);

private:
	int handle_timeout(const ACE_Time_Value &current_time,const void *arg);

	void StopAllServices(bool stopMainService = true);
	bool SuspendResumeAllServices(const ServicesBatchCommand &command);
	int SuspendAllServices();
	bool ResumeAllServices();

	//initial configuration
	void ScanConfiguration();

	//ongoing configuration
	int UpdateConfiguration(const ChangeConfiguration *conf);
	void ChangeServiceState(ACE_TString &serviceName, SERVICE_STATUS_TYPE status);
	void FiniAceService(const ACE_TString &serviceName);
	void OnToggleService(const ACE_TString &service, bool val);
	bool CompleteSuspendAceService(const ACE_TString &serviceName);
	void DeviceEventRequested(uint32_t dwEventType, bool wasOnOurGUID);

	//Sequential tasks management
	void ExecuteTask(MessageBlockPtr& mbPtr);
	void TaskCompleted();

	//Configuration data
	bool m_SkuAndBrandScanned;
	int m_scanningNum;
	bool IsLMEExists() const;
	bool m_LME_exists;
	Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE m_platform;
	Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI m_stateData;

	std::map<ACE_TString, CheckLoadFunc*> m_checkLoadMap;
	bool m_needToStop;

	bool MEIEnabled() const;
	bool m_meiEnabled;
	bool m_gotMeiEnabled;

	//Sequential tasks management
	int m_inProcessType;
	bool m_inProcess;
	bool m_onToggleService;
	//The name of the subservice which will be toggled on/off
	ACE_TString m_toggeledService;
	std::queue<MessageBlockPtr> m_nextTasks;

	Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE m_fwVer = { 0 };

	void CancelDeferredResumeTimer();

	long deferredResumeTimerId_;

	void DoOverrideProsetAdapterSwitching() const;
	bool PasswordOnWakeupDisabled() const;
};

#endif /* __CONFIGURATOR_H_ */