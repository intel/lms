/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERLEGACY_H_
#define __PFWUPDATEDLLWRAPPERLEGACY_H_

#include "PFWUpdateDllWrapper.h"

#define PFWU_RETRIES_LOOP 15

class PFWUpdateDllWrapperLegacy : public PFWUpdateDllWrapper
{
public:
	virtual void printPfwuReturnCode(uint32_t status);
protected:
	virtual uint32_t isFwInitDone(bool* isFwInitDone) = 0;
};

#endif /* __PFWUPDATEDLLWRAPPERLEGACY_H_ */
