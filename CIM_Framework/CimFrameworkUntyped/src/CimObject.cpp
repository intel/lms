//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimObject.cpp
//
//  Contents:   An untyped interface to CIM objects, implementation.
//
//----------------------------------------------------------------------------


#include <algorithm>
#include "CimObject.h"
#include "CimException.h"
#include "CimUtils.h"
#include "CimSerializer.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{
	CimObject::CimObject()
	{
		_client = NULL;
	}

	CimObject::CimObject(const CimObject &Other)
		:_objectName(Other._objectName), 
			_xmlNameSpace(Other._xmlNameSpace),
			_xmlPrefix(Other._xmlPrefix),
			_resourceURI(Other._resourceURI),
			_client(Other._client)
	{
		UpdateFields(Other.GetAllFields());
	}

	CimObject::CimObject(ICimWsmanClient *client, const string &objectName,
			const string &xmlNameSpace, const string &xmlPrefix, const string &resourceURI)
		: _objectName(objectName), 
			_xmlNameSpace(xmlNameSpace),
			_xmlPrefix(xmlPrefix),
			_resourceURI(resourceURI),
			_client(client)
	{}

	CimObject::~CimObject()
	{
		_client = NULL;
	}

	CimObject& CimObject::operator=(const CimObject& other)
	{
		if (this != &other)
		{
			_objectName = other.ObjectType();
			_xmlNameSpace = other.XmlNameSpace();
			_xmlPrefix = other.XmlPrefix();
			_resourceURI = other.ResourceURI();
			_client = other._client;
			UpdateFields(other.GetAllFields());
		}
		return *this;
	}

	const string &CimObject::ObjectType() const
	{
		return _objectName;
	}

	void CimObject::ObjectType(const string &name)
	{
		_objectName = name;
	}

	const string &CimObject::XmlNameSpace() const
	{
		return _xmlNameSpace;
	}
		
	void CimObject::XmlNameSpace(const string &ns)
	{
		_xmlNameSpace = ns;
	}

	const string &CimObject::XmlPrefix() const
	{
		return _xmlPrefix;
	}
		
	void CimObject::XmlPrefix(const string &ns)
	{
		_xmlPrefix = ns;
	}

	const string &CimObject::ResourceURI() const
	{
		return _resourceURI;
	}

	void CimObject::ResourceURI(const string &uri)
	{
		_resourceURI = uri;
	}


	void CimObject::Get()
	{
		WsManSelectors selectors;
		CimObject t = Get(selectors);
		// fill inside data
		this->operator=(t);
	}

	void CimObject::Get(const CimKeys &keys)
	{
		CimObject t = Get(CimKeys::KeysToSelectors(keys));
		// fill inside data
		this->operator=(t);
	}

	void CimObject::Get(const CimReference &reference)
	{
		WsManSelectors selectors = reference.Selectors();
		CimObject t = Get(selectors);
		// fill inside data
		this->operator =(t);
	}


	CimObject CimObject::Get(const WsManSelectors &selectors)
	{
		if (! _client)
			throw CimException("wsman client not initialized");
		string xml;
		xml = _client->Get(_resourceURI, &selectors);
		CimObject theObject = CreateObject(_client, _resourceURI, xml);

		return theObject;
	}



	vector<shared_ptr<CimObject> > CimObject::Enumerate(ICimWsmanClient *client,
		const string &resourceURI, const CimKeys &keys) 
	{
		if (! client)
			throw CimException("wsman client not initialized");

		vector<string> xmls;
		WsManSelectors selectors = CimKeys::KeysToSelectors(keys);

		client->Enumerate(resourceURI, xmls, &selectors);

		vector<shared_ptr<CimObject> > ret;
		vector<string>::const_iterator iter;
		for (iter = xmls.begin(); iter != xmls.end(); iter++)
		{ 
			CimObject* obj = new CimObject(CreateObject(client, resourceURI, *iter));
			shared_ptr<CimObject> cur_ptr(obj);
			ret.push_back(cur_ptr);
		}

		return ret;
	}

	vector<shared_ptr<CimObject> > CimObject::Enumerate(ICimWsmanClient *client,
							const EnumerateFilter &filter)
	{
		if (! client)
			throw CimException("wsman client not initialized");
		
		vector<string> xmls;
		client->Enumerate(xmls, filter);

		vector<shared_ptr<CimObject> > ret;
		vector<string>::const_iterator iter;
		

		for (iter = xmls.begin(); iter != xmls.end(); iter++)
		{
			string objectName;
			string prefix;
			string resourceURI;
			VectorFieldData fields;

			fields = CimSerializer::GetSerializer()->Deserialize(*iter, objectName, prefix, resourceURI);
			CimObject *cur = new CimObject(client, objectName, resourceURI,prefix, resourceURI);
			cur->ResetFields(fields);
			shared_ptr<CimObject> cur_ptr(cur);
			ret.push_back(cur_ptr);
		}

		return ret;
	}


	vector<shared_ptr<CimReference> > CimObject::EnumerateRef(ICimWsmanClient *client,
							const EnumerateFilter &filter)
	{
		if (! client)
			throw CimException("wsman client not initialized");
		
		vector<string> xmls;
		client->EnumerateRef(xmls, filter);

		vector< shared_ptr<CimReference> > ret;
		vector<string>::const_iterator iter;
		for (iter = xmls.begin(); iter != xmls.end(); iter++)
		{			
			CimReference temp = CimSerializer::GetSerializer()->DeserializeEPR(*iter);
			CimReference* cur = new CimReference();
			
			cur->ResourceURI(temp.ResourceURI());
			cur->Name(temp.Name());
			cur->NameSpace(temp.NameSpace());
			cur->Prefix(temp.Prefix());
			cur->Address(temp.Address());
			cur->Selectors(temp.Selectors());
			
			shared_ptr<CimReference> cur_ptr(cur);
			ret.push_back(cur_ptr);
		}

		return ret;
	}

	void CimObject::Delete(const CimKeys &keys) const
	{
		if (!_client)
			throw CimException("wsman client not initialized");
		WsManSelectors selectors = CimKeys::KeysToSelectors(keys);
		_client->Delete(_resourceURI, &selectors);
		
	}

	void CimObject::Delete(ICimWsmanClient *client, const CimReference &reference)
	{
		Delete(client, reference.ResourceURI(), reference.Selectors());
	}

	void CimObject::Delete(ICimWsmanClient *client, const string &resourceURI, const CimKeys &keys)
	{
		WsManSelectors selectors = CimKeys::KeysToSelectors(keys);
		Delete(client, resourceURI, selectors);
	}

	void CimObject::Delete(ICimWsmanClient *client, const string &resourceURI)
	{
		Delete(client, resourceURI, CimObject::CimKeys());
	}

	void CimObject::Delete(ICimWsmanClient *client, const string &resourceURI, const WsManSelectors &selectors)
	{
		if (! client)
			throw CimException("wsman client not initialized");

		client->Delete(resourceURI, &selectors);
	}


	void CimObject::Put(const CimKeys &keys)
	{
		if (! _client)
			throw CimException("wsman client not initialized");

		WsManSelectors selectors = CimKeys::KeysToSelectors(keys);
		_client->Put(_resourceURI, CimSerializer::GetSerializer()->Serialize(
				ObjectType(),
				XmlNameSpace(),
				_resourceURI,
				XmlPrefix(),
				GetAllFields()),
				&selectors);
	}


	CimReference CimObject::Create() const
	{
		if (! _client)
			throw CimException("wsman client not initialized");

		string xml = _client->Create(_resourceURI,
		CimSerializer::GetSerializer()->Serialize(
				ObjectType(),
				XmlNameSpace(),
				_resourceURI,
				XmlPrefix(),
				GetAllFields()));

		CimReference reference = CimSerializer::GetSerializer()->DeserializeEPR(xml);
		return reference;
	}

	unsigned int CimObject::Invoke(const string &methodName, const CimKeys &keys,
					const CimParam &input, CimParam &output)
	{
		if (! _client)
			throw CimException("wsman client not initialized");

		unsigned int ret = 0;
		string xml;
		WsManSelectors selectors = CimKeys::KeysToSelectors(keys);
		xml = _client->Invoke(_resourceURI, methodName,
			CimSerializer::GetSerializer()->Serialize(
					methodName + "_INPUT",
					_xmlNameSpace,
					_resourceURI,
					_xmlPrefix,
					input.GetAllFields()),
			&selectors);

		VectorFieldData vfd = CimSerializer::GetSerializer()->Deserialize(xml);
		output.ResetFields(vfd);	
		TypeConverter::StringToType(output.GetField("ReturnValue"), ret);
		return ret;
	}

	ICimWsmanClient *CimObject::WsmanClient() const
	{
		return _client;
	}

	void CimObject::WsmanClient(ICimWsmanClient *client)
	{
		_client = client;
	}

	CimObject CimObject::CreateObject(ICimWsmanClient *client, string resourceUri, const string &xml)
	{
		string objectName, nameSpace, prefix, XMLresourceURI;

		// part of XML work
		VectorFieldData vfd = CimSerializer::GetSerializer()->Deserialize(xml, objectName, prefix, XMLresourceURI);
		
		// We assume that namespace is the same as resourceUri.
		nameSpace = XMLresourceURI;
		CimObject theObject(client, objectName, nameSpace, prefix, XMLresourceURI);
		theObject.ResetFields(vfd);
		return theObject;
	}

	// Return sorted (lexicographically) version of the vector.
	const VectorFieldData CimObject::GetAllFields() const
	{
		VectorFieldData ret = CimData::GetAllFields();

		std::sort(ret.begin(), ret.end());

		return ret;
	}

	

	

};
};
};
};
