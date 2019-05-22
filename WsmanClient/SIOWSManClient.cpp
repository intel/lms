/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: SIOWSManClient.cpp

--*/

#include "SIOWSManClient.h"
#include "UNSDebug.h"
#include "WsmanClientCatch.h"

using namespace std;
const std::string SIOWSManClient::DEFAULT_USER = "$$uns";
const std::string SIOWSManClient::DEFAULT_PASS = "$$uns";

using namespace Intel::Manageability::Cim::Typed;

SIOWSManClient::SIOWSManClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS)
{
	m_isInit = false;
	
}

SIOWSManClient::~SIOWSManClient()
{
}

bool SIOWSManClient::SetSpriteLanguage(unsigned short language)
{
	try {
		if (!Init(true))
			return false;
	
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.language(language);
		m_service.Put();
	}
	CATCH_exception_return("SIOWSManClient::SetSpriteLanguage Put")

	return true;
}

bool SIOWSManClient::GetSpriteLanguage(unsigned short *language)
{
	if (!Init(true))
		return false;
	if (m_service.languageExists())
	{
		*language = (m_service.language()); 
		if (*language == SIOWSManClient::DefaultEnglish)
		{
			*language = SIOWSManClient::English;
		}
		return true;
	}
	return false;
}

bool SIOWSManClient::SetSpriteZoom(unsigned short zoom)
{
	try	
	{
		if (!Init(true))
			return false;
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.zoom(zoom); 
		m_service.Put();
	}
	CATCH_exception_return("SIOWSManClient::SetSpriteZoom Put")
	return true;
}

bool SIOWSManClient::GetSpriteZoom(unsigned short *zoom)
{
	if (!Init(true))
		return false;
	if (m_service.zoomExists())
	{
		*zoom = (m_service.zoom()); 
		return true;
	}
	return false;
}

bool SIOWSManClient::GetSpriteParameters(unsigned short *language, unsigned short *zoom)
{
	if (!Init(true))
		return false;
	if (m_service.languageExists() && m_service.zoomExists())
	{
		*language = (m_service.language()); 
		*zoom = (m_service.zoom()); 
		return true;
	}
	return false;
}

bool SIOWSManClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit) return true;
	m_isInit = false;
			

	try {
		if (!m_endpoint)
			SetEndpoint(false);

		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get(); 
		m_isInit = true;
	}
	CATCH_exception("SIOWSManClient::Init")
	return m_isInit;
}

bool SIOWSManClient::SetExpectedLanguage(unsigned short language)
{
	try {
		if (!Init(true))
			return false;
	
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.RequestedLanguage(language);
		m_service.Put();
	}
	CATCH_exception_return("SIOWSManClient::SetExpectedLanguage Put")

	return true;
}

bool SIOWSManClient::GetExpectedLanguage(unsigned short *language)
{
	if (!Init(true))
		return false;

	if (!m_service.RequestedLanguageExists())
		return false;

	*language = (m_service.RequestedLanguage()); 
	return true;
}


	