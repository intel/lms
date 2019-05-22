//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ActiveFilterStatistics.h
//
//  Contents:   Represents an active filter in a policy.
//
//              This file was automatically generated from AMT_ActiveFilterStatistics.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ACTIVEFILTERSTATISTICS_H
#define AMT_ACTIVEFILTERSTATISTICS_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents an active filter in a policy.
	class CIMFRAMEWORK_API AMT_ActiveFilterStatistics  : public CimBase
	{
	public:

		//Default constructor
		AMT_ActiveFilterStatistics()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		AMT_ActiveFilterStatistics(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~AMT_ActiveFilterStatistics(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ActiveFilterStatistics keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, References an instance of CIM_EthernetPort.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Key, Required, References an instance of CIM_EthernetPort.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, References an instance of AMT_FilterInSystemDefensePolicy.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Key, Required, References an instance of AMT_FilterInSystemDefensePolicy.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, References an instance of CIM_EthernetPort.
		const CimReference Antecedent() const;

		// Key, Required, References an instance of CIM_EthernetPort.
		void Antecedent(const CimReference &value); 


		// Key, Required, References an instance of AMT_FilterInSystemDefensePolicy.
		const CimReference Dependent() const;

		// Key, Required, References an instance of AMT_FilterInSystemDefensePolicy.
		void Dependent(const CimReference &value); 


		// Optional, Indicates number of times read since last statistics reset.
		const unsigned int ReadCount() const;

		// Optional, Indicates number of times read since last statistics reset.
		void ReadCount(const unsigned int value); 

		// Is true if the field ReadCount exists in the current object, otherwise is false.
		bool ReadCountExists() const;

		// Remove ReadCount field.
		void RemoveReadCount(); 

		// Optional, Indicates whether this filter was matched.
		const bool FilterMatched() const;

		// Optional, Indicates whether this filter was matched.
		void FilterMatched(const bool value); 

		// Is true if the field FilterMatched exists in the current object, otherwise is false.
		bool FilterMatchedExists() const;

		// Remove FilterMatched field.
		void RemoveFilterMatched(); 

		// Optional, A time value that specifies when is the last time the current active policy became active.
		const CimDateTime ActivationTime() const;

		// Optional, A time value that specifies when is the last time the current active policy became active.
		void ActivationTime(const CimDateTime &value); 

		// Is true if the field ActivationTime exists in the current object, otherwise is false.
		bool ActivationTimeExists() const;

		// Remove ActivationTime field.
		void RemoveActivationTime(); 

		// Optional, A time value that specifies the last time the statistics were reset in the specified policy.
		const CimDateTime LastResetTime() const;

		// Optional, A time value that specifies the last time the statistics were reset in the specified policy.
		void LastResetTime(const CimDateTime &value); 

		// Is true if the field LastResetTime exists in the current object, otherwise is false.
		bool LastResetTimeExists() const;

		// Remove LastResetTime field.
		void RemoveLastResetTime(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ActiveFilterStatistics> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ActiveFilterStatistics(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ActiveFilterStatistics(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // AMT_ACTIVEFILTERSTATISTICS_H
