//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AccountManagementCapabilities.h
//
//  Contents:   AccountManagementCapabilities describes the capabilities supported for managing Accounts associated with an instance of AccountManagementService. AccountManagementCapabilities is associated with an instance of AccountManagementService through the ElementCapabilities association.
//
//              This file was automatically generated from CIM_AccountManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ACCOUNTMANAGEMENTCAPABILITIES_H
#define CIM_ACCOUNTMANAGEMENTCAPABILITIES_H 1
#include "CIM_EnabledLogicalElementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// AccountManagementCapabilities describes the capabilities supported for managing Accounts associated with an instance of AccountManagementService. AccountManagementCapabilities is associated with an instance of AccountManagementService through the ElementCapabilities association.
	class CIMFRAMEWORK_API CIM_AccountManagementCapabilities  : public CIM_EnabledLogicalElementCapabilities
	{
	public:

		//Default constructor
		CIM_AccountManagementCapabilities()
			: CIM_EnabledLogicalElementCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_AccountManagementCapabilities(ICimWsmanClient *client)
			: CIM_EnabledLogicalElementCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_AccountManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AccountManagementCapabilities keys
		class CimKeys : public CIM_EnabledLogicalElementCapabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, OperationsSupported describes the type of operations that are supported for an Account associated with the AccountManagementService.
		// "Create" indicates the AccountManagementService may be used to create new accounts.
		// "Modify" indicates that the associated Accounts may be modified.
		// "Delete" indicates that associated Accounts may be deleted.
		const vector<unsigned short> OperationsSupported() const;

		// Optional, OperationsSupported describes the type of operations that are supported for an Account associated with the AccountManagementService.
		// "Create" indicates the AccountManagementService may be used to create new accounts.
		// "Modify" indicates that the associated Accounts may be modified.
		// "Delete" indicates that associated Accounts may be deleted.
		void OperationsSupported(const vector<unsigned short> &value); 

		// Is true if the field OperationsSupported exists in the current object, otherwise is false.
		bool OperationsSupportedExists() const;

		// Remove OperationsSupported field.
		void RemoveOperationsSupported(); 

		// Optional, Additional implementation-specific algorithms that a client may use to encrypt a value in the UserPassword property when creating or modifying an instance of CIM_Account. If this property is non-NULL, a client may select an algorithm in it by setting CIM_Account.UserPasswordEncryptionAlgorithm to 1 ("Other") and setting CIM_Account.OtherUserPasswordEncryptionAlgorithm to the value of the selected algorithm string.
		const vector<string> OtherSupportedUserPasswordEncryptionAlgorithms() const;

		// Optional, Additional implementation-specific algorithms that a client may use to encrypt a value in the UserPassword property when creating or modifying an instance of CIM_Account. If this property is non-NULL, a client may select an algorithm in it by setting CIM_Account.UserPasswordEncryptionAlgorithm to 1 ("Other") and setting CIM_Account.OtherUserPasswordEncryptionAlgorithm to the value of the selected algorithm string.
		void OtherSupportedUserPasswordEncryptionAlgorithms(const vector<string> &value); 

		// Is true if the field OtherSupportedUserPasswordEncryptionAlgorithms exists in the current object, otherwise is false.
		bool OtherSupportedUserPasswordEncryptionAlgorithmsExists() const;

		// Remove OtherSupportedUserPasswordEncryptionAlgorithms field.
		void RemoveOtherSupportedUserPasswordEncryptionAlgorithms(); 

		// Optional, This property enumerates encryption algorithms that a client may use to encrypt a value in the UserPassword property when creating or modifying an instance of CIM_Account. This capability is aimed at ensuring some measure of confidentiality when the password is transferred over an unencrypted transport protocol. An implementation may elect to accept only encrypted passwords, without regard to whether the transport protocol is encrypted. Similarly, a a client may elect to always provide encrypted passwords to implementations that accept either unencrypted or encrypted passwords, even if the underlying transport protocol is encrypted.
		// See CIM_Account property UserPasswordEncryptionAlgorithm for a description of each enum value.
		const vector<unsigned short> SupportedUserPasswordEncryptionAlgorithms() const;

		// Optional, This property enumerates encryption algorithms that a client may use to encrypt a value in the UserPassword property when creating or modifying an instance of CIM_Account. This capability is aimed at ensuring some measure of confidentiality when the password is transferred over an unencrypted transport protocol. An implementation may elect to accept only encrypted passwords, without regard to whether the transport protocol is encrypted. Similarly, a a client may elect to always provide encrypted passwords to implementations that accept either unencrypted or encrypted passwords, even if the underlying transport protocol is encrypted.
		// See CIM_Account property UserPasswordEncryptionAlgorithm for a description of each enum value.
		void SupportedUserPasswordEncryptionAlgorithms(const vector<unsigned short> &value); 

		// Is true if the field SupportedUserPasswordEncryptionAlgorithms exists in the current object, otherwise is false.
		bool SupportedUserPasswordEncryptionAlgorithmsExists() const;

		// Remove SupportedUserPasswordEncryptionAlgorithms field.
		void RemoveSupportedUserPasswordEncryptionAlgorithms(); 

		// Optional, A value unique to the specific WBEM server that may be used in the selected UserPassword encryption algorithm to ensure a value that is unique among all WBEM servers even if a user uses the same password on multiple WBEM servers.
		const string UserPasswordEncryptionSalt() const;

		// Optional, A value unique to the specific WBEM server that may be used in the selected UserPassword encryption algorithm to ensure a value that is unique among all WBEM servers even if a user uses the same password on multiple WBEM servers.
		void UserPasswordEncryptionSalt(const string &value); 

		// Is true if the field UserPasswordEncryptionSalt exists in the current object, otherwise is false.
		bool UserPasswordEncryptionSaltExists() const;

		// Remove UserPasswordEncryptionSalt field.
		void RemoveUserPasswordEncryptionSalt(); 

		// Optional, MaximumAccountsSupported shall indicate the maximum number of accounts that may be managed by the associated instance of CIM_AccountManagementService. Note that if multiple instances of CIM_AccountManagementService manage the accounts of a system, the total maximum number of accounts supported on the system is the sum of MaximumAccountsSupported for all of the instances of CIM_AccountManagementService. A value of zero shall indicate that the maximum number of accounts is unknown or that a maximum number of accounts is not enforced.
		const unsigned short MaximumAccountsSupported() const;

		// Optional, MaximumAccountsSupported shall indicate the maximum number of accounts that may be managed by the associated instance of CIM_AccountManagementService. Note that if multiple instances of CIM_AccountManagementService manage the accounts of a system, the total maximum number of accounts supported on the system is the sum of MaximumAccountsSupported for all of the instances of CIM_AccountManagementService. A value of zero shall indicate that the maximum number of accounts is unknown or that a maximum number of accounts is not enforced.
		void MaximumAccountsSupported(const unsigned short value); 

		// Is true if the field MaximumAccountsSupported exists in the current object, otherwise is false.
		bool MaximumAccountsSupportedExists() const;

		// Remove MaximumAccountsSupported field.
		void RemoveMaximumAccountsSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AccountManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AccountManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElementCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AccountManagementCapabilities(const CimObject &object)
			: CIM_EnabledLogicalElementCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElementCapabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_ACCOUNTMANAGEMENTCAPABILITIES_H
