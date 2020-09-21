/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: KVMScreenSettingClient.cpp

--*/

#include "KVMScreenSettingClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

KVMScreenSettingClient::KVMScreenSettingClient() : m_isInit(false)
{
}

KVMScreenSettingClient::KVMScreenSettingClient(const std::string &User, const std::string &Password) :
	BaseWSManClient(User, Password), m_isInit(false)
{
}

KVMScreenSettingClient::~KVMScreenSettingClient()
{
}

bool KVMScreenSettingClient::updateScreenSettings(const ExtendedDisplayParameters &displaySettings, short numOfDisplays)
{
	try 
	{
		if (!Init())
			return false;

		std::lock_guard<std::mutex> lock(WsManSemaphore()); 		//Lock WsMan to prevent reentry
		short i = 0;
		
		std::vector<bool> isActive(numOfDisplays);
		std::vector<int> positionX(numOfDisplays);
		std::vector<int> positionY(numOfDisplays);
		std::vector<unsigned int> resolutionX(numOfDisplays);
		std::vector<unsigned int> resolutionY(numOfDisplays);
	
		for (i = 0 ; i < numOfDisplays ; i++)
		{
			WSMAN_DEBUG("adding %d, isActive:%d,UpperLeftX:%d,UpperLeftY:%d,ResolutionX:%d,ResolutionY:%d, pipe:%d \n",
				i,displaySettings.screenSettings[i].isActive,displaySettings.screenSettings[i].UpperLeftX,
				displaySettings.screenSettings[i].UpperLeftY,displaySettings.screenSettings[i].ResolutionX,
				displaySettings.screenSettings[i].ResolutionY,displaySettings.screenSettings[i].Pipe);
			isActive[i]=displaySettings.screenSettings[i].isActive;
			positionX[i]=displaySettings.screenSettings[i].UpperLeftX;
			positionY[i]=displaySettings.screenSettings[i].UpperLeftY;
			resolutionX[i]=displaySettings.screenSettings[i].ResolutionX;
			resolutionY[i]=displaySettings.screenSettings[i].ResolutionY;

			if (i == 0)
				m_service.PrimaryIndex(displaySettings.screenSettings[i].Pipe);
			if (i == 1)
				m_service.SecondaryIndex(displaySettings.screenSettings[i].Pipe);
			if (i == 2)
				m_service.TertiaryIndex(displaySettings.screenSettings[i].Pipe);
			if (i == 3)
				m_service.QuadraryIndex(displaySettings.screenSettings[i].Pipe);
		}	
		m_service.IsActive(isActive);
		m_service.UpperLeftX(positionX);
		m_service.UpperLeftY(positionY);		
		m_service.ResolutionX(resolutionX);
		m_service.ResolutionY(resolutionY);
		m_service.Put();
	}
	CATCH_exception_return("KVMScreenSettingClient::updateScreenSettings")
	return true;
}

bool  KVMScreenSettingClient::getScreenSettings (ExtendedDisplayParameters &displaySettings, unsigned char & primary, short numOfDisplays)
{
	try 
	{
		if (!Init())
			return false;

		primary = m_service.PrimaryIndex();
		const std::vector<bool> isActive = m_service.IsActive();
		const std::vector<int> UpperLeftX = m_service.UpperLeftX();
		const std::vector<int> UpperLeftY = m_service.UpperLeftY();
		const std::vector<unsigned int> ResolutionX = m_service.ResolutionX();
		const std::vector<unsigned int> ResolutionY = m_service.ResolutionY();

		for (short i=0; i<numOfDisplays; i++)
		{
			displaySettings.screenSettings[i].isActive = isActive[i];
			displaySettings.screenSettings[i].ResolutionX = ResolutionX[i];
			displaySettings.screenSettings[i].ResolutionY = ResolutionY[i];
			displaySettings.screenSettings[i].UpperLeftX = UpperLeftX[i];
			displaySettings.screenSettings[i].UpperLeftY= UpperLeftY[i];
		}
		return true;
	}
	CATCH_exception_return("KVMScreenSettingClient::getScreenSettings")
}

bool KVMScreenSettingClient::Init(bool forceGet)
{
	WSMAN_DEBUG("KVMScreenSettingClient::Init\n");
	if (!forceGet && m_isInit) return true;
	m_isInit = false;
	

	try 
	{
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();
		m_isInit = true;
		WSMAN_DEBUG("KVMScreenSettingClient::Initialized\n");
	}
	CATCH_exception("KVMScreenSettingClient::Init")
	return m_isInit;	
}