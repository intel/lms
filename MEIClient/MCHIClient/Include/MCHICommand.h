/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022 Intel Corporation
 */
/*++

@file: MCHICommand.h

--*/

#ifndef __MCHI_COMMAND_H__
#define __MCHI_COMMAND_H__

#include "MEICommand.h"
#include "MCHIErrorException.h"
#include <string>
#include <iostream>
#include <mutex>

namespace Intel
{
namespace MEI_Client
{
namespace MCHI_Client
{

enum MCHIGroups
{
	MCHI_GROUP_ID_MCA = 0xA,
};

typedef union _MCHI_MSG_HEADER
{
	uint32_t Data;
	struct
	{
		uint32_t GroupId :8; // Kernel Client specific Info for dispatching
		uint32_t Command :7; // Command code specific to HECI client
		uint32_t IsResponse :1; // Set to 1 in ACK/response message
		uint32_t Reserved :8;
		uint32_t Result :8; // Result of the request message
	} Fields;
} MCHI_MSG_HEADER;

class MCHICommand : public Intel::MEI_Client::MEICommand
{
public:
	MCHICommand() {}
	virtual ~MCHICommand() {}
	// To avoid multiple HECI client calls
	static std::mutex& getInternalSemaphore();
protected:
	void Transact()
	{
		std::lock_guard<std::mutex> lock(getInternalSemaphore());
		MEICommand::Transact();
	}

private:
	virtual const GUID& getGUID();
	friend class SemaphoreInitializer;
	class SemaphoreInitializer
	{
		SemaphoreInitializer();
		static SemaphoreInitializer initializer;
	};
};

class MCHICommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	MCHICommandRequest() {}
	virtual ~MCHICommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:

	std::vector<uint8_t> serializeHeader(const MCHI_MSG_HEADER& header);
	//returns the AMTHI command number (in the header) of the request command
	virtual uint32_t requestHeaderCommandNumber() = 0;
	virtual uint32_t requestHeaderGroupID() = 0;
	virtual uint32_t requestDataSize() = 0;
	virtual std::vector<uint8_t> SerializeData()
	{
		//default no data
		std::vector<uint8_t> tmp;
		return tmp;
	}
};

template <typename T>
class MCHICommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public:
	MCHICommandResponse(const std::vector<uint8_t>& buffer, unsigned int commandNumber, unsigned int groupID) : m_result()
	{
		m_commandNumber = commandNumber;
		m_groupID = groupID;
		unsigned int headerAndStatSize =0;
		verifyHeaderAndStatus(buffer,  headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~MCHICommandResponse() {}
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
	unsigned int m_commandNumber;
	unsigned int m_groupID;

private:
	void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int& headerAndStatSize)
	{
		if (buffer.size() < sizeof(MCHI_MSG_HEADER))
		{
			throw MEIClientException("Error: response buffer too short");
		}

		MCHI_MSG_HEADER *header = (MCHI_MSG_HEADER*)&buffer[0];
		if ((header->Fields.Command != getCommandNumber()) || (header->Fields.GroupId != getGroupID()) ||
			(header->Fields.IsResponse != 1))
		{
			throw MEIClientException("Error: MCHI Command number/ Group ID/ is response is incorrect" );
		}
		if (header->Fields.Result == MCA_STATUS_NO_FILE)
		{
			throw MCHIErrorExceptionNoFile(header->Fields.Result);
		}
		if (header->Fields.Result != MCA_STATUS_SUCCESS)
		{
			throw MCHIErrorException(header->Fields.Result);
		}
		headerAndStatSize = sizeof(MCHI_MSG_HEADER);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
	unsigned int getCommandNumber() { return m_commandNumber; }
	unsigned int getGroupID() { return m_groupID; }
};

} // namespace MCHI_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__MCHI_COMMAND_H__
