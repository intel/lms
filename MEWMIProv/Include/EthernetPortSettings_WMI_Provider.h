/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: EthernetPortSettings_WMI_Provider.h

--*/

#pragma once
#include "WMIInfrastructure.h"
#include "PTHI_Commands.h"

class EthernetPortSettings_WMI_Provider
{
public:
	std::wstring ElementName;
	std::wstring InstanceID;
	std::wstring MACAddress;
	boolean	LinkIsUp;
	boolean DHCPEnabled;
	std::wstring IPAddress;
	std::wstring SubnetMask;
	std::wstring DefaultGateway;
	std::wstring PrimaryDNS;
	std::wstring SecondaryDNS;

	static HRESULT Enumerate(
		IWbemServices* pNamespace,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);

	static HRESULT Get_PortSettings(
		IWbemServices* pNamespace,
		const BSTR strObjectPath,
		IWbemContext __RPC_FAR *pCtx,
		IWbemObjectSink __RPC_FAR *pResponseHandler);
	static HRESULT EnumerateEthernetPortSettings(
		std::vector<EthernetPortSettings_WMI_Provider>& settingsVec,
		uint32& ReturnValue);
	
	static uint32 GetPortList(
		std::vector<EthernetPortEntry>& ethernetPortList);

	~EthernetPortSettings_WMI_Provider() { };
private:
	EthernetPortSettings_WMI_Provider(
		const EthernetPortEntry &port,
		const std::wstring &instanceID,
		const std::wstring &elementName);
};
