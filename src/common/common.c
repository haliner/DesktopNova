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
#include <unistd.h>

#include <config.h>
#include <common/common.h>


gchar *
dn_path_get_executable()
{
	/* TODO: Error handling */
	gchar *exec = g_file_read_link("/proc/self/exe", NULL);
	return exec;
}


gchar *
dn_path_get_settings()
{
	const gchar * config = g_get_user_config_dir();
	return g_build_filename(config, "desktopnova", NULL);
}


gchar *
dn_path_get_settings_file()
{
	gchar * result;
	gchar * settings = dn_path_get_settings();
	result = g_build_filename(settings, "desktopnova.conf", NULL);
	g_free(settings);
	return result;
}


gchar *
dn_path_get_helper()
{
	gchar * executable = dn_path_get_executable();
	gchar * dirname = g_path_get_dirname(executable);
	gchar * result = g_build_filename(dirname, DIR_HELPER_REL, NULL);
	g_free(dirname);
	g_free(executable);
	return result;
}
