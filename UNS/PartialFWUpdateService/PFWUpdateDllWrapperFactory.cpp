/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2021 Intel Corporation
 */
#include "PFWUpdateDllWrapperFactory.h"
#include "PFWUpdateDllWrapperME11.h"
#include "PFWUpdateDllWrapperME12.h"

std::unique_ptr<PFWUpdateDllWrapper> PFWUpdateDllWrapperFactory::Create(uint16_t fwVersion)
{
	if (fwVersion < 11)
	{
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got unsupported version: %u.\n", fwVersion);
		throw std::exception("PFWUpdateDllWrapperFactory got unsupported version");
	}
	if (fwVersion == 11)
	{
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version 11. Loading ME11 DLL.\n");
		return std::make_unique<PFWUpdateDllWrapperME11>();
	}
	UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version: %u. Loading ME12 DLL.\n", fwVersion);
	return std::make_unique<PFWUpdateDllWrapperME12>();
}
