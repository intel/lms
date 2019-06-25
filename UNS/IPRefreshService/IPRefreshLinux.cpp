/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "IPRefreshService.h"
#include "Tools.h"
#include <netlink/route/link.h>

static bool runDHClient(const char* name, bool renew)
{
	UNS_DEBUG(L"IPRefresh - runDHClient %C %d\n", name, renew);
	pid_t cpid = fork();
	if (cpid == -1) {
		UNS_DEBUG(L"IPRefresh - fork failed %d\n", errno);
		return false;
	} else if (cpid == 0) {
		//child
		const char *op = renew ? "-1" : "-r";
		std::vector<char*> cmd =
			{ NULL, const_cast<char*>(op), const_cast<char*>(name), NULL };
		char *env[] = { NULL };
		int ret = execve("/sbin/dhclient", cmd.data(), env);
		if (ret)
			exit(errno);
	} else {
		pid_t w;
		int stat;
		w = waitpid(cpid, &stat, 0);
		if (w == -1) {
			UNS_DEBUG(L"IPRefresh - waitpid failed %d\n", errno);
			return false;
		} else if (WIFEXITED(stat)) {
			if (!WEXITSTATUS(stat)) {
				UNS_DEBUG(L"IPRefresh - dhclient succeeded.\n");
				return true;
			} else {
				UNS_DEBUG(L"IPRefresh - dhclient failed %d\n",
					  WEXITSTATUS(stat));
				return false;
			}
		} else if (WIFSIGNALED(stat)) {
			UNS_DEBUG(L"IPRefresh - dhclient killed %d\n",
				  WTERMSIG(stat));
			return false;
		}
	}
}

//Main flow
bool IPRefreshService::IPRefresh(unsigned int nicType)
{
	int adaptorID;
	bool status;
	int ret;

	if (!GetAdaptorIDs())
		return false;
	if (nicType == 0) adaptorID = wiredAdaptorID;
	else adaptorID = wirelessAdaptorID;

	struct nl_cache *link_cache;
	struct nl_sock *sock;
	struct rtnl_link *link;

	sock = nl_socket_alloc();
	if (!sock) {
		UNS_DEBUG(L"IPRefresh - nl_socket_alloc failed\n");
		status = false;
		return status;
	}
	ret = nl_connect(sock, NETLINK_ROUTE);
	if (ret) {
		UNS_DEBUG(L"IPRefresh - nl_connect failed %d\n", ret);
		status = false;
		goto out;
	}
	ret = rtnl_link_alloc_cache(sock, AF_UNSPEC, &link_cache);
	if (ret) {
		UNS_DEBUG(L"IPRefresh - rtnl_link_alloc_cache failed %d\n", ret);
		status = false;
		goto out;
	}

	status = true;
	link = rtnl_link_get(link_cache, adaptorID);
	if (link) {
		const char* name = rtnl_link_get_name(link);
		if (!name) {
			UNS_DEBUG(L"IPRefresh - rtnl_link_get_name failed\n");
			status = false;
		} else {
			runDHClient(name, false); //release - not really interesting if succeeded
			status = runDHClient(name, true); //renew
			if (status) {
				UNS_DEBUG(L"IP renew succeeded.\n");
				publishIPRefreshEvent(nicType==1);
			}
		}
		rtnl_link_put(link);
	} else {
		UNS_DEBUG(L"IPRefresh - adaptor %d not found\n", adaptorID);
	}

	nl_cache_free(link_cache);
out:
	nl_socket_free(sock);
	return status;
}

bool IPRefreshService::FillAdaptorIDs()
{
	int ret;
	bool status;

	struct nl_cache *link_cache;
	struct nl_sock *sock;
	struct nl_object *obj;
	char buf[128];
	buf[127] = '\0';

	sock = nl_socket_alloc();
	if (!sock) {
		UNS_DEBUG(L"GetAdaptorIDs - nl_socket_alloc failed\n");
		status = false;
		return status;
	}
	ret = nl_connect(sock, NETLINK_ROUTE);
	if (ret) {
		UNS_DEBUG(L"GetAdaptorIDs - nl_connect failed %d\n", ret);
		status = false;
		goto out;
	}
	ret = rtnl_link_alloc_cache(sock, AF_UNSPEC, &link_cache);
	if (ret) {
		UNS_DEBUG(L"GetAdaptorIDs - rtnl_link_alloc_cache failed %d\n", ret);
		status = false;
		goto out;
	}

	obj = nl_cache_get_first(link_cache);
	while (obj) {
		struct rtnl_link *link = (struct rtnl_link *) obj;

		struct nl_addr *addr = rtnl_link_get_addr(link);
		if (!addr) {
			continue;
		}

		nl_addr2str(addr, buf, sizeof(buf) - 1);
		UNS_DEBUG(L"GetAdaptorIDs addr %C\n", buf);
		if (wiredMacAddress == buf) {
			if (rtnl_link_get_ifindex(link)) {
				wiredAdaptorID = rtnl_link_get_ifindex(link);
				UNS_DEBUG(L"GetAdaptorIDs wiredAdaptorID %d\n", wiredAdaptorID);
				wiredAdaptorID_updated = true;
			}
		}
		else if (wirelessMacAddress == buf) {
			if (rtnl_link_get_ifindex(link)) {
				wirelessAdaptorID = rtnl_link_get_ifindex(link);
				UNS_DEBUG(L"GetAdaptorIDs wirelessAdaptorID %d\n", wirelessAdaptorID);
				wirelessAdaptorID_updated = true;
			}
		}

		obj = nl_cache_get_next(obj);
	}

	nl_cache_free(link_cache);
	status = true;
out:
	nl_socket_free(sock);
	return status;
}
