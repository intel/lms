;//  SPDX-License-Identifier: Apache-2.0
;//  Copyright (C) Intel Corporation, 2003 - 2019.
;//
;//  File:       UNSEventsCnf.mc 
;//
;//  Contents:   User Notification Event Log message DLL.
;//
;//  Notes:      
;//
;//----------------------------------------------------------------------------

;// ---------------------------------------------------------------------------
;// HEADER SECTION
;// ---------------------------------------------------------------------------

MessageIdTypedef=uint16_t

SeverityNames=(	Success=0x0:STATUS_SEVERITY_SUCCESS
				Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
				Warning=0x2:STATUS_SEVERITY_WARNING
				Error=0x3:STATUS_SEVERITY_ERROR)

LanguageNames=(All=0x000:MSG00001)

;#ifndef EVENT_LOG_MESSAGE_DLL
;#define EVENT_LOG_MESSAGE_DLL


;//**********************Category Definitions***********************

MessageId=1
Facility=Application
Severity=Success
SymbolicName=UNS_WLAN
Language=All
WLAN
.

MessageId=2
Facility=Application
Severity=Success
SymbolicName=UNS_REMOTE_DIAGNOSTIC
Language=All
Remote Diagnostics
.


MessageId=3
Facility=Application
Severity=Success
SymbolicName=UNS_GENERAL
Language=All
LMS
.

MessageId=4
Facility=Application
Severity=Success
SymbolicName=UNS_CIRCUIT_BREAKER
Language=All
System Defense
.

MessageId=6
Facility=Application
Severity=Success
SymbolicName=UNS_REMOTE_PWR
Language=All
Remote Power Operation
.

;//********************End of Category Definitions*******************

MessageIdTypedef=uint32_t

;//***********************Event Definitions******************************

MessageId=1001
Facility=Application
Severity=Informational
SymbolicName=NETWORK_TRAFFIC_TX_CEASED
Language=All
Security policy invoked. Some or all network traffic (TX) was stopped.
.

MessageId=1002
Facility=Application
Severity=Informational
SymbolicName=NETWORK_CONNECTIVITY_TX_REDUCED
Language=All
Security policy invoked. TX Network connectivity was reduced.
.

MessageId=1003
Facility=Application
Severity=Informational
SymbolicName=NETWORK_TRAFFIC_RX_CEASED
Language=All
Security policy invoked. Some or all network traffic (RX) was stopped.
.

MessageId=1004
Facility=Application
Severity=Informational
SymbolicName=NETWORK_CONNECTIVITY_RX_REDUCED
Language=All
Security policy invoked. RX Network connectivity was reduced.
.

MessageId=1101
Facility=Application
Severity=Informational
SymbolicName=WLAN_WIRELESS_PROFILE_STATE_CHANGED
Language=All
WLAN Wireless Profile sync enablement state changed. 
.

MessageId=1102
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROFILE_INSUFFICIENT
Language=All
WLAN Profile insufficient for management session over WLAN interface. 
.

MessageId=1103
Facility=Application
Severity=Informational
SymbolicName=WLAN_SECURITY_INSUFFICIENT
Language=All
Security parameters insufficient for management session over WLAN interface.
.

MessageId=1104
Facility=Application
Severity=Informational
SymbolicName=WLAN_SESSION_ESTABLISHED
Language=All
Control preference for WLAN interface assigned to Intel(R) Manageability Engine. Intel(R) ME will take control of WLAN interface when it is able.
.

MessageId=1105
Facility=Application
Severity=Informational
SymbolicName=WLAN_SESSION_ENDED
Language=All
Control preference for WLAN interface assigned to operating system. Operating system will take control of WLAN interface when it is able.
.

MessageId=1106
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROFILE_SYNC_DISABLE
Language=All
Wireless Profile sync enablement state is disabled.

.

MessageId=1107
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROFILE_SYNC_ENABLE
Language=All
Wireless Profile sync enablement state is enabled.
.

MessageId=1201
Facility=Application
Severity=Informational
SymbolicName=REMOTE_SOL_STARTED
Language=All
A remote Serial Over LAN session was established.
.

MessageId=1202
Facility=Application
Severity=Informational
SymbolicName=REMOTE_SOL_ENDED
Language=All
Remote Serial Over LAN session finished. User control was restored.
.

MessageId=1203
Facility=Application
Severity=Informational
SymbolicName=REMOTE_USBR_STARTED
Language=All
A remote USB-Redirection session was established.
.

MessageId=1204
Facility=Application
Severity=Informational
SymbolicName=REMOTE_USBR_ENDED
Language=All
Remote USB-Redirection session finished. User control was restored.
.

MessageId=1210
Facility=Application
Severity=Informational
SymbolicName=AGENT_PRSENCE_NOT_STARTED
Language=All
Local Software Monitor has detected that agent %1
.

MessageId=1211
Facility=Application
Severity=Warning
SymbolicName=AGENT_PRSENCE_STOPED
Language=All
Local Software Monitor has detected that agent %1
.

MessageId=1212
Facility=Application
Severity=Warning
SymbolicName=AGENT_PRSENCE_EXPIRED
Language=All
Local Software Monitor has detected that agent %1
.

MessageId=2000
Facility=Application
Severity=Informational
SymbolicName=UNS_INFO_MESSAGE
Language=All
%1
.

MessageId=2001
Facility=Application
Severity=Warning
SymbolicName=UNS_WARNING_MESSAGE
Language=All
%1
.

MessageId=2002
Facility=Application
Severity=Error
SymbolicName=UNS_ERROR_MESSAGE
Language=All
%1
.

MessageId=2050
Facility=Application
Severity=Warning
SymbolicName=UNS_NETWORK_SYNC_UPDATE_FAILED
Language=All
Failed to update Intel(R) ME firmware with new network configuration.
.

MessageId=2051
Facility=Application
Severity=Informational
SymbolicName=UNS_NETWORK_SYNC_VALIDATION_FAILED
Language=All
Failed to verify that the new network configuration is valid and did not update the Intel(R) ME firmware with the configuration.
.

MessageId=2100
Facility=Application
Severity=Success
SymbolicName=PFW_UPGRADE_SUCCESS_WLAN
Language=All
Intel(R) ME Wireless LAN uCode updated successfully.
.

MessageId=2101
Facility=Application
Severity=Success
SymbolicName=PFW_UPGRADE_SUCCESS_LANG
Language=All
Intel(R) ME User Consent language updated successfully.
.

MessageId=2102
Facility=Application
Severity=Warning
SymbolicName=PFW_UPGRADE_FAILURE_WLAN
Language=All
Intel(R) ME Wireless LAN update unsuccessful, error %1
.

MessageId=2103
Facility=Application
Severity=Warning
SymbolicName=PFW_UPGRADE_FAILURE_LANG
Language=All
Intel(R) ME User Consent language update unsuccessful, error %1
.

MessageId=2104
Facility=Application
Severity=Warning
SymbolicName=MISSING_IMAGE_FILE_WLAN
Language=All
Intel(R) ME Wireless LAN uCode update unsuccessful, due to missing image file.
.

MessageId=2105
Facility=Application
Severity=Warning
SymbolicName=MISSING_IMAGE_FILE_LANG
Language=All
Intel(R) ME User Consent language update unsuccessful, due to missing image file.
.

MessageId=2106
Facility=Application
Severity=Informational
SymbolicName=IP_REFRESH_REQUESTED_LAN
Language=All
DHCP IP address for LAN interface has been renewed.
.

MessageId=2107
Facility=Application
Severity=Informational
SymbolicName=IP_REFRESH_REQUESTED_WLAN
Language=All
DHCP IP address for WLAN interface has been renewed.
.

MessageId=2108
Facility=Application
Severity=Informational
SymbolicName=ALARM_CLOCK_REBOOT
Language=All
Local Maintenance Timer has awoken the system from %1
.

MessageId=2109
Facility=Application
Severity=Informational
SymbolicName=WLAN_CONTROL_HOST
Language=All
WLAN Link Control set to Host (Operating system)
.

MessageId=2110
Facility=Application
Severity=Informational
SymbolicName=WLAN_CONTROL_ME
Language=All
WLAN Link Control set to Intel(R) ME
.

MessageId=2111
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROTECTION_ON_HIGH
Language=All
Intel(R) ME WLAN Link Protection is ON (HIGH)
.

MessageId=2112
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROTECTION_ON_PASSIVE
Language=All
Intel(R) ME WLAN Link Protection is ON (PASSIVE)
.

MessageId=2113
Facility=Application
Severity=Informational
SymbolicName=WLAN_PROTECTION_OFF
Language=All
Intel(R) ME WLAN Link Protection is OFF
.

MessageId=2114
Facility=Application
Severity=Informational
SymbolicName=REMOTE_GRACEFUL_SHUTDOWN_SUCCEED
Language=All
Remote administrator shutdown request was executed
.

MessageId=2115
Facility=Application
Severity=Informational
SymbolicName=REMOTE_GRACEFUL_SHUTDOWN_FAILED
Language=All
Remote administrator shutdown request failed with error %1
.

MessageId=2116
Facility=Application
Severity=Informational
SymbolicName=REMOTE_GRACEFUL_REBOOT_SUCCEED
Language=All
Remote administrator reboot request was executed
.

MessageId=2117
Facility=Application
Severity=Informational
SymbolicName=REMOTE_GRACEFUL_REBOOT_FAILED
Language=All
Remote administrator reboot request failed with error %1
.

MessageId=2118
Facility=Application
Severity=Informational
SymbolicName=REMOTE_SLEEP
Language=All
Sleep operation was requested by remote administrator 
.

MessageId=2119
Facility=Application
Severity=Informational
SymbolicName=REMOTE_HIBERNATE
Language=All
Hibernate operation was requested by remote administrator 
.

MessageId=2120
Facility=Application
Severity=Informational
SymbolicName=REMOTE_SLEEP_FAILED
Language=All
Remote administrator sleep request failed with error %1 
.

MessageId=2121
Facility=Application
Severity=Informational
SymbolicName=REMOTE_HIBERNATE_FAILED
Language=All
Remote administrator hibernate request failed with error %1 
.

MessageId=2122
Facility=Application
Severity=Warning
SymbolicName=FW_FATAL_ERROR
Language=All
Intel(R) Management Engine (Intel(R) ME) error(s) occurred. Please review Intel(R) ME logs.
.

MessageId=2123
Facility=Application
Severity=Informational
SymbolicName=KVM_SESSION_STARTED
Language=All
KVM Session has been started.
.

MessageId=2124
Facility=Application
Severity=Informational
SymbolicName=KVM_SESSION_STOPPED
Language=All
KVM Session has been stopped.
.

MessageId=2125
Facility=Application
Severity=Warning
SymbolicName=PORT_FORWARDING_SERVICE_UNAVAILABLE
Language=All
Port Forwarding Service failed
.

MessageId=2126
Facility=Application
Severity=Informational
SymbolicName=AMT_DISABLE_ATTEMPT
Language=All
Intel(R) AMT disable attempt detected
.

;//***********************End of Event Definitions***********************

;#endif
