//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyManagementService.h
//
//  Contents:   This service contains the information necessary to represent and manage the functionality provided by the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicKeyManagementService.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PUBLICKEYMANAGEMENTSERVICE_H
#define AMT_PUBLICKEYMANAGEMENTSERVICE_H 1
#include "CIM_CredentialManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This service contains the information necessary to represent and manage the functionality provided by the Intel(R) AMT CertStore.
	class CIMFRAMEWORK_API AMT_PublicKeyManagementService  : public CIM_CredentialManagementService
	{
	public:

		//Default constructor
		AMT_PublicKeyManagementService()
			: CIM_CredentialManagementService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_CredentialManagementService::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_PublicKeyManagementService(ICimWsmanClient *client)
			: CIM_CredentialManagementService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_CredentialManagementService::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_PublicKeyManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PublicKeyManagementService keys
		class CimKeys : public CIM_CredentialManagementService::CimKeys
		{
		public:
		};
		//Input parameter for function AddCRL
		class CIMFRAMEWORK_API AddCRL_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddCRL_INPUT() : CimParam() {}

			// Class Destructor
			~AddCRL_INPUT(){}

			// Optional, The issuer URL of the revoked certificates.
			void Url(const string &value); 

			// Required, Notice: the values of this array are actually base64 encoded values. A list of serial numbers removed by the CA which is specified in the Url variable.
			void SerialNumbers(const vector<string> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddCRL
		class CIMFRAMEWORK_API AddCRL_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddCRL_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddCRL_OUTPUT(){}

			// class fields
			// Reference to the new AMT_CRL instance.
			const CimReference CRL() const;
			bool CRLExists() const;
		private:
		};

		// This call adds a Certificate revocation list to be used by the Intel(R) AMT device.
		virtual unsigned int AddCRL(const AddCRL_INPUT &input, AddCRL_OUTPUT &output);

		// Remove the usage of CRL during the authentication process
		virtual unsigned int ResetCRLList();

		//Input parameter for function AddCertificate
		class CIMFRAMEWORK_API AddCertificate_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddCertificate_INPUT() : CimParam() {}

			// Class Destructor
			~AddCertificate_INPUT(){}

			// Required,
			void CertificateBlob(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddCertificate
		class CIMFRAMEWORK_API AddCertificate_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddCertificate_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddCertificate_OUTPUT(){}

			// class fields
			// Certificate encoded in X.509 format
			const CimReference CreatedCertificate() const;
			bool CreatedCertificateExists() const;
		private:
		};

		// This function adds new certificate to the Intel(R) AMT CertStore. A certificate cannot be removed if it is referenced (for example, used by TLS, 802.1X or EAC).
		virtual unsigned int AddCertificate(const AddCertificate_INPUT &input, AddCertificate_OUTPUT &output);

		//Input parameter for function AddTrustedRootCertificate
		class CIMFRAMEWORK_API AddTrustedRootCertificate_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddTrustedRootCertificate_INPUT() : CimParam() {}

			// Class Destructor
			~AddTrustedRootCertificate_INPUT(){}

			// Required,
			void CertificateBlob(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddTrustedRootCertificate
		class CIMFRAMEWORK_API AddTrustedRootCertificate_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddTrustedRootCertificate_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddTrustedRootCertificate_OUTPUT(){}

			// class fields
			// Certificate encoded in X.509 format
			const CimReference CreatedCertificate() const;
			bool CreatedCertificateExists() const;
		private:
		};

		// This function adds new root certificate to the Intel(R) AMT CertStore. A certificate cannot be removed if it is referenced (for example, used by TLS, 802.1X or EAC).
		virtual unsigned int AddTrustedRootCertificate(const AddTrustedRootCertificate_INPUT &input, AddTrustedRootCertificate_OUTPUT &output);

		//Input parameter for function AddKey
		class CIMFRAMEWORK_API AddKey_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddKey_INPUT() : CimParam() {}

			// Class Destructor
			~AddKey_INPUT(){}

			// Required, RSA Key encoded as DES PKCS#1
			void KeyBlob(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddKey
		class CIMFRAMEWORK_API AddKey_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddKey_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddKey_OUTPUT(){}

			// class fields
			// 
			const CimReference CreatedKey() const;
			bool CreatedKeyExists() const;
		private:
		};

		// This function adds new certificate key to the Intel(R) AMT CertStore. A key cannot be removed if its corresponding certificate is referenced (for example, used by TLS, 802.1X or EAC).
		virtual unsigned int AddKey(const AddKey_INPUT &input, AddKey_OUTPUT &output);

		//Input parameter for function GeneratePKCS10RequestEx
		class CIMFRAMEWORK_API GeneratePKCS10RequestEx_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GeneratePKCS10RequestEx_INPUT() : CimParam() {}

			// Class Destructor
			~GeneratePKCS10RequestEx_INPUT(){}

			// Required, An EPR to a key pair.
			void KeyPair(const CimReference &value); 

			// Required, The signing algorithm that the FW should use for signing the certificate request
			// Legal values:
			// SHA1: 0
			// SHA256: 1
			// SHA384: 2
			// Reserved: ..
			void SigningAlgorithm(const unsigned int value); 

			// Required, A binary representation of the null-signed PKCS#10 request.the request must include a valid PKCS10RequestInfo, that will be signed by AMT FW.  The Public Key specified in the request must match the public key of the referenced KeyPair parameter.
			void NullSignedCertificateRequest(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GeneratePKCS10RequestEx
		class CIMFRAMEWORK_API GeneratePKCS10RequestEx_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GeneratePKCS10RequestEx_OUTPUT() : CimParam() {}

			// Class Destructor
			~GeneratePKCS10RequestEx_OUTPUT(){}

			// class fields
			// A binary representation of the PKCS#10 request, signed by FW.
			const Base64 SignedCertificateRequest() const;
			bool SignedCertificateRequestExists() const;
		private:
		};

		// This API is used to create a PKCS#10 certificate signing request based on a key from the key store.
		virtual unsigned int GeneratePKCS10RequestEx(const GeneratePKCS10RequestEx_INPUT &input, GeneratePKCS10RequestEx_OUTPUT &output);

		//Input parameter for function GenerateKeyPair
		class CIMFRAMEWORK_API GenerateKeyPair_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GenerateKeyPair_INPUT() : CimParam() {}

			// Class Destructor
			~GenerateKeyPair_INPUT(){}

			// Required, The algorithm of the generated key.
			// Legal values:
			// RSA: 0
			// Reserved: ..
			void KeyAlgorithm(const unsigned int value); 

			// Required, The length of the generatd key in bits.
			void KeyLength(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GenerateKeyPair
		class CIMFRAMEWORK_API GenerateKeyPair_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GenerateKeyPair_OUTPUT() : CimParam() {}

			// Class Destructor
			~GenerateKeyPair_OUTPUT(){}

			// class fields
			// An EPR to a key pair.
			const CimReference KeyPair() const;
			bool KeyPairExists() const;
		private:
		};

		// This API is used to generate a key in the FW
		virtual unsigned int GenerateKeyPair(const GenerateKeyPair_INPUT &input, GenerateKeyPair_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PublicKeyManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PublicKeyManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_CredentialManagementService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_CredentialManagementService::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PublicKeyManagementService(const CimObject &object)
			: CIM_CredentialManagementService(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_CredentialManagementService::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_CredentialManagementService::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // AMT_PUBLICKEYMANAGEMENTSERVICE_H
