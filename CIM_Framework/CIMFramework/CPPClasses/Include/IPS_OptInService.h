//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_OptInService.h
//
//  Contents:   Describes the user consent service. This service manages user opt-in options and sends a user consent code for KVM, redirection, and set boot options.
//
//              This file was automatically generated from IPS_OptInService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_OPTINSERVICE_H
#define IPS_OPTINSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the user consent service. This service manages user opt-in options and sends a user consent code for KVM, redirection, and set boot options.
	class CIMFRAMEWORK_API IPS_OptInService  : public CIM_Service
	{
	public:

		//Default constructor
		IPS_OptInService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		IPS_OptInService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~IPS_OptInService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_OptInService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates the idle timeout, in seconds, after which the opt-in code expires.
		const unsigned int OptInCodeTimeout() const;

		// Optional, Indicates the idle timeout, in seconds, after which the opt-in code expires.
		void OptInCodeTimeout(const unsigned int value); 

		// Is true if the field OptInCodeTimeout exists in the current object, otherwise is false.
		bool OptInCodeTimeoutExists() const;

		// Remove OptInCodeTimeout field.
		void RemoveOptInCodeTimeout(); 

		// Optional, Indicates The OptIn (User Consent) Policy for Redirection operations,including KVM and IDER, or setting of boot options. This value is Read Only if the system was configured in Client Control Mode and Read-Write in Admin Control Mode and CanModifyOptInPolicy=true. The allowed values in Admin Control Mode are: None (opt-in not required for any of the features), KVM, or All (KVM+IDER+Boot options). Possible values in Client Control Mode: All.
		const unsigned int OptInRequired() const;

		// Optional, Indicates The OptIn (User Consent) Policy for Redirection operations,including KVM and IDER, or setting of boot options. This value is Read Only if the system was configured in Client Control Mode and Read-Write in Admin Control Mode and CanModifyOptInPolicy=true. The allowed values in Admin Control Mode are: None (opt-in not required for any of the features), KVM, or All (KVM+IDER+Boot options). Possible values in Client Control Mode: All.
		void OptInRequired(const unsigned int value); 

		// Is true if the field OptInRequired exists in the current object, otherwise is false.
		bool OptInRequiredExists() const;

		// Remove OptInRequired field.
		void RemoveOptInRequired(); 

		// Optional, Read Only. Indicates the state of OptIn: Not started: OptIn is required for sessions affected by OptInPolicy. Requested: a console has requested an opt-in code, but it was not displayed to the user yet. Displayed: the opt-in code was displayed to the user. Received: opt-in code was successfully entered by the console operator. opt-in is not required for additional redirection sessions until a timeout occurs. In Session: A session that uses the consent code is currently in progress
		const unsigned char OptInState() const;

		// Optional, Read Only. Indicates the state of OptIn: Not started: OptIn is required for sessions affected by OptInPolicy. Requested: a console has requested an opt-in code, but it was not displayed to the user yet. Displayed: the opt-in code was displayed to the user. Received: opt-in code was successfully entered by the console operator. opt-in is not required for additional redirection sessions until a timeout occurs. In Session: A session that uses the consent code is currently in progress
		void OptInState(const unsigned char &value); 

		// Is true if the field OptInState exists in the current object, otherwise is false.
		bool OptInStateExists() const;

		// Remove OptInState field.
		void RemoveOptInState(); 

		// Optional, Read Only: Indicates if Modifying the OptIn Policy via WS-Management is enabled.
		const unsigned char CanModifyOptInPolicy() const;

		// Optional, Read Only: Indicates if Modifying the OptIn Policy via WS-Management is enabled.
		void CanModifyOptInPolicy(const unsigned char &value); 

		// Is true if the field CanModifyOptInPolicy exists in the current object, otherwise is false.
		bool CanModifyOptInPolicyExists() const;

		// Remove CanModifyOptInPolicy field.
		void RemoveCanModifyOptInPolicy(); 

		// Optional, Defines the maximum time between session request and session establishment (when user discloses the PIN on the Sprite or MEBx screen to the remote operator and the operator enters the PIN). When timeout expires, all displays of Sprite notifications or MEBx screens are cancelled. Intel(R) recommends a minimum of 5 minutes (300 seconds). Read Only in Client Control Mode, R/W in Admin Control Mode.
		const unsigned short OptInDisplayTimeout() const;

		// Optional, Defines the maximum time between session request and session establishment (when user discloses the PIN on the Sprite or MEBx screen to the remote operator and the operator enters the PIN). When timeout expires, all displays of Sprite notifications or MEBx screens are cancelled. Intel(R) recommends a minimum of 5 minutes (300 seconds). Read Only in Client Control Mode, R/W in Admin Control Mode.
		void OptInDisplayTimeout(const unsigned short value); 

		// Is true if the field OptInDisplayTimeout exists in the current object, otherwise is false.
		bool OptInDisplayTimeoutExists() const;

		// Remove OptInDisplayTimeout field.
		void RemoveOptInDisplayTimeout(); 

		// Request an opt-in code. Intel(R) AMT generates code internally.
		virtual unsigned int StartOptIn();

		// Cancel a previous opt-in code request.
		virtual unsigned int CancelOptIn();

		//Input parameter for function SendOptInCode
		class CIMFRAMEWORK_API SendOptInCode_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SendOptInCode_INPUT() : CimParam() {}

			// Class Destructor
			~SendOptInCode_INPUT(){}

			// Optional, The opt-in code generated by Intel(R) AMT. This code is displayed on the user screen and should be entered by the remote IT technician.
			// Legal values:
			// Generated Code: 0..999999
			// Reserved: 1000000..
			void OptInCode(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Send the opt-in code to Intel(R) AMT.
		virtual unsigned int SendOptInCode(const SendOptInCode_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_OptInService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_OptInService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_OptInService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // IPS_OPTINSERVICE_H
