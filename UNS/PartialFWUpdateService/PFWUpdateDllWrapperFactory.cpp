/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2022 Intel Corporation
 */
#include "PFWUpdateDllWrapperFactory.h"
#include "PFWUpdateDllWrapperME11.h"
#include "PFWUpdateDllWrapperME12.h"
#include "PFWUpdateDllWrapperME16.h"
#include "PFWUpdateDllWrapperME18.h"

std::unique_ptr<PFWUpdateDllWrapper> PFWUpdateDllWrapperFactory::Create(uint16_t fwVersionMajor, uint16_t fwVersionMinor)
{
	if (fwVersionMajor < 11)
	{
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got unsupported version: %u.%u.\n", fwVersionMajor, fwVersionMinor);
		throw std::exception("PFWUpdateDllWrapperFactory got unsupported version");
	}
	if (fwVersionMajor == 11)
	{
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version 11. Loading ME11 DLL.\n");
		return std::make_unique<PFWUpdateDllWrapperME11>();
	}
	if (fwVersionMajor >= 18) {
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version %u.%u. Loading ME18 DLL.\n", fwVersionMajor, fwVersionMinor);
		return std::make_unique<PFWUpdateDllWrapperME18>();
	}
	if (fwVersionMajor > 15 || ((fwVersionMajor == 15) && (fwVersionMinor == 20)))
	{
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version %u.%u. Loading ME16 DLL.\n", fwVersionMajor, fwVersionMinor);
		return std::make_unique<PFWUpdateDllWrapperME16>();
	}
	UNS_DEBUG(L"PFWUpdateDllWrapperFactory got version: %u.%u. Loading ME12 DLL.\n", fwVersionMajor, fwVersionMinor);
	return std::make_unique<PFWUpdateDllWrapperME12>();
}
