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

#ifndef __PROFILES__H__
#define __PROFILES__H__

#include <glib.h>

#include <config.h>


struct dn_profile_path_struct {
	gchar *path;
	gboolean directory;
	gboolean recursive;
};
typedef struct dn_profile_path_struct dn_profile_path;

/*
 * Initializes struct.
 */
dn_profile_path *dn_profile_path_init();

/*
 * Finalizes struct.
 */
void dn_profile_path_fini(dn_profile_path *profile_path);



struct dn_profile_struct {
	gchar *name;
	GPtrArray *paths; /* Array of dn_profile_path */
};
typedef struct dn_profile_struct dn_profile;

/*
 * Initializes struct.
 */
dn_profile * dn_profile_init();

/*
 * Finalizes struct.
 */
void dn_profile_fini(dn_profile *profile);

#endif
