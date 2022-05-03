/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2022 Intel Corporation
 */
#ifndef SOAP_HANDLER
#define SOAP_HANDLER

#include <vector>
#include <string>

class SOAP_Handler
{
public:
	SOAP_Handler(void);
	virtual ~SOAP_Handler(void);

	// Disable operator= and CopyConstructor. We do not expect this class to be duplicated in any way
	SOAP_Handler &operator=(const SOAP_Handler &other) = delete;
	SOAP_Handler(const SOAP_Handler &) = delete;

	bool handle_input(const char *data, size_t size);

private:
	std::string buf;
	bool event_sent;

	int read_and_parse_input(const char *data, size_t size, std::string &TestMessageId, std::string &TestMessageArg, std::string &TestMessageText, bool *finished);
	int parse_message(const std::string &xmlMessage, std::string &TestMessageId, std::string &TestMessageArg, std::string &TestMessageText, bool *finished);
	bool HandleCimAlert(const std::string &TestMessageId, const std::string &TestMessageArg, const std::string &TestMessageText);
};
#endif // SOAP_HANDLER
