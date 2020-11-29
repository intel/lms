/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: UNSEventsDefinition.h

--*/

//----------------------------------------------------------------------------
//
//  Notes:      Define the event that LMS publishes
//----------------------------------------------------------------------------

#ifndef _UNS_EVENT_DEFENITION_H
#define _UNS_EVENT_DEFENITION_H

#define CATEGORY_GENERAL						  1
#define CATEGORY_CIRCUIT_BREAKER				  2
#define CATEGORY_EAC							  3
#define CATEGORY_REMOTE_DIAGNOSTIC				  4
#define CATEGORY_WLAN							  5
#define CATEGORY_SECIO							  6
#define CATEGORY_KVM							  7
#define CATEGORY_RCS							  8
#define CATEGORY_UNS							  9
#define CATEGORY_IPSYNC							 10
#define CATEGORY_PROXY							 11
#define CATEGORY_USER_CONSENT					 13
#define CATEGORY_PARTIAL_FW_UPDATE				 14
#define CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION 15
#define CATEGORY_TIMESYNC						 16


///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_GENERAL_DEFAULT					0
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_GENERAL_NOTIFICATION				10
#define EVENT_PROVISIONING_STATE_PRE			11
#define EVENT_PROVISIONING_STATE_IN				12
#define EVENT_PROVISIONING_STATE_POST			13
#define EVENT_NETWORK_STATE_CHANGE 				14
#define EVENT_UNPROVISIONES_STARTED				15
#define EVENT_CONTROL_MODE_CHANGE				16 
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_ALARM_CLOCK_BOOT					18
#define EVENT_REMOTE_REBOOT						19
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_NETWORK_TRAFFIC_TX_CEASED			20
#define EVENT_NETWORK_CONNECTIVITY_TX_REDUCED	21
#define EVENT_NETWORK_TRAFFIC_RX_CEASED			22
#define EVENT_NETWORK_CONNECTIVITY_RX_REDUCED	23
#define EVENT_SYSTEM_DEFENCE_CHANGE				24
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_EAC_NOTIFICATION					30
#define EVENT_EAC_ENABLED						31 
#define EVENT_EAC_DISABLED						32 
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_REMOTE_SOL_STARTED				40
#define EVENT_REMOTE_SOL_ENDED					41
#define EVENT_REMOTE_IDER_STARTED				42
#define EVENT_REMOTE_IDER_ENDED					43
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_WLAN_PROTECTION_ON_HIGH			47
#define EVENT_WLAN_PROTECTION_ON_PASSIVE		48
#define EVENT_WLAN_PROTECTION_OFF				49
#define EVENT_WLAN_PROFILE_INSUFFICIENT			50
#define EVENT_WLAN_SECURITY_INSUFFICIENT		51
#define EVENT_WLAN_SESSION_ESTABLISHED			52
#define EVENT_WLAN_SESSION_ENDED				53
#define EVENT_WIRELESS_STATE_CHANGED			54
#define EVENT_WLAN_PROFILE_SYNC_DISABLE 		55
#define EVENT_WLAN_PROFILE_SYNC_ENABLE			56
#define EVENT_WLAN_CONTROL_ME					57
#define EVENT_WLAN_CONTROL_HOST					58
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_SECIO_SEMAPHORE_AT_HOST			60
#define EVENT_SECIO_SEMAPHORE_AT_ME				61
#define EVENT_SECIO_SEMAPHORE_TIMEOUT			62
#define EVENT_SECIO_CONFIGURATION_EVENT			63
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_KVM_SESSION_REQUESTED				70
#define EVENT_KVM_SESSION_STARTED				71
#define EVENT_KVM_SESSION_STOPPED				72
#define EVENT_KVM_DISABLED						73
#define EVENT_KVM_ENABLED						74
#define EVENT_KVM_SCREEN_SETTING_UPDATE	        75 
#define EVENT_KVM_DATA_CHANNEL					76 
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_RCS_TUNNEL_CLOSE					84
#define EVENT_RCS_TUNNEL_OPEN					85
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_SERVICE_RESUME						92
#define EVENT_SERVICE_HECI_ENABLE					93
#define EVENT_SERVICE_HECI_DISABLE					94
#define EVENT_PORT_FORWARDING_SERVICE_AVAILABLE		95
#define EVENT_PORT_FORWARDING_SERVICE_UNAVAILABLE	96
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_IP_SYNC_DISABLE 					110
#define EVENT_IP_SYNC_ENABLE					111
///////////////////////////////////////////////////////////////////////////////////////////////////
// LMS extended events
#define EVENT_PROVISIONING						112 // 1 112
#define EVENT_UNPROVISIONING					113 // 1 113
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_IP_REFRESH_REQUESTED_LAN			114
#define EVENT_IP_REFRESH_REQUESTED_WLAN			115
#define EVENT_IP_SYNC_FW_UPDATE_FAILED			116
#define EVENT_IP_SYNC_VALIDATION_FAILED			117
#define EVENT_IP_REFRESH_LAN					118
#define EVENT_IP_REFRESH_WLAN					119
#define EVENT_PROXY_SYNC_DISABLE 				120
#define EVENT_PROXY_SYNC_ENABLE					121
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_USER_CONSENT_ENDED 					130
#define EVENT_USER_CONSENT_GRANTED 					131
#define EVENT_USER_CONSENT_REQUESTED 				132
#define EVENT_USER_CONSENT_TIMEOUT_STARTED 			133
#define EVENT_USER_CONSENT_CONFIGURATION_CHANGED	134  
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_PARTIAL_FWU_BEGIN						140
#define EVENT_PARTIAL_FWU_END_SUCCESS_WLAN			141
#define EVENT_PARTIAL_FWU_END_SUCCESS_LANG			142
#define EVENT_PARTIAL_FWU_END_FAILURE_WLAN			143
#define EVENT_PARTIAL_FWU_END_FAILURE_LANG			144
#define EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN		145
#define EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG		146
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_ME_ENABLE		 					150
#define EVENT_ME_DISABLE		 				151
#define EVENT_AMT_ENABLE		 				160
#define EVENT_AMT_DISABLE		 				161
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_AGENT_1							191
#define EVENT_AGENT_2							192
#define EVENT_AGENT_4							193
#define EVENT_AGENT_PRSENCE_NOT_STARTED			194
#define EVENT_AGENT_PRSENCE_STOPED				195
#define EVENT_AGENT_PRSENCE_EXPIRED				196
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_SD_STARTED						241  // 2 241
#define EVENT_SD_FINISHED						242  // 2 242
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_TIME_SYNC_DISABLE					270  // 15 270
#define EVENT_TIME_SYNC_ENABLE					271  // 15 271
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_REMOTE_GRACEFUL_SHUTDOWN_REQUESTED          272
#define EVENT_REMOTE_GRACEFUL_REBOOT_REQUESTED            273
#define EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED			  274
#define EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED             275
#define EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED              276
#define EVENT_REMOTE_GRACEFUL_REBOOT_FAILED               277
#define EVENT_REMOTE_SLEEP                                278
#define EVENT_REMOTE_HIBERNATE                            279
#define EVENT_REMOTE_SLEEP_FAILED                                280
#define EVENT_REMOTE_HIBERNATE_FAILED                            281
///////////////////////////////////////////////////////////////////////////////////////////////////
#define EVENT_FW_FATAL_ERROR                            282
#define EVENT_AMT_DISABLE_ATTEMPT						283
#define EVENT_WATCHDOG_ERROR                            284

//note this should be updated when when adding events
#define MAX_EVENT_NUM							290

#endif // _UNS_EVENT_DEFENITION_H