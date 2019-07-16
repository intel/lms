/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: StringManager.cpp

--*/

//------------------------------------------------------------------------------------------------
//
//  Contents:   implementation to the string manager - used to load strings of correct language
//              from embedded rc file 
//              
//
//------------------------------------------------------------------------------------------------

#include "StringManager.h"
#include <memory>

//---------- CStringManager functions----------------

//get string by it's ID
//returns : the string if was loaded, empty string otherwise
const STRING_TYPE CStringManager::getString(unsigned int id) const
{
	std::map<unsigned int,STRING_TYPE>::const_iterator itr;

	itr = m_stringMap.find(id);
	if (itr== m_stringMap.end())
		return EMPTY_STR;
	else
		return itr->second;
}
//----------------------------

//----------------StringManager functions
 std::shared_ptr<CStringManager> StringManager::m_instance = std::shared_ptr<CStringManager>(NULL); 

CStringManager* StringManager::instance()
{
	if (m_instance.get()==NULL)
		m_instance = std::shared_ptr<CStringManager>(new CStringManager()); 
	
	return m_instance.get(); 
}
//-------------------------------------------
//#undef UNICODE