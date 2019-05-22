/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "AMTEthernetPortSettingsClient.h"
#include "AMT_EthernetPortSettings.h"

using namespace Intel::Manageability::Cim::Typed;
using namespace std;


class Mock_AMT_EthernetPortSettings : public AMT_EthernetPortSettings {
public:

	MOCK_METHOD1(SetLinkPreference, unsigned int(const SetLinkPreference_INPUT &input));
	MOCK_METHOD0(LinkControlExists, bool());
	MOCK_METHOD0(LinkPreferenceExists, bool());
	MOCK_METHOD0(LinkControl, const unsigned int());
	MOCK_METHOD0(LinkPreference, const unsigned int());
	
};