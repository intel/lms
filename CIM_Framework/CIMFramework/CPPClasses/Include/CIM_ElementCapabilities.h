//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementCapabilities.h
//
//  Contents:   ElementCapabilities represents the association between ManagedElements and their Capabilities. Note that the cardinality of the ManagedElement reference is Min(1). This cardinality mandates the instantiation of the ElementCapabilities association for the referenced instance of Capabilities. ElementCapabilities describes the existence requirements and context for the referenced instance of ManagedElement. Specifically, the ManagedElement MUST exist and provides the context for the Capabilities.
//
//              This file was automatically generated from CIM_ElementCapabilities.mof,  version: 2.24.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTCAPABILITIES_H
#define CIM_ELEMENTCAPABILITIES_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ElementCapabilities represents the association between ManagedElements and their Capabilities. Note that the cardinality of the ManagedElement reference is Min(1). This cardinality mandates the instantiation of the ElementCapabilities association for the referenced instance of Capabilities. ElementCapabilities describes the existence requirements and context for the referenced instance of ManagedElement. Specifically, the ManagedElement MUST exist and provides the context for the Capabilities.
	class CIMFRAMEWORK_API CIM_ElementCapabilities  : public CimBase
	{
	public:

		//Default constructor
		CIM_ElementCapabilities()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementCapabilities(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_ElementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementCapabilities keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The managed element.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The managed element.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The Capabilities object associated with the element.
			const CimReference Capabilities() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Capabilities"), ret);
				return ret;
			}

			// Key, Required, The Capabilities object associated with the element.
			void Capabilities(const CimReference &value)
			{
				SetOrAddKey("Capabilities", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The managed element.
		const CimReference ManagedElement() const;

		// Key, Required, The managed element.
		void ManagedElement(const CimReference &value); 


		// Key, Required, The Capabilities object associated with the element.
		const CimReference Capabilities() const;

		// Key, Required, The Capabilities object associated with the element.
		void Capabilities(const CimReference &value); 


		// Optional, Characteristics provides descriptive information about the Capabilities. when the value 2 "Default" is specified, the associated Capabilities shall represent the default capabilities of the associated Managed Element 
		// when the value 2 "Default" is not specified, the Capabilities instance may represent the default capabilities of the Managed Element
		// When the value 3 "Current" is specified, the associated Capabilities shall represent the current capabilities of the associated Managed Element
		// When the value 3 "Current" is not specified, the Capabilities instance may represent the current capabilities of the Managed Element.
		const vector<unsigned short> Characteristics() const;

		// Optional, Characteristics provides descriptive information about the Capabilities. when the value 2 "Default" is specified, the associated Capabilities shall represent the default capabilities of the associated Managed Element 
		// when the value 2 "Default" is not specified, the Capabilities instance may represent the default capabilities of the Managed Element
		// When the value 3 "Current" is specified, the associated Capabilities shall represent the current capabilities of the associated Managed Element
		// When the value 3 "Current" is not specified, the Capabilities instance may represent the current capabilities of the Managed Element.
		void Characteristics(const vector<unsigned short> &value); 

		// Is true if the field Characteristics exists in the current object, otherwise is false.
		bool CharacteristicsExists() const;

		// Remove Characteristics field.
		void RemoveCharacteristics(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementCapabilities(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_ELEMENTCAPABILITIES_H
