/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#include "COMEventHandler.h"
#include <atlbase.h>
#include <atlcom.h>
#include "AMT_COM_Interface.h"


	COMEventHandler:: COMEventHandler():filter_(new ComFilter)
	{
		initFilter();
	}

	void 
	COMEventHandler::initFilter()
	{
		ComFilter::defaultInitialization(filter_);
	}

	int
	COMEventHandler::init (int argc, ACE_TCHAR *argv[])
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
	COMEventHandler::handle_event (MessageBlockPtr mbPtr )
	{	
		GMS_AlertIndication *pGMS_AlertIndication = nullptr;
		int type = mbPtr->msg_type();

		UNS_DEBUG(L"COMEventHandler::handle_event\n");

		switch (type) {
		case MB_PUBLISH_EVENT:
			pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{
				return COMLogging(pGMS_AlertIndication);
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("COMEventHandler::Invalid data block.\n")), -1);
			}
			break;
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("COMEventHandler::Invalid Message.\n")), -1);
		}
		return 0;
	}

	int 
	COMEventHandler::COMLogging(GMS_AlertIndication* alert)
	{
		
		UNS_DEBUG(L"COMEventHandler::COMLogging\n");

		if (m_mainService->GetStopped())
		{
			UNS_DEBUG(L"LMS was stopped, canceling COM operataion.\n"); //In order to avoid failure in LMS stop
			return -1;
		}

		GUID uiid= {0x64417EAE, 0x2E0E, 0x45E8, 0xA8, 0xC1, 0x03, 0x28, 0x4E, 0x3D, 0x35, 0x87};
		HRESULT rc;
		HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
		if (hr != S_OK && hr != S_FALSE)
		{
			UNS_ERROR(L"COMEventHandler::COMLogging - CoInitializeEx failed %d\n", hr);
			return -1;
		}
		UNS_DEBUG(L"COMEventHandler::COMLogging - after CoInitializeEx\n");
		{
			CComPtr<IUnknown> pUnk;
			rc=pUnk.CoCreateInstance(uiid);	
			UNS_DEBUG(L"COMEventHandler::COMLogging - after CoCreateInstance\n");
			static const char* emptyStr = "";
			if ((rc==S_OK) && (pUnk!=NULL))
			{
				CComPtr<IUNSAlert> pI;
				rc=pUnk.QueryInterface(&pI);
				UNS_DEBUG(L"COMEventHandler::COMLogging - after QueryInterface\n");
				if ((rc==S_OK) && (pI!=NULL))
				{
					BSTR bstrMessage, bstrMessageArgument, bstrMessageID, bstrDatetime;
					bstrMessage = W2BSTR(alert->Message.c_str());
					if (alert->MessageArguments.size() > 0)
						bstrMessageArgument = W2BSTR(alert->MessageArguments[0].c_str());
					else
						bstrMessageArgument=A2BSTR(emptyStr);
					bstrMessageID = W2BSTR(alert->MessageID.c_str());
					bstrDatetime = A2BSTR(alert->Datetime.c_str());
					UNS_DEBUG(L"Sending RiseAlert, alert id: %d, message: %s\n", alert->id, alert->Message.c_str());
					pI->RiseAlert(alert->category,alert->id, bstrMessage,	bstrMessageArgument,bstrMessageID,bstrDatetime);
					UNS_DEBUG(L"RiseAlert sent\n");
					SysFreeString(bstrMessage);
					SysFreeString(bstrMessageArgument);
					SysFreeString(bstrMessageID);
					SysFreeString(bstrDatetime);
				}
				else
				{
					UNS_ERROR(L"QueryInterface failed rc=%x\n", rc);
				}
			}
			else
			{
				UNS_ERROR(L"CoCreateInstance failed rc=%x\n", rc);
			}
		}
		CoUninitialize();
		UNS_DEBUG(L"COMEventHandler::COMLogging - after CoUninitialize\n");
		return (rc==S_OK);
	}

	const ACE_TString
	COMEventHandler::name()
	{
		return COM_EVENT_HANDLER;
	}

	LMS_SUBSERVICE_DEFINE (COMEVENTHANDLER, COMEventHandler)


