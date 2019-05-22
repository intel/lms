/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2018 Intel Corporation
 */
#include "DBusSkeleton.h"

namespace Intel {
namespace DBus {
namespace PTHI {
	gboolean on_bus_acquired(GDBusConnection *connection, LmsPTHI **skeleton,
				gpointer user_data);
}}} //namespace
