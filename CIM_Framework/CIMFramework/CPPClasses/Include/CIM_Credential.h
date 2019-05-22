//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Credential.h
//
//  Contents:   Subclasses of CIM_Credential define materials, information or other data which are used to establish identity. Generally, there may be some shared information, or credential material which is used to identify and authenticate an entity in the process of gaining access to, or permission to use, resources. Such credential material may be used to authenticate an entity's identity initially, as done by a CIM_AuthenticationService, and additionally on an ongoing basis (for example, during the course of a connection or other security association), as proof that each received message or communication came from a valid 'user' of that credential material.
//
//              This file was automatically generated from CIM_Credential.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CREDENTIAL_H
#define CIM_CREDENTIAL_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Subclasses of CIM_Credential define materials, information or other data which are used to establish identity. Generally, there may be some shared information, or credential material which is used to identify and authenticate an entity in the process of gaining access to, or permission to use, resources. Such credential material may be used to authenticate an entity's identity initially, as done by a CIM_AuthenticationService, and additionally on an ongoing basis (for example, during the course of a connection or other security association), as proof that each received message or communication came from a valid 'user' of that credential material.
	class CIMFRAMEWORK_API CIM_Credential  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_Credential()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_Credential(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_Credential(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Credential keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The date and time when the credential was issued. Use a value of all '00000101000000.000000+000', (midnight, January 1, 1 BCE at coordinated universal time +0 minutes), if this information is not applicable. On CreateInstance, if this property is unspecified, or set to NULL, then current time is assumed.
		const CimDateTime Issued() const;

		// Optional, The date and time when the credential was issued. Use a value of all '00000101000000.000000+000', (midnight, January 1, 1 BCE at coordinated universal time +0 minutes), if this information is not applicable. On CreateInstance, if this property is unspecified, or set to NULL, then current time is assumed.
		void Issued(const CimDateTime &value); 

		// Is true if the field Issued exists in the current object, otherwise is false.
		bool IssuedExists() const;

		// Remove Issued field.
		void RemoveIssued(); 

		// Optional, The date and time when the credential expires (and is not appropriate for use for authentication/ authorization). If this information is not applicable, Use a value of '99991231235959.999999+999', (1 microsecond before midnight, December 31, 9999 CE, at coordinated universal time + 999 minutes). 
		// On CreateInstance, if this property is unspecified, or set to NULL, then a value of '99991231235959.999999+999' is assumed. Note that this property does not define how the expiration is set - but that there IS an expiration. The property may be set to either a specific date/time or an interval (calculated from the Issued datetime). For example, for Certificate Authority-signed public key, the expiration is determined by the CA. Another example is a voice mail password that expires 60 days after it is set/issued.
		const CimDateTime Expires() const;

		// Optional, The date and time when the credential expires (and is not appropriate for use for authentication/ authorization). If this information is not applicable, Use a value of '99991231235959.999999+999', (1 microsecond before midnight, December 31, 9999 CE, at coordinated universal time + 999 minutes). 
		// On CreateInstance, if this property is unspecified, or set to NULL, then a value of '99991231235959.999999+999' is assumed. Note that this property does not define how the expiration is set - but that there IS an expiration. The property may be set to either a specific date/time or an interval (calculated from the Issued datetime). For example, for Certificate Authority-signed public key, the expiration is determined by the CA. Another example is a voice mail password that expires 60 days after it is set/issued.
		void Expires(const CimDateTime &value); 

		// Is true if the field Expires exists in the current object, otherwise is false.
		bool ExpiresExists() const;

		// Remove Expires field.
		void RemoveExpires(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Credential> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Credential(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Credential(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_CREDENTIAL_H
