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
#include <gconf/gconf-client.h>

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
	 * GConf needs a working gobjects type system.
	 */
	g_type_init();

	/*
	 * This code changes the background image actually.
	 */
	GConfClient * gconf_client = gconf_client_get_default();
	if (gconf_client == NULL)
	{
		g_critical("Couldn't acquire gconf client.\n");
		return EXIT_FAILURE;
	}
	gconf_client_set_string(gconf_client,
	                        "/desktop/gnome/background/picture_filename",
	                        filename, NULL);
	g_object_unref(gconf_client);

	return EXIT_SUCCESS;
}
