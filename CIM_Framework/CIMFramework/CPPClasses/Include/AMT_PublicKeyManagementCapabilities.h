//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyManagementCapabilities.h
//
//  Contents:   Represents the Certificate Store Capabilitites of the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_PublicKeyManagementCapabilities.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PUBLICKEYMANAGEMENTCAPABILITIES_H
#define AMT_PUBLICKEYMANAGEMENTCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the Certificate Store Capabilitites of the Intel(R) AMT system.
	class CIMFRAMEWORK_API AMT_PublicKeyManagementCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_PublicKeyManagementCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		AMT_PublicKeyManagementCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~AMT_PublicKeyManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PublicKeyManagementCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The maximum supported size (in bytes) of the CRL store in the internal certificate store.
		const unsigned int MaximumCRLSize() const;

		// Optional, The maximum supported size (in bytes) of the CRL store in the internal certificate store.
		void MaximumCRLSize(const unsigned int value); 

		// Is true if the field MaximumCRLSize exists in the current object, otherwise is false.
		bool MaximumCRLSizeExists() const;

		// Remove MaximumCRLSize field.
		void RemoveMaximumCRLSize(); 

		// Optional, The maximum supported size (in bytes) of a trusted root certificate in the internal certificate store.
		const unsigned int RootCertMaxSize() const;

		// Optional, The maximum supported size (in bytes) of a trusted root certificate in the internal certificate store.
		void RootCertMaxSize(const unsigned int value); 

		// Is true if the field RootCertMaxSize exists in the current object, otherwise is false.
		bool RootCertMaxSizeExists() const;

		// Remove RootCertMaxSize field.
		void RemoveRootCertMaxSize(); 

		// Optional, The maximum number of trusted root certificates supported by the internal certificate store.
		const unsigned int RootCertMaxCount() const;

		// Optional, The maximum number of trusted root certificates supported by the internal certificate store.
		void RootCertMaxCount(const unsigned int value); 

		// Is true if the field RootCertMaxCount exists in the current object, otherwise is false.
		bool RootCertMaxCountExists() const;

		// Remove RootCertMaxCount field.
		void RemoveRootCertMaxCount(); 

		// Optional, The maximum supported size (in bytes) of a trusted certificate subject common name in the internal certificate store.
		const unsigned int CommonNameMaxSize() const;

		// Optional, The maximum supported size (in bytes) of a trusted certificate subject common name in the internal certificate store.
		void CommonNameMaxSize(const unsigned int value); 

		// Is true if the field CommonNameMaxSize exists in the current object, otherwise is false.
		bool CommonNameMaxSizeExists() const;

		// Remove CommonNameMaxSize field.
		void RemoveCommonNameMaxSize(); 

		// Optional, The maximum number of trusted subject common names supported by the internal certificate store.
		const unsigned int CommonNameMaxCount() const;

		// Optional, The maximum number of trusted subject common names supported by the internal certificate store.
		void CommonNameMaxCount(const unsigned int value); 

		// Is true if the field CommonNameMaxCount exists in the current object, otherwise is false.
		bool CommonNameMaxCountExists() const;

		// Remove CommonNameMaxCount field.
		void RemoveCommonNameMaxCount(); 

		// Optional, The maximum size (in bytes) of a certificate supported by the internal certificate store.
		const unsigned int CertChainMaxSize() const;

		// Optional, The maximum size (in bytes) of a certificate supported by the internal certificate store.
		void CertChainMaxSize(const unsigned int value); 

		// Is true if the field CertChainMaxSize exists in the current object, otherwise is false.
		bool CertChainMaxSizeExists() const;

		// Remove CertChainMaxSize field.
		void RemoveCertChainMaxSize(); 

		// Optional, An array of unsigned integer values, each of which gives the number of bits in a supported RSA key length.
		const vector<unsigned int> SupportedKeyLengths() const;

		// Optional, An array of unsigned integer values, each of which gives the number of bits in a supported RSA key length.
		void SupportedKeyLengths(const vector<unsigned int> &value); 

		// Is true if the field SupportedKeyLengths exists in the current object, otherwise is false.
		bool SupportedKeyLengthsExists() const;

		// Remove SupportedKeyLengths field.
		void RemoveSupportedKeyLengths(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PublicKeyManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PublicKeyManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PublicKeyManagementCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 7);
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
#endif // AMT_PUBLICKEYMANAGEMENTCAPABILITIES_H
