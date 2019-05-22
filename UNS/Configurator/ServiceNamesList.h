/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2015 Intel Corporation
 */
#ifndef __SERVICE_NAMES_LIST_H_
#define __SERVICE_NAMES_LIST_H_

#include "ConfCommonTypes.h"

class ServiceNamesList {

public:
	virtual ~ServiceNamesList() {}
	ServiceNamesList() {}
	ServiceNamesList(const NamesList& names) { m_ServicesNames = names;}
	void Read(const ACE_WString &fileName);
	void Read(NamesGroup namesGroup);
	void GetNames(NamesList &serviceNames) const;
	void AddName(const ACE_TString &serviceName);
	void SetNames(const NamesList &serviceNames);
	

protected:
	NamesList m_ServicesNames;

};

#endif //__SERVICE_NAMES_LIST_H_