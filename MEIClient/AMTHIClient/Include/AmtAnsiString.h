/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2021 Intel Corporation
 */
/*++

@file: AmtAnsiString.h

--*/
#ifndef _AMT_ANSI_STRING_H
#define _AMT_ANSI_STRING_H

#include <string>
#include <vector>
#include <cstdint>

namespace Intel
{
namespace MEI_Client
{
namespace AMTHI_Client
{

class AmtAnsiString {
public :
	AmtAnsiString():m_str(""), m_nullTerminated(false){}
	AmtAnsiString(std::vector<uint8_t>::const_iterator& first, std::vector<uint8_t>::const_iterator last, bool nullTerminated = true); //does "deserialize"
	AmtAnsiString(const std::string &str, bool nullTerminated = true);
	AmtAnsiString (const AmtAnsiString& str):m_str(str.m_str), m_nullTerminated(str.m_nullTerminated) {}

	std::vector<uint8_t> serialize();
	std::string getString() {return m_str;}

	size_t size()
	{
		if (m_nullTerminated)
		{
			return m_str.size() + 1;
		}
		return m_str.size();
	}

	uint32_t bufSize()
	{
		return static_cast<uint32_t>(size() + sizeof(uint16_t));
	}

	AmtAnsiString& operator= ( const AmtAnsiString& str )
	{
		m_str = str.m_str;
		m_nullTerminated = str.m_nullTerminated;
		return *this;
	}

private :
	std::string m_str;
	bool m_nullTerminated;

}; //class AmtAnsiString

} // namespace AMTHI_Client
} // namespace MEI_Client
} // namespace Intel

#endif //_AMT_ANSI_STRING_H
