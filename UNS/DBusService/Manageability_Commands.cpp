/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2021 Intel Corporation
 */
#include "DBusService.h"
#include "Manageability_Commands.h"
#include "DBus_Commands.h"
#include "Manageability_Commands_BE.h"
#include "global.h"
namespace Intel {
namespace DBus {
namespace Manageability {

	gboolean on_get_the_feature_state(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
                                          guint Feat, gpointer user_data)
	{
		UNS_DEBUG(L"on_get_the_feature_state %d\n", Feat);
		DBusService *th = (DBusService *)user_data;
		FEATURE_STATE state = NOT_PRESENT;

		Intel::LMS::LMS_ERROR error = Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).GetTheFeatureState((FEATURES)Feat, state);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", state));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_customer_type(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
				      gpointer user_data)
	{
		UNS_DEBUG(L"on_get_customer_type\n");
		DBusService *th = (DBusService *)user_data;
		CUSTOMER_TYPE customer_type = WRONG_CUSTOMER_TYPE;

		Intel::LMS::LMS_ERROR error = Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).GetCustomerType(customer_type);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", customer_type));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_menageabilty_mode(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
					  gpointer user_data)
	{
		UNS_DEBUG(L"on_get_menageabilty_mode\n");
		DBusService *th = (DBusService *)user_data;
		MENAGEABILTY_MODE menageabilty_mode = NOT_KNOWN;

		Intel::LMS::LMS_ERROR error = Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).GetMenageabiltyMode(menageabilty_mode);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", menageabilty_mode));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_fwinfo(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
			       gpointer user_data)
	{
		UNS_DEBUG(L"on_get_fwinfo\n");
		DBusService *th = (DBusService *)user_data;
		std::string MEBxVersion;
		unsigned long BiosBootState = 0;
		bool CryptoFuseEnable = false;
		bool LocalFWupdateEnable = false;

		Intel::LMS::LMS_ERROR error = Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).GetFWInfo(MEBxVersion, BiosBootState, CryptoFuseEnable, LocalFWupdateEnable);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(subb)", MEBxVersion.c_str(), BiosBootState, CryptoFuseEnable, LocalFWupdateEnable));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_pmc_version(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
				    gpointer user_data)
	{
		UNS_DEBUG(L"on_get_pmc_version\n");
		DBusService *th = (DBusService *)user_data;
		std::string version;

		Intel::LMS::LMS_ERROR error =
			Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).GetPMCVersion(version);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", version.c_str()));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_is_measured_boot_state(LmsManageability *skeleton, GDBusMethodInvocation *invocation,
					   gpointer user_data)
	{
		UNS_DEBUG(L"on_is_measured_boot_state\n");
		DBusService *th = (DBusService *)user_data;
		bool Status = false;

		Intel::LMS::LMS_ERROR error = Intel::LMS::Manageability_Commands_BE(th->GetGmsPortForwardingStarted()).IsMeasuredBootState(Status);
		if (!error)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_bus_acquired(GDBusConnection *connection, LmsManageability **skeleton_manageability,
				 gpointer user_data)
	{
		*skeleton_manageability = lms_manageability_skeleton_new();
		g_signal_connect (*skeleton_manageability, "handle-get-the-feature-state",
			G_CALLBACK (on_get_the_feature_state), user_data);
		g_signal_connect (*skeleton_manageability, "handle-get-customer-type",
			G_CALLBACK (on_get_customer_type), user_data);
		g_signal_connect (*skeleton_manageability, "handle-get-menageabilty-mode",
			G_CALLBACK (on_get_menageabilty_mode), user_data);
		g_signal_connect (*skeleton_manageability, "handle-get-fwinfo",
			G_CALLBACK (on_get_fwinfo), user_data);
		g_signal_connect (*skeleton_manageability, "handle-get-pmcversion",
			G_CALLBACK (on_get_pmc_version), user_data);
		g_signal_connect (*skeleton_manageability, "handle-is-measured-boot-state",
			G_CALLBACK (on_is_measured_boot_state), user_data);
		return g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(*skeleton_manageability),
							connection,
							Intel::DBus::OBJ_PATH,
							NULL);
	}
}}} // namespace
