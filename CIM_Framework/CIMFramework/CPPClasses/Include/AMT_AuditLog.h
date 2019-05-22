//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuditLog.h
//
//  Contents:   Represents an Audit Log
//
//              This file was automatically generated from AMT_AuditLog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AUDITLOG_H
#define AMT_AUDITLOG_H 1
#include "CIM_Log.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents an Audit Log
	class CIMFRAMEWORK_API AMT_AuditLog  : public CIM_Log
	{
	public:

		//Default constructor
		AMT_AuditLog()
			: CIM_Log(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		AMT_AuditLog(ICimWsmanClient *client)
			: CIM_Log(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~AMT_AuditLog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AuditLog keys
		class CimKeys : public CIM_Log::CimKeys
		{
		public:
			// Key, Required, 
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, 
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Required, Indicates the percentage of free space in the storage dedicated to the audit log.
		const unsigned int PercentageFree() const;

		// Required, Indicates the percentage of free space in the storage dedicated to the audit log.
		void PercentageFree(const unsigned int value); 

		// Is true if the field PercentageFree exists in the current object, otherwise is false.
		bool PercentageFreeExists() const;

		// Remove PercentageFree field.
		void RemovePercentageFree(); 

		// Optional, Time stamp of the most recent entry in the log if such an entry exists.
		const CimDateTime TimeOfLastRecord() const;

		// Optional, Time stamp of the most recent entry in the log if such an entry exists.
		void TimeOfLastRecord(const CimDateTime &value); 

		// Is true if the field TimeOfLastRecord exists in the current object, otherwise is false.
		bool TimeOfLastRecordExists() const;

		// Remove TimeOfLastRecord field.
		void RemoveTimeOfLastRecord(); 

		// Required, State of log. A bitwise combination of one or more of: 0x00 (Enabled), 0x01 (Disabled), 0x02 (Locked), 0x04 (Almost Full - The storage area dedicated for the audit log reached 85% full, and non-critical events will not be logged.), 0x08 (Full - The storage area dedicated for the audit log is completely full; no events will be logged and critical events in policy will not be executed.), 0x10 (No Key - No key and certificate were set for the signing of the audit log. Feature cannot be enabled).
		const unsigned int AuditState() const;

		// Required, State of log. A bitwise combination of one or more of: 0x00 (Enabled), 0x01 (Disabled), 0x02 (Locked), 0x04 (Almost Full - The storage area dedicated for the audit log reached 85% full, and non-critical events will not be logged.), 0x08 (Full - The storage area dedicated for the audit log is completely full; no events will be logged and critical events in policy will not be executed.), 0x10 (No Key - No key and certificate were set for the signing of the audit log. Feature cannot be enabled).
		void AuditState(const unsigned int value); 

		// Is true if the field AuditState exists in the current object, otherwise is false.
		bool AuditStateExists() const;

		// Remove AuditState field.
		void RemoveAuditState(); 

		// Required, Maximum number of auditors allowed
		const unsigned short MaxAllowedAuditors() const;

		// Required, Maximum number of auditors allowed
		void MaxAllowedAuditors(const unsigned short value); 

		// Is true if the field MaxAllowedAuditors exists in the current object, otherwise is false.
		bool MaxAllowedAuditorsExists() const;

		// Remove MaxAllowedAuditors field.
		void RemoveMaxAllowedAuditors(); 

		// Optional, AuditLog storage policy. The available policies are: "NO_ROLL_OVER" - No roll-over in storage. Old events will not be overwritten. "ROLL_OVER" - Full rollover. Any old record will be overwritten. "RESTRICTED_ROLL_OVER" - Parital (restricted) rollover. Only old events (under certain threshold, which can be set using SetStoragePolicy) will be overwritten. If not specified default is "ROLL_OVER" unless FW was upgraded from AMT 5.0 and then "NO_ROLL_OVER" will be used as default.
		const unsigned char StoragePolicy() const;

		// Optional, AuditLog storage policy. The available policies are: "NO_ROLL_OVER" - No roll-over in storage. Old events will not be overwritten. "ROLL_OVER" - Full rollover. Any old record will be overwritten. "RESTRICTED_ROLL_OVER" - Parital (restricted) rollover. Only old events (under certain threshold, which can be set using SetStoragePolicy) will be overwritten. If not specified default is "ROLL_OVER" unless FW was upgraded from AMT 5.0 and then "NO_ROLL_OVER" will be used as default.
		void StoragePolicy(const unsigned char &value); 

		// Is true if the field StoragePolicy exists in the current object, otherwise is false.
		bool StoragePolicyExists() const;

		// Remove StoragePolicy field.
		void RemoveStoragePolicy(); 

		// Optional, Minimum number of days to keep records in the AuditLog. Relevant only if "storagePolicy" is set to "RESTRICTED_ROLL_OVER".
		const unsigned char MinDaysToKeep() const;

		// Optional, Minimum number of days to keep records in the AuditLog. Relevant only if "storagePolicy" is set to "RESTRICTED_ROLL_OVER".
		void MinDaysToKeep(const unsigned char &value); 

		// Is true if the field MinDaysToKeep exists in the current object, otherwise is false.
		bool MinDaysToKeepExists() const;

		// Remove MinDaysToKeep field.
		void RemoveMinDaysToKeep(); 

		// Requests that the Log be cleared of all entries. 
		// The return value should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value, as indicated by the ValueMap/Values qualifiers, if an error occurred.
		virtual unsigned int ClearLog();

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

		//Input parameter for function ReadRecords
		class CIMFRAMEWORK_API ReadRecords_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ReadRecords_INPUT() : CimParam() {}

			// Class Destructor
			~ReadRecords_INPUT(){}

			// Required, Identifies the position of the first record to retrieve. An index of 1 indicates the first record in the log.
			void StartIndex(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function ReadRecords
		class CIMFRAMEWORK_API ReadRecords_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			ReadRecords_OUTPUT() : CimParam() {}

			// Class Destructor
			~ReadRecords_OUTPUT(){}

			// class fields
			// The total number of records in the log.
			const unsigned int TotalRecordCount() const;
			bool TotalRecordCountExists() const;
			// The number of records returned + content of 10 records from the start index.
			const unsigned int RecordsReturned() const;
			bool RecordsReturnedExists() const;
			// Notice: the values of this array are actually base64 encoded values. A list of event records.
			const vector<string> EventRecords() const;
			bool EventRecordsExists() const;
		private:
		};

		// Returns a list of consecutive audit log records in chronological order: The first record in the returned array is the oldest record stored in the log . The record entries are returned as an array of base64Binary elements. Each record holds the following information: uint16 AuditAppID -A unique ID for each auditable application. uint16 EventID -ID of an event of the application. uint8 InitiatorType -0 (HTTP Digest username), 1 (Kerberos SID), 2 (Local). See below InitiatorData -See below. uint32 TimeStamp -Time when the event occurred in seconds since 1.1.1970. uint8 MCLocationType -0 (IPv4 Address), 1 (IPv6 Address), 2 (None). uint8 NetAddressLength -Length of the NetAddress field. Array of uint8 NetAddress	 -ASCII representation of the network address of management console or Local Host IP (e.g. 127.0.0.1). Note: In Intel AMT Release 4.0 IP address representation includes null-terminator and NetAddressLength includes the null terminator. uint8 ExtendedDataLength -Length of event specific data. Array of uint8 ExtendedData -Event specific data. 
		// 
		// The InitiatorData field may hold different data types according to the InitiatorType field: HTTP digest initiator: In Intel AMT Release 4.0 data for username includes null terminator and UsernameLength includes the null terminator. uint8 UsernameLength Array of uint8 Username Kerberos SID initiator: uint32 UserInDomain uint8 DomainLength Array of uint8 Domain Local: Empty.
		virtual unsigned int ReadRecords(const ReadRecords_INPUT &input, ReadRecords_OUTPUT &output);

		//Input parameter for function SetAuditLock
		class CIMFRAMEWORK_API SetAuditLock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAuditLock_INPUT() : CimParam() {}

			// Class Destructor
			~SetAuditLock_INPUT(){}

			// Optional, The maximum number of seconds that the audit log will be locked in case for some reason the auditor fails to unlock the log. Max value is 5 minutes. This parameter is required when the flag parameter has a value of AUDIT_LOG_LOCK, or UNPROVISIONING_LOCK. This parameter is not required and is ignored when AUDIT_LOG_UNLOCK flag is used.
			void LockTimeoutInSeconds(const unsigned int value); 

			// Required, Defines the locking action.
			// Legal values:
			// AUDIT_LOG_LOCK: 0
			// UNPROVISIONING_LOCK: 1
			// AUDIT_LOG_UNLOCK: 2
			void Flag(const unsigned int value); 

			// Optional, A handle is received when locking the log. As long as the log is locked, lock and unlock requests can be performed only by using the same handle. If the log is not locked so Handle-IN is not required and is ignored. Handle-OUT is not supplied when SetAuditLock failed to lock the audit log or when unlock is preformed.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function SetAuditLock
		class CIMFRAMEWORK_API SetAuditLock_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAuditLock_OUTPUT() : CimParam() {}

			// Class Destructor
			~SetAuditLock_OUTPUT(){}

			// class fields
			// A handle is received when locking the log. As long as the log is locked, lock and unlock requests can be performed only by using the same handle. If the log is not locked so Handle-IN is not required and is ignored. Handle-OUT is not supplied when SetAuditLock failed to lock the audit log or when unlock is preformed.
			const unsigned int Handle() const;
			bool HandleExists() const;
		private:
		};

		// This method is used by an auditor to stop the system from logging any records while exporting and clearing the log. It performs lock, unlock or allows unprovisioning of the system. When the audit log is locked, no events are written into the log. Any events marked in the policy as critical will not be executed. If the log is locked and another lock is requested with the same handle, so the timeout will be renewed with the new LockTimeoutInSeconds.
		virtual unsigned int SetAuditLock(const SetAuditLock_INPUT &input, SetAuditLock_OUTPUT &output);

		//Input parameter for function ExportAuditLogSignature
		class CIMFRAMEWORK_API ExportAuditLogSignature_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ExportAuditLogSignature_INPUT() : CimParam() {}

			// Class Destructor
			~ExportAuditLogSignature_INPUT(){}

			// Required, Signing Mechanism
			// Legal values:
			// RSA_SHA1: 0
			// RSA_SHA256: 1
			// RSA_SHA384: 2
			// Reserved: 3..65535
			void SigningMechanism(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function ExportAuditLogSignature
		class CIMFRAMEWORK_API ExportAuditLogSignature_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			ExportAuditLogSignature_OUTPUT() : CimParam() {}

			// Class Destructor
			~ExportAuditLogSignature_OUTPUT(){}

			// class fields
			// The total number of event records in the event log.
			const unsigned int TotalRecordCount() const;
			bool TotalRecordCountExists() const;
			// Time stamp of the first record.
			const CimDateTime StartLogTime() const;
			bool StartLogTimeExists() const;
			// Time stamp of the last record.
			const CimDateTime EndLogTime() const;
			bool EndLogTimeExists() const;
			// Time stamp indicating when was the signature generated.
			const CimDateTime GenerationTime() const;
			bool GenerationTimeExists() const;
			// UUID of the current system for identifying it in the audit repository.
			const HexBinary UUID() const;
			bool UUIDExists() const;
			// FQDN of the system.
			const string FQDN() const;
			bool FQDNExists() const;
			// Signature mechanism.
			// Legal values:
			// RSA_SHA1: 0
			// RSA_SHA256: 1
			// RSA_SHA384: 2
			// Reserved: 3..65535
			const unsigned int SignatureMechanism() const;
			bool SignatureMechanismExists() const;
			// The audit log signature, 256 bytes long.
			const Base64 Signature() const;
			bool SignatureExists() const;
			// An array specifying the length of each certificate.
			const vector<unsigned short> LengthOfCertificates() const;
			bool LengthOfCertificatesExists() const;
			// The certificates, cascaded into one stream.
			const Base64 Certificates() const;
			bool CertificatesExists() const;
		private:
		};

		// Returns the audit log signature and log related information.
		virtual unsigned int ExportAuditLogSignature(const ExportAuditLogSignature_INPUT &input, ExportAuditLogSignature_OUTPUT &output);

		//Input parameter for function SetSigningKeyMaterial
		class CIMFRAMEWORK_API SetSigningKeyMaterial_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetSigningKeyMaterial_INPUT() : CimParam() {}

			// Class Destructor
			~SetSigningKeyMaterial_INPUT(){}

			// Required, Audit data signing mechanism type.
			// Legal values:
			// RSA_SHA1: 0
			// RSA_SHA256: 1
			// RSA_SHA384: 2
			// Reserved: 3..65535
			void SigningMechanismType(const unsigned int value); 

			// Required, Key pair (RSA 2048 bit modulus).
			void SigningKey(const Base64 &value); 

			// Required, An array specifying the length of each certificate.
			void LengthOfCertificates(const vector<unsigned short> &value); 

			// Required, Up to 5 certificates cascaded into one stream (with a total length of 4100 bytes).
			void Certificates(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sets the key and certificates needed for the signing of the audit log. This method must be called before enabling the audit log.
		virtual unsigned int SetSigningKeyMaterial(const SetSigningKeyMaterial_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AuditLog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AuditLog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Log(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AuditLog(const CimObject &object)
			: CIM_Log(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Log::SetMetaData(childMetaData);
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
#endif // AMT_AUDITLOG_H
