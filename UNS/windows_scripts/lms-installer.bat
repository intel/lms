@REM SPDX-License-Identifier: Apache-2.0
@REM Copyright (C) 2010-2019 Intel Corporation
@echo off
REM - This script installs LMS on the current machine.
REM - Run it from folder containing all required files (you'll be notified when missing one)
REM - Author : Reuven Abliyev

SETLOCAL

SET ACTION=""
::Parse arguments
for %%A in (%*) do call :ParseArgs %%A

if /i %ACTION%=="" (
	call :PrintUsage
	exit /b 1
)      

set LMS_INSTALL_PATH32=C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\LMS
set LMS_INSTALL_PATH=C:\Program Files\Intel\Intel(R) Management Engine Components\LMS
if EXIST "C:\Program Files (x86)" (
set "LMS_INSTALL_PATH=%LMS_INSTALL_PATH32%"
)

goto :Action

:ParseArgs
if /i %1==INSTALL       set ACTION=INSTALL           && goto :eof
if /i %1==UNINSTALL       set ACTION=UNINSTALL           && goto :eof
if /i %1==START       set ACTION=START           && goto :eof
if /i %1==STOP       set ACTION=STOP           && goto :eof

call :PrintUsage
exit /b 1
goto :eof


:Action
call :PrintLogo

:: dir %LMS_INSTALL_PATH%
echo %ACTION%

IF %ACTION%==INSTALL (
	goto MAIN.INSTALL
) else IF %Action%==UNINSTALL (
	goto MAIN.UNINSTALL
) else IF %Action%==START (
	goto MAIN.START
) else IF %Action%==STOP (
	goto MAIN.STOP
) else (
	call :PrintUsage
	EXIT /B 1
)

:EXIT_SUCCESS
EXIT /B 0

:EXIT_FAILURE
EXIT /B 1

REM - *************************     FUNCTIONS **************************

:MAIN.INSTALL
echo Installing LMS to %LMS_INSTALL_PATH%...
echo.

echo Verify admin priviligies
call :VerifyAdminPrivileges
IF %ERRORLEVEL%==1 EXIT /B 1
echo SUCCESS

set LMS_FILES=ACE.dll ComEventHandler.dll Common.dll Configurator.dll EventManager.dll GmsCommon.dll HistoryEventHandler.dll HostChangesNotificationService.dll IPRefreshService.dll LMS.exe PartialFWUpdateService.dll PortForwardingService.dll PowerOperationsService.dll SharedStaticIPService.dll StatusEventHandler.dll TimeSyncService.dll WiFiProfileSyncService.dll WinLogEventHandler.dll WMIEventHandler.dll WsmanClient.dll

set EXTERNAL_FILES=1100_PP_PFU.BIN 1105_PP_PFU.BIN 1106_PP_PFU.BIN 1108_PP_PFU.BIN 1200_PP_PFU.BIN 1300_PP_PFU.BIN FWUpdateLib_10.dll FWUpdateLib_11.dll FWUpdateLib_12.dll

echo Verify installation files consistency 
call :VerifyLmsFilesExists %LMS_FILES%
IF %ERRORLEVEL%==1 (
	echo.
	echo Error: some of LMS files are missing. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Stopping LMS service
call :StopLmsService 
IF %ERRORLEVEL%==1 (
	echo Error: failed to stop LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Uninstall LMS service
call :UninstallLmsService 
IF %ERRORLEVEL%==1 (
	echo Error: failed to unregister LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS


echo Remove LMS directories
call :RemoveLmsDirectories 
IF %ERRORLEVEL%==1 (
	echo Error: Error: failed to remove LMS directories. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Create LMS directories
call :CreateLmsDirectories 
IF %ERRORLEVEL%==1 (
	echo Error: failed to create LMS directories. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Copying LMS files
call :CopyLMSFiles %LMS_FILES% %EXTERNAL_FILES%
IF %ERRORLEVEL%==1 (
	echo Error: failed copying LMS Service files. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Adding register keys
call :AddRegistryKeys
IF %ERRORLEVEL%==1 (
	echo Error: failed add register keys. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Installing LMS service
call :InstallLMSService 
IF %ERRORLEVEL%==1 (
	echo Error: failed register LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Starting LMS service
call :StartLMSService 
IF %ERRORLEVEL%==1 (
	echo Error: failed starting LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Install completed successfuly.
echo.
goto EXIT_SUCCESS

:MAIN.UNINSTALL
echo uninstalling LMS...
echo.

echo Verify admin priviligies
call :VerifyAdminPrivileges
IF %ERRORLEVEL%==1 EXIT /B 1
echo SUCCESS

echo Stopping LMS service
call :StopLMSService 
IF %ERRORLEVEL%==1 (
	echo Error: failed to stop LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

echo Uninstall LMS service
call :UninstallLMSService 
IF %ERRORLEVEL%==1 (
	echo Error: failed to unregister LMS Service. aborting.
	goto EXIT_FAILURE
)
echo SUCCESS

call :RemoveRegistryKeys 
IF %ERRORLEVEL%==1 (
	echo Error: failed remove LMS keys from registry. aborting.
	goto EXIT_FAILURE
)

echo Remove LMS directories
call:RemoveLMSDirectories 
IF %ERRORLEVEL%==1 (
	echo Error: failed to remove LMS directories.  
	goto EXIT_FAILURE
)
echo SUCCESS

echo Uninstall completed successfuly.
echo.
echo.

goto EXIT_SUCCESS

:MAIN.START
echo starting LMS...
echo.

call :VerifyAdminPrivileges
IF %ERRORLEVEL%==1 EXIT /B 1

call :StartLMSService 
IF %ERRORLEVEL% EQU 0 goto EXIT_SUCCESS
goto EXIT_FAILURE

:MAIN.STOP
echo stopping LMS...
echo.

call:VerifyAdminPrivileges
IF %ERRORLEVEL%==1 EXIT /B 1

call:StopLMSService 
IF %ERRORLEVEL% EQU 0 goto EXIT_SUCCESS
goto EXIT_FAILURE


:CreateLMSDirectories
IF NOT EXIST "%LMS_INSTALL_PATH%" (
	call MD "%LMS_INSTALL_PATH%"
)
EXIT /B 0
goto :eof

:RemoveLMSDirectories
IF EXIST "%LMS_INSTALL_PATH%" (
	call RD /S /Q "%LMS_INSTALL_PATH%"
)
EXIT /B 0
goto :eof

:CopyLMSFiles
FOR %%F IN ( %* ) DO (
	copy %%F "%LMS_INSTALL_PATH%\%%F"
)
EXIT /B 0
goto :eof

:StopLMSService

call :GetServerStatus lms RUNNING
if %errorlevel%==1 (
EXIT /B 0
)
sc.exe stop lms
goto :eof

:UninstallLMSService
IF EXIST "%LMS_INSTALL_PATH%\lms.exe" (
"%LMS_INSTALL_PATH%\lms.exe" /unregserver
)
goto:eof

:StartLMSService
sc.exe start lms
if %errorlevel%==1 (
EXIT /B 1
)
call :GetServerStatus lms RUNNING
if %errorlevel%==0 (
EXIT /B 0
)
call :GetServerStatus lms START_PENDING
if %errorlevel%==0 (
EXIT /B 0
)
EXIT /B 1
goto :eof

:InstallLMSService
"%LMS_INSTALL_PATH%\lms.exe" /service
goto :eof

:VerifyLMSFilesExists
FOR %%F IN ( %*  ) DO (
IF NOT EXIST %%F (
	echo File %%F is missing
	exit /B 1
)
)
EXIT /B 0
goto :eof

:: %1 - service name
:: %2 - status to check
:GetServerStatus
sc.exe query %1 | findstr %2

goto :eof


:RemoveRegistryKeys
set TempRegistryFile=lms-remove-%RANDOM%.reg
IF EXIST %TempRegistryFile% DEL /Q /F %TempRegistryFile% 

echo Windows Registry Editor Version 5.00 >> %TempRegistryFile%
echo. >> %TempRegistryFile%
echo [-HKEY_LOCAL_MACHINE\SOFTWARE\Intel\IntelAMTUNS] >> %TempRegistryFile%

REGEDIT /S %TempRegistryFile%

DEL %TempRegistryFile%

IF %ERRORLEVEL% EQU 0 EXIT /B 0
EXIT /B 1
goto :eof


:AddRegistryKeys
set TempRegistryFile=lms-remove-%RANDOM%.reg

IF EXIST %TempRegistryFile% DEL /Q /F %TempRegistryFile% 

echo Windows Registry Editor Version 5.00 >> %TempRegistryFile%
echo. >> %TempRegistryFile%


echo [HKEY_LOCAL_MACHINE\SOFTWARE\Intel\IntelAMTUNS] >> %TempRegistryFile%
echo "LastLanguageUpdate"=hex: >> %TempRegistryFile%

echo [HKEY_LOCAL_MACHINE\SOFTWARE\Intel\IntelAMTUNS\ConfigData]  >> %TempRegistryFile%
echo "AMTStatusPollingInterval"=dword:00002710  >> %TempRegistryFile%

echo [HKEY_LOCAL_MACHINE\SOFTWARE\Intel\IntelAMTUNS\credentials]  >> %TempRegistryFile%
echo "GetUserInitiatedEnabled"=""  >> %TempRegistryFile%
echo "GetKVMRedirectionState"=""  >> %TempRegistryFile%
echo "OpenUserInitiatedConnection"="" >> %TempRegistryFile%
echo "CloseUserInitiatedConnection"="" >> %TempRegistryFile%
echo "GetIMSSEventHistory"="" >> %TempRegistryFile%
echo "GetAMTVersion"="" >> %TempRegistryFile%
echo "GetLMSVersion"="" >> %TempRegistryFile%
echo "GetHeciVersion"="" >> %TempRegistryFile%
echo "GetProvisioningMode"="" >> %TempRegistryFile%
echo "GetProvisioningTlsMode"="" >> %TempRegistryFile%
echo "GetProvisioningState"="" >> %TempRegistryFile%
echo "GetNetworkConnectionStatus"="" >> %TempRegistryFile%
echo "userInitiatedPolicyRuleExists"="" >> %TempRegistryFile%
echo "snmpEventSubscriberExists"="" >> %TempRegistryFile%
echo "CILAFilterCollectionSubscriptionExists"="" >> %TempRegistryFile%
echo "getWebUIState"="" >> %TempRegistryFile%
echo "GetPowerPolicy"="" >> %TempRegistryFile%
echo "GetLastResetReason"="" >> %TempRegistryFile%
echo "GetRedirectionStatus"="" >> %TempRegistryFile%
echo "GetSystemDefenseStatus"="" >> %TempRegistryFile%
echo "GetNetworkSettings"="" >> %TempRegistryFile%
echo "GetSystemUUID"="" >> %TempRegistryFile%
echo "GetIPv6NetworkSettings"="" >> %TempRegistryFile%
echo "TerminateKVMSession"="" >> %TempRegistryFile%
echo "IsKVMSessionInProgress"="" >> %TempRegistryFile%
echo "GetSpriteLanguage"="" >> %TempRegistryFile%
echo "SetSpriteLanguage"="" >> %TempRegistryFile%
echo "GetSpriteZoom"="" >> %TempRegistryFile%
echo "SetSpriteZoom"="" >> %TempRegistryFile%
echo "GetSpriteParameters"="" >> %TempRegistryFile%
echo "TerminateRemedySessions"="" >> %TempRegistryFile%
echo "GetAuditLogs"="" >> %TempRegistryFile%
echo "GetATDeviceInfo"="" >> %TempRegistryFile%
echo "GetTheFeatureState"="" >> %TempRegistryFile%
echo "GetFeaturesState"="" >> %TempRegistryFile%
echo "GetCustomerType"="" >> %TempRegistryFile%
echo "GetPlatformType"="" >> %TempRegistryFile%
echo "GetMenageabiltyMode"="" >> %TempRegistryFile%
echo "GetConfigurationInfo"="" >> %TempRegistryFile%
echo "GetUserConsentState"="" >> %TempRegistryFile%
echo "GetWLANLinkInfo"="" >> %TempRegistryFile%
echo "SetLinkPreferenceToHost"="" >> %TempRegistryFile%
echo "GetFWInfo"="" >> %TempRegistryFile%
echo "InitiateUserConnection"="" >> %TempRegistryFile%
echo "GetRedirectionSessionLinkTechnology"="" >> %TempRegistryFile%

REGEDIT /S %TempRegistryFile%

DEL %TempRegistryFile%

IF %ERRORLEVEL% EQU 0 EXIT /B 0
EXIT /B 1
goto :eof


:VerifyAdminPrivileges
@echo off
NET SESSION > NUL
IF NOT %ERRORLEVEL% EQU 0 (
   echo.
   echo ######## ########  ########   #######  ########  
   echo ##       ##     ## ##     ## ##     ## ##     ## 
   echo ##       ##     ## ##     ## ##     ## ##     ## 
   echo ######   ########  ########  ##     ## ########  
   echo ##       ##   ##   ##   ##   ##     ## ##   ##   
   echo ##       ##    ##  ##    ##  ##     ## ##    ##  
   echo ######## ##     ## ##     ##  #######  ##     ## 
   echo.
   echo.
   echo ############### ERROR: ADMINISTRATOR PRIVILEGES REQUIRED ################
   echo #
   echo #  This script must be run as administrator to work properly!  
   echo #  If you're seeing this after clicking on the install.bat file,
   echo #  then right click on the file and select "Run As Administrator".
   echo #
   echo #########################################################################
   echo.
   PAUSE
   EXIT /B 1
)
goto:eof

:PrintLogo
@echo off
cls
echo.
echo. 
echo #       #     #  #####   
echo #       ##   ## #     #  
echo #       # # # # #        
echo #       #  #  #  #####   
echo #       #     #       #  
echo #       #     # #     #  
echo ####### #     #  #####   
echo.
goto:eof

:PrintUsage
@echo off
echo.
echo Usage: %~n0 action
echo.
echo   Action:
echo 	install    - install the LMS service using current directory files
echo 	uninstall  - remove the LMS service and all it components
echo 	start      - starts the LMS service
echo 	stop       - stops the LMS service
echo.       
pause 
goto:eof