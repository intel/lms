//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimReference.h
//
//  Contents:   Representation of and Endpoint Reference object, declarations.
//
//----------------------------------------------------------------------------

#ifndef CIMREFERENCE_H
#define CIMREFERENCE_H 1

#include <string>

#include "CimUtils.h"
#include "NameValuePairs.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
	using std::string;
	using std::vector;
	using Intel::WSManagement::NameValuePairs;	

	// Selectors as used in WS-Management
	typedef NameValuePairs WsManSelectors;

	class CIMUNTYPEDFRAMEWORK_API Key {
	public:
		string Value;
		string Name;
		bool IsReference;

		Key(const string &name, const string &value, bool IsRef = false);

		~Key();
		// Copy constructor
		Key(const Key& other);
		Key& operator =(const Key& other);
	};

	// An Endpoint Reference.  This class and its descendants
	// are handles to CIM objects and are used a lot.
	class CIMUNTYPEDFRAMEWORK_API CimReference
	{
	public:		
		// Constructor.
		explicit CimReference(const string& name = "CimReference",
			const string& ns = "http://schemas.xmlsoap.org/ws/2004/08/addressing",
			const string& prefix = "wsa");

		// Copy Constructor.
		CimReference(const CimReference &other);
		CimReference& operator =(const CimReference& other);

		// Destructor.
		~CimReference();
		
		// Access to fields.
		string Name() const;
		void Name(const string &name);

		string Prefix() const;
		void Prefix(const string &prefix);
		
		string NameSpace() const;
		void NameSpace(const string &ns);
		
		void Address(const string &add);
		string Address() const;
		
		const WsManSelectors Selectors() const;
		void Selectors(const WsManSelectors &sel);
		
		string ResourceURI() const;
		void ResourceURI(const string& uri);
		
		// Type conversion functions
		string Serialize() const;
		void Deserialize(const string &innerValue);


		// Convenience functions used by when creating objects
		// from XML received over the network.
		static WsManSelectors KeysToWsManSelectors(const vector<Key> &keys);
		static vector<Key> WsManSelectorsToKeys(const WsManSelectors &sel);

	private:

		string _name;
		string _namespace;
		string _prefix;
		string _resourceURI;

		string _address;

		WsManSelectors _selectors;

		// Clear out our data.
		void ClearValues(); 
	};

	


};
};
};

#endif // CIMREFERENCE_H
