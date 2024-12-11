/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2024 Intel Corporation
 */
#ifndef __FWCIRAWORKAROUND_SERVICE_H_
#define __FWCIRAWORKAROUND_SERVICE_H_
#include "GmsSubService.h"
#include "FWCIRAWORKAROUNDSERVICE_export.h"

class FWCIRAWORKAROUNDSERVICE_Export FWCIRAWorkaroundService : public GmsSubService
{
public:
	FWCIRAWorkaroundService() : timeout(0) {}

	// ********************* ACE PART ********************************
	virtual int init(int argc, ACE_TCHAR *argv[]);
	virtual int fini(void);
	virtual int resume();
	virtual const ACE_TString name();
	virtual const wchar_t *short_name() const { return L"CIRAWA"; }
	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	//*********************** business logic ****************************

protected:
	virtual int handle_timeout(const ACE_Time_Value &current_time, const void *arg);

private:
	unsigned long timeout;

	bool CheckCIRA();
};

#endif /* __FWCIRAWORKAROUND_SERVICE_H_ */
