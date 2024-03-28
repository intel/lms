/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2024 Intel Corporation
 */
#ifndef __DBUSSERVICE_H_
#define __DBUSSERVICE_H_

#include <mutex>
#include <vector>

#include "EventHandler.h"
#include "DBusFilter.h"
#include "DBUSSERVICE_export.h"

#include "DBus_Commands.h"
#include "Manageability_Commands.h"
#include "PTHI_Commands.h"
#include "AT_Device.h"
#include "UNSAlert.h"

class DBusService;

class DBusThread : public ACE_Task<ACE_MT_SYNCH>
{

public:
	DBusThread(DBusService *father);
	virtual ~DBusThread();
	DBusThread(const DBusThread&) = delete;
	DBusThread& operator = (const DBusThread&) = delete;

	virtual int svc();

	bool emit_alarm(const GMS_AlertIndication* alert);

	void stop();

private:
	DBusService *m_father;
	GMainLoop *m_loop;

	Lms *m_skeleton;
	LmsManageability *m_skeleton_manageability;
	LmsPTHI *m_skeleton_pthi;
	LmsAT_Device *m_skeleton_device;
	LmsUNSAlert *m_skeleton_alert;

	std::mutex m_mutex;
	bool m_have_bus;
	std::vector<GMS_AlertIndication> m_store;

	static void on_bus_acquired(GDBusConnection *connection,
				    const gchar *name, gpointer user_data);

	static void on_name_lost(GDBusConnection *connection,
				 const gchar *name, gpointer user_data);

	void send_alarm(const GMS_AlertIndication* alert);
};

class DBUSSERVICE_Export DBusService : public EventHandler
{
public:
	DBusService();
	// ********************* ACE PART ********************************
	virtual int init (int argc, ACE_TCHAR *argv[]);
	virtual int fini (void);

	virtual const ACE_TString name();
	const wchar_t *short_name() const { return L"DBUS"; };

	//*********************** business logic ****************************
	unsigned int GetGmsPortForwardingPort();
protected:
	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}
private:
	DBusThread m_DBusThread;

	void SendAlarm(const GMS_AlertIndication* alert);

	std::shared_ptr<DBusFilter> filter_;
};

#endif /* __DBUSSERVICE_H_ */
