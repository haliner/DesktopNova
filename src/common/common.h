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

#ifndef __COMMON__H__
#define __COMMON__H__

#include <glib.h>

#include <config.h>


/*
 * Returns the path (file) of the running executable.
 */
gchar * dn_path_get_executable();


/*
 * Returns path where DesktopNova stores the settings.
 */
gchar * dn_path_get_settings();


/*
 * Returns path to main settings file.
 */
gchar * dn_path_get_settings_file();


/*
 * Returns absolute path (dir) to modules.
 */
gchar * dn_path_get_helper();

#endif
