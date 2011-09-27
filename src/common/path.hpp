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

#ifndef GUARD_DN_COMMON_PATH_HPP
#define GUARD_DN_COMMON_PATH_HPP

#include <boost/filesystem.hpp>


namespace dn {
namespace Path {

	namespace fs = boost::filesystem;

	//
	// The following function return the target directories of the build
	// system. Use them only in spare cases!
	//
	fs::path get_prefix();
	fs::path get_dir_runtime();
	fs::path get_dir_library();
	fs::path get_dir_archive();
	fs::path get_dir_runtime_helper();

	//
	// Returns the path relative from the binary directory to the helpers'
	// binary directory.
	//
	fs::path get_dir_helper_rel();

	//
	// Returns the path or the directory of the currently running executable.
	//
	fs::path get_binary_path();
	fs::path get_binary_dir();

	//
	// Calculates the helper path. Uses the current binary directory and the
	// relative directory of the helper files.
	//
	fs::path get_helper_path();

	//
	// Returns the home directory of the user.
	//
	fs::path get_home();

	//
	// Returns the application's directory, where it stores the configuration
	// file.
	// The other functions are returning related files in this directory.
	//
	fs::path get_app_path();
	fs::path get_settings_path();

}} // Namespaces

#endif
