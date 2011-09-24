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

#ifndef __HELPERS__H__
#define __HELPERS__H__

#include <glib.h>

#include <config.h>


struct dn_helper_struct {
	gchar *filename;
};
typedef struct dn_helper_struct dn_helper;

/*
 * Initializes struct.
 */
dn_helper *dn_helper_init();

/*
 * Finalizes struct.
 */
void dn_helper_fini(dn_helper *helper);



/*
 * Scans helpers in helper directory.
 * Returns GArray filled with dn_helper structure. The list must be freed.
 * Use dn_helper_array_free for that, because it will free all the allocated
 * memory correctly.
 */
GPtrArray *dn_helper_scan();



/*
 * Executes a helper program. The wallpaper argument will be passed as the
 * first argument.
 */
void dn_helper_exec(dn_helper *helper, gchar *wallpaper);

#endif
