/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: PowerManagementCapabilitiesWsManClient.cpp

--*/


#include "PowerManagementCapabilitiesWsManClient.h"
#include <algorithm>
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

//These are the supported values of PowerStatesSupported
// 2=On, corresponding to ACPI state G0 or S0 or D0. 
// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 
// 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 
// 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 
// 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderlyshutdown. 
// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
// ..=DMTF Reserved. 
// 0x7FFF..0xFFFF = Vendor Specific.

//we need only the following values:
enum PowerStates
{
	SLEEP = 4,
    HIBERNATE = 7,
	GRACEFUL_SHUTDOWN = 12,
	GRACEFUL_RESET = 14
};

PowerManagementCapabilitiesClient::PowerManagementCapabilitiesClient() : m_isInit(false)
{
}

PowerManagementCapabilitiesClient::PowerManagementCapabilitiesClient(const std::string &User, const std::string &Password) :
	BaseWSManClient(User, Password), m_isInit(false)
{
}

PowerManagementCapabilitiesClient::~PowerManagementCapabilitiesClient()
{
}

bool PowerManagementCapabilitiesClient::Init(bool forceGet)
{
	WSMAN_DEBUG("PowerManagementCapabilitiesClient::Init\n");
	if (!forceGet && m_isInit) return true;
	m_isInit = false;
	
	try 
	{
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();
		m_isInit = true;
		WSMAN_DEBUG("PowerManagementCapabilitiesClient::Initialized\n");
	}
	CATCH_exception("PowerManagementCapabilitiesClient::Init")
	return m_isInit;	
}

/*
	This function is used to update the given vector, to include or exclude the given capability.
	params:
	bool insert: whether the capability should be included (when true) in the vector or excluded (when false).
	unsigned short capability - the capability to include or exclude.
	vector<unsigned short> &capabilities - the vector to make the changes on.
	return:
	true, if changes have been made to the vector, false otherwise.
*/
bool updateCapability(bool insert, unsigned short capability, std::vector<unsigned short> &capabilities){
	bool result = false;
	std::vector<unsigned short>::iterator position = find(capabilities.begin(), capabilities.end(), capability);
	bool exists = (position != capabilities.end());
	if (insert && !exists) { // the value is not present in the vector - add it
		WSMAN_DEBUG("Adding the value %d. PowerManagementCapabilitiesClient::updateCapability\n", capability);
		capabilities.push_back(capability);
		result = true;
	}
	else if (!insert && exists) { //the vector contains this value, remove it.
		WSMAN_DEBUG("Removing the value %d. PowerManagementCapabilitiesClient::updateCapability\n", capability);
		capabilities.erase(position);
		result = true;
	}
	return result;
}

bool PowerManagementCapabilitiesClient::addGracefulOperations(bool sleep,bool hibernate)
{
	try
	{
		if (!Init())
			return false;

		std::lock_guard<std::mutex> lock(WsManSemaphore()); //Lock WsMan to prevent reentry
	
		//use PowerStatesSupportedExists() to know if PSS is supported (should be true all the time)
		if(m_service.PowerStatesSupportedExists()){
			//indicates whether the PSS should be rewritten, if it has been changed.
			bool changed = false;
			//checking the inclusion/declusion of a capability in the capabilities vector
			std::vector<unsigned short> capabilities(m_service.PowerStatesSupported());
			// graceful shutdown and reset are supported:
			changed |= updateCapability(true, GRACEFUL_SHUTDOWN, capabilities);
			changed |= updateCapability(true, GRACEFUL_RESET, capabilities);
			// graceful sleep and hibernate are supported only if stated so in the input of this function
			changed |= updateCapability(sleep, SLEEP, capabilities);
			changed |= updateCapability(hibernate, HIBERNATE, capabilities);
			if (changed) {
				WSMAN_DEBUG("Updating the capabilities. PowerManagementCapabilitiesClient::addGracefulOperations\n");
				m_service.PowerStatesSupported(capabilities);
				m_service.Put();
			}
		}
		else {//Not supported - return false
			WSMAN_DEBUG("PSS is not supported - unexpected FW behavior. PowerManagementCapabilitiesClient::addGracefulOperations\n");
			return false;
		}
	}
	CATCH_exception_return("PowerManagementCapabilitiesClient::addGracefulOperations")
	return true;
}

/*
* This function check whether Remote Graceful Power Operations are supported 
* (by reading the value of PowerStatesSupportedExists property).
* returns false if there was an error retrieving the value,
* and fills the value in the given bool referance.
*/
bool PowerManagementCapabilitiesClient::GetPowerOperationsSupport(bool & support)
{
	support = false;
	try{
		if (!Init())
			return false;
		support = m_service.RequestedPowerStatesSupportedExists(); 
	}
	CATCH_exception_return("PowerManagementCapabilitiesClient::GetPowerOperationsSupport")
	return true;
}

	//for Unit testing
#ifdef _DEBUG
	std::vector<unsigned short>  PowerManagementCapabilitiesClient::getCapsVector()
	{
		if (!Init())
			return std::vector<unsigned short>();

		std::lock_guard<std::mutex> lock(WsManSemaphore()); //Lock WsMan to prevent reentry
			
		return m_service.PowerChangeCapabilities();
	}

	std::string PowerManagementCapabilitiesClient::getOtherCapsString()
	{
		if(!Init())
			return "";

		std::lock_guard<std::mutex> lock(WsManSemaphore()); //Lock WsMan to prevent reentry

		if (!m_service.OtherPowerChangeCapabilitiesExists())
			return "";

		return m_service.OtherPowerChangeCapabilities();
	}
#endif
