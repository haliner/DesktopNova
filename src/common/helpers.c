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

#include <glib.h>

#include <config.h>
#include <common/common.h>
#include <common/helpers.h>


static gchar *
dn_helper_get_path(dn_helper *helper)
{
	gchar *path = dn_path_get_helper();
	gchar *result = g_build_filename(path, helper->filename, NULL);
	g_free(path);
	return result;
}


dn_helper *
dn_helper_init()
{
	dn_helper *helper = g_new(dn_helper, 1);
	helper->filename = NULL;
	return helper;
};


void
dn_helper_fini(dn_helper *helper)
{
	g_free(helper->filename);
	g_free(helper);
};


GPtrArray *
dn_helper_scan()
{
	dn_helper *helper;
	const gchar *filename;
	GPtrArray *helpers =
		g_ptr_array_new_with_free_func((GDestroyNotify)&dn_helper_fini);

	gchar *path = dn_path_get_helper();
	GDir *dir = g_dir_open(path, 0, NULL);
	while ((filename = g_dir_read_name(dir)) != NULL) {
		helper = dn_helper_init();
		helper->filename = g_strdup(filename);
		g_ptr_array_add(helpers, helper);
	}
	g_dir_close(dir);
	g_free(path);

	return helpers;
}


void
dn_helper_exec(dn_helper *helper, gchar *wallpaper)
{
	gchar *argv[3] = {
		dn_helper_get_path(helper),
		wallpaper,
		NULL
	};
	/* TODO: Error handling */
	g_spawn_async(
		NULL, /* working directory */
		argv,
		NULL, /* environment table */
		0,    /* flags */
		NULL, /* child setup callback */
		NULL, /* user data */
		NULL, /* child pid - must be freed if non-NULL! */
		NULL  /* error */
	);
	g_free(argv[0]);
}
