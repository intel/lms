;//SPDX-License-Identifier: Apache-2.0 */
;//
;//Copyright (C) 2009 Intel Corporation
;//
;//----------------------------------------------------------------------------
;//
;//  File:       MEProvMessages.mc 
;//
;//  Contents:   ME WMI provider Event Log message DLL.
;//
;//  Notes:      
;//
;//----------------------------------------------------------------------------

;// ---------------------------------------------------------------------------
;// HEADER SECTION
;// ---------------------------------------------------------------------------

MessageIdTypedef=WORD

SeverityNames=(	Success=0x0:STATUS_SEVERITY_SUCCESS
				Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
				Warning=0x2:STATUS_SEVERITY_WARNING
				Error=0x3:STATUS_SEVERITY_ERROR)

LanguageNames=(English=0x409:MSG00001)

;#ifndef EVENT_LOG_MESSAGE_DLL_PROV_FILE
;#define EVENT_LOG_MESSAGE_DLL_PROV_FILE


;//**********************Category Definitions***********************
MessageId=1
Facility=Application
Severity=Informational
SymbolicName=ME_PROVIDER_EVENT
Language=English
Intel(R) ME WMI Provider notification
.
;//********************End of Category Definitions*******************

MessageIdTypedef=DWORD

;//***********************Event Definitions******************************
MessageId=1002
SymbolicName=LOCAL_ADMIN_REQUEST
Language=English
%1
.

MessageId=1003
SymbolicName=UNCONFIGURE_REQUEST
Language=English
%1
.
;//***********************End of Event Definitions***********************

;#endif