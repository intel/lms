/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */

#include "PFWUpdateDllWrapperLegacy.h"

void PFWUpdateDllWrapperLegacy::printPfwuReturnCode(uint32_t status)
{
	/*
	Zero = Success
	1 = Not ME SKU
	2 = Failed to load FwUpdateLib_Dll
	8193 = Heci Device not found
	8199 = Failure to send or receive messages to heci to get Status Info
	8204 = Heci message has incorrect message type
	8213 = Heci Buffer Size is Small Error
	8707 = Internal error within the library
	8710 = Insufficient memory Error
	8713 = Invalid Image file header
	8714 = Failed to open input file
	8727 = Failure to send or receive heci messages to heci client
	8741 = FW returns incorrect Message Type or wrong image ordering
	8743 = The tool is running on “an unknown or unsupported platform"
	8746 = Ivalid image size
	8747 = Bffer not available
	8748 = Inavlid parameters sent to Firmware
	8761 = Firmware write file failure
	8762 = Firmware read file failure
	8763 = Firmware delete file failure
	8764 = partition layout not compatible
	8771 = Invalid file used for partial FW update (only FULL and Partial images are supported)
	8776 = Failure in Send or Receive of the Get Partition Attribute Command. Or even when FW returns an error status after receiving command
	8778 = The partition ID requested for update is not expected by the FW
	*/
	std::wstring dbgStr;
	switch (status)
	{
	case   0:    dbgStr = L"Success";	break;
	case   1:    dbgStr = L"Not ME SKU";	break;
	case   2:    dbgStr = L"Failed to load FwUpdateLib_Dll";	break;
	case   8199: dbgStr = L"Failure to send or receive messages to heci to get Status Info";	break;
	case   8204: dbgStr = L"Heci message has incorrect message type";	break;
	case   8213: dbgStr = L"Heci Buffer Size is Small Error";	break;
	case   8771: dbgStr = L"Invalid file used for partial FW update (only FULL and Partial images are supported)";	break;
	case   8776: dbgStr = L"Failure in Send or Receive of the Get Partition Attribute Command. Or even when FW returns an error status after receiving command";	break;

	case   8193: dbgStr = L"Intel (R) ME Interface : Cannot locate ME device driver";	break;
	case   8704: dbgStr = L"Firmware update operation not initiated due to a SKU mismatch";	break;
	case   8705: dbgStr = L"Firmware update not initiated due to version mismatch";	break;
	case   8706: dbgStr = L"Firmware update not initiated due to integrity failure or invalid FW image";	break;
	case   8707: dbgStr = L"Firmware update failed due to an internal error";	break;
	case   8708: dbgStr = L"Firmware Update operation not initiated because a firmware update is already in progress";	break;
	case   8710: dbgStr = L"Firmware update tool failed due to insufficient memory";	break;
	case   8713: dbgStr = L"Firmware update not initiated due to an invalid FW image header";	break;
	case   8714: dbgStr = L"Firmware update not initiated due to file open or read failure";	break;
	case   8716: dbgStr = L"Invalid usage";	break;
	case   8718: dbgStr = L"Update operation timed-out : cannot determine if the operation succeeded";	break;
	case   8719: dbgStr = L"Firmware update cannot be initiated because Local Firmware update is disabled";	break;
	case   8722: dbgStr = L"Intel (R) ME Interface : Unsupported message type";	break;
	case   8723: dbgStr = L"No Firmware update is happening";	break;
	case   8724: dbgStr = L"Platform did not respond to update request";	break;
	case   8725: dbgStr = L"Failed to receive last update status from the firmware";	break;
	case   8727: dbgStr = L"Firmware update tool failed to get the firmware parameters";	break;
	case   8728: dbgStr = L"This version of the Intel (R) FW Update Tool is not compatible with the current platform";	break;
	case   8741: dbgStr = L"FW Update Failed";	break;
	case   8743: dbgStr = L"Unknown or unsupported Platform";	break;
	case   8744: dbgStr = L"OEM ID verification failed";	break;
	case   8745: dbgStr = L"Firmware update cannot be initiated because the OEM ID provided is incorrect";	break;
	case   8746: dbgStr = L"Firmware update not initiated due to invalid image length";	break;
	case   8747: dbgStr = L"Firmware update not initiated due to an unavailable global buffer";	break;
	case   8748: dbgStr = L"Firmware update not initiated due to invalid firmware parameters";	break;
	case   8754: dbgStr = L"Encountered error writing to file";	break;
	case   8757: dbgStr = L"Display FW Version failed";	break;
	case   8758: dbgStr = L"The image provided is not supported by the platform";	break;
	case   8759: dbgStr = L"Internal Error";	break;
	case   8760: dbgStr = L"Update downgrade vetoed";	break;
	case   8761: dbgStr = L"Firmware write file failure";	break;
	case   8762: dbgStr = L"Firmware read file failure";	break;
	case   8763: dbgStr = L"Firmware delete file failure";	break;
	case   8764: dbgStr = L"Partition layout NOT compatible";	break;
	case   8765: dbgStr = L"Downgrade NOT allowed, data mismatched";	break;
	case   8766: dbgStr = L"Password did not match";	break;
	case   8768: dbgStr = L"Password Not provided when required";	break;
	case   8769: dbgStr = L"Polling for FW Update Failed";	break;
	case   8772: dbgStr = L"Invalid usage, -allowsv switch required to update the same version firmware";	break;
	case   8778: dbgStr = L"Unable to read FW version from file. Please verify the update image used";	break;
	case   8787: dbgStr = L"Password exceeded maximum number of retries";	break;
	default: dbgStr = L"Unknown error";	break;
	}
	UNS_DEBUG(L"Decode error:: %u -> %W\n", status, dbgStr.c_str());
}
