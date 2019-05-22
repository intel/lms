/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: GMSConfig.h

--*/

#ifndef GMS_CONFIG
#define GMS_CONFIG

#include "ace/Map_Manager.h"
#include "ace/Null_Mutex.h"

class GMSConfig
{
public:
	GMSConfig();
//init(): Load the configuration from configuration files.
//Returns true on success, false if either of the files could not be opened (in which
//case the defaults will be used).
	bool Init();
	virtual bool  CheckEventToPublish(unsigned long EventID) const;

private:
	bool LoadMachineConfig();
	ACE_Map_Manager <unsigned long,int,ACE_Null_Mutex> m_EventsToPublish;
};

#endif //GMS_CONFIG