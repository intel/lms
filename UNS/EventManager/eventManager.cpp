/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "eventManager.h"

void 
EventManager::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	UNS_DEBUG(L"EventManager::HandleAceMessage type:%d\n", type);

	switch (type) 
	{
		case MB_SUBSCRIBE_EVENT:
		{
			SubscribeEventHandler *event = dynamic_cast<SubscribeEventHandler*>(mbPtr->data_block());
			if (event != nullptr)
			{
				subscribeForEvents(event);
			}
			else
			{
				UNS_DEBUG(L"Invalid data block.\n");
			}
		}
		break;
		
		case MB_UNSUBSCRIBE_EVENT:
		{
			UnSubscribeEventHandler *event = dynamic_cast<UnSubscribeEventHandler*>(mbPtr->data_block());
			if (event != nullptr)
			{
				unSubscribeForEvents(event);
			}
			else
			{
				UNS_DEBUG(L"Invalid data block.\n");
			}
		}
		break;
		
		case MB_PUBLISH_EVENT:
		{
			GMS_AlertIndication *pGMS_AlertIndication = pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{
				publishEvent(mbPtr, pGMS_AlertIndication);
			}
			else
			{
				UNS_DEBUG(L"Invalid data block.\n");
			}
		}
		break;
		
		default:
			GmsSubService::HandleAceMessage(type, mbPtr);
	}

}

void 
EventManager::publishEvent(MessageBlockPtr &eventMsg, const GMS_AlertIndication *pGMS_AlertIndication)
{
	ACE_Map_Iterator< ACE_TString, EventsFilter*, ACE_Null_Mutex> iter (handlers);
	for (iter = handlers.begin (); iter != handlers.end (); iter++)
	{
		ACE_Map_Entry< ACE_TString, EventsFilter*> entry = *iter;

		UNS_DEBUG(L"Event manager post event to %s\n", entry.ext_id_.c_str());
		if (entry.int_id_->toSubscribe(pGMS_AlertIndication))
		{
			m_mainService->sendMessage(entry.ext_id_,eventMsg);
			UNS_DEBUG(L"EventManager::publish event %s to %s\n", pGMS_AlertIndication->Message.c_str(), entry.ext_id_.c_str());
		}
		else
			UNS_DEBUG(L"EventManager:: Filter blocked Subscribe %s for event\n", entry.ext_id_.c_str());
	}
}

int
EventManager::subscribeForEvents(SubscribeEventHandler* eventHandler)
{
	UNS_DEBUG(L"EventManager::subscribe %s for events\n", eventHandler->serviceName_.c_str());
	

	// we need to pass to the map a regular pointer since the delayed memory management is
	// dangerous when subservice can be dynamically unloaded.
	int i=handlers.bind(eventHandler->serviceName_, eventHandler->filter_.get());
	if (i==-1)
	{
		UNS_DEBUG(L"subscribe error:\n");
		return -1;
	}
	if(i==1)
	{
		UNS_DEBUG(L"EventManager::eventHandler already registered\n");	
	}
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new SubscribeEventHandler());
	mbPtr->msg_type(MB_SUBSCRIBE_EVENT);
	mbPtr->msg_priority(1);//priority higher than publish event.
	m_mainService->sendMessage(eventHandler->serviceName_,mbPtr);
	return 0;

}

int
EventManager::unSubscribeForEvents(UnSubscribeEventHandler* eventHandler)
{
	UNS_DEBUG(L"EventManager::unSubscribe %s for events\n", eventHandler->serviceName_.c_str());
	int i=handlers.unbind(eventHandler->serviceName_);
	if (i==-1)
	{
		UNS_DEBUG(L"Unsubscribe error:\n");
		return -1;
	}
	if (handlers.current_size() == 0)
		handlers.Clear();

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new UnSubscribeEventHandler(eventHandler->serviceName_, eventHandler->meiEnabled_));
	mbPtr->msg_type(MB_UNSUBSCRIBE_EVENT);
	mbPtr->msg_priority(5);
	m_mainService->sendMessage(eventHandler->serviceName_,mbPtr);
	return 0;
}

const ACE_TString
	EventManager::name()
	{
		return EVENT_MANAGER;
	}

int EventManager::resume()
{
	GmsSubService::resume();

	return 0;
}

ACE_FACTORY_DEFINE (EVENTMANAGER, EventManager)


