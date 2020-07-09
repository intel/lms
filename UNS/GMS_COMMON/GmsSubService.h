/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
#ifndef __SUBSERVICE_H_
#define __SUBSERVICE_H_
#include "global.h"
#include "GmsService.h"
#include <ace/Task.h>
#include <ace/Reactor_Notification_Strategy.h>
#include <ace/Reactor.h>
#include <ace/Service_Config.h>
#include "EventManagment.h"
#include "servicesNames.h"
#include "GMSCommonDllExport.h"
#include "FuncEntryExit.h"

class GMS_COMMON_EXPORT GmsSubService : public ACE_Task<ACE_MT_SYNCH>
{
public:

	GmsSubService() :notifier_(0, NULL, ACE_Event_Handler::WRITE_MASK), m_mainService(nullptr), m_serviceIsClosed(false) {}

	virtual int init(int argc, ACE_TCHAR *argv[]);

	virtual int fini(void);

	virtual int suspend();

	virtual int resume(); // this base implementation must be called by all derived services

	//please don't reimplement
	int handle_output(ACE_HANDLE fd = ACE_INVALID_HANDLE);

	static bool sendAlertIndicationMessage(unsigned short category, unsigned long id,
		const ACE_TString &Message, const ACE_TString &MessageArgument = ACE_TEXT(""));

	virtual const wchar_t *short_name() const = 0;

protected:

	int initSubService(int argc, ACE_TCHAR *argv[]);
	int closeSubService();
	int suspendSubService();
	int startSubService();

	// messages handling
	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	virtual void PreStop(int type, bool meiEnabled) {}
	virtual bool ShouldPass() { return !m_serviceIsClosed; }

	virtual const ACE_TString name() = 0;

	ACE_Reactor_Notification_Strategy notifier_;
	GmsService* m_mainService;
	// This indicates that the service is in a closing process
	// When false - the service is active
	// When true  - the service is in closing stages
	bool m_serviceIsClosed;

	template <typename T>
	using FuncEntryExit = FuncEntryExit_<T, GmsSubService>;
private:
	void sendStatusChanged(SERVICE_STATUS_TYPE type);
};

#define LMS_SUBSERVICE_DEFINE(_export_, _name_) \
ACE_FACTORY_DEFINE (_export_, _name_) \
\
ACE_STATIC_SVC_DEFINE ( \
  _name_, \
  ACE_TEXT (#_name_), \
  ACE_SVC_OBJ_T, \
  &ACE_SVC_NAME (_name_), \
  ACE_Service_Type::DELETE_THIS \
  | ACE_Service_Type::DELETE_OBJ, \
  1 \
) \
\
ACE_STATIC_SVC_REQUIRE (_name_)

#endif /* __SUBSERVICE_H_ */
