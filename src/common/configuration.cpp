#include "configuration.hpp"

#include "profile.hpp"


namespace dn {

bool
Configuration::get_enabled() const
{
	return true;
}

void
Configuration::set_enabled(const bool value)
{
}

bool
Configuration::get_change_on_start() const
{
	return true;
}

void
Configuration::set_change_on_start(const bool value)
{
}

bool
Configuration::get_change_regularly() const
{
	return true;
}

void
Configuration::set_change_regularly(const bool value)
{
}

int
Configuration::get_interval() const
{
	return 60;
}

void
Configuration::set_interval(const int value)
{
}

Profile
Configuration::get_default_profile() const
{
	return Profile();
}

void
Configuration::set_default_profile(const Profile &prof)
{
}

Profile
Configuration::get_profile(const std::string &name) const
{
	return Profile();
}

std::vector<Profile>
Configuration::get_profiles() const
{
	return std::vector<Profile>();
}


Configuration
Configuration::load()
{
	return Configuration();
}

void
Configuration::save(Configuration &conf)
{
}

} // Namespace
