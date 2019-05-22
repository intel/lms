//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareFeature.h
//
//  Contents:   The CIM_SoftwareFeature class defines a particular function or capability of a product or application system. This class captures a level of granularity describing a unit of installation, rather than the units that reflect how the product is built or packaged. The latter detail is captured using a CIM_SoftwareElement class. When a SoftwareFeature can exist on multiple platforms or operating systems (for example, a client component of a three tiered client/server application that runs on Solaris, Windows NT, and Windows 95), the Feature is a collection of all the SoftwareElements for these different platforms. In this case, the users of the model must be aware of this situation since typically they will be interested in a sub-collection of the SoftwareElements required for a particular platform. 
//              SoftwareFeatures are always defined in the context of a CIM_Product, using the CIM_ProductSoftwareFeature association. Features are delivered through Products. Optionally, SoftwareFeatures from one or more Products can be organized into ApplicationSystems using the CIM_ApplicationSystemSoftwareFeature association.
//
//              This file was automatically generated from CIM_SoftwareFeature.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SOFTWAREFEATURE_H
#define CIM_SOFTWAREFEATURE_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The CIM_SoftwareFeature class defines a particular function or capability of a product or application system. This class captures a level of granularity describing a unit of installation, rather than the units that reflect how the product is built or packaged. The latter detail is captured using a CIM_SoftwareElement class. When a SoftwareFeature can exist on multiple platforms or operating systems (for example, a client component of a three tiered client/server application that runs on Solaris, Windows NT, and Windows 95), the Feature is a collection of all the SoftwareElements for these different platforms. In this case, the users of the model must be aware of this situation since typically they will be interested in a sub-collection of the SoftwareElements required for a particular platform. 
	// SoftwareFeatures are always defined in the context of a CIM_Product, using the CIM_ProductSoftwareFeature association. Features are delivered through Products. Optionally, SoftwareFeatures from one or more Products can be organized into ApplicationSystems using the CIM_ApplicationSystemSoftwareFeature association.
	class CIMFRAMEWORK_API CIM_SoftwareFeature  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		CIM_SoftwareFeature()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_SoftwareFeature(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_SoftwareFeature(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SoftwareFeature keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
			// Key, Required, The scoping Product's identification.
			const string IdentifyingNumber() const
			{
				return GetKey("IdentifyingNumber");
			}

			// Key, Required, The scoping Product's identification.
			void IdentifyingNumber(const string &value)
			{
				SetOrAddKey("IdentifyingNumber", value);
			}

			// Key, Required, The scoping Product's commonly used name.
			const string ProductName() const
			{
				return GetKey("ProductName");
			}

			// Key, Required, The scoping Product's commonly used name.
			void ProductName(const string &value)
			{
				SetOrAddKey("ProductName", value);
			}

			// Key, Required, The scoping Product's supplier.
			const string Vendor() const
			{
				return GetKey("Vendor");
			}

			// Key, Required, The scoping Product's supplier.
			void Vendor(const string &value)
			{
				SetOrAddKey("Vendor", value);
			}

			// Key, Required, The scoping Product's version.
			const string Version() const
			{
				return GetKey("Version");
			}

			// Key, Required, The scoping Product's version.
			void Version(const string &value)
			{
				SetOrAddKey("Version", value);
			}

			// Key, Required, The Name property defines the unique label by which the SoftwareFeature is identified. This label should be a human-readable name that uniquely identifies the element in the context of the element's namespace.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property defines the unique label by which the SoftwareFeature is identified. This label should be a human-readable name that uniquely identifies the element in the context of the element's namespace.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, The scoping Product's identification.
		const string IdentifyingNumber() const;

		// Key, Required, The scoping Product's identification.
		void IdentifyingNumber(const string &value); 


		// Key, Required, The scoping Product's commonly used name.
		const string ProductName() const;

		// Key, Required, The scoping Product's commonly used name.
		void ProductName(const string &value); 


		// Key, Required, The scoping Product's supplier.
		const string Vendor() const;

		// Key, Required, The scoping Product's supplier.
		void Vendor(const string &value); 


		// Key, Required, The scoping Product's version.
		const string Version() const;

		// Key, Required, The scoping Product's version.
		void Version(const string &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SoftwareFeature> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SoftwareFeature(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SoftwareFeature(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
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
#endif // CIM_SOFTWAREFEATURE_H
