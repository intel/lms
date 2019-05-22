//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPortCapabilities.h
//
//  Contents:   NetworkPortCapabilities describes the capabilities supported for properties that are configurable in NetworkPort.
//
//              This file was automatically generated from CIM_NetworkPortCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_NETWORKPORTCAPABILITIES_H
#define CIM_NETWORKPORTCAPABILITIES_H 1
#include "CIM_LogicalPortCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// NetworkPortCapabilities describes the capabilities supported for properties that are configurable in NetworkPort.
	class CIMFRAMEWORK_API CIM_NetworkPortCapabilities  : public CIM_LogicalPortCapabilities
	{
	public:

		//Default constructor
		CIM_NetworkPortCapabilities()
			: CIM_LogicalPortCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_NetworkPortCapabilities(ICimWsmanClient *client)
			: CIM_LogicalPortCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_NetworkPortCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_NetworkPortCapabilities keys
		class CimKeys : public CIM_LogicalPortCapabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Boolean that indicates whether the Speed can be configured.
		const bool SpeedConfigurable() const;

		// Optional, Boolean that indicates whether the Speed can be configured.
		void SpeedConfigurable(const bool value); 

		// Is true if the field SpeedConfigurable exists in the current object, otherwise is false.
		bool SpeedConfigurableExists() const;

		// Remove SpeedConfigurable field.
		void RemoveSpeedConfigurable(); 

		// Optional, List of supported port speeds that can be configured on NetworkPort.Speed.
		const vector<Uint64> PortSpeedsSupported() const;

		// Optional, List of supported port speeds that can be configured on NetworkPort.Speed.
		void PortSpeedsSupported(const vector<Uint64> &value); 

		// Is true if the field PortSpeedsSupported exists in the current object, otherwise is false.
		bool PortSpeedsSupportedExists() const;

		// Remove PortSpeedsSupported field.
		void RemovePortSpeedsSupported(); 

		// Optional, Boolean indicating whether the NetworkPort can be configured to connect to specific Networks.
		const bool NetworkIDsConfigurable() const;

		// Optional, Boolean indicating whether the NetworkPort can be configured to connect to specific Networks.
		void NetworkIDsConfigurable(const bool value); 

		// Is true if the field NetworkIDsConfigurable exists in the current object, otherwise is false.
		bool NetworkIDsConfigurableExists() const;

		// Remove NetworkIDsConfigurable field.
		void RemoveNetworkIDsConfigurable(); 

		// Optional, The format that is expected to populate the NetworkIds for the associated NetworkPortSettings.list of supported LinkTechnologies of the NetworkPort is defined in the NetworkPortCapabilities.
		const unsigned short NetworkIDsFormat() const;

		// Optional, The format that is expected to populate the NetworkIds for the associated NetworkPortSettings.list of supported LinkTechnologies of the NetworkPort is defined in the NetworkPortCapabilities.
		void NetworkIDsFormat(const unsigned short value); 

		// Is true if the field NetworkIDsFormat exists in the current object, otherwise is false.
		bool NetworkIDsFormatExists() const;

		// Remove NetworkIDsFormat field.
		void RemoveNetworkIDsFormat(); 

		// Optional, List of the LinkTechnologies supported by the the NetworkPort.
		const vector<unsigned short> LinkTechnologiesSupported() const;

		// Optional, List of the LinkTechnologies supported by the the NetworkPort.
		void LinkTechnologiesSupported(const vector<unsigned short> &value); 

		// Is true if the field LinkTechnologiesSupported exists in the current object, otherwise is false.
		bool LinkTechnologiesSupportedExists() const;

		// Remove LinkTechnologiesSupported field.
		void RemoveLinkTechnologiesSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_NetworkPortCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_NetworkPortCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalPortCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_NetworkPortCapabilities(const CimObject &object)
			: CIM_LogicalPortCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPortCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalPortCapabilities::SetMetaData(childMetaData);
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
#endif // CIM_NETWORKPORTCAPABILITIES_H
