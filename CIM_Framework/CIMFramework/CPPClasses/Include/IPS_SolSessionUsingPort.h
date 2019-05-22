//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_SolSessionUsingPort.h
//
//  Contents:   The IPS_SolSessionUsingPort is an association between the AMT_RedirectionService that manages the SOL session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
//
//              This file was automatically generated from IPS_SolSessionUsingPort.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_SOLSESSIONUSINGPORT_H
#define IPS_SOLSESSIONUSINGPORT_H 1
#include "IPS_SessionUsingPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_SolSessionUsingPort is an association between the AMT_RedirectionService that manages the SOL session and the AMT_EthernetPortSettings instance that describes the I/F port through which the session is managed
	class CIMFRAMEWORK_API IPS_SolSessionUsingPort  : public IPS_SessionUsingPort
	{
	public:

		//Default constructor
		IPS_SolSessionUsingPort()
			: IPS_SessionUsingPort(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_SessionUsingPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		IPS_SolSessionUsingPort(ICimWsmanClient *client)
			: IPS_SessionUsingPort(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_SessionUsingPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~IPS_SolSessionUsingPort(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_SolSessionUsingPort keys
		class CimKeys : public IPS_SessionUsingPort::CimKeys
		{
		public:
			// Required, The settings of the port through which the session is performed.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The settings of the port through which the session is performed.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The Service that represents the management session.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The Service that represents the management session.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_SolSessionUsingPort> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_SolSessionUsingPort(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_SessionUsingPort(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_SessionUsingPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_SolSessionUsingPort(const CimObject &object)
			: IPS_SessionUsingPort(object)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_SessionUsingPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_SessionUsingPort::SetMetaData(childMetaData);
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
#endif // IPS_SOLSESSIONUSINGPORT_H
