/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: LMS_if.h

--*/

#ifndef _LMS_IF_H_
#define _LMS_IF_H_

#include "LMS_if_constants.h"

// disable the "zero-sized array" warning
#ifdef WIN32
#pragma warning(disable:4200)
#endif

#pragma pack(1)

typedef struct
{
   uint8_t MessageType;
} APF_MESSAGE_HEADER;


/**
 * APF_GENERIC_HEADER - generic request header (note that its not complete header per protocol (missing WantReply)
 *
 * @MessageType:
 * @RequestStringLength: length of the string identifies the request
 * @RequestString: the string that identifies the request
 **/

typedef struct
{
   uint8_t MessageType;
   uint32_t StringLength;
   uint8_t String[0];
} APF_GENERIC_HEADER;

/**
 * TCP forward reply message
 * @MessageType - Protocol's Major version
 * @PortBound - the TCP port was bound on the server
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t PortBound;
} APF_TCP_FORWARD_REPLY_MESSAGE;

/**
 * response to ChannelOpen when channel open succeed
 * @MessageType - APF_CHANNEL_OPEN_CONFIRMATION
 * @RecipientChannel - channel number given in the open request
 * @SenderChannel - channel number assigned by the sender
 * @InitialWindowSize - Number of bytes in the window
 * @Reserved - Reserved
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t RecipientChannel;
   uint32_t SenderChannel;
   uint32_t InitialWindowSize;
   uint32_t Reserved;
} APF_CHANNEL_OPEN_CONFIRMATION_MESSAGE;

/**
 * response to ChannelOpen when a channel open failed
 * @MessageType - APF_CHANNEL_OPEN_FAILURE
 * @RecipientChannel - channel number given in the open request
 * @ReasonCode - code for the reason channel could not be open
 * @Reserved - Reserved
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t RecipientChannel;
   uint32_t ReasonCode;
   uint32_t Reserved;
   uint32_t Reserved2;
} APF_CHANNEL_OPEN_FAILURE_MESSAGE;

/**
 * close channel message
 * @MessageType - APF_CHANNEL_CLOSE
 * @RecipientChannel - channel number given in the open request
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t RecipientChannel;
} APF_CHANNEL_CLOSE_MESSAGE;

/**
 * used to send/receive data.
 * @MessageType - APF_CHANNEL_DATA
 * @RecipientChannel - channel number given in the open request
 * @Length - Length of the data in the message
 * @Data - The data in the message
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t RecipientChannel;
   uint32_t DataLength;
   uint8_t Data[0];
} APF_CHANNEL_DATA_MESSAGE;

/**
 * used to adjust receive window size .
 * @MessageType - APF_WINDOW_ADJUST
 * @RecipientChannel - channel number given in the open request
 * @BytesToAdd - number of bytes to add to current window size value
 **/
typedef struct
{
   uint8_t MessageType;
   uint32_t RecipientChannel;
   uint32_t BytesToAdd;
} APF_WINDOW_ADJUST_MESSAGE;

/**
 * This message causes immediate termination of the connection with AMT.
 * @ReasonCode -  A Reason code for the disconnection event
 * @Reserved - Reserved must be set to 0
 **/
typedef struct
{
	uint8_t MessageType;
	uint32_t ReasonCode;
	uint16_t Reserved;
} APF_DISCONNECT_MESSAGE;

/**
 * Used to request a service identified by name
 * @ServiceNameLength -  The length of the service name string.
 * @ServiceName - The name of the service being requested.
 **/
typedef struct
{
	uint8_t MessageType;
	uint32_t ServiceNameLength;
	uint8_t ServiceName[0];
} APF_SERVICE_REQUEST_MESSAGE;

/**
 * Used to send a service accept identified by name
 * @ServiceNameLength -  The length of the service name string.
 * @ServiceName - The name of the service being requested.
 **/
typedef struct
{
	uint8_t MessageType;
	uint32_t ServiceNameLength;
	uint8_t ServiceName[0];
} APF_SERVICE_ACCEPT_MESSAGE;

/**
 * holds the protocol major and minor version implemented by AMT.
 * @MajorVersion - Protocol's Major version
 * @MinorVersion - Protocol's Minor version
 * @Trigger - The open session reason
 * @UUID - System Id
 **/
typedef struct
{
	uint8_t MessageType;
	uint32_t MajorVersion;
	uint32_t MinorVersion;
	uint32_t TriggerReason;
	uint8_t UUID[16];
	uint8_t Reserved[64];
} APF_PROTOCOL_VERSION_MESSAGE;

/**
 * holds the user authentication request.
 * @UsernameLength - The length of the user name string.
 * @Username - The name of the user in ASCII encoding. Maximum allowed size is 64 bytes.
 * @ServiceNameLength - The length of the service name string.
 * @ServiceName - The name of the service to authorize.
 * @MethodNameLength - The length of the method name string.
 * @MethodName - The authentication method to use.
 **/
//typedef struct
//{
//	uint8_t MessageType;
//	uint32_t UsernameLength;
//	uint8_t Username[0];
//	uint32_t ServiceNameLength;
//	uint8_t ServiceName[0];
//	uint32_t MethodNameLength;
//	uint8_t MethodName[0];
//} APF_USERAUTH_REQUEST_MESSAGE;

/**
 * holds the user authentication request failure response.
 * @MethodNameListLength - The length of the methods list string.
 * @MethodNameList - A comma separated string of authentication
 *                   methods supported by the server in ASCII.
 **/
//typedef struct
//{
//	uint8_t MessageType;
//	uint32_t MethodNameListLength;
//	uint8_t MethodNameList[0];
//	uint8_t Reserved;
//} APF_USERAUTH_FAILURE_MESSAGE;

/**
 * holds the user authentication request success response.
 **/
typedef struct
{
	uint8_t MessageType;
} APF_USERAUTH_SUCCESS_MESSAGE;

#pragma pack()

#endif
