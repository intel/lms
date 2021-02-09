//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2021  All Rights Reserved.
//
//  File: CimAnonymous.h
//
//  Contents: Class which represent unknown received class form the FW, definitions.
//
//----------------------------------------------------------------------------

#ifndef CIMANONYMOUS_H
#define CIMANONYMOUS_H 1

#include "CimBase.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	class CIMFRAMEWORK_API CimAnonymous : public CimBase {
	public:
		CimAnonymous(ICimWsmanClient *client, const string &objectName,
			const string &nameSpace, const string &prefix, const string &resourceURI);
		CimAnonymous(const CimObject &object);
		virtual ~CimAnonymous();

		CimObject GetUnTyped() const;

		string Serialize() const;
		void Deserialize(const string &xml);
};
};
};
};


};

#endif // CIMANONYMOUS_H
