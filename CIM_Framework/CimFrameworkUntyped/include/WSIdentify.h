//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:		WSIdentify.h    
//
//  Contents:	Class representing the results for wsman Identify operation.   
//
//----------------------------------------------------------------------------

#ifndef WSIDENTIFY_H
#define WSIDENTIFY_H 1

#include <string>
#include <vector>

#include "CimUntypedDllExport.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	using std::string;
	using std::vector;
	using std::pair;

	class CIMUNTYPEDFRAMEWORK_API WSIdentify
	{
	public:
		WSIdentify(const string &data);
		const string ProtocolVersion() const;
		const string ProductVendor() const;
		const string ProductVersion() const;
		const string DASHVersion() const;
		const vector<string> &SecurityProfiles() const;
	private:
		string _protocolVersion;
		string _productVendor;
		string _productVersion;
		string _DASHVersion;
		vector<string> _securityProfiles;

	};
}
}
}
}
#endif
