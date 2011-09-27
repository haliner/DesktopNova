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

#ifndef GUARD_DN_COMMON_CONFIGURATION_HPP
#define GUARD_DN_COMMON_CONFIGURATION_HPP

#include <string>
#include <vector>

#include "../fwd.hpp"


namespace dn {

class Configuration {
public:
	bool get_enabled() const;
	void set_enabled(const bool value);

	bool get_change_on_start() const;
	void set_change_on_start(const bool value);

	bool get_change_regularly() const;
	void set_change_regularly(const bool value);

	int get_interval() const;
	void set_interval(const int value);

	profile::Profile get_default_profile() const;
	void set_default_profile(const profile::Profile &prof);

	profile::Profile get_profile(const std::string &name) const;
	std::vector<profile::Profile> get_profiles() const;


	//
	// Reads the application's config file.
	//
	static Configuration load();

	//
	// Saves to application's config file.
	//
	static void save(Configuration &conf);
};

} // Namespace

#endif
