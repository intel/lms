;//SPDX-License-Identifier: Apache-2.0
;//
;//Copyright (C) 2021 Intel Corporation

SeverityNames=(Informational=0x1:STATUS_SEVERITY_INFORMATIONAL
               Warning=0x2:STATUS_SEVERITY_WARNING
               Error=0x3:STATUS_SEVERITY_ERROR
			   )

LanguageNames=(All=0x000:MSG00001)

;//*********** WMI Provider Registration Event Definitions**************
MessageId=0
Severity=Informational
SymbolicName=MSG_SERVICE_START
Language=All
Intel(R) WMI Registration Service started.
.
MessageId=1
Severity=Informational
SymbolicName=MSG_SERVICE_STOP
Language=All
Intel(R) WMI Registration Service stopped.
.
MessageId=2
Severity=Informational
SymbolicName=MSG_REGISTRATION_SUCCESS
Language=All
Intel(R) WMI Registration Service has successfully finished WMI Registration.
.
MessageId=3
Severity=Error
SymbolicName=MSG_REGISTRATION_FAILURE
Language=All
Intel(R) WMI Registration Service has failed WMI Registration.
.
