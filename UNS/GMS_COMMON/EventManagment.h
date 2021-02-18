/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2021 Intel Corporation
 */
#ifndef __EVENTMANAGMENT_H_
#define __EVENTMANAGMENT_H_

#include "global.h"
#include <ace/SString.h>
#include "MessageBlockPtr.h"
#include <memory>
#include <vector>
#include <string>
#include "GMSCommonDllExport.h"

enum { MB_SUBSCRIBE_EVENT = ACE_Message_Block::MB_USER,MB_UNSUBSCRIBE_EVENT,
		MB_PUBLISH_EVENT, MB_PFWU_EVENT,MB_PFWU_START_EVENT,
		MB_IPREFRESH_LAN, MB_IPREFRESH_WLAN,MB_CONFIGURATION_CHANGE, MB_CONFIGURATION_START,
		MB_CONFIGURATION_STOP, MB_CONFIGURATION_RESUME, MB_CONFIGURATION_SUSPEND,
		MB_SERVICE_STATUS_CHANGED, MB_STOP_SERVICE, MB_SUSPEND_SERVICE,
		MB_MEI_DISABLE_FAILED, MB_PORT_FORWARDING_STARTED, MB_PORT_FORWARDING_STOPPED,
		MB_DEVICE_EVENT, MB_TIMER_EXPIRED, MB_SRVICE_UP, MB_PWR_OPR_START_EVENT, MB_ME_CONFIGURED,
		MB_TASK_COMPLETED, MB_DEFERRED_RESUME, MB_WTS_SESSION_UNLOCK, MB_WPFS_SYNC};

struct GMS_COMMON_EXPORT GmsEventType {
	unsigned short	category;
	unsigned long	id;
	ACE_CString message;
	GmsEventType() :category(0), id(0), message() {}
	GmsEventType(unsigned short o_category,unsigned long o_id) :
		category(o_category),id(o_id), message() {}
	GmsEventType(unsigned short o_category,unsigned long o_id,const char* o_message) :
		category(o_category),id(o_id), message(o_message) {}
	GmsEventType(const GmsEventType &other) :
		category(other.category), id(other.id), message(other.message) {}
	GmsEventType &operator=(const GmsEventType &other)
	{
		if (&other == this)
			return *this;
		category = other.category;
		id = other.id;
		message = other.message;
		return *this;
	}
};


class GMS_COMMON_EXPORT GMS_AlertIndication: public ACE_Data_Block
{
public:
	GMS_AlertIndication(): category(0), id(0) {} ;	// Default constructor
	GMS_AlertIndication(const GMS_AlertIndication& other): // Copy constructor
		category(other.category),
		id(other.id),
		Datetime(other.Datetime),
		MessageID(other.MessageID),
		Message(other.Message),
		MessageArguments(other.MessageArguments){}
	GMS_AlertIndication(unsigned short o_category, unsigned long o_id,
		const std::string &o_Datetime, const ACE_TString &o_MessageID, const ACE_TString &o_Message):
		category(o_category), id(o_id), Datetime(o_Datetime), MessageID(o_MessageID), Message(o_Message) {}
	GMS_AlertIndication(unsigned short o_category, unsigned long o_id,
		const std::string &o_Datetime, const ACE_TString &o_MessageID, const ACE_TString &o_Message, const ACE_TString &o_MessageArgument):
		category(o_category), id(o_id), Datetime(o_Datetime), MessageID(o_MessageID), Message(o_Message)
	{ MessageArguments.push_back(o_MessageArgument); }
	GMS_AlertIndication &operator=(const GMS_AlertIndication &other) = delete;

	virtual ~GMS_AlertIndication(){} // Destructor

	// Data members
	unsigned short	category;  // event category
	unsigned long	id;      // event id
	std::string	  Datetime;   // event date time as standard ctime string
	ACE_TString   MessageID;  // event messageID
	ACE_TString   Message;    // event message description
	//currently just one argument is supported and is appended to Message
	std::vector<ACE_TString>  MessageArguments; // addition to message
};

class GMS_COMMON_EXPORT EventsFilter
{
public:
	EventsFilter() {}
	virtual ~EventsFilter() {}
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const = 0;
};

class GMS_COMMON_EXPORT SubscribeEventHandler: public ACE_Data_Block
{
public:
	SubscribeEventHandler() {};	// Default constructor
	SubscribeEventHandler(const ACE_TString &serviceName, const std::shared_ptr<EventsFilter> &filter):
		serviceName_(serviceName), filter_(filter){}
	SubscribeEventHandler(const SubscribeEventHandler &) = delete; // Copy constructor
	virtual ~SubscribeEventHandler(){} // Destructor
	SubscribeEventHandler &operator=(const SubscribeEventHandler &other) = delete;

	const ACE_TString   serviceName_;   // event date time as standard ctime string
	std::shared_ptr<EventsFilter>	   filter_;
};

class GMS_COMMON_EXPORT UnSubscribeEventHandler: public ACE_Data_Block
{
public:
	UnSubscribeEventHandler() : meiEnabled_(false) {};	// Default constructor
	UnSubscribeEventHandler(const ACE_TString &serviceName, bool meiEnabled):
		serviceName_(serviceName), meiEnabled_(meiEnabled){}
	UnSubscribeEventHandler(const UnSubscribeEventHandler &) = delete; // Copy constructor
	virtual ~UnSubscribeEventHandler(){} // Destructor
	UnSubscribeEventHandler &operator=(const UnSubscribeEventHandler &other) = delete;

	const ACE_TString   serviceName_;
	bool meiEnabled_;
};

typedef enum
{
	ME_ENABLE_CONF,
	AMT_ENABLE_CONF,
	IP_SYNC_CONF,
	TIME_SYNC_CONF,
	PFW_ENABLE_CONF,
	WIFI_PROFILE_SYNC_CONF,
	AMT_PROVISION_CONF,
	WRONG_CONFIGURATION_TYPE
} CONFIGURATION_TYPE;

class GMS_COMMON_EXPORT ChangeConfiguration: public ACE_Data_Block
{
public:
	ChangeConfiguration() : type(WRONG_CONFIGURATION_TYPE), value(0)  {};	// Default constructor
	ChangeConfiguration(const ChangeConfiguration& other): // Copy constructor
		type(other.type),
			value(other.value){};
	ChangeConfiguration(CONFIGURATION_TYPE o_type,int o_value) :
		type(o_type),value(o_value) {}
	virtual ~ChangeConfiguration(){}; // Destructor
	ChangeConfiguration &operator=(const ChangeConfiguration &other) = delete;

	// Data members
	CONFIGURATION_TYPE	type;  // type of changed configuration
	int 	value;      // the new configuration
};

class GMS_COMMON_EXPORT StartPFWUP: public ACE_Data_Block
{
public:
	StartPFWUP() : value(0) {};											// Default constructor
	StartPFWUP(const StartPFWUP& other):value(other.value){};	// Copy constructor
	StartPFWUP(unsigned short o_value) :
		value(o_value) {}
	virtual ~StartPFWUP(){};							// Destructor
	StartPFWUP &operator=(const StartPFWUP &other) = delete;

	// Data members
	short 	value;												// Language to update
};

class GMS_COMMON_EXPORT DeviceEventDataBlock : public ACE_Data_Block
{
public:
	DeviceEventDataBlock() : eventType(0), wasOnOurGuid(false) {};// Default constructor
	DeviceEventDataBlock(const DeviceEventDataBlock& other) :
		eventType(other.eventType), wasOnOurGuid(other.wasOnOurGuid){}// Copy constructor
	DeviceEventDataBlock(unsigned long o_eventType, bool o_wasOnOurGuid) :
		eventType(o_eventType), wasOnOurGuid(o_wasOnOurGuid) {}
	virtual ~DeviceEventDataBlock(){}// Destructor
	DeviceEventDataBlock &operator=(const DeviceEventDataBlock &other) = delete;

	// Data members
	unsigned long eventType;
	bool wasOnOurGuid;
};

class GMS_COMMON_EXPORT StopServiceDataBlock: public ACE_Data_Block
{
public:
	StopServiceDataBlock():m_meiEnabled(true) {};											// Default constructor
	StopServiceDataBlock(const StopServiceDataBlock& other):m_meiEnabled(other.m_meiEnabled){};	// Copy constructor
	StopServiceDataBlock(bool meiEnabled):m_meiEnabled(meiEnabled) {}
	virtual ~StopServiceDataBlock(){};							// Destructor
	StopServiceDataBlock &operator=(const StopServiceDataBlock &other) = delete;

	// Data members
	bool m_meiEnabled;
};

	typedef enum
	{
		STATUS_UNLOADCOMPLETE,
		STATUS_LOADCOMPLETE,
		STATUS_SUSPENDCOMPLETE,
		STATUS_RESUMECOMPLETE,
		SERVICE_STATUS_UNKNOWN,
	} SERVICE_STATUS_TYPE;

class GMS_COMMON_EXPORT ServiceStatus: public ACE_Data_Block
{
public:
	ServiceStatus() : serviceName(), status(SERVICE_STATUS_UNKNOWN) {};	// Default constructor
	ServiceStatus(const ServiceStatus& other): serviceName(other.serviceName),status(other.status){};// Copy constructor
	ServiceStatus(const ACE_TString &o_serviceName, SERVICE_STATUS_TYPE o_status) :
		serviceName(o_serviceName),
		status(o_status){};
	virtual ~ServiceStatus(){}; // Destructor
	ServiceStatus &operator=(const ServiceStatus &other) = delete;

	// Data members
	const ACE_TString   serviceName;
	SERVICE_STATUS_TYPE 	status;      // the new status
};


class GMS_COMMON_EXPORT PortForwardingStoppedBlock : public ACE_Data_Block
{
public:
	PortForwardingStoppedBlock() :m_publishFailure(false) {};											// Default constructor
	PortForwardingStoppedBlock(const PortForwardingStoppedBlock& other) :m_publishFailure(other.m_publishFailure) {};	// Copy constructor
	PortForwardingStoppedBlock(bool failure) :m_publishFailure(failure) {}
	virtual ~PortForwardingStoppedBlock() {};							// Destructor
	PortForwardingStoppedBlock &operator=(const PortForwardingStoppedBlock &other) = delete;

	bool m_publishFailure;														// Data members
};
#endif /* __EVENTMANAGMENT_H_ */
