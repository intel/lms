/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2023 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERME16_H_
#define __PFWUPDATEDLLWRAPPERME16_H_

#include "PFWUpdateDllWrapper.h"

class PFWUpdateDllWrapperME16 : public PFWUpdateDllWrapper
{
public:
	PFWUpdateDllWrapperME16();
	~PFWUpdateDllWrapperME16();
	PFWUpdateDllWrapperME16(const PFWUpdateDllWrapperME16&) = delete;
	PFWUpdateDllWrapperME16& operator = (const PFWUpdateDllWrapperME16&) = delete;

	uint32_t waitForFwInitDone();
	uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage);
	uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath);
	
	void printPfwuReturnCode(uint32_t status);

private:
	struct FUNCTIONS;
	FUNCTIONS *functionsPtr;
};

#endif /* __PFWUPDATEDLLWRAPPERME16_H_ */