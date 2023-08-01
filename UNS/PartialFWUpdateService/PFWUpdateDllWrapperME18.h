/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2023 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERME18_H_
#define __PFWUPDATEDLLWRAPPERME18_H_

#include "PFWUpdateDllWrapper.h"

class PFWUpdateDllWrapperME18 : public PFWUpdateDllWrapper
{
public:
	PFWUpdateDllWrapperME18();
	~PFWUpdateDllWrapperME18();
	PFWUpdateDllWrapperME18(const PFWUpdateDllWrapperME18&) = delete;
	PFWUpdateDllWrapperME18& operator = (const PFWUpdateDllWrapperME18&) = delete;

	uint32_t waitForFwInitDone();
	uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage);
	uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath);
	
	void printPfwuReturnCode(uint32_t status);

private:
	struct FUNCTIONS;
	FUNCTIONS *functionsPtr;
};

#endif /* __PFWUPDATEDLLWRAPPERME18_H_ */