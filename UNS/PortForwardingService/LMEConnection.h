/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: LMEConnection.h

--*/

#ifndef __LME_CONNECTION_H__
#define __LME_CONNECTION_H__
#include "global.h"
#include "heci.h"

#include <memory>
#include <mutex>
#include <string>
#include <vector>
#include <ace/Thread.h>
#include <ace/Thread_Manager.h>
#include <ace/Event.h>
#include "LMS_if_constants.h"
#include "FuncEntryExit.h"

struct AuthMethodData {

};

struct AuthPasswordData : AuthMethodData {
	std::string Password;
};

struct LMEMessage {

	LMEMessage(APF_MESSAGE_TYPE type) : MessageType(type) {}
	const APF_MESSAGE_TYPE MessageType;
};

struct LMEDisconnectMessage  : LMEMessage {

	LMEDisconnectMessage(APF_DISCONNECT_REASON_CODE reasonCode) : LMEMessage(APF_DISCONNECT), 
		ReasonCode(reasonCode) {}

	APF_DISCONNECT_REASON_CODE ReasonCode;
};

struct LMEServiceRequestMessage  : LMEMessage {

	LMEServiceRequestMessage(const std::string &serviceName = std::string()) : LMEMessage(APF_SERVICE_REQUEST), 
		ServiceName(serviceName) {}

	std::string ServiceName;
};

struct LMEGlobalRequestMessage  : LMEMessage {

	enum REQUEST_TYPE
	{
		TCP_FORWARD_REQUEST,
		TCP_FORWARD_CANCEL_REQUEST,
		UDP_SEND_TO
	};

	LMEGlobalRequestMessage(REQUEST_TYPE type) : LMEMessage(APF_GLOBAL_REQUEST) , RequestType(type) {}

	const REQUEST_TYPE RequestType;
};

struct LMEProtocolVersionMessage : LMEMessage {

	LMEProtocolVersionMessage(uint32_t majorVersion = 0, uint32_t minorVersion = 0, 
		APF_TRIGGER_REASON triggerReason = LME_REQUEST) : 
		LMEMessage(APF_PROTOCOLVERSION), MajorVersion(majorVersion), MinorVersion(minorVersion),
		TriggerReason(triggerReason) {}
	
	uint32_t MajorVersion;
	uint32_t MinorVersion;
	APF_TRIGGER_REASON TriggerReason;
};

struct LMEUserAuthRequestMessage : LMEMessage {

	LMEUserAuthRequestMessage(const std::string &username = std::string(), const std::string &serviceName = std::string(),
		const std::string &methodName = std::string(), AuthMethodData *methodData = NULL) :
		LMEMessage(APF_USERAUTH_REQUEST), Username(username), ServiceName(serviceName),
		MethodName(methodName), MethodData(methodData) {}
	
	std::string Username;
	std::string ServiceName;
	std::string MethodName;

	AuthMethodData *MethodData;
};


struct LMETcpForwardRequestMessage : LMEGlobalRequestMessage {

	LMETcpForwardRequestMessage(const std::string &address = std::string(), uint32_t port = 0) :
					LMEGlobalRequestMessage(TCP_FORWARD_REQUEST), Address(address), Port(port) {}
	std::string Address;
	uint32_t Port;
};

struct LMETcpForwardCancelRequestMessage : LMEGlobalRequestMessage {

	LMETcpForwardCancelRequestMessage(const std::string &address = std::string(), uint32_t port = 0) :
				LMEGlobalRequestMessage(TCP_FORWARD_CANCEL_REQUEST), Address(address), Port(port) {}
	std::string Address;
	uint32_t Port;
};

struct LMEUdpSendToMessage : LMEGlobalRequestMessage {

	LMEUdpSendToMessage(const std::string &address, uint32_t port, uint32_t dataLength, uint8_t *data) :
		LMEGlobalRequestMessage(UDP_SEND_TO), Address(address), Port(port),
		Data(data, data + dataLength)
	{
	}

	~LMEUdpSendToMessage() {
	}

	LMEUdpSendToMessage (const LMEUdpSendToMessage& other): 
		LMEGlobalRequestMessage(UDP_SEND_TO), Address(other.Address),
		Port(other.Port), Data(other.Data) 
	{
	}

	const LMEUdpSendToMessage& operator = (const LMEUdpSendToMessage& other) 
	{
		if (&other==this)
			return *this;

		Address = other.Address;
		Port = other.Port;
		Data = other.Data;

		return *this;
	}

	std::string Address;
	uint32_t Port;
	std::vector<uint8_t> Data;
};

struct LMEChannelOpenRequestMessage  : LMEMessage {

	enum CHANNEL_TYPE
	{
		FORWARDED,
		DIRECT
	};

	LMEChannelOpenRequestMessage(CHANNEL_TYPE channelType = FORWARDED, uint32_t senderChannel = 0, 
		uint32_t initialWindow = 0, const std::string &address = std::string(), uint32_t port = 0) :
		LMEMessage(APF_CHANNEL_OPEN), ChannelType(channelType), SenderChannel(senderChannel),
		InitialWindow(initialWindow), Address(address), Port(port) {} 

	CHANNEL_TYPE ChannelType;
	uint32_t SenderChannel;
	uint32_t InitialWindow;
	std::string Address;
	uint32_t Port;
};

struct LMEChannelOpenReplaySuccessMessage  : LMEMessage {

	LMEChannelOpenReplaySuccessMessage(uint32_t recipientChannel = 0, uint32_t senderChannel = 0, 
		uint32_t initialWindow = 0) : 
		LMEMessage(APF_CHANNEL_OPEN_CONFIRMATION), RecipientChannel(recipientChannel),
		SenderChannel(senderChannel), InitialWindow(initialWindow) {} 

	uint32_t RecipientChannel;
	uint32_t SenderChannel;
	uint32_t InitialWindow;
};

struct LMEChannelOpenReplayFailureMessage  : LMEMessage {

	LMEChannelOpenReplayFailureMessage(uint32_t recipientChannel = 0, 
		OPEN_FAILURE_REASON reasonCode = OPEN_FAILURE_REASON_ADMINISTRATIVELY_PROHIBITED) : 
		LMEMessage(APF_CHANNEL_OPEN_FAILURE), RecipientChannel(recipientChannel),
		ReasonCode(reasonCode) {} 

	uint32_t RecipientChannel;
	OPEN_FAILURE_REASON ReasonCode;
};

struct LMEChannelCloseMessage  : LMEMessage {

	LMEChannelCloseMessage(uint32_t recipientChannel = 0) : 
		LMEMessage(APF_CHANNEL_CLOSE), RecipientChannel(recipientChannel) {} 

	uint32_t RecipientChannel;
};

struct LMEChannelDataMessage  : LMEMessage {

	LMEChannelDataMessage(uint32_t recipientChannel, uint32_t dataLength, uint8_t *data) : 
		LMEMessage(APF_CHANNEL_DATA), RecipientChannel(recipientChannel),
		Data(data, data + dataLength)
	{
	} 

	~LMEChannelDataMessage() {
	}

	LMEChannelDataMessage(LMEChannelDataMessage& other) : 
		LMEMessage(APF_CHANNEL_DATA), RecipientChannel(other.RecipientChannel), Data(other.Data)
	{
	}

	const LMEChannelDataMessage& operator = (LMEChannelDataMessage& other)
	{
		if (&other==this)
			return *this;

		RecipientChannel = other.RecipientChannel;
		Data = other.Data;

		return *this;
	}

	uint32_t RecipientChannel;
	std::vector<uint8_t> Data; 
};

struct LMEChannelWindowAdjustMessage  : LMEMessage {

	LMEChannelWindowAdjustMessage(uint32_t recipientChannel = 0, uint32_t bytesToAdd = 0) : 
		LMEMessage(APF_CHANNEL_WINDOW_ADJUST), RecipientChannel(recipientChannel), BytesToAdd(bytesToAdd) {} 

	uint32_t RecipientChannel;
	uint32_t BytesToAdd;
};

typedef void (*HECICallback) (void *param, void *buffer, unsigned int len, int *status);
typedef bool (*DeviceNotifyCallBack)(void *param, HDEVNOTIFY * hNotify, HANDLE drvHandle, bool regOrUnreg);
typedef void (*SignalSelectCallback) (void* protocol);



class LMEConnection {
public:
	LMEConnection(bool verbose = false);
	~LMEConnection();

	struct InitParameters
		{
		
		InitParameters(HECICallback heciCb, void * heciCbParam, 
							DeviceNotifyCallBack devNotifyCb, void * devNotifyCbParam, 
							ACE_Thread_Manager * threadMgr, SignalSelectCallback signalSelectCb) : 
							heciCb_(heciCb), heciCbParam_(heciCbParam), 
							devNotifyCb_(devNotifyCb), devNotifyCbParam_(devNotifyCbParam), 
							threadMgr_(threadMgr), signalSelectCb_(signalSelectCb) {}
							
			HECICallback heciCb_;
			void * heciCbParam_;
			
			DeviceNotifyCallBack devNotifyCb_;
			void * devNotifyCbParam_;
			
			ACE_Thread_Manager * threadMgr_;
			SignalSelectCallback signalSelectCb_;
		
		private:
			InitParameters();
		};

	bool Init(InitParameters & params);
	bool IsInitialized();
	bool Disconnect(APF_DISCONNECT_REASON_CODE reasonCode);
	bool ServiceAccept(const std::string &serviceName);
	bool UserAuthSuccess();
	bool ProtocolVersion(const LMEProtocolVersionMessage versionMessage);
	bool TcpForwardReplySuccess(uint32_t port);
	bool TcpForwardReplyFailure();
	bool TcpForwardCancelReplySuccess();
	bool TcpForwardCancelReplyFailure();
	bool ChannelOpenForwardedRequest(uint32_t sender, const std::string &connectedIP, uint32_t connectedPort, 
		const std::string &originatorIP, uint32_t originatorPort);
	bool ChannelOpenReplaySuccess(uint32_t recipient, uint32_t sender);
	bool ChannelOpenReplayFailure(uint32_t recipient, uint32_t reason);
	bool ChannelClose(uint32_t recipient);
	int  ChannelData(uint32_t recipient, uint32_t len, unsigned char *buffer);
	bool ChannelWindowAdjust(uint32_t recipient, uint32_t len);
	bool IsSelfDisconnect() { return _selfDisconnect; }
	bool IsClientNotFound() { return _clientNotFound; }
	//parameter : signalSelect - indicates that we want to signal the main thread to exit the select and reinit the connection
	void Deinit(bool signalSelect = false);
	const Intel::MEI_Client::HECI& GetHECI();

	enum INIT_STATES {
		INIT_STATE_DISCONNECTED = 0,
		INIT_STATE_CONNECTING,
		INIT_STATE_CONNECTED,
		INIT_STATE_DISCONNECTING,
	};

	static const uint32_t RX_WINDOW_SIZE;

private:
	static void _rxThreadFunc(void *param);

	void DeinitInternal();
	void _doRX();
	int _receiveMessage(unsigned char *buffer, int len);
	int _sendMessage(unsigned char *buffer, int len);

	unsigned char *_txBuffer;

	HECICallback _cb;
	SignalSelectCallback _signalSelectCallback; //callback for waking the service from the Select() to allow re-initilization 
	void *_cbParam;
	std::mutex _initLock;
	std::mutex _sendMessageLock;
	INIT_STATES _initState;
	INIT_STATES getInitState() { std::lock_guard<std::mutex> lock(_initLock); return _initState; }
	std::unique_ptr<Intel::MEI_Client::HECI> _heci;
	ACE_Event _threadStartedEvent;
	ACE_Event _portIsOk;

	HDEVNOTIFY _notifyHandle;
	DeviceNotifyCallBack  _devNotify;
	void *_devNotifyParam;
	bool _selfDisconnect;
	bool _clientNotFound;

	ACE_Thread_Manager * aceMgr_;
	ACE_thread_t _rxThread;
	

	template <typename T>
	using FuncEntryExit = FuncEntryExit_<T, LMEConnection>;
public:
	const wchar_t *short_name() const { return L"LMEC"; }
};

#endif
