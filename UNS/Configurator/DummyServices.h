/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2012-2020 Intel Corporation
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
	  virtual const wchar_t *short_name() const { return L"FirstService"; }
};

class LASTSERVICE_Export LastService : public GmsSubService
{
  public:
	  LastService(){}
	  virtual const ACE_TString name();
	  virtual const wchar_t *short_name() const { return L"LastService"; }
};

class AMTENABLELASTSERVICE_Export AmtEnableLastService : public GmsSubService
{
public:
	AmtEnableLastService(){}
	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"AmtEnableLastService"; }
};

class WAITINGFORPFWLASTSERVICE_Export WaitingForPfwLastService : public GmsSubService
{
public:
	WaitingForPfwLastService() {}
	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"WaitingForPfwLastService"; }
};

#endif//DUMMY_SERVICES_H