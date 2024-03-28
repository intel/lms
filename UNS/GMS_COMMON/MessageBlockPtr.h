/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#ifndef MESSAGEBLOCK_PTR
#define MESSAGEBLOCK_PTR
#include <memory>
#include "ace/Message_Block.h"

typedef std::shared_ptr<ACE_Message_Block> MessageBlockPtr;

inline void deleteMessageBlockPtr(ACE_Message_Block *mb)
{
	ACE_Message_Block::release(mb);
}

#endif //MESSAGEBLOCK_PTR