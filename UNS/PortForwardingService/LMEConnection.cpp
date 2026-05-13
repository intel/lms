/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2026 Intel Corporation
 */
/*++

@file: LMEConnection.cpp

--*/

#include "LMEConnection.h"
#include "MEICommand.h"

#include <errno.h>

#include "LMS_if.h"

#include <BaseWSManClient.h>

const uint32_t LMEConnection::RX_WINDOW_SIZE = 1024; // TBD Choose optimal window size

LMEConnection::LMEConnection(bool verbose): _initState(INIT_STATE_DISCONNECTED),
				_cb(NULL), _signalSelectCallback(nullptr), _cbParam(NULL),
				_threadStartedEvent(1), _portIsOk(1), m_portForwardingPort(0),
				_selfDisconnect(false), _clientNotFound(false), aceMgr_(nullptr), _rxThread(0),
				m_shutdownInProgress(false)
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
			UNS_DEBUG(L"Disconnect\n");
			_heci.Disconnect();
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
			UNS_DEBUG(L"Connect\n");
			_heci.Connect();

			// Register Device Notification
			if (_devNotify != nullptr)
			{
				HANDLE drvHandle = _heci.GetDeviceHandle();
				if (drvHandle)
					_devNotify(_devNotifyParam, &_notifyHandle, drvHandle, true);
			}

			// reset events
			_portIsOk.reset();

			_txBuffer.reserve(_heci.GetBufferSize());
		}
		catch (const Intel::MEI_Client::MEIClientExceptionNoClient& e)
		{
			_clientNotFound = true;
			_heci.Disconnect();
			_initState = INIT_STATE_DISCONNECTED;
			UNS_ERROR(L"Heci init failed. Error: %C\n", e.what());
			return res;
		}
		catch (const Intel::MEI_Client::MEIClientException& e)
		{
			_clientNotFound = false;
			_heci.Disconnect();
			_initState = INIT_STATE_DISCONNECTED;
			UNS_ERROR(L"Heci init failed. Error: %C\n", e.what());
			return res;
		}

		UNS_DEBUG(L"Spawn thread\n");
		// launch RX thread
		auto spawn_res = aceMgr_->spawn((ACE_THR_FUNC)_rxThreadFunc, this, THR_CANCEL_ENABLE, &_rxThread);
		if (spawn_res == -1)
		{
			UNS_ERROR(L"mgr->spawn spawn failure\n");
			DeinitInternal();
			return res;
		}

		UNS_DEBUG(L"Wait for _threadStartedEvent\n");
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

	UNS_DEBUG(L"Wait for _portIsOk\n");
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
	FuncEntryExit<void> fee(this, L"DeinitInternal");

	// Try to stop RX thread asynchronously to catch it before blocking read
	aceMgr_->cancel(_rxThread, 1);
	// Stop blocking read in RX thread
	try
	{
		_heci.Cancel();
	}
	catch (const Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"Heci Cancel failed. Error: %C\n", e.what());
	}
	// Stop RX thread synchronously when it exited blocking read
	aceMgr_->cancel(_rxThread, 0);
	try
	{
		_heci.Disconnect();
	}
	catch (const Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"Heci Disconnect failed. Error: %C\n", e.what());
	}
	_initState = INIT_STATE_DISCONNECTED;
	m_portForwardingPort = 0;
}

//parameter : signalSelect - indicates that we want to signal the main thread to exit the select and reinit the connection
void LMEConnection::Deinit(bool signalSelect)
{
	FuncEntryExit<void> fee(this, L"Deinit");

	std::lock_guard<std::mutex> lock(_initLock);

	if (_initState != INIT_STATE_DISCONNECTED)
	{
		if (_devNotify != NULL)
		{
			if (_devNotify(_devNotifyParam, &_notifyHandle, static_cast<HANDLE>(NULL), false))
				_notifyHandle = NULL;
		}

		DeinitInternal();
	}

	if (signalSelect)
		_signalSelectCallback(_cbParam);
}

bool LMEConnection::Disconnect(APF_DISCONNECT_REASON_CODE reasonCode)
{
	FuncEntryExit<void> fee(this, L"Disconnect");

	std::vector<uint8_t> buf(sizeof(APF_DISCONNECT_MESSAGE));
	APF_DISCONNECT_MESSAGE *disconnectMessage = reinterpret_cast<APF_DISCONNECT_MESSAGE *>(buf.data());

	disconnectMessage->MessageType = APF_DISCONNECT;
	disconnectMessage->ReasonCode = htonl(reasonCode);

	UNS_DEBUG(L"==>LME: Disconnect.\n");
	bool res = _sendMessage(buf);

	_selfDisconnect = true;

	return res;
}

bool LMEConnection::ServiceAccept(const std::string &serviceName)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	auto messageLen = sizeof(APF_SERVICE_ACCEPT_MESSAGE) + serviceName.length();
	std::vector<uint8_t> buf(messageLen);
	auto apfSam = reinterpret_cast<APF_SERVICE_ACCEPT_MESSAGE*>(buf.data());

	apfSam->MessageType = APF_SERVICE_ACCEPT;
	apfSam->ServiceNameLength = htonl(static_cast<u_long>(serviceName.size()));
	// The apfSam allocate with enough place for serviceName
	std::copy(serviceName.begin(), serviceName.end(), apfSam->ServiceName);

	UNS_DEBUG(L"==>LME: Service accept: %C\n", serviceName.c_str());
	return _sendMessage(buf);
}

bool LMEConnection::UserAuthSuccess()
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	UNS_DEBUG(L"==>LME: User authentication success.\n");
	return _sendCommandMessage(APF_USERAUTH_SUCCESS);
}

bool LMEConnection::ProtocolVersion(const LMEProtocolVersionMessage &versionMessage)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_PROTOCOL_VERSION_MESSAGE));
	APF_PROTOCOL_VERSION_MESSAGE *protVersion = reinterpret_cast<APF_PROTOCOL_VERSION_MESSAGE *>(buf.data());

	protVersion->MessageType = APF_PROTOCOLVERSION;
	protVersion->MajorVersion = htonl(versionMessage.MajorVersion);
	protVersion->MinorVersion = htonl(versionMessage.MinorVersion);
	protVersion->TriggerReason = htonl(versionMessage.TriggerReason);

	UNS_DEBUG(L"==>LME: Protocol version: %d.%d.%d\n", versionMessage.MajorVersion, versionMessage.MinorVersion, versionMessage.TriggerReason);
	return _sendMessage(buf);
}

bool LMEConnection::TcpForwardReplySuccess(uint32_t port)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_TCP_FORWARD_REPLY_MESSAGE));
	APF_TCP_FORWARD_REPLY_MESSAGE* message = reinterpret_cast<APF_TCP_FORWARD_REPLY_MESSAGE*>(buf.data());

	message->MessageType = APF_REQUEST_SUCCESS;
	message->PortBound = htonl(port);

	UNS_DEBUG(L"==>LME: TCP forward replay success, Port %d.\n", port);
	return _sendMessage(buf);
}

bool LMEConnection::TcpForwardReplyFailure()
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	UNS_DEBUG(L"==>LME: TCP forward replay failure.\n");
	return _sendCommandMessage(APF_REQUEST_FAILURE);
}

bool LMEConnection::TcpForwardCancelReplySuccess()
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	UNS_DEBUG(L"==>LME: TCP forward cancel replay success.\n");
	return _sendCommandMessage(APF_REQUEST_SUCCESS);
}

bool LMEConnection::TcpForwardCancelReplyFailure()
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	UNS_DEBUG(L"==>LME: TCP forward cancel replay failure\n");
	return _sendCommandMessage(APF_REQUEST_FAILURE);
}

#define CHECK_BUFFER_OVERFLOW(nbytes) \
																if (bufferEnd <= (pCurrent + nbytes)) \
																{ \
																	UNS_ERROR(L"Buffer overflow %d %d %d\n", pCurrent, bufferEnd, nbytes); \
																	return false; \
																}

bool LMEConnection::ChannelOpenForwardedRequest(uint32_t senderChannel, const std::string &connectedIP, uint32_t connectedPort,
												const std::string &originatorIP, uint32_t originatorPort)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	auto bufferSize = 5 + APF_STR_SIZE_OF(APF_OPEN_CHANNEL_REQUEST_FORWARDED) + 16 +
		connectedIP.size() + 8 + originatorIP.size() + 4;
	std::vector<uint8_t> buf(bufferSize);
	unsigned char *pCurrent = buf.data();
	unsigned char *bufferEnd = buf.data() + bufferSize + 1;


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
	*((uint32_t *)pCurrent) = htonl(static_cast<u_long>(connectedIP.size())); pCurrent += sizeof(uint32_t);

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
	return _sendMessage(buf);
}

bool LMEConnection::ChannelOpenReplaySuccess(uint32_t recipientChannel, uint32_t senderChannel)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE));
	APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE* message = reinterpret_cast<APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE*>(buf.data());

	message->MessageType = APF_CHANNEL_OPEN_CONFIRMATION;
	message->RecipientChannel = htonl(recipientChannel);
	message->SenderChannel = htonl(senderChannel);
	message->InitialWindowSize = htonl(RX_WINDOW_SIZE);
	message->Reserved = 0xFFFFFFFF;

	UNS_DEBUG(L"==>LME[%d]: CHANNEL_OPEN_CONFIRMATION\n", recipientChannel);
	return _sendMessage(buf);
}

bool LMEConnection::ChannelOpenReplayFailure(uint32_t recipientChannel, uint32_t reason)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_CHANNEL_OPEN_FAILURE_MESSAGE));
	APF_CHANNEL_OPEN_FAILURE_MESSAGE* message = reinterpret_cast<APF_CHANNEL_OPEN_FAILURE_MESSAGE*>(buf.data());

	message->MessageType = APF_CHANNEL_OPEN_FAILURE;
	message->RecipientChannel = htonl(recipientChannel);
	message->ReasonCode = htonl(reason);
	message->Reserved = 0x00000000;
	message->Reserved2 = 0x00000000;

	UNS_DEBUG(L"==>LME[%d]: CHANNEL_OPEN_FAILURE, Reason: %d\n", recipientChannel, reason);
	return _sendMessage(buf);
}

bool LMEConnection::ChannelClose(uint32_t recipientChannel)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_CHANNEL_CLOSE_MESSAGE));
	APF_CHANNEL_CLOSE_MESSAGE* message = reinterpret_cast<APF_CHANNEL_CLOSE_MESSAGE*>(buf.data());

	message->MessageType = APF_CHANNEL_CLOSE;
	message->RecipientChannel = htonl(recipientChannel);

	UNS_DEBUG(L"==>LME[%d]: Channel close\n", recipientChannel);
	return _sendMessage(buf);
}

bool LMEConnection::ChannelData(uint32_t recipientChannel, uint32_t len, char *buffer)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	if (len > GetBufferSize() - sizeof(APF_CHANNEL_DATA_MESSAGE)) {
		return false;
	}

	_txBuffer.resize(sizeof(APF_CHANNEL_DATA_MESSAGE) + len);
	APF_CHANNEL_DATA_MESSAGE *message = reinterpret_cast<APF_CHANNEL_DATA_MESSAGE *>(_txBuffer.data());
	message->MessageType = APF_CHANNEL_DATA;
	message->RecipientChannel = htonl(recipientChannel);
	message->DataLength = htonl(len);
	// Data have at least len places, checked above
	std::copy_n(buffer, len, message->Data);

	UNS_TRACE(L"==>LME[%d]: %d bytes\n", recipientChannel, len);
	return _sendMessage(_txBuffer);
}

bool LMEConnection::ChannelWindowAdjust(uint32_t recipientChannel, size_t len)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	std::vector<uint8_t> buf(sizeof(APF_WINDOW_ADJUST_MESSAGE));
	APF_WINDOW_ADJUST_MESSAGE* message = reinterpret_cast<APF_WINDOW_ADJUST_MESSAGE*>(buf.data());

	message->MessageType = APF_CHANNEL_WINDOW_ADJUST;
	message->RecipientChannel = htonl(recipientChannel);
	message->BytesToAdd = htonl(static_cast<u_long>(len));

	UNS_TRACE(L"==>LME[%d]: Window Adjust with %B bytes\n", recipientChannel, len);
	return _sendMessage(buf);
}

bool LMEConnection::_sendMessage(const std::vector<uint8_t>& buffer)
{
	if (!IsInitialized())
	{
		UNS_DEBUG(L"State: not connected to HECI.\n");
		return false;
	}

	// Check if shutdown is in progress
	if (m_shutdownInProgress) {
		UNS_DEBUG(L"LMEConnection::_sendMessage - shutdown in progress, stop writing\n");
		return false;
	}

	try
	{
		return (_heci.Write(buffer) == buffer.size());
	}
	catch (const Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"Error sending data to HECI. Error: %C\n", e.what());
		return false;
	}
}

bool LMEConnection::_sendCommandMessage(uint8_t command)
{
	return _sendMessage(std::vector<uint8_t>(1, command));
}

void LMEConnection::_rxThreadFunc(void *param)
{
	LMEConnection *connection = (LMEConnection*)param;

	try {
		connection->_doRX();
	}

	catch (const std::exception &e) {
		UNS_ERROR(L"LMEConnection do RX exception %C\n", e.what());
	}
}

void LMEConnection::_doRX()
{
	_threadStartedEvent.signal();
	unsigned char *pCurrent;

	std::vector<uint8_t> rxBufferVector;
	unsigned char *rxBuffer;

	const std::string apf_auth_password(APF_AUTH_PASSWORD);

	while (true) {
		int status = 1;

		if (aceMgr_->testcancel(aceMgr_->thr_self()))
		{
			UNS_DEBUG(L"_doRX thread shutdown\n");
			break;
		}

		if (!IsInitialized())
		{
			UNS_DEBUG(L"State: not connected to HECI.\n");
			Deinit(true);
			break;
		}

		try
		{
			rxBufferVector = _heci.Read();
		}
		catch (const Intel::MEI_Client::MEIClientException& e)
		{
			UNS_ERROR(L"Error receiving data from HECI. Error: %C\n", e.what());
			Deinit(true);
			break;
		}

		if (aceMgr_->testcancel(aceMgr_->thr_self()))
		{
			UNS_DEBUG(L"_doRX thread shutdown\n");
			break;
		}


		if (rxBufferVector.size() == 0) {
			UNS_DEBUG(L"Receive zero-length data from HECI.\n");
			continue; // TBD Do we want to deinit?
		}

		rxBuffer = rxBufferVector.data();

		UNS_TRACE(L"LME==>: %d bytes, message type %02d\n", rxBufferVector.size(), rxBuffer[0]);

		uint32_t posBytesRead = (uint32_t)rxBufferVector.size();

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
					APF_SERVICE_REQUEST_MESSAGE *pMessage = (APF_SERVICE_REQUEST_MESSAGE *)rxBuffer;

					if ((posBytesRead < sizeof(APF_SERVICE_REQUEST_MESSAGE))) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					uint32_t len = ntohl(pMessage->ServiceNameLength);

					if (len > std::max(strlen(APF_SERVICE_PFWD), strlen(APF_SERVICE_AUTH)) ||
						posBytesRead < sizeof(APF_SERVICE_REQUEST) + len) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

					LMEServiceRequestMessage serviceRequestMessage;
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

					if (posBytesRead < sizeof(APF_GENERIC_HEADER)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

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
						if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
							UNS_ERROR(L"Error receiving data from HECI\n");
							Deinit(true);
							return;
						}

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
						if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
							UNS_ERROR(L"Error receiving data from HECI\n");
							Deinit(true);
							return;
						}

						tcpForwardCancelRequest.Address.append((char *)pCurrent, len); pCurrent += len;
						tcpForwardCancelRequest.Port = ntohl(*((uint32_t *)pCurrent));

						_cb(_cbParam, &tcpForwardCancelRequest, sizeof(tcpForwardCancelRequest), &status);
					}
					else if (_strnicmp((char *)pHeader->String, APF_GLOBAL_REQUEST_STR_UDP_SEND_TO,
													APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_UDP_SEND_TO)) == 0) {

						pCurrent = rxBuffer + sizeof(APF_GENERIC_HEADER) +
							APF_STR_SIZE_OF(APF_GLOBAL_REQUEST_STR_UDP_SEND_TO) + sizeof(uint8_t);

						uint32_t len = ntohl(*((uint32_t *)pCurrent)); pCurrent += sizeof(uint32_t);
						if ((posBytesRead - (pCurrent - rxBuffer)) < len) {
							UNS_ERROR(L"Error receiving data from HECI\n");
							Deinit(true);
							return;
						}

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

					if (posBytesRead < sizeof(APF_GENERIC_HEADER)) {
						UNS_ERROR(L"Error receiving data from HECI\n");
						Deinit(true);
						return;
					}

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
				UNS_ERROR(L"Unknown request from HECI. %d bytes, message type %02d\n", rxBufferVector.size(), rxBuffer[0]);
				break;
		}
	}
}
