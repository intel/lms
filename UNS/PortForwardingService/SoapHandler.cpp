/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#include "SoapHandler.h"
#include "global.h"
#include "EventManagment.h"
#include "CimToEventTranslator.h"
#include "GmsService.h"
#include "servicesNames.h"

// Constructor
SOAP_Handler::SOAP_Handler(void) : buf(), event_sent(false)
{
}

SOAP_Handler::~SOAP_Handler(void)
{
}

// The "soap" CIMevent that we are getting from the FW is always of the CONSTANT format, here is one example:
//"
// POST / HTTP/1.1\n\nHost: localhost:0\n\nUser-Agent: Intel(R) AMT Agent\n\nConnection: Keep-Alive\n\nContent-Length: 2203\n\n\n\n<?xml version="1.0" encoding="UTF-8"?>
// <a:Envelope xmlns:a="http://www.w3.org/2003/05/soap-envelope" xmlns:b="http://schemas.xmlsoap.org/ws/2004/08/addressing" xmlns:c="http://schemas.dmtf.org/wbem/wsman/1/wsman.xsd" 
// xmlns:d="http://schemas.xmlsoap.org/ws/2005/02/trust" xmlns:e="http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd" 
// xmlns:f="http://schemas.dmtf.org/wbem/wsman/1/cimbinding.xsd" xmlns:g="http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AlertIndication" 
// xmlns:h="http://schemas.dmtf.org/wbem/wscim/1/common" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"><a:Header><b:To>http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</b:To>
// <b:ReplyTo><b:Address>http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</b:Address></b:ReplyTo>
// <b:Action a:mustUnderstand="true">http://schemas.dmtf.org/wbem/wsman/1/wsman/Event</b:Action>
// <b:MessageID>uuid:00000000-8086-8086-8086-00000000014D</b:MessageID><c:ResourceURI>http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_AlertIndication</c:ResourceURI>
// </a:Header><a:Body><g:CIM_AlertIndication><g:AlertType>6</g:AlertType><g:AlertingElementFormat>2</g:AlertingElementFormat>
// <g:AlertingManagedElement>http://Interop/(instance)CIM_ComputerSystem.CreationClassName=(string)&quot;CIM_ComputerSystem&quot;,Name=(string)&quot;ManagedSystem&quot;</g:AlertingManagedElement>
// <g:IndicationFilterName>Intel(r) AMT:User Notification</g:IndicationFilterName><g:IndicationIdentifier>Intel(r):1635516445</g:IndicationIdentifier><g:IndicationTime>
// <h:Datetime>2018-08-09T15:45:00.000Z</h:Datetime></g:IndicationTime><g:Message></g:Message><g:MessageArguments>0</g:MessageArguments>
// <g:MessageArguments>http://Interop/(instance)CIM_ComputerSystem.CreationClassName=(string)&quot;CIM_ComputerSystem&quot;,Name=(string)&quot;ManagedSystem&quot;</g:MessageArguments>
// <g:MessageID>iAMT0057</g:MessageID><g:OtherAlertingElementFormat></g:OtherAlertingElementFormat><g:OtherSeverity></g:OtherSeverity><g:OwningEntity>Intel(r) AMT</g:OwningEntity>
// <g:PerceivedSeverity>2</g:PerceivedSeverity><g:ProbableCause>0</g:ProbableCause><g:SystemName>Intel(r) AMT</g:SystemName></g:CIM_AlertIndication></a:Body></a:Envelope>
// "
// The LMS SW is interested only in the following 3 elements out of all this xml structure:
//    <g:Message></g:Message>
//    <g:MessageArguments>0</g:MessageArguments>
//    <g:MessageID>iAMT0057</g:MessageID>
// So instead of using a heavy soap parser we just quickly parse those fields here.
int SOAP_Handler::read_and_parse_input(const char *data, size_t size, std::string &TestMessageId, std::string &TestMessageArg, std::string &TestMessageText, bool *finished)
{
	*finished = false;

	buf.append(data, size);

	// now parse the message
	return parse_message(buf, TestMessageId, TestMessageArg, TestMessageText, finished);
}

int SOAP_Handler::parse_message(const std::string &xmlMessage, std::string &TestMessageId, std::string &TestMessageArg, std::string &TestMessageText, bool *finished)
{
	std::string mesStartTag("<g:Message>"), mesEndTag("</g:Message>"),
		mesIdStartTag("<g:MessageID>"), mesIdEndTag("</g:MessageID>"),
		mesArgStartTag("<g:MessageArguments>"), mesArgEndTag("</g:MessageArguments>");
	size_t start, stop;

	start = xmlMessage.find(mesIdStartTag);
	if (start == std::string::npos)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesIdStartTag\n");
		return -1;
	}
	start += mesIdStartTag.size();
	stop = xmlMessage.find(mesIdEndTag, start);
	if (stop == std::string::npos || stop <= start)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesIdEndTag\n");
		return -1;
	}
	TestMessageId = xmlMessage.substr(start, stop - start);
	UNS_DEBUG(L"SOAP_Server_Handler::read_and_parse_input TestMessageId '%C'\n", TestMessageId.c_str());
	if (TestMessageId.size() != std::string("iAMTxxxx").size() ||
		TestMessageId.substr(0, 4) != std::string("iAMT"))
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message: wrong mesIdStartTag '%C'\n", TestMessageId.c_str());
		return -1;
	}
	start = xmlMessage.find(mesArgStartTag);
	if (start == std::string::npos)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesArgStartTag\n");
		return -1;
	}
	start += mesArgStartTag.size();
	stop = xmlMessage.find(mesArgEndTag, start);
	if (stop == std::string::npos || stop <= start)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesArgEndTag\n");
		return -1;
	}
	TestMessageArg = xmlMessage.substr(start, stop - start);
	UNS_DEBUG(L"SOAP_Server_Handler::parse_message TestMessageArg '%C'\n", TestMessageArg.c_str());
	if (TestMessageArg.size() > 2)
	{
		UNS_ERROR(L"SOAP_Server_Handler::parse_message: wrong TestMessageArg '%C'\n", TestMessageArg.c_str());
		return -1;
	}

	start = xmlMessage.find(mesStartTag);
	if (start == std::string::npos)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesStartTag\n");
		return -1;
	}
	start += mesStartTag.size();
	stop = xmlMessage.find(mesEndTag, start);
	// message can be empty string
	if (stop == std::string::npos || stop < start)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::parse_message cannot find mesEndTag\n");
		return -1;
	}
	if (stop == start)
		TestMessageText = "";
	else
		TestMessageText = xmlMessage.substr(start, stop - start);
	UNS_DEBUG(L"SOAP_Server_Handler::parse_message TestMessageText '%C'\n", TestMessageText.c_str());
	// when we successfully parsed the message we can close the connection - we do not expect anything else coming from there
	*finished = true;
	return 0;
}


// Receive and process incoming SOAP request.
bool SOAP_Handler::handle_input(const char *data, size_t size)
{
	bool finished = false;

	std::string TestMessageId, TestMessageArg, TestMessageText;
	if (read_and_parse_input(data, size, TestMessageId, TestMessageArg, TestMessageText, &finished) != 0)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::read_and_parse_input failed\n");
	}
	else
	{
		// we don't care about what is the return value of HandleCimAlert, if it failed it means that the SOAP xml was wrong
		HandleCimAlert(TestMessageId, TestMessageArg, TestMessageText);
	}

	return finished;
}

//*****************************************************************************
// Name			: SOAP_Server_Handler::HandleCimAlert
// Description	: Parse the given cim alert and record the appropriate event 
//				  to the Event Log.
// Params		: message Id, Arg and Text
// Returns		: true if alert was parsed successfully, false otherwise. 
//*****************************************************************************
bool SOAP_Handler::HandleCimAlert(const std::string &TestMessageId, const std::string &TestMessageArg, const std::string &TestMessageText)
{
	UNS_DEBUG(L"SOAP_Server_Handler::HandleCimAlert started\n");

	if (event_sent)
	{
		UNS_DEBUG(L"SOAP_Server_Handler::HandleCimAlert message is already out\n");
		return true;
	}

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	GMS_AlertIndication* alert = new GMS_AlertIndication();

	if (!CimToEventTranslator::instance().translate(TestMessageId, TestMessageArg, TestMessageText, *alert))
	{
		UNS_DEBUG(L"Soapserver:: Failed to parse CIM event!\n");
		delete alert;
		return false;
	}
	mbPtr->data_block(alert);
	mbPtr->msg_type(MB_PUBLISH_EVENT);
	auto svc = theService::instance();
	if (svc == nullptr)
	{
		UNS_DEBUG(L"Soapserver:: Failed to obtain service pointer!\n");
		delete alert;
		return false;
	}
	svc->sendMessage(EVENT_MANAGER, mbPtr);
	UNS_DEBUG(L"Soapserver:: publish LMS Event(category %d,Id %d, message %s\n", alert->category, alert->id, alert->Message.c_str());
	event_sent = true;
	return true;
}