/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MEICommand.h

--*/

#ifndef __MEI_COMMAND_H__
#define __MEI_COMMAND_H__
#include "heci.h"
#include "MEIClientException.h"
#include <memory>
#include <vector>

namespace Intel
{

namespace MEI_Client
{
class MEICommandRequest;
class MEICommandResponse;

HECI* GenerateLMEClient(bool verbose = false);
void GetHeciDriverVersion(teeDriverVersion_t *heciVersion);

class MEICommand
{
public:
	MEICommand() {}
	virtual ~MEICommand() {}

protected:
	std::shared_ptr <MEICommandRequest> m_request;
	void Transact();

private:
	virtual const GUID& getGUID() = 0;
	virtual void parseResponse(const std::vector<uint8_t>& buffer) = 0;

};

class MEICommandRequest
{
public:
	MEICommandRequest() {}
	virtual ~MEICommandRequest() {}
	virtual std::vector<uint8_t> Serialize() = 0;
};

class MEICommandResponse
{
public:
	MEICommandResponse() {}
	virtual ~MEICommandResponse() {}

};

template <class T> std::vector<uint8_t> serializeHeader(const T& header)
{
	std::vector<uint8_t> output(sizeof(T), 0);
	const uint8_t* tmp = reinterpret_cast<const uint8_t*>(&header);
	std::copy(tmp, tmp + sizeof(T), output.begin());
	return output;
}

} // namespace MEI_Client
} // namespace Intel

#endif //__MEI_COMMAND_H__
