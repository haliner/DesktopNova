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

#ifndef GUARD_DN_COMMON_PROFILE_HPP
#define GUARD_DN_COMMON_PROFILE_HPP

#include <string>
#include <vector>


namespace dn {
namespace profile {

class Directory {
public:
	Directory();
	Directory(std::string &path, const bool subdirectories = true);
	Directory(const Directory &rhs);
	Directory(Directory &&rhs);

	Directory& operator=(const Directory &rhs);
	Directory& operator=(Directory &&rhs);

	const std::string& get_path() const;
	void set_path(const std::string& value);

	const bool &get_subdirectores() const;
	void set_subdirectories(const bool value);

private:
	std::string path;
	bool subdirectories;
};

class Profile {
public:
	Profile() = default;
	Profile(std::string &name);
	Profile(const Profile &rhs);
	Profile(Profile &&rhs);

	Profile& operator=(const Profile &rhs);
	Profile& operator=(Profile &&rhs);

	void add_directory(const Directory &directory);
	void add_directory(Directory &&directory);

	void remove_directory(const std::string &path);
	void remove_directory(const Directory &directory);

	const std::vector<Directory>& get_directories();

private:
	std::string name;
	std::vector<Directory> directories;
};

}} // Namespaces

#endif
