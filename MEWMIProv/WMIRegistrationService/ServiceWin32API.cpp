//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2021 Intel Corporation
#include "shlwapi.h"
#include <sstream>
#include "EventLog.h"
#include "EventLogMessages.h" // auto generated form mc file


using tstring = std::wstring;


//function forward declarations
VOID
WINAPI
ServiceMain(DWORD, LPTSTR*);

BOOL _Check_return_
UpdateServiceStatus(
    _In_ SERVICE_STATUS_HANDLE hHandle,
    _In_     DWORD                 dwCurrentState,
    _In_     DWORD                 dwWin32ExitCode
    );

VOID
CALLBACK
ServiceStopCallback(
    _In_ PVOID   lpParameter,
    _In_ BOOLEAN TimerOrWaitFired
    );

VOID
ServiceStop(
    _In_ DWORD ExitCode
    );

DWORD _Check_return_
WINAPI
ServiceRunningWorkerThread(
    _In_ PVOID
    );

DWORD _Check_return_
WINAPI
ServiceStopWorkerThread(
    _In_ PVOID lpThreadParameter
    );

DWORD _Check_return_
ExecuteMofcomp(
    tstring param
    );

//
// Settings of the service
//
#define SERVICE_NAME             L"Intel(R) WMI Registration Service"
const unsigned int SERVICE_FLAGS_STARTED = 0x0;
const unsigned int SERVICE_FLAGS_DONE = 0x1;
const unsigned int WAIT_FOR_COMPILITION_IN_MILLI = 1000000;
const unsigned int STATUS_SUCCESS = 0;
const int STATUS_UNSUCCESSFUL = -1;
const unsigned int SERVICE_WAIT_HINT_TIME = 30000; // 30 seconds
const unsigned int DEBUG_MSG_LEN = 260;

//
// Service context
//
SERVICE_STATUS_HANDLE StatusHandle     = NULL;
volatile LONG         ControlFlags     = 0;
HANDLE                StopRequestEvent = NULL;
HANDLE                StopWaitObject   = NULL;




VOID DbgPrint(_In_ const TCHAR* args, ...)
{
    tstring dbgPrefix = SERVICE_NAME;
    dbgPrefix += L": ";
    TCHAR msg[DEBUG_MSG_LEN + 1];
    //no point in checking return code, nothing to do if fails.
    wcscpy_s(msg, DEBUG_MSG_LEN, dbgPrefix.c_str());
    va_list varl;
    va_start(varl, args);
    vswprintf_s(&msg[dbgPrefix.size()], DEBUG_MSG_LEN - dbgPrefix.size(), args, varl);
    va_end(varl);

    OutputDebugString(msg);
}

_Check_return_
tstring GetServicePath()
{
    WCHAR szSource[MAX_PATH];
    tstring path = {};
    tstring source;

    DWORD pathErr = GetModuleFileName(0, szSource, MAX_PATH);
    if (pathErr == 0)
    {
        DbgPrint(L"GetModuleFileName Failed with %ul ", GetLastError());
        return tstring();
    }
    source = tstring(szSource);
    tstring::size_type pos = source.find_last_of(L"\\/");
    if (pos == tstring::npos)
    {
        DbgPrint(L"Find exe directory failed.");
        return tstring();
    }
    path = source.substr(0, pos);

    DbgPrint(L"Service exe path is %s" ,path.c_str());
    return tstring(path.c_str());
}

tstring GetServiceState(_In_ DWORD currnetState)
{
    tstring state;
    switch (currnetState)
    {
    case SERVICE_STOPPED:
        state = L"SERVICE_STOPPED";
        break;
    case SERVICE_START_PENDING:
        state = L"SERVICE_START_PENDING";
        break;
    case SERVICE_STOP_PENDING:
        state = L"SERVICE_STOP_PENDING";
        break;
    case SERVICE_RUNNING:
        state = L"SERVICE_RUNNING";
        break;
    case SERVICE_CONTINUE_PENDING:
        state = L"SERVICE_CONTINUE_PENDING";
        break;
    case SERVICE_PAUSE_PENDING:
        state = L"SERVICE_PAUSE_PENDING";
        break;
    case SERVICE_PAUSED:
        state = L"SERVICE_PAUSED";
        break;
    default:
        state = L"UNKNOWN STATE";
        break;
    }
    return state;
}

_Check_return_
DWORD
WINAPI
ServiceCtrlHandler(
    _In_ DWORD Ctrl,
    _In_ DWORD dwEventType,
    _In_ LPVOID lpEventData,
    _In_ LPVOID lpContext
    )
{
    switch (Ctrl)
    {
    case SERVICE_CONTROL_STOP:
        //
        // Set service stop event
        //
        UpdateServiceStatus(StatusHandle, SERVICE_STOP_PENDING, ERROR_SUCCESS);
        SetEvent(StopRequestEvent);
        break;

    default:
        break;
    }
    return NO_ERROR;
}

VOID WINAPI ServiceMain(DWORD, LPTSTR*)
{
    DWORD Err = ERROR_SUCCESS;

    DbgPrint(L"ServiceMain Entry");
    StatusHandle = RegisterServiceCtrlHandlerExW((LPWSTR)SERVICE_NAME,
                                                 ServiceCtrlHandler, NULL);

    if (StatusHandle == NULL)
    {
        DbgPrint(L"RegisterServiceCtrlHandlerExW Failed");
        Err = GetLastError();
        goto cleanup;
    }

    UpdateServiceStatus(StatusHandle,
                        SERVICE_START_PENDING,
                        ERROR_SUCCESS);

    //
    // Register callback function for stop event
    //
    StopRequestEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

    if (StopRequestEvent == NULL)
    {
        Err = GetLastError();
        DbgPrint(L"Event Creation Failed with Error", Err);
        goto cleanup;
    }

    if (!RegisterWaitForSingleObject(&StopWaitObject,
                                     StopRequestEvent,
                                     ServiceStopCallback,
                                     NULL,
                                     INFINITE,
                                     WT_EXECUTEONLYONCE | WT_EXECUTEINPERSISTENTTHREAD))
    {
        Err = GetLastError();
        DbgPrint(L"RegisterWaitForSingleObject Failed with Error", Err);
        goto cleanup;
    }

    UpdateServiceStatus(StatusHandle,
                        SERVICE_START_PENDING,
                        ERROR_SUCCESS);

    //
    // Queue the main service function for execution in a worker thread.
    //
    QueueUserWorkItem(&ServiceRunningWorkerThread,
                      NULL,
                      WT_EXECUTELONGFUNCTION);

    UpdateServiceStatus(StatusHandle,
                        SERVICE_RUNNING,
                        ERROR_SUCCESS);

    WriteToEventLog(EVENT_LOG_INFORMATION, MSG_SERVICE_START);

cleanup:

    if (Err != ERROR_SUCCESS)
    {
        ServiceStop(Err);
    }

    DbgPrint(L"ServiceMain Exit");
}


_Check_return_
BOOL
UpdateServiceStatus(
    _In_ SERVICE_STATUS_HANDLE hHandle,
    _In_  DWORD  dwCurrentState,
    _In_  DWORD  dwWin32ExitCode
    )
{
    SERVICE_STATUS Status;

    DbgPrint(L"Update service state to %s", GetServiceState(dwCurrentState));

    static DWORD dwCheckPoint = 1;

    Status.dwServiceType             = SERVICE_WIN32_OWN_PROCESS;
    Status.dwCurrentState            = dwCurrentState;
    Status.dwWin32ExitCode           = dwWin32ExitCode;
    Status.dwServiceSpecificExitCode = ERROR_SUCCESS;

    if (dwCurrentState == SERVICE_START_PENDING)
    {
        Status.dwControlsAccepted = 0;
    }
    else
    {
        Status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
    }

    if ((dwCurrentState == SERVICE_RUNNING) ||
        (dwCurrentState == SERVICE_STOPPED))
    {
        Status.dwCheckPoint = 0;
        Status.dwWaitHint = 0;
    }
    else
    {
        Status.dwCheckPoint = dwCheckPoint++;
        Status.dwWaitHint = SERVICE_WAIT_HINT_TIME;
    }

    return SetServiceStatus(hHandle, &Status);
}

_Check_return_
DWORD
ExecuteMofcomp(_In_ tstring param)
{
    DWORD status = STATUS_SUCCESS;
    SHELLEXECUTEINFO info = { 0 };
    tstring commandPath;
    DWORD exitCode, waitErr = 0;
    HRESULT err = S_OK;
    BOOL res = TRUE;
    WCHAR systemFolder[MAX_PATH];
    DbgPrint(L"ExecuteMofcomp Entry");

    err = GetSystemDirectory(systemFolder, MAX_PATH);
    if (err == 0)
    {
        DbgPrint(L"GetSystemDirectory failed with status %lu ", GetLastError());
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }
    commandPath = systemFolder;

    commandPath += L"\\wbem\\mofcomp.exe";

    if (!PathFileExists(commandPath.c_str()))
    {
        DbgPrint(L"PathFileExists failed");
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }

    DbgPrint(L"Command path is: %s ", commandPath);
    DbgPrint(L"Param is: %s ", param);

    info.cbSize = sizeof(SHELLEXECUTEINFOW);
    info.fMask = SEE_MASK_DEFAULT | SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = NULL;
    info.lpVerb = L"open";
    info.lpFile = commandPath.c_str();
    info.lpParameters = param.c_str();
    info.lpDirectory = NULL;
    info.nShow = SW_SHOW;

    res = ShellExecuteEx(&info);
    if (!res)
    {
        DbgPrint(L"ShellExecuteEx failed with status %d" ,GetLastError());
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }

    if (!info.hProcess)
    {
        DbgPrint(L"Procces handle is Null");
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }

    waitErr = WaitForSingleObject(info.hProcess, WAIT_FOR_COMPILITION_IN_MILLI);
    if (waitErr != WAIT_OBJECT_0)
    {
        DbgPrint(L"WaitForSingleObject failed with status %lu",waitErr);
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }


    res = GetExitCodeProcess(info.hProcess, &exitCode);
    if (res == 0)
    {
        DbgPrint(L"GetExitCodeProcess failed with status %lu" ,GetLastError());
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }

    if (exitCode != STATUS_SUCCESS)
    {
        DbgPrint(L"Execution failed with exit code %lu" ,exitCode);
        status = STATUS_UNSUCCESSFUL;
        goto end;
    }

end:
    DbgPrint(L"ExecuteMofcomp Exit");
    return status;
}

_Check_return_
DWORD
WINAPI
ServiceRunningWorkerThread(
    _In_ PVOID
    )
{
    DWORD status = STATUS_SUCCESS;
    tstring buildParam, registerParam = { 0 };
    DbgPrint(L"ServiceRunningWorkerThread Entry");

    InterlockedOr(&ControlFlags, SERVICE_FLAGS_STARTED);

    tstring path = GetServicePath();
    if (path.empty())
    {
        DbgPrint(L"GetServicePath failed.");
        goto end;
    }
    buildParam = path + L"\\ME\\wmi_build.mof";
    registerParam = path + L"\\ME\\register.mof";

    DbgPrint(L"Starting WMI registration.");
    status = ExecuteMofcomp(buildParam);
    if (status != STATUS_SUCCESS)
    {
        DbgPrint(L"ExecuteMofcomp with %s failed.", buildParam.c_str());
        goto end;
    }

    status = ExecuteMofcomp(registerParam);
    if (status != STATUS_SUCCESS)
    {
        DbgPrint(L"ExecuteMofcomp with %s failed.", registerParam.c_str());
        goto end;
    }
    DbgPrint(L"WMI registration finished successfully.");

    WriteToEventLog(EVENT_LOG_INFORMATION, MSG_REGISTRATION_SUCCESS);


end:
    InterlockedOr(&ControlFlags, SERVICE_FLAGS_DONE);
    if (status != STATUS_SUCCESS)
    {
        WriteToEventLog(EVENT_LOG_ERROR, MSG_REGISTRATION_FAILURE);
    }
    DbgPrint(L"ServiceRunningWorkerThread Exit");
    return status;
}

VOID
CALLBACK
ServiceStopCallback(
    _In_ PVOID   lpParameter,
    _In_ BOOLEAN TimerOrWaitFired
    )
{
    UNREFERENCED_PARAMETER(TimerOrWaitFired);

    //
    // Since wait object can not be unregistered in callback function, queue
    // another thread
    //
    QueueUserWorkItem(ServiceStopWorkerThread,
                      lpParameter,
                      WT_EXECUTEDEFAULT);
}

_Check_return_
DWORD
WINAPI
ServiceStopWorkerThread(
    _In_ PVOID lpThreadParameter
    )
{
    UNREFERENCED_PARAMETER(lpThreadParameter);

    ServiceStop(ERROR_SUCCESS);

    return 0;
}

VOID
ServiceStop(
    _In_ DWORD ExitCode
    )
{
    DbgPrint(L"ServiceStop Entry");
    if (StatusHandle == NULL)
    {
        DbgPrint(L"StatusHandle is NULL");
        return;
    }
    DWORD status = STATUS_SUCCESS;
    UpdateServiceStatus(StatusHandle, SERVICE_STOP_PENDING, ExitCode);

    // wait for service to register to WMI
    while ((InterlockedOr(&ControlFlags, 0) & SERVICE_FLAGS_DONE) != 1);

    tstring path = GetServicePath();
    tstring removeParam = path + L"\\ME\\remove.mof";

    DbgPrint(L"Starting WMI unregistration.");
    status = ExecuteMofcomp(removeParam);
    if (status != STATUS_SUCCESS)
    {
        DbgPrint(L"ExecuteMofcomp with %s failed.", removeParam);
    }

    if (StopWaitObject != NULL)
    {
        UnregisterWait(StopWaitObject);
    }

    if (StopRequestEvent != NULL)
    {
        CloseHandle(StopRequestEvent);
    }

    WriteToEventLog(EVENT_LOG_INFORMATION, MSG_SERVICE_STOP);
    DbgPrint(L"ServiceStop Exit");
    UpdateServiceStatus(StatusHandle, SERVICE_STOPPED, ExitCode);
}

_Check_return_
INT main()
{
    DbgPrint(L"main entry");

    SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_SYSTEM32);

    SERVICE_TABLE_ENTRY serviceTable[] =
    {
        { SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)ServiceMain },
        { NULL, NULL }
    };

    return StartServiceCtrlDispatcher(serviceTable);
}
