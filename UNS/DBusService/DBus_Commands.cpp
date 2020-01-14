/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2020 Intel Corporation
 */
#include "DBus_Commands.h"
namespace Intel {
namespace DBus {

	void send_error(GDBusMethodInvocation *invocation, Intel::LMS::LMS_ERROR error)
	{
		const gchar *str;
		gint code;
		switch (error)
		{
		case Intel::LMS::ERROR_UNEXPECTED:
			code = G_IO_ERROR_INVALID_ARGUMENT;
			str = "Unexpected argument";
			break;
		case Intel::LMS::ERROR_INVALIDARG:
			code = G_IO_ERROR_INVALID_ARGUMENT;
			str = "Invalid argument";
			break;
		case Intel::LMS::ERROR_NOT_AVAILABLE_NOW:
			code = G_IO_ERROR_BUSY;
			str = "Service is not available now";
			break;
		case Intel::LMS::ERROR_NOT_SUPPORTED_BY_FW:
			code = G_IO_ERROR_NOT_SUPPORTED;
			str = "Request is not suported by system";
			break;
		case Intel::LMS::ERROR_FAIL:
		default:
			code = G_IO_ERROR_FAILED;
			str = "Internal error";
		}
		g_dbus_method_invocation_return_error_literal (
			invocation, G_IO_ERROR, code, str);
	}

}} // namespace
