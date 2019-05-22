//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogEntry.h
//
//  Contents:   The LogEntry object can describe the definitional format for entries in a Log, or can be used to instantiate the actual entries in the Log.
//
//              This file was automatically generated from CIM_LogEntry.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOGENTRY_H
#define CIM_LOGENTRY_H 1
#include "CIM_RecordForLog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The LogEntry object can describe the definitional format for entries in a Log, or can be used to instantiate the actual entries in the Log.
	class CIMFRAMEWORK_API CIM_LogEntry  : public CIM_RecordForLog
	{
	public:

		//Default constructor
		CIM_LogEntry()
			: CIM_RecordForLog(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RecordForLog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		CIM_LogEntry(ICimWsmanClient *client)
			: CIM_RecordForLog(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RecordForLog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~CIM_LogEntry(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_LogEntry keys
		class CimKeys : public CIM_RecordForLog::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, The containing Log's InstanceID.
		const string LogInstanceID() const;

		// Optional, The containing Log's InstanceID.
		void LogInstanceID(const string &value); 

		// Is true if the field LogInstanceID exists in the current object, otherwise is false.
		bool LogInstanceIDExists() const;

		// Remove LogInstanceID field.
		void RemoveLogInstanceID(); 

		// Optional, The containing Log's Name. This property is available for backwards continuity with CIM_LogRecord.
		const string LogName() const;

		// Optional, The containing Log's Name. This property is available for backwards continuity with CIM_LogRecord.
		void LogName(const string &value); 

		// Is true if the field LogName exists in the current object, otherwise is false.
		bool LogNameExists() const;

		// Remove LogName field.
		void RemoveLogName(); 

		// Optional, RecordID may be used to provide a representation of log entry ordering or pointers/handles for log entries.
		const string RecordID() const;

		// Optional, RecordID may be used to provide a representation of log entry ordering or pointers/handles for log entries.
		void RecordID(const string &value); 

		// Is true if the field RecordID exists in the current object, otherwise is false.
		bool RecordIDExists() const;

		// Remove RecordID field.
		void RemoveRecordID(); 

		// Optional, A LogEntry may include a timestamp for the entry.
		const CimDateTime CreationTimeStamp() const;

		// Optional, A LogEntry may include a timestamp for the entry.
		void CreationTimeStamp(const CimDateTime &value); 

		// Is true if the field CreationTimeStamp exists in the current object, otherwise is false.
		bool CreationTimeStampExists() const;

		// Remove CreationTimeStamp field.
		void RemoveCreationTimeStamp(); 

		// Optional, A string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		const string MessageID() const;

		// Optional, A string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		void MessageID(const string &value); 

		// Is true if the field MessageID exists in the current object, otherwise is false.
		bool MessageIDExists() const;

		// Remove MessageID field.
		void RemoveMessageID(); 

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		const string Message() const;

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		void Message(const string &value); 

		// Is true if the field Message exists in the current object, otherwise is false.
		bool MessageExists() const;

		// Remove Message field.
		void RemoveMessage(); 

		// Optional, An array containing the dynamic content of the message.
		// Each DYNAMIC_ELEMENT for the message referred to by the MessageID property shall be contained in MessageArguments whether the DYNAMIC_ELEMENT is included in the Message or not.
		// In addition, the entries in MessageArguments need to be in the same order as the DYNAMIC_ELEMENTs.
		const vector<string> MessageArguments() const;

		// Optional, An array containing the dynamic content of the message.
		// Each DYNAMIC_ELEMENT for the message referred to by the MessageID property shall be contained in MessageArguments whether the DYNAMIC_ELEMENT is included in the Message or not.
		// In addition, the entries in MessageArguments need to be in the same order as the DYNAMIC_ELEMENTs.
		void MessageArguments(const vector<string> &value); 

		// Is true if the field MessageArguments exists in the current object, otherwise is false.
		bool MessageArgumentsExists() const;

		// Remove MessageArguments field.
		void RemoveMessageArguments(); 

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		const string OwningEntity() const;

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		void OwningEntity(const string &value); 

		// Is true if the field OwningEntity exists in the current object, otherwise is false.
		bool OwningEntityExists() const;

		// Remove OwningEntity field.
		void RemoveOwningEntity(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_LogEntry> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_LogEntry(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_RecordForLog(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RecordForLog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_LogEntry(const CimObject &object)
			: CIM_RecordForLog(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_RecordForLog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_RecordForLog::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 9);
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
#endif // CIM_LOGENTRY_H
