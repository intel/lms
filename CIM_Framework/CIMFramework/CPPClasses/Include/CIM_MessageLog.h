//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MessageLog.h
//
//  Contents:   MessageLog represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Several methods are defined for retrieving, writing and deleting log entries, and maintaining the log. This type of log uses iterators to access the log records, whereas its peer class, RecordLog, uses more abstracted access mechanisms.
//
//              This file was automatically generated from CIM_MessageLog.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MESSAGELOG_H
#define CIM_MESSAGELOG_H 1
#include "CIM_Log.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// MessageLog represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Several methods are defined for retrieving, writing and deleting log entries, and maintaining the log. This type of log uses iterators to access the log records, whereas its peer class, RecordLog, uses more abstracted access mechanisms.
	class CIMFRAMEWORK_API CIM_MessageLog  : public CIM_Log
	{
	public:

		//Default constructor
		CIM_MessageLog()
			: CIM_Log(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//constructor which receives WSMan client
		CIM_MessageLog(ICimWsmanClient *client)
			: CIM_Log(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//Destructor
		virtual ~CIM_MessageLog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_MessageLog keys
		class CimKeys : public CIM_Log::CimKeys
		{
		public:
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

			// Key, Required, The inherited Name serves as part of the key (a unique identifier) for the MessageLog instance.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The inherited Name serves as part of the key (a unique identifier) for the MessageLog instance.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Optional, An array of integers indicating the Log capabilities. Information such as "Write Record Supported" (value= 2) or "Variable Length Records Supported" (8) is specified in this property.
		const vector<unsigned short> Capabilities() const;

		// Optional, An array of integers indicating the Log capabilities. Information such as "Write Record Supported" (value= 2) or "Variable Length Records Supported" (8) is specified in this property.
		void Capabilities(const vector<unsigned short> &value); 

		// Is true if the field Capabilities exists in the current object, otherwise is false.
		bool CapabilitiesExists() const;

		// Remove Capabilities field.
		void RemoveCapabilities(); 

		// Optional, An array of free-form strings providing more detailed explanations for any of the Log features indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		const vector<string> CapabilitiesDescriptions() const;

		// Optional, An array of free-form strings providing more detailed explanations for any of the Log features indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		void CapabilitiesDescriptions(const vector<string> &value); 

		// Is true if the field CapabilitiesDescriptions exists in the current object, otherwise is false.
		bool CapabilitiesDescriptionsExists() const;

		// Remove CapabilitiesDescriptions field.
		void RemoveCapabilitiesDescriptions(); 

		// Optional, The maximum size, in bytes, to which the Log can grow. If there is no maximum, then MaxLogSize should be set to 0.
		const Uint64 MaxLogSize() const;

		// Optional, The maximum size, in bytes, to which the Log can grow. If there is no maximum, then MaxLogSize should be set to 0.
		void MaxLogSize(const Uint64 value); 

		// Is true if the field MaxLogSize exists in the current object, otherwise is false.
		bool MaxLogSizeExists() const;

		// Remove MaxLogSize field.
		void RemoveMaxLogSize(); 

		// Optional, The size of the Log header, in bytes, if one is present. If there is no Log header, then this property should be set to 0. Headers may include general information about the Log such as the current number of records, time of last update, or a pointer to the location of the first Log entry. Note that this property is NOT the size of the header for an individual Log entry. The latter is described by the property, SizeOfRecordHeader.
		const Uint64 SizeOfHeader() const;

		// Optional, The size of the Log header, in bytes, if one is present. If there is no Log header, then this property should be set to 0. Headers may include general information about the Log such as the current number of records, time of last update, or a pointer to the location of the first Log entry. Note that this property is NOT the size of the header for an individual Log entry. The latter is described by the property, SizeOfRecordHeader.
		void SizeOfHeader(const Uint64 value); 

		// Is true if the field SizeOfHeader exists in the current object, otherwise is false.
		bool SizeOfHeaderExists() const;

		// Remove SizeOfHeader field.
		void RemoveSizeOfHeader(); 

		// Optional, If the SizeOfHeader property is non-zero, this property describes the structure and format of the Log header. It is a free-form string. If the SizeOfHeader property is 0, then the information in this property is undefined.
		const string HeaderFormat() const;

		// Optional, If the SizeOfHeader property is non-zero, this property describes the structure and format of the Log header. It is a free-form string. If the SizeOfHeader property is 0, then the information in this property is undefined.
		void HeaderFormat(const string &value); 

		// Is true if the field HeaderFormat exists in the current object, otherwise is false.
		bool HeaderFormatExists() const;

		// Remove HeaderFormat field.
		void RemoveHeaderFormat(); 

		// Optional, Maximum size, in bytes, to which an individual Log entry (record) can grow - if the Capabilities array includes a value of 7 ("Variable Length Records Supported"). If the Capabilities array does not include a 7, then the Log only supports fixed length entries. The size of these entries is described by this property.
		const Uint64 MaxRecordSize() const;

		// Optional, Maximum size, in bytes, to which an individual Log entry (record) can grow - if the Capabilities array includes a value of 7 ("Variable Length Records Supported"). If the Capabilities array does not include a 7, then the Log only supports fixed length entries. The size of these entries is described by this property.
		void MaxRecordSize(const Uint64 value); 

		// Is true if the field MaxRecordSize exists in the current object, otherwise is false.
		bool MaxRecordSizeExists() const;

		// Remove MaxRecordSize field.
		void RemoveMaxRecordSize(); 

		// Optional, The size of the header for the Log's individual entries, in bytes, if record headers are defined. If there are no record headers, then this property should be set to 0. Record headers may include information such as the type of the Log entry, the date/time that the entry was last updated, or a pointer to the start of optional data. Note that this property defines the header size for individual records in the Log, while the SizeOfHeader property describes the Log's overall header, typically located at the start of the MessageLog.
		const Uint64 SizeOfRecordHeader() const;

		// Optional, The size of the header for the Log's individual entries, in bytes, if record headers are defined. If there are no record headers, then this property should be set to 0. Record headers may include information such as the type of the Log entry, the date/time that the entry was last updated, or a pointer to the start of optional data. Note that this property defines the header size for individual records in the Log, while the SizeOfHeader property describes the Log's overall header, typically located at the start of the MessageLog.
		void SizeOfRecordHeader(const Uint64 value); 

		// Is true if the field SizeOfRecordHeader exists in the current object, otherwise is false.
		bool SizeOfRecordHeaderExists() const;

		// Remove SizeOfRecordHeader field.
		void RemoveSizeOfRecordHeader(); 

		// Optional, If the SizeOfRecordHeader property is non-zero, this property describes the structure and format of the record headers. It is a free-form string. If the SizeOfRecordHeader property is 0, then the information in this property is undefined.
		const string RecordHeaderFormat() const;

		// Optional, If the SizeOfRecordHeader property is non-zero, this property describes the structure and format of the record headers. It is a free-form string. If the SizeOfRecordHeader property is 0, then the information in this property is undefined.
		void RecordHeaderFormat(const string &value); 

		// Is true if the field RecordHeaderFormat exists in the current object, otherwise is false.
		bool RecordHeaderFormatExists() const;

		// Remove RecordHeaderFormat field.
		void RemoveRecordHeaderFormat(); 

		// Optional, When the OverwritePolicy specifies a value of 1 ("Other"), the Log's behavior can be explained using this property. If OverwritePolicy is not 1, then this property's contents are undefined.
		const string OtherPolicyDescription() const;

		// Optional, When the OverwritePolicy specifies a value of 1 ("Other"), the Log's behavior can be explained using this property. If OverwritePolicy is not 1, then this property's contents are undefined.
		void OtherPolicyDescription(const string &value); 

		// Is true if the field OtherPolicyDescription exists in the current object, otherwise is false.
		bool OtherPolicyDescriptionExists() const;

		// Remove OtherPolicyDescription field.
		void RemoveOtherPolicyDescription(); 

		// Optional, If the OverwritePolicy is based on 'outdated' records (values 4 or 5), this property defines when a Log entry is considered to be outdated - either by time interval or at a specific date and time.
		const CimDateTime TimeWhenOutdated() const;

		// Optional, If the OverwritePolicy is based on 'outdated' records (values 4 or 5), this property defines when a Log entry is considered to be outdated - either by time interval or at a specific date and time.
		void TimeWhenOutdated(const CimDateTime &value); 

		// Is true if the field TimeWhenOutdated exists in the current object, otherwise is false.
		bool TimeWhenOutdatedExists() const;

		// Remove TimeWhenOutdated field.
		void RemoveTimeWhenOutdated(); 

		// Optional, If the OverwritePolicy is based on clearing records when the Log is near full (value=3), this property defines the record capacity (in percentage) that is considered to be 'near full'.
		const unsigned char PercentageNearFull() const;

		// Optional, If the OverwritePolicy is based on clearing records when the Log is near full (value=3), this property defines the record capacity (in percentage) that is considered to be 'near full'.
		void PercentageNearFull(const unsigned char &value); 

		// Is true if the field PercentageNearFull exists in the current object, otherwise is false.
		bool PercentageNearFullExists() const;

		// Remove PercentageNearFull field.
		void RemovePercentageNearFull(); 

		// Optional, An enumeration describing the last change to the MessageLog.
		const unsigned short LastChange() const;

		// Optional, An enumeration describing the last change to the MessageLog.
		void LastChange(const unsigned short value); 

		// Is true if the field LastChange exists in the current object, otherwise is false.
		bool LastChangeExists() const;

		// Remove LastChange field.
		void RemoveLastChange(); 

		// Optional, When a change is made to the Log, the date/time of that modification is captured. This property could be used to event against any update to the MessageLog.
		const CimDateTime TimeOfLastChange() const;

		// Optional, When a change is made to the Log, the date/time of that modification is captured. This property could be used to event against any update to the MessageLog.
		void TimeOfLastChange(const CimDateTime &value); 

		// Is true if the field TimeOfLastChange exists in the current object, otherwise is false.
		bool TimeOfLastChangeExists() const;

		// Remove TimeOfLastChange field.
		void RemoveTimeOfLastChange(); 

		// Optional, When a change is made to the Log, the record number that was modified is captured.
		const Uint64 RecordLastChanged() const;

		// Optional, When a change is made to the Log, the record number that was modified is captured.
		void RecordLastChanged(const Uint64 value); 

		// Is true if the field RecordLastChanged exists in the current object, otherwise is false.
		bool RecordLastChangedExists() const;

		// Remove RecordLastChanged field.
		void RemoveRecordLastChanged(); 

		// Optional, Boolean indicating that the Log is currently frozen and modifications are not allowed.
		const bool IsFrozen() const;

		// Optional, Boolean indicating that the Log is currently frozen and modifications are not allowed.
		void IsFrozen(const bool value); 

		// Is true if the field IsFrozen exists in the current object, otherwise is false.
		bool IsFrozenExists() const;

		// Remove IsFrozen field.
		void RemoveIsFrozen(); 

		// Optional, An enumeration describing the character set used to record data in the individual Log entries. For example, the Log records may contain ASCII data (value=2), or be raw octet strings (value=10).
		const unsigned short CharacterSet() const;

		// Optional, An enumeration describing the character set used to record data in the individual Log entries. For example, the Log records may contain ASCII data (value=2), or be raw octet strings (value=10).
		void CharacterSet(const unsigned short value); 

		// Is true if the field CharacterSet exists in the current object, otherwise is false.
		bool CharacterSetExists() const;

		// Remove CharacterSet field.
		void RemoveCharacterSet(); 

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

		//Output parameter for function PositionToFirstRecord
		class CIMFRAMEWORK_API PositionToFirstRecord_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			PositionToFirstRecord_OUTPUT() : CimParam() {}

			// Class Destructor
			~PositionToFirstRecord_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
		private:
		};

		// Requests that an iteration of the MessageLog be established and that the iterator be set to the first entry in the Log. An identifier for the iterator is returned as an output parameter of the method. 
		// 
		// Regarding iteration, you have 2 choices: 1) Embed iteration data in the method call, and allow implementations to track/ store this data manually; or, 2) Iterate using a separate object (for example, class ActiveIterator) as an iteration agent. The first approach is used here for interoperability. The second requires an instance of the Iterator object for EACH iteration in progress. 2's functionality could be implemented underneath 1. 
		// 
		// The return value from PositionToFirstRecord should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int PositionToFirstRecord(PositionToFirstRecord_OUTPUT &output);

		//Input parameter for function PositionAtRecord
		class CIMFRAMEWORK_API PositionAtRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			PositionAtRecord_INPUT() : CimParam() {}

			// Class Destructor
			~PositionAtRecord_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Optional, Advancing or retreating the IterationIdentifier is achieved by setting the MoveAbsolute boolean to FALSE, and specifying the number of entries to advance or retreat as positive or negative values in the RecordNumber parameter. Moving to a specific record number is accomplished by setting the MoveAbsolute parameter to TRUE, and placing the record number into the RecordNumber parameter.
			void MoveAbsolute(const bool value); 

			// Optional, The relative or absolute record number.
			void RecordNumber(const Int64 value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function PositionAtRecord
		class CIMFRAMEWORK_API PositionAtRecord_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			PositionAtRecord_OUTPUT() : CimParam() {}

			// Class Destructor
			~PositionAtRecord_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
			// The relative or absolute record number.
			const Int64 RecordNumber() const;
			bool RecordNumberExists() const;
		private:
		};

		// Requests that the Log's iteration identifier be advanced or retreated a specific number of records, or set to the entry at a specified numeric location. These two different behaviors are accomplished using the input parameters of the method. Advancing or retreating is achieved by setting the MoveAbsolute boolean to FALSE, and then specifying the number of entries to advance or retreat as positive or negative values in the RecordNumber parameter. Moving to a specific record number is accomplished by setting the MoveAbsolute input parameter to TRUE, and then placing the record number into the RecordNumber parameter. This can only be done if the Capabilities array includes a value of 7, "Supports Addressing by Ordinal Record Number". 
		// 
		// After the method completes and if ordinal record numbers are supported (the Capabilities array includes a 7), the current record number is returned in the RecordNumber output parameter. Otherwise, the value of the parameter is undefined. 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// The return value from PositionAtRecord should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. If the request is not supported, check the Capabilities array regarding support for ordinal record number addressing and backward movement in the Log (values 7 and 4, respectively). 
		// 
		// Note: In a subclass, the set of possible return codes could be described using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int PositionAtRecord(const PositionAtRecord_INPUT &input, PositionAtRecord_OUTPUT &output);

		//Input parameter for function GetRecord
		class CIMFRAMEWORK_API GetRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRecord_INPUT() : CimParam() {}

			// Class Destructor
			~GetRecord_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Optional, Boolean indicating that the Iteration Identifier should be advanced to the next record, after retrieving the current Log entry.
			void PositionToNext(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetRecord
		class CIMFRAMEWORK_API GetRecord_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRecord_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetRecord_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
			// The record number.
			const Uint64 RecordNumber() const;
			bool RecordNumberExists() const;
			// The record data.
			const vector<unsigned char> RecordData() const;
			bool RecordDataExists() const;
		private:
		};

		// Requests that the record indicated by the IterationIdentifier be retrieved from the MessageLog. After retrieval, the IterationIdentifier may be advanced to the next record by setting the PositionToNext input parameter to TRUE. Two output parameters are defined for the method - RecordData which holds the contents of the Log entry (as an array of bytes that can be recast to an appropriate format), and RecordNumber which returns the current record number addressed via the Iteration Identifier. The RecordNumber parameter is only defined/valid when the Capabilities array indicates that ordinal record number addressing is supported (a value of 7). 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// The return value from GetRecord should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int GetRecord(const GetRecord_INPUT &input, GetRecord_OUTPUT &output);

		//Input parameter for function DeleteRecord
		class CIMFRAMEWORK_API DeleteRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			DeleteRecord_INPUT() : CimParam() {}

			// Class Destructor
			~DeleteRecord_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Optional, Boolean that when set to TRUE requests the IterationIdentifier to be advanced to the next record, after the current entry is deleted. If set to FALSE, IterationIdentifier is set to the previous record.
			void PositionToNext(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function DeleteRecord
		class CIMFRAMEWORK_API DeleteRecord_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			DeleteRecord_OUTPUT() : CimParam() {}

			// Class Destructor
			~DeleteRecord_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
			// The record number.
			const Uint64 RecordNumber() const;
			bool RecordNumberExists() const;
			// The record data.
			const vector<unsigned char> RecordData() const;
			bool RecordDataExists() const;
		private:
		};

		// Requests that the record indicated by the IterationIdentifier be deleted from the MessageLog. After deletion, the Iteration Identifier may be advanced to the next record by setting the PositionToNext input parameter to TRUE. If set to FALSE, then the IterationIdentifier will be positioned at the previous record. Two output parameters are defined for the method - RecordData which holds the contents of the deleted Log entry (as an array of bytes that can be recast to an appropriate format or discarded), and RecordNumber which returns the current record number addressed via the IterationIdentifier. The RecordNumber parameter is only defined/valid when the Capabilities array indicates that ordinal record number addressing is supported (a value of 7). 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// The return value from DeleteRecord should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value if an error occurred. If the request is not supported, check the Capabilities array that a value of 3 ("Delete Record Supported") is specified. 
		// 
		// Note: In a subclass, the set of possible return codes could be described using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int DeleteRecord(const DeleteRecord_INPUT &input, DeleteRecord_OUTPUT &output);

		//Input parameter for function WriteRecord
		class CIMFRAMEWORK_API WriteRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			WriteRecord_INPUT() : CimParam() {}

			// Class Destructor
			~WriteRecord_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Optional, Boolean indicating that the Iteration Identifier should be advanced to the next record, after writing the Log entry.
			void PositionToNext(const bool value); 

			// Required, The record data.
			void RecordData(const vector<unsigned char> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function WriteRecord
		class CIMFRAMEWORK_API WriteRecord_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			WriteRecord_OUTPUT() : CimParam() {}

			// Class Destructor
			~WriteRecord_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
			// The record number.
			const Uint64 RecordNumber() const;
			bool RecordNumberExists() const;
		private:
		};

		// Requests that a record be inserted at the Log position indicated by the IterationIdentifier. The entry's data is provided in the RecordData input parameter. After insertion, the IterationIdentifier may be advanced to the next record by setting the PositionToNext input parameter to TRUE. The output parameter, RecordNumber, returns the current record number addressed via the IterationIdentifier. This parameter is only defined/valid when the Capabilities array indicates that ordinal record number addressing is supported (a value of 7). 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// The return value from WriteRecord should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value if an error occurred. If the request is not supported, check the Capabilities array that a value of 2 ("Write Record Supported") is specified. 
		// 
		// Note: In a subclass, the set of possible return codes could be described using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int WriteRecord(const WriteRecord_INPUT &input, WriteRecord_OUTPUT &output);

		//Input parameter for function CancelIteration
		class CIMFRAMEWORK_API CancelIteration_INPUT : public CimParam
		{
		public:
			// Class Constructor
			CancelIteration_INPUT() : CimParam() {}

			// Class Destructor
			~CancelIteration_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Requests that an iteration of the Log, identified by the IterationIdentifier input parameter, be stopped. The return value from CancelIteration should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int CancelIteration(const CancelIteration_INPUT &input);

		//Input parameter for function FreezeLog
		class CIMFRAMEWORK_API FreezeLog_INPUT : public CimParam
		{
		public:
			// Class Constructor
			FreezeLog_INPUT() : CimParam() {}

			// Class Destructor
			~FreezeLog_INPUT(){}

			// Optional, If TRUE then freeze the log, if FALSE 'unfreeze' the log.
			void Freeze(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Requests that the MessageLog be placed in a frozen state ("Freeze" input parameter = TRUE) or 'unfrozen' (= FALSE). If frozen, modifications to the Log will not be allowed. If successful, the Log's IsFrozen boolean property will be updated to reflect the desired state. 
		// 
		// The method's return code should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. If the request is not supported, check the Capabilities array that a value of 5 ("Freeze Log Supported") is specified. 
		// 
		// Note: In a subclass, the set of possible return codes could be described using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int FreezeLog(const FreezeLog_INPUT &input);

		//Input parameter for function FlagRecordForOverwrite
		class CIMFRAMEWORK_API FlagRecordForOverwrite_INPUT : public CimParam
		{
		public:
			// Class Constructor
			FlagRecordForOverwrite_INPUT() : CimParam() {}

			// Class Destructor
			~FlagRecordForOverwrite_INPUT(){}

			// Optional, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Optional, Boolean indicating that the Iteration Identifier should be advanced to the next record, after updating the current Log entry.
			void PositionToNext(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function FlagRecordForOverwrite
		class CIMFRAMEWORK_API FlagRecordForOverwrite_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			FlagRecordForOverwrite_OUTPUT() : CimParam() {}

			// Class Destructor
			~FlagRecordForOverwrite_OUTPUT(){}

			// class fields
			// An identifier for the iterator.
			const string IterationIdentifier() const;
			bool IterationIdentifierExists() const;
			// The record number.
			const Uint64 RecordNumber() const;
			bool RecordNumberExists() const;
		private:
		};

		// Requests that the record indicated by the IterationIdentifier be flagged as overwriteable. This method is only supported when the Capabilities array includes a value of 10, "Can Flag Records for Overwrite". After updating the entry, the IterationIdentifier may be advanced to the next record by setting the PositionToNext input parameter to TRUE. One output parameter is defined for the method RecordNumber. It returns the current record number addressed via the Iteration Identifier. This parameter is only defined/valid when the Capabilities array indicates that ordinal record number addressing is supported (a value of 7). 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// The return value from FlagRecordForOverwrite should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int FlagRecordForOverwrite(const FlagRecordForOverwrite_INPUT &input, FlagRecordForOverwrite_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_MessageLog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_MessageLog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Log(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_MessageLog(const CimObject &object)
			: CIM_Log(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Log::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Log::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 19);
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
#endif // CIM_MESSAGELOG_H
