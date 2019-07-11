/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#include "WMIEventHandler.h"
#include <atlbase.h>
#include <atlcom.h>
#include <string> 
#include <list>
#include <vector>
#include <wbemidl.h>
#include <wmiutils.h>
#include <locale>
#include "wbemcli.h"
#include <sstream>


	WMIEventHandler:: WMIEventHandler():filter_(new WMIFilter)
	{
		WMIFilter::defaultInitialization(filter_);
	}


	int
	WMIEventHandler::init (int argc, ACE_TCHAR *argv[])
	{
		int retVal = EventHandler::init(argc, argv);
		if (retVal != 0)
		{
			UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
			return retVal;
		}

		return 0;
	}


	int
	WMIEventHandler::handle_event (MessageBlockPtr mbPtr )
	{
		GMS_AlertIndication *pGMS_AlertIndication = nullptr;
		int type=mbPtr->msg_type();

		switch (type) {
			case MB_PUBLISH_EVENT:
				pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
				if (pGMS_AlertIndication != nullptr)
				{
					return WMILogging(pGMS_AlertIndication);
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

	bool 
	WMIEventHandler::shouldAppendMessageArgToEnd(unsigned long id )
	{
		switch(id)
		{
			case EVENT_AGENT_PRSENCE_NOT_STARTED:
			case EVENT_AGENT_PRSENCE_STOPED:
			case EVENT_AGENT_PRSENCE_EXPIRED:
				return false;
				break;
			default:
				return true;
		}
	}

	int 
	WMIEventHandler::WMILogging(GMS_AlertIndication* alert)
	{
		UNS_DEBUG(L"WMIEventHandler::handleEvent\n");
		HRESULT hr = WBEM_S_NO_ERROR;
		hr  = CoInitializeEx(NULL, COINIT_MULTITHREADED );
		{
			// Access WMI
			CComPtr<IWbemLocator> spLoc;
			hr = spLoc.CoCreateInstance(__uuidof(WbemLocator));
			if (hr == WBEM_S_NO_ERROR)
			{
		
				CComBSTR bstrNamespace(_T("\\\\.\\root\\Intel_ME"));
				CComPtr<IWbemServices> spServices;

				// Connect to WMI to get access to the namespace via IWebmServices
				hr = spLoc->ConnectServer(bstrNamespace, NULL, NULL, 0, NULL, 0, 0, &spServices);
				if ((hr == WBEM_S_NO_ERROR) && (spServices!=NULL))
				{
					// Create the event
					CComPtr<IWbemClassObject> spEventClass;
					hr = spServices->GetObject(CComBSTR("ME_Event"), 0, NULL, &spEventClass, NULL);
					if ((hr == WBEM_S_NO_ERROR) && (spEventClass!=NULL))
					{

						CComPtr<IWbemClassObject> spEvent;
						hr = spEventClass->SpawnInstance(0, &spEvent);
						if ((hr == WBEM_S_NO_ERROR) && (spEvent!=NULL))
						{
							// Populate the event's properties
							CComVariant	varEventID(alert->id);
							varEventID.ChangeType(VT_I4);
							hr = spEvent->Put(L"ID", 0, &varEventID, 0);
							if (hr!=S_OK){
								DWORD err=GetLastError();
								UNS_ERROR(L"spEvent->Put(L\"ID\" failed, hr=%x err=%d\n", hr, err);
							}
							CComVariant	varEventCategory(alert->category);
							varEventCategory.ChangeType(VT_UI1);
							hr = spEvent->Put(L"Category", 0, &varEventCategory, 0);
							if (hr!=S_OK){
								DWORD err=GetLastError();
								UNS_ERROR(L"spEvent->Put(L\"Category\" failed, hr=%x err=%d\n", hr, err);
							}
							ACE_WString message(ACE_TEXT_ALWAYS_WCHAR(alert->Message));
							if (alert->MessageArguments.size() && shouldAppendMessageArgToEnd(alert->id))
							{
								message.append(ACE_TEXT_ALWAYS_WCHAR(alert->MessageArguments[0].c_str()), alert->MessageArguments[0].length());
							}
							CComVariant varEventMessage(message.c_str());
							hr = spEvent->Put(L"Message", 0, &varEventMessage, 0);
							if (hr!=S_OK){
								DWORD err=GetLastError();
								UNS_ERROR(L"spEvent->Put(L\"Message\" failed, hr=%x err=%d\n", hr, err);
							}
						
							//
							SYSTEMTIME st;
							GetSystemTime(&st);
							std::stringstream sdate;
							sdate<<setfill('0')<<setw(4)<<st.wYear<<setw(2)<<st.wMonth<<setw(2)<<st.wDay<<
								setw(2)<<st.wHour<<setw(2)<<st.wMinute<<
								setw(2)<<st.wSecond<<".000000+000";
									
							//string date = A2W(sdate);
							CComVariant varCreationTime(sdate.str().c_str());
							hr = spEvent->Put(L"CreationTime", 0, &varCreationTime, 0);
							if (hr!=S_OK){
								DWORD err=GetLastError();
								UNS_ERROR(L"spEvent->Put(L\"CreationTime\" failed, hr=%x err=%d\n", hr, err);
							}
						
							// Ask WMI for an event sink so we can publish events
							CComPtr<IWbemObjectSink> spEventSink;
							hr = spServices->QueryObjectSink(0, &spEventSink);
							if ((hr == WBEM_S_NO_ERROR) && (spEventSink!=NULL))
							{
								// Publish the __InstanceCreationEvent
								hr = spEventSink->Indicate(1, &spEvent.p);
								UNS_DEBUG(L"spEventSink->Indicate return, hr=%x\n", hr);

								if (hr!=S_OK){
									DWORD err=GetLastError();
									UNS_ERROR(L"spEventSink->Indicate failed, hr=%x err=%d\n", hr, err);
								}
								else {
									UNS_DEBUG(L"spEventSink->Indicate succeed !!!\n");
									hr = spEventSink->SetStatus(WBEM_STATUS_COMPLETE,S_OK,NULL,NULL);
								}
							}
							else
							{
								DWORD err=GetLastError();
								UNS_ERROR(L"spServices->QueryObjectSink failed, hr=%x err=%d\n", hr, err);

							}
						}
						else
							UNS_ERROR(L"WMIEventHandler::handleEvent SpawnInstance failed, hr=%x\n", hr);
					}
					else
						UNS_ERROR(L"WMIEventHandler::handleEvent GetObject failed, hr=%x\n", hr);
				}
				else
					UNS_ERROR(L"WMIEventHandler::handleEvent ConnectServer failed, hr=%x\n", hr);
			}
			else
				UNS_ERROR(L"WMIEventHandler::handleEvent CoCreateInstance failed, hr=%x\n", hr);
		}
		CoUninitialize();
		return (hr == WBEM_S_NO_ERROR);
	}

	const ACE_TString
	WMIEventHandler::name()
	{
		return WMI_EVENT_HANDLER;
	}

	ACE_FACTORY_DEFINE (WMIEVENTHANDLER, WMIEventHandler)


