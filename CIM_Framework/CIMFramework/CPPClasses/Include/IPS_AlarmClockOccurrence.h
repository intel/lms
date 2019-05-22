//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_AlarmClockOccurrence.h
//
//  Contents:   IPS_AlarmClockOccurrence represents a single alarm clock setting. An instance of this class is created by calling AMT_AlarmClockService.AddAlarm method.
//
//              This file was automatically generated from IPS_AlarmClockOccurrence.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_ALARMCLOCKOCCURRENCE_H
#define IPS_ALARMCLOCKOCCURRENCE_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// IPS_AlarmClockOccurrence represents a single alarm clock setting. An instance of this class is created by calling AMT_AlarmClockService.AddAlarm method. 
	class CIMFRAMEWORK_API IPS_AlarmClockOccurrence  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		IPS_AlarmClockOccurrence()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		IPS_AlarmClockOccurrence(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~IPS_AlarmClockOccurrence(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_AlarmClockOccurrence keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, The instance key, set by the caller of AMT_AlarmClockService.AddAlarm.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, The instance key, set by the caller of AMT_AlarmClockService.AddAlarm.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Key, Required, The instance key, set by the caller of AMT_AlarmClockService.AddAlarm.
		const string InstanceID() const;

		// Key, Required, The instance key, set by the caller of AMT_AlarmClockService.AddAlarm.
		void InstanceID(const string &value); 


		// Optional, The next time when the alarm is scheduled to be set.
		const CimDateTime StartTime() const;

		// Optional, The next time when the alarm is scheduled to be set.
		void StartTime(const CimDateTime &value); 

		// Is true if the field StartTime exists in the current object, otherwise is false.
		bool StartTimeExists() const;

		// Remove StartTime field.
		void RemoveStartTime(); 

		// Optional, The interval between occurrences of the alarm (0 if the alarm is scheduled to run once).
		const CimDateTime Interval() const;

		// Optional, The interval between occurrences of the alarm (0 if the alarm is scheduled to run once).
		void Interval(const CimDateTime &value); 

		// Is true if the field Interval exists in the current object, otherwise is false.
		bool IntervalExists() const;

		// Remove Interval field.
		void RemoveInterval(); 

		// Optional, if set to TRUE, the instance will be deleted by the FW when the alarm is completed. Otherwise, the SW can delete the instance using the Delete() method.
		const bool DeleteOnCompletion() const;

		// Optional, if set to TRUE, the instance will be deleted by the FW when the alarm is completed. Otherwise, the SW can delete the instance using the Delete() method.
		void DeleteOnCompletion(const bool value); 

		// Is true if the field DeleteOnCompletion exists in the current object, otherwise is false.
		bool DeleteOnCompletionExists() const;

		// Remove DeleteOnCompletion field.
		void RemoveDeleteOnCompletion(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_AlarmClockOccurrence> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_AlarmClockOccurrence(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_AlarmClockOccurrence(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // IPS_ALARMCLOCKOCCURRENCE_H
