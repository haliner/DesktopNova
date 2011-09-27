// Copyright (C) 2011  Stefan Haller
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "daemon.hpp"

#include "../common/configuration.hpp"
#include "../common/profile.hpp"
#include "activeprofile.hpp"


namespace dn {

void
Daemon::run(bool *should_restart) throw ()
{
	if (should_restart) {
		*should_restart = false;
	}
}

void
Daemon::start_application() throw ()
{
	bool should_restart = true;
	while (should_restart) {
		Daemon daemon;
		daemon.run(&should_restart);
	}
}

} // Namespace
