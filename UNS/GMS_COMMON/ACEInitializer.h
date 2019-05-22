/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2015 Intel Corporation
 */
#ifndef _ACE_INITIALIZER__H_
#define _ACE_INITIALIZER__H_

#include "ace/streams.h"
#include "ace/OS_NS_errno.h"
#include <ace/Init_ACE.h>


class ACEInitializer
{
public:
	ACEInitializer (void)
	{
		ACE::init ();
	}
	~ACEInitializer (void)
	{
		ACE::fini (); 
	}
};


#endif //_ACE_INITIALIZER__H_
