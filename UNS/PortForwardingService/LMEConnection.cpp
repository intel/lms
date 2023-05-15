/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: LMEConnection.cpp

--*/

#include "LMEConnection.h"
#include "MEICommand.h"
#include "HECIException.h"

#include <errno.h>

#include "LMS_if.h"

#include <BaseWSManClient.h>

using namespace Intel::MEI_Client;

#define HECI_IO_TIMEOUT 5000

const uint32_t LMEConnection::RX_WINDOW_SIZE = 1024; // TBD Choose optimal window size

LMEConnection::LMEConnection(bool verbose): _txBuffer(NULL), _initState(INIT_STATE_DISCONNECTED),
				_cb(NULL), _signalSelectCallback(nullptr), _cbParam(NULL), _heci(GenerateLMEClient(verbose)),
				_threadStartedEvent(1), _portIsOk(1), m_portForwardingPort(0),
				_selfDisconnect(false), _clientNotFound(false), aceMgr_(nullptr), _rxThread(0)
{
	_devNotify = NULL;
	_devNotifyParam = NULL;
	_notifyHandle = NULL;
}

LMEConnection::~LMEConnection()
{
	Deinit();
}

bool LMEConnection::IsInitialized()
{
	std::lock_guard<std::mutex> lock(_initLock);
	return (_initState == INIT_STATE_CONNECTED) ? true : false;
}

bool LMEConnection::Init(InitParameters & params)
{
	bool res = false;
	FuncEntryExit<decltype(res)> fee(this, L"Init", res);

	{
		std::lock_guard<std::mutex> lock(_initLock);

		aceMgr_ = params.threadMgr_;

		_selfDisconnect = false;

		_devNotify = params.devNotifyCb_;

		_devNotifyParam = params.devNotifyCbParam_;

		_clientNotFound = false;
		if (_initState == INIT_STATE_CONNECTED) {
			_heci->Deinit();
		}
		else if (_initState != INIT_STATE_DISCONNECTED) {
			return res;
		}
		_initState = INIT_STATE_CONNECTING;
		_signalSelectCallback = params.signalSelectCb_;
		_cb = params.heciCb_;

		_cbParam = params.heciCbParam_;

		try
		{
			_heci->Init();

			// Register Device Notification
			if (_devNotify != nullptr)
			{
				HANDLE drvHandle = _heci.get()->GetHandle();
				if (drvHandle)
					_devNotify(_devNotifyParam, &_notifyHandle, drvHandle, true);
			}
		}
		catch (HeciNoClientException& e)
		{
			_clientNotFound = true;
			_heci->Deinit();
			_initState = INIT_STATE_DISCONNECTED;
			UNS_ERROR(L"Heci init failed. Error: %C\n", e.what());
			return res;
		}
		catch (HECIException& e)
		{
			_clientNotFound = false;
			_heci->Deinit();
			_initState = INIT_STATE_DISCONNECTED;
			UNS_ERROR(L"Heci init failed. Error: %C\n", e.what());
			return res;
		}

		// reset events
		_portIsOk.reset();

		// launch RX thread
		_txBuffer = new unsigned char[GetBufferSize()];
		auto spawn_res = aceMgr_->spawn((ACE_THR_FUNC)_rxThreadFunc, this, THR_CANCEL_ENABLE, &_rxThread);
		if (spawn_res == -1)
		{
			UNS_ERROR(L"mgr->spawn spawn failure\n");
			DeinitInternal();
			return res;
		}

		ACE_Time_Value till(10);
		int wait = _threadStartedEvent.wait(&till, 0);
		_threadStartedEvent.reset();
		if (wait) {
			UNS_ERROR(L"_threadStartedEvent was not set\n");
			DeinitInternal();
			return res;
		}
		else {
			UNS_DEBUG(L"_threadStartedEvent was set\n");
		}
		_initState = INIT_STATE_CONNECTED;
	}

	ACE_Time_Value till(5);
	int wait = _portIsOk.wait(&till, 0);
	_portIsOk.reset();
	if (wait) {
		UNS_ERROR(L"_portIsOk was not set\n");
		Deinit(false);
		return res;
	}
	else {
		UNS_DEBUG(L"_portIsOk was set\n");
	}

	res = true;
	return res;
}

// Should be called under _initLock
void LMEConnection::DeinitInternal()
{
	_heci->Deinit();
	_initState = INIT_STATE_DISCONNECTED;
	m_portForwardingPort = 0;

	if (aceMgr_)
		aceMgr_->cancel(_rxThread, 0);

	delete[] _txBuffer;
	_txBuffer = NULL;
}

//parameter : signalSelect - indicates that we want to signal the main thread to exit the select and reinit the connection
void LMEConnection::Deinit(bool signalSelect)
{
	FuncEntryExit<void> fee(this, L"Deinit");

	std::lock_guard<std::mutex> lock(_initLock);

	if (_devNotify != NULL)
	{
		if (_devNotify(_devNotifyParam, &_notifyHandle, NULL, false))
			_notifyHandle = NULL;
	}

	DeinitInternal();

	if (signalSelect)
		_signalSelectCallback(_cbParam);
}

bool LMEConnection::Disconnect(APF_DISCONNECT_REASON_CODE reasonCode)
{
	FuncEntryExit<void> fee(this, L"Disconnect");

	unsigned char buf[sizeof(APF_DISCONNECT_MESSAGE)];

	APF_DISCONNECT_MESSAGE *disconnectMessage = (APF_DISCONNECT_MESSAGE *)buf;

	memset(disconnectMessage, 0, sizeof(buf));
	disconnectMessage->MessageType = APF_DISCONNECT;
	disconnectMessage->ReasonCode = htonl(reasonCode);

	UNS_DEBUG(L"==>LME: Disconnect.\n");
	ssize_t res = _sendMessage(buf, sizeof(buf));

	_selfDisconnect = true;

	return (res == sizeof(buf));
}

bool LMEConnection::ServiceAccept(const std::string &serviceName)
{
	INIT_STATES initState = getInitState();

	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	auto messageLen = sizeof(APF_SERVICE_ACCEPT_MESSAGE) + serviceName.length();
	std::vector<unsigned char> buf(messageLen);
	auto apfSam = (APF_SERVICE_ACCEPT_MESSAGE*)buf.data();

	apfSam->MessageType = APF_SERVICE_ACCEPT;
	apfSam->ServiceNameLength = htonl(serviceName.size());
	// The apfSam allocate with enough place for serviceName
	std::copy(serviceName.begin(), serviceName.end(), apfSam->ServiceName);

	UNS_DEBUG(L"==>LME: Service accept: %C\n", serviceName.c_str());
	ssize_t res = _sendMessage(buf.data(), messageLen);
	return (res == messageLen);
}

bool LMEConnection::UserAuthSuccess()
{
	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	unsigned char buf = APF_USERAUTH_SUCCESS;

	UNS_DEBUG(L"==>LME: User authentication success.\n");
	ssize_t res = _sendMessage(&buf, sizeof(buf));

	return (res == sizeof(buf));
}

bool LMEConnection::ProtocolVersion(const LMEProtocolVersionMessage &versionMessage)
{
	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_PROTOCOL_VERSION_MESSAGE protVersion;
	memset(&protVersion, 0, sizeof(protVersion));

	protVersion.MessageType = APF_PROTOCOLVERSION;
	protVersion.MajorVersion = htonl(versionMessage.MajorVersion);
	protVersion.MinorVersion = htonl(versionMessage.MinorVersion);
	protVersion.TriggerReason = htonl(versionMessage.TriggerReason);

	UNS_DEBUG(L"==>LME: Protocol version: %d.%d.%d\n", versionMessage.MajorVersion, versionMessage.MinorVersion, versionMessage.TriggerReason);
	ssize_t res = _sendMessage((unsigned char *)&protVersion, sizeof(protVersion));

	return (res == sizeof(protVersion));
}

bool LMEConnection::TcpForwardReplySuccess(uint32_t port) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_TCP_FORWARD_REPLY_MESSAGE message;

	message.MessageType = APF_REQUEST_SUCCESS;
	message.PortBound = htonl(port);

	UNS_DEBUG(L"==>LME: TCP forward replay success, Port %d.\n", port);
	ssize_t res = _sendMessage((unsigned char *)&message, sizeof(message));

	return (res == sizeof(message));

}

bool LMEConnection::TcpForwardReplyFailure() {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	unsigned char buf = APF_REQUEST_FAILURE;

	UNS_DEBUG(L"==>LME: TCP forward replay failure.\n");
	ssize_t res = _sendMessage(&buf, sizeof(buf));

	return (res == sizeof(buf));

}

bool LMEConnection::TcpForwardCancelReplySuccess() {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	unsigned char buf = APF_REQUEST_SUCCESS;

	UNS_DEBUG(L"==>LME: TCP forward cancel replay success.\n");
	ssize_t res = _sendMessage(&buf, sizeof(buf));

	return (res == sizeof(buf));

}

bool LMEConnection::TcpForwardCancelReplyFailure() {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	unsigned char buf = APF_REQUEST_FAILURE;

	UNS_DEBUG(L"==>LME: TCP forward cancel replay failure\n");
	ssize_t res = _sendMessage(&buf, sizeof(buf));

	return (res == sizeof(buf));

}

#define CHECK_BUFFER_OVERFLOW(nbytes) \
																if (bufferEnd <= (pCurrent + nbytes)) \
																{ \
																	UNS_ERROR(L"Buffer overflow %d %d %d\n", pCurrent, bufferEnd, nbytes); \
																	delete[] buf; \
																	return false; \
																}

bool LMEConnection::ChannelOpenForwardedRequest(uint32_t senderChannel, const std::string &connectedIP, uint32_t connectedPort,
												const std::string &originatorIP, uint32_t originatorPort) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	auto bufferSize = 5 + APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED) + 16 +
		connectedIP.size() + 8 + originatorIP.size() + 4;
	unsigned char *buf = new unsigned char[bufferSize];
	unsigned char *pCurrent = buf;
	unsigned char * bufferEnd = buf + bufferSize + 1;


	CHECK_BUFFER_OVERFLOW(sizeof(unsigned char));
	*pCurrent = APF_CHANNEL_OPEN; ++pCurrent;

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED)); pCurrent += 4;

	CHECK_BUFFER_OVERFLOW(APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED));
	std::copy_n(APF_OPEN_CHANNEL_REQUEST_FORWARDED, APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED), pCurrent);
	pCurrent += APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED);

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(senderChannel); pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(RX_WINDOW_SIZE); pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = 0xFFFFFFFF; pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(connectedIP.size()); pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(connectedIP.size());
	std::copy(connectedIP.begin(), connectedIP.end(), pCurrent);
	pCurrent += connectedIP.size();

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(connectedPort); pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl((uint32_t)originatorIP.size()); pCurrent += sizeof(uint32_t);

	CHECK_BUFFER_OVERFLOW(originatorIP.size());
	std::copy(originatorIP.begin(), originatorIP.end(), pCurrent);
	pCurrent += originatorIP.size();

	CHECK_BUFFER_OVERFLOW(sizeof(uint32_t));
	*((uint32_t *)pCurrent) = htonl(originatorPort); pCurrent += sizeof(uint32_t);

	UNS_DEBUG(L"==>LME: OPEN_CHANNEL_REQUEST, Address: %C:%d.\n", originatorIP.c_str(), connectedPort);

	int actualLen = (int)(pCurrent - buf);
	ssize_t res = _sendMessage(buf, actualLen);

	delete[] buf;
	return (res == actualLen);

}

bool LMEConnection::ChannelOpenReplaySuccess(uint32_t recipientChannel, uint32_t senderChannel) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE message;

	message.MessageType = APF_CHANNEL_OPEN_CONFIRMATION;
	message.RecipientChannel = htonl(recipientChannel);
	message.SenderChannel = htonl(senderChannel);
	message.InitialWindowSize = htonl(RX_WINDOW_SIZE);
	message.Reserved = 0xFFFFFFFF;

	UNS_DEBUG(L"==>LME[%d]: CHANNEL_OPEN_CONFIRMATION\n", recipientChannel);
	ssize_t res = _sendMessage((unsigned char *)&message, sizeof(message));

	return (res == sizeof(message));

}

bool LMEConnection::ChannelOpenReplayFailure(uint32_t recipientChannel, uint32_t reason) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_CHANNEL_OPEN_FAILURE_MESSAGE message;

	message.MessageType = APF_CHANNEL_OPEN_FAILURE;
	message.RecipientChannel = htonl(recipientChannel);
	message.ReasonCode = htonl(reason);
	message.Reserved = 0x00000000;
	message.Reserved2 = 0x00000000;

	UNS_DEBUG(L"==>LME[%d]: CHANNEL_OPEN_FAILURE, Reason: %d\n", recipientChannel, reason);
	ssize_t res = _sendMessage((unsigned char *)&message, sizeof(message));

	return (res == sizeof(message));

}

bool LMEConnection::ChannelClose(uint32_t recipientChannel) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_CHANNEL_CLOSE_MESSAGE message;

	message.MessageType = APF_CHANNEL_CLOSE;
	message.RecipientChannel = htonl(recipientChannel);

	UNS_DEBUG(L"==>LME[%d]: Channel close\n", recipientChannel);
	ssize_t res = _sendMessage((unsigned char *)&message, sizeof(message));

	return (res == sizeof(message));

}

ssize_t LMEConnection::ChannelData(uint32_t recipientChannel, uint32_t len, unsigned char *buffer) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_CHANNEL_DATA_MESSAGE *message;

	if (len > GetBufferSize() - sizeof(APF_CHANNEL_DATA_MESSAGE)) {
		return -1;
	}

	message = (APF_CHANNEL_DATA_MESSAGE *)_txBuffer;
	message->MessageType = APF_CHANNEL_DATA;
	message->RecipientChannel = htonl(recipientChannel);
	message->DataLength = htonl(len);
	// Data have at least len places, checked above
	std::copy_n(buffer, len, message->Data);

	UNS_TRACE(L"==>LME[%d]: %d bytes\n", recipientChannel, len);

	return _sendMessage((unsigned char *)message, sizeof(APF_CHANNEL_DATA_MESSAGE) + len);

}

bool LMEConnection::ChannelWindowAdjust(uint32_t recipientChannel, uint32_t len) {

	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	APF_WINDOW_ADJUST_MESSAGE message;

	message.MessageType = APF_CHANNEL_WINDOW_ADJUST;
	message.RecipientChannel = htonl(recipientChannel);
	message.BytesToAdd = htonl(len);

	UNS_TRACE(L"==>LME[%d]: Window Adjust with %d bytes\n", recipientChannel, len);
	ssize_t res = _sendMessage((unsigned char *)&message, sizeof(message));

	return (res == sizeof(message));

}

ssize_t LMEConnection::_receiveMessage(unsigned char *buffer, size_t len)
{
	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return -1;
	}

	try
	{
		return _heci->ReceiveHeciMessage(buffer, len, 0);
	}
	catch (HECIException& e)
	{
		UNS_ERROR(L"Error receiving data from HECI. Error: %C\n", e.what());
		return -1;
	}
}

ssize_t LMEConnection::_sendMessage(unsigned char *buffer, size_t len)
{
	INIT_STATES initState = getInitState();
	if (initState != INIT_STATE_CONNECTED)
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return -1;
	}

	std::lock_guard<std::mutex> lock(_sendMessageLock);

	try
	{
		return _heci->SendHeciMessage(buffer, len, HECI_IO_TIMEOUT);
	}
	catch (HECIException& e)
	{
		UNS_ERROR(L"Error sending data to HECI. Error: %C\n", e.what());
		return -1;
	}
}

void LMEConnection::_rxThreadFunc(void *param)
{
	LMEConnection *connection = (LMEConnection*)param;

	try {
		connection->_doRX();
	}

	catch (...) {
		UNS_ERROR(L"LMEConnection do RX exception\n");
	}
}

void LMEConnection::_doRX()
{
	_threadStartedEvent.signal();
	unsigned char *pCurrent;
	ssize_t bytesRead;

	std::vector<unsigned char> rxBufferVector(GetBufferSize());
	unsigned char *rxBuffer = rxBufferVector.data();

	const std::string apf_auth_password(APF_AUTH_PASSWORD);

	while (true) {
		int status = 1;

		bytesRead = _receiveMessage(rxBuffer, GetBufferSize());

		if (bytesRead < 0) {
			Deinit(true);
			break;
		}

		if (aceMgr_->testcancel(aceMgr_->thr_self()))
		{
			UNS_DEBUG(L"_doRX thread shutdown\n");
			break;
		}


		if (bytesRead == 0) {
			// ERROR
			continue; // TBD Do we want to deinit?
		}


		UNS_TRACE(L"==>LME: %d bytes, message type %02d\n", bytesRead, rxBuffer[0]);

		uint32_t posBytesRead = (uint32_t) bytesRead;

		switch (rxBuffer[0]) {
			case APF_DISCONNECT:
				{
					APF_DISCONNECT_MESSAGE *pMessage = (APF_DISCONNECT_MESSAGE *)rxBuffer;


					if (posBytesRead < sizeof(APF_DISCONNECT_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEDisconnectMessage disconnectMessage(
						(APF_DISCONNECT_REASON_CODE)ntohl(pMessage->ReasonCode));

					_cb(_cbParam, &disconnectMessage, sizeof(disconnectMessage), &status);

					break;
				}

			case APF_SERVICE_REQUEST:
				{
					APF_SERVICE_REQUEST_MESSAGE *pMessage =
						(APF_SERVICE_REQUEST_MESSAGE *)rxBuffer;


					if ((posBytesRead < sizeof(APF_SERVICE_REQUEST)) ||
						(posBytesRead < sizeof(APF_SERVICE_REQUEST) +
														ntohl(pMessage->ServiceNameLength))) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEServiceRequestMessage serviceRequestMessage;

					uint32_t len = ntohl(pMessage->ServiceNameLength);
					serviceRequestMessage.ServiceName.append((char *)pMessage->ServiceName, len);

					_cb(_cbParam, &serviceRequestMessage, sizeof(serviceRequestMessage), &status);

					break;
				}

			case APF_USERAUTH_REQUEST:
				{
					pCurrent = rxBuffer; ++pCurrent;

					LMEUserAuthRequestMessage userAuthRequest;

					if ((posBytesRead - (pCurrent - rxBuffer)) < sizeof(uint32_t)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
					if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					userAuthRequest.Username.append((char *)pCurrent, len); pCurrent += len;

					if ((posBytesRead - (pCurrent - rxBuffer)) < sizeof(uint32_t)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
					if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					userAuthRequest.ServiceName.append((char *)pCurrent, len); pCurrent += len;

					if ((posBytesRead - (pCurrent - rxBuffer)) < sizeof(uint32_t)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
					if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}
					userAuthRequest.MethodName.append((char *)pCurrent, len); pCurrent += len;

					if (
						(apf_auth_password.length() == userAuthRequest.MethodName.length()) &&
						(_strnicmp(apf_auth_password.c_str(), userAuthRequest.MethodName.c_str(), apf_auth_password.length()) == 0)
						) {

							if ((posBytesRead - (pCurrent - rxBuffer)) < sizeof(uint32_t) + 1) {
								UNS_ERROR(L"Error receiving data from HECI\n");
								Deinit(true);
								return;
							}
							++pCurrent;

							len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
							if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
								UNS_ERROR(L"Error receiving data from HECI\n");
								Deinit(true);
								return;
							}
							AuthPasswordData authData;
							authData.Password.append((char *)pCurrent, len); pCurrent += len;

							userAuthRequest.MethodData = &authData;
					}

					_cb(_cbParam, &userAuthRequest, sizeof(userAuthRequest), &status);

					break;
				}

			case APF_GLOBAL_REQUEST:
				{
					APF_GENERIC_HEADER *pHeader = (APF_GENERIC_HEADER *)rxBuffer;

					if (posBytesRead < sizeof(APF_GENERIC_HEADER) + ntohl(pHeader->StringLength) + sizeof(uint8_t)) {
						// TBD Do we want to deinit?
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					if (_strnicmp((char *)pHeader->String, APF_GLOBAL_REQUEST_STR_TCP_FORWARD_REQUEST,
														APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_TCP_FORWARD_REQUEST)) == 0) {

						pCurrent = rxBuffer + sizeof(APF_GENERIC_HEADER) +
							APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_TCP_FORWARD_REQUEST) + sizeof(uint8_t);

						//if (bytesRead < (unsigned char)pCurrent - rxBuffer + sizeof(uint32_t) +) {
						//	// TBD Do we want to deinit?
						//	/*UNS_ERROR("Error receiving data from HECI\n");
						//	Deinit();
						//	return;*/
						//}


						LMETcpForwardRequestMessage tcpForwardRequest;
						uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);

						tcpForwardRequest.Address.append((char *)pCurrent, len); pCurrent += len;
						tcpForwardRequest.Port = ntohl(*((uint32_t *)pCurrent));

						_cb(_cbParam, &tcpForwardRequest, sizeof(tcpForwardRequest), &status);

						if (status == 0 && m_portForwardingPort == 0 &&
							(tcpForwardRequest.Port == AMT_NON_SECURE_PORT || tcpForwardRequest.Port == AMT_SECURE_PORT))
						{
							m_portForwardingPort = tcpForwardRequest.Port;
							UNS_DEBUG(L"_portIsOk\n");
							_portIsOk.signal();
						}
					}
					else if (_strnicmp((char *)pHeader->String, APF_GLOBAL_REQUEST_STR_TCP_FORWARD_CANCEL_REQUEST,
													APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_TCP_FORWARD_CANCEL_REQUEST)) == 0) {

						pCurrent = rxBuffer + sizeof(APF_GENERIC_HEADER) +
							APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_TCP_FORWARD_CANCEL_REQUEST) + sizeof(uint8_t);

						LMETcpForwardCancelRequestMessage tcpForwardCancelRequest;
						uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);

						tcpForwardCancelRequest.Address.append((char *)pCurrent, len); pCurrent += len;
						tcpForwardCancelRequest.Port = ntohl(*((uint32_t *)pCurrent));

						_cb(_cbParam, &tcpForwardCancelRequest, sizeof(tcpForwardCancelRequest), &status);
					}
					else if (_strnicmp((char *)pHeader->String, APF_GLOBAL_REQUEST_STR_UDP_SEND_TO,
													APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_UDP_SEND_TO)) == 0) {

						pCurrent = rxBuffer + sizeof(APF_GENERIC_HEADER) +
							APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_UDP_SEND_TO) + sizeof(uint8_t);

						uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
						std::string address;
						address.append((char *)pCurrent, len); pCurrent += len;
						uint32_t port = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);

						// Skip Originator IP and Port
						len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
						pCurrent += len; pCurrent += sizeof(uint32_t);

						// Retrieve Data
						len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);

						LMEUdpSendToMessage udpSendTo(address, port, len ,pCurrent);

						_cb(_cbParam, &udpSendTo, sizeof(udpSendTo), &status);
					}
					else {
						// Unknown request. Ignore TBD Do we want to deinit?
						break;
					}
				}
				break;

			case APF_CHANNEL_OPEN:
				{
					APF_GENERIC_HEADER *pHeader = (APF_GENERIC_HEADER *)rxBuffer;

					if (posBytesRead < sizeof(APF_GENERIC_HEADER) + ntohl(pHeader->StringLength)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					if (_strnicmp((char *)pHeader->String, APF_OPEN_CHANNEL_REQUEST_DIRECT,
																	APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_DIRECT)) == 0) {

						pCurrent = rxBuffer + sizeof(APF_GENERIC_HEADER) + APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_DIRECT);

						LMEChannelOpenRequestMessage channelOpenRequest;
						channelOpenRequest.ChannelType = LMEChannelOpenRequestMessage::DIRECT;

						channelOpenRequest.SenderChannel = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
						channelOpenRequest.InitialWindow = ntohl(*((uint32_t *)pCurrent)); pCurrent += 2 * sizeof(uint32_t);

						uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
						channelOpenRequest.Address.append((char *)pCurrent, len); pCurrent += len;
						channelOpenRequest.Port = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);

						_cb(_cbParam, &channelOpenRequest, sizeof(channelOpenRequest), &status);

					}
					else {
						// Unknown request. Ignore TBD Do we want to deinit?
						break;
					}
				}

				break;

			case APF_CHANNEL_OPEN_CONFIRMATION:
				{
					APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE *pMessage = (APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}


					LMEChannelOpenReplaySuccessMessage channelOpenReply;
					channelOpenReply.RecipientChannel = ntohl(pMessage->RecipientChannel);
					channelOpenReply.SenderChannel = ntohl(pMessage->SenderChannel);
					channelOpenReply.InitialWindow = ntohl(pMessage->InitialWindowSize);

					_cb(_cbParam, &channelOpenReply, sizeof(channelOpenReply), &status);

					break;
				}

			case APF_CHANNEL_OPEN_FAILURE:
				{
					APF_CHANNEL_OPEN_FAILURE_MESSAGE *pMessage = (APF_CHANNEL_OPEN_FAILURE_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_CHANNEL_OPEN_FAILURE_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}


					LMEChannelOpenReplayFailureMessage channelOpenReply;
					channelOpenReply.RecipientChannel = ntohl(pMessage->RecipientChannel);
					channelOpenReply.ReasonCode = (OPEN_FAILURE_REASON)
						(ntohl(pMessage->ReasonCode));

					_cb(_cbParam, &channelOpenReply, sizeof(channelOpenReply), &status);

					break;
				}

			case APF_CHANNEL_CLOSE:
				{
					APF_CHANNEL_CLOSE_MESSAGE *pMessage = (APF_CHANNEL_CLOSE_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_CHANNEL_CLOSE_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEChannelCloseMessage channelClose;
					channelClose.RecipientChannel = ntohl(pMessage->RecipientChannel);

					_cb(_cbParam, &channelClose, sizeof(channelClose), &status);

					break;
				}

			case APF_CHANNEL_DATA:
				{
					APF_CHANNEL_DATA_MESSAGE *pMessage = (APF_CHANNEL_DATA_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_CHANNEL_DATA_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					if (posBytesRead < sizeof(APF_CHANNEL_DATA_MESSAGE) + ntohl(pMessage->DataLength)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEChannelDataMessage channelData(ntohl(pMessage->RecipientChannel), ntohl(pMessage->DataLength),
						pMessage->Data);


					_cb(_cbParam, &channelData, sizeof(channelData), &status);

					break;
				}

			case APF_CHANNEL_WINDOW_ADJUST:
				{
					APF_WINDOW_ADJUST_MESSAGE *pMessage = (APF_WINDOW_ADJUST_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_WINDOW_ADJUST_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEChannelWindowAdjustMessage channelWindowAdjust;
					channelWindowAdjust.RecipientChannel = ntohl(pMessage->RecipientChannel);
					channelWindowAdjust.BytesToAdd = ntohl(pMessage->BytesToAdd);

					_cb(_cbParam, &channelWindowAdjust, sizeof(channelWindowAdjust), &status);

					break;
				}

			case APF_PROTOCOLVERSION:
				{
					APF_PROTOCOL_VERSION_MESSAGE *pMessage = (APF_PROTOCOL_VERSION_MESSAGE *)rxBuffer;

					if (posBytesRead < sizeof(APF_PROTOCOL_VERSION_MESSAGE)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEProtocolVersionMessage protVersion;
					protVersion.MajorVersion = ntohl(pMessage->MajorVersion);
					protVersion.MinorVersion = ntohl(pMessage->MinorVersion);
					protVersion.TriggerReason =
						(APF_TRIGGER_REASON)ntohl(pMessage->TriggerReason);

					_cb(_cbParam, &protVersion, sizeof(protVersion), &status);

					break;
				}

			default:
				// Unknown request. Ignore TBD Do we want to deinit?
				break;
		}
	}
}

size_t LMEConnection::GetBufferSize() const
{
	return _heci->GetBufferSize();
}
