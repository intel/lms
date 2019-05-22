//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimNamespaces.h
//
//  Contents:   Give full specifcations of classes in use with their namespaces.
//
//----------------------------------------------------------------------------

#ifndef CIMBASICNAMESPACES_H
#define CIMBASICNAMESPACES_H 1

namespace Intel {
	namespace Manageability {
		namespace Exceptions {
		};
		namespace Cim {
			namespace Untyped {
				class CimObject;
				class CimSerializer;
				class CimData;
				class CimParam;
			};
			namespace Utils {
				class Base64;
				class TypeConverter;
			};
			class CimDateTime;
			class CimReference;
		};
	};
	namespace WSManagement {
		struct SubscribeInfo;
		struct ConnectionInfo;
		struct EnumerateFilter;
		struct EnumerateOptions;
		class ICimWsmanClient;
	}
};

#endif // CIMBASICNAMESPACES_H
