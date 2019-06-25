/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
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
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService::init failed. retVal: %d\n", retVal);

		return retVal;
	}

	InitAndPerformSync();
	
	return 0;
}

void WiFiProfileSyncService::InitAndPerformSync()
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: WiFiProfileSyncService:: Initialize WLAN...\n");

	if (InitWlan() != 0)
	{
		ACE_Reactor::instance()->schedule_timer(this, NULL, ACE_Time_Value(INIT_LOOP_DELAY), ACE_Time_Value::zero);
		return;
	}

	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Calling PerformSync...\n");
	PerformSync();
}

int WiFiProfileSyncService::InitWlan()
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
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__": WlanOpenHandle error\n");
		return dwResult;
	}

	wlanps::WlanBL&  wlanBL = wlanps::WlanBL::getInstance();

	int retVal = wlanBL.Init(m_wlanHandle);
	if (retVal)
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__":  wlanBL.Init error %d\n", retVal);
		return retVal;
	}

	wlanps::WlanNotifications&  wlanNotifications = wlanps::WlanNotifications::getInstance();

	retVal = wlanNotifications.Init(m_wlanHandle, this); // _hEvents, 
	if (retVal)
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__":  wlanNotifications.Init error %d\n", retVal);
		return retVal;
	}

	return 0;
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


ACE_FACTORY_DEFINE (WIFIPROFILESYNCSERVICE, WiFiProfileSyncService)

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
				wlanps::WlanBL& wlanBL = wlanps::WlanBL::getInstance();

				wlanBL.onConnectionComplete(&message->_profileData);
				return 1;
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid data block.\n")), -1);
			}
		}
		break;

		default:
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: Invalid message. Return ERROR\n");
		}
		break;
	}

	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message.\n")), -1);
}

int WiFiProfileSyncService::handlePublishEvent(const GMS_AlertIndication & alert)
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: handlePublishEvent --->\n");

	switch (alert.category)
	{
		case CATEGORY_UNS:
		{
			switch (alert.id)
			{
				case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
				{
					UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: %s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
					if (m_syncRequiredButNoPfw)
					{
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: m_syncRequiredButNoPfw is true -> PerformSync...\n");

						wlanps::WlanBL::getInstance().SyncProfiles();
						m_syncRequiredButNoPfw = false;
						return 1;
					}
					else
					{
						UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]:: m_syncRequiredButNoPfw is false -> Do nothing...\n");
					}
				}
				break;

				default:
				{
					ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message id.\n")), -1);
				}
				break;
			}
		}
		break;

		default:
		{
			UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Invalid category. Return ERROR\n");

			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message category.\n")), -1);
		}
		break;
	}

	return 1;
}

void WiFiProfileSyncService::PerformSync()
{
	UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"...\n");

	if (!m_mainService->GetPortForwardingStarted()) 
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: %s: Port Forwarding did not start yet, aborting sync operation. \n", name().c_str());
		m_syncRequiredButNoPfw = true;
	}
	else
	{
		UNS_DEBUG(L"[ProfileSync] " __FUNCTIONW__"[%03l]: Port Forwarding started -> Call PerformSync...\n");

		wlanps::WlanBL::getInstance().SyncProfiles();
		m_syncRequiredButNoPfw = false;
	}
}