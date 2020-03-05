## [2011.0.0.0]

### Added
 - Add special error for requests not supported by the system (G_IO_ERROR_NOT_SUPPORTED on DBus, E_NOINTERFACE on COM)
 - MEIClient: make exceptions hierarchical for ease of catching
 - Reduce calls to FW by retrieving only required info
 - PortForwardingService: demote traffic dump to TRACE level
 - WMIProvider: mark mof removal as nofail
 - StatusEventHandler: improve WifiProfileSync detection
 - code quality improvements

### Fixed
 - Avoid WS-MAN calls till port forwarding is available in different code paths
 - MEIClient: CMake: fix build with Ninja
 - [Windows] WifiProfileSync: OWE PSKPassPhrase should be NULL
 - PowerOperationService: set default value for reboot reason message to the correct variable
 - [Windows] WiFiProfileSync: consolidate all operation in one WsManClient instance to avoid crash
 - [Windows] WiFiProfileService: plug memleak in error path

### Deprecated
 - Drop AMT 7 support from SetSpriteLanguage DBus and COM methods
 - Drop unused LMSstarted event and deprecate reset COM method.
 - Deprecate unused DBus and COM interfaces:
    - GetProvisioningMode
    - GetProvisioningTlsMode
    - getWebUIState
    - TerminateKVMSession
    - UpdateScreenSettings
    - ProxyAddProxyEntry
    - GetFeaturesState
    - GetPlatformType
    - OpenUserInitiatedConnection

## [2003.0.0.0]

### Fixed
 - [Windows] Fix build with CMake
 - [Windows] Explicitly ask for CMake 3.12 in AMT_COM_Interface
 - Delete LastLanguageUpdate registry value for default language set and fix it usage
 - WifiProfileSync: Add support for OWE in WPA3 protocol
 - PortForwarding: try re-init if mei is fast-disconnected to fix service stale on CSME reset

## [2001.0.0.0]

### Added
 - Update internal copy of openwsman code to latest upstream tip
 - [Windows] Support for WPA3 protocol in WiFiProfileSync
 - Improve code quality (variable shadowing, unused code, code style, etc.)
 - [Windows] Push some prints from debug to trace to lighten logs in WiFiProfileSync
 - [Windows] Clean up the memory management in IPRefresh service.
 - [Windows] Add build option to bypass DLL signatures check
 - Add IsMeasuredBootState method to DBus and COM interfaces

### Fixed
 - [Windows] Fix DLL signature check
 - [Windows] Remove logging of AP password in WiFiProfileSync
 - Replace non-threadsafe functions
 - Fix various cases where service failed to stop
 - [Windows] Fix socket creation on Windows 8.1
 - Fix initialization sequence for cases when MEI is not ready yet
 - [CMake] fix build-depend on MeTee to ensure proper build order
 - Fix buffer overflow in RegistryStorage
 - Fixes for bunch of security issues (check return values, input validation, use secure functions)

## [1932.0.0.0]

### Added
 - Improve debug prints in WsManClient code and print errors in Release builds

### Fixed
 - AuditLogWSManClient: Add parse to value 3 in InitType

## [1930.0.0.0]

### Added
 - Traffic dump into general log
 - The log system was updated:
   - different log levels
   - ability to enable logs above specified severity
   - the debug is enabled using the lms_enable_logging_severity.sh/bat script
 - Fix and add scripts for LMS testing
 - Conditionally add tests to installation package for ease of continuous integration
 - [Linux] load service libraries using full name to ease on Yocto integration

### Fixed
 - Build instructions updated
 - Fix vector size initialization in port forwarding
 - [Windows] Release HECI device on driver unload to allow restart-less update
 - [Linux] make storage directories traversable (set executable bit for new directories created in /etc/lms)


