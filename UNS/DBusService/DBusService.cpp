/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2020 Intel Corporation
 */
#include <gio/gio.h>

#include "DBusService.h"
#include "DBusSkeleton.h"

DBusThread::DBusThread(DBusService *father) : m_father(father),
					  m_loop(g_main_loop_new(NULL, FALSE)),
					  m_skeleton(NULL),
					  m_skeleton_manageability(NULL),
					  m_skeleton_pthi(NULL),
					  m_skeleton_device(NULL),
					  m_skeleton_alert(NULL)
{
}

DBusThread::~DBusThread()
{
	g_main_loop_unref(m_loop);
}

int DBusThread::svc()
{
	UNS_DEBUG(L"Main DBus Thread started\n");

	guint owner_id;

	if (!m_loop)
	{
		UNS_ERROR(L"Main DBus Thread m_loop is NULL\n");
		return 0;
	}
	owner_id = g_bus_own_name(G_BUS_TYPE_SYSTEM,
				  lms_interface_info()->name, //"com.intel.amt.lms",
				  G_BUS_NAME_OWNER_FLAGS_NONE,
				  on_bus_acquired,
				  NULL, /*on_name_acquired*/
				  on_name_lost,
				  this,
				  NULL);
	UNS_DEBUG(L"Main DBus Thread owner_id %d\n", owner_id);

	g_main_loop_run(m_loop);

	g_bus_unown_name(owner_id);
	UNS_DEBUG(L"Main DBus Thread stopped\n");

	return 0;
}

bool DBusThread::emit_alarm(unsigned int category, unsigned int id,
			    const char* message, const char *arg,
			    const char *msg_id, const char* date)
{
	if (!m_skeleton)
		return false;
	lms_emit_alert(m_skeleton, category, id, message, arg, msg_id, date);
	return true;
}

void DBusThread::stop()
{
	if (m_loop)
		g_main_loop_quit(m_loop);
}

void DBusThread::on_bus_acquired(GDBusConnection *connection,
			    const gchar *name, gpointer user_data)
{
	DBusThread *th = (DBusThread *)user_data;

	UNS_DEBUG(L"Main DBus Thread on_bus_acquired\n");
	th->m_skeleton = lms_skeleton_new();
	gboolean ret = g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON (th->m_skeleton),
							connection,
							Intel::DBus::OBJ_PATH,
							NULL);
	Intel::DBus::Manageability::on_bus_acquired(connection, &th->m_skeleton_manageability, th->m_father);
	Intel::DBus::PTHI::on_bus_acquired(connection, &th->m_skeleton_pthi, th->m_father);
	Intel::DBus::AT_Device::on_bus_acquired(connection, &th->m_skeleton_device, th->m_father);
	Intel::DBus::UNSAlert::on_bus_acquired(connection, &th->m_skeleton_alert, th->m_father);
	UNS_DEBUG(L"Main DBus Thread on_bus_acquired %d\n", ret);
}

void DBusThread::on_name_lost(GDBusConnection *connection,
			 const gchar *name, gpointer user_data)
{
	DBusThread *th = (DBusThread *)user_data;

	UNS_DEBUG(L"Main DBus Thread on_name_lost\n");

	g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON(th->m_skeleton));
	g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON(th->m_skeleton_manageability));
	g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON(th->m_skeleton_pthi));
	g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON(th->m_skeleton_device));
	g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON(th->m_skeleton_alert));
}

DBusService::DBusService(): m_DBusThread(this), filter_(new DBusFilter)
{
	DBusFilter::defaultInitialization(filter_);
}

int DBusService::init(int argc, ACE_TCHAR *argv[])
{
	int ret = EventHandler::init(argc, argv);
	if (ret)
		return ret;

	m_DBusThread.activate();

	return 0;
}

int DBusService::fini (void)
{
	UNS_DEBUG(L"DBusService service stopped\n");

	m_DBusThread.stop();
	m_DBusThread.thr_mgr()->wait_task(&m_DBusThread);

	return 0;
}

const ACE_TString DBusService::name()
{
	return GMS_DBUSSERVICE;
}

LMS_SUBSERVICE_DEFINE (DBUSSERVICE, DBusService)

void DBusService::SendAlarm(GMS_AlertIndication* alert)
{
	if (!m_DBusThread.emit_alarm(alert->category, alert->id,
	     ACE_TEXT_ALWAYS_CHAR(alert->Message.c_str()),
	     (alert->MessageArguments.size() > 0) ? ACE_TEXT_ALWAYS_CHAR(alert->MessageArguments[0].c_str()) : "",
	     ACE_TEXT_ALWAYS_CHAR(alert->MessageID.c_str()), alert->Datetime.c_str()))
		UNS_ERROR(L"DBusService can't send alarm\n");
}

int DBusService::handle_event(MessageBlockPtr mbPtr)
{
	FuncEntryExit<void> fee(this, L"handle_event");
	int type = mbPtr->msg_type();
	GMS_AlertIndication *pGMS_AlertIndication = nullptr;
	switch (type)
	{
	case MB_PUBLISH_EVENT:
		pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
		if (pGMS_AlertIndication)
			SendAlarm(pGMS_AlertIndication);
		break;
	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT ("DBusService::Invalid Message.\n")), -1);
	}
	return 0;
}

bool DBusService::GetGmsPortForwardingStarted()
{
	return m_mainService->GetPortForwardingStarted();
}
