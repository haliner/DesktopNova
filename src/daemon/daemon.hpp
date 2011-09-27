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

#ifndef GUARD_DN_DAEMON_DAEMON_HPP
#define GUARD_DN_DAEMON_DAEMON_HPP

#include <memory>
#include <vector>

#include "../fwd.hpp"


namespace dn {

//
// The daemon class is responsible for almost everything. It ties together the
// other parts of the deamon implementation, sets everything up and runs
// everything...
//
class Daemon {
public:
	//
	// Runs the daemon.
	// Optionally pass a pointer to a boolean variable. If a pointer is passed,
	// the functions can request a restart of the daemon. So check the pointer
	// afterwards and if the bool is true, start a new Daemon.
	//
	void run(bool *should_restart = 0) throw ();

	//
	// This function provides a simple solution for running a daemon and
	// restarting it, if necessary.
	//
	static void start_application() throw ();

private:
	std::unique_ptr<Configuration> configuration;
	std::unique_ptr<ActiveProfile> profile;
};

} // Namespace

#endif
