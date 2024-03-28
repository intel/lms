/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
/*++

@file: AMTHICommand.h

--*/

#ifndef __AMTHI_COMMAND_H__
#define __AMTHI_COMMAND_H__

#include "MEICommand.h"
#include "AMTHIErrorException.h"
#include "StatusCodeDefinitions.h"
#include <string>
#include <mutex>

namespace Intel
{
namespace MEI_Client
{
namespace AMTHI_Client
{
typedef uint32_t AMT_BOOLEAN;
static const uint32_t AMT_FALSE = 0;
static const uint32_t AMT_TRUE = 1;

typedef uint32_t AMT_STATUS;

//IPv4_ADDRESS is defined to represent IP version 4 addresses IP Addresses are
//represented per [IP] i.e. value: 0x01020304 ip addr: 1.2.3.4
typedef uint32_t CFG_IPv4_ADDRESS;

#pragma pack(1)
static const size_t CFG_IP_ADDR_LEN_MAX = 46;

struct CFG_IP_ADDR
{
	uint8_t Address[CFG_IP_ADDR_LEN_MAX];

	std::string toString()
	{
		char* tmp = (char*)&Address[0];
		return std::string(tmp);
	}
};

typedef struct _AMTHI_VERSION
{
	uint8_t   MajorNumber;
	uint8_t   MinorNumber;
} AMTHI_VERSION;

typedef struct _COMMAND_FMT_
{
	union
	{
		uint32_t  val;
		struct
		{
			uint32_t   Operation   : 23;
			uint32_t   IsResponse  : 1;
			uint32_t   Class       : 8;
		} fields;
	} cmd;
} COMMAND_FMT_;

enum AMT_PROVISIONING_STATE
{
	PROVISIONING_STATE_PRE = 0,
	PROVISIONING_STATE_IN = 1,
	PROVISIONING_STATE_POST = 2
};

enum INTERFACE_SETTINGS	//uint32_t
{
	WIRED = 0,
	WIRELESS = 1
};

typedef struct _AMTHI_MESSAGE_HEADER
{
	AMTHI_VERSION Version;
	uint16_t       Reserved;
	COMMAND_FMT_  Command;
	uint32_t       Length;
} AMTHI_MESSAGE_HEADER;

enum CFG_PROVISIONING_MODE	//uint32_t 
{
	CFG_PROVISIONING_MODE_NONE = 0,
	CFG_PROVISIONING_MODE_ENTERPRISE = 1,
};

const uint8_t AMT_MAJOR_VERSION = 1;
const uint8_t AMT_MINOR_VERSION = 1;
#pragma pack()

class AMTHICommand : public Intel::MEI_Client::MEICommand
{
public:
	AMTHICommand() {}
	virtual ~AMTHICommand() {}
	// To avoid multiple HECI client calls
	static std::mutex& getInternalSemaphore();
	protected:
		void Transact();

private:
	virtual const GUID& getGUID();
	friend class SemaphoreInitializer;
	class SemaphoreInitializer
	{
		SemaphoreInitializer();
		static SemaphoreInitializer initializer;
	};
	
};

class AMTHICommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	AMTHICommandRequest(unsigned int requestHeaderCommandNumber) : m_requestHeaderCommandNumber(requestHeaderCommandNumber) {}
	virtual ~AMTHICommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:

	std::vector<uint8_t> serializeHeader(const AMTHI_MESSAGE_HEADER& header);
	virtual uint32_t requestDataSize() { return 0; };
	virtual std::vector<uint8_t> SerializeData()
	{
		//default no data
		std::vector<uint8_t> tmp;
		return tmp;
	}
	//the AMTHI command number (in the header) of the request command
	unsigned int m_requestHeaderCommandNumber;
};

template <typename T>
class AMTHICommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public:
	AMTHICommandResponse() : m_result(), m_commandNumber(0) {}
	AMTHICommandResponse(AMTHICommandResponse&& other) = default;
	AMTHICommandResponse& operator = (AMTHICommandResponse&& other) = default;

	AMTHICommandResponse(const std::vector<uint8_t>& buffer, unsigned int commandNumber): m_result()
	{
		m_commandNumber = commandNumber;
		unsigned int headerAndStatSize =0;
		verifyHeaderAndStatus(buffer, headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~AMTHICommandResponse() {}
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
	unsigned int m_commandNumber;
private:
	void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int & headerAndStatSize)
	{
		if (buffer.size() < sizeof(AMTHI_MESSAGE_HEADER) + sizeof(AMT_STATUS))
		{
			throw  MEIClientException("Error: response buffer too short.");
		}

		AMTHI_MESSAGE_HEADER *header = (AMTHI_MESSAGE_HEADER *)&buffer[0];
		if ((header->Command.cmd.val != getCommandNumber()) ||
			(header->Length != (buffer.size() - sizeof(AMTHI_MESSAGE_HEADER))))
		{
			throw MEIClientException("Error: AMTHI Command number is incorrect." );
		}
		AMT_STATUS *status = (AMT_STATUS*)&(buffer[sizeof(AMTHI_MESSAGE_HEADER)]);
		if (*status != AMT_STATUS_SUCCESS)
		{
			throw AMTHIErrorException(*status);
		}
		headerAndStatSize = sizeof(AMTHI_MESSAGE_HEADER)+sizeof(AMT_STATUS);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
	unsigned int getCommandNumber() { return m_commandNumber; };
};
} // namespace AMTHI_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__AMTHI_COMMAND_H__
