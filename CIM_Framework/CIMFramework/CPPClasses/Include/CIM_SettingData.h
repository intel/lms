//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SettingData.h
//
//  Contents:   CIM_SettingData is used to represent configuration and and operational parameters for CIM_ManagedElement instances. There are a number of different uses of CIM_SettingData supported in the model today. Additional uses may be defined in the future.
//              Instances of CIM_SettingData may represent Aspects of a CIM_ManagedElement instance. This is modeled using the CIM_SettingsDefineState association. CIM_SettingData may be used to define capabilities when associated to an instance of CIM_Capabilities through the CIM_SettingsDefineCapabilities association. 
//              Instances of CIM_SettingData may represent different types of configurations for a CIM_ManagedElement, including persistent configurations, in progress configuration changes, or requested configurations. The CIM_ElementSettingData association is used to model the relationship between a CIM_SettingData instance and the CIM_ManagedElement for which it is a configuration. 
//              When an instance of CIM_SettingData represents a configuration, the current operational values for the parameters of the element are reflected by properties in the Element itself or by properties in its associations. These properties do not have to be the same values that are present in the SettingData object. For example, a modem might have a SettingData baud rate of 56Kb/sec but be operating at 19.2Kb/sec. 
//              Note: The CIM_SettingData class is very similar to CIM_Setting, yet both classes are present in the model because many implementations have successfully used CIM_Setting. However, issues have arisen that could not be resolved without defining a new class. Therefore, until a new major release occurs, both classes will exist in the model. Refer to the Core White Paper for additional information. SettingData instances can be aggregated together into higher- level SettingData objects using ConcreteComponent associations.
//
//              This file was automatically generated from CIM_SettingData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SETTINGDATA_H
#define CIM_SETTINGDATA_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_SettingData is used to represent configuration and and operational parameters for CIM_ManagedElement instances. There are a number of different uses of CIM_SettingData supported in the model today. Additional uses may be defined in the future.
	// Instances of CIM_SettingData may represent Aspects of a CIM_ManagedElement instance. This is modeled using the CIM_SettingsDefineState association. CIM_SettingData may be used to define capabilities when associated to an instance of CIM_Capabilities through the CIM_SettingsDefineCapabilities association. 
	// Instances of CIM_SettingData may represent different types of configurations for a CIM_ManagedElement, including persistent configurations, in progress configuration changes, or requested configurations. The CIM_ElementSettingData association is used to model the relationship between a CIM_SettingData instance and the CIM_ManagedElement for which it is a configuration. 
	// When an instance of CIM_SettingData represents a configuration, the current operational values for the parameters of the element are reflected by properties in the Element itself or by properties in its associations. These properties do not have to be the same values that are present in the SettingData object. For example, a modem might have a SettingData baud rate of 56Kb/sec but be operating at 19.2Kb/sec. 
	// Note: The CIM_SettingData class is very similar to CIM_Setting, yet both classes are present in the model because many implementations have successfully used CIM_Setting. However, issues have arisen that could not be resolved without defining a new class. Therefore, until a new major release occurs, both classes will exist in the model. Refer to the Core White Paper for additional information. SettingData instances can be aggregated together into higher- level SettingData objects using ConcreteComponent associations.
	class CIMFRAMEWORK_API CIM_SettingData  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_SettingData()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_SettingData(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_SettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SettingData keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. To ensure uniqueness within the NameSpace, the value of InstanceID should be constructed using the following "preferred" algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements. If the above "preferred" algorithm is not used, the defining entity must assure that the resulting InstanceID is not reused across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
			// For DMTF-defined instances, the "preferred" algorithm must be used with the <OrgID> set to CIM.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. To ensure uniqueness within the NameSpace, the value of InstanceID should be constructed using the following "preferred" algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in InstanceID must appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be reused to identify different underlying (real-world) elements. If the above "preferred" algorithm is not used, the defining entity must assure that the resulting InstanceID is not reused across any InstanceIDs produced by this or other providers for the NameSpace of this instance. 
			// For DMTF-defined instances, the "preferred" algorithm must be used with the <OrgID> set to CIM.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SettingData(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // CIM_SETTINGDATA_H
