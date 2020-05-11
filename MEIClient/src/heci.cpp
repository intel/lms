/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: heci.cpp

--*/

#include <vector>
#include <string>
#include <sstream>
#include "heci.h"
#include "HECIException.h"

namespace Intel {
namespace MEI_Client {

HECI::~HECI()
{
	Deinit();
}

void HECI::Init()
{
	TEESTATUS ret = TEE_INTERNAL_ERROR;
	bool client_not_found = false;

	if (_initialized)
		return;

#ifdef WIN32
	std::vector<const char*> devices = { NULL };
#else
	std::vector<const char*> devices =
		{"/dev/mei0", "/dev/mei1", "/dev/mei2", "/dev/mei3"};
#endif // WIN32
	std::stringstream err;
	for (std::vector<const char*>::const_iterator it = devices.begin();
	    it != devices.end(); it++) {
		ret = TeeInit(&_handle, &_guid, *it);
		if (!TEE_IS_SUCCESS(ret)) {
			err << ((*it) ? *it : "NULL") << " init " << ret << " ";
			continue;
		}

		ret = TeeConnect(&_handle);
		if (!TEE_IS_SUCCESS(ret)) {
			err << ((*it) ? *it : "NULL") << " connect " << ret << " ";
			if (ret == TEE_CLIENT_NOT_FOUND)
				client_not_found = true;
			TeeDisconnect(&_handle);
			continue;
		}

		_bufSize = _handle.maxMsgLen;
		_initialized = true;
		return;
	}

	_initialized = false;

	if (client_not_found)
		throw HeciNoClientException("Client not found. " + err.str(), TEE_CLIENT_NOT_FOUND);
	else
		throw HECIException("Error in connecting to HECI. " + err.str(), ret);
}

void HECI::Deinit()
{
	if (_initialized) {
		TeeDisconnect(&_handle);
		_initialized = false;
	}
}

unsigned int HECI::ReceiveHeciMessage(unsigned char *buffer, int len, unsigned long timeout)
{
	TEESTATUS ret;
	size_t numberOfBytesRead;

	if (!_initialized)
		throw HECIException("Not initialized");

	ret = TeeRead(&_handle, buffer, len, &numberOfBytesRead, timeout);
	if (!TEE_IS_SUCCESS(ret))
		throw HECIException("Read failed", ret);

	return numberOfBytesRead;
}

unsigned int HECI::SendHeciMessage(const unsigned char *buffer, int len, unsigned long timeout)
{
	TEESTATUS ret;
	size_t numberOfBytesWritten;

	if (!_initialized)
		throw HECIException("Not initialized");

#ifdef __linux__
	// Workaround for Linux kernels before 4.17
	// These kernels does not support select before write
	timeout = 0;
#endif // __linux__

	ret = TeeWrite(&_handle, buffer, len, &numberOfBytesWritten, timeout);
	if (!TEE_IS_SUCCESS(ret))
		throw HECIException("Write failed", ret);

	return numberOfBytesWritten;
}

void* HECI::GetHandle()
{
	if (!_initialized)
		throw HECIException("Not initialized");

	return reinterpret_cast<void*>(TeeGetDeviceHandle(&_handle));
}

void HECI::GetHeciDriverVersion(teeDriverVersion_t *heciVersion)
{
	TEESTATUS ret;

	if (!_initialized)
		throw HECIException("Not initialized");

	ret = GetDriverVersion(&_handle, heciVersion);
	if (!TEE_IS_SUCCESS(ret))
		throw HECIException("GetDriverVersion failed", ret);
}
}} // namespace
