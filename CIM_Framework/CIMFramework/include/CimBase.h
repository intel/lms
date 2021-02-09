//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2021  All Rights Reserved.
//
//  File:		CimBase.h    
//
//  Contents:	A typed interface to CIM objects, declarations.   
//
//----------------------------------------------------------------------------

#ifndef CIMBASE_H
#define CIMBASE_H 1

#include "CimTypedDllExport.h"
#include "CimObject.h"
#include "CimException.h"
#include "CimDateTime.h"
#include "CimClassFactory.h"
#include "CimSerializer.h"
#include "CimTypedUtils.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	using namespace Intel::Manageability::Cim::Utils;	
	using Intel::Manageability::Cim::Untyped::CimObject;
	using Intel::Manageability::Cim::CimReference;
	using Intel::Manageability::Cim::WsManSelectors;
	using Intel::WSManagement::ICimWsmanClient;
	using Intel::WSManagement::EnumerateFilter;
	using Intel::Manageability::Exceptions::CimException;
	using std::shared_ptr;

	// This class tells us if a field is a key and if it's required.
	// This is metadata about the field.
	// The name here must match the name of the field as stored with the values.
	struct CimFieldAttribute {
		string name;
		bool iskey;
		bool isrequired;
		bool isEmbeddedObject;
	};

	// This class is used on the off chance that Enumerate returns an unknown object
	// that is derived from a known object.
	template<class T>
	class CIMFRAMEWORK_API CimExtended : public T
	{
	public:
		// Constructors.
		CimExtended(ICimWsmanClient *client, const string &objectName,
				const string &nameSpace, const string &prefix, const string &resourceURI)
				: T(client, objectName, nameSpace, prefix, resourceURI)
		{
		}

		CimExtended(const CimObject &object)
				: T(object)
		{
		}

		// Set an existing field or add a new field.
		void SetOrAddField(const string &name, const string &value)
		{
			T::SetOrAddField(name, value);
		}
		void SetOrAddField(const string &name, const vector<string> &value)
		{
			T::SetOrAddField(name, value);
		}
	};


	// This class serves as the base class for parameters classes. Parameter classes
	// are used for the input and output parameters of method calls on CIM objects.
	class CIMFRAMEWORK_API CimParam
	{
		friend class Intel::Manageability::Cim::Typed::CimBase;
	private:
		Intel::Manageability::Cim::Untyped::CimParam _cimParamObject;
	public:

	protected:
		// Constructor.  Protected so that this class cannot be instantiated directly.
		CimParam() {}

		// Set a field or add a new one. For use by derived class.
		void SetOrAddField(const string &name, const string &value)
		{
			_cimParamObject.SetOrAddField(name, value);
		}
		void SetOrAddField(const string &name, const vector<string> &value)
		{
			_cimParamObject.SetOrAddField(name, value);
		}

		// Get the value of a field.
		const vector<string> GetField(const string &name) const
		{
			return _cimParamObject.GetField(name);
		}
		
		// Return true if the object contains the given field.
		bool ContainsField(const string &name) const
		{
			return _cimParamObject.ContainsField(name);
		}

		// Helper function used by derived classes that sorts the field data into
		// the order defined by the object's MOF; this is required for input
		// parameters.
		VectorFieldData sortData(const CimFieldAttribute metadata[], int count) const
		{
			VectorFieldData ret;
			for (int i = 0; i < count; i++)
			{
				FieldData temp;
				temp.name = metadata[i].name;
				if(ContainsField(temp.name))
				{
					temp.value = GetField(temp.name);
					ret.push_back(temp);
				}
			}
			return ret;
		}

		
		// Return sorted vector of fields according to the definition in the MOF file.
		virtual const VectorFieldData GetAllFields() const 
		{ 
			VectorFieldData ret;
			return ret;
		};
		
		// Destructor.
		virtual ~CimParam () = 0;

	}; // end class CimParam

	// Base class for all of the typed classes.
	class CIMFRAMEWORK_API CimBase {
		friend class Intel::Manageability::Cim::Utils::TypedTypeConverter;
	public:
		// Base class for the CimKeys classes for each typed class.
		class CimKeys {
		private:
			CimObject::CimKeys cimObjectKeys;
		protected:
			CimKeys() { }
			virtual ~CimKeys() {}
			const string &GetKey(const string &name) const
			{
				return cimObjectKeys.GetKey(name);
			}

			void SetOrAddKey(const string &name, const string &value, const bool isRef = false)
			{
				cimObjectKeys.SetKey(name, value, isRef);
			}
		public:
			const CimObject::CimKeys &CimObjectKeys() const
			{
				return cimObjectKeys;
			}
		};

		// Destructor.
		virtual ~CimBase();

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const;
		virtual const string& XmlNamespace() const;
		virtual const string& XmlPrefix() const;
		virtual const string& ObjectType() const;

		// The WS-Management client - gettor and settor.
		ICimWsmanClient *WsmanClient() const;
		void WsmanClient(ICimWsmanClient *client);

		// Return a reference object for this CIM class.
		CimReference Reference() const;

		// Return all the fields and their values.
		// This allows easy iteration over the fields and values of
		// a concrete object if all that's necessary is to print values.
		const VectorFieldData GetAllFields() const;

		// WS-Management Methods:

		// Get methods.
		void Get();
		void Get(const CimKeys &keys);
		void Get(const CimReference &reference);

		// Delete the calling object only
		void Delete();

		// Delete the object specified by the reference.
		static void Delete(ICimWsmanClient *client, const CimReference &reference);

		// "Special" Enumerate (return a vector of CimBase pointers)
		static vector<shared_ptr<CimBase> > Enumerate(ICimWsmanClient *client, const EnumerateFilter &filter);

		// "Special" Enumerate (return a vector of CimReference pointers)
		static vector<shared_ptr<CimReference> > EnumerateRef(ICimWsmanClient *client, const EnumerateFilter &filter);

		// Put this object. Note that the firmware may change the values of fields
		// as a result of this operation. However, keys are guaranteed NOT to be changed.
		// In order to have an object fully represents the CIM object in the firmware,
		// you must do a Get() operation.
		void Put();

		// Create this object.  Return a reference describing the actual object.
		// Note: In order to have an object that fully represents the CIM object
		// in the firmware you must do a Get() with the returned reference.
		CimReference Create() const;

		// Is a particular field a key?
		bool IsKey(const string &field) const;

		// Is a particular field required?
		bool IsRequired(const string &field) const;

	protected:
		class CimEmptyParam : public CimParam {
		public:
			~CimEmptyParam() {}
		};

		// Constructors. These are protected so that instances of this class
		// cannot be created directly.
		CimBase(ICimWsmanClient *client, const string &objectName,
				const string &nameSpace, const string &prefix, const string &resourceURI);
		CimBase();
		CimBase(const CimObject &object);
			
		// Serialize/Deserialize to/from XML.
		string Serialize(const string &name = "") const;
		void Deserialize(const string &xml);
		
		// CimObject interface functions for internal use by derived classes
		// not virtual, this is delegation to _lateBindingObject.
		const vector<string> GetField(const string &name) const;

		void SetOrAddField(const string &name, const string &value);
		void SetOrAddField(const string &name, const vector<string> &value);

		bool ContainsField(const string &name) const;
		void RemoveField(const string &name);
		
		unsigned int Invoke(const string &methodName,
			const CimParam &input, CimParam &output);

		// Enumerate using CimObject::Enumerate.
		template<class T>
		static vector< shared_ptr<T> > Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
		{			
			vector< shared_ptr<T> > vec;
			string resourceUri = T::ClassResourceURI();
			vector< shared_ptr<CimObject> > objectVec = CimObject::Enumerate(client, resourceUri, keys.CimObjectKeys());
			vector< shared_ptr<CimObject> >::const_iterator iter;

			for(iter = objectVec.begin(); iter != objectVec.end(); iter++)
			{
				CimBase* obj = CimClassFactory::CreateCimClass(**iter, (**iter).ObjectType(), T::ClassObjectType());
				T* newobj = (T*)obj;
				shared_ptr<T> a(newobj);
				vec.push_back(a);
			}
			return vec;
		}

		// Delete the object defined by the ResourceURI and the keys.
		static void Delete(ICimWsmanClient *client, const string &resourceURI, const CimKeys &keys);
		
		// Reset the fields based on the parameter. Use by Deserialize.
		void ResetFields(const VectorFieldData &fields);

		// Called by descendant constructors to fill in their metadata with the given information.
		void SetMetaData(vector<CimFieldAttribute>& resultVector, const CimFieldAttribute metadata[], int count);

		// Return the underlying untyped CIM object.  Needed by CimAnonymous.
		CimObject GetUnTyped() const;

		// Return the full metadata for this class.
		virtual const vector<CimFieldAttribute> &GetMetaData() const;

	private:
		// The underlying untyped object which stores the data.
		CimObject _lateBindingObject;

		// Retrieve the keys for the CIM class.
		const CimObject::CimKeys GetKeys() const;

		// Finds position in _metadata vector.
		// Returns -1 if name is not found.
		int FindMetaData(const string &name) const;
	};

	
};
};
};
};

#endif // CIMBASE_H
