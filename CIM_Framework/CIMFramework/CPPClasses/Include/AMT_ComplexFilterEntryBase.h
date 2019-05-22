//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ComplexFilterEntryBase.h
//
//  Contents:   Class AMT_ComplexFilterEntryBase is an abstract class, representing any type of filter which can be identified by InstanceID and Name
//
//              This file was automatically generated from AMT_ComplexFilterEntryBase.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_COMPLEXFILTERENTRYBASE_H
#define AMT_COMPLEXFILTERENTRYBASE_H 1
#include "AMT_FilterEntryBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Class AMT_ComplexFilterEntryBase is an abstract class, representing any type of filter which can be identified by InstanceID and Name
	class CIMFRAMEWORK_API AMT_ComplexFilterEntryBase  : public AMT_FilterEntryBase
	{
	public:

		//Default constructor
		AMT_ComplexFilterEntryBase()
			: AMT_FilterEntryBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_FilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		AMT_ComplexFilterEntryBase(ICimWsmanClient *client)
			: AMT_FilterEntryBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_FilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~AMT_ComplexFilterEntryBase(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ComplexFilterEntryBase keys
		class CimKeys : public AMT_FilterEntryBase::CimKeys
		{
		public:
			// Key, Required, The scoping ComputerSystem's CreationClassName.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The scoping ComputerSystem's CreationClassName.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The scoping ComputerSystem's Name.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The scoping ComputerSystem's Name.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, The Name property defines the label by which the Filter Entry is known and uniquely identified.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property defines the label by which the Filter Entry is known and uniquely identified.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

			// Key, Required, The creation handle for this filter.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, The creation handle for this filter.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Key, Required, The scoping ComputerSystem's CreationClassName.
		const string SystemCreationClassName() const;

		// Key, Required, The scoping ComputerSystem's CreationClassName.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The scoping ComputerSystem's Name.
		const string SystemName() const;

		// Key, Required, The scoping ComputerSystem's Name.
		void SystemName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ComplexFilterEntryBase> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ComplexFilterEntryBase(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_FilterEntryBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_FilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ComplexFilterEntryBase(const CimObject &object)
			: AMT_FilterEntryBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_FilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_FilterEntryBase::SetMetaData(childMetaData);
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
#endif // AMT_COMPLEXFILTERENTRYBASE_H
