/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef __IPREFRESHSERVICE_H_
#define __IPREFRESHSERVICE_H_

#include <string>
#include "GmsSubService.h"
#include "MessageBlockPtr.h"
#include "IPREFRESHSERVICE_export.h"

class IPREFRESHSERVICE_Export IPRefreshService: public GmsSubService
{
  public:
	// ********************* ACE PART ********************************
    virtual int init (int argc, ACE_TCHAR *argv[]);

 	virtual const ACE_TString name();

	virtual void HandleAceMessage(int type, MessageBlockPtr &mbPtr);
	// ******************************************************************

private:

	bool wiredMacAddress_exisits;
	bool wirelessMacAddress_exisits;
	bool wiredAdaptorID_updated;
	bool wirelessAdaptorID_updated;
	std::string wiredMacAddress;
	std::string wirelessMacAddress;
	int  wiredAdaptorID;
	int  wirelessAdaptorID;

	bool GetAdaptorIDs();
	void publishIPRefreshEvent(bool wlan);
	bool GetMacAddresses(unsigned short adaptorType);

	bool IPRefresh(unsigned int nicType);
	bool FillAdaptorIDs();
};

#endif /* __IPREFRESHSERVICE_H_ */