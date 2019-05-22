//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OrderedComponent.h
//
//  Contents:   CIM_OrderedComponent is a generic association used to establish 'part of' relationships between ManagedElements. It arranges the PartComponents in a specific assigned order. The semantics of the order depends on the context and use by the referencing classes. For example, if this association is used to arrange settings in a hierarchical order, then this specifies the sequence in which the settings are applied.
//
//              This file was automatically generated from CIM_OrderedComponent.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#ifndef CIM_ORDEREDCOMPONENT_H
#define CIM_ORDEREDCOMPONENT_H 1
#include "CIM_Component.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_OrderedComponent is a generic association used to establish 'part of' relationships between ManagedElements. It arranges the PartComponents in a specific assigned order. The semantics of the order depends on the context and use by the referencing classes. For example, if this association is used to arrange settings in a hierarchical order, then this specifies the sequence in which the settings are applied.
	class CIMFRAMEWORK_API CIM_OrderedComponent  : public CIM_Component
	{
	public:

		//Default constructor
		CIM_OrderedComponent()
			: CIM_Component(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		CIM_OrderedComponent(ICimWsmanClient *client)
			: CIM_Component(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~CIM_OrderedComponent(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_OrderedComponent keys
		class CimKeys : public CIM_Component::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, AssignedSequence is an unsigned integer 'n' that indicates the relative order of ManagedElement instances. When 'n' is a positive integer, it indicates a place in the sequence of members, with smaller integers indicating earlier positions in the sequence. The special value '0' indicates 'don't care'. If two or more members have the same non-zero sequence number, then the ordering between those members is irrelevant, but they must all be ordered at the appropriate place in the overall sequence. 
		// 
		// A series of examples will make ordering of members clearer: 
		// If all members have the same sequence number, 
		// regardless of whether it is '0' or non-zero, any 
		// order is acceptable. 
		// o The values: 
		// 1:MEMBER A 
		// 2:MEMBER B 
		// 1:MEMBER C 
		// 3:MEMBER D 
		// indicate two acceptable orders: A,C,B,D or C,A,B,D, 
		// since A and C can be ordered in either sequence, but 
		// only at the '1' position. 
		// 
		// Note that the non-zero sequence numbers need not start with '1', and they need not be consecutive. All that matters is their relative magnitude.
		const Uint64 AssignedSequence() const;

		// Optional, AssignedSequence is an unsigned integer 'n' that indicates the relative order of ManagedElement instances. When 'n' is a positive integer, it indicates a place in the sequence of members, with smaller integers indicating earlier positions in the sequence. The special value '0' indicates 'don't care'. If two or more members have the same non-zero sequence number, then the ordering between those members is irrelevant, but they must all be ordered at the appropriate place in the overall sequence. 
		// 
		// A series of examples will make ordering of members clearer: 
		// If all members have the same sequence number, 
		// regardless of whether it is '0' or non-zero, any 
		// order is acceptable. 
		// o The values: 
		// 1:MEMBER A 
		// 2:MEMBER B 
		// 1:MEMBER C 
		// 3:MEMBER D 
		// indicate two acceptable orders: A,C,B,D or C,A,B,D, 
		// since A and C can be ordered in either sequence, but 
		// only at the '1' position. 
		// 
		// Note that the non-zero sequence numbers need not start with '1', and they need not be consecutive. All that matters is their relative magnitude.
		void AssignedSequence(const Uint64 value); 

		// Is true if the field AssignedSequence exists in the current object, otherwise is false.
		bool AssignedSequenceExists() const;

		// Remove AssignedSequence field.
		void RemoveAssignedSequence(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_OrderedComponent> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_OrderedComponent(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Component(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_OrderedComponent(const CimObject &object)
			: CIM_Component(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Component::SetMetaData(childMetaData);
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
#endif // CIM_ORDEREDCOMPONENT_H
