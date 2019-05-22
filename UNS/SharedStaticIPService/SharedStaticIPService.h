/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef __SHAREDSTATICIPSERVICE_H_
#define __SHAREDSTATICIPSERVICE_H_

#include <ace/Acceptor.h>
#include <ace/INET_Addr.h>
#include <ace/SOCK_Stream.h>
#include <ace/SOCK_Acceptor.h>

#include "EventHandler.h"
#include "SharedStaticIPEventFilter.h"
#include "SHAREDSTATICIPSERVICE_export.h"
#include "SyncNetworkData.h"

struct nl_sock;

class SHAREDSTATICIPSERVICE_Export SharedStaticIPService : public EventHandler
{
  public:

	  SharedStaticIPService() : m_SharedStaticIP(false), m_SyncStaticIPStateOnce(false),
		  m_SyncStaticIP(false), m_SyncRetries(0),
#ifndef WIN32
		  m_sock(NULL),
#endif // WIN32
		  m_event(ACE_INVALID_HANDLE),
		  m_HandleStateRequiredButNoPfw(false), m_filter(new SharedStaticIPEventFilter) {}

	// ********************* ACE PART ********************************
    virtual int init (int argc, ACE_TCHAR *argv[]);

    virtual int fini (void);

	virtual int handle_close(ACE_HANDLE, ACE_Reactor_Mask);

	virtual void PreStop(int type, bool meiEnabled);

#ifdef WIN32
	virtual int handle_signal (int, siginfo_t *, ucontext_t *);
#else
	virtual int handle_input(ACE_HANDLE = ACE_INVALID_HANDLE);
#endif // WIN32

	virtual const ACE_TString name();

	virtual ACE_HANDLE get_handle() const;

	//*********************** business logic ****************************
protected:


	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual int handle_timeout (const ACE_Time_Value &current_time,const void *arg);

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return m_filter;
	}
	
private:

	class SSIP_Message_Block: public ACE_Data_Block
	{
	public:
		typedef enum SSIP_STATE { SSIP_GETSHAREDSTATICIPSTATE = 101, SSIP_SHAREDSTATICIPSTATE_DISABLED, SSIP_SHAREDSTATICIPSTATE_ENABLED, /*SSIP_SHAREDSTATICIPSTATE_SYNC, SSIP_DONOTHING*/   } SSIP_STATE;

		//SSIP_Message_Block() {};											
		//SSIP_Message_Block(const StartPFWUP& other) : Value(other.value) {};	
		SSIP_Message_Block(SSIP_STATE State) : Value(State) {}
		virtual ~SSIP_Message_Block();
		// Data members
		SSIP_STATE	Value;												
	};

	static const unsigned long CheckDNSInterval;
	static const unsigned long RetryInterval;

	// SharedStaticIP functions.
	bool setTimer(unsigned long Interval, SSIP_Message_Block::SSIP_STATE State);
	
	// Get the network settings (need for populate the MAC address)
	bool UpdateMacAddress();
	void SyncFwUpdateFailed();
	void SyncValidationFailed();
	
	bool m_SharedStaticIP;				// keep the feature state	
	bool m_SyncStaticIPStateOnce;		// if true we'll check the state for the first time we run
	bool m_SyncStaticIP;				// if true we'll need to sync the settings	
	uint32_t m_SyncRetries;				// The current retries to sync the network settings
	SyncNetworkData m_syncNetData;		// The object responsible to sync the network settings	
#ifdef WIN32
	HANDLE m_hand;
	OVERLAPPED m_overlap;
#else
	struct nl_sock *m_sock; // The NetLink socket to obtain ping on settins change
#endif // WIN32
	ACE_HANDLE m_event;

	void free_event();

	void MoveToState(SSIP_Message_Block::SSIP_STATE State, unsigned long Interval);
	void HandleState(SSIP_Message_Block::SSIP_STATE State);

	bool SyncSettings(unsigned long & TimerInterval);
	bool GetSharedStaticIpState(bool * IsEnabled);
	bool NetworkSettingsChanged();
	
	int handlePublishEvent(const GMS_AlertIndication & alert);
	bool m_HandleStateRequiredButNoPfw;
	std::shared_ptr<SharedStaticIPEventFilter> m_filter;
};

#endif /* __SHAREDSTATICIPSERVICE_H_ */
