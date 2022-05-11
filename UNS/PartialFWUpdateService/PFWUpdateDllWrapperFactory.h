/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2022 Intel Corporation
 */
#ifndef __PFWUPDATEDLLWRAPPERFACTORY_H_
#define __PFWUPDATEDLLWRAPPERFACTORY_H_

#include "PFWUpdateDllWrapper.h"
#include <memory>

class PFWUpdateDllWrapperFactory
{
public:
	static std::unique_ptr<PFWUpdateDllWrapper> Create(uint16_t fwVersionMajor, uint16_t fwVersionMinor);
};

#endif /* __PFWUPDATEDLLWRAPPERFACTORY_H_ */