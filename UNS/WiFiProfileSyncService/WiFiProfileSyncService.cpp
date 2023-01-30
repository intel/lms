/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2023 Intel Corporation
 */
#include "WiFiProfileSyncService.h"
#include "WlanBL.h"
#include "WlanNotifications.h"
#include "UNSEventsDefinition.h"

#define NUM_RETRIES 3
#define INIT_LOOP_DELAY 2 //seconds

int WiFiProfileSyncService::init(int argc, ACE_TCHAR *argv[])
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService::init\n");

	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService::init failed. retVal: %d\n", retVal);

		return retVal;
	}

	InitAndPerformSync();
	
	return 0;
}

void WiFiProfileSyncService::InitAndPerformSync()
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService:: Initialize WLAN...\n");

	if (!InitWlan())
	{
		ACE_Reactor::instance()->schedule_timer(this, NULL, ACE_Time_Value(INIT_LOOP_DELAY), ACE_Time_Value::zero);
		return;
	}

	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Calling PerformSync...\n");
	PerformSync();
}

bool WiFiProfileSyncService::InitWlan()
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService:: Open Handle...\n");

	unsigned long dwMaxClientVer = 2;
	unsigned long dwCurVersion = 0;
	unsigned long dwResult;


	// open wlan handle
	dwResult = WlanOpenHandle(dwMaxClientVer, NULL, &dwCurVersion, &m_wlanHandle);
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": WlanOpenHandle dwResult=%d\n", dwResult);

	if (dwResult != ERROR_SUCCESS)
	{
		UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__": WlanOpenHandle error\n");
		return false;
	}

	wlanps::WlanNotifications&  wlanNotifications = wlanps::WlanNotifications::getInstance();

	unsigned long retVal = wlanNotifications.Init(m_wlanHandle, this); // _hEvents, 
	if (retVal != ERROR_SUCCESS)
	{
		UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__":  wlanNotifications.Init error %u\n", retVal);
		return false;
	}

	return true;
}


int WiFiProfileSyncService::handle_timeout(const ACE_Time_Value &current_time, const void *arg)
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__":  Init Timer #%d\n", m_initNum);

	if (m_initNum < NUM_RETRIES)
	{
		m_initNum++;
		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->data_block(new ACE_Data_Block());
		mbPtr->msg_type(MB_TIMER_EXPIRED);
		this->putq(mbPtr->duplicate());

	}
	return 0;
}


int WiFiProfileSyncService::fini(void)
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSync service stopped\n");
	WlanCloseHandle(m_wlanHandle, nullptr);
	ACE_Reactor::instance()->cancel_timer(this);
	return 0;
}


const ACE_TString WiFiProfileSyncService::name()
{
	return GMS_WIFIPROFILESYNCSERVICE;
}


LMS_SUBSERVICE_DEFINE (WIFIPROFILESYNCSERVICE, WiFiProfileSyncService)

//Note : the return value is not used (see EventHandler::HandleAceMessage)
int WiFiProfileSyncService::handle_event (MessageBlockPtr mbPtr )
{	
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: %s::handle_event\n", name().c_str());

	int type = mbPtr->msg_type();
	switch (type)
	{
		case MB_TIMER_EXPIRED:
		{
			InitAndPerformSync();
			return 1; 
		}
		break;
		case MB_PUBLISH_EVENT:
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Got MB_PUBLISH_EVENT\n");
			GMS_AlertIndication * pGMS_AlertIndication = nullptr;
			pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{
				return handlePublishEvent(*pGMS_AlertIndication);
			}
		}
		break;
		case MB_WPFS_SYNC:
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Got MB_WPFS_SYNC\n");
			WPFS_Message_Block * message = nullptr;
			message = dynamic_cast<WPFS_Message_Block*>(mbPtr->data_block());
			if (message != nullptr)
			{
				if (!m_mainService->GetPortForwardingPort())
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %s: Port Forwarding did not start yet, aborting sync operation. \n", name().c_str());
					m_syncRequiredButNoPfw = true;
				}
				else
				{
					wlanps::WlanBL::onConnectionComplete(m_wlanHandle, &message->_profileData);
				}
				return 1;
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("WiFiProfileSyncService::Invalid data block.\n")), -1);
			}
		}
		break;

		default:
		{
			UNS_ERROR(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Invalid message. Return ERROR\n");
		}
		break;
	}

	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("WiFiProfileSyncService::Invalid Message.\n")), -1);
}

int WiFiProfileSyncService::handlePublishEvent(const GMS_AlertIndication & alert)
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: handlePublishEvent --->\n");

	switch (alert.category)
	{
		case CATEGORY_UNS:
			switch (alert.id)
			{
				case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: %s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE. m_syncRequiredButNoPfw: %d\n", name().c_str(), m_syncRequiredButNoPfw);
					if (m_syncRequiredButNoPfw)
					{
						PerformSync();
						m_syncRequiredButNoPfw = false;
					}
				break;
				default:
					ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("WiFiProfileSyncService::Invalid Message id.\n")), -1);
				break;
			}
			break;
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("WiFiProfileSyncService::Invalid Message category.\n")), -1);
			break;
	}

	return 1;
}

void WiFiProfileSyncService::PerformSync()
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"...\n");

	if (!m_mainService->GetPortForwardingPort())
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %s: Port Forwarding did not start yet, aborting sync operation. \n", name().c_str());
		m_syncRequiredButNoPfw = true;
		return;
	}

	wlanps::WlanBL::SyncProfiles(m_wlanHandle);
}
