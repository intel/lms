/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: PortForwardRequest.h

--*/

#ifndef _PORT_FORWARD_REQUEST_H_
#define _PORT_FORWARD_REQUEST_H_

#include <vector>

typedef int (*IsConnectionPermittedCallback) (void *const param, SOCKET s, sockaddr_storage* caller_addr);

class PortForwardRequest {
public:
	enum class PORT_FORWARD_REQUEST_STATUS {
		NOT_ACTIVE,
		PENDING_REQUEST,
		LISTENING 
	};

	PortForwardRequest(const std::string &bindedAddress, int port, const std::vector<SOCKET> &listeningSockets, 
		IsConnectionPermittedCallback cb, bool isLocal) :
		_bindedAddress(bindedAddress), _port(port), _local(isLocal), _listeningSockets(listeningSockets), _cb(cb),
		_status(PORT_FORWARD_REQUEST_STATUS::NOT_ACTIVE), _channelCount(0) {}

	const std::string GetBindedAddress() const { return _bindedAddress; }
	unsigned int GetPort() const { return _port;}
	const std::vector<SOCKET> & GetListeningSockets() const { return _listeningSockets; }
	int IsConnectionPermitted(void *param,SOCKET sock,sockaddr_storage* caller_addr)
	{ if (_cb != NULL) { return _cb(param,sock,caller_addr);} else return -1; }
	PORT_FORWARD_REQUEST_STATUS GetStatus() { return _status; }
	bool IsLocal() { return _local; }
	bool SetStatus(PORT_FORWARD_REQUEST_STATUS newStatus) { _status = newStatus; return true; }
	unsigned int GetChannelCount() { return _channelCount; }
	unsigned int IncreaseChannelCount() { return ++_channelCount; }
	unsigned int DecreaseChannelCount() { if (_channelCount > 0) { --_channelCount; } return _channelCount; }
	
	
private:
	const std::string _bindedAddress;
	const unsigned int _port;
	const bool _local;
	const std::vector<SOCKET> _listeningSockets;
	const IsConnectionPermittedCallback _cb;
	PORT_FORWARD_REQUEST_STATUS _status;
	unsigned int _channelCount;
};

#endif