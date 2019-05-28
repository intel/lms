/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#ifndef SERVICES_NAMES
#define SERVICES_NAMES
#include <ace/SString.h>

static const ACE_TString EVENT_MANAGER(ACE_TEXT("EventManager"));
static const ACE_TString WINLOG_EVENT_HANDLER(ACE_TEXT("WinLogEventHandler"));
static const ACE_TString GMS_CONFIGURATOR(ACE_TEXT("Configurator"));
static const ACE_TString COM_EVENT_HANDLER(ACE_TEXT("COMEventHandler"));
static const ACE_TString WMI_EVENT_HANDLER(ACE_TEXT("WMIEventHandler"));
static const ACE_TString HISTORY_EVENT_HANDLER(ACE_TEXT("HistoryEventHandler"));
static const ACE_TString STATUS_EVENT_HANDLER(ACE_TEXT("StatusEventHandler"));
static const ACE_TString GMS_SHAREDSTATICIPSERVICE(ACE_TEXT("SharedStaticIPService"));
static const ACE_TString GMS_PARTIALFWUPDATESERVICE(ACE_TEXT("PartialFWUpdateService"));
static const ACE_TString GMS_IPREFRESHSERVICE(ACE_TEXT("IPRefreshService"));
static const ACE_TString GMS_TIMESYNCSERVICE(ACE_TEXT("TimeSyncService"));
static const ACE_TString GMS_PORTFORWARDINGSERVICE(ACE_TEXT("PortForwardingService"));
static const ACE_TString GMS_HOSTCHANGESNOTIFICATIONSERVICE(ACE_TEXT("HostChangesNotificationService"));
static const ACE_TString POWER_OPERATIONS_SERVICE(ACE_TEXT("PowerOperationsService"));
static const ACE_TString GMS_DBUSSERVICE(ACE_TEXT("DBusService"));
static const ACE_TString GMS_WIFIPROFILESYNCSERVICE(ACE_TEXT("WiFiProfileSyncService"));
static const ACE_TString FIRST_SERVICE(ACE_TEXT("FirstService"));
static const ACE_TString LAST_SERVICE(ACE_TEXT("LastService"));
static const ACE_TString AMT_ENABLE_LAST_SERVICE(ACE_TEXT("AmtEnableLastService"));
static const ACE_TString WAITING_FOR_PFW_LAST_SERVICE(ACE_TEXT("WaitingForPfwLastService"));
#endif //SERVICES_NAMES
