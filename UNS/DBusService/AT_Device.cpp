/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2019 Intel Corporation
 */
#include "DBusService.h"
#include "AT_Device.h"
#include "DBus_Commands.h"
#include "AT_Device_BE.h"
#include "global.h"
namespace Intel {
namespace DBus {
namespace AT_Device {
	gboolean on_get_audit_logs(LmsAT_Device *skeleton,
				   GDBusMethodInvocation *invocation,
				   gpointer user_data)
	{
		UNS_DEBUG(L"on_get_audit_logs\n");
		DBusService *th = (DBusService *)user_data;
		std::string logs;

		Intel::LMS::LMS_ERROR error =
			Intel::LMS::AT_Device_BE(th->GetGmsPortForwardingStarted()).GetAuditLogs(logs);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", logs.c_str()));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_bus_acquired(GDBusConnection *connection,
				 LmsAT_Device **skeleton,
				 gpointer user_data)
	{
		*skeleton = lms_at__device_skeleton_new();
		g_signal_connect(*skeleton, "handle-get-audit-logs",
				 G_CALLBACK(on_get_audit_logs), user_data);
		return g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON (*skeleton),
							connection,
							Intel::DBus::OBJ_PATH,
							NULL);
	}
}}} // namespace
