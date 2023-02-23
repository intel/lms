/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFWCapsCommand.h

--*/

#ifndef __GET_FWCAPS_COMMAND_H__
#define __GET_FWCAPS_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			enum CapsRule
			{
				FEATURES_CAPABLE = MEFWCAPS_FW_SKU_RULE, // get features which the platform is capable of
				FEATURES_ENABLED = MEFWCAPS_FEATURE_ENABLE_RULE, // get features which the platform is capable of and enabled
				FEATURES_AVAILABLE = MEFWCAPS_AVAILABLE_BITMAP_RULE_ID //get features which the platform is capable of,enabled and ready
			};

			union MEFWCAPS_SKU_MKHI
			{
				MEFWCAPS_SKU_MKHI() : Data(0) {}
				uint32_t Data;
				struct
				{
					uint32_t MngFull:1;
					uint32_t MngStd:1;
					uint32_t Amt:1;
					uint32_t Irwt:1; //Intel Remote Wake Tech //N/A since 8.0
					uint32_t Qst:1; //Quiet System Technology //N/A since 8.0
					uint32_t PSR:1; //Platform Service Record (was: Anti-Theft)
					uint32_t SoftCreek:1; //Intel Capability Licensing Service (aka CLS)
					uint32_t Ve:1; //Virtualization Engine //N/A since 9.0
					uint32_t Nand35:1; //N/A since 9.5
					uint32_t Nand29:1; //N/A since 9.5
					uint32_t ThermReport:1; //N/A since 9.5
					uint32_t IccOverClockin:1; //N/A
					uint32_t Pav:1; //Protected Audio Video Path
					uint32_t Spk:1; //N/A since 8.0
					uint32_t Rca:1;
					uint32_t Rpat:1; //N/A since 8.0
					uint32_t Hap:1;
					uint32_t Ipv6:1;
					uint32_t Kvm:1;
					uint32_t Och:1;
					uint32_t MEDAL:1;
					uint32_t Tls:1;
					uint32_t Cila:1;
					uint32_t Wlan:1;
					uint32_t WirelessDisp:1;
					uint32_t LakeHouston:1;
					uint32_t Nap:1;
					uint32_t AlarmClk:1;
					uint32_t CbRaid:1;
					uint32_t MediaVault:1;
					uint32_t mDNSProxy:1;
					uint32_t Reserved3:1;
				} Fields;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData (Data, itr, end);
				}
			};

			class GetFWCapsRequest : public MKHICommandRequest
			{
			public:
				GetFWCapsRequest(CapsRule rule) : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID) { m_rule.Data = rule; }
				virtual ~GetFWCapsRequest() {}

			private:
				RULE_ID m_rule;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x02;

				virtual uint32_t requestDataSize()
				{
					return sizeof(RULE_ID);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					std::vector<uint8_t> output((std::uint8_t*)&m_rule, (std::uint8_t*)&m_rule + sizeof(m_rule));
					return output;
				}
			};

			class GetFWCapsCommand : public MKHICommand
			{
			public:

				GetFWCapsCommand(CapsRule rule)
				{
					m_rule = rule;
					m_request = std::make_shared<GetFWCapsRequest>(rule);
					Transact();
				}
				virtual ~GetFWCapsCommand() {}

				MEFWCAPS_SKU_MKHI getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHIGetRuleCommandResponse<MEFWCAPS_SKU_MKHI>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID, m_rule);
				}

				MKHIGetRuleCommandResponse<MEFWCAPS_SKU_MKHI> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x02;

				CapsRule m_rule;
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_FWCAPS_COMMAND_H__
