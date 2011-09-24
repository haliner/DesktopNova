/*
 * Copyright (C) 2010  Eric Gach <eric@php-oop.net>
 *
 * Slightly modified by Stefan Haller <haliner@googlemail.com>.
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
#include <dconf/dconf-client.h>

#include <config.h>


/*
 * Dummy callback function.
 */
void module_free_user_data(gpointer user_data)
{
}

/*
 * Dummy callback function.
 */
void module_dconf_watch(DConfClient *client,        const gchar *path,
                        const gchar * const *items, gint n_items,
                        const gchar *tag,           gpointer user_data)
{
}

int main(int argc, char **argv)
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
	 * Dconf needs a working gobjects type system. (?)
	 */
	g_type_init();


	/*
	 * This code changes the background image actually.
	 */
	DConfClient *client = dconf_client_new(NULL, module_dconf_watch, NULL,
	                                       module_free_user_data);
	if (client == NULL) {
		g_critical("Couldn't acquire dconf client.\n");
		return EXIT_FAILURE;
	}

	if (dconf_client_is_writable(client,
		                         "/org/gnome/desktop/background/picture-uri")) {
		g_critical("Dconf key not writable.\n");
		return EXIT_FAILURE;
	}

	GVariant *gfilename = g_variant_new("s", g_filename_to_uri(filename,
	                                                           NULL, NULL));
	if (! dconf_client_write(client,
	                         "/org/gnome/desktop/background/picture-uri",
		      gfilename, NULL, NULL, NULL)) {
		g_critical("Failed to write to background image key.\n");
		return EXIT_FAILURE;
	}

	g_variant_unref(gfilename);
	g_object_unref(client);

	return EXIT_SUCCESS;
}
