/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPER_H_
#define __PFWUPDATEDLLWRAPPER_H_

#include <string>
#include "global.h"

#ifndef FPUPUBLIC_LMS_QUOTE
#define FPUPUBLIC_LMS_QUOTE(s) #s 
#endif

#define FPUPUBLIC_LMS_NAME_MACRO(x) FPUPUBLIC_LMS_QUOTE(x)

#define MAXIMUM_IPU_SUPPORTED		4

#define FWU_GENERAL					8707;

#define WOCD_ID						0x444f4357  
#define LOCL_ID						0x4C434F4C

#define INIT_WAIT_SEC				1

typedef enum
{
	FWU_ENV_MANUFACTURING = 0,   // Manufacturing update
	FWU_ENV_IFU,                 // Independent Firmware update
}FWU_ENVIRONMENT;

/** @brief Defines a generic version structure used in the software build process. This structure will be used to
*   represent versions of ROM, FW and Recovery modules.
*/
typedef struct _VERSION
{
	uint16_t      Major;
	uint16_t      Minor;
	uint16_t      Hotfix;
	uint16_t      Build;
}VERSION;



class PFWUpdateDllWrapper 
{
public:
	virtual uint32_t waitForFwInitDone() = 0;
	virtual uint32_t isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage) = 0;
	virtual uint32_t performPFWU(uint32_t partialID, const std::wstring& imagePath) = 0;
	
	virtual void printPfwuReturnCode(uint32_t status) = 0; 
};

#endif /* __PFWUPDATEDLLWRAPPER_H_ */
