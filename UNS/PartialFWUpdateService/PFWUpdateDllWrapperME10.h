/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERME10_H_
#define __PFWUPDATEDLLWRAPPERME10_H_

#include "PFWUpdateDllWrapperLegacy.h"

class PFWUpdateDllWrapperME10 : public PFWUpdateDllWrapperLegacy
{
public:
	PFWUpdateDllWrapperME10();
	~PFWUpdateDllWrapperME10();
	
	uint32_t waitForFwInitDone();
	uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage);
	uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath);
	
private:
	struct FUNCTIONS;
	FUNCTIONS *functionsPtr;

	uint32_t isFwInitDone(bool* isFwInitDone);
};

#endif /* __PFWUPDATEDLLWRAPPERME10_H_ */
