@rem SPDX-License-Identifier: Apache-2.0 */
@rem
@rem Copyright (C) 2010-2019 Intel Corporation
@rem

@echo off

echo ***************************************
echo ***   Enable LMS Logging Severity   ***
echo ***************************************

set ERROR_FLAG=0

if [%1] equ [] goto usage
set SEV_TXT=%1 


set SEV_BIN=0

if %SEV_TXT% equ TRACE set SEV_BIN=1
if %SEV_TXT% equ DEBUG set SEV_BIN=2
if %SEV_TXT% equ WARNING set SEV_BIN=3
if %SEV_TXT% equ ERROR set SEV_BIN=4
if %SEV_TXT% equ CRITICAL set SEV_BIN=5

if %SEV_BIN% equ 0 goto usage


echo *** Setting logging severity %SEV_BIN%   ***
reg add HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\LMS\IntelAMTUNS /v "LMSLoggingSeverity" /t REG_DWORD /d "%SEV_BIN%" /f 
if %errorlevel% neq 0 (
	echo Error: Setting logging severity %SEV_BIN% - Failed
	set ERROR_FLAG=1
)


EXIT /B %ERROR_FLAG%

:usage
echo.
echo USAGE:
echo lms_enable_logging_severity.bat (TRACE ^| DEBUG ^| WARNING ^| ERROR ^| CRITICAL)
set ERROR_FLAG=1
EXIT /B %ERROR_FLAG%