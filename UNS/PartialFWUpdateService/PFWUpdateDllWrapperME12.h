/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERME12_H_
#define __PFWUPDATEDLLWRAPPERME12_H_

#include "PFWUpdateDllWrapper.h"

class PFWUpdateDllWrapperME12 : public PFWUpdateDllWrapper
{
public:
	PFWUpdateDllWrapperME12();
	~PFWUpdateDllWrapperME12();
	
	uint32_t waitForFwInitDone();
	uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage);
	uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath);
	
	void printPfwuReturnCode(uint32_t status);

private:
	struct FUNCTIONS;
	FUNCTIONS *functionsPtr;
};

#endif /* __PFWUPDATEDLLWRAPPERME12_H_ */
