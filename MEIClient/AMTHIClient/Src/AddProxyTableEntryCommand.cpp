/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetCertificateHashStateCommand.cpp

--*/

#include "AddProxyTableEntryCommand.h"

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

AddProxyTableEntryCommand::AddProxyTableEntryCommand(uint16_t proxyPort, uint8_t gatewayMAC[MAC_ADDRESS_SIZE],
	const std::string &proxyFQDN, const std::string &networkDnsSuffix)
{
	shared_ptr<MEICommandRequest> tmp(new AddProxyTableEntryRequest(proxyPort, gatewayMAC, proxyFQDN, networkDnsSuffix));
	m_request = tmp;
	Transact();
}

void 
AddProxyTableEntryCommand::reTransact(uint16_t proxyPort, uint8_t gatewayMAC[MAC_ADDRESS_SIZE],
	const std::string &proxyFQDN, const std::string &networkDnsSuffix)
{ 
	shared_ptr<MEICommandRequest> tmp(new AddProxyTableEntryRequest(proxyPort, gatewayMAC, proxyFQDN, networkDnsSuffix));
	m_request = tmp;
	Transact();
}

void
AddProxyTableEntryCommand::parseResponse(const vector<uint8_t>& buffer)
{	
	shared_ptr<AMTHICommandResponse<ADD_PROXY_TABLE_ENTRY_RESPONSE>> tmp(
	new AMTHICommandResponse<ADD_PROXY_TABLE_ENTRY_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

vector<uint8_t> 
AddProxyTableEntryRequest::SerializeData() {
	vector<uint8_t> tmp;
	vector<uint8_t> output;
	

	copy_n(reinterpret_cast<uint8_t*>(&_proxyPort), sizeof(_proxyPort), back_inserter(output));
	copy(begin(_gatewayMAC), end(_gatewayMAC), back_inserter(output));
	
	tmp = _proxyFQDN.serialize();
	copy(begin(tmp), end(tmp), back_inserter(output));

	tmp = _networkDnsSuffix.serialize();
	copy(begin(tmp), end(tmp), back_inserter(output));

	return output;	
}

