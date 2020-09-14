/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: MethProv.Cpp

--*/

//***************************************************************************

//***************************************************************************

#define _WIN32_DCOM

#include <objbase.h>
#include "methprov.h"
#include <process.h>
#include <wbemidl.h>
#include <stdio.h>
//#include "WMIInfrastructure.h"
#include "OOB_Service_WMI_Provider.h"
#include "ME_System_WMI_Provider.h"
#include "Audit_Record_WMI_Provider.h"
#include "AMT_Service_WMI_Provider.h"
#include "ProvisioningCertificateHash_WMI_Provider.h"
#include "EthernetPortSettings_WMI_Provider.h"
#include "Hosted_Service_WMI_Provider.h"
#include "Concrete_Component_WMI_Provider.h"


//***************************************************************************
//
// CMethodPro::CMethodPro
// CMethodPro::~CMethodPro
//
//***************************************************************************

CMethodPro::CMethodPro()
{
    InterlockedIncrement(&g_cObj);
    return;
   
}

CMethodPro::~CMethodPro(void)
{
    InterlockedDecrement(&g_cObj);
    return;
}

//***************************************************************************
//
// CMethodPro::QueryInterface
// CMethodPro::AddRef
// CMethodPro::Release
//
// Purpose: IUnknown members for CMethodPro object.
//***************************************************************************


STDMETHODIMP CMethodPro::QueryInterface(REFIID riid, PPVOID ppv)
{
    *ppv=NULL;

    if (IID_IUnknown==riid || IID_IWbemServices == riid || IID_IWbemProviderInit==riid)
       if(riid== IID_IWbemServices){
          *ppv=(IWbemServices*)this;
       }

       if(IID_IUnknown==riid || riid== IID_IWbemProviderInit){
          *ppv=(IWbemProviderInit*)this;
       }
    

    if (NULL!=*ppv) {
        AddRef();
        return NOERROR;
        }
    else
        return E_NOINTERFACE;
}


STDMETHODIMP_(ULONG) CMethodPro::AddRef(void)
{
    return ++m_cRef;
}

STDMETHODIMP_(ULONG) CMethodPro::Release(void)
{
    ULONG nNewCount = InterlockedDecrement((long *)&m_cRef);
    if (0L == nNewCount)
        delete this;
    
    return nNewCount;
}

/***********************************************************************
*                                                                      *
*CMethodPro::Initialize                                                *
*                                                                      *
*Purpose: This is the implementation of IWbemProviderInit. The method  *
* is need to initialize with CIMOM.                                    *
*                                                                      *
***********************************************************************/
STDMETHODIMP CMethodPro::Initialize(LPWSTR pszUser, LONG lFlags,
                                    LPWSTR pszNamespace, LPWSTR pszLocale,
                                    IWbemServices *pNamespace, 
                                    IWbemContext *pCtx,
                                    IWbemProviderInitSink *pInitSink)
{

  	if(! pNamespace)
	{
	    pInitSink->SetStatus(WBEM_E_FAILED , 0);
	}
	else
	{
		m_pWbemSvcs = pNamespace;
	    m_pWbemSvcs->AddRef();
		pInitSink->SetStatus(WBEM_S_INITIALIZED, 0);
	}

    
    return WBEM_S_NO_ERROR;
}



/************************************************************************
*                                                                       *      
*CMethodPro::ExecMethodAsync                                            *
*                                                                       *
*Purpose: This is the Async function implementation.                    *
*                                                                       *
************************************************************************/

STDMETHODIMP CMethodPro::ExecMethodAsync(const BSTR ObjectPath, const BSTR MethodName, 
            long lFlags, IWbemContext* pCtx, IWbemClassObject* pInParams, 
            IWbemObjectSink* pResponseHandler)
{

	HRESULT hr = S_OK;


	try {
		//CString csMethodName = strMethodName;
		CComPtr<IWbemClassObject> pClass;
		//BSTR Text;
		//if (pInParams != NULL) 
		//{
		//	pInParams->GetObjectText(0, &Text);
		//	CString Stext = Text;
		//	wstring tc ;
		//	tc += 8217;
		//	tc += 8216;
		//	wstring tmp = Stext.GetBuffer();
		//	tmp  = StringUtilsNamespace::wClearChars(tmp,tc);

		//	_Module.logger.Detail(File,LOCATION, _T("ExecMethodAsync"), _T("strObjectPath"),strObjectPath);
		//	_Module.logger.Detail(File,LOCATION, _T("ExecMethodAsync"), _T("Params for Function are"),tmp);
		//	SysFreeString(Text);
		//}
		//else
		//{
		//}

		std::wstring objectPathTmp(ObjectPath);
		std::wstring objectPath = objectPathTmp.substr(0,objectPathTmp.find(L"."));
		CComBSTR cbstr(objectPath.c_str());
		RETURNIF(m_pWbemSvcs->GetObject(cbstr, 0, pCtx, &pClass, NULL));
		if(objectPath.compare(0, std::wstring(L"OOB_Service").length(),L"OOB_Service") == 0 )
			hr = OOB_Service_WMI_Provider::DispatchMethods(MethodName,ObjectPath, m_pWbemSvcs, pClass, pInParams, pResponseHandler);
		if(objectPath.compare(0, std::wstring(L"ME_System").length(),L"ME_System") == 0 )
			hr = ME_System_WMI_Provider::DispatchMethods(MethodName,ObjectPath, m_pWbemSvcs, pClass, pInParams, pResponseHandler);
		if(objectPath.compare(0, std::wstring(L"AMT_Service").length(),L"AMT_Service") == 0 )
			hr = AMT_Service_WMI_Provider::DispatchMethods(MethodName,ObjectPath, m_pWbemSvcs, pClass, pInParams, pResponseHandler);
	}
	catch (...)
	{
		//_Module.logger.Detail(File,LOCATION, _T("ExecMethodAsync"), _T("bad catch"),_T("bad catch"));
	}
	CoUninitialize();
    return hr;
}

SCODE CMethodPro::CreateInstanceEnumAsync( const BSTR RefStr, long lFlags, 
										  IWbemContext *pCtx, IWbemObjectSink FAR* pHandler)
{
	HRESULT hr = S_OK;

	try 
	{

		if(CComBSTR(RefStr) == L"OOB_Service")
			OOB_Service_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"ME_System")
			ME_System_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"AMT_SetupAuditRecord")
			Audit_Record_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"AMT_ProvisioningCertificateHash")
			ProvisioningCertificateHash_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"AMT_EthernetPortSettings")
			EthernetPortSettings_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"AMT_Service")
			AMT_Service_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"CIM_HostedService")
			Hosted_Service_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		else if(CComBSTR(RefStr) == L"CIM_ConcreteComponent")
			Concrete_Component_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
		
		else
		{
			WMIHandleSetStatus(m_pWbemSvcs,pHandler,0);
			//_Module.logger.Error(File,LOCATION, _T("CreateInstanceEnumAsync"), _T("WBEM_E_NOT_SUPPORTED"),_T(""));
		}

		//	ME_System_WMI_Provider::Enumerate(m_pWbemSvcs, pCtx, pHandler);
	}
	catch (...)
	{
		//_Module.logger.Detail(File,LOCATION, _T("CreateInstanceEnumAsync"), _T("bad catch"),_T("bad catch"));

	}
	CoUninitialize();
    return hr;
}


/**
** Name:            CMethodPro::GetObjectAsync()
**
** Description:     The IWbemServices::GetObjectAsync method gets CIM objects. 
**					Information and status are returned to the caller through 
**					the supplied object sink.
**
****************************************************************************/
HRESULT CMethodPro::GetObjectAsync(
								  /*[in] */ const BSTR strClass,
								  /*[in] */ long lFlags,
								  /*[in] */ IWbemContext __RPC_FAR *pCtx,
								  /*[in] */ IWbemObjectSink __RPC_FAR *pResponseHandler)
{

	HRESULT hr = S_OK;
	try 
	{


		//DBCREQUIRE((strClass != NULL),_T("strClass"));

		do
		{

			//_Module.logger.Detail(File,LOCATION, _T("GetObjectAsync"), _T("Params for GetObjectAsync are"),strClass);
			CComPtr<IWbemPath>pParser;
			hr = CoCreateInstance(CLSID_WbemDefPath,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IWbemPath,
				(LPVOID *)&pParser);
			// -- do something

			pParser->SetText(WBEMPATH_CREATE_ACCEPT_ALL,strClass);
			wchar_t className [256];
			unsigned long size = 256;
			pParser->GetClassName(&size,className);

			//if (checkCredentials(className,_T("GetObject"))!= S_OK)
			//{
			//	_Module.logger.Error(File,LOCATION, _T("GetObjectAsync"), className,_T("WBEM_E_ACCESS_DENIED"));
			//	WMIHandleSetStatus(m_pNamespace,pResponseHandler, WBEM_E_ACCESS_DENIED);
			//	break;
			//}

			//_Module.logger.Detail(File,LOCATION, _T("GetObjectAsync"), strClass,_T("WBEM_E_ACCESS_DENIED"));
			if(CComBSTR(className) == L"OOB_Service")
				OOB_Service_WMI_Provider::GetOOB_Service(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if(CComBSTR(className) == L"ME_System")
				ME_System_WMI_Provider::GetME_System(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if(CComBSTR(className) == L"AMT_SetupAuditRecord")
				Audit_Record_WMI_Provider::GetAudit_Record(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if(CComBSTR(className) == L"AMT_ProvisioningCertificateHash")
				ProvisioningCertificateHash_WMI_Provider::Get_Entry(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if(CComBSTR(className) == L"AMT_EthernetPortSettings")
				EthernetPortSettings_WMI_Provider::Get_PortSettings(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if (CComBSTR(className) == L"AMT_Service")
				AMT_Service_WMI_Provider::GetAMT_Service(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if (CComBSTR(className) == L"CIM_HostedService")
				Hosted_Service_WMI_Provider::GetHosted_Service(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else if (CComBSTR(className) == L"CIM_ConcreteComponent")
				Concrete_Component_WMI_Provider::GetConcrete_Component(m_pWbemSvcs,strClass, pCtx, pResponseHandler);
			else
			{
				WMIHandleSetStatus(m_pWbemSvcs,pResponseHandler, WBEM_E_NOT_SUPPORTED);
				//_Module.logger.Error(File,LOCATION, _T("GetObjectAsync"), _T("WBEM_E_NOT_SUPPORTED"),className);
			}

		}while(0);

	}
	//catch (DBCException &e)
	//{
	//	//_Module.logger.Error(File, _T("GetObjectAsync"), _T("DBCException"),e);
	//	WMIHandleSetStatus(m_pNamespace,pResponseHandler, WBEM_E_INVALID_PARAMETER);
	//}
	catch (...)
	{
		//_Module.logger.Error(File,LOCATION, _T("GetObjectAsync"), _T("bad catch"),_T("bad catch"));
		WMIHandleSetStatus(m_pWbemSvcs,pResponseHandler, WBEM_E_CRITICAL_ERROR);
	}
	//_Module.RemoveThread();
	CoUninitialize();

	return 1;

}


