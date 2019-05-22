/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: HOTHAMCommand.h

--*/

#ifndef __HOTHAM_COMMAND_H__
#define __HOTHAM_COMMAND_H__

#include "MEICommand.h"
#include "HOTHAMErrorException.h"
#include <mutex>

namespace Intel
{

namespace MEI_Client
{

namespace HOTHAM_Client
{
static const uint32_t HOTHAM_RESPONSE_STATUS_SUCCESS = 0x10;
static const uint32_t HOTHAM_COMMAND_CODE = 2;

// ====== Request Header

typedef union _HTM_MSG_HDR_REQ_TYPE_COMMON
{
	uint32_t ul;  ///< Whole register.

	struct
	{
		uint32_t Reserved : 31; ///< Bits 30:0 - Reserved, type 0/1 may not align
		uint32_t HeaderType : 1;  ///< Bit 31 - Corresponds to message type (0 or 1)
	} Fields;

} HTM_MSG_HDR_REQ_TYPE_COMMON;

typedef union _HTM_MSG_HDR_REQ_TYPE_0
{
	uint32_t   ul;  ///< Whole register.

	struct
	{
		uint32_t MsgClass : 2;  ///< Bits 1:0 - Message class (Continued, Control, Command, Pass through)
		uint32_t TargetId : 3;  ///< Bits 4:2 - Target Silicon ID
		uint32_t SequenceNo : 3;  ///< Bits 7:5 - Sequence Number
		uint32_t ReqCode : 8;  ///< Bits 15:8 - Request code (or opcode)
		uint32_t MsgLength : 12; ///< Bits 27:16  - Length of entire message, set to
		uint32_t Reserved : 3;  ///< Bits 30:28 -Reserved
		uint32_t HeaderType : 1;  ///< Bit 31 - Must be '0' on Type 0 messages
	} Fields;

} HTM_MSG_HDR_REQ_TYPE_0;

typedef union _HTM_MSG_HDR_REQUEST 
{
	uint32_t ul;
	HTM_MSG_HDR_REQ_TYPE_COMMON ReqHeaderCommon;
	HTM_MSG_HDR_REQ_TYPE_0 ReqHeaderType0;
	/* Type 1 header goes here */
} HTM_MSG_HDR_REQUEST;

// ====== Response Header

typedef union _HTM_MSG_HDR_RESP_TYPE_COMMON
{
	uint32_t ul;  ///< Whole register.
	struct
	{
		uint32_t Reserved : 31;  ///< Bits 30:0 - Reserved, type 0/1 may not align
		uint32_t HeaderType : 1;  ///< Bit 31 - Corresponds to message type (0 or 1)
	} Fields;

} HTM_MSG_HDR_RESP_TYPE_COMMON;

typedef union _HTM_MSG_HDR_RESP_TYPE_0
{
	uint32_t ul;  ///< Whole register.
	struct
	{
		uint32_t Reserved1 : 5;  ///< Bits 4:0 -Reserved
		uint32_t SequenceNo : 3;  ///< Bits 7:5 - Sequence Number
		uint32_t RespCode : 8;  ///< Bits 15:8 - Response code (or opcode)
		uint32_t MsgLength : 12; ///< Bits 27:16  - Length of entire message, set to
		uint32_t Reserved2 : 3;  ///< Bits 30:28 - Reserved
		uint32_t HeaderType : 1;  ///< Bit 31 - Must be '0' on Type 0 messages
	} Fields;

} HTM_MSG_HDR_RESP_TYPE_0;

typedef union _HTM_MSG_HDR_RESPONSE
{
	uint32_t ul;
	HTM_MSG_HDR_RESP_TYPE_COMMON RespHeaderCommon;
	HTM_MSG_HDR_RESP_TYPE_0 RespHeaderType0;
	/* Type 1 header goes here */
} HTM_MSG_HDR_RESPONSE;

class HOTHAMCommand : public Intel::MEI_Client::MEICommand
{
public:
	HOTHAMCommand() {}
	virtual ~HOTHAMCommand() {}	
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

class HOTHAMCommandRequest: public Intel::MEI_Client::MEICommandRequest
{
public:
	HOTHAMCommandRequest() {}
	virtual ~HOTHAMCommandRequest() {}
	virtual std::vector<uint8_t> Serialize();

private:
	
	std::vector<uint8_t> serializeHeader(const HTM_MSG_HDR_REQUEST& header);
	//returns the HOTHAM command number (in the header) of the request command
	virtual uint8_t requestHeaderReqCode() = 0;
	//returns the HOTHAM message class code (in the header) of the request command
	virtual uint8_t requestHeaderMsgClass() = 0;
	virtual std::vector<uint8_t> SerializeData()
	{
		//default no data
		std::vector<uint8_t> tmp;
		return tmp;
	}

};

template <typename T>
class HOTHAMCommandResponse : public Intel::MEI_Client::MEICommandResponse
{
public:
	HOTHAMCommandResponse(const std::vector<uint8_t>& buffer)
	{
		unsigned int headerAndStatSize = 0;
		verifyHeaderAndStatus(buffer, headerAndStatSize);
		verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
	}
	virtual ~HOTHAMCommandResponse() {}	
	T getResponse()
	{
		return m_result;
	}
protected:
	T m_result;
private:
	void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int & headerAndStatSize)
	{
		if (buffer.size() < sizeof(HTM_MSG_HDR_RESPONSE))
		{
			throw MEIClientException("Error: response buffer too short");
		}

		HTM_MSG_HDR_RESPONSE *header = (HTM_MSG_HDR_RESPONSE *)&buffer[0];
		if (header->RespHeaderType0.Fields.RespCode != HOTHAM_RESPONSE_STATUS_SUCCESS)
		{
			throw HOTHAMErrorException(header->RespHeaderType0.Fields.RespCode); 
		}

		headerAndStatSize = sizeof(HTM_MSG_HDR_RESPONSE);
	}
	void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
	{
		m_result.parse(itr, end);
	}
};

} // namespace HOTHAM_Client
} // namespace MEI_Client
} // namespace Intel

#endif //__HOTHAM_COMMAND_H__
