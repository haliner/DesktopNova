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

#include <config.h>
#include <common/settings.h>
#include <common/profiles.h>


dn_settings *
dn_settings_init()
{
	dn_settings *settings = g_new(dn_settings, 1);
	settings->helpers =
		g_ptr_array_new_with_free_func((GDestroyNotify)&g_free);
	settings->profiles =
		g_ptr_array_new_with_free_func((GDestroyNotify)&dn_profile_fini);
	return settings;
}


void
dn_settings_fini(dn_settings *settings)
{
	g_ptr_array_unref(settings->helpers);
	g_ptr_array_unref(settings->profiles);
	g_free(settings);
}


dn_settings *
dn_settings_load()
{
	dn_settings * settings = dn_settings_init();
	/*
	 * TODO: Not implemented.
	 *
	 * Hard-code the settings to sane defaults.
	 */

	dn_profile_path *path = dn_profile_path_init();
	path->path = g_strdup("/usr/share/wallpapers");
	path->directory = TRUE;
	path->recursive = TRUE;

	dn_profile *profile = dn_profile_init();
	profile->name = g_strdup("Default");
	g_ptr_array_add(profile->paths, path);

	g_ptr_array_add(settings->profiles, profile);
	g_ptr_array_add(settings->helpers, g_strdup("gnome2"));

	return settings;
}
