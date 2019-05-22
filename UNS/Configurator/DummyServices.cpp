/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2012-2015 Intel Corporation
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

ACE_FACTORY_DEFINE (FIRSTSERVICE, FirstService)
ACE_FACTORY_DEFINE (LASTSERVICE, LastService)
ACE_FACTORY_DEFINE (AMTENABLELASTSERVICE, AmtEnableLastService)
ACE_FACTORY_DEFINE (WAITINGFORPFWLASTSERVICE, WaitingForPfwLastService)