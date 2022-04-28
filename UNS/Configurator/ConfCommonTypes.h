/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2022 Intel Corporation
 */
#ifndef __CONF_COMMON_TYPES_H_
#define __CONF_COMMON_TYPES_H_
#include <list>
#include "ace/Stream.h"
#include <map>
#include <set>

typedef std::list<ACE_TString> NamesList;
typedef std::set<ACE_TString> NamesSet;
enum class NamesGroup {EVENT_HANDLERS_GROUP, SKU_5_GROUP, SKU_1_5_GROUP, MANAGABILITY_GROUP, SKU_5_NO_LME_GROUP, DUMMY_SERVICES};
typedef std::map<ACE_TString, NamesList> DepMap;

#endif //__CONF_COMMON_TYPES_H_
