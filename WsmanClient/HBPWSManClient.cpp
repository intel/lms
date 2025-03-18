/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2025 Intel Corporation
 */
/*++

@file: HBPWSManClient.cpp

--*/

#include "HBPWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"
#include <sstream>

HBPWSManClient::HBPWSManClient(unsigned int port) :
	BaseWSManClient(port), m_isInit(false), m_HostBasedSetupServiceGot(false), m_HostProvisioningRecordGot(false),
	m_RemoteProvisioningRecordGot(false), m_ManualProvisioningRecordGot(false), m_AdminProvisioningRecordGot(false)
{
}

HBPWSManClient::~HBPWSManClient()
{
}

std::string toUNSDateFormat(const std::string &xml)
{
	if (!xml.empty())
	{
		size_t pos = xml.find_first_of('>');
		std::string tmp = xml.substr(pos+1);
		pos = tmp.find('<');
		return tmp.substr(0, pos);
	}
	return "";
}

bool HBPWSManClient::GetConfigurationInfo(short* pControlMode, short* pProvisioningMethod, std::string& CreationTimeStamp, std::vector<unsigned char> &ppCertHash)
{
	if (!Init(true))
		return false;
	try 
	{	
		if (m_HostBasedSetupServiceGot && m_HostBasedSetupService.CurrentControlModeExists())
			*pControlMode = (m_HostBasedSetupService.CurrentControlMode());
		else
			*pControlMode = 100;

		if (m_HostProvisioningRecordGot)
		{
			if (m_HostProvisioningRecord.ProvCertificateHashExists())
			{
				Intel::Manageability::Cim::Utils::Base64 data = m_HostProvisioningRecord.ProvCertificateHash();
				ppCertHash.resize(data.Length());
				std::stringstream stream;
				stream << "CertificateHash len = " << data.Length() << " data: ";
				for (unsigned int i = 0; i < data.Length(); i++)
				{
					ppCertHash[i] = data.Data()[i];
					stream << " " << std::hex << (unsigned int)data.Data()[i];
				}
				WSMAN_DEBUG("%C\n", stream.str().c_str());
			}
			else
			{
				ppCertHash.resize(0);
			}
			if (m_HostProvisioningRecord.CreationTimeStampExists())
			{
				CreationTimeStamp = toUNSDateFormat(m_HostProvisioningRecord.CreationTimeStamp().Serialize());
			}
			*pProvisioningMethod = ProvisioningMethod_Host;
		}
		else
		{
			if (m_RemoteProvisioningRecordGot && m_RemoteProvisioningRecord.CreationTimeStampExists())
			{
				
				CreationTimeStamp = toUNSDateFormat(m_RemoteProvisioningRecord.CreationTimeStamp().Serialize());
				*pProvisioningMethod = ProvisioningMethod_Remote;
				if (m_RemoteProvisioningRecord.SelectedHashDataExists())
				{
					Intel::Manageability::Cim::Utils::Base64 data = m_RemoteProvisioningRecord.SelectedHashData();
					ppCertHash.resize(data.Length());
					std::stringstream stream;
					stream << "CertificateHash len = " << data.Length() << " data: ";
					for (unsigned int i = 0; i < data.Length(); i++)
					{
						ppCertHash[i] = data.Data()[i];
						stream << " " << std::hex << (unsigned int)data.Data()[i];
					}
					WSMAN_DEBUG("%C\n", stream.str().c_str());
				}
				else
				{
					ppCertHash.resize(0);
				}
			}
			else
			{
				if (m_ManualProvisioningRecordGot)
				{
					if (m_ManualProvisioningRecord.CreationTimeStampExists())
					{
						CreationTimeStamp = toUNSDateFormat(m_ManualProvisioningRecord.CreationTimeStamp().Serialize());
					}
					*pProvisioningMethod = ProvisioningMethod_Manual;
					ppCertHash.resize(0);
				}
				else
				{
					if (m_AdminProvisioningRecordGot)
					{
						if (m_AdminProvisioningRecord.CreationTimeStampExists())
						{
							CreationTimeStamp = toUNSDateFormat(m_AdminProvisioningRecord.CreationTimeStamp().Serialize());
						}
						*pProvisioningMethod = ProvisioningMethod_Reserved1; //Admin;
						ppCertHash.resize(0);
						WSMAN_DEBUG("AdminProvisioningRecord CreationTimeStamp=%C\n", CreationTimeStamp.c_str());
					}
					else
					{
						ppCertHash.resize(0);
						CreationTimeStamp = "";
						*pProvisioningMethod = ProvisioningMethod_NotSupported;
					}
				}
			}
		}
		return true;
	}
	CATCH_exception("HBPWSManClient::GetConfigurationInfo")

	return false;
}

bool HBPWSManClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit) 
		return true;
	m_isInit = false;
	
	try 
	{			
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_HostBasedSetupService.WsmanClient(m_client.get());
		m_HostBasedSetupService.Get();	  // CurrentFunctionalityLevel (Not provisioned: 0, Default: 1, Advanced: 2)
		m_HostBasedSetupServiceGot = true;

		m_isInit = true;
	}
	CATCH_exception_return("HBPWSManClient::Init get m_HostBasedSetupService.Get")

	// connected

	if ((m_HostBasedSetupService.CurrentControlMode() == 1) || //Default(Client): 1
		(m_HostBasedSetupService.CurrentControlMode() == 2))   //Advanced(Admin): 2
	{
		// provisioned

		// try RemoteProvisioningRecord
		try 
		{	
			//Lock WsMan to prevent reentry
			std::lock_guard<std::mutex> lock(WsManSemaphore());
			m_RemoteProvisioningRecord.WsmanClient(m_client.get());
			m_RemoteProvisioningRecord.Get(); // for CreationTimeStamp from cast to ProvisioningAuditRecord
			m_RemoteProvisioningRecordGot = true;
		}
		CATCH_exception_debug("HBPWSManClient::Init get m_RemoteProvisioningRecord.Get -- no TLS")

		if (!m_RemoteProvisioningRecordGot)
		{
			// try HostProvisioningRecord
			try 
			{
				//Lock WsMan to prevent reentry
				std::lock_guard<std::mutex> lock(WsManSemaphore());
				m_HostProvisioningRecord.WsmanClient(m_client.get());
				m_HostProvisioningRecord.Get(); 
				m_HostProvisioningRecordGot = true;
			}
			CATCH_exception_debug("HBPWSManClient::Init get m_HostProvisioningRecord.Get")

			if (!m_HostProvisioningRecordGot)
			{
				// try ManualProvisioningRecord
				try {		
					//Lock WsMan to prevent reentry
					std::lock_guard<std::mutex> lock(WsManSemaphore());
					m_ManualProvisioningRecord.WsmanClient(m_client.get());
					m_ManualProvisioningRecord.Get(); 
					m_ManualProvisioningRecordGot = true;
				}
				CATCH_exception_debug("HBPWSManClient::Init get m_ManualProvisioningRecord.Get")

				if (!m_ManualProvisioningRecordGot)
				{
					// try AdminProvisioningRecord
					try {	
						//Lock WsMan to prevent reentry
						std::lock_guard<std::mutex> lock(WsManSemaphore());
		
						m_AdminProvisioningRecord.WsmanClient(m_client.get());
						m_AdminProvisioningRecord.Get(); 
						m_AdminProvisioningRecordGot = true;
						WSMAN_DEBUG("m_AdminProvisioningRecord.Get succeed\n");
					}
					CATCH_exception_debug("HBPWSManClient::Init get m_AdminProvisioningRecordGet")
				}
			}
		}
	}
	//else
		// not provisioned

	return true;
}