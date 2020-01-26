/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: SIOWSManClient.h

--*/

#ifndef  _SIO_WSMAN_CLIENT_H
#define  _SIO_WSMAN_CLIENT_H

#include "IPS_SecIOService.h"
#include "BaseWSManClient.h"

class WSMAN_DLL_API SIOWSManClient : public BaseWSManClient
{
public:
	SIOWSManClient();
	virtual ~SIOWSManClient();

	/*Actual soap actions!*/
	
	bool GetSpriteLanguage(unsigned short *language);
	bool SetSpriteZoom(unsigned short zoom);
	bool GetSpriteParameters(unsigned short *language, unsigned short *zoom);
	bool GetExpectedLanguage(unsigned short *language);
	bool SetExpectedLanguage(unsigned short language);
	
	bool Init(bool forceGet = false);
	enum LanguageId
	{
		English				= 0,
		French				= 1,
		German				= 2,
		Chinese_Traditional	= 3,
		Gapanese			= 4,
		Russian				= 5,
		Italian				= 6,
		Spanish				= 7,
		Portuguese_Brazil	= 8,
		Korean				= 9,
		Chinese_Simplified	= 10,
		Arabic				= 11,
		Czech				= 12,
		Danish				= 13,
		Greek				= 14,
		Finnish				= 15,
		Hebrew				= 16,
		Hungarian			= 17,
		Dutch				= 18,
		Norwegian			= 19,
		Polish				= 20,
		Portuguese_Portugal = 21,
		Slovak				= 22,
		Slovenian			= 23,
		Swedish				= 24,
		Thai				= 25,
		Turkish				= 26,
		DefaultEnglish		= 65535
	};
private:
	bool m_isInit;

	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_SecIOService m_service;	
	UNLOCK_AFTER;
};

#endif //_SIO_SOAP_CLIENT_H