/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2012-2020 Intel Corporation
 */
#include "DummyServices.h"

const ACE_TString LastService::name()
{
	return LAST_SERVICE;
}

const ACE_TString FirstService::name()
{
	return FIRST_SERVICE;
}

const ACE_TString AmtEnableLastService::name()
{
	return AMT_ENABLE_LAST_SERVICE;
}

const ACE_TString WaitingForPfwLastService::name()
{
	return WAITING_FOR_PFW_LAST_SERVICE;
}

LMS_SUBSERVICE_DEFINE (FIRSTSERVICE, FirstService)
LMS_SUBSERVICE_DEFINE (LASTSERVICE, LastService)
LMS_SUBSERVICE_DEFINE (AMTENABLELASTSERVICE, AmtEnableLastService)
LMS_SUBSERVICE_DEFINE (WAITINGFORPFWLASTSERVICE, WaitingForPfwLastService)
