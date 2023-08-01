/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: AT_Device.h

--*/

// AT_Device.h : Declaration of the CAT_Device

#pragma once
#include "resource.h"       // main symbols

#include "AMT_COM_Interface.h"
#include "GmsService.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CAT_Device

class ATL_NO_VTABLE CAT_Device :
	public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
	public ATL::CComCoClass<CAT_Device, &CLSID_AT_Device>,
	public ATL::IDispatchImpl<IAT_Device, &IID_IAT_Device, &LIBID_AMT_COM_InterfaceLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAT_Device()
	{
		theService::instance()->inherit_log_msg_attributes();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AT_DEVICE)

BEGIN_COM_MAP(CAT_Device)
	COM_INTERFACE_ENTRY(IAT_Device)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}


public:
	STDMETHOD(GetATDeviceInfo)(SHORT* pState, BSTR* bstrInfo);
	STDMETHOD(GetAuditLogs)(BSTR* bstrAuditLogs);		//LPSAFEARRAY VARIANT SAFEARRAY
};

OBJECT_ENTRY_AUTO(__uuidof(AT_Device), CAT_Device)
