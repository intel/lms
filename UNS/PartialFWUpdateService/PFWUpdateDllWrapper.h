/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2022 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPER_H_
#define __PFWUPDATEDLLWRAPPER_H_

#include <string>
#include "global.h"

#ifndef FPUPUBLIC_LMS_QUOTE
#define FPUPUBLIC_LMS_QUOTE(s) #s 
#endif

#define FPUPUBLIC_LMS_NAME_MACRO(x) FPUPUBLIC_LMS_QUOTE(x)

const unsigned int WOCD_ID = 0x444f4357;
const unsigned int LOCL_ID = 0x4C434F4C;

class PFWUpdateDllWrapper 
{
public:
	virtual uint32_t waitForFwInitDone() = 0;
	virtual uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage) = 0;
	virtual uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath) = 0;
	
	virtual void printPfwuReturnCode(uint32_t status) = 0; 
};

#endif /* __PFWUPDATEDLLWRAPPER_H_ */
