//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:		WSIdentify.cpp    
//
//  Contents:	Class representing the results for wsman Identify operation.   
//
//----------------------------------------------------------------------------

#include "WSIdentify.h"
#include "CimSerializer.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	WSIdentify::WSIdentify(const string &data)
	{
		// Unused parameters
		string name, prefix, uri;

		VectorFieldData ret = CimSerializer::GetSerializer()->Deserialize(data, name, prefix, uri);
		VectorFieldData::const_iterator iter;
		for(iter = ret.begin(); iter != ret.end(); iter++)
		{
			if (iter->name == "ProtocolVersion")
				_protocolVersion = iter->value[0];
			else if (iter->name == "ProductVendor")
				_productVendor = iter->value[0];
			else if (iter->name == "ProductVersion")
				_productVersion = iter->value[0];
			else if (iter->name == "DASHVersion")
				_DASHVersion = iter->value[0];
			else if (iter->name == "SecurityProfiles")
			{
				string xml = "<SecurityProfiles>" + iter->value[0] + "</SecurityProfiles>";
				VectorFieldData ret1 = CimSerializer::GetSerializer()->Deserialize(xml, name, prefix, uri);
				_securityProfiles = ret1[0].value;
			}

		}

	}
	const string WSIdentify::ProtocolVersion() const
	{
		return _protocolVersion;
	}
	const string WSIdentify::ProductVendor() const
	{
		return _productVendor;
	}
	const string WSIdentify::ProductVersion() const
	{
		return _productVersion;
	}
	const string WSIdentify::DASHVersion() const
	{
		return _DASHVersion;
	}
	const vector<string> &WSIdentify::SecurityProfiles() const
	{
		return _securityProfiles;
	}
}
}
}
}
