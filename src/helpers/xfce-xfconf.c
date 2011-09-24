/*
 * Copyright (C) 2008-2011  Stefan Haller <haliner@googlemail.com>
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
#include <xfconf/xfconf.h>

#include <config.h>


int main(int argc, char ** argv)
{
	/*
	 * Fail if not enough parameter were passed.
	 */
	if (argc < 2) {
		g_critical("Argument missing.\n");
		return EXIT_FAILURE;
	}

	/*
	 * The filename of the new image should be the first parameter.
	 */
	char * filename = argv[1];


	/*
	 * Init the xfconf subsystem.
	 */
	GError * error = NULL;
	if (! xfconf_init(&error))
	{
		g_critical("Could not init xfconf: %s", error->message);
		g_error_free(error);
		return EXIT_FAILURE;
	}

	/*
	 * This code changes the background image actually.
	 *
	 * We're iterating through all monitors and screens. Not very beautiful,
	 * but it works.
	 */
	XfconfChannel * channel = xfconf_channel_get("xfce4-desktop");

	guint screen;
	guint monitor;
	gboolean empty;
	for (screen = 0; screen < 100; screen++)
	{
		empty = TRUE;
		for (monitor = 0; monitor < 100; monitor++)
		{
			const gchar * property =
				g_strdup_printf("/backdrop/screen%u/monitor%u/image-path",
				                screen, monitor);

			if (! xfconf_channel_has_property(channel, property))
			{
				break;
			}
			empty = FALSE;

			xfconf_channel_set_string(channel, property, filename);
		}
		if (empty)
		{
			break;
		}
	}

	/*
	 * Shutdown the xfconf subsystem.
	 */
	xfconf_shutdown();

	return EXIT_SUCCESS;
}
