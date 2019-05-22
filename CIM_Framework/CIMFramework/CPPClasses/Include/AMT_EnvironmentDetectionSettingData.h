//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EnvironmentDetectionSettingData.h
//
//  Contents:   The AMT_EnvironmentDetectionSettingData class represents configuration-related and operational parameters for the Environment-Detection service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_EnvironmentDetectionSettingData.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ENVIRONMENTDETECTIONSETTINGDATA_H
#define AMT_ENVIRONMENTDETECTIONSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The AMT_EnvironmentDetectionSettingData class represents configuration-related and operational parameters for the Environment-Detection service in the Intel(R) AMT.
	class CIMFRAMEWORK_API AMT_EnvironmentDetectionSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_EnvironmentDetectionSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_EnvironmentDetectionSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_EnvironmentDetectionSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_EnvironmentDetectionSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, Specifies which algorithm is used to determine whether the system is in its intranet environment or in the Internet environment.
		const unsigned short DetectionAlgorithm() const;

		// Required, Specifies which algorithm is used to determine whether the system is in its intranet environment or in the Internet environment.
		void DetectionAlgorithm(const unsigned short value); 

		// Is true if the field DetectionAlgorithm exists in the current object, otherwise is false.
		bool DetectionAlgorithmExists() const;

		// Remove DetectionAlgorithm field.
		void RemoveDetectionAlgorithm(); 

		// Optional, An array of strings used in the environment detection algorithm. If DetectionAlgorithm is "Local Domains", DetectionStrings contains a set of local domain strings. If DetectionAlgorithm is "Remote URLs", then DetectionStrings contains a set of remote URLs.
		const vector<string> DetectionStrings() const;

		// Optional, An array of strings used in the environment detection algorithm. If DetectionAlgorithm is "Local Domains", DetectionStrings contains a set of local domain strings. If DetectionAlgorithm is "Remote URLs", then DetectionStrings contains a set of remote URLs.
		void DetectionStrings(const vector<string> &value); 

		// Is true if the field DetectionStrings exists in the current object, otherwise is false.
		bool DetectionStringsExists() const;

		// Remove DetectionStrings field.
		void RemoveDetectionStrings(); 

		// Optional, Can be used for environment detection in IPv6 networks that do not configure the DNS suffix via DHCP. The format is: "XXXX:XXXX:XXXX:XXXX/Y" where Y is the prefix length, the XXXX:XXXX:XXXX:XXXX part can include zeros compression (e.g. 0:0:0 or ::) formats.
		const vector<string> DetectionIPv6LocalPrefixes() const;

		// Optional, Can be used for environment detection in IPv6 networks that do not configure the DNS suffix via DHCP. The format is: "XXXX:XXXX:XXXX:XXXX/Y" where Y is the prefix length, the XXXX:XXXX:XXXX:XXXX part can include zeros compression (e.g. 0:0:0 or ::) formats.
		void DetectionIPv6LocalPrefixes(const vector<string> &value); 

		// Is true if the field DetectionIPv6LocalPrefixes exists in the current object, otherwise is false.
		bool DetectionIPv6LocalPrefixesExists() const;

		// Remove DetectionIPv6LocalPrefixes field.
		void RemoveDetectionIPv6LocalPrefixes(); 

		//Input parameter for function SetSystemDefensePolicy
		class CIMFRAMEWORK_API SetSystemDefensePolicy_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetSystemDefensePolicy_INPUT() : CimParam() {}

			// Class Destructor
			~SetSystemDefensePolicy_INPUT(){}

			// Optional, The System Defense policy which will be applied to each interface separately when it is assumed that the interface is connected to an external network. When this parameter is Null, System Defense functionality is expected to remain the same when operating inside or outside the organization.
			void Policy(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Defines the System Defense policy which will be used by Environment Detection and updates the appropriate instances of AMT_EnvironmentDetectionInterfacePolicy.
		virtual unsigned int SetSystemDefensePolicy(const SetSystemDefensePolicy_INPUT &input);

		//Input parameter for function EnableVpnRouting
		class CIMFRAMEWORK_API EnableVpnRouting_INPUT : public CimParam
		{
		public:
			// Class Constructor
			EnableVpnRouting_INPUT() : CimParam() {}

			// Class Destructor
			~EnableVpnRouting_INPUT(){}

			// Required, Enable or disable the VPN routing feature.
			void Enable(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This command is used to enable or disable VPN routing of Intel(R) AMT network messages.
		virtual unsigned int EnableVpnRouting(const EnableVpnRouting_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_EnvironmentDetectionSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_EnvironmentDetectionSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_EnvironmentDetectionSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
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
#endif // AMT_ENVIRONMENTDETECTIONSETTINGDATA_H
