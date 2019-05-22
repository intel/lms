//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Log.h
//
//  Contents:   Log represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Log does not dictate the form of the data represented or how records/messages are stored in the log and/or accessed. Subclasses will define the appropriate methods and behavior.
//
//              This file was automatically generated from CIM_Log.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOG_H
#define CIM_LOG_H 1
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Log represents any type of event, error or informational register or chronicle. The object describes the existence of the log and its characteristics. Log does not dictate the form of the data represented or how records/messages are stored in the log and/or accessed. Subclasses will define the appropriate methods and behavior.
	class CIMFRAMEWORK_API CIM_Log  : public CIM_EnabledLogicalElement
	{
	public:

		//Default constructor
		CIM_Log()
			: CIM_EnabledLogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_Log(ICimWsmanClient *client)
			: CIM_EnabledLogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_Log(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Log keys
		class CimKeys : public CIM_EnabledLogicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Maximum number of records that can be captured in the Log. If undefined, a value of zero should be specified.
		const Uint64 MaxNumberOfRecords() const;

		// Optional, Maximum number of records that can be captured in the Log. If undefined, a value of zero should be specified.
		void MaxNumberOfRecords(const Uint64 value); 

		// Is true if the field MaxNumberOfRecords exists in the current object, otherwise is false.
		bool MaxNumberOfRecordsExists() const;

		// Remove MaxNumberOfRecords field.
		void RemoveMaxNumberOfRecords(); 

		// Optional, Current number of records in the Log.
		const Uint64 CurrentNumberOfRecords() const;

		// Optional, Current number of records in the Log.
		void CurrentNumberOfRecords(const Uint64 value); 

		// Is true if the field CurrentNumberOfRecords exists in the current object, otherwise is false.
		bool CurrentNumberOfRecordsExists() const;

		// Remove CurrentNumberOfRecords field.
		void RemoveCurrentNumberOfRecords(); 

		// Optional, OverwritePolicy is an integer enumeration that indicates whether the log, represented by the CIM_Log subclasses, can overwrite its entries.Unknown (0) indicates the log's overwrite policy is unknown. 
		// Wraps when Full (2) indicates that the log overwrites its entries with new entries when the log has reached its maximum capacity. 
		// Never Overwrites (7) indicates that the log never overwrites its entries by the new entries.
		const unsigned short OverwritePolicy() const;

		// Optional, OverwritePolicy is an integer enumeration that indicates whether the log, represented by the CIM_Log subclasses, can overwrite its entries.Unknown (0) indicates the log's overwrite policy is unknown. 
		// Wraps when Full (2) indicates that the log overwrites its entries with new entries when the log has reached its maximum capacity. 
		// Never Overwrites (7) indicates that the log never overwrites its entries by the new entries.
		void OverwritePolicy(const unsigned short value); 

		// Is true if the field OverwritePolicy exists in the current object, otherwise is false.
		bool OverwritePolicyExists() const;

		// Remove OverwritePolicy field.
		void RemoveOverwritePolicy(); 

		// Optional, LogState is an integer enumeration that indicates the current state of a log represented by CIM_Log subclasses. LogState is to be used in conjunction with the EnabledState property to fully describe the current state of the log. The following text briefly summarizes the various log states: 
		// Unknown (0) indicates the state of the log is unknown. 
		// Normal (2) indicates that the log is or could be executing logging commands, will process any queued log entries, and will queue new logging requests. 
		// Erasing (3) indicates that the log is being erased. 
		// Not Applicable (4) indicates the log does not support representing a log state.
		const unsigned short LogState() const;

		// Optional, LogState is an integer enumeration that indicates the current state of a log represented by CIM_Log subclasses. LogState is to be used in conjunction with the EnabledState property to fully describe the current state of the log. The following text briefly summarizes the various log states: 
		// Unknown (0) indicates the state of the log is unknown. 
		// Normal (2) indicates that the log is or could be executing logging commands, will process any queued log entries, and will queue new logging requests. 
		// Erasing (3) indicates that the log is being erased. 
		// Not Applicable (4) indicates the log does not support representing a log state.
		void LogState(const unsigned short value); 

		// Is true if the field LogState exists in the current object, otherwise is false.
		bool LogStateExists() const;

		// Remove LogState field.
		void RemoveLogState(); 

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

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Log> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Log(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Log(const CimObject &object)
			: CIM_EnabledLogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // CIM_LOG_H
