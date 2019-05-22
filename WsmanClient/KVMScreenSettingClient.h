/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
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

#define MAX_DISPLAY_NUMBER_LATEST  4 

struct ScreenSettings
{
	bool isActive;
	int UpperLeftX,UpperLeftY;
	unsigned int ResolutionX,ResolutionY;
	unsigned int Pipe;
};

struct ExtendedDisplayParameters 
{
	ScreenSettings screenSettings[MAX_DISPLAY_NUMBER_LATEST];
};

class WSMAN_DLL_API KVMScreenSettingClient : public BaseWSManClient
{
public:
	KVMScreenSettingClient();
	KVMScreenSettingClient(const std::string &User, const std::string &Password);
	virtual ~KVMScreenSettingClient();

	/*Actual soap actions!*/
	
	bool updateScreenSettings(const ExtendedDisplayParameters &displaySettings, short numOfDisplays);
	bool getScreenSettings (ExtendedDisplayParameters &displaySettings, unsigned char & primary, short numOfDisplays);
	
private:
	bool Init(bool forceGet = false);
	bool m_isInit;
	static const std::string DEFAULT_USER;
	static const std::string DEFAULT_PASS;
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