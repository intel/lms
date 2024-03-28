/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: AMTEthernetPortSettingsClient.cpp

--*/

#include "AMTEthernetPortSettingsClient.h"
#include "AMT_EthernetPortSettings.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

AMTEthernetPortSettingsClient::AMTEthernetPortSettingsClient(unsigned int port) :
	BaseWSManClient(port), m_isInit(false), m_isLink(false), m_LinkControl(0), m_LinkPreference(0), m_LinkProtection(5)
{
}

AMTEthernetPortSettingsClient::~AMTEthernetPortSettingsClient()
{
}

bool AMTEthernetPortSettingsClient::Init(bool forceGet, bool actionGet)
{
	if (!forceGet && m_isInit) return true;
	m_isInit = false;
	m_isLink = false;
	

	try 
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		using Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings;

		std::vector<std::shared_ptr<AMT_EthernetPortSettings>> ethernetSettings;
		std::vector<std::shared_ptr<AMT_EthernetPortSettings>>::iterator settingsIterator;
		ethernetSettings = AMT_EthernetPortSettings::Enumerate(m_client.get());
	
		for (settingsIterator = ethernetSettings.begin(); 
			 settingsIterator != ethernetSettings.end() ; 
			 settingsIterator++)
		{	
			AMT_EthernetPortSettings *currSetting = settingsIterator->get();
			if (!currSetting)
				continue;
			if (actionGet)
			{
				if ((currSetting->LinkControlExists()) &&
					(currSetting->LinkPreferenceExists()) )
				{
					m_LinkControl = currSetting->LinkControl();
					m_LinkPreference = currSetting->LinkPreference();
					m_isLink = true;
				}
				if(currSetting->WLANLinkProtectionLevelExists())
				{
					m_LinkProtection = currSetting->WLANLinkProtectionLevel();
					if(m_LinkProtection == 0)
						m_LinkProtection = 1;
				}
				m_isInit = true;
			}
			else // action Set
			{				
				try 
				{	
					AMT_EthernetPortSettings::SetLinkPreference_INPUT inputLinkVal;
					inputLinkVal.LinkPreference(m_LinkPreference);
					currSetting->SetLinkPreference(inputLinkVal);
					m_isInit = true;
				}
				CATCH_exception("AMTEthernetPortSettingsClient::Init Put")
			}
		}
		m_endpoint = true;
		return m_isInit;
	}
	CATCH_exception("AMTEthernetPortSettingsClient::Init")
	m_endpoint = false;
	return false;
}

bool AMTEthernetPortSettingsClient::GetAMTEthernetPortSettings(unsigned int* pLinkPreference, unsigned int* pLinkControl, unsigned int* pLinkProtection, bool* pIsLink)
{	
	if (!Init(true,true))
		return false;

	WSMAN_DEBUG("GetAMTEthernetPortSettings LinkPreference=%d LinkControl=%d LinkProtection=%d\n",
		m_LinkPreference,m_LinkControl,m_LinkProtection);
	*pLinkPreference=m_LinkPreference;
	*pLinkControl=m_LinkControl;
	*pLinkProtection=m_LinkProtection;
	*pIsLink=m_isLink;

	return true;
}

bool AMTEthernetPortSettingsClient::SetLinkPreference(unsigned int LinkPreference)
{
	m_LinkPreference = LinkPreference;
	if (!Init(true,false))
		return false;	
	return true;
}
