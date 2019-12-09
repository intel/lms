/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "WinLogEventHandler.h"
#include "HTMGetFLogCommand.h"
#include "DataStorageGenerator.h"
#include "UNSMessageFile.h"
#include "UNSEventsDefinition.h"

WinLogEventHandler:: WinLogEventHandler():filter_(new WinLogFilter)
{
	// Initialize a map from eventID to category/id 
	logger_=&GMSExternalLogger::instance();
}
int
WinLogEventHandler::init (int argc, ACE_TCHAR *argv[])
{
	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
		return retVal;
	}

	// ===== FLOG =====

	//get current FLog size (using HOTHAM command)
	uint32_t currentSize = 0;
	try
	{			
		Intel::MEI_Client::HOTHAM_Client::HTMGetFatalErrorsCommand getFatalErrorsCommand;	
		currentSize = getFatalErrorsCommand.getResponse().response.response;
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception with HTMGetFatalErrorsCommand: %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"Exception with HTMGetFatalErrorsCommand\n");
	}


	unsigned long registrySize; //previous FLog size from the registry
	//If current log's size is greater than previous one (of when we got up) = there was a fatal error.
	//Even if it is lower than the current - it may be after reset of FLog
	if (DSinstance().GetDataValue(FLogSize, registrySize, false) == true && currentSize != registrySize ||
		DSinstance().GetDataValue(FLogSize, registrySize, false) == false ) // no value is saved in the registry
	{	
		UNS_DEBUG(L"Intel(R) Management Engine (Intel(R) ME) error(s) occurred. Please review Intel(R) ME logs.\n");
			
		//notify in the Event Viewer
		sendAlertIndicationMessage(CATEGORY_GENERAL, EVENT_FW_FATAL_ERROR, ACE_TEXT("Fatal Error in FW log"));

		//update the reg with current log size
		DSinstance().SetDataValue(FLogSize, currentSize, false);
	}

	return 0;
}

int
WinLogEventHandler::fini (void)
{
	return EventHandler::fini();
}

int
WinLogEventHandler::handle_event (MessageBlockPtr mbPtr )
{
	GMS_AlertIndication *pGMS_AlertIndication = nullptr;
	int type = mbPtr->msg_type();

	switch (type) {
		case MB_PUBLISH_EVENT:
			pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{
				return winLogging(pGMS_AlertIndication);
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid data block.\n")), -1);
			}
		default:
			ACE_ERROR_RETURN
			((LM_ERROR, ACE_TEXT ("Invalid Message.\n")), -1);
			}
	return 0;
}

int 
WinLogEventHandler::winLogging(GMS_AlertIndication* alert)
{
		
		GmsEventType et;
	
		bool subscribe = filter_->toSubscribe (alert,et);
		if (!subscribe)
		{
			UNS_DEBUG(L"WinLogEventHandler: not subscribed\n");
			return 0;
		}
		 
		
	if ((et.id == PFW_UPGRADE_FAILURE_LANG)			|| (et.id == PFW_UPGRADE_FAILURE_WLAN) || 
		(et.id == MISSING_IMAGE_FILE_LANG)			|| (et.id == MISSING_IMAGE_FILE_WLAN) ||
		(et.id == AGENT_PRSENCE_STOPED)				|| (et.id == AGENT_PRSENCE_EXPIRED) ||
		(et.id == UNS_NETWORK_SYNC_UPDATE_FAILED)	|| (et.id == UNS_WARNING_MESSAGE) ||
		(et.id == FW_FATAL_ERROR)					|| (et.id == EVENT_PORT_FORWARDING_SERVICE_UNAVAILABLE))
	{
		if (alert->MessageArguments.size() > 0)
		{
			logger_->LogWarningEvent(et.category, et.id, alert->MessageArguments[0].c_str());
		}
		else
		{
			logger_->LogWarningEvent(et.category, et.id);
		}
	}
	else
	{
		if (alert->MessageArguments.size() > 0)
		{
			logger_->LogInfoEvent(et.category, et.id, alert->MessageArguments[0].c_str());
		}
		else 
		{
			logger_->LogInfoEvent(et.category, et.id);
		}
	}
		
	UNS_DEBUG(L"WinLogEventHandler: sent event to logger\n");
	return 0;
}

const ACE_TString
WinLogEventHandler::name()
{
	return WINLOG_EVENT_HANDLER;
}

ACE_FACTORY_DEFINE (WINLOGEVENTHANDLER, WinLogEventHandler)
