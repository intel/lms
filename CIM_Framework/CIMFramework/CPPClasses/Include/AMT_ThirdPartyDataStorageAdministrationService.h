//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ThirdPartyDataStorageAdministrationService.h
//
//  Contents:   The Storage Administration service enables administrators to reconfigure the global parameters that govern allocation and use of third-party non-volatile storage. It also enables to retrieve various management data, and perform management actions.
//
//              This file was automatically generated from AMT_ThirdPartyDataStorageAdministrationService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_THIRDPARTYDATASTORAGEADMINISTRATIONSERVICE_H
#define AMT_THIRDPARTYDATASTORAGEADMINISTRATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Storage Administration service enables administrators to reconfigure the global parameters that govern allocation and use of third-party non-volatile storage. It also enables to retrieve various management data, and perform management actions.
	class CIMFRAMEWORK_API AMT_ThirdPartyDataStorageAdministrationService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_ThirdPartyDataStorageAdministrationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_ThirdPartyDataStorageAdministrationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_ThirdPartyDataStorageAdministrationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ThirdPartyDataStorageAdministrationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Output parameter for function GetGlobalStorageAttributes
		class CIMFRAMEWORK_API GetGlobalStorageAttributes_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetGlobalStorageAttributes_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetGlobalStorageAttributes_OUTPUT(){}

			// class fields
			// Specifies the total size, in bytes, of the portion of non-volatile memory that is available to third-party applications. This total is subdivided into partner and non-partner areas.
			const unsigned int TotalStorage() const;
			bool TotalStorageExists() const;
			// Specifies the total size, in bytes, of the portion of third-party application storage which is already allocated for use by applications.
			const unsigned int TotalAllocatedStorage() const;
			bool TotalAllocatedStorageExists() const;
			// Specifies the size, in bytes, of the portion of third-party non-volatile storage that is reserved for partner applications. This size is specified as a number of bytes. The sum of MaxPartnerStorage and MaxNonPartnerStorage must not exceed the total size of third-party non-volatile storage. The total size of non-volatile storage is an implementation-dependent quantity, but shall not be less than 96 kilobytes.
			const unsigned int MaxPartnerStorage() const;
			bool MaxPartnerStorageExists() const;
			// Specifies the size, in bytes, of the portion of third-party partner application storage which is allocated for use by applications.
			const unsigned int TotalPartnerAllocatedStorage() const;
			bool TotalPartnerAllocatedStorageExists() const;
			// Specifies the total size, in bytes, of the portion of third-party non-volatile storage that is available for non-partner applications. This area is also open to partner applications when partner storage becomes unavailable. This size is specified as a number of bytes. The sum of MaxPartnerStorage and MaxNonPartnerStorage must not exceed the total size of third-party non-volatile storage. The total size of non-volatile storage is an implementation-dependent quantity, but shall not be less than 96 kilobytes.
			const unsigned int MaxNonPartnerStorage() const;
			bool MaxNonPartnerStorageExists() const;
			// Specifies the maximum number of entries supported in the Factory Partner Allocation Control List (FPACL). This is also the maximum number of different partner applications supported by the Intel(R) AMT device at one time.
			const unsigned short MaxFpaclEntries() const;
			bool MaxFpaclEntriesExists() const;
			// Specifies the maximum number of entries supported in the Application Session List (ASL). This is the maximum number of application sessions supported concurrently at the same time.
			const unsigned short MaxAslEntries() const;
			bool MaxAslEntriesExists() const;
			// Specifies the maximum number of entries in the Enterprise access control list (EACL).
			const unsigned short MaxEaclEntries() const;
			bool MaxEaclEntriesExists() const;
			// Specifies the maximum number of permissions groups that may be associated with a single block of storage. Every permissions group is associated with a single block of storage.
			const unsigned short MaxGroupsPerBlock() const;
			bool MaxGroupsPerBlockExists() const;
			// Specifies the maximum number of members that any permissions group may have.
			const unsigned short MaxMembersPerGroup() const;
			bool MaxMembersPerGroupExists() const;
			// The maximum total allocation size, in bytes, for a single non-partner storage application.
			const unsigned int MaxNonPartnerTotalAllocationSize() const;
			bool MaxNonPartnerTotalAllocationSizeExists() const;
		private:
		};

		// Get the global attributes of the third party storage system in the Intel(R) AMT device.
		virtual unsigned int GetGlobalStorageAttributes(GetGlobalStorageAttributes_OUTPUT &output);

		//Input parameter for function SetGlobalStorageAttributes
		class CIMFRAMEWORK_API SetGlobalStorageAttributes_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetGlobalStorageAttributes_INPUT() : CimParam() {}

			// Class Destructor
			~SetGlobalStorageAttributes_INPUT(){}

			// Optional, Specifies a new value for the size of the portion of third-party non-volatile storage that is reserved for partner applications. This size is specified as a number of bytes. The remaining portion of third-party non-volatile storage is used for non-partner applications. The total size of non-volatile storage is an implementation-dependent quantity, but shall not be less than 96 kilobytes. The size must be a multiple of 4KB.
			void MaxPartnerStorage(const unsigned int value); 

			// Optional, Specifies the maximum total number of bytes that can be allocated by any application that is not in the Factory Partner Allocation Control List. The size must be a multiple of 4KB.
			void MaxNonPartnerTotalAllocationSize(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Set global attributes of the third party storage system in the Intel(R) AMT device.
		virtual unsigned int SetGlobalStorageAttributes(const SetGlobalStorageAttributes_INPUT &input);

		//Output parameter for function AdminGetRegisteredApplications
		class CIMFRAMEWORK_API AdminGetRegisteredApplications_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AdminGetRegisteredApplications_OUTPUT() : CimParam() {}

			// Class Destructor
			~AdminGetRegisteredApplications_OUTPUT(){}

			// class fields
			// The list of the application handles.
			const vector<unsigned int> ApplicationHandles() const;
			bool ApplicationHandlesExists() const;
		private:
		};

		// Returns a list of handles, each associated with a storage application which has registered to the Intel(R) AMT device in the past (i.e. in the ARL list).
		virtual unsigned int AdminGetRegisteredApplications(AdminGetRegisteredApplications_OUTPUT &output);

		//Input parameter for function AdminGetApplicationAttributes
		class CIMFRAMEWORK_API AdminGetApplicationAttributes_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AdminGetApplicationAttributes_INPUT() : CimParam() {}

			// Class Destructor
			~AdminGetApplicationAttributes_INPUT(){}

			// Required, Handle of the application whose attributes are being requested.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AdminGetApplicationAttributes
		class CIMFRAMEWORK_API AdminGetApplicationAttributes_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AdminGetApplicationAttributes_OUTPUT() : CimParam() {}

			// Class Destructor
			~AdminGetApplicationAttributes_OUTPUT(){}

			// class fields
			// The type of application attributes in this entry. This parameter should always return a value of 1.
			const unsigned int AttrType() const;
			bool AttrTypeExists() const;
			// Unique identifier of this application. This should be the 16-byte SMBIOS UUID value of the machine from which the registration originated.
			const Base64 UUID() const;
			bool UUIDExists() const;
			// The name of the vendor as specified by the vendor and provided in the application's registration.
			const string VendorName() const;
			bool VendorNameExists() const;
			// The name of the ISV application, as specified by the vendor and provided in the application's registration.
			const string ApplicationName() const;
			bool ApplicationNameExists() const;
			// The name of the enterprise that acquires and owns the Intel(R) AMT system, as specified by the enterprise and provided in the application's registration.
			const string EnterpriseName() const;
			bool EnterpriseNameExists() const;
			// The number of bytes of storage currently allocated by the application.
			const unsigned int CurrentAllocationSize() const;
			bool CurrentAllocationSizeExists() const;
			// Set to TRUE if Intel(R) AMT has active session state for the application; otherwise this field is set to FALSE.
			const bool ActiveSession() const;
			bool ActiveSessionExists() const;
			// Set to TRUE if the application is in the Factory Partner Allocation List (FPACL), otherwise this field is set to FALSE.
			const bool Partner() const;
			bool PartnerExists() const;
		private:
		};

		// Get attributes of a third party application from the Intel(R) AMT device.
		virtual unsigned int AdminGetApplicationAttributes(const AdminGetApplicationAttributes_INPUT &input, AdminGetApplicationAttributes_OUTPUT &output);

		//Input parameter for function AdminRemoveApplication
		class CIMFRAMEWORK_API AdminRemoveApplication_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AdminRemoveApplication_INPUT() : CimParam() {}

			// Class Destructor
			~AdminRemoveApplication_INPUT(){}

			// Required, Handle of the application being removed.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Releases all Intel(R) AMT resources associated with a single ISV application. If the application owns any storage blocks, then they are released, along with any associated permissions group resources. The application is removed from all permissions groups associated with storage blocks that are owned by another application.
		virtual unsigned int AdminRemoveApplication(const AdminRemoveApplication_INPUT &input);

		//Input parameter for function AddStorageEaclEntry
		class CIMFRAMEWORK_API AddStorageEaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddStorageEaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~AddStorageEaclEntry_INPUT(){}

			// Required, An EACL entry to be added to the list.
			void EnterpriseName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddStorageEaclEntry
		class CIMFRAMEWORK_API AddStorageEaclEntry_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddStorageEaclEntry_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddStorageEaclEntry_OUTPUT(){}

			// class fields
			// The handle to the added EACL entry.
			const unsigned int Handle() const;
			bool HandleExists() const;
		private:
		};

		// Adds a new ISV Storage Enterprise Access Control List (EACL) entry and returns a handle that can be used in subsequent ISV Storage operations.
		virtual unsigned int AddStorageEaclEntry(const AddStorageEaclEntry_INPUT &input, AddStorageEaclEntry_OUTPUT &output);

		//Output parameter for function EnumerateStorageEaclEntries
		class CIMFRAMEWORK_API EnumerateStorageEaclEntries_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			EnumerateStorageEaclEntries_OUTPUT() : CimParam() {}

			// Class Destructor
			~EnumerateStorageEaclEntries_OUTPUT(){}

			// class fields
			// The list of the EACL entries handles.
			const vector<unsigned int> Handles() const;
			bool HandlesExists() const;
		private:
		};

		// Returns a list of ISV Storage Enterprise Access Control List (EACL) entry handles that can be used in subsequent ISV Storage operations.
		virtual unsigned int EnumerateStorageEaclEntries(EnumerateStorageEaclEntries_OUTPUT &output);

		//Input parameter for function GetStorageEaclEntry
		class CIMFRAMEWORK_API GetStorageEaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetStorageEaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~GetStorageEaclEntry_INPUT(){}

			// Required, Contains a handle to one of the EACL entries.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetStorageEaclEntry
		class CIMFRAMEWORK_API GetStorageEaclEntry_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetStorageEaclEntry_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetStorageEaclEntry_OUTPUT(){}

			// class fields
			// The requested EACL entry.
			const string EnterpriseName() const;
			bool EnterpriseNameExists() const;
		private:
		};

		// Returns a single ISV Storage Enterprise Access Control List (EACL) entry, given a handle returned by AddStorageEaclEntry or EnumerateStorageEaclEntries.
		virtual unsigned int GetStorageEaclEntry(const GetStorageEaclEntry_INPUT &input, GetStorageEaclEntry_OUTPUT &output);

		//Input parameter for function RemoveStorageEaclEntry
		class CIMFRAMEWORK_API RemoveStorageEaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemoveStorageEaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~RemoveStorageEaclEntry_INPUT(){}

			// Required, Contains a handle to one of the EACL entries.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Removes a single ISV Storage Enterprise Access Control List (EACL) entry, given a handle returned by AddStorageEaclEntry or EnumerateStorageEaclEntries. If an application using this Enterprise ACL entry has registered, then this operation will fail. The applications using the entry must be removed before the entry itself can be removed.
		virtual unsigned int RemoveStorageEaclEntry(const RemoveStorageEaclEntry_INPUT &input);

		//Input parameter for function AddStorageFpaclEntry
		class CIMFRAMEWORK_API AddStorageFpaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddStorageFpaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~AddStorageFpaclEntry_INPUT(){}

			// Required, The type of application attributes in this entry. This parameter should always have a value of 1.
			void AttrType(const unsigned int value); 

			// Required, Name of an ISV storage application.
			void ApplicationName(const string &value); 

			// Required, Name of the ISV vendor.
			void VendorName(const string &value); 

			// Required, This parameter should always have a value of TRUE, which indicates a partner application.
			void IsPartner(const bool value); 

			// Required, Maximum size, in bytes, of storage area an application of this type can allocate. Must be a multiple of 4KB.
			void TotalAllocationSize(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddStorageFpaclEntry
		class CIMFRAMEWORK_API AddStorageFpaclEntry_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddStorageFpaclEntry_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddStorageFpaclEntry_OUTPUT(){}

			// class fields
			// FPACL entry handle.
			const unsigned int Handle() const;
			bool HandleExists() const;
		private:
		};

		// Adds an entry to the ISV Storage Factory Partner Allocation Control List (FPACL). Non-partner allocation control list (NACL) entries cannot be added using this method. NACL entries are added when a non-partner application registers for the first time.
		virtual unsigned int AddStorageFpaclEntry(const AddStorageFpaclEntry_INPUT &input, AddStorageFpaclEntry_OUTPUT &output);

		//Output parameter for function EnumerateStorageAllocEntries
		class CIMFRAMEWORK_API EnumerateStorageAllocEntries_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			EnumerateStorageAllocEntries_OUTPUT() : CimParam() {}

			// Class Destructor
			~EnumerateStorageAllocEntries_OUTPUT(){}

			// class fields
			// Contains a list of FPACL or NACL entries handles.
			const vector<unsigned int> Handles() const;
			bool HandlesExists() const;
		private:
		};

		// Enumerates entries in the ISV Storage Factory Partner Allocation Control List (FPACL) and in the non-partner Allocation Control List.
		virtual unsigned int EnumerateStorageAllocEntries(EnumerateStorageAllocEntries_OUTPUT &output);

		//Input parameter for function GetStorageAllocEntry
		class CIMFRAMEWORK_API GetStorageAllocEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetStorageAllocEntry_INPUT() : CimParam() {}

			// Class Destructor
			~GetStorageAllocEntry_INPUT(){}

			// Required, Specifies the FPACL or NACL entry to fetch.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetStorageAllocEntry
		class CIMFRAMEWORK_API GetStorageAllocEntry_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetStorageAllocEntry_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetStorageAllocEntry_OUTPUT(){}

			// class fields
			// The type of application attributes in this entry. This parameter should always return a value of 1.
			const unsigned int AttrType() const;
			bool AttrTypeExists() const;
			// Name of an ISV storage application.
			const string ApplicationName() const;
			bool ApplicationNameExists() const;
			// Name of the ISV vendor.
			const string VendorName() const;
			bool VendorNameExists() const;
			// TRUE if this application is a partner application. FALSE otherwise.
			const bool IsPartner() const;
			bool IsPartnerExists() const;
			// Maximum size, in bytes, of storage area an application of this type can allocate.
			const unsigned int TotalAllocationSize() const;
			bool TotalAllocationSizeExists() const;
		private:
		};

		// Returns a single ISV Storage Factory Partner Allocation Control List (FPACL) or non-partner Allocation Control List (NACL) entry, given the entry's handle. FPACL entry handles are returned by the methods AddStorageFpaclEntry and EnumerateStorageAllocEntries. NACL entry handles are returned by EnumerateStorageAllocEntries.
		virtual unsigned int GetStorageAllocEntry(const GetStorageAllocEntry_INPUT &input, GetStorageAllocEntry_OUTPUT &output);

		//Input parameter for function UpdateStorageFpaclEntry
		class CIMFRAMEWORK_API UpdateStorageFpaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdateStorageFpaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~UpdateStorageFpaclEntry_INPUT(){}

			// Required, Handle of the FPACL entry to update.
			void Handle(const unsigned int value); 

			// Required, Specifies the new maximum size, in bytes, of storage area that an application of this type can allocate. The size must be a multiple of 4KB.
			void NewAllocationSize(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Updates the allocation size of an existing entry in the ISV Storage Factory Partner Allocation Control List (FPACL), given the entry's handle and the new size. FPACL entry handles are returned by the methods AddStorageFpaclEntry and EnumerateStorageAllocEntries. If the method increases the allowed allocation size, then it will succeed. Decreasing the size will only succeed if the currently allocated size for this application does not exceed the new size. Note: Non-partner allocation control list (NACL) entries cannot be updated using this function. The allowed allocation size for non-partner applications can be set using the SetGlobalStorageAttributes method.
		virtual unsigned int UpdateStorageFpaclEntry(const UpdateStorageFpaclEntry_INPUT &input);

		//Input parameter for function RemoveStorageFpaclEntry
		class CIMFRAMEWORK_API RemoveStorageFpaclEntry_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemoveStorageFpaclEntry_INPUT() : CimParam() {}

			// Class Destructor
			~RemoveStorageFpaclEntry_INPUT(){}

			// Required, Handle of the FPACL entry to be removed.
			void Handle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This function removes an entry from the ISV Storage Factory Partner Allocation Control List (FPACL), given the entry's handle. FPACL entry handles are returned by the methods AddStorageFpaclEntry and EnumerateStorageAllocEntries. If an application using this FPACL entry has registered, then this operation will fail. The applications using the entry must be removed before the entry itself can be removed. Note: Non-partner allocation control list (NACL) entries cannot be removed using this function. NACL entries are removed when all application instances of the non-partner application are removed from the device.
		virtual unsigned int RemoveStorageFpaclEntry(const RemoveStorageFpaclEntry_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ThirdPartyDataStorageAdministrationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ThirdPartyDataStorageAdministrationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ThirdPartyDataStorageAdministrationService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // AMT_THIRDPARTYDATASTORAGEADMINISTRATIONSERVICE_H
