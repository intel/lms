/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: KVMScreenSettingClient.cpp

--*/

#include "KVMScreenSettingClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

KVMScreenSettingClient::KVMScreenSettingClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

KVMScreenSettingClient::~KVMScreenSettingClient()
{
}

bool KVMScreenSettingClient::updateScreenSettings(const ExtendedDisplayParameters &displaySettings, unsigned short numOfDisplays)
{
	try
	{
		if (!Init())
			return false;

		std::lock_guard<std::mutex> lock(WsManSemaphore()); //Lock WsMan to prevent reentry
		unsigned short i = 0;
		
		std::vector<bool> isActive(MAX_DISPLAY_NUMBER);
		std::vector<int> positionX(MAX_DISPLAY_NUMBER);
		std::vector<int> positionY(MAX_DISPLAY_NUMBER);
		std::vector<unsigned int> resolutionX(MAX_DISPLAY_NUMBER);
		std::vector<unsigned int> resolutionY(MAX_DISPLAY_NUMBER);
	
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