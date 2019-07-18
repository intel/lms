/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: AMT_COM_Interface.cpp

--*/

// AMT_COM_Interface.cpp : Implementation of WinMain


#include "stdafx.h"
#include "Dbt.h"
#include "resource.h"
#include "AMT_COM_Interface.h"
#include "DataStorageGenerator.h"
#include "Sddl.h"
#include "Winbase.h"
#include "GmsService.h"
#include "ACEInitializer.h"
#include "global.h"
#include "GMSExternalLogger.h"
#include "DataStorageWrapper.h"

using namespace std;

int RunUNSService(GmsService** gmsSrv);

#include <stdio.h>

const GUID heciGuid = {0xE2D1FF34, 0x3458, 0x49A9, 0x88, 0xDA, 0x8E, 0x69, 0x15, 0xCE, 0x9B, 0xE5};



HRESULT AddRegKeys()
{

	//-----------------------
/*	WCHAR szUserName[257];
	memset(szUserName,0,sizeof(WCHAR)*257);
  //obtain WinBuiltinUsersSid droup name
	DWORD SidSize;
	PSID TheSID;
	LPTSTR p;
	SidSize = SECURITY_MAX_SID_SIZE;
	// Allocate enough memory for the largest possible SID.
	if(!(TheSID = LocalAlloc(LMEM_FIXED, SidSize)))
	{    
		return 1;
	}
	// Create a SID for the Everyone group on the local computer.
	if(!CreateWellKnownSid(WinBuiltinUsersSid, NULL, TheSID, &SidSize))
	{    
		LocalFree(TheSID);
		return 1;
	}
	else
	{
		// Get the string version of the SID (S-1-1-0).
		if(!(ConvertSidToStringSid(TheSID, &p)))
		{
			LocalFree(TheSID);
			return 1;
		}
		else
		{
			DWORD dwUserNameSize = 256, dwDomainNameSize = 15;
			WCHAR  szDomainName[15 + 1];
			SID_NAME_USE snu;
			BOOL bRes;
			bRes = ::LookupAccountSidW(0, TheSID,
				szUserName, &dwUserNameSize, szDomainName,
				&dwDomainNameSize, &snu);

			LocalFree(p);
			LocalFree(TheSID);
		}
	}
*/
	//-----------------------
	DataStorageWrapper& ds = DSinstance();
	if (false == ds.SetDataValue(GetUserInitiatedEnabled_F,L"",true))
		return 1;
 	if (false == ds.SetDataValue(GetKVMRedirectionState_F,L"",true))
		return 1;
 	if (false == ds.SetDataValue(OpenUserInitiatedConnection_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(CloseUserInitiatedConnection_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetIMSSEventHistory_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetAMTVersion_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetLMSVersion_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetHeciVersion_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetProvisioningMode_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetProvisioningTlsMode_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetProvisioningState_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetNetworkConnectionStatus_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(userInitiatedPolicyRuleExists_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(snmpEventSubscriberExists_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(CILAFilterCollectionSubscriptionExists_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(getWebUIState_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetPowerPolicy_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetLastResetReason_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetRedirectionStatus_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetSystemDefenseStatus_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetNetworkSettings_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetSystemUUID_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetIPv6NetworkSettings_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(TerminateKVMSession_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetSpriteLanguage_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(SetSpriteLanguage_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetSpriteZoom_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(SetSpriteZoom_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetSpriteParameters_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(TerminateRemedySessions_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetAuditLogs_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetATDeviceInfo_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetTheFeatureState_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetFeaturesState_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetCustomerType_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetPlatformType_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetMenageabiltyMode_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetConfigurationInfo_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetUserConsentState_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetWLANLinkInfo_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(SetLinkPreferenceToHost_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetFWInfo_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(GetPMCVersion_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(InitiateUserConnection_F,L"",false))
		return 1;
	if (false == ds.SetDataValue(UpdateScreenSettings_F,L"",false)) 
		return 1;
	if (false == ds.SetDataValue(GetRedirectionSessionLinkTechnology_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(IsRebootAfterProvisioningNeeded_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(ProxyAddProxyEntry_F,L"",true))
		return 1;
	if (false == ds.SetDataValue(UserInitiatedPolicyRuleForLocalMpsExists_F,L"",true))
		return 1;

	DWORD val = 0;
	if (false == ds.SetDataValue(LastLanguageUpdate, val, false))
		return 1;

	if (false == ds.DeleteDataVal(NETWORK_TRAFFIC_TX_CEASED_))
		return 1;
	return 0;
}

HRESULT DelRegKeys()
{
	//The following function will remove all the keys the UNS uses
	return DSinstance().CleanDataStorage();
	
}


class CAMT_COM_InterfaceModule : public CAtlServiceModuleT< CAMT_COM_InterfaceModule, IDS_SERVICENAME >
{
private:
	static GmsService* GMSsrv;
	//ACEInitializer Initializer;	// TMP TILL CLOSE FINI ISSUE
public:

	static bool getGmsPortForwardingStarted() {
		return GMSsrv->GetPortForwardingStarted();
	}
	
	DECLARE_LIBID(LIBID_AMT_COM_InterfaceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_AMT_COM_INTERFACE, "{545C8D56-7A88-492D-B38D-559657A3DD4C}")
	HRESULT InitializeSecurity() throw()
	{

		HRESULT rc;
		CSecurityDescriptor sd;
		sd.InitializeFromThreadToken();
		//sd.Allow("NETWORK_SERVICE", COM_RIGHTS_EXECUTE);
		rc = CoInitializeSecurity( sd,
			-1,
			NULL,
			NULL,
			RPC_C_AUTHN_LEVEL_PKT_PRIVACY, 
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE,
			NULL );


		return S_OK;
	}

	static DWORD WINAPI sServiceCtrlHandler(
	DWORD dwControl,
	DWORD dwEventType,
	LPVOID lpEventData,
	LPVOID lpContext)
	{
		return ((CAMT_COM_InterfaceModule*)_pAtlModule)->ServiceCtrlHandler(dwControl, dwEventType, lpEventData, lpContext);
	}

	DWORD WINAPI ServiceCtrlHandler(
	DWORD dwControl,
	DWORD dwEventType,
	LPVOID lpEventData,
	LPVOID lpContext)	
	{
		switch (dwControl) 
		{ 
	  		case SERVICE_CONTROL_SHUTDOWN: 
			case SERVICE_CONTROL_STOP: 			
				GMSsrv->handle_control(dwControl); 
				OnStop();
				break;
			case SERVICE_CONTROL_DEVICEEVENT:
				{
					// Check if the event belong to the MEI driver:
					bool wasOnOurGUID = false;
					wasOnOurGUID = (memcmp(&((PDEV_BROADCAST_DEVICEINTERFACE)lpEventData)->dbcc_classguid,&heciGuid,sizeof(GUID)) == 0);
					if (!wasOnOurGUID && ((dwEventType == DBT_DEVICEARRIVAL) || (dwEventType == DBT_DEVICEREMOVECOMPLETE)))
						break;

					// We must close PortForwardingService's open handle to HECI before returning NO_ERROR for this event
					// Otherwise OS will require reboot if any HECI operation is performed immediately after this function
					if (dwEventType == DBT_DEVICEQUERYREMOVE) 
						GMSsrv->CloseHeciHandle();
					if(dwEventType == DBT_DEVICEARRIVAL)
						GMSsrv->NotifyHeciEnable();

					GMSsrv->handle_control(dwControl,dwEventType, wasOnOurGUID);
				}
				break;
			case SERVICE_CONTROL_SESSIONCHANGE:
				if (dwEventType == WTS_SESSION_UNLOCK)
				{
					GMSsrv->handle_control(dwControl,dwEventType, 0);
				}
				break;
			default:
				GMSsrv->handle_control(dwControl,dwEventType);
				break;
		}
		return NO_ERROR; 
	}

	void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv) throw()
	{
		ACEInitializer Initializer;
		// next lines copied from AtlBase::ServiceMain - because we must use RegisterServiceCtrlHandlerEx
		lpszArgv;
		dwArgc;
		// Register the control request handler
		m_status.dwCurrentState = SERVICE_START_PENDING;
		m_hServiceStatus	= RegisterServiceCtrlHandlerEx( m_szServiceName,sServiceCtrlHandler, NULL);
		if (m_hServiceStatus == NULL)
		{
			LogEvent(_T("Handler not installed"));
			return;
		}

		try
		{
			GmsService *svc = theService::instance();
			if (svc == NULL)
			{
				LogEvent(L"GmsService is not instantiated");
				return;
			}
			svc->SetServiceHandle(m_hServiceStatus);
		}
		catch (...)
		{
			LogEvent(L"GmsService throws exception on init");
			return;
		}
		// Register device notificaion
		DEV_BROADCAST_DEVICEINTERFACE notification;
		ZeroMemory(&notification,sizeof(notification));
		notification.dbcc_size			=	sizeof(DEV_BROADCAST_DEVICEINTERFACE);
		notification.dbcc_devicetype	=	DBT_DEVTYP_DEVICEINTERFACE;
		notification.dbcc_classguid		=	heciGuid;

		HDEVNOTIFY hDevNotify = RegisterDeviceNotification(m_hServiceStatus,&notification,DEVICE_NOTIFY_SERVICE_HANDLE);

		if (hDevNotify == NULL)
		{
			LogEvent(_T("Register Device Notification Failed"));
		}
		m_status.dwWin32ExitCode = S_OK;
		m_status.dwCheckPoint = 0;
		m_status.dwWaitHint = 0;

		CAMT_COM_InterfaceModule* pT = static_cast<CAMT_COM_InterfaceModule*>(this);
#ifndef _ATL_NO_COM_SUPPORT

		HRESULT hr = E_FAIL;
		hr = CAMT_COM_InterfaceModule::InitializeCom();
		if (FAILED(hr))
		{
			// Ignore RPC_E_CHANGED_MODE if CLR is loaded. Error is due to CLR initializing
			// COM and InitializeCOM trying to initialize COM with different flags.
			if (hr != RPC_E_CHANGED_MODE || GetModuleHandle(_T("Mscoree.dll")) == NULL)
			{
				return;
			}
		}
		else
		{
			m_bComInitialized = true;
		}

		m_bDelayShutdown = false;
#endif //_ATL_NO_COM_SUPPORT
		RunUNSService(&GMSsrv);

		// Sara: Add SERVICE_ACCEPT_POWEREVENT before Run() willexceute setServicestatus 
        m_status.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_POWEREVENT | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_SESSIONCHANGE;
		
		// When the Run function returns, the service has stopped.
		m_status.dwWin32ExitCode = pT->Run(SW_HIDE);
		
		if (GMSsrv!=NULL)
		{
			GMSsrv->wait();
			theService::close(); 
		}
		GMSExternalLogger::instance().ServiceStopped(); //should be sent even if LMS was killed by force
#ifndef _ATL_NO_COM_SUPPORT	
		if (m_bService && m_bComInitialized)
			CAMT_COM_InterfaceModule::UninitializeCom();
#endif
		if (!UnregisterDeviceNotification(hDevNotify))
		{
			UNS_DEBUG(L"UnregisterDeviceNotification failed \n");
		}
		SetServiceStatus(SERVICE_STOPPED);
	}

	// override the Run - to check if gmsService stopped before com download
	HRESULT Run(int nShowCmd = SW_HIDE) throw()
	{
		HRESULT hr = S_OK;
		CAMT_COM_InterfaceModule* pT = static_cast<CAMT_COM_InterfaceModule*>(this);

		if (m_bService)
		{
			m_dwThreadID = GetCurrentThreadId();
		}
		hr = pT->PreMessageLoop(nShowCmd);

		while (!GMSsrv->Loading()){}

		if (hr == S_OK && !GMSsrv->GetStopped())
		{
			pT->RunMessageLoop();
		}

		if (SUCCEEDED(hr))
		{
			while (!GMSsrv->GetStopped()){}
			hr = pT->PostMessageLoop();
		}

		return hr;
	}
	
	// override the RegisterServer/UnRegisterServer function for running RegiterNAP

     HRESULT RegisterServer(BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL) throw()
     {
		HRESULT hr = __super::RegisterServer(bRegTypeLib, pCLSID);
		
		// change Display name
		SC_HANDLE hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if (hSCM == NULL)
		{
			TCHAR szBuf[1024];
			if (AtlLoadString(ATL_SERVICE_MANAGER_OPEN_ERROR, szBuf, 1024) == 0)
				Checked::tcscpy_s(szBuf, _countof(szBuf), _T("Could not open Service Manager"));
			MessageBox(NULL, szBuf, _T("LMS"), MB_OK);
			return S_FALSE;
		}
		SC_HANDLE hService = OpenService(hSCM, _T("LMS"),SERVICE_ALL_ACCESS);

		// change Dependencies
		
		::ChangeServiceConfig (
			hService, SERVICE_NO_CHANGE ,SERVICE_AUTO_START , SERVICE_NO_CHANGE ,
			NULL, NULL, NULL, NULL, NULL, NULL, _T("Intel(R) Management and Security Application Local Management Service"));

		// change description
		SERVICE_DESCRIPTION sc;
		sc.lpDescription = _T("Intel(R) Management and Security Application Local Management Service - Provides OS-related Intel(R) ME functionality.");
		::ChangeServiceConfig2(hService,SERVICE_CONFIG_DESCRIPTION , &sc);

		SERVICE_DELAYED_AUTO_START_INFO si;
		si.fDelayedAutostart=true;
		::ChangeServiceConfig2(hService, SERVICE_CONFIG_DELAYED_AUTO_START_INFO, &si);

		
		::CloseServiceHandle(hService);
		::CloseServiceHandle(hSCM);

		AddRegKeys();
        return hr;
	 }

 

	HRESULT UnregisterServer(BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL) throw()
	{
		HRESULT hr = __super::UnregisterServer(bUnRegTypeLib, pCLSID);
		if (FAILED(DelRegKeys()))
		{
			UNS_DEBUG(L"UnregisterServer:: Failed to clean all registry values\n");
		}
		return hr;
	}



};

GmsService * CAMT_COM_InterfaceModule::GMSsrv = NULL;
CAMT_COM_InterfaceModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR lpCmdLine, int nShowCmd)
{
	/**if (lpCmdLine != "") */
	if (_wcsicmp(lpCmdLine,L"")!=0)
	{
		if ((_wcsicmp(lpCmdLine, L"console") == 0)) 
		{
			GmsService* GMSsrv;
			if (RunUNSService(&GMSsrv))
				exit(EXIT_FAILURE);
			Sleep(120000);
			getchar();						
			if (GMSsrv != NULL)
			{
				GMSsrv->stop();
				delete GMSsrv;
			}
		}
	}
    return _AtlModule.WinMain(nShowCmd);
}


bool GetGmsPortForwardingStarted()
{
	return CAMT_COM_InterfaceModule::getGmsPortForwardingStarted();
}
