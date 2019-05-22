/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#include "PFWUpdateDllWrapperFactory.h"
#include "PFWUpdateDllWrapperME10.h"
#include "PFWUpdateDllWrapperME11.h"
#include "PFWUpdateDllWrapperME12.h"

std::unique_ptr<PFWUpdateDllWrapper> PFWUpdateDllWrapperFactory::Create(uint16_t fwVersion)
{
	UNS_DEBUG(L"PFWUpdateDllWrapperFactory Create wrapper for %u", L"\n", fwVersion);

	switch (fwVersion)
	{
	case 8:
	case 9:
	case 10:
		return std::make_unique<PFWUpdateDllWrapperME10>();
	case 11:
		return std::make_unique<PFWUpdateDllWrapperME11>();
	case 12:
		return std::make_unique<PFWUpdateDllWrapperME12>();
	default:
		UNS_DEBUG(L"PFWUpdateDllWrapperFactory got unsupported version: %u. Loading ME12 DLL.", L"\n", fwVersion);
		return std::make_unique<PFWUpdateDllWrapperME12>();
	}
}
