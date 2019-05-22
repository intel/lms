//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteIdentity.h
//
//  Contents:   An instance of RemoteIdentity is an Identity that should be used to provide a persistent representation of a security principal for which authoritative information required for mapping to users or groups is not otherwise modeled.
//
//              This file was automatically generated from CIM_RemoteIdentity.mof,  version: 2.16.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REMOTEIDENTITY_H
#define CIM_REMOTEIDENTITY_H 1
#include "CIM_Identity.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An instance of RemoteIdentity is an Identity that should be used to provide a persistent representation of a security principal for which authoritative information required for mapping to users or groups is not otherwise modeled.
	class CIMFRAMEWORK_API CIM_RemoteIdentity  : public CIM_Identity
	{
	public:

		//Default constructor
		CIM_RemoteIdentity()
			: CIM_Identity(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Identity::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_RemoteIdentity(ICimWsmanClient *client)
			: CIM_Identity(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Identity::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_RemoteIdentity(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RemoteIdentity keys
		class CimKeys : public CIM_Identity::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Name is an octet string representing an identifier that can be correlated to the authoritative information.  The type and format are defined by the NameFormat and OtherNameFormat properties.
		const Base64 Name() const;

		// Optional, Name is an octet string representing an identifier that can be correlated to the authoritative information.  The type and format are defined by the NameFormat and OtherNameFormat properties.
		void Name(const Base64 &value); 

		// Is true if the field Name exists in the current object, otherwise is false.
		bool NameExists() const;

		// Remove Name field.
		void RemoveName(); 

		// Optional, An enumeration defining the type and format of Name.
		// 	* GID: A Unix Group ID, an integer encoded as an octet string. For example, the decimal value 25 results in the octetstring 0x0000000519.
		// 	* UID: A Unix User ID, an integer encoded as an octet string. For example, the decimal value 100 results in the octetstring 0x0000000564.
		// 	* SID: A Windows Security ID in its native binary format
		// 	* DN: An ASN.1-encoded LDAP Distinguished Name
		// 	* KID: A Kerberos Remote Identifier, a string encoded as an octet string.
		const unsigned short NameFormat() const;

		// Optional, An enumeration defining the type and format of Name.
		// 	* GID: A Unix Group ID, an integer encoded as an octet string. For example, the decimal value 25 results in the octetstring 0x0000000519.
		// 	* UID: A Unix User ID, an integer encoded as an octet string. For example, the decimal value 100 results in the octetstring 0x0000000564.
		// 	* SID: A Windows Security ID in its native binary format
		// 	* DN: An ASN.1-encoded LDAP Distinguished Name
		// 	* KID: A Kerberos Remote Identifier, a string encoded as an octet string.
		void NameFormat(const unsigned short value); 

		// Is true if the field NameFormat exists in the current object, otherwise is false.
		bool NameFormatExists() const;

		// Remove NameFormat field.
		void RemoveNameFormat(); 

		// Optional, OtherNameFormat is a string that describes the format of the Name property when NameFormat is set to  "Other" .  The format of this string is vendor specific.
		const string OtherNameFormat() const;

		// Optional, OtherNameFormat is a string that describes the format of the Name property when NameFormat is set to  "Other" .  The format of this string is vendor specific.
		void OtherNameFormat(const string &value); 

		// Is true if the field OtherNameFormat exists in the current object, otherwise is false.
		bool OtherNameFormatExists() const;

		// Remove OtherNameFormat field.
		void RemoveOtherNameFormat(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RemoteIdentity> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RemoteIdentity(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Identity(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Identity::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RemoteIdentity(const CimObject &object)
			: CIM_Identity(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Identity::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Identity::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
		static const CimFieldAttribute _metadata[];
		static const string CLASS_NAME;
		static const string CLASS_URI;
		static const string CLASS_NS;
		static const string CLASS_NS_PREFIX;
		static vector<CimFieldAttribute> _classMetaData;
	};

} // close namespace Typed
} // close namespace Cim
} // close namespace Manageability
} // close namespace Intel
#endif // CIM_REMOTEIDENTITY_H
