//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_FilterCollectionSubscription.h
//
//  Contents:   CIM_FilterCollectionSubscription associates the CIM_FilterCollection with a CIM_ListenerDestionation.
//
//              This file was automatically generated from CIM_FilterCollectionSubscription.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_FILTERCOLLECTIONSUBSCRIPTION_H
#define CIM_FILTERCOLLECTIONSUBSCRIPTION_H 1
#include "CIM_AbstractIndicationSubscription.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_FilterCollectionSubscription associates the CIM_FilterCollection with a CIM_ListenerDestionation.
	class CIMFRAMEWORK_API CIM_FilterCollectionSubscription  : public CIM_AbstractIndicationSubscription
	{
	public:

		//Default constructor
		CIM_FilterCollectionSubscription()
			: CIM_AbstractIndicationSubscription(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_AbstractIndicationSubscription::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_FilterCollectionSubscription(ICimWsmanClient *client)
			: CIM_AbstractIndicationSubscription(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_AbstractIndicationSubscription::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_FilterCollectionSubscription(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_FilterCollectionSubscription keys
		class CimKeys : public CIM_AbstractIndicationSubscription::CimKeys
		{
		public:
			// Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
			const CimReference Filter() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Filter"), ret);
				return ret;
			}

			// Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
			void Filter(const CimReference &value)
			{
				SetOrAddKey("Filter", TypeConverter::TypeToString(value), true);
			}

			// Required, The Handler addressing delivery of the possible Indications of this subscription.
			const CimReference Handler() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Handler"), ret);
				return ret;
			}

			// Required, The Handler addressing delivery of the possible Indications of this subscription.
			void Handler(const CimReference &value)
			{
				SetOrAddKey("Handler", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_FilterCollectionSubscription> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_FilterCollectionSubscription(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_AbstractIndicationSubscription(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_AbstractIndicationSubscription::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_FilterCollectionSubscription(const CimObject &object)
			: CIM_AbstractIndicationSubscription(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_AbstractIndicationSubscription::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_AbstractIndicationSubscription::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_FILTERCOLLECTIONSUBSCRIPTION_H
