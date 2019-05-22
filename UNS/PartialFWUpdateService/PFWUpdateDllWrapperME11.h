/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERME11_H_
#define __PFWUPDATEDLLWRAPPERME11_H_

#include "PFWUpdateDllWrapperLegacy.h"

class PFWUpdateDllWrapperME11 : public PFWUpdateDllWrapperLegacy
{
public:
	PFWUpdateDllWrapperME11();
	~PFWUpdateDllWrapperME11();
	
	uint32_t waitForFwInitDone();
	uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage);
	uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath);
	
private:
	struct FUNCTIONS;
	FUNCTIONS *functionsPtr;

	uint32_t isFwInitDone(bool* isFwInitDone);
};

#endif /* __PFWUPDATEDLLWRAPPERME11_H_ */
