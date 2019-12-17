/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */

#include "AmtAnsiString.h"
#include "MEIClientException.h"
#include <climits>

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {

			AmtAnsiString::AmtAnsiString(std::vector<uint8_t>::const_iterator& first, std::vector<uint8_t>::const_iterator last, bool nullTerminated)
				:m_nullTerminated(nullTerminated)
			{

				if ((first + sizeof(uint16_t)) > last)
				{
					throw MEIClientException("Error: Buffer size is too small!");
				}
				uint16_t count;
				count = *first;
				first += sizeof(uint16_t);
				if (count == 0)
				{
					return;
				}

				//copy data
				if ((first + (sizeof(char)*count)) > last)
				{
					throw MEIClientException("Error: Buffer size is too small!");
				}
				std::string str(first, last);
				m_str = str;

			}

			AmtAnsiString::AmtAnsiString(const std::string &str, bool nullTerminated) : m_nullTerminated(nullTerminated)
			{
				if (str.length() >= USHRT_MAX)
				{
					throw MEIClientException("Error: str is too long!");
				}
				m_str = str;
			}

			std::vector<uint8_t> AmtAnsiString::serialize()
			{
				uint16_t len = (uint16_t)m_str.size();
				if (m_nullTerminated)
				{
					++len;
				}
				std::vector<uint8_t> output(sizeof(uint16_t) + len, 0);
				std::vector<uint8_t>::iterator it = output.begin();
				std::copy((std::uint8_t*)&len, (std::uint8_t*)&len + sizeof(len), it);
				it += sizeof(len);
				if (len != 0)
					std::copy(m_str.begin(), m_str.end(), it);
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel