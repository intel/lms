//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Account.h
//
//  Contents:   CIM_Account is the information held by a SecurityService to track identity and privileges managed by that service. Common examples of an Account are the entries in a UNIX /etc/passwd file. Several kinds of security services use various information from those entries - the /bin/login program uses the account name ('root') and hashed password to authenticate users, and the file service, for instance, uses the UserID field ('0') and GroupID field ('0') to record ownership and determine access control privileges on files in the file system. This class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. 
//              
//              The semantics of Account overlap with that of the class, CIM_Identity. However, aspects of Account - such as its specific tie to a System - are valuable and have been widely implemented. For this reason, the Account and Identity classes are associated using a subclass of LogicalIdentity (AccountIdentity), instead of deprecating the Account class in the CIM Schema. When an Account has been authenticated, the corresponding Identity's TrustEstablished Boolean would be set to TRUE. Then, the Identity class can be used as defined for authorization purposes.
//
//              This file was automatically generated from CIM_Account.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ACCOUNT_H
#define CIM_ACCOUNT_H 1
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_Account is the information held by a SecurityService to track identity and privileges managed by that service. Common examples of an Account are the entries in a UNIX /etc/passwd file. Several kinds of security services use various information from those entries - the /bin/login program uses the account name ('root') and hashed password to authenticate users, and the file service, for instance, uses the UserID field ('0') and GroupID field ('0') to record ownership and determine access control privileges on files in the file system. This class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. 
	// 
	// The semantics of Account overlap with that of the class, CIM_Identity. However, aspects of Account - such as its specific tie to a System - are valuable and have been widely implemented. For this reason, the Account and Identity classes are associated using a subclass of LogicalIdentity (AccountIdentity), instead of deprecating the Account class in the CIM Schema. When an Account has been authenticated, the corresponding Identity's TrustEstablished Boolean would be set to TRUE. Then, the Identity class can be used as defined for authorization purposes.
	class CIMFRAMEWORK_API CIM_Account  : public CIM_EnabledLogicalElement
	{
	public:

		//Default constructor
		CIM_Account()
			: CIM_EnabledLogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}

		//constructor which receives WSMan client
		CIM_Account(ICimWsmanClient *client)
			: CIM_EnabledLogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}

		//Destructor
		virtual ~CIM_Account(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Account keys
		class CimKeys : public CIM_EnabledLogicalElement::CimKeys
		{
		public:
			// Key, Required, The scoping System's CCN.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The scoping System's CCN.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The scoping System's Name.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The scoping System's Name.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, The Name property defines the label by which the object is known. The value of this property may be set to be the same as that of the UserID property or, in the case of an LDAP-derived instance, the Name property value may be set to the distinguishedName of the LDAP-accessed object instance.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property defines the label by which the object is known. The value of this property may be set to be the same as that of the UserID property or, in the case of an LDAP-derived instance, the Name property value may be set to the distinguishedName of the LDAP-accessed object instance.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, The scoping System's CCN.
		const string SystemCreationClassName() const;

		// Key, Required, The scoping System's CCN.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The scoping System's Name.
		const string SystemName() const;

		// Key, Required, The scoping System's Name.
		void SystemName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Optional, UserID is the value used by the SecurityService to represent identity. For an authentication service, the UserID may be the name of the user, or for an authorization service the value which serves as a handle to a mapping of the identity.
		const string UserID() const;

		// Optional, UserID is the value used by the SecurityService to represent identity. For an authentication service, the UserID may be the name of the user, or for an authorization service the value which serves as a handle to a mapping of the identity.
		void UserID(const string &value); 

		// Is true if the field UserID exists in the current object, otherwise is false.
		bool UserIDExists() const;

		// Remove UserID field.
		void RemoveUserID(); 

		// Optional, In the case of an LDAP-derived instance, the ObjectClass property value(s) may be set to the objectClass attribute values.
		const vector<string> ObjectClass() const;

		// Optional, In the case of an LDAP-derived instance, the ObjectClass property value(s) may be set to the objectClass attribute values.
		void ObjectClass(const vector<string> &value); 

		// Is true if the field ObjectClass exists in the current object, otherwise is false.
		bool ObjectClassExists() const;

		// Remove ObjectClass field.
		void RemoveObjectClass(); 

		// Optional, The Descriptions property values may contain human-readable descriptions of the object. In the case of an LDAP-derived instance, the description attribute may have multiple values that, therefore, cannot be placed in the inherited Description property.
		const vector<string> Descriptions() const;

		// Optional, The Descriptions property values may contain human-readable descriptions of the object. In the case of an LDAP-derived instance, the description attribute may have multiple values that, therefore, cannot be placed in the inherited Description property.
		void Descriptions(const vector<string> &value); 

		// Is true if the field Descriptions exists in the current object, otherwise is false.
		bool DescriptionsExists() const;

		// Remove Descriptions field.
		void RemoveDescriptions(); 

		// Optional, Based on RFC1274, the host name of the system(s) for which the account applies. The host name may be a fully-qualified DNS name or it may be an unqualified host name.
		const vector<string> Host() const;

		// Optional, Based on RFC1274, the host name of the system(s) for which the account applies. The host name may be a fully-qualified DNS name or it may be an unqualified host name.
		void Host(const vector<string> &value); 

		// Is true if the field Host exists in the current object, otherwise is false.
		bool HostExists() const;

		// Remove Host field.
		void RemoveHost(); 

		// Optional, This property contains the name of a locality, such as a city, county or other geographic region.
		const vector<string> LocalityName() const;

		// Optional, This property contains the name of a locality, such as a city, county or other geographic region.
		void LocalityName(const vector<string> &value); 

		// Is true if the field LocalityName exists in the current object, otherwise is false.
		bool LocalityNameExists() const;

		// Remove LocalityName field.
		void RemoveLocalityName(); 

		// Required, The name of the organization related to the account.
		const vector<string> OrganizationName() const;

		// Required, The name of the organization related to the account.
		void OrganizationName(const vector<string> &value); 

		// Is true if the field OrganizationName exists in the current object, otherwise is false.
		bool OrganizationNameExists() const;

		// Remove OrganizationName field.
		void RemoveOrganizationName(); 

		// Optional, The name of an organizational unit related to the account.
		const vector<string> OU() const;

		// Optional, The name of an organizational unit related to the account.
		void OU(const vector<string> &value); 

		// Is true if the field OU exists in the current object, otherwise is false.
		bool OUExists() const;

		// Remove OU field.
		void RemoveOU(); 

		// Optional, In the case of an LDAP-derived instance, the SeeAlso property specifies distinguished name of other Directory objects which may be other aspects (in some sense) of the same real world object.
		const vector<string> SeeAlso() const;

		// Optional, In the case of an LDAP-derived instance, the SeeAlso property specifies distinguished name of other Directory objects which may be other aspects (in some sense) of the same real world object.
		void SeeAlso(const vector<string> &value); 

		// Is true if the field SeeAlso exists in the current object, otherwise is false.
		bool SeeAlsoExists() const;

		// Remove SeeAlso field.
		void RemoveSeeAlso(); 

		// Optional, Based on inetOrgPerson and for directory compatibility, the UserCertificate property may be used to specify a public key certificate for the person.
		const HexBinary UserCertificate() const;

		// Optional, Based on inetOrgPerson and for directory compatibility, the UserCertificate property may be used to specify a public key certificate for the person.
		void UserCertificate(const HexBinary &value); 

		// Is true if the field UserCertificate exists in the current object, otherwise is false.
		bool UserCertificateExists() const;

		// Remove UserCertificate field.
		void RemoveUserCertificate(); 

		// Optional, In the case of an LDAP-derived instance, the UserPassword property may contain an encrypted password used to access the person's resources in a directory.
		const HexBinary UserPassword() const;

		// Optional, In the case of an LDAP-derived instance, the UserPassword property may contain an encrypted password used to access the person's resources in a directory.
		void UserPassword(const HexBinary &value); 

		// Is true if the field UserPassword exists in the current object, otherwise is false.
		bool UserPasswordExists() const;

		// Remove UserPassword field.
		void RemoveUserPassword(); 

		// Optional, The encryption algorithm (if any) used by the client to produce the value in the UserPassword property when creating or modifying an instance of CIM_Account. The original password is encrypted using the algorithm specified in this property, and UserPassword contains the resulting encrypted value. In response to an operation request that would return the value of the UserPassword property to a client, an implementation shall instead return an array of length zero.
		// The value of UserPasswordEncryptionAlgorithm in an instance of CIM_Account shall be 0 ("None") unless the SupportedUserPasswordEncryptionAlgorithms[] property in the CIM_AccountManagementCapabilities instance associated with the CIM_AccountManagementService instance associated with the CIM_Account instance contains a non-null entry other than 0 ("None").
		// This property does not prevent the use of encryption at the transport, network, or data-link layer to protect communications between a management client and the server, nor is it meant to encourage communications without such encryption.
		// The supported values for this property are:
		// - 0 ("None"): Indicates that the contents of UserPassword are not encrypted.
		// - 1 ("Other"): Indicates that the contents of UserPassword are encrypted using an algorithm not specifically identified in the value map for this property, and that this algorithm is described in OtherUserPasswordEncryptionAlgorithm.
		// - 2 ("HTTP Digest MD5(A1)"): The MD5 hash algorithm, applied to the string A1 defined in RFC2617 as the concatenation username-value ":" realm-value ":" passwd, where username-value is provided by the client as the value of the UserID property. passwd is the underlying user password. realm-value is the HTTP digest realm value, and is provided by the server. The semantics of the HTTP digest realm are specified in RFC 2617. The server may surface the realm-value in the UserPasswordEncryptionSalt property of CIM_AccountManagementCapabilities.
		const unsigned short UserPasswordEncryptionAlgorithm() const;

		// Optional, The encryption algorithm (if any) used by the client to produce the value in the UserPassword property when creating or modifying an instance of CIM_Account. The original password is encrypted using the algorithm specified in this property, and UserPassword contains the resulting encrypted value. In response to an operation request that would return the value of the UserPassword property to a client, an implementation shall instead return an array of length zero.
		// The value of UserPasswordEncryptionAlgorithm in an instance of CIM_Account shall be 0 ("None") unless the SupportedUserPasswordEncryptionAlgorithms[] property in the CIM_AccountManagementCapabilities instance associated with the CIM_AccountManagementService instance associated with the CIM_Account instance contains a non-null entry other than 0 ("None").
		// This property does not prevent the use of encryption at the transport, network, or data-link layer to protect communications between a management client and the server, nor is it meant to encourage communications without such encryption.
		// The supported values for this property are:
		// - 0 ("None"): Indicates that the contents of UserPassword are not encrypted.
		// - 1 ("Other"): Indicates that the contents of UserPassword are encrypted using an algorithm not specifically identified in the value map for this property, and that this algorithm is described in OtherUserPasswordEncryptionAlgorithm.
		// - 2 ("HTTP Digest MD5(A1)"): The MD5 hash algorithm, applied to the string A1 defined in RFC2617 as the concatenation username-value ":" realm-value ":" passwd, where username-value is provided by the client as the value of the UserID property. passwd is the underlying user password. realm-value is the HTTP digest realm value, and is provided by the server. The semantics of the HTTP digest realm are specified in RFC 2617. The server may surface the realm-value in the UserPasswordEncryptionSalt property of CIM_AccountManagementCapabilities.
		void UserPasswordEncryptionAlgorithm(const unsigned short value); 

		// Is true if the field UserPasswordEncryptionAlgorithm exists in the current object, otherwise is false.
		bool UserPasswordEncryptionAlgorithmExists() const;

		// Remove UserPasswordEncryptionAlgorithm field.
		void RemoveUserPasswordEncryptionAlgorithm(); 

		// Optional, If the UserPasswordEncryptionAlgorithm property is set to 1 ("Other") this property contains a free form string that provides more information about the encryption algorithm. If UserPasswordEncryptionAlgorithm is not set to 1 ("Other") this property has no meaning.
		const string OtherUserPasswordEncryptionAlgorithm() const;

		// Optional, If the UserPasswordEncryptionAlgorithm property is set to 1 ("Other") this property contains a free form string that provides more information about the encryption algorithm. If UserPasswordEncryptionAlgorithm is not set to 1 ("Other") this property has no meaning.
		void OtherUserPasswordEncryptionAlgorithm(const string &value); 

		// Is true if the field OtherUserPasswordEncryptionAlgorithm exists in the current object, otherwise is false.
		bool OtherUserPasswordEncryptionAlgorithmExists() const;

		// Remove OtherUserPasswordEncryptionAlgorithm field.
		void RemoveOtherUserPasswordEncryptionAlgorithm(); 

		// Optional, ComplexPasswordRulesEnforced indicates the rules for constructing a complex password enforced by the Account.
		// Minimum Length a minimum length is enforced for passwords for the account.
		// Preclude User ID inclusion precluding the password from including the user ID is supported. 
		// Maximum Repeating Characters a limit will be enforced on the number of times a character can occur consecutively. 
		// Lower Case Alpha at least one lower case alpha character is required. 
		// Upper Case Alpha at least one upper case alpha character is required. 
		// Numeric Character at least one numeric character is required. 
		// Special Character at least one special character is required.
		const vector<unsigned short> ComplexPasswordRulesEnforced() const;

		// Optional, ComplexPasswordRulesEnforced indicates the rules for constructing a complex password enforced by the Account.
		// Minimum Length a minimum length is enforced for passwords for the account.
		// Preclude User ID inclusion precluding the password from including the user ID is supported. 
		// Maximum Repeating Characters a limit will be enforced on the number of times a character can occur consecutively. 
		// Lower Case Alpha at least one lower case alpha character is required. 
		// Upper Case Alpha at least one upper case alpha character is required. 
		// Numeric Character at least one numeric character is required. 
		// Special Character at least one special character is required.
		void ComplexPasswordRulesEnforced(const vector<unsigned short> &value); 

		// Is true if the field ComplexPasswordRulesEnforced exists in the current object, otherwise is false.
		bool ComplexPasswordRulesEnforcedExists() const;

		// Remove ComplexPasswordRulesEnforced field.
		void RemoveComplexPasswordRulesEnforced(); 

		// Optional, InactivityTimeout specifies the interval after which if an account has been inactive, it shall be Disabled. The value may be expressed in interval format, as an absolute date-time, or be NULL.
		// An absolute date-time shall indicate when the password will be disabled due to inactivity.
		// An interval value shall indicate the time remaining before the password is disabled due to inactivity.
		// A value of NULL shall indicate that the Account will not be disabled due to inactivity.
		const CimDateTime InactivityTimeout() const;

		// Optional, InactivityTimeout specifies the interval after which if an account has been inactive, it shall be Disabled. The value may be expressed in interval format, as an absolute date-time, or be NULL.
		// An absolute date-time shall indicate when the password will be disabled due to inactivity.
		// An interval value shall indicate the time remaining before the password is disabled due to inactivity.
		// A value of NULL shall indicate that the Account will not be disabled due to inactivity.
		void InactivityTimeout(const CimDateTime &value); 

		// Is true if the field InactivityTimeout exists in the current object, otherwise is false.
		bool InactivityTimeoutExists() const;

		// Remove InactivityTimeout field.
		void RemoveInactivityTimeout(); 

		// Optional, LastLogin shall be an absolute date-time that specifies the last successful authentication that occurred for this Account.A value of 99990101000000.000000+000 shall indicate the Account has never been used. A value of NULL shall indicate the last successful login is unknown.
		const CimDateTime LastLogin() const;

		// Optional, LastLogin shall be an absolute date-time that specifies the last successful authentication that occurred for this Account.A value of 99990101000000.000000+000 shall indicate the Account has never been used. A value of NULL shall indicate the last successful login is unknown.
		void LastLogin(const CimDateTime &value); 

		// Is true if the field LastLogin exists in the current object, otherwise is false.
		bool LastLoginExists() const;

		// Remove LastLogin field.
		void RemoveLastLogin(); 

		// Optional, MaximumSuccessiveLoginFailures indicates the number of successive failed login attempts that shall result in the Account being disabled. A value of zero shall indicate that the Account will not be disabled due to successive failed login attempts.
		const unsigned short MaximumSuccessiveLoginFailures() const;

		// Optional, MaximumSuccessiveLoginFailures indicates the number of successive failed login attempts that shall result in the Account being disabled. A value of zero shall indicate that the Account will not be disabled due to successive failed login attempts.
		void MaximumSuccessiveLoginFailures(const unsigned short value); 

		// Is true if the field MaximumSuccessiveLoginFailures exists in the current object, otherwise is false.
		bool MaximumSuccessiveLoginFailuresExists() const;

		// Remove MaximumSuccessiveLoginFailures field.
		void RemoveMaximumSuccessiveLoginFailures(); 

		// Optional, PasswordExpiration indicates the maximum password age enforced for the Account. The value may be expressed as an absolute date-time as an interval, or may be NULL.
		// An absolute date-time shall indicate the date and time when the password will expire.
		// An interval value shall indicate the time remaining until the password expires.
		// A value of NULL shall indicate the password never expires.
		const CimDateTime PasswordExpiration() const;

		// Optional, PasswordExpiration indicates the maximum password age enforced for the Account. The value may be expressed as an absolute date-time as an interval, or may be NULL.
		// An absolute date-time shall indicate the date and time when the password will expire.
		// An interval value shall indicate the time remaining until the password expires.
		// A value of NULL shall indicate the password never expires.
		void PasswordExpiration(const CimDateTime &value); 

		// Is true if the field PasswordExpiration exists in the current object, otherwise is false.
		bool PasswordExpirationExists() const;

		// Remove PasswordExpiration field.
		void RemovePasswordExpiration(); 

		// Optional, PasswordHistoryDepth indicates the number of previous passwords that shall be maintained for the Account. The Account shall preclude the selection of a password if it occurs in the password history. A value of zero shall indicate that a password history is not maintained.
		const unsigned short PasswordHistoryDepth() const;

		// Optional, PasswordHistoryDepth indicates the number of previous passwords that shall be maintained for the Account. The Account shall preclude the selection of a password if it occurs in the password history. A value of zero shall indicate that a password history is not maintained.
		void PasswordHistoryDepth(const unsigned short value); 

		// Is true if the field PasswordHistoryDepth exists in the current object, otherwise is false.
		bool PasswordHistoryDepthExists() const;

		// Remove PasswordHistoryDepth field.
		void RemovePasswordHistoryDepth(); 

		// Optional, UserPasswordEncoding specifies encoding used for the UserPassword property.
		// "kbd" denotes a string in hexadecimal format containing keyboard scan code input. An example of a UserPassword structured in this format would be "321539191E1F1F11181320", which is the representation of "my password" in US English keyboard scan codes.
		// "ascii" denotes clear text that complies with the ASCII character set. An example would be "my password".
		// "pin" denotes that only numeric input in ASCII text is allowed for the UserPassword. An example would be "1234".
		// "UTF-8" denotes that the UserPassword is a Unicode string that is encoded using UTF-8 character set.
		// "UTF-16" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set. The byte order mark (BOM) shall be the first character of the string.
		// "UTF-16LE" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set in little-endian byte order.
		// "UTF-16BE" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set in big-endian byte order.
		// "UCS-2" denotes that the UserPassword is a Unicode string that is encoded using UCS-2 character set.
		const unsigned int UserPasswordEncoding() const;

		// Optional, UserPasswordEncoding specifies encoding used for the UserPassword property.
		// "kbd" denotes a string in hexadecimal format containing keyboard scan code input. An example of a UserPassword structured in this format would be "321539191E1F1F11181320", which is the representation of "my password" in US English keyboard scan codes.
		// "ascii" denotes clear text that complies with the ASCII character set. An example would be "my password".
		// "pin" denotes that only numeric input in ASCII text is allowed for the UserPassword. An example would be "1234".
		// "UTF-8" denotes that the UserPassword is a Unicode string that is encoded using UTF-8 character set.
		// "UTF-16" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set. The byte order mark (BOM) shall be the first character of the string.
		// "UTF-16LE" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set in little-endian byte order.
		// "UTF-16BE" denotes that the UserPassword is a Unicode string that is encoded using UTF-16 character set in big-endian byte order.
		// "UCS-2" denotes that the UserPassword is a Unicode string that is encoded using UCS-2 character set.
		void UserPasswordEncoding(const unsigned int value); 

		// Is true if the field UserPasswordEncoding exists in the current object, otherwise is false.
		bool UserPasswordEncodingExists() const;

		// Remove UserPasswordEncoding field.
		void RemoveUserPasswordEncoding(); 

		//Input parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_INPUT(){}

			// Optional, The state requested for the element. This information will be placed into the RequestedState property of the instance if the return code of the RequestStateChange method is 0 ('Completed with No Error'), or 4096 (0x1000) ('Job Started'). Refer to the description of the EnabledState and RequestedState properties for the detailed explanations of the RequestedState values.
			// Legal values:
			// Enabled: 2
			// Disabled: 3
			// Shut Down: 4
			// Offline: 6
			// Test: 7
			// Defer: 8
			// Quiesce: 9
			// Reboot: 10
			// Reset: 11
			// DMTF Reserved: ..
			// Vendor Reserved: 32768..65535
			void RequestedState(const unsigned short value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' shall be returned.
			void TimeoutPeriod(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_OUTPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_OUTPUT(){}

			// class fields
			// May contain a reference to the ConcreteJob created to track the state transition initiated by the method invocation.
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// Requests that the state of the element be changed to the value specified in the RequestedState parameter. When the requested state change takes place, the EnabledState and RequestedState of the element will be the same. Invoking the RequestStateChange method multiple times could result in earlier requests being overwritten or lost. 
		// A return code of 0 shall indicate the state change was successfully initiated. 
		// A return code of 3 shall indicate that the state transition cannot complete within the interval specified by the TimeoutPeriod parameter. 
		// A return code of 4096 (0x1000) shall indicate the state change was successfully initiated, a ConcreteJob has been created, and its reference returned in the output parameter Job. Any other return code indicates an error condition.
		virtual unsigned int RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Account> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Account(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Account(const CimObject &object)
			: CIM_EnabledLogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 23);
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
#endif // CIM_ACCOUNT_H
