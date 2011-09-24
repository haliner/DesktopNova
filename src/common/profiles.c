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
#include <common/profiles.h>


dn_profile_path *
dn_profile_path_init()
{
	dn_profile_path *profile_path = g_new(dn_profile_path, 1);
	profile_path->path = NULL;
	profile_path->directory = TRUE;
	profile_path->recursive = TRUE;
	return profile_path;
}


void
dn_profile_path_fini(dn_profile_path *profile_path)
{
	g_free(profile_path->path);
	g_free(profile_path);
}


dn_profile *
dn_profile_init()
{
	dn_profile *profile = g_new(dn_profile, 1);
	profile->name = NULL;
	profile->paths =
		g_ptr_array_new_with_free_func((GDestroyNotify)&dn_profile_path_fini);
	return profile;
}


void
dn_profile_fini(dn_profile *profile)
{
	g_free(profile->name);
	g_ptr_array_unref(profile->paths);
	g_free(profile);
}
