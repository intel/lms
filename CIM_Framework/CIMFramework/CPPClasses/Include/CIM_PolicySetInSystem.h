//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PolicySetInSystem.h
//
//  Contents:   PolicySetInSystem is an abstract association class that represents a relationship between a System and a PolicySet used in the administrative scope of that system (e.g., AdminDomain, ComputerSystem). The Priority property is used to assign a relative priority to a PolicySet within the administrative scope in contexts where it is not a component of another PolicySet.
//
//              This file was automatically generated from CIM_PolicySetInSystem.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POLICYSETINSYSTEM_H
#define CIM_POLICYSETINSYSTEM_H 1
#include "CIM_PolicyInSystem.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PolicySetInSystem is an abstract association class that represents a relationship between a System and a PolicySet used in the administrative scope of that system (e.g., AdminDomain, ComputerSystem). The Priority property is used to assign a relative priority to a PolicySet within the administrative scope in contexts where it is not a component of another PolicySet.
	class CIMFRAMEWORK_API CIM_PolicySetInSystem  : public CIM_PolicyInSystem
	{
	public:

		//Default constructor
		CIM_PolicySetInSystem()
			: CIM_PolicyInSystem(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_PolicySetInSystem(ICimWsmanClient *client)
			: CIM_PolicyInSystem(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_PolicySetInSystem(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PolicySetInSystem keys
		class CimKeys : public CIM_PolicyInSystem::CimKeys
		{
		public:
			// Required, The System in whose scope a PolicySet is defined.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The System in whose scope a PolicySet is defined.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, A PolicySet named within the scope of a System.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, A PolicySet named within the scope of a System.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, The Priority property is used to specify the relative priority of the referenced PolicySet when there are more than one PolicySet instances applied to a managed resource that are not PolicySetComponents and, therefore, have no other relative priority defined. The priority is a non-negative integer; a larger value indicates a higher priority.
		const unsigned short Priority() const;

		// Optional, The Priority property is used to specify the relative priority of the referenced PolicySet when there are more than one PolicySet instances applied to a managed resource that are not PolicySetComponents and, therefore, have no other relative priority defined. The priority is a non-negative integer; a larger value indicates a higher priority.
		void Priority(const unsigned short value); 

		// Is true if the field Priority exists in the current object, otherwise is false.
		bool PriorityExists() const;

		// Remove Priority field.
		void RemovePriority(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PolicySetInSystem> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PolicySetInSystem(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicyInSystem(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PolicySetInSystem(const CimObject &object)
			: CIM_PolicyInSystem(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyInSystem::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicyInSystem::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // CIM_POLICYSETINSYSTEM_H
