/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2023 Intel Corporation
 */
#include "DBus_Commands.h"
namespace Intel {
namespace DBus {
	const char* OBJ_PATH = "/com/intel/amt/lms";

	void send_error(GDBusMethodInvocation *invocation, Intel::LMS::LMS_ERROR error)
	{
		const gchar *str;
		gint code;
		switch (error)
		{
		case Intel::LMS::LMS_ERROR::UNEXPECTED:
			code = G_IO_ERROR_INVALID_ARGUMENT;
			str = "Unexpected argument";
			break;
		case Intel::LMS::LMS_ERROR::INVALIDARG:
			code = G_IO_ERROR_INVALID_ARGUMENT;
			str = "Invalid argument";
			break;
		case Intel::LMS::LMS_ERROR::NOT_AVAILABLE_NOW:
			code = G_IO_ERROR_BUSY;
			str = "Service is not available now";
			break;
		case Intel::LMS::LMS_ERROR::NOT_SUPPORTED_BY_FW:
			code = G_IO_ERROR_NOT_SUPPORTED;
			str = "Request is not supported by system";
			break;
		case Intel::LMS::LMS_ERROR::FAIL:
		default:
			code = G_IO_ERROR_FAILED;
			str = "Internal error";
		}
		g_dbus_method_invocation_return_error_literal (
			invocation, G_IO_ERROR, code, str);
	}

}} // namespace
