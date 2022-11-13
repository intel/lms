/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
/*++

@file: Protocol.h

--*/

#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <mutex>
#include <map>
#include <vector>
#include <string> 
#include "LMEConnection.h"
#include "PortForwardRequest.h"
#include "Channel.h"
#include <ace/Pipe.h>
#include "FuncEntryExit.h"

#ifdef WIN32
#include <windows.h>
#else
#include <netdb.h>
#endif // WIN32

#ifdef _REMOTE_SUPPORT
#include "AdapterListInfo.h"
#endif

typedef void (*EventLogCallback) (void *param, const char* message);

class Protocol {
public:

	struct InitParameters
		{
		InitParameters(EventLogCallback evtLogCbWrn, EventLogCallback evtLogCbDbg, DeviceNotifyCallBack devNotifyCb,
			void * evtLogParam, ACE_Thread_Manager * threadMgr):
			evtLogCbWrn_(evtLogCbWrn), evtLogCbDbg_(evtLogCbDbg), devNotifyCb_(devNotifyCb), evtLogParam_(evtLogParam), threadMgr_(threadMgr) {}
			
				
			EventLogCallback evtLogCbWrn_;
			EventLogCallback evtLogCbDbg_;
			DeviceNotifyCallBack devNotifyCb_;
			void * evtLogParam_;
			ACE_Thread_Manager * threadMgr_;
		private:
			InitParameters();
		};

	static const LMEProtocolVersionMessage MIN_PROT_VERSION; 
	static const LMEProtocolVersionMessage MAX_PROT_VERSION;

	enum class SOCKET_STATUS {
		ACTIVE = 0,
		NOT_CREATED,
		LINGER_ERROR,
		NOT_BINDED,
		NOT_EXCLUSIVE_ADDRESS,
		NOT_LISTENED,
		CONDITIONAL_ACCEPT_ERROR,
		CANT_REUSE_ADDRESS,
		NO_IPV6_V6ONLY
	};

	Protocol();
	~Protocol();

	bool CreateSockets();
	void DestroySockets();
	bool SocketsCreated() { return _sockets_active; }
	bool IsInitialized() { return _lme.IsInitialized(); }
	bool Init(InitParameters & params);
	int Select();
	void Deinit();
	void SignalSelect();
	LMEConnection& GetLMEConnection();
	int checkAcceptLogic(sockaddr_storage& caller_addr, unsigned int port, PortForwardRequest* PW_req);

	bool IsClientNotFound() { return _clientNotFound; }
private:
	static void _LmeCallback(void *param, void *buffer, unsigned int len, int *status);
	static int _isLocalCallback(void *const param, SOCKET s, sockaddr_storage* caller_addr);
	//callback for waking the service from the Select() to allow re-initilization 
	static void _SignalSelectCallback(void *protocol);
#ifdef _REMOTE_SUPPORT
	static void _AdapterCallback(void *param, SuffixMap &localDNSSuffixes);
	static int _isRemoteCallback(void *const param, SOCKET sock, sockaddr_storage* caller_addr);
#endif	
	bool _checkProtocolFlow(LMEMessage *message);
	void _closePortForwardRequest(PortForwardRequest *p); 
	void _LmeReceive(void *buffer, unsigned int len, int *status);
	void _signalSelect();
	static int _closeSocket(SOCKET s);
	SOCKET _createSocket(const addrinfo *addr, SOCKET_STATUS &status);
	bool _setSockOptions(const addrinfo &addr,SOCKET s, SOCKET_STATUS &status);
	std::vector<SOCKET> _createServerSocket(unsigned int family, unsigned int port, SOCKET_STATUS &status,bool cond_accept = false);
	bool _acceptConnection(SOCKET s, unsigned int port);
	bool _setNonBlocking(SOCKET s, bool enable);
	int _rxFromSocket(SOCKET s);
	int _isLocal(SOCKET s, sockaddr_storage* connction_sockaddr = NULL) const;
	int _handleFQDNChange(const char *fqdn);
	int _updateIPFQDN(const std::string &fqdn);
	PortForwardRequest* _findFWReq(SOCKET sock, unsigned int port, sockaddr_storage* caller_addr);
	void _checkRemoteAccessStatus();
	bool _remoteTunnelExist();

#ifdef _REMOTE_SUPPORT
	
	int _isRemote(SOCKET s) const;
	bool _checkRemoteSupport(bool requestDnsFromAmt = false);
	bool _updateEnterpriseAccessStatus(const SuffixMap &localDNSSuffixes, bool sendAnyWay = false);
	bool _isRemoteAPFAddress(std::string addr);

#endif
	SOCKET _connect(addrinfo *addr, unsigned int port, int type, long timeOut = 0);
	void _TCPCleanup();
	//void _TCPCleanupIPv6()

	struct Connection {
		SOCKET s;
	};

	typedef std::vector<PortForwardRequest *> PortForwardRequestList;
	typedef std::map<unsigned int, PortForwardRequestList> PortMap;
	typedef std::map<SOCKET, Channel *> ChannelMap;

	LMEConnection _lme;

	bool _sockets_active;
	ACE_Pipe _signalPipe; // Used to notify Select() to check new available channels
	PortMap _openPorts;
	ChannelMap _openChannels;
	std::mutex _portsLock;
	std::mutex _channelsLock;
	std::mutex _deleteLock;
	char *_rxSocketBuffer;
	size_t _rxSocketBufferSize;

#ifdef _REMOTE_SUPPORT
	std::vector<std::string> _AMTDNSSuffixes;
	mutable std::mutex _AMTDNSLock;
	bool _remoteAccessEnabledInAMT;
	bool _remoteAccessCurrentlyPossible;
	mutable std::mutex _remoteAccessLock;
#endif

	enum class VERSION_HANDSHAKING {
		NOT_INITIATED,
		INITIATED,
		AGREED
	};

	enum class SERVICE_STATUS {
		NOT_STARTED,
		STARTED,
	};

	VERSION_HANDSHAKING _handshakingStatus;
	SERVICE_STATUS _pfwdService;
	LMEProtocolVersionMessage _AmtProtVersion;
	std::mutex _versionLock;
	
	std::string _AMTFQDN;
	EventLogCallback _eventLogWrn;
	EventLogCallback _eventLogDbg;
	void *_eventLogParam;
	bool _OutHostsFileLog;
	typedef std::map<uint32_t, bool> PortFailureReports;
	PortFailureReports _failureReported;
	bool _clientNotFound;

	template <typename T>
	using FuncEntryExit = FuncEntryExit_<T, Protocol>;
public:
	const wchar_t *short_name() const { return L"PROT"; }};

#endif // _PROTOCOL_H_
