/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: ErrorCodes.cpp

--*/

#ifndef __ERRORCODES_H
#define __ERRORCODES_H

#include <winerror.h>

// HECI/MEI FACILITY
const unsigned long FACILITY_MEI = 0x8086;

// PT/ME/AMT Status Faclity
const unsigned long FACILITY_ME_STATUS = 0x8087;

const unsigned long WMI_ERRORCODE_BASE = 0x3000;

const HRESULT WMI_E_MESTATUS_BASE = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ME_STATUS, WMI_ERRORCODE_BASE);


#endif __ERRORCODES_H

