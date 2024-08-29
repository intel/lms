/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: Manageability_Commands.h

--*/
// Manageability_Commands.h : Declaration of the CManageability_Commands

#pragma once
#include "resource.h"       // main symbols
#include "AMT_COM_Interface.h"
#include <atlcom.h>
#include "GmsService.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CManageability_Commands


class ATL_NO_VTABLE CManageability_Commands :
	public ATL::CComObjectRootEx<ATL::CComMultiThreadModel>,
	public ATL::CComCoClass<CManageability_Commands, &CLSID_Manageability_Commands>,
	public ATL::IDispatchImpl<IManageability_Commands, &IID_IManageability_Commands, &LIBID_AMT_COM_InterfaceLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CManageability_Commands()
	{
		auto svc = GmsService::getService();
		if (svc)
			svc->inherit_log_msg_attributes();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_Manageability_Commands)


BEGIN_COM_MAP(CManageability_Commands)
	COM_INTERFACE_ENTRY(IManageability_Commands)
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
	STDMETHOD(GetTheFeatureState)(FEATURES feat, FEATURE_STATE* pState);
	STDMETHOD(GetFeaturesState)(SAFEARRAY** ppStates);
	STDMETHOD(GetCustomerType)(CUSTOMER_TYPE* pType);
	STDMETHOD(GetPlatformType)(PLATFORM_TYPE* pType);
	STDMETHOD(GetCPUBrand)(SHORT* pBrand);
	STDMETHOD(GetMenageabiltyMode)(MENAGEABILTY_MODE* pMode);
	STDMETHOD(GetFWInfo)(BSTR* pMEBxVersion, ULONG* pBiosBootState, VARIANT_BOOL* pCryptoFuseEnable, VARIANT_BOOL* pLocalFWupdateEnable);
	STDMETHOD(GetPMCVersion)(BSTR* pFwVer);
	STDMETHOD(IsMeasuredBootState)(VARIANT_BOOL *pState);
};

OBJECT_ENTRY_AUTO(__uuidof(Manageability_Commands), CManageability_Commands)
