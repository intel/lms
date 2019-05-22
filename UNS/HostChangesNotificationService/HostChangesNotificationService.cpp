/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
#include "global.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "Tools.h"
#include "HostChangesNotificationService.h"
#include <SetHostFQDNCommand.h>

HostChangesNotificationService::HostChangesNotificationService() : m_hostFQDN("")
{
}

int
HostChangesNotificationService::init (int argc, ACE_TCHAR *argv[])
{
	initSubService(argc,argv);
	static unsigned long nGetFQDN_Interval = 3600 * GMS_ACE_SECOND;


	ACE_Time_Value interval (nGetFQDN_Interval); 

	/*long timerID = */ACE_Reactor::instance()->schedule_timer (this,
		0,
		ACE_Time_Value::zero,
		interval);

	startSubService();
	return 0;
}

int
HostChangesNotificationService::fini (void)
{
	UNS_DEBUG(L"HostChangesNotificationService service stopped",L"\n");
	ACE_Reactor::instance()->cancel_timer (this);
	return 0;
}

const ACE_TString
HostChangesNotificationService::name()
{
	return GMS_HOSTCHANGESNOTIFICATIONSERVICE;
}


ACE_FACTORY_DEFINE (HOSTCHANGESNOTIFICATIONSERVICE, HostChangesNotificationService)


int HostChangesNotificationService::handle_timeout( const ACE_Time_Value &current_time,const void *arg )
{
	UNS_DEBUG(L"%s service handle timeout",L"\n",name().c_str());

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_TIMER_EXPIRED);
	this->putq(mbPtr->duplicate()); 

	return 0;
}

void 
HostChangesNotificationService::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	UNS_DEBUG(L"HostChangesNotificationService::HandleAceMessage",L"\n");	
	switch (type) 
	{
		case MB_TIMER_EXPIRED:
			Action();
			break;
		default:
			GmsSubService::HandleAceMessage(type, mbPtr);
	}
}

void HostChangesNotificationService::Action()
{
	std::string fqdn;
	if (!GetLocalFQDN(fqdn))
	{
		UNS_DEBUG(L"Error in setting host FQDN.- not sending HOSTFQDN to FW\n");
		return;
	}
	if (m_hostFQDN != fqdn)
	{
		try {
			Intel::MEI_Client::AMTHI_Client::SetHostFQDNCommand setHostFQDNCommand(fqdn);
			m_hostFQDN = fqdn;
		}
		catch(Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
		{
			int errNo = e.getErr();
			UNS_DEBUG(L"Error in SET_HOST_FQDN. Number is: %d",L"\n", errNo);
		}
#ifdef _DEBUG
		catch(Intel::MEI_Client::MEIClientException& e)
		{
			UNS_DEBUG(L"HostChangesNotificationService::Action: SetHostFQDNCommand failed: %C",L"\n", e.what());
		}
#else
		catch(Intel::MEI_Client::MEIClientException&){}
#endif
	}
}

int HostChangesNotificationService::resume()
{
	GmsSubService::resume();
	Action();
	return 0;
}

