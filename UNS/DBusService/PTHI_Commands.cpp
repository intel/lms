/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2023 Intel Corporation
 */
#include "DBusService.h"
#include "PTHI_Commands.h"
#include "DBus_Commands.h"
#include "PTHI_Commands_BE.h"
#include "Tools.h"
#include "global.h"

namespace Intel {
namespace DBus {
namespace PTHI {

	gboolean on_get_amtversion(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_amtversion\n");
		DBusService *th = (DBusService *)user_data;
		std::string version;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetAMTVersion(version);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", version.c_str()));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_lmsversion(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_lmsversion\n");
		DBusService *th = (DBusService *)user_data;

		try
		{
			std::string version;
			GetLMSProductVersion(version);
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", version.c_str()));
		}
		catch (const std::exception &e)
		{
			UNS_ERROR(L"GetLMSProductVersion failed %C\n", e.what());
			send_error(invocation, Intel::LMS::LMS_ERROR::FAIL);
		}
		return TRUE;
	}

	gboolean on_get_provisioning_state(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_provisioning_state\n");
		DBusService *th = (DBusService *)user_data;
		uint32_t state = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetProvisioningState(state);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", state));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_network_connection_status(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_network_connection_status\n");
		DBusService *th = (DBusService *)user_data;
		uint32_t status = 0, connection_type = 0, connection_trigger = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetNetworkConnectionStatus(
			status, connection_type, connection_trigger);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(uuu)", status, connection_type, connection_trigger));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_user_initiated_enabled(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_user_initiated_enabled\n");
		DBusService *th = (DBusService *)user_data;
		short int state = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetUserInitiatedEnabled(state);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", state));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_power_policy(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_power_policy\n");
		DBusService *th = (DBusService *)user_data;
		std::string policy;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetPowerPolicy(policy);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", policy.c_str()));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_last_reset_reason(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_last_reset_reason\n");
		DBusService *th = (DBusService *)user_data;
		short int reason = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetLastResetReason(reason);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", reason));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_redirection_status(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_redirection_status\n");
		DBusService *th = (DBusService *)user_data;
		uint32_t SOL = 0, IDER = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetRedirectionStatus(SOL, IDER);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(uu)", SOL, IDER));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_system_defense_status(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_system_defense_status\n");
		DBusService *th = (DBusService *)user_data;
		uint32_t status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetSystemDefenseStatus(status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_network_settings(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				guint ConnectionType, gpointer user_data)
	{
		UNS_DEBUG(L"on_get_network_settings %d\n", ConnectionType);
		DBusService *th = (DBusService *)user_data;
		uint32_t DhcpEnabled = 0;
		std::string IpAddress;
		std::string MacAddress;
		short LinkStatus = 0;
		short WirelessControl = 0;
		short WirelessConfEnabled = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetNetworkSettings(ConnectionType,
			DhcpEnabled, IpAddress,MacAddress,LinkStatus, WirelessControl, WirelessConfEnabled);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation,
				g_variant_new ("(ussuuu)",
					DhcpEnabled,
					IpAddress.c_str(),
					MacAddress.c_str(),
					LinkStatus,
					WirelessControl,
					WirelessConfEnabled));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_ipv6_network_settings(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				guint ConnectionType, gpointer user_data)
	{
		UNS_DEBUG(L"on_get_ipv6_network_settings %d\n", ConnectionType);
		DBusService *th = (DBusService *)user_data;
		std::string IPv6DefaultRouter;
		std::string PrimaryDNS;
		std::string SecondaryDNS;
		std::vector<std::string> Response;
		bool Ipv6Enable = false;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetIPv6NetworkSettings(ConnectionType,
			IPv6DefaultRouter, PrimaryDNS, SecondaryDNS, Response, Ipv6Enable);
		if (error == Intel::LMS::LMS_ERROR::OK)
		{
			GVariantBuilder builder;
			GVariantBuilder builder1;

			g_variant_builder_init(&builder, G_VARIANT_TYPE ("as"));
			for (const std::string& i : Response)
				g_variant_builder_add_value(&builder, g_variant_new_string(i.c_str()));
			g_variant_builder_init(&builder1, G_VARIANT_TYPE ("(sssasb)"));
			g_variant_builder_add_value(&builder1, g_variant_new_string(IPv6DefaultRouter.c_str()));
			g_variant_builder_add_value(&builder1, g_variant_new_string(PrimaryDNS.c_str()));
			g_variant_builder_add_value(&builder1, g_variant_new_string(SecondaryDNS.c_str()));
			g_variant_builder_add_value(&builder1, g_variant_builder_end(&builder));
			g_variant_builder_add_value(&builder1, g_variant_new_boolean(Ipv6Enable));
			g_dbus_method_invocation_return_value(invocation, g_variant_builder_end (&builder1));
		}
		else
		{
			send_error(invocation, error);
		}
		return TRUE;
	}

	gboolean on_get_system_uuid(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_system_uuid\n");
		DBusService *th = (DBusService *)user_data;
	 	std::string uuid;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetSystemUUID(uuid);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(s)", uuid.c_str()));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_close_user_initiated_connection(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_close_user_initiated_connection\n");
		DBusService *th = (DBusService *)user_data;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).CloseUserInitiatedConnection();
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_kvmredirection_state(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_kvmredirection_state\n");
		DBusService *th = (DBusService *)user_data;
		bool Enabled = false, Connected = false;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetKVMRedirectionState(Enabled, Connected);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(bb)", Enabled, Connected));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_set_sprite_language(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				guint Language, gpointer user_data)
	{
		UNS_DEBUG(L"on_set_sprite_language %d\n", Language);
		DBusService *th = (DBusService *)user_data;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).SetSpriteLanguage(Language);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_sprite_parameters(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_sprite_parameters\n");
		DBusService *th = (DBusService *)user_data;
		unsigned short int Language = 0;
		unsigned short int Zoom = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetSpriteParameters(Language, Zoom);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(uu)", Language, Zoom));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_set_sprite_zoom(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				guint Zoom, gpointer user_data)
	{
		UNS_DEBUG(L"on_set_sprite_zoom %d\n", Zoom);
		DBusService *th = (DBusService *)user_data;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).SetSpriteZoom(Zoom);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_configuration_info(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_configuration_info\n");
		DBusService *th = (DBusService *)user_data;
		short ControlMode = 0;
		short ProvisioningMethod = 0;
		std::string CreationTimeStamp;
		std::vector<unsigned char> CertHash;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetConfigurationInfo(
			ControlMode, ProvisioningMethod, CreationTimeStamp, CertHash);
		if (error == Intel::LMS::LMS_ERROR::OK)
		{
			GVariantBuilder builder;
			GVariantBuilder builder1;

			g_variant_builder_init(&builder, G_VARIANT_TYPE ("ay"));
			for (const unsigned char& i : CertHash)
				g_variant_builder_add_value(&builder, g_variant_new_byte(i));
			g_variant_builder_init(&builder1, G_VARIANT_TYPE ("(uusay)"));
			g_variant_builder_add_value(&builder1, g_variant_new_uint32(ControlMode));
			g_variant_builder_add_value(&builder1, g_variant_new_uint32(ProvisioningMethod));
			g_variant_builder_add_value(&builder1, g_variant_new_string(CreationTimeStamp.c_str()));
			g_variant_builder_add_value(&builder1, g_variant_builder_end(&builder));
			g_dbus_method_invocation_return_value(invocation, g_variant_builder_end (&builder1));
		}
		else
		{
			send_error(invocation, error);
		}
		return TRUE;
	}

	gboolean on_terminate_remedy_sessions(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_terminate_remedy_sessions\n");
		DBusService *th = (DBusService *)user_data;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).TerminateRemedySessions();
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_user_consent_state(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_user_consent_state\n");
		DBusService *th = (DBusService *)user_data;
		short int State = 0;
		USER_CONSENT_POLICY Policy = NOT_REQUIRED;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetUserConsentState(State, Policy);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(uu)", State, Policy));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_wlanlink_info(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_get_wlanlink_info\n");
		DBusService *th = (DBusService *)user_data;
		uint32_t Preference = 0, Control = 0, Protection = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetWLANLinkInfo(Preference, Control, Protection);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(uuu)", Preference, Control, Protection));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_set_link_preference_to_host(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_set_link_preference_to_host\n");
		DBusService *th = (DBusService *)user_data;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).SetLinkPreferenceToHost();
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_initiate_user_connection(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_initiate_user_connection\n");
		DBusService *th = (DBusService *)user_data;
		short int Status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).InitiateUserConnection(Status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_user_initiated_policy_rule_exists(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_user_initiated_policy_rule_exists\n");
		DBusService *th = (DBusService *)user_data;
		short int Status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).userInitiatedPolicyRuleExists(Status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_user_initiated_policy_rule_for_local_mps_exists(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_user_initiated_policy_rule_for_local_mps_exists\n");
		DBusService *th = (DBusService *)user_data;
		short int Status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).userInitiatedPolicyRuleForLocalMpsExists(Status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_snmp_event_subscriber_exists(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_snmp_event_subscriber_exists\n");
		DBusService *th = (DBusService *)user_data;
		short int Status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).snmpEventSubscriberExists(Status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_cilafilter_collection_subscription_exists(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_cilafilter_collection_subscription_exists\n");
		DBusService *th = (DBusService *)user_data;
		short int Status = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).CILAFilterCollectionSubscriptionExists(Status);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", Status));
		else
			send_error(invocation, error);
		return TRUE;
	}


	gboolean on_update_screen_settings2(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
				GVariant *ExtendedDisplayParameters, guint numOfDisplays,
				gpointer user_data)
	{
		UNS_DEBUG(L"on_update_screen_settings2\n");
		DBusService *th = (DBusService *)user_data;
		EXTENDED_DISPLAY_PARAMETERS eExtendedDisplayParameters;

		if (numOfDisplays > MAX_DISPLAY_NUMBER_LATEST)
		{
			UNS_ERROR(L"on_update_screen_settings2 numOfDisplays %d>%d\n",
				  numOfDisplays, MAX_DISPLAY_NUMBER_LATEST);
			send_error(invocation, Intel::LMS::LMS_ERROR::INVALIDARG);
			return TRUE;
		}

		GVariantIter iter;
		GVariantIter iter1;
		GVariant *child;
		GVariant *child1;
		unsigned int i = 0;

		g_variant_iter_init(&iter, ExtendedDisplayParameters);
		while((child = g_variant_iter_next_value (&iter)))
		{
			if (i >= numOfDisplays)
			{
				g_variant_unref(child);
				UNS_ERROR(L"on_update_screen_settings2 actual numOfDisplays > %d\n",
					  numOfDisplays);
				send_error(invocation, Intel::LMS::LMS_ERROR::INVALIDARG);
				return TRUE;
			}
			int pos = 0;
			g_variant_iter_init(&iter1, child);
			while((child1 = g_variant_iter_next_value (&iter1)))
			{
				switch(pos)
				{
				case 0:
					eExtendedDisplayParameters.DisplayParameters[i].IsActive = g_variant_get_boolean(child1);
					break;
				case 1:
					eExtendedDisplayParameters.DisplayParameters[i].UpperLeftX = g_variant_get_int32(child1);
					break;
				case 2:
					eExtendedDisplayParameters.DisplayParameters[i].UpperLeftY = g_variant_get_int32(child1);
					break;
				case 3:
					eExtendedDisplayParameters.DisplayParameters[i].SizeX = g_variant_get_uint32(child1);
					break;
				case 4:
					eExtendedDisplayParameters.DisplayParameters[i].SizeY = g_variant_get_uint32(child1);
					break;
				case 5:
					eExtendedDisplayParameters.DisplayParameters[i].Pipe = g_variant_get_uint32(child1);
					break;
				default:
					UNS_ERROR(L"on_update_screen_settings2 more then 6 params in line\n");
					break;
				}
				g_variant_unref(child1);
				pos++;
			}
			g_variant_unref(child);
			if (pos != 6)
			{
				UNS_ERROR(L"on_update_screen_settings2 actual parameters %d != 6 on line %u\n", pos, i);
				send_error(invocation, Intel::LMS::LMS_ERROR::INVALIDARG);
				return TRUE;
			}
			i++;
		}
		if (i != numOfDisplays)
		{
			UNS_ERROR(L"on_update_screen_settings2 wrong actual numOfDisplays %d != %d\n",
				  numOfDisplays, i);
			send_error(invocation, Intel::LMS::LMS_ERROR::INVALIDARG);
			return TRUE;
		}

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).UpdateScreenSettings2(eExtendedDisplayParameters, numOfDisplays);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, NULL);
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_get_redirection_session_link_technology(LmsPTHI *skeleton, GDBusMethodInvocation *invocation,
							guint sessionType, gpointer user_data)
	{
		UNS_DEBUG(L"on_get_redirection_session_link_technology %d\n", sessionType);
		DBusService *th = (DBusService *)user_data;
		short LinkTechnology = 0;

		Intel::LMS::LMS_ERROR error = Intel::LMS::PTHI_Commands_BE(th->GetGmsPortForwardingPort()).GetRedirectionSessionLinkTechnology((REDIRECTION_SESSION_TYPE)sessionType, LinkTechnology);
		if (error == Intel::LMS::LMS_ERROR::OK)
			g_dbus_method_invocation_return_value(invocation, g_variant_new ("(u)", LinkTechnology));
		else
			send_error(invocation, error);
		return TRUE;
	}

	gboolean on_bus_acquired(GDBusConnection *connection, LmsPTHI **skeleton,
				 gpointer user_data)
	{
		*skeleton = lms_pthi_skeleton_new();
		g_signal_connect (*skeleton, "handle-get-amtversion",
			G_CALLBACK (on_get_amtversion), user_data);
		g_signal_connect (*skeleton, "handle-get-lmsversion",
			G_CALLBACK (on_get_lmsversion), user_data);
		g_signal_connect (*skeleton, "handle-get-provisioning-state",
			G_CALLBACK (on_get_provisioning_state), user_data);
		g_signal_connect (*skeleton, "handle-get-network-connection-status",
			G_CALLBACK (on_get_network_connection_status), user_data);
		g_signal_connect (*skeleton, "handle-get-user-initiated-enabled",
			G_CALLBACK (on_get_user_initiated_enabled), user_data);
		g_signal_connect (*skeleton, "handle-get-power-policy",
			G_CALLBACK (on_get_power_policy), user_data);
		g_signal_connect (*skeleton, "handle-get-last-reset-reason",
			G_CALLBACK (on_get_last_reset_reason), user_data);
		g_signal_connect (*skeleton, "handle-get-redirection-status",
			G_CALLBACK (on_get_redirection_status), user_data);
		g_signal_connect (*skeleton, "handle-get-system-defense-status",
			G_CALLBACK (on_get_system_defense_status), user_data);
		g_signal_connect (*skeleton, "handle-get-network-settings",
			G_CALLBACK (on_get_network_settings), user_data);
		g_signal_connect (*skeleton, "handle-get-ipv6-network-settings",
			G_CALLBACK (on_get_ipv6_network_settings), user_data);
		g_signal_connect (*skeleton, "handle-get-system-uuid",
			G_CALLBACK (on_get_system_uuid), user_data);
		g_signal_connect (*skeleton, "handle-close-user-initiated-connection",
			G_CALLBACK (on_close_user_initiated_connection), user_data);
		g_signal_connect (*skeleton, "handle-get-kvmredirection-state",
			G_CALLBACK (on_get_kvmredirection_state), user_data);
		g_signal_connect (*skeleton, "handle-set-sprite-language",
			G_CALLBACK (on_set_sprite_language), user_data);
		g_signal_connect (*skeleton, "handle-get-sprite-parameters",
			G_CALLBACK (on_get_sprite_parameters), user_data);
		g_signal_connect (*skeleton, "handle-set-sprite-zoom",
			G_CALLBACK (on_set_sprite_zoom), user_data);
		g_signal_connect (*skeleton, "handle-get-configuration-info",
			G_CALLBACK (on_get_configuration_info), user_data);
		g_signal_connect (*skeleton, "handle-terminate-remedy-sessions",
			G_CALLBACK (on_terminate_remedy_sessions), user_data);
		g_signal_connect (*skeleton, "handle-get-user-consent-state",
			G_CALLBACK (on_get_user_consent_state), user_data);
		g_signal_connect (*skeleton, "handle-get-wlanlink-info",
			G_CALLBACK (on_get_wlanlink_info), user_data);
		g_signal_connect (*skeleton, "handle-set-link-preference-to-host",
			G_CALLBACK (on_set_link_preference_to_host), user_data);
		g_signal_connect (*skeleton, "handle-initiate-user-connection",
			G_CALLBACK (on_initiate_user_connection), user_data);
		g_signal_connect (*skeleton, "handle-user-initiated-policy-rule-exists",
			G_CALLBACK (on_user_initiated_policy_rule_exists), user_data);
		g_signal_connect (*skeleton, "handle-user-initiated-policy-rule-for-local-mps-exists",
			G_CALLBACK (on_user_initiated_policy_rule_for_local_mps_exists), user_data);
		g_signal_connect (*skeleton, "handle-snmp-event-subscriber-exists",
			G_CALLBACK (on_snmp_event_subscriber_exists), user_data);
		g_signal_connect (*skeleton, "handle-cilafilter-collection-subscription-exists",
			G_CALLBACK (on_cilafilter_collection_subscription_exists), user_data);
		g_signal_connect (*skeleton, "handle-update-screen-settings2",
			G_CALLBACK (on_update_screen_settings2), user_data);
		g_signal_connect (*skeleton, "handle-get-redirection-session-link-technology",
			G_CALLBACK (on_get_redirection_session_link_technology), user_data);
		return g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON (*skeleton),
							connection,
							Intel::DBus::OBJ_PATH,
							NULL);
	}
}}} // namespace
