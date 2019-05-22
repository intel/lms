//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ManagedElement.h
//
//  Contents:   ManagedElement is an abstract class that provides a common superclass (or top of the inheritance tree) for the non-association classes in the CIM Schema.
//
//              This file was automatically generated from CIM_ManagedElement.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MANAGEDELEMENT_H
#define CIM_MANAGEDELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ManagedElement is an abstract class that provides a common superclass (or top of the inheritance tree) for the non-association classes in the CIM Schema.
	class CIMFRAMEWORK_API CIM_ManagedElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_ManagedElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_ManagedElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_ManagedElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ManagedElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, InstanceID is an optional property that may be used to opaquely and uniquely identify an instance of this class within the scope of the instantiating Namespace. Various subclasses of this class may override this property to make it required, or a key. Such subclasses may also modify the preferred algorithms for ensuring uniqueness that are defined below.
		// To ensure uniqueness within the NameSpace, the value of InstanceID should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements. If not null and the above "preferred" algorithm is not used, the defining entity must assure that the resulting InstanceID is not reused across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
		// If not set to null for DMTF-defined instances, the "preferred" algorithm must be used with the <OrgID> set to CIM.
		const string InstanceID() const;

		// Optional, InstanceID is an optional property that may be used to opaquely and uniquely identify an instance of this class within the scope of the instantiating Namespace. Various subclasses of this class may override this property to make it required, or a key. Such subclasses may also modify the preferred algorithms for ensuring uniqueness that are defined below.
		// To ensure uniqueness within the NameSpace, the value of InstanceID should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements. If not null and the above "preferred" algorithm is not used, the defining entity must assure that the resulting InstanceID is not reused across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
		// If not set to null for DMTF-defined instances, the "preferred" algorithm must be used with the <OrgID> set to CIM.
		void InstanceID(const string &value); 

		// Is true if the field InstanceID exists in the current object, otherwise is false.
		bool InstanceIDExists() const;

		// Remove InstanceID field.
		void RemoveInstanceID(); 

		// Optional, The Caption property is a short textual description (one- line string) of the object.
		const string Caption() const;

		// Optional, The Caption property is a short textual description (one- line string) of the object.
		void Caption(const string &value); 

		// Is true if the field Caption exists in the current object, otherwise is false.
		bool CaptionExists() const;

		// Remove Caption field.
		void RemoveCaption(); 

		// Optional, The Description property provides a textual description of the object.
		const string Description() const;

		// Optional, The Description property provides a textual description of the object.
		void Description(const string &value); 

		// Is true if the field Description exists in the current object, otherwise is false.
		bool DescriptionExists() const;

		// Remove Description field.
		void RemoveDescription(); 

		// Optional, A user-friendly name for the object. This property allows each instance to define a user-friendly name in addition to its key properties, identity data, and description information. 
		// Note that the Name property of ManagedSystemElement is also defined as a user-friendly name. But, it is often subclassed to be a Key. It is not reasonable that the same property can convey both identity and a user-friendly name, without inconsistencies. Where Name exists and is not a Key (such as for instances of LogicalDevice), the same information can be present in both the Name and ElementName properties. Note that if there is an associated instance of CIM_EnabledLogicalElementCapabilities, restrictions on this properties may exist as defined in ElementNameMask and MaxElementNameLen properties defined in that class.
		const string ElementName() const;

		// Optional, A user-friendly name for the object. This property allows each instance to define a user-friendly name in addition to its key properties, identity data, and description information. 
		// Note that the Name property of ManagedSystemElement is also defined as a user-friendly name. But, it is often subclassed to be a Key. It is not reasonable that the same property can convey both identity and a user-friendly name, without inconsistencies. Where Name exists and is not a Key (such as for instances of LogicalDevice), the same information can be present in both the Name and ElementName properties. Note that if there is an associated instance of CIM_EnabledLogicalElementCapabilities, restrictions on this properties may exist as defined in ElementNameMask and MaxElementNameLen properties defined in that class.
		void ElementName(const string &value); 

		// Is true if the field ElementName exists in the current object, otherwise is false.
		bool ElementNameExists() const;

		// Remove ElementName field.
		void RemoveElementName(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ManagedElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ManagedElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ManagedElement(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_MANAGEDELEMENT_H
