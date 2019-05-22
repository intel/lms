//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimObject.h
//
//  Contents:   An untyped interface to CIM objects, declarations.
//
//----------------------------------------------------------------------------

#ifndef CIMOBJECT_H
#define CIMOBJECT_H 1

#include <algorithm>
#include <memory>

#include "CimData.h"
#include "CimParam.h"
#include "CimWsman.h"

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
	using Intel::WSManagement::ICimWsmanClient;
	using Intel::WSManagement::EnumerateFilter;
	using Intel::Manageability::Exceptions::CimPropertyException;
	using Intel::Manageability::Cim::CimReference;
	using Intel::Manageability::Cim::Key;
	using std::shared_ptr;

	class CIMUNTYPEDFRAMEWORK_API CimObject : public CimData {
	public:
		class CimKeys {
		public:
			virtual ~CimKeys() {};
			const vector<Key> &Keys() const { return cimKeys; }
			vector<Key> &Keys() { return cimKeys; }
			void Keys(vector<Key> &Keys) { cimKeys = Keys; }

			// Indexer getter
			const string& GetKey(const string &name) const
			{
				// find it and return it if there otherwise throw a tantrum
				vector<Key>::const_iterator i = locate(name);
				if (i == cimKeys.end())
					throw CimPropertyException("The requested key \"" + name + "\" does not exist");

				return i->Value;
			}

			// Setter
			void SetKey(const string &name, const string &value, const bool isRef = false)
			{
				vector<Key>::iterator i = locate(name);
				if (i == cimKeys.end())
				{
					cimKeys.push_back(Key(name, value, isRef));
				}
				else
				{
					i->Value = value;
				}
			}


			// Utility functions to convert from keys to selectors and back
			static WsManSelectors KeysToSelectors(const CimKeys &keys)
			{
				WsManSelectors selectors = CimReference::KeysToWsManSelectors(keys.Keys());
				return selectors;
			}

			static CimKeys SelectorsToKeys(const WsManSelectors &selectors)
			{
				CimKeys ret;			
				vector<Key> keys = CimReference::WsManSelectorsToKeys(selectors);
				ret.Keys(keys);
				return ret;
			}

		private:
			vector<Key> cimKeys;

			class comparator {
			public:
				comparator(const string &val): value(val){}

				bool operator()(const Key &key)
				{
					return key.Name == value;
				};
				/*const comparator &operator=(const comparator &other)
				{
					value = other.value;
					return *this;
				};*/
			private:
				string value;

			};

			vector<Key>::iterator locate(const string &name)
			{
				vector<Key>::iterator i = find_if (cimKeys.begin(), cimKeys.end(), comparator(name) );
				return i;
			}

			vector<Key>::const_iterator locate(const string &name) const
			{
				vector<Key>::const_iterator i = find_if (cimKeys.begin(), cimKeys.end(), comparator(name) );;
				return i;
			}
		};

		// Constructors.
		CimObject();
		CimObject(const CimObject &Other);
		CimObject(ICimWsmanClient *client, const string &objectName,
			const string &xmlNameSpace, const string &xmlPrefix, const string &resourceURI);

		// Destructors.
		~CimObject();

		// Assignment operator.
		CimObject& operator=(const CimObject& other);

		// Retrieve fields and their values.
		virtual const VectorFieldData GetAllFields() const;

		// The "type" of the data

		// Name of real object e.g. CimPowerScheme
		const string &ObjectType() const;
		void ObjectType(const string &name);

		// The XML namespace
		const string &XmlNameSpace() const;
		void XmlNameSpace(const string &ns);

		// The XML prefix in tags (the "x" in <x:CimPowerScheme>)
		const string &XmlPrefix() const;
		void XmlPrefix(const string &prefix);

		// The ResourceURI for the object
		const string &ResourceURI() const;
		void ResourceURI(const string &uri);

		// Access to the WS-Management transport agent.
		ICimWsmanClient *WsmanClient() const;
		void WsmanClient(ICimWsmanClient *client);

		// CIM object methods:

		// Get methods.
		void Get();
		void Get(const CimKeys &keys);
		void Get(const CimReference &reference);

		// Various kinds of Enumerate.
		static vector<shared_ptr<CimObject> > Enumerate(ICimWsmanClient *client,
			const string &resourceURI, const CimKeys &keys = CimKeys());

		static vector<shared_ptr<CimObject> > Enumerate(ICimWsmanClient *client,
			const EnumerateFilter &filter);

		static vector<shared_ptr<CimReference> > EnumerateRef(ICimWsmanClient *client,
							const EnumerateFilter &filter);

		// Delete methods.
		void Delete(const CimKeys &keys) const;
		static void Delete(ICimWsmanClient *client, const CimReference &reference);
		static void Delete(ICimWsmanClient *client, const string &resourceURI, const CimKeys &keys);
		static void Delete(ICimWsmanClient *client, const string &resourceURI);

		// Put method.
		void Put(const CimKeys &keys) ;

		// Create method.
		CimReference Create() const ;

		// Invoke method.
		unsigned int Invoke(const string &methodName, const CimKeys &keys,
			const CimParam &input, CimParam &output);

	protected:
		// Nothing here at the moment.

	private:
		// The "type" information for the object.
		string _objectName;
		string _xmlNameSpace;
		string _xmlPrefix;
		string _resourceURI;

		// WS-Management client.
		ICimWsmanClient *_client;

		// Create a new object of the type specified by the URI,
		// with fields as given in the XML.
		static CimObject CreateObject(ICimWsmanClient *client,
			string resourceUri, const string &xml);

		// Get based on WS-Man selectors.
		CimObject Get(const WsManSelectors &sel);

		// Delete based on WS-Man selectors.
		static void Delete(ICimWsmanClient *client, const string &resourceURI, const WsManSelectors &selectors);
	};
};
};
};
};

#endif // CIMOBJECT_H
