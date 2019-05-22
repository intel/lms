//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimReference.cpp
//
//  Contents:   Representation of and Endpoint Reference object, implementation.
//
//----------------------------------------------------------------------------

#include "CimReference.h"
#include "CimSerializer.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
	using std::pair;

	Key::Key(const string &name, const string &value, bool IsRef)
		: Name(name), Value(value), IsReference(IsRef)
	{}

	Key::~Key(){}

	Key::Key(const Key& other)
		: Value(other.Value),Name(other.Name),IsReference(other.IsReference)
	{	
	}

	Key& Key::operator =(const Key& other)
	{
		if (this == &other) 
		{
			return *this;
		}
		Value = other.Value;
		Name = other.Name;
		IsReference = other.IsReference;
		return *this;
	}
	
	CimReference::CimReference(const string& name,
					 const string& ns,
					 const string& prefix)
		: _name(name),
		  _namespace(ns),
		  _prefix(prefix),
		  _address("default")
	{
	}

	CimReference::CimReference(const CimReference &other)
		: _name(other._name),
		  _namespace(other._namespace),
		  _prefix(other._prefix),
		  _address(other._address),
		  _selectors(other._selectors),
		  _resourceURI(other._resourceURI)
	{
	}


	CimReference& CimReference::operator =(const CimReference& other)
	{
		if (this == &other) 
		{
			return *this;
		}
		_name = other._name;
		_namespace = other._namespace;
		_prefix = other._prefix;
		_address = other._address;
		_selectors = other._selectors;
		_resourceURI = other._resourceURI;
		return *this;
	}

	CimReference::~CimReference()
	{
	}

	string CimReference::Name() const
	{
		return _name;
	}

	void CimReference::Name(const string &name)
	{
		_name = name;
	}

	string CimReference::Prefix() const
	{
		return _prefix;
	}

	void CimReference::Prefix(const string &prefix)
	{
		_prefix = prefix;
	}

	string CimReference::NameSpace() const
	{
		return _namespace;
	}

	void CimReference::NameSpace(const string &ns)
	{
		_namespace = ns;
	}



	void CimReference::Address(const string &newAdd)
	{
		_address = newAdd;
	}

	string CimReference::Address() const
	{
		return _address;
	}

	string CimReference::Serialize() const
	{
		return CimSerializer::GetSerializer()->SerializeEPR(*this);
	}

	void CimReference::Deserialize(const string &innerValue)
	{
		// This is done to create a valid xml (adding the outer tag)
		string validXML = "<"+Name()+" xmlns=\""+NameSpace()+"\">"+innerValue+ "</"+Name()+">";
		CimReference tmp = CimSerializer::GetSerializer()->DeserializeEPR(validXML);
		
		_name = tmp.Name();
		_namespace = tmp.NameSpace();
		_prefix = tmp._prefix;
		_address = tmp.Address();
		_resourceURI = tmp.ResourceURI();
		Selectors(tmp.Selectors());
	}

	void CimReference::ClearValues()
	{
		_selectors.clear();
	}


	const WsManSelectors CimReference::Selectors() const
	{		
		return _selectors;
	}

	void CimReference::Selectors(const WsManSelectors &sel)
	{
		_selectors = sel;
	}

	string CimReference::ResourceURI() const
	{
		return _resourceURI;
	}

	void CimReference::ResourceURI(const string& uri)
	{
		_resourceURI = uri;
	}

	


	
	

	WsManSelectors CimReference::KeysToWsManSelectors(const vector<Key> &keys)
	{
		WsManSelectors selectors;
		vector<Key>::const_iterator iter;

		for (iter = keys.begin(); iter != keys.end(); iter++)
		{
			pair<string, string> current;
			current.first = iter->Name;
			string value = iter->Value;
			//This code is for handling the case when the key is EPR
			if ( iter->IsReference)
			{
				CimReference ref;
				ref.Deserialize(value);
				value = CimSerializer::GetSerializer()->SerializeFullEPR(ref);
			}
			current.second = value;
			selectors.insert(current);			
		}
		return selectors;
	}
 
	vector<Key> CimReference::WsManSelectorsToKeys(const WsManSelectors &sel)
	{
		vector<Key> keys;
		WsManSelectors::const_iterator iter;
		for (iter = sel.begin(); iter != sel.end(); iter++)
		{
			Key current(iter->first, iter->second);
			keys.push_back(current);
		}
		return keys;
	}
};
};
};
