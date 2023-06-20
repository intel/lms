/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */

#ifndef _WLAN_WSMAN_CLIENT_H
#define _WLAN_WSMAN_CLIENT_H

#include "CIM_WiFiEndpointSettings.h"
#include "BaseWSManClient.h"
#include <vector>
#include <memory>

typedef Intel::Manageability::Cim::Typed::CIM_WiFiEndpointSettings SingleMeProfile;
typedef std::vector<std::shared_ptr<SingleMeProfile>> MeProfileList;

class WlanWSManClient : public BaseWSManClient
{
public:

	WlanWSManClient(unsigned int port);

	virtual ~WlanWSManClient(void);

	bool Enumerate(MeProfileList& wifiSettings);
	bool DeleteProfile(SingleMeProfile& wifiSettings);
	unsigned int AddProfile(SingleMeProfile& settings);
	unsigned int UpdateProfile(SingleMeProfile& settings);

	bool LocalProfileSynchronizationEnabled(bool &enabled);

private:
	bool Init(void);

	bool m_isInit;
};
#endif // _WLAN_WSMAN_CLIENT_H