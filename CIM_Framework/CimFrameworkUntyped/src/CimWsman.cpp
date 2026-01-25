//----------------------------------------------------------------------------
//
// Copyright (C) 2003 Intel Corporation
//
//  File:       CimWsman.cpp
//
//  Contents:   Library independent interface to WS-Management transport
//
//----------------------------------------------------------------------------

#include "CimWsman.h"

namespace Intel
{
namespace WSManagement
{
	SubscribeInfo::SubscribeInfo() :
		delivery_mode(WSMAN_DELIVERY_PUSH), selectorset(nullptr),
		heartbeat_interval(0), expires(0)
	{}
	SubscribeInfo::~SubscribeInfo(){}

	ConnectionInfo::ConnectionInfo() :
		authmethod(KERBEROS), local(false), port(0), secure(true) {}
	ConnectionInfo::~ConnectionInfo(){}

	EnumerateFilter::EnumerateFilter(){ assocType = AllInstances;}
	EnumerateFilter::~EnumerateFilter(){}

	EnumerateOptions::EnumerateOptions() : type(OBJECT_ONLY)
		 {}
	EnumerateOptions::~EnumerateOptions(){}


}
}