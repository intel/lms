/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
/*++

@file: MKHICommand.h

--*/

#ifndef __MKHI_COMMAND_H__
#define __MKHI_COMMAND_H__

#include "MEICommand.h"
#include "MKHIErrorException.h"
#include <string>
#include <iostream>
#include <mutex>

namespace Intel
{
namespace MEI_Client
{
namespace MKHI_Client
{

enum MKHIGroups
{
	MKHI_CBM_GROUP_ID = 0x0,
	MKHI_PM_GROUP_ID,
	MKHI_PWD_GROUP_ID,
	MKHI_FWCAPS_GROUP_ID,
	MKHI_APP_GROUP_ID,
	MKHI_HMRFPO_GROUP_ID,
	MKHI_FWUPDATE_GROUP_ID,
	MKHI_MAX_GROUP_ID,
	MKHI_GEN_GROUP_ID = 0xff
};

//Macro to build a rule identifier. for Me rules all other fields are zeros
#define MAKE_ME_RULE_ID(FeatureId, RuleId)  ((FeatureId << 16) | RuleId)
#define ME_RULE_FEATURE_ID                            0
#define MEFWCAPS_FW_SKU_RULE                          0
#define MEFWCAPS_ME_FW_UPDATE_RULE                    7
#define MEFWCAPS_PCV_OEM_PLAT_TYPE_CFG_RULE           29
#define MEFWCAPS_FEATURE_ENABLE_RULE                  32
#define MEFWCAPS_AVAILABLE_BITMAP_RULE                39
#define MEFWCAPS_SKU_RULE_ID                          MAKE_ME_RULE_ID(ME_RULE_FEATURE_ID,MEFWCAPS_FW_SKU_RULE)
#define MEFWCAPS_ME_FW_UPDATE_RULE_ID                 MAKE_ME_RULE_ID(ME_RULE_FEATURE_ID,MEFWCAPS_ME_FW_UPDATE_RULE)
#define MEFWCAPS_PCV_OEM_PLAT_TYPE_CFG_RULE_ID        MAKE_ME_RULE_ID(ME_RULE_FEATURE_ID,MEFWCAPS_PCV_OEM_PLAT_TYPE_CFG_RULE)
#define MEFWCAPS_FEATURE_ENABLE_RULE_ID               MAKE_ME_RULE_ID(ME_RULE_FEATURE_ID, MEFWCAPS_FEATURE_ENABLE_RULE)
#define MEFWCAPS_AVAILABLE_BITMAP_RULE_ID             MAKE_ME_RULE_ID(ME_RULE_FEATURE_ID,MEFWCAPS_AVAILABLE_BITMAP_RULE)

typedef union _RULE_ID
{
	uint32_t      Data;
	struct
	{
		uint32_t   RuleTypeId     :16;
		uint32_t   FeatureId      :8;
		uint32_t   Reserved       :8;
	} Fields;
} RULE_ID;

typedef union _MKHI_MSG_HEADER
{
	uint32_t	Data;
	struct
	{
		uint32_t    GroupId	:8;	// Kernel Client specific Info for dispatching
		uint32_t    Command	:7;	// Command code specific to HECI client
		uint32_t    IsResponse	:1;	// Set to 1 in ACK/response message
		uint32_t    Reserved	:8;
		uint32_t    Result	:8;	// Result of the request message
	} Fields;
} MKHI_MSG_HEADER;

class MKHICommand : public Intel::MEI_Client::MEICommand
{
public:
	MKHICommand() {}
	virtual ~MKHICommand() {}
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

class MKHICommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	MKHICommandRequest() {}
	virtual ~MKHICommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:

	std::vector<uint8_t> serializeHeader(const MKHI_MSG_HEADER& header);
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
class MKHICommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public:
	MKHICommandResponse(const std::vector<uint8_t>& buffer, unsigned int commandNumber, unsigned int groupID) : m_result()
	{
		m_commandNumber = commandNumber;
		m_groupID = groupID;
		unsigned int headerAndStatSize =0;
		verifyHeaderAndStatus(buffer,  headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~MKHICommandResponse() {}
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
	unsigned int m_commandNumber;
	unsigned int m_groupID;

private:
	void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int & headerAndStatSize)
	{
		if (buffer.size() < sizeof(MKHI_MSG_HEADER))
		{
			throw  MEIClientException("Error: response buffer too short");
		}

		MKHI_MSG_HEADER *header = (MKHI_MSG_HEADER *)&buffer[0];
		if ((header->Fields.Command!= getCommandNumber()) || (header->Fields.GroupId!=getGroupID()) ||
			(header->Fields.IsResponse!=1))
		{
			throw MEIClientException("Error: MKHI Command number/Group ID/ is response is incorrect" );
		}

		if (header->Fields.Result!= MKHI_STATUS_SUCCESS)
		{
			throw Intel::MEI_Client::MKHI_Client::MKHIErrorException(header->Fields.Result);
		}
		headerAndStatSize = sizeof(MKHI_MSG_HEADER);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
	unsigned int getCommandNumber() { return m_commandNumber; }
	unsigned int getGroupID() { return m_groupID; }
};

template <typename T>
class MKHIGetRuleCommandResponse : Intel::MEI_Client::MEICommandResponse
{
public:
	MKHIGetRuleCommandResponse(const std::vector<uint8_t>& buffer, unsigned int commandNumber, unsigned int groupID,
		unsigned int ruleID)
	{
		m_commandNumber = commandNumber;
		m_groupID = groupID;
		m_ruleID = ruleID;
		unsigned int headerAndStatSize = 0;
		verifyHeaderAndStatus(buffer,  headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~MKHIGetRuleCommandResponse() {}
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
	unsigned int m_commandNumber;
	unsigned int m_groupID;
	unsigned int m_ruleID;

private:
	void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int & headerAndStatSize)
	{
		if (buffer.size() < sizeof(MKHI_MSG_HEADER)+ sizeof(RULE_ID)+sizeof(uint8_t))
		{
			throw  MEIClientException("Error: response buffer too short");
		}

		MKHI_MSG_HEADER *header = (MKHI_MSG_HEADER *)&buffer[0];
		if ((header->Fields.Command!= getCommandNumber()) || (header->Fields.GroupId!=getGroupID()) ||
			(header->Fields.IsResponse!=1))
		{
			throw MEIClientException("Error: MKHI Command number/Group ID/ is response is incorrect", header->Data );
		}

		if (header->Fields.Result!= MKHI_STATUS_SUCCESS)
		{
			throw Intel::MEI_Client::MKHI_Client::MKHIErrorException(header->Fields.Result);
		}
		headerAndStatSize = sizeof(MKHI_MSG_HEADER);
		RULE_ID *ruleID = (RULE_ID *)&(buffer[headerAndStatSize]);
		if (ruleID->Data!= getRuleID())
		{
			 throw MEIClientException("Error: MKHI RuleID is incorrect", ruleID->Data );
		}
		headerAndStatSize += sizeof(RULE_ID);
		uint8_t *RuleDataLen = (uint8_t *)&(buffer[headerAndStatSize]);
		if (*RuleDataLen!= sizeof(T))
		{
			std::stringstream ob;
			ob << std::hex << buffer[0];
			for (int i = 1; i <= 8; i++)
				ob << " " << std::hex << buffer[i];
#ifdef WIN32
			OutputDebugStringA(ob.str().c_str());
#else
			std::cout << ob.str() << std::endl;
#endif // WIN32
			throw MEIClientException("Error: MKHI RuleDataLen is incorrect", *RuleDataLen );
		}
		headerAndStatSize += sizeof(uint8_t);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
	unsigned int getCommandNumber() { return m_commandNumber; }
	unsigned int getGroupID() { return m_groupID; }
	unsigned int getRuleID() { return m_ruleID; }
};

} // namespace MKHI_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__MKHI_COMMAND_H__
