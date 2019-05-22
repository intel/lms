//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ConcreteJob.h
//
//  Contents:   A concrete version of Job. This class represents a generic and instantiable unit of work, such as a batch or a print job.
//
//              This file was automatically generated from CIM_ConcreteJob.mof,  version: 2.31.1
//
//----------------------------------------------------------------------------
#ifndef CIM_CONCRETEJOB_H
#define CIM_CONCRETEJOB_H 1
#include "CIM_Job.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A concrete version of Job. This class represents a generic and instantiable unit of work, such as a batch or a print job.
	class CIMFRAMEWORK_API CIM_ConcreteJob  : public CIM_Job
	{
	public:

		//Default constructor
		CIM_ConcreteJob()
			: CIM_Job(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Job::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_ConcreteJob(ICimWsmanClient *client)
			: CIM_Job(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Job::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_ConcreteJob(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ConcreteJob keys
		class CimKeys : public CIM_Job::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> must include a copyrighted, trademarked or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID, or that is a registered ID that is assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> must not contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity must assure that the resulting InstanceID is not re-used across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
			// For DMTF defined instances, the 'preferred' algorithm must be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> must include a copyrighted, trademarked or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID, or that is a registered ID that is assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> must not contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity must assure that the resulting InstanceID is not re-used across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
			// For DMTF defined instances, the 'preferred' algorithm must be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, JobState is an integer enumeration that indicates the operational state of a Job. It can also indicate transitions between these states, for example, 'Shutting Down' and 'Starting'. Following is a brief description of the states: 
		// New (2) indicates that the job has never been started. 
		// Starting (3) indicates that the job is moving from the 'New', 'Suspended', or 'Service' states into the 'Running' state. 
		// Running (4) indicates that the Job is running. 
		// Suspended (5) indicates that the Job is stopped, but can be restarted in a seamless manner. 
		// Shutting Down (6) indicates that the job is moving to a 'Completed', 'Terminated', or 'Killed' state. 
		// Completed (7) indicates that the job has completed normally. 
		// Terminated (8) indicates that the job has been stopped by a 'Terminate' state change request. The job and all its underlying processes are ended and can be restarted (this is job-specific) only as a new job. 
		// Killed (9) indicates that the job has been stopped by a 'Kill' state change request. Underlying processes might have been left running, and cleanup might be required to free up resources. 
		// Exception (10) indicates that the Job is in an abnormal state that might be indicative of an error condition. Actual status might be displayed though job-specific objects. 
		// Service (11) indicates that the Job is in a vendor-specific state that supports problem discovery, or resolution, or both.
		// Query pending (12) waiting for a client to resolve a query
		const unsigned short JobState() const;

		// Optional, JobState is an integer enumeration that indicates the operational state of a Job. It can also indicate transitions between these states, for example, 'Shutting Down' and 'Starting'. Following is a brief description of the states: 
		// New (2) indicates that the job has never been started. 
		// Starting (3) indicates that the job is moving from the 'New', 'Suspended', or 'Service' states into the 'Running' state. 
		// Running (4) indicates that the Job is running. 
		// Suspended (5) indicates that the Job is stopped, but can be restarted in a seamless manner. 
		// Shutting Down (6) indicates that the job is moving to a 'Completed', 'Terminated', or 'Killed' state. 
		// Completed (7) indicates that the job has completed normally. 
		// Terminated (8) indicates that the job has been stopped by a 'Terminate' state change request. The job and all its underlying processes are ended and can be restarted (this is job-specific) only as a new job. 
		// Killed (9) indicates that the job has been stopped by a 'Kill' state change request. Underlying processes might have been left running, and cleanup might be required to free up resources. 
		// Exception (10) indicates that the Job is in an abnormal state that might be indicative of an error condition. Actual status might be displayed though job-specific objects. 
		// Service (11) indicates that the Job is in a vendor-specific state that supports problem discovery, or resolution, or both.
		// Query pending (12) waiting for a client to resolve a query
		void JobState(const unsigned short value); 

		// Is true if the field JobState exists in the current object, otherwise is false.
		bool JobStateExists() const;

		// Remove JobState field.
		void RemoveJobState(); 

		// Optional, The date or time when the state of the Job last changed. If the state of the Job has not changed and this property is populated, then it must be set to a 0 interval value. If a state change was requested, but rejected or not yet processed, the property must not be updated.
		const CimDateTime TimeOfLastStateChange() const;

		// Optional, The date or time when the state of the Job last changed. If the state of the Job has not changed and this property is populated, then it must be set to a 0 interval value. If a state change was requested, but rejected or not yet processed, the property must not be updated.
		void TimeOfLastStateChange(const CimDateTime &value); 

		// Is true if the field TimeOfLastStateChange exists in the current object, otherwise is false.
		bool TimeOfLastStateChangeExists() const;

		// Remove TimeOfLastStateChange field.
		void RemoveTimeOfLastStateChange(); 

		// Required, The amount of time that the Job is retained after it has finished executing, either succeeding or failing in that execution. The job must remain in existence for some period of time regardless of the value of the DeleteOnCompletion property. 
		// The default is five minutes.
		const CimDateTime TimeBeforeRemoval() const;

		// Required, The amount of time that the Job is retained after it has finished executing, either succeeding or failing in that execution. The job must remain in existence for some period of time regardless of the value of the DeleteOnCompletion property. 
		// The default is five minutes.
		void TimeBeforeRemoval(const CimDateTime &value); 

		// Is true if the field TimeBeforeRemoval exists in the current object, otherwise is false.
		bool TimeBeforeRemovalExists() const;

		// Remove TimeBeforeRemoval field.
		void RemoveTimeBeforeRemoval(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ConcreteJob> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ConcreteJob(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Job(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Job::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ConcreteJob(const CimObject &object)
			: CIM_Job(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Job::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Job::SetMetaData(childMetaData);
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
#endif // CIM_CONCRETEJOB_H
