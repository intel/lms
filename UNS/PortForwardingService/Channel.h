/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: Channel.h

--*/

#ifndef _CHANNEL_H_
#define _CHANNEL_H_
#include "SoapHandler.h"

class Channel {
public:
	enum CHANNEL_STATUS {
		NOT_OPENED,
		OPEN,
		WAITING_CLOSE,
		CLOSED
	};

	static const unsigned int LMS_WINDOW_SIZE = 4095;

	Channel(PortForwardRequest *portForwardRequest, SOCKET socket) : 
			_recipientChannel(0), _senderChannel((unsigned int)socket), _socket(socket), _txWindow(0), _rxWindow(LMS_WINDOW_SIZE), _status(NOT_OPENED),
			_portForwardRequest(portForwardRequest){}
	virtual ~Channel() {}

	Channel(const Channel &orig) :
		_recipientChannel(orig._recipientChannel), _senderChannel(orig._senderChannel),
		_socket(orig._socket), _txWindow(orig._txWindow), _rxWindow(orig._rxWindow), _status(orig._status),
		_portForwardRequest(orig._portForwardRequest) {}
	Channel &operator=(const Channel &other) = delete;

	unsigned int GetRecipientChannel() const { return _recipientChannel; }
	unsigned int GetSenderChannel() const { return _senderChannel; }
	bool SetRecipientChannel(unsigned int recipientChannel) { _recipientChannel = recipientChannel; return true; }
	unsigned int GetTxWindow() const { return _txWindow; }
	void SetTxWindow(unsigned int wndSize) { _txWindow = wndSize; }
	unsigned int GetRxWindow() const { return _rxWindow; }
	bool AddBytesTxWindow(const unsigned int bytesToAdd) {
		if (bytesToAdd > (UINT_MAX - _txWindow) ) {
			_txWindow = UINT_MAX;
			return true;
		}
		_txWindow += bytesToAdd; 
		return true; 
	}
	bool RemoveBytesTxWindow(const unsigned int bytesToRemove) {
		if (_txWindow < bytesToRemove) {
			_txWindow = 0;
			return true;
		}
		_txWindow -= bytesToRemove;
		return true;
	}
	SOCKET GetSocket() const { return _socket; }
	CHANNEL_STATUS GetStatus() const { return _status; }
	bool SetStatus(const CHANNEL_STATUS newStatus) { _status = newStatus; return true; }
	PortForwardRequest * GetPortForwardRequest() const { return _portForwardRequest; }

	virtual int ProcessRx(const char *data, uint32_t len, bool& request_close) = 0;

private:
	unsigned int _recipientChannel;
	const unsigned int _senderChannel;
	const SOCKET _socket;
	unsigned int _txWindow;
	unsigned int _rxWindow;
	CHANNEL_STATUS _status;
	PortForwardRequest *_portForwardRequest;
};

class SocketChannel : public Channel
{
public:
	SocketChannel(PortForwardRequest *portForwardRequest, SOCKET socket) :
		Channel(portForwardRequest, socket) {}
	virtual ~SocketChannel() {}
	SocketChannel(const SocketChannel &orig) : Channel(orig) {};
	SocketChannel &operator=(const SocketChannel &) = delete;

	virtual int ProcessRx(const char *data, uint32_t len, bool& request_close)
	{
		request_close = false;
		return send(GetSocket(), data, len, 0);
	}
};

class SoapChannel : public Channel
{
public:
	SoapChannel(PortForwardRequest *portForwardRequest, SOCKET socket) :
		Channel(portForwardRequest, socket) {}
	virtual ~SoapChannel() {}

	SoapChannel(const SoapChannel &) = delete;
	SoapChannel &operator=(const SoapChannel &) = delete;

	virtual int ProcessRx(const char *data, uint32_t len, bool& request_close)
	{
		request_close = _soapHandler.handle_input(data, len);
		return len;
	}
private:
	SOAP_Handler _soapHandler;
};
#endif