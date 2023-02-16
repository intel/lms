/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetPlatformTypeCommand.h

--*/

#ifndef __GET_PLATFORM_TYPE_COMMAND_H__
#define __GET_PLATFORM_TYPE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			enum BRAND_TYPE
			{
				NoBrand,
				BrandAMT,
				BrandStdMng,
				BrandL3,
				BrandRpat,
				BrandSBT
			};
			enum IMAGE_TYPE
			{
				NoME,
				IGN_FW,//IGN_FW
				ME_LITE,//ME_LITE -(reserved)
				ME_FULL_4MB,
				ME_FULL_8MB
			};
			enum MPT_IMAGE_TYPE { MPT_IMAGE_TYPE_NO_FW  =  0,    // NO SKU
								MPT_IMAGE_TYPE_SLIM_SKU  = 2,   // SLIMSKU
								MPT_IMAGE_TYPE_SMALL_SKU = 3,   // SKU2 - Consumer
								MPT_IMAGE_TYPE_FULL_SKU  = 4,   // SKU1 - Corporate
								MPT_IMAGE_TYPE_TEST_SKU  = 15,  // TEST
			};

			union MKHI_PLATFORM_TYPE
			{
				uint32_t    Data;
				struct
				{
					uint32_t   Mobile           :1;
					uint32_t   Desktop          :1;
					uint32_t   Server           :1;
					uint32_t   WorkStn          :1;
					uint32_t   Rsvd2            :1;// Previously Corporate
					uint32_t   PV               :1;// Previously Consumer. Validation requested this
					uint32_t   SuperSKU         :1;
					uint32_t   ProdSigned       :1;// 0 - image is debug signed, 1- image is production signed (RCR #1404732707)
					uint32_t   ImageType        :4;
					uint32_t   Brand            :4;
					uint32_t   CpuType          :4;
					uint32_t   Chipset          :4;
					uint32_t   CpuBrandClass    :4;
					uint32_t   PchNetInfraFuses :3;
					uint32_t   Rsvd1            :1;
				}Fields;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetPlatformTypeCommand : public MKHICommand
			{
			public:

				GetPlatformTypeCommand();
				virtual ~GetPlatformTypeCommand() {}

				MKHI_PLATFORM_TYPE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<MKHIGetRuleCommandResponse<MKHI_PLATFORM_TYPE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x02;
			};

			class GetPlatformTypeRequest : public MKHICommandRequest
			{
			public:
				GetPlatformTypeRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID) {}
				virtual ~GetPlatformTypeRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x02;

				virtual uint32_t requestDataSize()
				{
					return sizeof(RULE_ID);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_PLATFORM_TYPE_COMMAND_H__
