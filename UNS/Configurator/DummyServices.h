/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2012-2015 Intel Corporation
 */
#ifndef DUMMY_SERVICES_H
#define DUMMY_SERVICES_H

#include "GmsSubService.h"
#include "LASTSERVICE_export.h"
#include "FIRSTSERVICE_export.h"
#include "AMTENABLELASTSERVICE_export.h"
#include "WAITINGFORPFWLASTSERVICE_Export.h"

class FIRSTSERVICE_Export FirstService : public GmsSubService
{
  public:
	  FirstService(){}
	  virtual const ACE_TString name();
};

class LASTSERVICE_Export LastService : public GmsSubService
{
  public:
	  LastService(){}
	  virtual const ACE_TString name();
};

class AMTENABLELASTSERVICE_Export AmtEnableLastService : public GmsSubService
{
public:
	AmtEnableLastService(){}
	virtual const ACE_TString name();
};

class WAITINGFORPFWLASTSERVICE_Export WaitingForPfwLastService : public GmsSubService
{
public:
	WaitingForPfwLastService() {}
	virtual const ACE_TString name();
};

#endif//DUMMY_SERVICES_H