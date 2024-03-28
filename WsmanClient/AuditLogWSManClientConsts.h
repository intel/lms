/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2023 Intel Corporation
 */
 /*++

 @file: AuditLogWSManClientConsts.h

 --*/
#include <string>

 //Audit-Log Record User Method.
typedef enum _InitiatorType
{
	HTTP_DIGEST = 0,
	KERBEROS_SID = 1,
	LOCAL_INITIATOR = 2,
	KVM_DEFAULT_PORT = 3
} InitiatorType;

// Audit-Log Record Address Type
typedef enum _AddressType
{
	IPV4_ADDR = 0,
	IPV6_ADDR = 1,
	NON = 2
} AddressType;


/*
Events and APPID description
https://software.intel.com/sites/manageability/AMT_Implementation_and_Reference_Guide/default.htm?turl=WordDocuments%2Fdetaileddescription2.htm
*/

/* Auditable Events - Application ID */
typedef enum _Appid
{
	SECURITY_ADMIN_APPID = 16,
	RCO_APPID = 17,
	REDIR_MANAGER_APPID = 18,
	FIRMWARE_UPDATE_MANAGER_APPID = 19,
	SECURITY_AUDIT_LOG_APPID = 20,
	NETWORK_TIME_APPID = 21,
	NETWORK_ADMIN_APPID = 22,
	STORAGE_ADMIN_APPID = 23,
	EVENT_MANAGER_APPID = 24,
	CB_MANAGER_APPID = 25,
	AGENT_PRESENCE_MANAGER_APPID = 26,
	WIRELESS_CONFIG_APPID = 27,
	EAC_APPID = 28,
	KVM_APPID = 29,
	USER_OPT_IN_APPID = 30,
	BIOS_MANAGEMENT_APPID = 31,
	SCREEN_BLANKING = 32,
	WATCHDOG_APPID = 33,
}Appid;

const static unsigned int APP_ID_START_INDEX = 16;
const static unsigned int APP_ID_END_INDEX = 33;
const static unsigned int NUM_APPS = APP_ID_END_INDEX - APP_ID_START_INDEX + 1;

const static std::string appIdStrings[NUM_APPS] = { "Security Admin", "RCO", "Redirection Manager",
									  "Firmware Update Manager","Security Audit Log",
									  "Network Time","Network Administration",
									  "Storage Administration","Event Manager",
									  "System Defense Manager", "Agent Presence Manager",
									  "Wireless Configuration","EAC","KVM", "User Opt-In",
									  "BIOS Management", "Screen Blanking", "Watchdog" };

// Holds the final index of each id per event group
const static unsigned int endStringsArrayIndices[NUM_APPS] = { 20, 10, 13, 2, 6, 3, 6, 4, 4, 7, 3, 6, 5, 5, 3, 0, 2, 2 };

const static std::string eventIdStrings[] = {/*Security*/
										"Provisioning Started", // Removed - Intel(R) AMT 
										"Provisioning Completed",
										"ACL Entry Added",
										"ACL Entry Modified","ACL Entry Removed","ACL Access with invalid credentials",
										"ACL Entry Enabled","TLS State Changed","TLS Server Certificate Set",
										"TLS Server Certificate Remove","TLS Trusted Root Certificate Added",
										"TLS Trusted Root Certificate Removed","TLS Pre-shared Key Set",
										"Kerberos Settings Modified","Kerberos MasterKey or Passphrase Modified",
										"Flash Wear-Out Counters Reset","Power Package Modified",
										"Set realm Authentication mode","Upgrade from client to admin control mode",
										"UnProvisioning Started",
										/*RCO*/
										"Performed Power-Up","Performed Power-Down","Performed Power-Cycle",
										"Performed Reset","Set Boot Options", "Performed Graceful Power down",
										"Performed Graceful Power reset", "Performed Standby", "Performed Hiberate",
										"Performed NMI",
										/*REDIR*/
										"USBr Session Opened","USBr Session Closed ","USBr Enabled",
										"USBr Disabled","SoL Session Opened","SoL Session Closed",
										"SoL Enabled","SoL Disabled","KVM Session Started",
										"KVM Session Ended","KVM Enabled","KVM Disabled",
										"VNC Password Failed 3 Times",
										/*FW Update*/
										"Firmware Update Started","Firmware Update Failed",
										/*Audit Log*/
										"Security Audit Log Cleared","Security Audit policy modified",
										"Security Audit Log Disabled","Security Audit Log Enabled",
										"Security Audit Log Exported", "Security Audit Log Recovery",
										/*Network Time*/
										"Time Set",// Removed - Intel(R) AMT
										"Time Synchronization Enabled", "Time Synchronization Disabled",
										/*Network Admin*/
										"TCP/IP Parameters Set","Host Name Set","Domain Name Set",
										"VLAN Parameters Set","Link Policy Set","IPv6 parameters Set",
										/*Storage Admin*/
										"Global Storage Attributes Set","Storage EACL Modified",
										"Storage FPACL Modified","Storage Write Operation",
										/*Event Manager*/
										"Alert Subscribed","Alert Unsubscribed","Event Log Cleared",
										"Event Log Frozen",
										/*SD*/
										"SD Filter Added","SD Filter Removed","SD Policy Added",
										"SD Policy Removed","SD Default Policy Set","SD Heuristics Option Set",
										"SD Heuristics State Cleared",
										/*AP*/
										"Agent Watchdog Added","Agent Watchdog Removed",
										"Agent Watchdog Action set",
										/*Wireless*/
										"Wireless Profile Added","Wireless Profile Removed",
										"Wireless Profile Updated", "Wireless local Profile Sync Enablement changed" ,
										"Wireless Link Preference Changed", "Wireless profile share with UEFI enabled setting changed",
										/*EAC*/
										"EAC Posture Signer SET","EAC Enabled","EAC Disabled",
										"EAC Posture State Update","EAC Set Options",
										/*KVM*/
										"KVM opt-in Enabled","KVM opt-in Disabled","KVM password Changed",
										"KVM consent succeeded","KVM consent failed",
										/*User Opt-In*/
										"Opt-In policy Change",
										"Send Consent Code Event",
										"attempted to send a StartOptIn request, but the request was blocked",
										/* Screen Blanking */
										"Screen blanking start",
										"Screen blanking end",
										/* Watchdog */
										"Watchdog action settings have been changed.",
										"A Watchdog's action has been set, cleared, or changed.",

};

const static std::string realmsStrings[] = { "InvalidRealm","ReservedRealm","RedirectionRealm",
									  "PTAdministrationRealm","HardwareAssetRealm",
									  "RemoteControlRealm","StorageRealm",
									  "EventManagerRealm","StorageAdminRealm",
									  "AgentPresenceLocalRealm", "AgentPresenceRemoteRealm",
									  "SystemDefenseRealm","NetworkTimeRealm",
									  "GeneralInfoRealm","FirmwareUpdateRealm",
									  "EITRealm","LocalUN","EndpointAccessControlRealm",
									  "EndpointAccessControlAdminRealm", "EventLogReaderRealm",
									  "SecurityAuditLogRealm", "UserAccessControlRealm", "WoxRealm" };

const static std::string powerPolicyStrings[] = { "Mobile: ON in S0",									"Mobile: ON in S0, S3/AC",
											"Mobile: ON in S0, S3/AC, S4-5/AC",					"Mobile: ON in S0, ME Wake in S3/AC",
											"Mobile: ON in S0, ME Wake in S3/AC, S4-5/AC",		"Desktop: ON in S0",
											"Desktop: ON in S0, S3",							"Desktop: ON in S0, S3, S4-5",
											"Desktop: ON in S0, ME Wake in S3",					"Desktop: ON in S0, ME Wake in S3, S4-5",
											"Desktop: ON in S0, S3, S4-5, OFF After Power Loss","Desktop: ON in S0, ME Wake in S3, S4-5, OFF After Power Loss" };

const static std::string powerPolicyFW[] = { "763997110B56504388709812F391B560", "26D31C768708C74BBB5F38744315A5FF",
										"530E08DB6C0FD948B2D28958D3F1156E", "055DD5B64CA4874DA5A8B47C14DEDA5F",
										"30800DEE09C07843AF287868A2DBBE3A", "944F8312FB104FDC968E1E232B0C9065",
										"A18600AB9A7F4C42A6E6BB243A295D9E", "7286ABAC96B448E29B9E9B7DF91C7FD4",
										"7B32CD4D6BBE4389A62A4D7BD8DBD026", "7322734623DC432FA98A13D37982D855",
										"C519A4BA6E6F8D4DB227517F7E4595DB", "D60BE3ED04C52C46B772D18018EE2FC4" };


const static unsigned int MAX_REALM = 22;

typedef enum _SecAdminEventID
{
	AMT_PROVISIONING_STARTED = 0,
	AMT_PROVISIONING_COMPLETED = 1,
	ACL_ENTRY_ADDED = 2,
	ACL_ENTRY_MODIFIED = 3,
	ACL_ENTRY_REMOVED = 4,
	ACL_ACCESS_WITH_INVALID_CREDENTIALS = 5,
	ACL_ENTRY_ENABLED = 6,
	TLS_STATE_CHANGED = 7,
	TLS_SERVER_CERTIFICATE_SET = 8,
	TLS_SERVER_CERTIFICATE_REMOVE = 9,
	TLS_TRUSTED_ROOT_CERTIFICATE_ADDED = 10,
	TLS_TRUSTED_ROOT_CERTIFICATE_REMOVED = 11,
	TLS_PRE_SHARED_KEY_SET = 12,
	KERBEROS_SETTINGS_MODIFIED = 13,
	KERBEROS_MASTER_KEY_MODIFIED = 14,
	FLASH_WEAR_OUT_COUNTERS_RESET = 15,
	POWER_PACKAGE_MODIFIED = 16,
	SET_REALM_AUTHENTICATION_MODE = 17,
	UPGRADE_CLIENT_TO_ADMIN = 18,
	UNPROVISIONING_COMPLETED = 19
} SecAdminEventID;

typedef enum _RcoEventID
{
	PERFORMED_POWER_UP = 0,
	PERFORMED_POWER_DOWN = 1,
	PERFORMED_POWER_CYCLE = 2,
	PERFORMED_RESET = 3,
	SET_BOOT_OPTIONS = 4
}RcoEventID;

typedef enum _FirmwareUpdateEventID
{
	FIRMWARE_UPDATED = 0,
	FIRMWARE_UPDATED_FAILED = 1
}FirmwareUpdateEventID;

typedef enum _SecurityAuditLogEventID
{
	AUDIT_LOG_CLEARED = 0,
	AUDIT_LOG_MODIFIED = 1,
	AUDIT_LOG_DISABLED = 2,
	AUDIT_LOG_ENABLED = 3,
	AUDIT_LOG_EXPORTED = 4,
	AUDIT_LOG_RECOVERY = 5
}AuditEventID;

const static unsigned short MAX_SECURITY_AUDIT_RECOVERY_REASON = 2;

const static std::string securityAuditLogRecoveryReason[] = { "Unknown",
														"Migration failure",
														"Initialization failure" };

const static uint8_t MAX_INTERFACE_ID_GEN_TYPE_STRINGS = 3;
const static std::string interfaceIDGenTypeStrings[] = { "Random ID", "Intel ID", "Manual ID", "Invalid ID" };

typedef enum _NetworkTimeEventID
{
	AMT_TIME_SET = 0
}NetworkTimeEventID;

typedef enum _NetworkAdminEventID
{
	TCPIP_PARAMETERS_SET = 0,
	HOST_NAME_SET = 1,
	DOMAIN_NAME_SET = 2,
	VLAN_PARAMETERS_SET = 3,
	LINK_POLICY_SET = 4,
	IPV6_PARAMS_SET = 5
}NetworkAdminEventID;

typedef enum _StorageAdminEventID
{
	GLOBAL_STORAGE_ATTRIBUTES_SET = 0,
	STORAGE_EACL_MODIFIED = 1,
	STORAGE_FPACL_MODIFIED = 2,
	STORAGE_WRITE_OPERATION = 3
}StorageAdminEventID;

typedef enum _EventManagerEventID
{
	ALERT_SUBSCRIBED = 0,
	ALERT_UNSUBSCRIBED = 1,
	EVENT_LOG_CLEARED = 2,
	EVENT_LOG_FROZEN = 3
}EventManagerEventID;

typedef enum _CbManagerEventID
{
	CB_FILTER_ADDED = 0,
	CB_FILTER_REMOVE = 1,
	CB_POLICY_ADDED = 2,
	CB_POLICY_REMOVE = 3,
	CB_DEFAULT_POLICY_SET = 4,
	CB_HEURISTICS_OPTION_SET = 5,
	CB_HEURISTICS_STATE_CLEARED = 6
}CbManagerEventID;

typedef enum _AgentPresenceManagerEventID
{
	AGENT_WATCHDOG_ADDED = 0,
	AGENT_WATCHDOG_REMOVED = 1,
	AGENT_WATCHDOG_ACTION_SET = 2
}AgentPresenceManagerEventID;

typedef enum _WirelessConfigurationEventID
{
	WIRELESS_PROFILE_ADDED = 0,
	WIRELESS_PROFILE_REMOVED = 1,
	WIRELESS_PROFILE_UPDATED = 2,
	WIRELESS_PROFILE_SYNC = 3,
	WIRELESS_LINK_PREFERENCE_CHANGED = 4,
	WIRELESS_UEFI_PROFILE_SYNC = 5
}WirelessConfigurationEventID;

typedef enum _EACEventID
{
	EAC_POSTURE_SIGNER_SET = 0,
	EAC_ENABLED = 1,
	EAC_DISABLED = 2,
	EAC_POSTURE_STATE_UPDATE = 3,
	EAC_SET_OPTIONS = 4
}EACEventID;

typedef enum _UserOptInEventID
{
	OPT_IN_POLICY_CHANGE = 0,
	SEND_CONSENT_CODE_EVENT = 1,
	START_OPT_IN_BLOCKED_EVENT = 2
}UserOptInEventID;

typedef enum WatchdogEventID_
{
	WEI_WATCHDOG_RESET_TRIGGERING_OPTIONS_CHANGED = 1,
	WEI_WATCHDOG_ACTION_PAIRING_CHANGED = 2,
} WatchdogEventID;


typedef enum _ProvisioningMethod
{
	PSK = 1,
	PKI = 2,
	MANUAL_PROVISIONING = 3,
	ACM = 5,
	DAL_PROVISIONING = 6
}ProvisioningMethod;

typedef enum _HashType
{
	SHA1_160 = 1,
	SHA2_256 = 2,
	SHA2_384 = 3,
	SHA2_512 = 4
}TrustedRootHashType;

typedef enum _InvalidCredentialsType
{
	AMT_TYPE = 0,
	MEBX_TYPE = 1
}InvalidCredentialsType;

typedef enum _TlsStatus
{
	NO_AUTHENTICATION = 0,
	SERVER_AUTHENTICATION = 1,
	MUTUAL_AUTHENTICATION = 2
}TlsStatus;

typedef enum _AuthenticationMode
{
	NO_AUTHEN = 0,
	AUTHENTICATION = 1,
	DISABLE = 2
}AuthenticationMode;

typedef enum _SubscriptionAlertType
{
	SNMP = 1,
	SOAP = 2
}SubscriptionAlertType;

typedef enum _localProfileSyncEnablement
{
	PROFILE_SYNC_DISABLED,
	PROFILE_SYNC_USER,
	PROFILE_SYNC_ADMIN,
	PROFILE_SYNC_UNRESTRICTED
} localProfileSyncEnablement;

typedef enum _LinkPreferenceChangedType
{
	LINK_PREFERENCE_ME = 1,
	LINK_PREFERENCE_HOST = 2
}LinkPreferenceChangedType;

typedef enum _UEFIWiFiProfileShareEnabled
{
	UEFI_WIFI_PROFILE_SHARE_DISABLED = 0,
	UEFI_WIFI_PROFILE_SHARE_ENABLED = 1
}UEFIWiFiProfileShare;

typedef enum _EventLogFreezeType
{
	UNFREEZE = 0,
	FREEZE = 1
}EventLogFreezeType;

typedef enum _InterfaceIDGenType
{
	RANDOM_ID = 0,
	INTEL_ID = 1,
	MANUAL_ID = 2,
	INVALID_ID = 3
}InterfaceIDGenType;

typedef enum _PasswordEnterResultType
{
	SUCCESFUL_TYPE = 0,
	UNSUCCESFUL_TYPE = 1
}PasswordEnterResultType;

// Extended Data Consts
const uint8_t SSID_LEN = 32;
const uint8_t TRUSTED_ROOT_CERT_SHA1_160_HASH_LEN = 20;
const uint8_t TRUSTED_ROOT_CERT_SHA2_256_HASH_LEN = 32;
const uint8_t TRUSTED_ROOT_CERT_SHA2_384_HASH_LEN = 48;
const uint8_t TRUSTED_ROOT_CERT_SHA2_512_HASH_LEN = 64;
const uint8_t CERT_SERIAL_NUM_LEN = 16;
const uint8_t CERT_SERIAL_NUM_MAX_LEN = 20;
const uint8_t BOOT_OPTIONS_LEN = 7;
const uint8_t AGENT_ID_LEN = 16;
const uint8_t FW_VERSION_NUM_OF_FIELDS = 4;
const uint8_t INTERFCAE_ID_LEN = 8;

const static char* PSK_STRING = "PSK";
const static char* PKI_STRING = "PKI";
const static char* MANUAL_STRING = "Manual";
const static char* ACM_STRING = "ACM";
const static char* DAL_STRING = "DAL";
const static char* AMT_TYPE_STRING = "Intel(R) AMT";
const static char* MEBX_TYPE_STRING = "Intel(R) MEBx";
const static char* NO_AUTHENTICATION_STRING = "No authentication";
const static char* SERVER_AUTHENTICATION_STRING = "Server Authentication";
const static char* MUTUAL_AUTHENTICATION_STRING = "Mutual Authentication";
const static char* AUTHENTICATION_STRING = "Authentication";
const static char* SNMP_STRING = "SNMP";
const static char* SOAP_STRING = "SOAP";
const static char* UNFREEZE_STRING = "UnFreeze";
const static char* FREEZE_STRING = "Freeze";
const static char* SUCCESSFUL_PASSWORD_STRING = "Remote operator entered a one-time password successfully";
const static char* UNSUCCESSFUL_PASSWORD_STRING = "Remote operator failed (3 times) to enter a one-time password correctly";

const uint8_t NUMBER_OF_LINK_POLICIES = 4;

const std::string LinkPolicyValues[] =
{ "available on S0 AC", "available on Sx AC", "available on S0 DC", "available on Sx DC" };

const uint32_t NUMBER_OF_EAC_VENDOR_STRINGS = 4;
const std::string EACVendors[] = { "Unknown", "EAC NAC", "EAC NAP", "EAC NAC and NAP" };