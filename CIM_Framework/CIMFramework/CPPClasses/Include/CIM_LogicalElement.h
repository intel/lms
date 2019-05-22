//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalElement.h
//
//  Contents:   CIM_LogicalElement is a base class for all the components of a System that represent abstract system components, such as Files, Processes, or LogicalDevices.
//
//              This file was automatically generated from CIM_LogicalElement.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOGICALELEMENT_H
#define CIM_LOGICALELEMENT_H 1
#include "CIM_ManagedSystemElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_LogicalElement is a base class for all the components of a System that represent abstract system components, such as Files, Processes, or LogicalDevices.
	class CIMFRAMEWORK_API CIM_LogicalElement  : public CIM_ManagedSystemElement
	{
	public:

		//Default constructor
		CIM_LogicalElement()
			: CIM_ManagedSystemElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_ManagedSystemElement::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_LogicalElement(ICimWsmanClient *client)
			: CIM_ManagedSystemElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_ManagedSystemElement::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_LogicalElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_LogicalElement keys
		class CimKeys : public CIM_ManagedSystemElement::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_LogicalElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_LogicalElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedSystemElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_ManagedSystemElement::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_LogicalElement(const CimObject &object)
			: CIM_ManagedSystemElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_ManagedSystemElement::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedSystemElement::SetMetaData(childMetaData);
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
#endif // CIM_LOGICALELEMENT_H
