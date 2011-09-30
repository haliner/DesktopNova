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

#include <string>

#include "profile.hpp"


namespace dn {
namespace profile {

////////////////////////////////////////////////////////////////////////////////
// Directory
////////////////////////////////////////////////////////////////////////////////

Directory::Directory(std::string path, const bool subdirectories)
: path_(std::move(path)),
  subdirectories_(subdirectories)
{}

Directory::Directory(const Directory &rhs)
: path_(rhs.path_),
  subdirectories_(rhs.subdirectories_)
{}

Directory::Directory(Directory &&rhs)
: path_(std::move(rhs.path_)),
  subdirectories_(std::move(rhs.subdirectories_))
{}

Directory &
Directory::operator=(const Directory &rhs)
{
	path_ = rhs.path_;
	subdirectories_ = rhs.subdirectories_;
	return *this;
}

Directory &
Directory::operator=(Directory &&rhs)
{
	path_ = std::move(rhs.path_);
	subdirectories_ = std::move(rhs.subdirectories_);
	return *this;
}

bool
Directory::operator==(const Directory &rhs) const
{
	return ((this == &rhs) ||
	        ((path_ == rhs.path_) &&
	         (subdirectories_ == rhs.subdirectories_)));
}

const std::string &
Directory::get_path() const
{
	return path_;
}

void
Directory::set_path(std::string value)
{
	path_ = std::move(value);
}

const bool &
Directory::get_subdirectores() const
{
	return subdirectories_;
}

void
Directory::set_subdirectories(bool value)
{
	subdirectories_ = value;
}


////////////////////////////////////////////////////////////////////////////////
// Profile
////////////////////////////////////////////////////////////////////////////////

Profile::Profile(std::string name)
: name_(std::move(name))
{}

Profile::Profile(const Profile &rhs)
: name_(rhs.name_),
  directories_(rhs.directories_)
{}

Profile::Profile(Profile &&rhs)
: name_(std::move(rhs.name_)),
  directories_(std::move(rhs.directories_))
{}

Profile&
Profile::operator=(const Profile &rhs)
{
	name_ = rhs.name_;
	directories_ = rhs.directories_;
	return *this;
}

Profile&
Profile::operator=(Profile &&rhs)
{
	name_ = std::move(rhs.name_);
	directories_ = std::move(rhs.directories_);
	return *this;
}

bool
Profile::operator==(const Profile &rhs) const
{
	return ((this == &rhs) ||
	        ((name_ == rhs.name_) &&
	         (directories_ == rhs.directories_)));
}

void
Profile::add_directory(Directory directory)
{
	directories_.push_back(std::move(directory));
}

void
Profile::remove_directory(const std::string &path)
{
	for (auto i = directories_.begin();
	     i != directories_.end();
	     ++i)
	{
		if (i->get_path() == path) {
			directories_.erase(i);
			return;
		}
	}

	// TODO: Throw exception
}

void
Profile::remove_directory(const Directory &directory)
{
	for (auto i = directories_.begin();
	     i != directories_.end();
	     ++i)
	{
		if (*i == directory) {
			directories_.erase(i);
			return;
		}
	}

	// TODO: Throw exception
}

const std::vector<Directory>&
Profile::get_directories()
{
	return directories_;
}



}} // Namespaces
