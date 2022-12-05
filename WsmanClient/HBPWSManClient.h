/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
/*++

@file: HBPWSManClient.h

--*/

#ifndef  _HBP_WSMAN_CLIENT_H
#define  _HBP_WSMAN_CLIENT_H

#include "IPS_HostBasedSetupService.h"
#include "IPS_ClientProvisioningRecord.h"
#include "IPS_TLSProvisioningRecord.h"
#include "IPS_ManualProvisioningRecord.h"
#include "IPS_AdminProvisioningRecord.h"
#include "BaseWSManClient.h"
#include <vector>

class WSMAN_DLL_API HBPWSManClient : public BaseWSManClient
{
public:
	// ProvisioningMethodEnum defined in previous FW mof of IPS_ProvisioningAuditRecord
	//	ValueMap { "0", "1", "2", "3", "4", "5", "6",  ".."},
	//      Values { "Unknown", "Reserved", "Un-provisioned", "TLS-PSK", "TLS-PKI","Host Activated", "Manual", "Reserved"}]
	short ProvisioningMethod_Reserved1 = 1;
	short ProvisioningMethod_Remote = 3;
	short ProvisioningMethod_Host = 5;
	short ProvisioningMethod_Manual = 6;
	short ProvisioningMethod_NotSupported = 100;

	HBPWSManClient();
	virtual ~HBPWSManClient();

	bool GetConfigurationInfo(short* pControlMode,short* pProvisioningMethod,std::string& CreationTimeStamp, std::vector<unsigned char> &ppCertHash);

	bool Init(bool forceGet = false);
private:
	bool m_isInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_HostBasedSetupService m_HostBasedSetupService; //for CurrentFunctionalityLevel(0;1;2)
	Intel::Manageability::Cim::Typed::IPS_ClientProvisioningRecord m_HostProvisioningRecord; //for ProvCertificateHash
	Intel::Manageability::Cim::Typed::IPS_TLSProvisioningRecord m_RemoteProvisioningRecord; //for SelectedHashData(if ProvisioningMethod=TLS-PKI)
	Intel::Manageability::Cim::Typed::IPS_ManualProvisioningRecord m_ManualProvisioningRecord;
	Intel::Manageability::Cim::Typed::IPS_AdminProvisioningRecord m_AdminProvisioningRecord;
	UNLOCK_AFTER;
	bool m_HostBasedSetupServiceGot;
	bool m_HostProvisioningRecordGot;
	bool m_RemoteProvisioningRecordGot;
	bool m_ManualProvisioningRecordGot;
	bool m_AdminProvisioningRecordGot;
};
#endif //_HBP_SOAP_CLIENT_H