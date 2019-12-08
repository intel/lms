/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */

#include "MEIparser.h"
#include "AMTHICommand.h"
namespace Intel
{
namespace MEI_Client
{

/*
template specialization for T = bool
*/
template <>
void parseData<bool> (bool &t, std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
{
	AMTHI_Client::AMT_BOOLEAN tmp = AMTHI_Client::AMT_FALSE;
	//check that buffer is large enough
	if (end-itr < (int)(sizeof(tmp)))
	{
		throw MEIClientException("Error: Buffer size is too small!");
	}

	uint8_t *p = (uint8_t*)&tmp;
	std::copy(itr, itr + sizeof(tmp), p);
	itr += sizeof(tmp);
	t = (tmp == AMTHI_Client::AMT_TRUE);
}

} // namespace MEI_Client
} // namespace Intel
