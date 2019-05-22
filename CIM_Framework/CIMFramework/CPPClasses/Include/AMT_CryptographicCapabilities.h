//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_CryptographicCapabilities.h
//
//  Contents:   Describes the cryptographic capabilities of the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_CryptographicCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_CRYPTOGRAPHICCAPABILITIES_H
#define AMT_CRYPTOGRAPHICCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the cryptographic capabilities of the Intel(R) AMT subsystem.
	class CIMFRAMEWORK_API AMT_CryptographicCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_CryptographicCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_CryptographicCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_CryptographicCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_CryptographicCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates whether or not cryptographic algorithms are hardware accelerated.
		const unsigned int HardwareAcceleration() const;

		// Optional, Indicates whether or not cryptographic algorithms are hardware accelerated.
		void HardwareAcceleration(const unsigned int value); 

		// Is true if the field HardwareAcceleration exists in the current object, otherwise is false.
		bool HardwareAccelerationExists() const;

		// Remove HardwareAcceleration field.
		void RemoveHardwareAcceleration(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_CryptographicCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_CryptographicCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_CryptographicCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // AMT_CRYPTOGRAPHICCAPABILITIES_H
