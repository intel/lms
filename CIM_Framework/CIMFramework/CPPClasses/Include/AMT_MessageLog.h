//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_MessageLog.h
//
//  Contents:   Extends MessageLog with multiple record fetching
//
//              This file was automatically generated from AMT_MessageLog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_MESSAGELOG_H
#define AMT_MESSAGELOG_H 1
#include "CIM_MessageLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Extends MessageLog with multiple record fetching
	class CIMFRAMEWORK_API AMT_MessageLog  : public CIM_MessageLog
	{
	public:

		//Default constructor
		AMT_MessageLog()
			: CIM_MessageLog(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_MessageLog::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_MessageLog(ICimWsmanClient *client)
			: CIM_MessageLog(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_MessageLog::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_MessageLog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_MessageLog keys
		class CimKeys : public CIM_MessageLog::CimKeys
		{
		public:
		};
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

		// Requests that the Log be cleared of all entries. 
		// The return value should be 0 if the request was successfully executed, 1 if the request is not supported, and some other value, as indicated by the ValueMap/Values qualifiers, if an error occurred.
		virtual unsigned int ClearLog();

		//Input parameter for function GetRecords
		class CIMFRAMEWORK_API GetRecords_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRecords_INPUT() : CimParam() {}

			// Class Destructor
			~GetRecords_INPUT(){}

			// Required,
			void IterationIdentifier(const string &value); 

			// Required, Maximum number of records to read
			void MaxReadRecords(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetRecords
		class CIMFRAMEWORK_API GetRecords_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRecords_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetRecords_OUTPUT(){}

			// class fields
			// 
			const string IterationIdentifier() const;
			// Indicates that there are no more records to read
			const bool NoMoreRecords() const;
			bool NoMoreRecordsExists() const;
			// Array of records encoded as Base64
			const vector<string> RecordArray() const;
			bool RecordArrayExists() const;
		private:
		};

		// Retrieves multiple records from event log
		virtual unsigned int GetRecords(const GetRecords_INPUT &input, GetRecords_OUTPUT &output);

		//Input parameter for function GetRecord
		class CIMFRAMEWORK_API GetRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRecord_INPUT() : CimParam() {}

			// Class Destructor
			~GetRecord_INPUT(){}

			// Required, An identifier for the iterator.
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
			// The record number.
			const Uint64 RecordNumber() const;
			// The record data.
			const vector<unsigned char> RecordData() const;
			bool RecordDataExists() const;
		private:
		};

		// Requests that the record indicated by the IterationIdentifier be retrieved from the MessageLog. After retrieval, the IterationIdentifier may be advanced to the next record by setting the PositionToNext input parameter to TRUE. Two output parameters are defined for the method - RecordData which holds the contents of the Log entry (as an array of bytes that can be recast to an appropriate format), and RecordNumber which returns the current record number addressed via the Iteration Identifier. The RecordNumber parameter is only defined/valid when the Capabilities array indicates that ordinal record number addressing is supported (a value of 7). 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application.
		virtual unsigned int GetRecord(const GetRecord_INPUT &input, GetRecord_OUTPUT &output);

		//Input parameter for function PositionAtRecord
		class CIMFRAMEWORK_API PositionAtRecord_INPUT : public CimParam
		{
		public:
			// Class Constructor
			PositionAtRecord_INPUT() : CimParam() {}

			// Class Destructor
			~PositionAtRecord_INPUT(){}

			// Required, An identifier for the iterator.
			void IterationIdentifier(const string &value); 

			// Required, Advancing or retreating the IterationIdentifier is achieved by setting the MoveAbsolute boolean to FALSE, and specifying the number of entries to advance or retreat as positive or negative values in the RecordNumber parameter. Moving to a specific record number is accomplished by setting the MoveAbsolute parameter to TRUE, and placing the record number into the RecordNumber parameter.
			void MoveAbsolute(const bool value); 

			// Required, The relative or absolute record number.
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
			// The relative or absolute record number.
			const Int64 RecordNumber() const;
		private:
		};

		// Requests that the Log's iteration identifier be advanced or retreated a specific number of records, or set to the entry at a specified numeric location. These two different behaviors are accomplished using the input parameters of the method. Advancing or retreating is achieved by setting the MoveAbsolute boolean to FALSE, and then specifying the number of entries to advance or retreat as positive or negative values in the RecordNumber parameter. Moving to a specific record number is accomplished by setting the MoveAbsolute input parameter to TRUE, and then placing the record number into the RecordNumber parameter. This can only be done if the Capabilities array includes a value of 7, "Supports Addressing by Ordinal Record Number". 
		// 
		// After the method completes and if ordinal record numbers are supported (the Capabilities array includes a 7), the current record number is returned in the RecordNumber output parameter. Otherwise, the value of the parameter is undefined. 
		// 
		// IterationIdentifier is defined as an Input/Output method parameter to allow the Log to embed state information in the Identifier and potentially let the identifier be maintained by the using application. 
		// 
		// Note: In a subclass, the set of possible return codes could be described using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int PositionAtRecord(const PositionAtRecord_INPUT &input, PositionAtRecord_OUTPUT &output);

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
		virtual unsigned int PositionToFirstRecord(PositionToFirstRecord_OUTPUT &output);

		//Input parameter for function FreezeLog
		class CIMFRAMEWORK_API FreezeLog_INPUT : public CimParam
		{
		public:
			// Class Constructor
			FreezeLog_INPUT() : CimParam() {}

			// Class Destructor
			~FreezeLog_INPUT(){}

			// Required, If TRUE then freeze the log, if FALSE 'unfreeze' the log.
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

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_MessageLog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_MessageLog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_MessageLog(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_MessageLog::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_MessageLog(const CimObject &object)
			: CIM_MessageLog(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_MessageLog::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_MessageLog::SetMetaData(childMetaData);
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
#endif // AMT_MESSAGELOG_H
