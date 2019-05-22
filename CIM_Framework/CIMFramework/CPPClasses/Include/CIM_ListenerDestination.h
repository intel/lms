//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ListenerDestination.h
//
//  Contents:   The description of a CIM Listener destination. A CIM_Listener is an entity capable of receiving CIM Export Messages (e.g., Indications or responses to an asynchronous CIM Operation).
//
//              This file was automatically generated from CIM_ListenerDestination.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LISTENERDESTINATION_H
#define CIM_LISTENERDESTINATION_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The description of a CIM Listener destination. A CIM_Listener is an entity capable of receiving CIM Export Messages (e.g., Indications or responses to an asynchronous CIM Operation).
	class CIMFRAMEWORK_API CIM_ListenerDestination  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_ListenerDestination()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		CIM_ListenerDestination(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~CIM_ListenerDestination(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ListenerDestination keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, A System's CreationClassName. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, A System's CreationClassName. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, A System's Name. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, A System's Name. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, Indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, it allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, Indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, it allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, Indicates the name of the CIM Listener destination.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, Indicates the name of the CIM Listener destination.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, A System's CreationClassName. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
		const string SystemCreationClassName() const;

		// Key, Required, A System's CreationClassName. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
		void SystemCreationClassName(const string &value); 


		// Key, Required, A System's Name. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
		const string SystemName() const;

		// Key, Required, A System's Name. A CIM Listener destination is defined in context of a CIM_System (e.g., the sending system.
		void SystemName(const string &value); 


		// Key, Required, Indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, it allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, Indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, it allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Key, Required, Indicates the name of the CIM Listener destination.
		const string Name() const;

		// Key, Required, Indicates the name of the CIM Listener destination.
		void Name(const string &value); 


		// Optional, Describes the Persistence Type of the destination defined by this instance. If the value of PersistenceType is not specified, the value of PersistenceType MUST be treated as 2 ("Permanent"). A value of 2 ("Permanent") declares that the destination is always expected to be available (e.g., system log file). Inability to access this destination MUST be treated as an error condition. A value of 3 ("Transient") indicates that the destination is short-lived. Inability to access the destination MAY be treated as a normal termination condition. Subscriptions with "Transient" destinations MAY be deleted when the destination terminates or is no longer available.
		const unsigned short PersistenceType() const;

		// Optional, Describes the Persistence Type of the destination defined by this instance. If the value of PersistenceType is not specified, the value of PersistenceType MUST be treated as 2 ("Permanent"). A value of 2 ("Permanent") declares that the destination is always expected to be available (e.g., system log file). Inability to access this destination MUST be treated as an error condition. A value of 3 ("Transient") indicates that the destination is short-lived. Inability to access the destination MAY be treated as a normal termination condition. Subscriptions with "Transient" destinations MAY be deleted when the destination terminates or is no longer available.
		void PersistenceType(const unsigned short value); 

		// Is true if the field PersistenceType exists in the current object, otherwise is false.
		bool PersistenceTypeExists() const;

		// Remove PersistenceType field.
		void RemovePersistenceType(); 

		// Optional, A string describing ("Other") values for PersistenceType. This value MUST be set to a non NULL value when the PersistenceType is 1 ("Other"). For all other values of PersistenceType, the value of OtherPersistenceType MUST be NULL.
		const string OtherPersistenceType() const;

		// Optional, A string describing ("Other") values for PersistenceType. This value MUST be set to a non NULL value when the PersistenceType is 1 ("Other"). For all other values of PersistenceType, the value of OtherPersistenceType MUST be NULL.
		void OtherPersistenceType(const string &value); 

		// Is true if the field OtherPersistenceType exists in the current object, otherwise is false.
		bool OtherPersistenceTypeExists() const;

		// Remove OtherPersistenceType field.
		void RemoveOtherPersistenceType(); 

		// Optional, The destination IETF URI to which Export Messages are to be delivered. The scheme in the URI must be supported by theprotocol selected in the Protocol property.
		const string Destination() const;

		// Optional, The destination IETF URI to which Export Messages are to be delivered. The scheme in the URI must be supported by theprotocol selected in the Protocol property.
		void Destination(const string &value); 

		// Is true if the field Destination exists in the current object, otherwise is false.
		bool DestinationExists() const;

		// Remove Destination field.
		void RemoveDestination(); 

		// Optional, A free-form string providing a description of the supported protocols when 1, "Other", is specified for the Protocol.
		const string OtherProtocol() const;

		// Optional, A free-form string providing a description of the supported protocols when 1, "Other", is specified for the Protocol.
		void OtherProtocol(const string &value); 

		// Is true if the field OtherProtocol exists in the current object, otherwise is false.
		bool OtherProtocolExists() const;

		// Remove OtherProtocol field.
		void RemoveOtherProtocol(); 

		// Optional, Protocol describes an encoding and protocol which will be used to deliver the indication. If Other is used, the value for OtherProtocol must not be null.
		// If a protocol is not specified, 2 "CIM-XML" must be assumed.
		const unsigned short Protocol() const;

		// Optional, Protocol describes an encoding and protocol which will be used to deliver the indication. If Other is used, the value for OtherProtocol must not be null.
		// If a protocol is not specified, 2 "CIM-XML" must be assumed.
		void Protocol(const unsigned short value); 

		// Is true if the field Protocol exists in the current object, otherwise is false.
		bool ProtocolExists() const;

		// Remove Protocol field.
		void RemoveProtocol(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ListenerDestination> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ListenerDestination(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ListenerDestination(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 9);
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
#endif // CIM_LISTENERDESTINATION_H
