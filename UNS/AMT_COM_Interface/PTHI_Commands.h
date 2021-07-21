/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2021 Intel Corporation
 */
/*++

@file: PTHI_Commands.h

--*/

// PTHI_Commands.h : Declaration of the CPTHI_Commands

#pragma once
#include "resource.h"       // main symbols
#include "AMT_COM_Interface.h"
#include "AMTHICommand.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CPTHI_Commands

class ATL_NO_VTABLE CPTHI_Commands :
	public ATL::CComObjectRootEx<ATL::CComMultiThreadModel>,
	public ATL::CComCoClass<CPTHI_Commands, &CLSID_PTHI_Commands>,
	public ATL::IDispatchImpl<IPTHI_Commands, &IID_IPTHI_Commands, &LIBID_AMT_COM_InterfaceLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPTHI_Commands()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PTHI_COMMANDS)


BEGIN_COM_MAP(CPTHI_Commands)
	COM_INTERFACE_ENTRY(IPTHI_Commands)
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
	STDMETHOD(GetAMTVersion)(BSTR* AMTVersion);
	STDMETHOD(GetLMSVersion)(BSTR* sVersion);
	STDMETHOD(GetHeciVersion)(BSTR* sVersion);
	STDMETHOD(GetProvisioningMode)(SHORT* pProvisioningMode);
	STDMETHOD(GetProvisioningTlsMode)(SHORT* pProvisioningTlsMode);
	STDMETHOD(GetProvisioningState)(SHORT* pProvisioningState);
	STDMETHOD(GetNetworkConnectionStatus)(SHORT* pStatus, SHORT* pConnectionType, SHORT* pConnectionTrigger);
	STDMETHOD(userInitiatedPolicyRuleExists)(SHORT* pStatus);
	STDMETHOD(userInitiatedPolicyRuleForLocalMpsExists)(SHORT* pStatus);
	STDMETHOD(snmpEventSubscriberExists)(SHORT* pStatus);
	STDMETHOD(CILAFilterCollectionSubscriptionExists)(SHORT* pStatus);
	STDMETHOD(GetUserInitiatedEnabled)(SHORT* pStatus);
	STDMETHOD(getWebUIState)(SHORT*  pState);
	STDMETHOD(GetPowerPolicy)(BSTR* bstrPolicy);
	STDMETHOD(GetLastResetReason)(SHORT* pReason);
	STDMETHOD(GetRedirectionStatus)(SHORT* pSOL, SHORT* pIDER);
	STDMETHOD(GetSystemDefenseStatus)(SHORT* pStatus);
	STDMETHOD(GetNetworkSettings)(SHORT ConnectionType /*WIRED=0, WIRELESS=1*/,
												SHORT* pDhcpEnabled ,// Both
												BSTR*  bstrIpAddress,//Both
												BSTR*  bstrMacAddress,//Both
												SHORT* pLinkStatus, //Both
												SHORT* pWirelessControl,// WIRELESS
												SHORT* pWirelessConfEnabled); //WIRELESS
	STDMETHOD(GetIPv6NetworkSettings) (SHORT ConnectionType /*WIRED, WIRELESS*/,
										BSTR* IPv6DefaultRouter,
										BSTR* PrimaryDNS,
										BSTR* SecondaryDNS,
										VARIANT* pResponse, //IPv6 Addresses
										VARIANT_BOOL* pIpv6Enable); 
	STDMETHOD(GetSystemUUID)(BSTR* bstrUUID);
	STDMETHOD(OpenUserInitiatedConnection)(void);
	STDMETHOD(CloseUserInitiatedConnection)(void);
	STDMETHOD(TerminateKVMSession)(void);
	STDMETHOD(GetKVMRedirectionState)(VARIANT_BOOL* pEnabled,VARIANT_BOOL* pConnected);

	STDMETHOD(GetSpriteLanguage)(SHORT* pLanguag);
	STDMETHOD(SetSpriteLanguage)(SHORT Language);
	STDMETHOD(GetSpriteZoom)(SHORT* pZoom);
	STDMETHOD(SetSpriteZoom)(SHORT Zoom);
	STDMETHOD(GetSpriteParameters)(SHORT* pLanguage, SHORT* pZoom);
	STDMETHOD(GetConfigurationInfo)(SHORT* pControlMode,SHORT* pProvisioningMethod,BSTR* pCreationTimeStamp,SAFEARRAY** pCertHash);
	STDMETHOD(TerminateRemedySessions)(void);
	STDMETHOD(GetUserConsentState)(SHORT* pState, USER_CONSENT_POLICY* pPolicy);
	STDMETHOD(GetWLANLinkInfo)(UINT* pPreference, UINT* pControl, UINT* pProtection);
	STDMETHOD(SetLinkPreferenceToHost)(void);
	STDMETHOD(InitiateUserConnection)(SHORT* pStatus);
	STDMETHOD(UpdateScreenSettings)(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters);
	STDMETHOD(UpdateScreenSettings2)(EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters, SHORT numOfDisplays);
	STDMETHOD(GetRedirectionSessionLinkTechnology)(REDIRECTION_SESSION_TYPE sessionType , SHORT* pLinkTechnology);
	STDMETHOD(IsRebootAfterProvisioningNeeded)(VARIANT_BOOL *pNeeded);
	STDMETHOD(ProxyAddProxyEntry)( BSTR			proxy_fqdn, 
								   USHORT		proxy_port,
								   SAFEARRAY*	gateway_mac_address,
								   BSTR			network_dns_suffix);
	STDMETHOD(GetPlatformServiceRecord)(BSTR* bstrPSR);
	STDMETHOD(GetPlatformServiceRecordRaw)(SAFEARRAY** binPSR);
	STDMETHOD(GetUPIDFeatureState)(VARIANT_BOOL* pState);
	STDMETHOD(SetUPIDFeatureState)(VARIANT_BOOL State);
};

OBJECT_ENTRY_AUTO(__uuidof(PTHI_Commands), CPTHI_Commands)
