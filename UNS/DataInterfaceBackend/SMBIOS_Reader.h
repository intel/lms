/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: SMBIOS_Reader.h

--*/

//////////////////////////////////////////////////////////////// 
#ifndef _SMBIOS_READER_H_
#define _SMBIOS_READER_H_
//////////////////////////////////////////////////////////////// 
#include <string.h>
#include <stdint.h>

#define MAX_DATA 0xFA00					// Space allocated for SMBIOS Table Raw data 64K 
#define MAX_STRING 0x3E8				// 1K 
#define MAX_STRING_TABLE 0x19			// 25 
#define MAX_CONTAINED_ELEMENTS 0xFF		// 255 
#define MAX_CONTAINED_RECORD 0xFF		// 255 
#define SMALL_STRING 0x64				// 100 
#define BIGGER_STRING 0xFF				// 255 
///////////////////////////////////////////////////////////////
#define SMBIOS_INTEL_OEM_TYPE			0x83
#define SMBIOS_END_OF_TABLE_TYPE		127
#define ME_CAPABILITIES_FIELD_OFFSET	0x18
#define AT_INFO_1_OFFSET	            0x24
#define AT_INFO_2_OFFSET	            0x34
#define BIOS_CAPABILITY_OFFSET			0x34
#define PBA_SUPPORT_OFFSET				0x6
#define WWAN_SUPPORT_OFFSET				0x7
#define VPRO_STRING						"vPro"
#define SIGNATURE_LEN					4
#define SIGNATURE_OFFSET				0x38
///////////////////////////////////////////////////////////////
#define SMBIOS_FOUNDED				0
#define SMBIOS_NOT_FOUNDED			1
#define SMBIOS_FAILURE				2
///////////////////////////////////////////////////////////////
#define ERROR_COCREATEINSTANCE		3
#define ERROR_COINITIALIZE			4
#define ERROR_SMBIOS_ENUMERATION	5
#define ERROR_WMI_CONNECT			6
#define ERROR_WMI_SET_PROXY			7
/////////////////////////////////////////////////////////////// 
//Mask  
/////////////////////////////////////////////////////////////// 
#define BIOS_INFORMATION 0x01 
#define SYSTEM_INFORMATION 0x02 
#define SYSTEM_ENCLOSURE 0x04 
#define PROCESSOR_INFORMATION 0x08 
#define CACHE_INFORMATION 0x10 
#define SYSTEM_SLOTS 0x20 
#define PHYSICAL_MEMORY_ARRAY 0x40 
#define MEMORY_DEVICE 0x80 
#define MEMORY_ARRAY_MAPPED_ADDRESS 0x100 
#define SYSTEM_BOOT_INFORMATION 0x200 
///////////////////////////////////////////////////////////////
// Generic Structures 
//////////////////////////////////////////////////////////////// 
struct smbios_tbl_hdr
{
	unsigned char			Type;		
	unsigned char			Length; 
	unsigned short			Handle; 
	
};

struct bios_cap
{
	uint32_t					BiosCap1:6;			// We do not care about bit[5-0]
	uint32_t					PbaSupported:1;		// 1: supported, 0: not supported
	uint32_t					WwanSupported:1;	// 1: supported, 0: not supported
	uint32_t					BiosCap2:24;		// Reserved 
};
struct at_info1
{
    uint8_t                  flags1 : 5;
    uint8_t                  atEnrolled : 1;
    uint8_t                  flags2 : 2;
};
struct at_info2
{
    uint32_t                  flags1 : 6;
    uint32_t                  pbaRecoveryEnable : 1;
    uint32_t                  wwanSupport : 1;
    uint32_t                  flags2 : 24;
};

/*
///////////////////////////////////////////////////////////////
// Intel OEM Type 131 (0x131)
///////////////////////////////////////////////////////////////
struct oem_info_type_131
{
	struct smbios_tbl_hdr	Header;	                // 4 bytes of header		
	unsigned char           Data1[ME_CAPABILITIES_FIELD_OFFSET - sizeof(struct smbios_tbl_hdr)]; // 4 bytes of CPU cap
	struct me_cap			MeCapabilities;			// 0x18
	unsigned char			Data2[AT_INFO_1_OFFSET - ME_CAPABILITIES_FIELD_OFFSET - sizeof(struct me_cap)];
	struct at_info1         AtInfo1;                // offset 0x24	
	uint8_t					Data3[AT_INFO_2_OFFSET - AT_INFO_1_OFFSET - sizeof(struct at_info1)];
	struct at_info2         AtInfo2;                // offset 0x34
	uint8_t					vpro_signature[SIGNATURE_LEN];
};

*/
struct me_cap{
  uint32_t  MeEnabled : 1;          // [0]     ME enabled/Disabled
  uint32_t  IntelQstFw : 1;         // [1]     Qst Fw support
  uint32_t  Reserved : 1;           // [2]     Reserved, must set to 0
  uint32_t  IntelAmtFw : 1;         // [3]     Intel AMT FW support
  uint32_t  IntelAmtFwStandard : 1; // [4]     Intel AMT Standard FW support
  uint32_t  Reserved1 : 8;          // [12:5]  Reserved
  uint32_t  AtpSupported : 1;       // [13]    At-p Support
  uint32_t  IntelKVM : 1;           // [14]    Intel KVM supported
  uint32_t  LocalWakeupTimer : 1;   // [15]    Local Wakeup Timer support
};
///////////////////////////////////////////////////////////////
struct SMBIOS_Type131
{
   smbios_tbl_hdr			  Header;          // Standard SMBIOS header
   uint32_t                     CpuCap;
   uint16_t                     MebxVer[4];
   uint32_t                     PchCap[2];
   me_cap                     MeCap;
   uint16_t                     MeVer[4];   
   uint8_t                      Rerserve[4];
   uint32_t                     NetworkDev[3];
   uint32_t                     BiosCap;
   uint8_t                      vProSig[4];
   uint32_t                     OtherCap;
};
///////////////////////////////////////////////////////////////
struct SM_BIOS_CAPABILITIES
{	
	uint16_t      MEBx_Major;
    uint16_t      MEBx_Minor;
    uint16_t      MEBx_Hotfix;
    uint16_t      MEBx_Build;
	uint16_t      ME_Major;
    uint16_t      ME_Minor;
    uint16_t      ME_Hotfix;
    uint16_t      ME_Build;
	uint16_t		AT_Allowed:1;				
	uint16_t		AT_Enrolled:1;
	uint16_t		Reserved:14;
};
///////////////////////////////////////////////////////////////
class SMBIOS_Reader
{
public:
	SM_BIOS_CAPABILITIES pCapabilities;	
	SMBIOS_Reader()
	{
		memset(&pCapabilities,0,sizeof(SM_BIOS_CAPABILITIES));	
	};
	~SMBIOS_Reader(){};
	uint32_t CheckForSmbiosFlags();
private:
	uint32_t formatted_table_len(unsigned char*, uint32_t, uint32_t);
	uint32_t unformatted_table_len(unsigned char*, uint32_t, uint32_t);
	bool areSmbiosFlagsSet(unsigned char *smbios_table_data, uint32_t smbios_table_len, SM_BIOS_CAPABILITIES *pBIOSCapabilities);
};
///////////////////////////////////////////////////////////////
#endif // _SMBIOS_READER_H_


