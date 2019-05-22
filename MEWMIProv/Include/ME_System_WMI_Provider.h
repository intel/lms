/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
/*++

@file: ME_System_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"
#include "FWUpdate_Commands.h"

class ME_System_WMI_Provider
{
public:
	static   HRESULT DispatchMethods(
		const BSTR                  strMethodName,
		const BSTR strObjectPath,
		IWbemServices  *pNamespace,
		CComPtr<IWbemClassObject> pClass,
		IWbemClassObject __RPC_FAR* pInParams,
		IWbemObjectSink __RPC_FAR*  pResponseHandler);

	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT GetME_System(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT GetMESystem(
		wstring& fwversion, bool& CryptoFuseEnabled, uint16& val,
		vector<sint16>& OperationalStatus, uint32& type, uint32& segment, 
		uint32& mode, uint32& capabilities, uint32& enabledCapabilities);
private:
	typedef union _MEFWCAPS_SKU_INT
	{
		UINT32   Data;
		struct
		{
			//UINT32   MngFull  :1;
			//UINT32   MngStd  :1;
			UINT32   Amt       :1;
			UINT32   Irwt       :1; //N/A since 8.0
			UINT32   Qst        :1; //N/A since 8.0
			UINT32   Tdt         :1;
			UINT32   SoftCreek   :1;
			UINT32   Ve          :1;
			UINT32   Dt          :1; //N/A since 8.0
			UINT32   Nand      :1;
			UINT32   Mpc        :1; //N/A since 8.0
			UINT32   IccOverClockin :1; 
			UINT32   Pav              :1; 
			UINT32   Spk              :1;//N/A since 8.0
			UINT32   Rca              :1;//N/A since 8.0
			UINT32   Rpat             :1;   //N/A since 8.0   
			//UINT32   RpatCon          :1;   // To be removed
			UINT32   Ipv6             :1;
			UINT32   Kvm              :1; 
			UINT32   Och              :1; 
			UINT32   Vlan             :1; //N/A since 8.0
			UINT32   Tls             :1;
			UINT32   Cila             :1;
			UINT32	 StdMng			  :1;
			UINT32	 L3				  :1;
			UINT32	 DAL			  :1;
			UINT32	 SBT			  :1;
			UINT32   Reserved2        :8;   
		}Fields;
	}MEFWCAPS_SKU_INT;

	typedef union _ME_PLATFORM_TYPE
{
   UINT32    Data;
   struct
   {
	  UINT32   Mobile:  1;  //0
      UINT32   Desktop: 1; 
      UINT32   Server:  1;
      UINT32   WorkStn:  1;
      UINT32   Corporate: 1;
      UINT32   Consumer: 1;
      UINT32   SuperSKU: 1;
	  UINT32   Rsvd:     1;
	  UINT32   ImageType: 4; // enum {NoME, IGN_FW,ME_LITE,ME_FULL_4MB,ME_FULL_8MB}
	  UINT32   Brand:     4; // enum {NoBrand,BrandAMT,BrandStdMng,BrandL3,BrandRpat}
      UINT32   Rsvd1:    16;
   }Fields;
}ME_PLATFORM_TYPE;


		typedef enum PLATFORM_TYPE {
		MOBILE,
		DESKTOP,
		SERVER,
		WORKSTATION
	} PLATFORM_TYPE;

	typedef enum CUSTOMER_TYPE {
		CORPORATE,
		CONSUMER
	} CUSTOMER_TYPE;

	typedef enum MANAGEABILTY_MODE {
		NONE,
		NOT_KNOWN,
		VPRO,
		STANDARD,
		L3,
		SBT
	} MENAGEABILTY_MODE;

	typedef enum FEATURES {
		AMT = 0,
		IRWT,
		QST,
		TDT,
		SOFTCREEK,
		VE,
		DT,
		NAND,
		MPC,
		ICC_OVER_CLOCK_IN,
		PAV,
		SPK,
		RCA,
		RPAT,
		IPV6,
		KVM,
		OCH,
		VLAN,
		TLS,
		CILA,
		FEATURES_NUM
	} FEATURES;

	static CUSTOMER_TYPE GetPlatformTypeExt(const Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE * Platform);



	static   HRESULT getLastMEResetReason(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static HRESULT getCurrentPowerPolicy(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static HRESULT IsFirmwareUpdateEnabled(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT getFwUpdateOverrideParams(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);
	static HRESULT getCapabilitiesStrings(
		IWbemClassObject*              pClass,
		IWbemClassObject __RPC_FAR*    pInParams,
		IWbemObjectSink  __RPC_FAR*    pResponseHandler,
		IWbemServices*                 pNamespace);

	static HRESULT MenageabiltyModeLogic(
		Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI		    CapabilityData, 
		Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI		    StateData, 
		Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE	        platform, 
		MENAGEABILTY_MODE&	pMode);

	static uint32 GetCapabilities_int(
		Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI		CapabilityData, 
		Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE      Platform);

	static void GetCapabilities(
		MEFWCAPS_SKU_INT CapabilityData,
		vector<wstring>& capabilities);

	static void GetWString(
		UINT		id, 
		wstring& wstr);

};
