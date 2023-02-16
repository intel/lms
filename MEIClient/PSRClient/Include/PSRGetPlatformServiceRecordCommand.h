/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021-2023 Intel Corporation
 */
/*++

@file: PSRGetPlatformServiceRecordCommand.h

--*/

#ifndef __PSR_GET_PLATFORMSERVICE_RECORD_COMMAND_H__
#define __PSR_GET_PLATFORMSERVICE_RECORD_COMMAND_H__

#include <array>
#include "MEIparser.h"
#include "PSRCommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace PSR_Client
		{
			const size_t PSR_NONCE_SIZE = 20;
			const size_t PSR_UUID_LENGTH = 16;
			const size_t PSR_CRITICAL_EVENTS_NUM_MAX = 100;

			const size_t PSR_MAX_CERT_CHAIN_SIZE = 3000;
			const size_t PSR_ODCA_CHAIN_LEN = 4;
			const size_t PSR_MAX_SIGNATURE_LENGTH = 512;

			const size_t UPID_PLATFORM_ID_LENGTH = 64;
			const size_t SHA512_LEN_BYTES = 64;

			const size_t PSR_GENESIS_FIELD_INFO_SIZE = 64;
			const size_t PSR_GENESIS_DATA_STORE_INFO_SIZE = 1024;

			const uint8_t PSR_LOG_NOT_STARTED = 0;
			const uint8_t PSR_LOG_STARTED = 1;
			const uint8_t PSR_LOG_STOPPED = 2;

			const uint8_t PSR_EVENT_START = 8;
			const uint8_t PSR_EVENT_STOP = 9;
			const uint8_t PSR_EVENT_MAX_EVENT = 10;
			const uint8_t PSR_EVENT_RP_INF_FAIL = 16;
			const uint8_t PSR_EVENT_PSR_MISSING = 17;
			const uint8_t PSR_EVENT_PSR_INVALID = 18;
			const uint8_t PSR_EVENT_PRTC_FAILURE = 19;
			const uint8_t PSR_EVENT_RECOVERY_STATE = 20;
			const uint8_t PSR_EVENT_DAM_STATE = 21;
			const uint8_t PSR_EVENT_UNLOCK_STTE = 22;
			const uint8_t PSR_EVENT_SVN_INCREASE = 23;
			const uint8_t PSR_EVENT_CHASSIS_INTRUSION = 32;

			#pragma pack(1)
			struct PSR_GET_REQUEST
			{
				uint8_t user_nonce[PSR_NONCE_SIZE];
			};

			struct PSR_GENESIS_RECORD
			{
				uint32_t genesis_date;
				uint8_t  oem_info[PSR_GENESIS_FIELD_INFO_SIZE];
				uint8_t  oem_make_info[PSR_GENESIS_FIELD_INFO_SIZE];
				uint8_t  oem_model_info[PSR_GENESIS_FIELD_INFO_SIZE];
				uint8_t  manuf_country[PSR_GENESIS_FIELD_INFO_SIZE];
				uint8_t  oem_data_store[PSR_GENESIS_DATA_STORE_INFO_SIZE];
			};

			struct PSR_LEDGER_RECORD
			{
				uint32_t s0_seconds_counter;
				uint32_t s0_to_s5_counter;
				uint32_t s0_to_s4_counter;
				uint32_t s0_to_s3_counter;
				uint32_t warm_reset_counter;
				uint32_t reserved[11];
			};

			struct PSR_CRITICAL_EVENT
			{
				uint8_t  event_id;
				uint8_t  reserved[3];
				uint32_t timestamp;
				uint32_t data;
			};

			struct PSR_GET_RESPONSE
			{
				uint32_t log_state;
				uint16_t psr_version_major;
				uint16_t psr_version_minor;
				uint8_t  psrid[PSR_UUID_LENGTH];
				uint8_t  upid[UPID_PLATFORM_ID_LENGTH];
				struct PSR_GENESIS_RECORD genesis_info;
				struct PSR_LEDGER_RECORD ledger_info;
				uint32_t events_count;
				struct PSR_CRITICAL_EVENT events_info[PSR_CRITICAL_EVENTS_NUM_MAX];
				uint8_t  psr_hash[SHA512_LEN_BYTES];
				uint8_t  user_nonce[PSR_NONCE_SIZE];
				uint8_t  csme_nonce[PSR_NONCE_SIZE];
				uint16_t fw_version_major;
				uint16_t fw_version_minor;
				uint16_t fw_version_hotfix;
				uint16_t fw_version_build;
				uint32_t signing_mechanism;
				uint8_t  signature[PSR_MAX_SIGNATURE_LENGTH];
				uint16_t certificate_lengths[PSR_ODCA_CHAIN_LEN];
				uint8_t  certificates[PSR_MAX_CERT_CHAIN_SIZE];

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator& end)
				{
					parseData(log_state, itr, end);
					parseData(psr_version_major, itr, end);
					parseData(psr_version_minor, itr, end);
					parseArray(psrid, PSR_UUID_LENGTH, itr, end);
					parseArray(upid, UPID_PLATFORM_ID_LENGTH, itr, end);
					parseData(genesis_info.genesis_date, itr, end);
					parseArray(genesis_info.oem_info, PSR_GENESIS_FIELD_INFO_SIZE, itr, end);
					parseArray(genesis_info.oem_make_info, PSR_GENESIS_FIELD_INFO_SIZE, itr, end);
					parseArray(genesis_info.oem_model_info, PSR_GENESIS_FIELD_INFO_SIZE, itr, end);
					parseArray(genesis_info.manuf_country, PSR_GENESIS_FIELD_INFO_SIZE, itr, end);
					parseArray(genesis_info.oem_data_store, PSR_GENESIS_DATA_STORE_INFO_SIZE, itr, end);
					parseData(ledger_info.s0_seconds_counter, itr, end);
					parseData(ledger_info.s0_to_s5_counter, itr, end);
					parseData(ledger_info.s0_to_s4_counter, itr, end);
					parseData(ledger_info.s0_to_s3_counter, itr, end);
					parseData(ledger_info.warm_reset_counter, itr, end);
					parseArray(ledger_info.reserved, 11, itr, end);
					parseData(events_count, itr, end);
					for (int i = 0; i < PSR_CRITICAL_EVENTS_NUM_MAX; i++)
					{
						parseData(events_info[i].event_id, itr, end);
						parseArray(events_info[i].reserved, 3, itr, end);
						parseData(events_info[i].timestamp, itr, end);
						parseData(events_info[i].data, itr, end);
					}
					parseArray(psr_hash, SHA512_LEN_BYTES, itr, end);
					parseArray(user_nonce, PSR_NONCE_SIZE, itr, end);
					parseArray(csme_nonce, PSR_NONCE_SIZE, itr, end);
					parseData(fw_version_major, itr, end);
					parseData(fw_version_minor, itr, end);
					parseData(fw_version_hotfix, itr, end);
					parseData(fw_version_build, itr, end);
					parseData(signing_mechanism, itr, end);
					parseArray(signature, PSR_MAX_SIGNATURE_LENGTH, itr, end);
					parseArray(certificate_lengths, PSR_ODCA_CHAIN_LEN, itr, end);
					parseArray(certificates, PSR_MAX_CERT_CHAIN_SIZE, itr, end);
				}
			};

			struct PSR_GET_RESPONSE_RAW
			{
				uint8_t data[sizeof(struct PSR_GET_RESPONSE)];
				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator& end)
				{
					parseData(data, itr, end);
				}
			};
			#pragma pack()

			class PSRGetPlatformServiceRecordCommand : public PSRCommand
			{
			public:
				PSRGetPlatformServiceRecordCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce);
				virtual ~PSRGetPlatformServiceRecordCommand() {}

				PSR_GET_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<PSRCommandResponse<PSR_GET_RESPONSE>> m_response;
			};

			class PSRGetPlatformServiceRecordRequest : public PSRCommandRequest
			{
			public:
				PSRGetPlatformServiceRecordRequest(const std::array<uint8_t, PSR_NONCE_SIZE> &_nonce) : 
					PSRCommandRequest(PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET), user_nonce(_nonce) {}
				virtual ~PSRGetPlatformServiceRecordRequest() {}

			private:
				virtual uint16_t requestDataSize()
				{
					return static_cast<uint8_t>(sizeof(PSR_GET_REQUEST));
				}
				virtual std::vector<uint8_t> SerializeData();

				std::array<uint8_t, PSR_NONCE_SIZE> user_nonce;
			};

			class PSRGetPlatformServiceRecordRawCommand : public PSRCommand
			{
			public:
				PSRGetPlatformServiceRecordRawCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce);
				virtual ~PSRGetPlatformServiceRecordRawCommand() {}

				PSR_GET_RESPONSE_RAW getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<PSRCommandResponse<PSR_GET_RESPONSE_RAW>> m_response;
			};

		} // namespace PSR_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__PSR_GET_PLATFORMSERVICE_RECORD_COMMAND_H__
