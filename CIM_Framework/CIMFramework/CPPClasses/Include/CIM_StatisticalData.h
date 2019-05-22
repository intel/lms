//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_StatisticalData.h
//
//  Contents:   CIM_StatisticalData is a root class for any arbitrary collection of statistical data and/or metrics applicable to one or more ManagedElements. These statistics MUST represent the most recent observations and MUST NOT be provided if irrelevant or stale. Note that this class uses a simplified naming/identity algorithm as compared to CIM_StatisticalInformation.
//
//              This file was automatically generated from CIM_StatisticalData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_STATISTICALDATA_H
#define CIM_STATISTICALDATA_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_StatisticalData is a root class for any arbitrary collection of statistical data and/or metrics applicable to one or more ManagedElements. These statistics MUST represent the most recent observations and MUST NOT be provided if irrelevant or stale. Note that this class uses a simplified naming/identity algorithm as compared to CIM_StatisticalInformation.
	class CIMFRAMEWORK_API CIM_StatisticalData  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_StatisticalData()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_StatisticalData(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_StatisticalData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_StatisticalData keys
		class CimKeys : public CIM_ManagedElement::CimKeys
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

		// Optional, The time, relative to managed element where the statistic was collected, when the first measurement was taken. If the statistic is reset, the StartStatisticTime is the time when the reset was performed.
		const CimDateTime StartStatisticTime() const;

		// Optional, The time, relative to managed element where the statistic was collected, when the first measurement was taken. If the statistic is reset, the StartStatisticTime is the time when the reset was performed.
		void StartStatisticTime(const CimDateTime &value); 

		// Is true if the field StartStatisticTime exists in the current object, otherwise is false.
		bool StartStatisticTimeExists() const;

		// Remove StartStatisticTime field.
		void RemoveStartStatisticTime(); 

		// Optional, The time the most recent measurement was taken, relative to the managed element where the statistic was collected.
		const CimDateTime StatisticTime() const;

		// Optional, The time the most recent measurement was taken, relative to the managed element where the statistic was collected.
		void StatisticTime(const CimDateTime &value); 

		// Is true if the field StatisticTime exists in the current object, otherwise is false.
		bool StatisticTimeExists() const;

		// Remove StatisticTime field.
		void RemoveStatisticTime(); 

		// Optional, Some statistics are sampled at consistent time intervals. This property provides the sample interval so that client applications can determine the minimum time that new statistics should be pulled. If the statistics are not sampled at consistent time intervals, this property must be set to a zero time interval.
		const CimDateTime SampleInterval() const;

		// Optional, Some statistics are sampled at consistent time intervals. This property provides the sample interval so that client applications can determine the minimum time that new statistics should be pulled. If the statistics are not sampled at consistent time intervals, this property must be set to a zero time interval.
		void SampleInterval(const CimDateTime &value); 

		// Is true if the field SampleInterval exists in the current object, otherwise is false.
		bool SampleIntervalExists() const;

		// Remove SampleInterval field.
		void RemoveSampleInterval(); 

		//Input parameter for function ResetSelectedStats
		class CIMFRAMEWORK_API ResetSelectedStats_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ResetSelectedStats_INPUT() : CimParam() {}

			// Class Destructor
			~ResetSelectedStats_INPUT(){}

			// Required, Array of strings indicating which statistics to reset.
			void SelectedStatistics(const vector<string> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Method to reset one or more of the instance's statistics. The method takes one parameter as input - an array of strings indicating which statistics to reset. If all the statistics in the instance should be reset, the first element of the array MUST be set to "All" or "ALL". If one or more individual statistics should be reset, the corresponding property names are entered into the elements of the array. 
		// The method returns 0 if successful, 1 if not supported, and any other value if an error occurred. A method is specified so that the StatisticalInformation's provider/ instrumentation, which calculates the statistics, can reset its internal processing, counters, etc. 
		// In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int ResetSelectedStats(const ResetSelectedStats_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_StatisticalData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_StatisticalData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_StatisticalData(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // CIM_STATISTICALDATA_H
