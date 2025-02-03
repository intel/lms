/*******************************************************************************
 * Copyright (C) 2004-2006 Intel Corp. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  - Neither the name of Intel Corp. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

/**
 * @author Anas Nashif
 */

#ifdef HAVE_CONFIG_H
#include <wsman_config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <string.h>

#include <errno.h>
#include <assert.h>

#include "u/libu.h"
#include "wsmand-daemon.h"
#include "wsman-server-api.h"

#ifdef PACKAGE_SUBSCRIPTION_DIR
#define DEFAULT_SUBSCRIPTION_REPOSITORY PACKAGE_SUBSCRIPTION_DIR
#else
#define DEFAULT_SUBSCRIPTION_REPOSITORY "/var/lib/openwsman/subscriptions"
#endif
#ifdef __APPLE__
#define DEFAULT_BASIC_AUTH  "libwsman_file_auth.dylib"
#else
#define DEFAULT_BASIC_AUTH  "libwsman_file_auth.so"
#endif

int facility = LOG_DAEMON;

static const char **wsmand_argv = NULL;


static int server_port = -1;
static int server_ssl_port = -1;
static int use_ipv4 = 1;
#ifdef ENABLE_IPV6
static int use_ipv6 = 0;
#endif
static int use_digest = 0;
static char *ssl_key_file = NULL;
static char *service_path = DEFAULT_SERVICE_PATH;
static char *ssl_cert_file = NULL;
static char *ssl_disabled_protocols = NULL;
static char *ssl_cipher_list = NULL;
static char *pid_file = DEFAULT_PID_PATH;
static char *uri_subscription_repository = DEFAULT_SUBSCRIPTION_REPOSITORY;
static int daemon_flag = 0;
static int no_plugin_flag = 0;
static int use_ssl = 0;
static int debug_level = -1;
static int foreground_debug = 0;
static int syslog_level = -1;
static char *log_location = NULL;
static char *digest_password_file = NULL;
static char *basic_password_file = NULL;
static char *custom_anon_identify_file = NULL;
static char *custom_identify_file = NULL;
static char *basic_authenticator_arg = NULL;
static char *basic_authenticator = DEFAULT_BASIC_AUTH;
static int max_threads = 1;
static unsigned long enumIdleTimeout = 100;
static char *thread_stack_size="0";
static int max_connections_per_thread=20;
static char *auth_dir = PACKAGE_AUTH_DIR;
static char *plugin_dir = PACKAGE_PLUGIN_DIR;
static char *config_file = NULL;



int wsmand_parse_options(int argc, char **argv)
{
	char retval;
	u_option_context_t *opt_ctx;
	u_error_t *error = NULL;
	char *version = NULL;

	u_option_entry_t options[] = {
#if 0
		{"no-plugins", 'n', U_OPTION_ARG_NONE, &no_plugin_flag,
		 "Do not load any plugins", NULL},
#endif
		{"ssl", 'S', U_OPTION_ARG_NONE, &use_ssl,
		 "Use SSL port", NULL},
		{"version", 'q', U_OPTION_ARG_NONE, &version,
		 "Display application version", NULL},
		{"debug", 'd', U_OPTION_ARG_NONE, &foreground_debug,
		 "Start daemon in foreground and turn on debugging", NULL},
		{"syslog", 's', U_OPTION_ARG_INT, &syslog_level,
		 "Set the verbosity of syslog output.", "0-6"},
		{"enum-idle-timeout", 'e', U_OPTION_ARG_INT,
		 &enumIdleTimeout,
		 "Enumeration Idle timeout in secs", "default 100"},
		{"config-file", 'c', U_OPTION_ARG_STRING, &config_file,
		 "Alternate configuration file", "<file>"},
		{"pid-file", 'p', U_OPTION_ARG_STRING, &pid_file,
		 "PID file", "<file>"},
		{"subscription-repository-location", 'r',  U_OPTION_ARG_STRING, &uri_subscription_repository,
		"Subscription Repository Location", "<uri>"},
		{"auth-dir", 'a', U_OPTION_ARG_STRING, &auth_dir,
		 "Authentication plugin dir (testing)", "<directory>"},
		{"basic-password-file", 'b', U_OPTION_ARG_STRING, &basic_password_file,
		 "Basic password file (testing)", "<file>"},
		{"plugin-dir", 'P', U_OPTION_ARG_STRING, &plugin_dir,
		 "Dispatcher plugins directory (testing)", "<directory>"},
		{NULL}
	};

	wsmand_argv = (const char **) argv;
	opt_ctx = u_option_context_new("WS-Management Server");
	if (!opt_ctx)
		return 0;
	u_option_context_set_ignore_unknown_options(opt_ctx, FALSE);
	u_option_context_add_main_entries(opt_ctx, options, "wsman");
	retval = u_option_context_parse(opt_ctx, &argc, &argv, &error);
	if (error) {
		if (error->message)
			printf("%s\n", error->message);
		retval = 0;
	}
	if (version) {
		fprintf(stdout, PACKAGE_NAME " " PACKAGE_VERSION "\n\n");
		exit(0);
	}
	
	u_error_free(error);
	u_option_context_free(opt_ctx);
	return retval;
}

const char **wsmand_options_get_argv(void)
{
	return wsmand_argv;
}

int wsmand_read_config(dictionary * ini)
{
	if (!iniparser_find_entry(ini, "server")) {
		return 0;
	}

	server_port = iniparser_getint(ini, "server:port", 5985);
	server_ssl_port = iniparser_getint(ini, "server:ssl_port", 5986);
	debug_level = iniparser_getint(ini, "server:debug_level", 0);
	enumIdleTimeout =
	    (unsigned long) iniparser_getint(ini,
					     "server:enum_idle_timeout",
					     100);
	service_path =
	    iniparser_getstring(ini, "server:service_path", "/wsman");
	ssl_key_file = iniparser_getstr(ini, "server:ssl_key_file");
	ssl_cert_file = iniparser_getstr(ini, "server:ssl_cert_file");
        ssl_disabled_protocols = iniparser_getstr(ini, "server:ssl_disabled_protocols");
        ssl_cipher_list = iniparser_getstr(ini, "server:ssl_cipher_list");
	use_ipv4 = iniparser_getboolean(ini, "server:ipv4", 1);
#ifdef ENABLE_IPV6
        use_ipv6 = iniparser_getboolean(ini, "server:ipv6", 1);
        if (! (use_ipv4 || use_ipv6)) {
		fprintf(stderr, "Neither ipv4 nor ipv6 is enabled in openwsman.conf !\n");
		exit(1);
	}
#endif
	use_digest = iniparser_getboolean(ini, "server:use_digest", 0);
	digest_password_file = iniparser_getstr(ini,
						"server:digest_password_file");
	basic_password_file =
	    iniparser_getstring(ini, "server:basic_password_file", basic_password_file);
	custom_identify_file =
	    iniparser_getstr(ini, "server:identify_file");
	custom_anon_identify_file =
	    iniparser_getstr(ini, "server:anon_identify_file");
	basic_authenticator =
	    iniparser_getstr(ini, "server:basic_authenticator");
	basic_authenticator_arg =
	    iniparser_getstr(ini, "server:basic_authenticator_arg");
	log_location = iniparser_getstr(ini, "server:log_location");
	max_threads = iniparser_getint(ini, "server:max_threads", 0);
	uri_subscription_repository = iniparser_getstring(ini, "server:subs_repository", DEFAULT_SUBSCRIPTION_REPOSITORY);
        max_connections_per_thread = iniparser_getint(ini, "server:max_connections_per_thread", iniparser_getint(ini, "server:max_connextions_per_thread", 20));
        thread_stack_size = iniparser_getstring(ini, "server:thread_stack_size", "0");
#ifdef ENABLE_EVENTING_SUPPORT
	wsman_server_set_subscription_repos(uri_subscription_repository);
#endif
	return 1;
}

int wsmand_options_get_max_connections_per_thread(void)
{
        return max_connections_per_thread;
}

unsigned int wsmand_options_get_thread_stack_size(void)
{
        errno=0;
        unsigned int stack_size = strtoul(thread_stack_size,NULL,10);
        if(errno){
                debug("failed to convert string to unsigned int : %s", strerror(errno));
                return 0;
        }
        return stack_size;
}

const char *wsmand_options_get_config_file(void)
{
	char *p;
	if (config_file == NULL) {
		config_file = DEFAULT_CONFIG_FILE;
	}
	if (config_file != NULL && !u_path_is_absolute(config_file)) {
		char cwd[PATH_MAX];
		if ((p = getcwd(cwd, PATH_MAX)) != NULL)
			config_file =
			    u_strdup_printf("%s/%s", cwd, config_file);
	}
	return config_file;
}

char *wsmand_options_get_auth_dir(void)
{
    return auth_dir;
}

char *wsmand_options_get_plugin_dir(void)
{
    return plugin_dir;
}

char *wsmand_options_get_digest_password_file(void)
{
	return digest_password_file;
}

char *wsmand_options_get_basic_password_file(void)
{
	return basic_password_file;
}

char *wsmand_options_get_identify_file(void)
{
	return custom_identify_file;
}
char *wsmand_options_get_anon_identify_file(void)
{
	return custom_anon_identify_file;
}

char *wsmand_options_get_service_path(void)
{
	return service_path;
}

int wsmand_options_get_daemon_flag(void)
{
	return daemon_flag;
}

int wsmand_options_get_no_plugins_flag(void)
{
	return no_plugin_flag;
}

int wsmand_options_get_use_ssl(void)
{
	return use_ssl;
}

int wsmand_options_get_use_ipv4(void)
{
	return use_ipv4;
}

#ifdef ENABLE_IPV6
int wsmand_options_get_use_ipv6(void)
{
	return use_ipv6;
}

/* called when opening an ipv6 socket failed */
void wsmand_options_disable_use_ipv6(void)
{
	use_ipv6 = 0;
}
#endif

int wsmand_options_get_foreground_debug(void)
{
	if (foreground_debug)
		return 6;
	else
		return -1;
}



int wsmand_options_get_debug_level(void)
{
	return debug_level;
}


int wsmand_options_get_syslog_level(void)
{
	return syslog_level;
}


int wsmand_options_get_server_port(void)
{
	return server_port;
}


int wsmand_options_get_server_ssl_port(void)
{
	return server_ssl_port;
}



char *wsmand_options_get_ssl_key_file(void)
{
	return ssl_key_file;
}

char *wsmand_options_get_ssl_cert_file(void)
{
	return ssl_cert_file;
}

char *wsmand_options_get_ssl_disabled_protocols(void)
{
	return ssl_disabled_protocols;
}

char *wsmand_options_get_ssl_cipher_list(void)
{
	return ssl_cipher_list;
}

int wsmand_options_get_digest(void)
{
	return use_digest;
}


char *wsmand_options_get_pid_file(void)
{
	return pid_file;
}


int wsmand_options_get_max_threads(void)
{
//XXX: we might wish to return a constant 1 till the
//MT issues on unix are solved. See compat_unix.h for
//details on the issue.
	return max_threads;
}


char *wsmand_default_basic_authenticator()
{
	return DEFAULT_BASIC_AUTH;
}

char *wsmand_options_get_basic_authenticator()
{
	return basic_authenticator;
}

char *wsmand_options_get_basic_authenticator_arg()
{
	return basic_authenticator_arg;
}

unsigned long wsmand_options_get_enumIdleTimeout()
{
	return enumIdleTimeout;
}

typedef struct _ShutdownHandler ShutdownHandler;
struct _ShutdownHandler {
	WsmandShutdownFn fn;
	void *user_data;
};

static list_t *shutdown_handlers = NULL;
static int shutdown_counter = 0;
static int shutdown_pending = 0;
static int shutting_down = 0;

void wsmand_shutdown_add_handler(WsmandShutdownFn fn, void *user_data)
{
	ShutdownHandler *handler;
	lnode_t *n;

	if (fn == NULL)
		return;

	handler = u_zalloc(sizeof(ShutdownHandler));
	handler->fn = fn;
	handler->user_data = user_data;

	n = lnode_create(handler);

	if (!shutdown_handlers)
		shutdown_handlers = list_create(LISTCOUNT_T_MAX);

	list_prepend(shutdown_handlers, n);
}

void wsmand_shutdown_block(void)
{
	if (shutdown_counter < 0)
		return;

	if (shutting_down) {
		debug
		    ("Attempting to block shut-down while shut-down is already in progress!");
	}
	++shutdown_counter;
}

void wsmand_shutdown_allow(void)
{
	if (shutdown_counter <= 0)
		return;
	--shutdown_counter;

	if (shutdown_counter == 0 && shutdown_pending) {
		wsmand_shutdown();
	}
}

static int shutdown_idle_cb(void *user_data)
{
	// int restart = (int )user_data;
	lnode_t *n;
	if (shutdown_handlers == NULL) {
		goto NULL_SHUTDOWN_HANDLERS;
	}

	if (list_isempty(shutdown_handlers)) {
		goto EMPTY_LIST;
	}

	n = list_first(shutdown_handlers);

	debug("shutdown_idle_cb started");

	while (n) {
		ShutdownHandler *handler = n->list_data;

		if (handler && handler->fn)
			handler->fn(handler->user_data);

		u_free(handler);
		n = list_next(shutdown_handlers, n);
	}

	// list_destroy_nodes (shutdown_handlers);
      EMPTY_LIST:
	// list_destroy (shutdown_handlers);
      NULL_SHUTDOWN_HANDLERS:

	if (user_data == NULL) {
		/* We should be quitting the main loop (which will cause us to
		   exit) in a handler.  If not, we'll throw in an exit just to be
		   sure. */
		exit(0);
	} else {
		const char **argv = wsmand_options_get_argv();

		errno = 0;
		if ((execv(argv[0], (char **) argv)) < 0) {
			debug("Can not restart wsmand: %s",
			      strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	/* We should never reach here... */
	assert(1 == 1);
	return 0;
}

static void do_shutdown(int restart)
{
	if (shutdown_counter > 0) {
		debug("Shutting down pended");
		shutdown_pending = TRUE;
		return;
	}
	debug("Shutting down daemon...");

	if (shutting_down) {
		debug
		    ("Shut-down request received while shut-down is already in progress!");
		return;
	}

	shutting_down = TRUE;
	if (restart) {
		shutdown_idle_cb((void *) 1);
	} else {
		shutdown_idle_cb(NULL);
	}

}

void wsmand_shutdown(void)
{
	do_shutdown(FALSE);
}

void wsmand_restart(void)
{
	do_shutdown(TRUE);
}
