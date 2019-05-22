/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#include "ServiceNamesList.h"
#include "servicesNames.h"

void ServiceNamesList::Read(const ACE_WString &fileName)
{
	//todo - the future implementation of actually reading the services groups from XML instead of hard-coded impl below
}

#ifdef WIN32
#define AddNameWin(name) AddName(name)
#define AddNameLinux(name)
#else
#define AddNameWin(name)
#define AddNameLinux(name) AddName(name)
#endif // WIN32

void ServiceNamesList::Read(NamesGroup namesGroup)
{
	switch(namesGroup)
	{
	case EVENT_HANDLERS_GROUP:
		AddName(WINLOG_EVENT_HANDLER);
		AddNameWin(COM_EVENT_HANDLER);
		AddNameWin(WMI_EVENT_HANDLER);
		AddNameLinux(GMS_DBUSSERVICE);
		AddName(HISTORY_EVENT_HANDLER);
		AddName(STATUS_EVENT_HANDLER);
		#ifdef DEBUG //Only for L10N validation!
			AddName(POWER_OPERATIONS_SERVICE);
		#endif
		break;
	case SKU_1_5_GROUP:
		AddNameLinux(GMS_DBUSSERVICE);
		break;
	case SKU_5_GROUP:
		Read(EVENT_HANDLERS_GROUP);
		AddName(GMS_PORTFORWARDINGSERVICE);
		AddName(GMS_HOSTCHANGESNOTIFICATIONSERVICE);
		AddNameWin(GMS_PARTIALFWUPDATESERVICE);
		break;
	case MANAGABILITY_GROUP:   
		AddNameWin(GMS_IPREFRESHSERVICE);
		AddName(GMS_SHAREDSTATICIPSERVICE);
		AddName(POWER_OPERATIONS_SERVICE);
		AddName(GMS_TIMESYNCSERVICE);
		AddNameWin(GMS_WIFIPROFILESYNCSERVICE);
		break;

	case SKU_5_NO_LME_GROUP:
		Read(EVENT_HANDLERS_GROUP);
		break;
	case DUMMY_SERVICES:
		AddName(FIRST_SERVICE);
		AddName(LAST_SERVICE);
		break;
	}
}


void ServiceNamesList::GetNames(NamesList &serviceNames) const
{
	serviceNames = m_ServicesNames;
}

void ServiceNamesList::AddName(const ACE_TString &serviceName)
{
	m_ServicesNames.push_back(serviceName);
}

void ServiceNamesList::SetNames(const NamesList &serviceNames)
{
	m_ServicesNames = serviceNames;
}



