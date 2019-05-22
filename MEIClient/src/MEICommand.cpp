/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MEICommand.cpp

--*/

#include "MEICommand.h"
#include "StatusCodeDefinitions.h"
#include "heci.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {

		HECI* GenerateHECIClient(const GUID& guid, bool verbose = false)
		{
			return new HECI(guid, verbose);
		}

		HECI* GenerateLMEClient(bool verbose)
		{
			return GenerateHECIClient(LME_GUID, verbose);
		}

		void GetHeciDriverVersion(teeDriverVersion_t *heciVersion)
		{
			GUID guid(HECI_AMTHI_GUID);
			std::shared_ptr<HECI> heciClient(new HECI(guid));
			heciClient->Init();
			heciClient->GetHeciDriverVersion(heciVersion);
		}

		void MEICommand::Transact()
		{
			std::vector<uint8_t> buffer = m_request->Serialize();
			std::shared_ptr<HECI> heciClient(GenerateHECIClient(getGUID()));
			heciClient->Init();
			uint32_t inBuffSize = heciClient->GetBufferSize();
			unsigned int bytesWritten = 0;
			bytesWritten = heciClient->SendHeciMessage(&buffer[0], buffer.size(), 0);
			if (bytesWritten != buffer.size())
			{
				throw MEIClientException("Error: send message failed");
			}
			std::vector<uint8_t> readBuffer(inBuffSize, 0);

			bytesWritten = heciClient->ReceiveHeciMessage(&readBuffer[0], inBuffSize, 15000);
			if (bytesWritten > 0)
			{
				readBuffer.resize(bytesWritten);
				parseResponse(readBuffer);
			}
			else
			{
				throw MEIClientException("Error: Failed on RecieveResponse");
			}
		}

	} // MEI_Client
} // Intel


