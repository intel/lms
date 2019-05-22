//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_FilterEntryBase.h
//
//  Contents:   Class AMT_FilterEntryBase is an abstract class, representing any type of filter
//
//              This file was automatically generated from AMT_FilterEntryBase.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_FILTERENTRYBASE_H
#define AMT_FILTERENTRYBASE_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Class AMT_FilterEntryBase is an abstract class, representing any type of filter
	class CIMFRAMEWORK_API AMT_FilterEntryBase  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		AMT_FilterEntryBase()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_FilterEntryBase(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_FilterEntryBase(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_FilterEntryBase keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Boolean indicating that the match condition described in the properties of the FilterEntryBase subclass should be negated. This property is defined for ease of use when filtering on simple negations - for example, to select all source ports except 162. It is not recommended that this Boolean be set to True when filtering on multiple criteria, such as defining an IPHeadersFilter based on source/destination addresses, ports, and DiffServ Code Points.
		const bool IsNegated() const;

		// Optional, Boolean indicating that the match condition described in the properties of the FilterEntryBase subclass should be negated. This property is defined for ease of use when filtering on simple negations - for example, to select all source ports except 162. It is not recommended that this Boolean be set to True when filtering on multiple criteria, such as defining an IPHeadersFilter based on source/destination addresses, ports, and DiffServ Code Points.
		void IsNegated(const bool value); 

		// Is true if the field IsNegated exists in the current object, otherwise is false.
		bool IsNegatedExists() const;

		// Remove IsNegated field.
		void RemoveIsNegated(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_FilterEntryBase> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_FilterEntryBase(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_FilterEntryBase(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
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
#endif // AMT_FILTERENTRYBASE_H
