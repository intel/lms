/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#pragma once


#include "CIM_WiFiEndpointSettings.h"
#include "BaseWSManClient.h"
#include <vector>
#include <memory>

typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings SingleMeProfile;
typedef std::vector<std::shared_ptr<SingleMeProfile>> MeProfileList;

class WSMAN_DLL_API WlanWSManClient : public BaseWSManClient
{

public:

	WlanWSManClient(void);

	virtual ~WlanWSManClient(void);

	bool Enumerate(MeProfileList& wifiSettings);
	bool DeleteProfile(SingleMeProfile& wifiSettings);
	bool AddProfile(SingleMeProfile& settings);
	bool UpdateProfile(SingleMeProfile& settings);

	bool LocalProfileSynchronizationEnabled(bool &enabled);

private:
	bool Init(void);

	bool m_isInit;
};