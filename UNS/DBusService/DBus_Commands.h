/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2018 Intel Corporation
 */
#ifndef _DBUS_COMMANDS_H
#define _DBUS_COMMANDS_H
#include <gio/gio.h>
#include "DataInterfaceBackend.h"
namespace Intel {
namespace DBus {
	void send_error(GDBusMethodInvocation *invocation, Intel::LMS::LMS_ERROR error);
	static const char* OBJ_PATH = "/com/intel/amt/lms";
}} // namespace
#endif // _DBUS_COMMANDS_H
