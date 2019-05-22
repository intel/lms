//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       NameValuePairs.h
//
//  Contents:   
//
//----------------------------------------------------------------------------

#ifndef _NAMEVALUEPAIRS_H
#define _NAMEVALUEPAIRS_H 1

#include <string>
#include <vector>
#include <map>


namespace Intel
{
namespace WSManagement
{
	// type for holding selectors.
	typedef std::map<std::string, std::string> NameValuePairs;
	typedef std::map<std::string, std::string>::const_iterator PairsIterator;

}// namespace WSManagement
}// namespace Intel
#endif // _NAMEVALUEPAIRS_H

