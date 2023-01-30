/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: Manageability_Commands_BE.h

--*/

#include "DataInterfaceBackend.h"
#include <string>
#include <vector>

namespace Intel {
	namespace LMS {
		class Manageability_Commands_BE : Common_BE
		{
		public:
			Manageability_Commands_BE(unsigned int port);

			LMS_ERROR GetTheFeatureState(FEATURES feat, FEATURE_STATE& pState);
			LMS_ERROR GetFeaturesState(std::vector<FEATURE_STATE> &ppStates);
			LMS_ERROR GetCustomerType(CUSTOMER_TYPE& pType);
			LMS_ERROR GetMenageabiltyMode(MENAGEABILTY_MODE& pMode);
			LMS_ERROR GetFWInfo(std::string &pMEBxVersion, unsigned long &pBiosBootState, bool &pCryptoFuseEnable, bool &pLocalFWupdateEnable);
			LMS_ERROR GetPMCVersion(std::string &pFwVer);
			LMS_ERROR IsMeasuredBootState(bool &pState);
		};
	}
}
