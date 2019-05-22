/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: ManageabilityCommand.h

--*/

#ifndef __MANAGEABILITY_COMMAND_H__
#define __MANAGEABILITY_COMMAND_H__

#include <mutex>
#include "MEICommand.h"
#include "ManageabilityErrorException.h"

namespace Intel
{

namespace MEI_Client
{

namespace Manageability_Client
{
typedef uint32_t Manageability_STATUS;

struct Manageability_MESSAGE_HEADER 
{
	uint8_t CMD;
	uint8_t BytesCount;
	uint8_t SubCmd;
	uint8_t Version;
};

class ManageabilityCommand : public Intel::MEI_Client::MEICommand
{
public:
	static std::mutex& getInternalSemaphore();
	ManageabilityCommand() {}
	virtual ~ManageabilityCommand() {}
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

class ManageabilityCommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	ManageabilityCommandRequest() {}
	virtual ~ManageabilityCommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:
	
	std::vector<uint8_t> serializeHeader(const Manageability_MESSAGE_HEADER& header);
	//returns the Manageability command number (in the header) of the request command
	virtual uint8_t requestHeaderCMD() = 0;
	virtual uint8_t requestHeaderSubCMD() = 0;
	virtual uint8_t requestDataSize() = 0;

	virtual std::vector<uint8_t> SerializeData()
	{
		//default no data
		std::vector<uint8_t> tmp;
		return tmp;
	}

};

template <typename T>
class ManageabilityCommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public:
	ManageabilityCommandResponse(const std::vector<uint8_t>& buffer)
	{
		verifyAndGenerateResponse(buffer.begin(), buffer.end());
	}
	virtual ~ManageabilityCommandResponse() {}	
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
private:
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
};

} // namespace Manageability_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__MANAGEABILITY_COMMAND_H__
