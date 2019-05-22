/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2018 Intel Corporation
 */
#ifndef __DBUSSERVICE_H_
#define __DBUSSERVICE_H_

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

	virtual int svc();

	bool emit_alarm(unsigned int category, unsigned int id,
			const char* message, const char *arg,
			const char *msg_id, const char* date);

	void stop();

private:
	DBusService *m_father;
	GMainLoop *m_loop;

	Lms *m_skeleton;
	LmsManageability *m_skeleton_manageability;
	LmsPTHI *m_skeleton_pthi;
	LmsAT_Device *m_skeleton_device;
	LmsUNSAlert *m_skeleton_alert;

	static void on_bus_acquired(GDBusConnection *connection,
				    const gchar *name, gpointer user_data);

	static void on_name_lost(GDBusConnection *connection,
				 const gchar *name, gpointer user_data);
};

class DBUSSERVICE_Export DBusService : public EventHandler
{
public:
	DBusService();
	// ********************* ACE PART ********************************
	virtual int init (int argc, ACE_TCHAR *argv[]);
	virtual int fini (void);

	virtual const ACE_TString name();

	//*********************** business logic ****************************
	bool GetGmsPortForwardingStarted();
protected:
	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return filter_;
	}
private:
	DBusThread m_DBusThread;

	void SendAlarm(GMS_AlertIndication* alert);

	void initFilter();
	std::shared_ptr<DBusFilter> filter_;
};

#endif /* __DBUSSERVICE_H_ */
