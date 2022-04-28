/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2022 Intel Corporation
 */
#include "DBusService.h"
#include "UNSAlert.h"
#include "DBus_Commands.h"
#include "UNSAlert_BE.h"
#include "global.h"
#include <locale>
#include <codecvt>

namespace Intel {
namespace DBus {
namespace UNSAlert {
	gboolean on_get_imssevent_history(LmsUNSAlert *skeleton, GDBusMethodInvocation *invocation,
					  gpointer user_data)
	{
		UNS_DEBUG(L"on_get_imssevent_history\n");
		DBusService *th = (DBusService *)user_data;
		std::wstring str;

		Intel::LMS::LMS_ERROR error =
			Intel::LMS::UNSAlert_BE(th->GetGmsPortForwardingStarted()).GetIMSSEventHistory(str);
		if (error == Intel::LMS::LMS_ERROR::OK)
		{
			try
			{
				std::string buf = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(str);
				g_dbus_method_invocation_return_value(invocation, g_variant_new("(s)", buf.c_str()));
			}
			catch (const std::range_error&)
			{
				send_error(invocation, Intel::LMS::LMS_ERROR::FAIL);
			}
		}
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_bus_acquired(GDBusConnection *connection, LmsUNSAlert **skeleton,
				 gpointer user_data)
	{
		*skeleton = lms_unsalert_skeleton_new();
		g_signal_connect(*skeleton, "handle-get-imssevent-history",
				 G_CALLBACK(on_get_imssevent_history), user_data);
		return g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON (*skeleton),
							connection,
							Intel::DBus::OBJ_PATH,
							NULL);
	}
}}} // namespace
