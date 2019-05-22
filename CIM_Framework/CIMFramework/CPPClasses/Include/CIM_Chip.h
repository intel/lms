//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Chip.h
//
//  Contents:   The Chip class represents any type of integrated circuit hardware, including ASICs, processors, memory chips, etc.
//
//              This file was automatically generated from CIM_Chip.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CHIP_H
#define CIM_CHIP_H 1
#include "CIM_PhysicalComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Chip class represents any type of integrated circuit hardware, including ASICs, processors, memory chips, etc.
	class CIMFRAMEWORK_API CIM_Chip  : public CIM_PhysicalComponent
	{
	public:

		//Default constructor
		CIM_Chip()
			: CIM_PhysicalComponent(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		CIM_Chip(ICimWsmanClient *client)
			: CIM_PhysicalComponent(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~CIM_Chip(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Chip keys
		class CimKeys : public CIM_PhysicalComponent::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The implementation form factor for the Chip. For example, values such as SIMM (7), TSOP (9) or PGA (10) can be specified.
		const unsigned short FormFactor() const;

		// Optional, The implementation form factor for the Chip. For example, values such as SIMM (7), TSOP (9) or PGA (10) can be specified.
		void FormFactor(const unsigned short value); 

		// Is true if the field FormFactor exists in the current object, otherwise is false.
		bool FormFactorExists() const;

		// Remove FormFactor field.
		void RemoveFormFactor(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Chip> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Chip(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalComponent(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Chip(const CimObject &object)
			: CIM_PhysicalComponent(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalComponent::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // CIM_CHIP_H
