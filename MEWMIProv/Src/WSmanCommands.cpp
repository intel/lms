/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: WSmanCommands.cpp

--*/

// PTHI_Commands.cpp : Implementation of CPTHI_Commands

#include "stdafx.h"
#include "WSmanCommands.h"
#include "SIOWSManClient.h"
#include "KVMWSManClient.h"
#include "AMTRedirectionServiceWSManClient.h"
#include "EthernetSettingsWSManClient.h"
#include "StringManipulator.h"
#include "MNGIsChangeToAMTEnabledCommand.h"

WSmanCommands::WSmanCommands()
{
	Intel::MEI_Client::Manageability_Client::MNGIsChangeToAMTEnabledCommand cmd;
	Intel::MEI_Client::Manageability_Client::IsChangedEnabledResponse res = cmd.getResponse();
	m_port = (res.TlsOnLocalPorts) ? AMT_SECURE_PORT : AMT_NON_SECURE_PORT;
}

UINT32 WSmanCommands::setSpriteZoom(short zoom)
{
	SIOWSManClient sio(m_port);
	if (sio.SetSpriteZoom(zoom) != true)
		return 1;
	else
		return 0; 
}

UINT32 WSmanCommands::TerminateKVMSession(void)
{
	KVMWSManClient kvm(m_port);

	if (kvm.TerminateKVMSession() != true)
		return 1;

	return 0;

}

UINT32 WSmanCommands::isIDEREnabled(bool *enabled)
{
	AMTRedirectionServiceWSManClient redirectionClient(m_port);
	unsigned short state;
	*enabled = false;

	if (redirectionClient.RedirectionState(&state) != true)
		return 1;

	switch (state)
	{
	case IDER_SOL_ENABLED:
		*enabled = true;
		break;
	case IDER_ENABLED_SOL_DISABLED:
		*enabled = true;
		break;
	case IDER_DISABLED_SOL_ENABLED:
		*enabled = false;
		break;
	case IDER_SOL_DISABLED:
		*enabled = false;
		break;
	default:
		return 1;
	}
	return 0;
}

UINT32 WSmanCommands::isSOLEnabled(bool *enabled)
{
	AMTRedirectionServiceWSManClient redirectionClient(m_port);
	unsigned short state;
	*enabled = false;

	if (redirectionClient.RedirectionState(&state) != true)
		return 1;

	switch (state)
	{
	case IDER_SOL_ENABLED:
		*enabled = true;
		break;
	case IDER_ENABLED_SOL_DISABLED:
		*enabled = false;
		break;
	case IDER_DISABLED_SOL_ENABLED:
		*enabled = true;
		break;
	case IDER_SOL_DISABLED:
		*enabled = false;
		break;
	default:
		return 1;
	}
	return 0;
}

UINT32 WSmanCommands::isKVMActive(bool* enabled, bool* active)
{
	KVMWSManClient kvm(m_port);
	unsigned short state;
	*enabled = false;

	if (kvm.KVMRedirectionState(&state) != true)
		return 1;

	switch (state)
	{
		case 2:
				*enabled = true;
				*active = true;
				break;
		case 3:
				*enabled = false;
				*active = false;
				break;
		case 6:
				*enabled = true;
				*active = false;
				break;
		default:
				return 1;
		
	}
	return 0;
}

UINT32 WSmanCommands::GetPortSettings(std::vector<EthernetPortEntryWSMan> &ethernetPortList)
{
	EthernetSettingsWSManClient client(m_port);
	std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> ethernetSettings;
	std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>>::iterator settingsIterator;

	unsigned int response = client.Enumerate(ethernetSettings);
	if (response == S_OK)
	{
		for (settingsIterator = ethernetSettings.begin(); 
			 settingsIterator != ethernetSettings.end() ; 
			 settingsIterator++)
		{
			EthernetPortEntryWSMan entry;
			entry.LinkIsUp = false;
			entry.DHCPEnabled = false;

			if(settingsIterator->get()->DefaultGatewayExists())
				entry.DefaultGateway = ToWStr(settingsIterator->get()->DefaultGateway());
			if (settingsIterator->get()->DHCPEnabledExists())
				entry.DHCPEnabled = settingsIterator->get()->DHCPEnabled();
			if (settingsIterator->get()->IPAddressExists())
				entry.IPAddress = ToWStr(settingsIterator->get()->IPAddress());
			if (settingsIterator->get()->LinkIsUpExists())
				entry.LinkIsUp = settingsIterator->get()->LinkIsUp();
			if (settingsIterator->get()->MACAddressExists())
				entry.MACAddress = ToWStr(settingsIterator->get()->MACAddress());
			if (settingsIterator->get()->PrimaryDNSExists())
				entry.PrimaryDNS = ToWStr(settingsIterator->get()->PrimaryDNS());
			if (settingsIterator->get()->SecondaryDNSExists())
				entry.SecondaryDNS = ToWStr(settingsIterator->get()->SecondaryDNS());
			if (settingsIterator->get()->SubnetMaskExists())
				entry.SubnetMask = ToWStr(settingsIterator->get()->SubnetMask());
			ethernetPortList.push_back(entry);
		}
	}
	if (response == EthernetSettingsWSManClient::ERROR_UNKNOWN_ERROR)
	{
		response = ERR_UKNOWN_CONNECTION_ERROR;
	}
	
	return response;
}
