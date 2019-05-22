/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: FWUpdateCommand.h

--*/

#ifndef __FW_UPDATE_COMMAND_H__
#define __FW_UPDATE_COMMAND_H__

#include <mutex>
#include "MEICommand.h"
#include "FWUpdateErrorException.h"
#include "FWUpdateCodeDefinitions.h"

namespace Intel
{

namespace MEI_Client
{

namespace FWUpdate_Client
{

typedef uint32_t FWUpdate_STATUS;

struct FWUpdate_MESSAGE_HEADER 
{
	uint32_t MessageID;
};

struct FWU_VERSION
{
	uint16_t				 Major;
	uint16_t				 Minor;
	uint16_t				 Hotfix;
	uint16_t				 Build;
};


class FWUpdateCommand : public Intel::MEI_Client::MEICommand
{
public:
	FWUpdateCommand() {}
	virtual ~FWUpdateCommand() {}	
	// To avoid multiple FWU HECI client calls
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

class FWUpdateCommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	FWUpdateCommandRequest() {}
	virtual ~FWUpdateCommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:
	
	std::vector<uint8_t> serializeHeader(const FWUpdate_MESSAGE_HEADER& header);
	//returns the FWUpdate command number (in the header) of the request command
	virtual unsigned int requestHeaderMessageID() = 0;
	virtual std::vector<uint8_t> SerializeData()
	{
		//default no data
		std::vector<uint8_t> tmp;
		return tmp;
	}
};

template <typename T>
class FWUpdateCommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public: 	
	FWUpdateCommandResponse(const std::vector<uint8_t>& buffer, unsigned int commandNumber)
	{
		m_commandNumber = commandNumber;
		unsigned int headerAndStatSize =0;
		verifyHeaderAndStatus(buffer, headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~FWUpdateCommandResponse() {}	
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
		if (buffer.size() < sizeof(FWUpdate_MESSAGE_HEADER) + sizeof(FWUpdate_STATUS))
		{
			throw MEIClientException("Error: response buffer to short.");
		}

		FWUpdate_MESSAGE_HEADER *header = (FWUpdate_MESSAGE_HEADER *)&buffer[0];
		if (header->MessageID != getCommandNumber())
		{
			throw MEIClientException("Error: FWUpdate Command number is incorrect.");
		}
		FWUpdate_STATUS *status = (FWUpdate_STATUS*)&(buffer[sizeof(FWUpdate_MESSAGE_HEADER)]);
		if (*status != FW_UPDATE_STATUS_SUCCESS)
		{
			throw FWUpdateErrorException(*status);
		}
		headerAndStatSize = sizeof(FWUpdate_MESSAGE_HEADER)+sizeof(FWUpdate_STATUS);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
	unsigned int getCommandNumber() { return m_commandNumber; };
};

} // namespace FWUpdate_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__FW_UPDATE_COMMAND_H__
