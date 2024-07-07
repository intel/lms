/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
/*++

@file: MEICommand.cpp

--*/

#include "MEICommand.h"
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

		void GetHeciDriverVersion(std::string& ver)
		{
			GUID guid(HECI_AMTHI_GUID);
			std::shared_ptr<HECI> heciClient(new HECI(guid));
			heciClient->Init();
			heciClient->GetHeciDriverVersion(ver);
		}

		void MEICommand::Transact()
		{
			std::vector<uint8_t> buffer = m_request->Serialize();
			std::shared_ptr<HECI> heciClient(GenerateHECIClient(getGUID()));
			heciClient->Init();
			size_t inBuffSize = heciClient->GetBufferSize();
			size_t bytesWritten = 0;
			bytesWritten = heciClient->SendHeciMessage(&buffer[0], buffer.size(), 5000);
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
				throw MEIClientExceptionZeroBuffer("Error: Failed on RecieveResponse");
			}
		}

	} // MEI_Client
} // Intel


