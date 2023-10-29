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

			const size_t PSR_CAPABILITIES_SIZE = 32;

			const uint8_t PSR_LOG_NOT_STARTED = 0;
			const uint8_t PSR_LOG_STARTED = 1;
			const uint8_t PSR_LOG_STOPPED = 2;

			const uint8_t PSR_CAPABILITY_NOT_SUPPORTED = 0;
			const uint8_t PSR_CAPABILITY_SUPPORTED = 1;

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
			const uint8_t PSR_EVENT_EXCESSIVE_SHOCK = 33;
			const uint8_t PSR_EVENT_EXCESSIVE_OPERATIONAL_TEMPERATURE = 34;
			const uint8_t PSR_EVENT_ERASE = 35;
			const uint8_t PSR_EVENT_FIRMWARE_RECOVERY = 36;
			const uint8_t PSR_EVENT_FIRMWARE_UPDATE = 37;
			const uint8_t PSR_EVENT_SYSTEM_HUNG_UP = 38;
			const uint8_t PSR_EVENT_POWER_DROP = 39;

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
				uint32_t ish_connection_counter;
				uint32_t csme_reset_counter;
				uint32_t reserved[9];
			};

			struct PSR_LEDGER_RECORD2
			{
				uint32_t prtc_reset_counter;
				uint32_t recovery_state_counter;
				uint32_t dam_state_counter;
				uint32_t unlocked_state_counter;
				uint32_t psr_svn_increment_counter;
				uint32_t reserved[3];
				uint32_t excessive_shock_counter;
				uint32_t excessive_temp_counter;
				uint32_t firmware_recovery_counter;
				uint32_t firmware_update_counter;
				uint32_t system_hung_up_counter;
				uint32_t power_drop_counter;
				uint32_t reserved2[2];
			};

			struct PSR_CRITICAL_EVENT
			{
				uint8_t  event_id;
				uint8_t  event_sub_id[3];
				uint32_t timestamp;
				uint32_t data;
			};

			const uint32_t PSR_EVENT_ERASE_STATUS_MASK = 0x1;
			const uint32_t PSR_EVENT_ERASE_STATUS_OFFSET = 0x0;
			const uint32_t PSR_EVENT_ERASE_ACTION_MASK = 0x7C;
			const uint32_t PSR_EVENT_ERASE_ACTION_OFFSET = 0x2;
			const uint32_t PSR_EVENT_ERASE_SOURCE_MASK = 0x180;
			const uint32_t PSR_EVENT_ERASE_SOURCE_OFFSET = 0x7;

			const uint8_t PSR_EVENT_ERASE_SOURCE_RPE = 0;
			const uint8_t PSR_EVENT_ERASE_SOURCE_LPE = 1;
			const uint8_t PSR_EVENT_ERASE_SOURCE_OTHER = 2;

			const uint8_t PSR_EVENT_ERASE_ACTION_ALL_SSD = 2;
			const uint8_t PSR_EVENT_ERASE_ACTION_VERIFY_STORAGE = 3;
			const uint8_t PSR_EVENT_ERASE_ACTION_TPM_CLEAR = 6;
			const uint8_t PSR_EVENT_ERASE_ACTION_OEM_CUSTOM = 16;
			const uint8_t PSR_EVENT_ERASE_ACTION_CLEAR_BIOS = 25;
			const uint8_t PSR_EVENT_ERASE_ACTION_RELOAD_BIOS = 26;
			const uint8_t PSR_EVENT_ERASE_ACTION_ME_UNCONFIG = 31;

			struct PSR_GET_RESPONSE
			{
				PSR_GET_RESPONSE() : log_state(0), psr_version_major(0), psr_version_minor(0), psrid{ 0 },
					upid{ 0 }, genesis_info({ 0 }), capabilities{ 0 }, ledger_info({ 0 }), ledger_info2({ 0 }),
					events_count(0), events_info{ 0 }, psr_hash{ 0 }, user_nonce{ 0 }, csme_nonce{ 0 },
					fw_version_major(0), fw_version_minor(0), fw_version_hotfix(0), fw_version_build(0),
					signing_mechanism(0), signature{ 0 }, certificate_lengths{ 0 }, certificates{ 0 } {}
				uint32_t log_state;
				uint16_t psr_version_major;
				uint16_t psr_version_minor;
				uint8_t  psrid[PSR_UUID_LENGTH];
				uint8_t  upid[UPID_PLATFORM_ID_LENGTH];
				struct PSR_GENESIS_RECORD genesis_info;
				uint8_t capabilities[PSR_CAPABILITIES_SIZE];
				struct PSR_LEDGER_RECORD ledger_info;
				struct PSR_LEDGER_RECORD2 ledger_info2;
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
					if (psr_version_major >= 2)
					{
						parseArray(capabilities, PSR_CAPABILITIES_SIZE, itr, end);
					}
					parseData(ledger_info.s0_seconds_counter, itr, end);
					parseData(ledger_info.s0_to_s5_counter, itr, end);
					parseData(ledger_info.s0_to_s4_counter, itr, end);
					parseData(ledger_info.s0_to_s3_counter, itr, end);
					parseData(ledger_info.warm_reset_counter, itr, end);
					if (psr_version_major >= 2)
					{
						parseData(ledger_info.ish_connection_counter, itr, end);
						parseData(ledger_info.csme_reset_counter, itr, end);
						parseArray(ledger_info.reserved, 9, itr, end);
						parseData(ledger_info2.prtc_reset_counter, itr, end);
						parseData(ledger_info2.recovery_state_counter, itr, end);
						parseData(ledger_info2.dam_state_counter, itr, end);
						parseData(ledger_info2.unlocked_state_counter, itr, end);
						parseData(ledger_info2.psr_svn_increment_counter, itr, end);
						parseArray(ledger_info2.reserved, 3, itr, end);
						parseData(ledger_info2.excessive_shock_counter, itr, end);
						parseData(ledger_info2.excessive_temp_counter, itr, end);
						parseData(ledger_info2.firmware_recovery_counter, itr, end);
						parseData(ledger_info2.firmware_update_counter, itr, end);
						parseData(ledger_info2.system_hung_up_counter, itr, end);
						parseData(ledger_info2.power_drop_counter, itr, end);
						parseArray(ledger_info2.reserved2, 2, itr, end);
					}
					else
					{
						ledger_info.ish_connection_counter = 0;
						ledger_info.csme_reset_counter = 0;
						parseArray(ledger_info.reserved, 11, itr, end);
						ledger_info2.prtc_reset_counter = 0;
						ledger_info2.recovery_state_counter = 0;
						ledger_info2.dam_state_counter = 0;
						ledger_info2.unlocked_state_counter = 0;
						ledger_info2.psr_svn_increment_counter = 0;
						ledger_info2.reserved[0] = 0;
						ledger_info2.reserved[1] = 0;
						ledger_info2.reserved[2] = 0;
						ledger_info2.excessive_shock_counter = 0;
						ledger_info2.excessive_temp_counter = 0;
						ledger_info2.firmware_recovery_counter = 0;
						ledger_info2.firmware_update_counter = 0;
						ledger_info2.system_hung_up_counter = 0;
						ledger_info2.power_drop_counter = 0;
						ledger_info2.reserved2[0] = 0;
						ledger_info2.reserved2[1] = 0;
					}
					parseData(events_count, itr, end);
					for (size_t i = 0; i < PSR_CRITICAL_EVENTS_NUM_MAX; i++)
					{
						parseData(events_info[i].event_id, itr, end);
						parseArray(events_info[i].event_sub_id, 3, itr, end);
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
				PSR_GET_RESPONSE_RAW() : data{ 0 } {}
				std::vector<uint8_t> data;
				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator& end)
				{
					data = std::vector<uint8_t>(itr, end);
				}
			};
			#pragma pack()

			class PSRGetPlatformServiceRecordRequest : public PSRCommandRequest
			{
			public:
				PSRGetPlatformServiceRecordRequest(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce) :
					PSRCommandRequest(PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET), user_nonce(_nonce) {}
				virtual ~PSRGetPlatformServiceRecordRequest() {}

			private:
				virtual uint16_t requestDataSize()
				{
					return static_cast<uint8_t>(sizeof(PSR_GET_REQUEST));
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					return std::vector<uint8_t>(user_nonce.begin(), user_nonce.end());
				}

				std::array<uint8_t, PSR_NONCE_SIZE> user_nonce;
			};

			class PSRGetPlatformServiceRecordCommand : public PSRCommand
			{
			public:
				PSRGetPlatformServiceRecordCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce)
				{
					m_request = std::make_shared<PSRGetPlatformServiceRecordRequest>(_nonce);
					Transact();
				}
				virtual ~PSRGetPlatformServiceRecordCommand() {}

				PSR_GET_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = PSRCommandResponse<PSR_GET_RESPONSE>(buffer, PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET);
				}

				PSRCommandResponse<PSR_GET_RESPONSE> m_response;
			};

			class PSRGetPlatformServiceRecordRawCommand : public PSRCommand
			{
			public:
				PSRGetPlatformServiceRecordRawCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce)
				{
					m_request = std::make_shared<PSRGetPlatformServiceRecordRequest>(_nonce);
					Transact();
				}
				virtual ~PSRGetPlatformServiceRecordRawCommand() {}

				PSR_GET_RESPONSE_RAW getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = PSRCommandResponse<PSR_GET_RESPONSE_RAW>(buffer, PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET);
				}

				PSRCommandResponse<PSR_GET_RESPONSE_RAW> m_response;
			};

		} // namespace PSR_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__PSR_GET_PLATFORMSERVICE_RECORD_COMMAND_H__
