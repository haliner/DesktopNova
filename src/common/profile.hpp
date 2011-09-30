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
	Directory() = default;
	Directory(std::string path, const bool subdirectories = true);
	Directory(const Directory &rhs);
	Directory(Directory &&rhs);

	Directory& operator=(const Directory &rhs);
	Directory& operator=(Directory &&rhs);

	bool operator==(const Directory &rhs) const;

	const std::string& get_path() const;
	void set_path(std::string value);

	const bool &get_subdirectores() const;
	void set_subdirectories(bool value);

private:
	std::string path_;
	bool subdirectories_;
};

class Profile {
public:
	Profile() = default;
	Profile(std::string name);
	Profile(const Profile &rhs);
	Profile(Profile &&rhs);

	Profile& operator=(const Profile &rhs);
	Profile& operator=(Profile &&rhs);

	bool operator==(const Profile &rhs) const;

	void add_directory(Directory directory);

	void remove_directory(const std::string &path);
	void remove_directory(const Directory &directory);

	const std::vector<Directory>& get_directories();

private:
	std::string name_;
	std::vector<Directory> directories_;
};

}} // Namespaces

#endif
