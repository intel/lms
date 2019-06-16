/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#ifndef __EVENTMANAGER_H_
#define __EVENTMANAGER_H_

#include "GmsSubService.h"
#include "ace/Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "MessageBlockPtr.h"
#include "EVENTMANAGER_export.h"

class EventMapManager : public ACE_Map_Manager <ACE_TString , EventsFilter*, ACE_Null_Mutex>
{
public:
	void Clear() {free_search_structure();}
};

class EVENTMANAGER_Export EventManager : public GmsSubService
{

public:

	EventManager(){}

	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);

	virtual int resume();

	void publishEvent(MessageBlockPtr &eventMsg, const GMS_AlertIndication *pGMS_AlertIndication);

	int subscribeForEvents(SubscribeEventHandler* eventHandler);

	int unSubscribeForEvents(UnSubscribeEventHandler* eventHandler);

protected:

	virtual const ACE_TString name();

private:

	EventMapManager handlers;

};

#endif /* __EVENTMANAGER_H_ */