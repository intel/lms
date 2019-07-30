/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: KVMScreenSettingClient.h

--*/

#ifndef  _KVM_SCREEN_SETTING_CLIENT_H
#define  _KVM_SCREEN_SETTING_CLIENT_H

#include "IPS_KVMRedirectionSettingData.h"
#include "IPS_ScreenSettingData.h"
#include "BaseWSManClient.h"
#include <string>
#include <vector>

class WSMAN_DLL_API KVMScreenSettingClient : public BaseWSManClient
{
public:
	static const unsigned int MAX_DISPLAY_NUMBER = 4;

	KVMScreenSettingClient();
	KVMScreenSettingClient(const std::string &User, const std::string &Password);
	virtual ~KVMScreenSettingClient();

	struct ScreenSettings
	{
		bool isActive;
		int UpperLeftX, UpperLeftY;
		unsigned int ResolutionX, ResolutionY;
		unsigned int Pipe;
	};

	struct ExtendedDisplayParameters
	{
		ScreenSettings screenSettings[MAX_DISPLAY_NUMBER];
	};

	/*Actual soap actions!*/
	
	bool updateScreenSettings(const ExtendedDisplayParameters &displaySettings, short numOfDisplays);
	bool getScreenSettings (ExtendedDisplayParameters &displaySettings, unsigned char & primary, short numOfDisplays);
	
private:
	bool Init(bool forceGet = false);
	bool m_isInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_ScreenSettingData m_service;
	UNLOCK_AFTER;
};

class KVMScreenSettingClientException : public std::exception
{
public:
	KVMScreenSettingClientException(std::string reason) :_reason(reason){}
	virtual const char* what() const noexcept {return _reason.c_str();}
private:
	std::string _reason;
};

#endif // _KVM_SCREEN_SETTING_CLIENT_H