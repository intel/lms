/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2025 Intel Corporation
 */

#include "GmsSubService.h"
#include <ace/Get_Opt.h>
#include "Tools.h"

#include <sstream>

int GmsSubService::init (int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"init");
	int ret = initSubService(argc, argv);
	if (ret)
		return ret;
	startSubService();
	return 0;
}

int GmsSubService::initSubService(int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"initSubService");

	m_mainService = GmsService::getService();
	if (m_mainService == NULL)
	{
		UNS_ERROR(L"GmsService is not instantiated\n");
		return -1;
	}

	this->reactor(&gmsSubServiceReactor);
	this->notifier_.reactor(this->reactor());
	this->notifier_.event_handler(this);
	this->msg_queue()->notification_strategy(&this->notifier_);
	m_serviceIsClosed=false;
	this->activate();
	UNS_DEBUG(L"%s\n",name().c_str());
	return 0;
}

int GmsSubService::svc(void)
{
	FuncEntryExit<void> fee(this, L"svc");
	UNS_DEBUG(L"%s svc\n", name().c_str());

	int ret = 0;

	reactor()->owner(ACE_Thread::self());

	try
	{
		reactor()->run_reactor_event_loop();
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception %C\n", e.what());
		ret = -1;
	}
	catch (...)
	{
		UNS_ERROR(L"Exception\n");
		ret = -1;
	}
	
	UNS_DEBUG(L"%s Shutting down\n", name().c_str());
	return ret;
}

void GmsSubService::sendStatusChanged(SERVICE_STATUS_TYPE type)
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ServiceStatus(name(), type));
	mbPtr->msg_type(MB_SERVICE_STATUS_CHANGED);
	m_mainService->sendMessage(GMS_CONFIGURATOR, mbPtr);
}

int GmsSubService::closeSubService()
{
	FuncEntryExit<void> fee(this, L"closeSubService");

	ACE_Message_Block *mb = nullptr;
	int cleared_count = 0;
	while (!this->msg_queue()->is_empty() && cleared_count < 1000) { // Safety limit
		if (this->getq(mb, (ACE_Time_Value*)&ACE_Time_Value::zero) != -1 && mb != nullptr) {
			mb->release();
			mb = nullptr;
			cleared_count++;
		} else {
			break;
		}
	}
	UNS_DEBUG(L"%s::closeSubService cleared %d messages from queue\n", name().c_str(), cleared_count);

	sendStatusChanged(SERVICE_STATUS_TYPE::UNLOADCOMPLETE);

	UNS_DEBUG(L"%s\n",name().c_str());
	return 0;
}

int GmsSubService::suspendSubService()
{
	sendStatusChanged(SERVICE_STATUS_TYPE::SUSPENDCOMPLETE);

	UNS_DEBUG(L"%s suspendSubService()\n",name().c_str());
	return 0;
}

int GmsSubService::startSubService()
{
	FuncEntryExit<void> fee(this, L"startSubService");

	sendStatusChanged(SERVICE_STATUS_TYPE::LOADCOMPLETE);

	UNS_DEBUG(L"SubService: %s\n", name().c_str());
	return 0;
}

int GmsSubService::fini (void)
{
	UNS_DEBUG(L"%s service finalized\n",name().c_str());

	if (reactor() && !reactor()->reactor_event_loop_done()) {
		reactor()->end_reactor_event_loop();
		reactor()->notify();
		wait();

		reactor()->remove_handler(this, ACE_Event_Handler::ALL_EVENTS_MASK | ACE_Event_Handler::DONT_CALL);
		reactor()->purge_pending_notifications(this);
		reactor()->cancel_timer(this);
	}

	// Clear pending tasks from message queue with improved cleanup
	ACE_Message_Block *mb = nullptr;
	int cleared_count = 0;
	while (!this->msg_queue()->is_empty() && cleared_count < 1000) { // Safety limit
		if (this->getq(mb, (ACE_Time_Value*)&ACE_Time_Value::zero) != -1 && mb != nullptr) {
			mb->release();
			mb = nullptr;
			cleared_count++;
		} else {
			break;
		}
	}
	UNS_DEBUG(L"fini: cleared %d messages from queue\n", cleared_count);
	
	return 0;
}

int GmsSubService::suspend() 
{
	UNS_DEBUG(L"%s service suspended\n",name().c_str());
	return 0;
}

int GmsSubService::resume() 
{
	sendStatusChanged(SERVICE_STATUS_TYPE::RESUMECOMPLETE);

	UNS_DEBUG(L"%s service Resumed\n",name().c_str());
	return 0;
}

int GmsSubService::handle_output(ACE_HANDLE fd)
{
	FuncEntryExit<void> fee(this, L"handle_output");
	UNS_DEBUG(L"handle_output: %s\n",name().c_str());

	ACE_Message_Block *mb = nullptr;
	while (!this->msg_queue()->is_empty() && ShouldPass())
	{
		if (this->getq(mb) != -1 && mb != nullptr)
		{
			MessageBlockPtr mbPtr(mb, deleteMessageBlockPtr);
			int type=mbPtr->msg_type();
			HandleAceMessage(type, mbPtr);
		}
		mb = nullptr;
	}
	return true;
}

void GmsSubService::HandleAceMessage( int type, MessageBlockPtr &mbPtr )
{
	FuncEntryExit<decltype(type)> fee(this, L"GmsSubService::HandleAceMessage", type);

	switch (type) {
	case MB_STOP_SERVICE:
		{
			StopServiceDataBlock *event = dynamic_cast<StopServiceDataBlock*>(mbPtr->data_block());
			bool meiEnabled = false;
			if (event != nullptr)
				meiEnabled = event->m_meiEnabled;
			PreStop(type, meiEnabled);
			closeSubService();
			m_serviceIsClosed=true;
			break;
		}
	case MB_SUSPEND_SERVICE:
		{
			suspendSubService();
			break;
		}
	default:
		UNS_ERROR(L"%s Error: Unexpected message type: %d \n", name().c_str(), type);
		break;
	}
}

bool GmsSubService::sendAlertIndicationMessage(unsigned short category, unsigned long id,
	const ACE_TString &Message, const ACE_TString &MessageArgument)
{
	auto svc = GmsService::getService();
	if (svc == nullptr)
		return false;
	
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new GMS_AlertIndication(category, id, getDateTime(), ACTIVE_MESSAGEID, Message, MessageArgument));
	mbPtr->msg_type(MB_PUBLISH_EVENT);
	return svc->sendMessage(EVENT_MANAGER, mbPtr);
}