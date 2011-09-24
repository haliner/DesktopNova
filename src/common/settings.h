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

#ifndef __SETTINGS__H__
#define __SETTINGS__H__

#include <glib.h>

#include <config.h>


struct dn_settings_struct {
	/*
	 * In a perfect world this *should* be an array of dn_helpers, but
	 * the settings subsystem doesn't know anything about the helper tools.
	 * Currently it's up to the main program to iterate through the list
	 * of helper tools and check if the name matches.
	 *
	 * TODO: Should be really array of dn_helper.
	 */
	GPtrArray *helpers;  /* -- Array of gchar *    -- */
	GPtrArray *profiles; /* -- Array of dn_profile -- */
};
typedef struct dn_settings_struct dn_settings;

/*
 * Initializes struct.
 */
dn_settings *dn_settings_init();

/*
 * Finalizes struct.
 */
void dn_settings_fini(dn_settings *settings);


/*
 * Loads the settings from the main configuration file and returns the pointer
 * to the data (return value must be freed).
 */
dn_settings * dn_settings_load();

#endif
