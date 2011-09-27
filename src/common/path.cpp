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

#include <cstdlib>
#include <boost/filesystem.hpp>

#include "buildconfig.hpp"
#include "path.hpp"


namespace dn {
namespace Path {

fs::path
get_prefix()
{
	return PREFIX;
}

fs::path
get_dir_runtime()
{
	return DIR_RUNTIME;
}

fs::path
get_dir_library()
{
	return DIR_LIBRARY;
}

fs::path
get_dir_archive()
{
	return DIR_ARCHIVE;
}

fs::path
get_dir_runtime_helper()
{
	return DIR_RUNTIME_HELPER;
}

fs::path
get_dir_helper_rel()
{
	return DIR_HELPER_REL;
}

fs::path
get_binary_path()
{
	fs::path link = "/proc/self/exe";
	fs::path exe  = fs::read_symlink(link);
	return exe;
}

fs::path
get_binary_dir()
{
	fs::path exe = get_binary_path();
	return exe.parent_path();
}

fs::path
get_helper_path()
{
	fs::path p = get_binary_dir();
	p /= get_dir_helper_rel();
	return p;
}

fs::path
get_home()
{
	fs::path home = std::getenv("HOME");
	return home;
}

fs::path
get_app_path()
{
	fs::path p = get_home();
	p /= ".config";
	p /= "desktopnova";
	return p;
}

fs::path
get_settings_path()
{
	fs::path p = get_app_path();
	p /= "desktopnova.conf";
	return p;
}

}} // Namespaces
