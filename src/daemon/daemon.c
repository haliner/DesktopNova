/*
 * Copyright (C) 2008-2011 Stefan Haller
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <glib.h>
#include <unistd.h>

#include <config.h>
#include <daemon/daemon.h>
#include <common/helpers.h>


struct global_daemon_struct globdae = {
	/*
	 * Setting the mainloop to NULL lets the signal handler determine if
	 * the main loop is already running. Otherwise the handler might access
	 * a invalid memory region.
	 */
	.mainloop = NULL
};


static void
signal_handler(gint signal)
{
	/* Escape from mainloop if running. */
	if (globdae.mainloop != NULL) {
		g_main_loop_quit(globdae.mainloop);
	}
}


static void
setup_signals()
{
	/*
	 * Sets a new signal handler for the SIGINT signal. All other signals
	 * are left untouched. We do need nothing fancy. No flags, no blocked
	 * signals. Just a small signal trap for leaving the main loop.
	 */
	struct sigaction sa = {
		.sa_handler = signal_handler,
		.sa_flags = 0
	};
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}


static void
daemonize()
{
	if (g_getenv("DESKTOPNOVA_NO_DAEMON") != NULL) {
		/*
		 * It's requested that we do not run as daemon. Leaving here.
		 */
		 return;
	}

	/*
	 * Non POSIX function, BSD compatible.
	 * We could do the daemonizing stuff ourself, but there is already a
	 * function for this.
	 *
	 * TODO: Check if all supported platforms have this function.
	 * TODO: Error handling
	 */
	daemon(FALSE, FALSE); /* 0: Success, -1: Error (see errno) */
}


static gboolean
initialize_daemon()
{
	/* Initialize random number generator. */
	globdae.rand = g_rand_new();

	/* Scan helpers */
	globdae.helpers = dn_helper_scan();

	/* Load settings and profiles. */
	globdae.settings = dn_settings_load();

	setup_signals();

	return TRUE;
}


static gboolean
deinitialize_deamon()
{
	/*
	 * Free allocated memory of globaly used variables.
	 * Makes valgrind happy. :)
	 */
	g_rand_free(globdae.rand);
	g_ptr_array_unref(globdae.helpers);
	dn_settings_fini(globdae.settings);
	return TRUE;
}


int
main(int argc, gchar **argv)
{
	daemonize();

	if (! initialize_daemon()) {
		g_critical("Initialization failed.\n");
		return EXIT_FAILURE;
	}

	/*
	 * Creating the GMainContext is not strictly necessary. I like
	 * valgrind-clean programs and when the default main context is used,
	 * glib doesn't free the memory. That's why we are creating our own context.
	 */
	GMainContext *maincontext = g_main_context_new();
	globdae.mainloop = g_main_loop_new(maincontext, FALSE);
	g_main_loop_run(globdae.mainloop);
	g_main_loop_unref(globdae.mainloop);
	g_main_context_unref(maincontext);

	if (! deinitialize_deamon()) {
		g_critical("Deinitialization failed.\n");
	}

	return EXIT_SUCCESS;
}
